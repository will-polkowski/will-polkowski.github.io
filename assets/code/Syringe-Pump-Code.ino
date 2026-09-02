#include <AccelStepper.h>

// -----------------------------
// Pin assignments
// -----------------------------
const int STEP_PIN = 3;
const int DIR_PIN = 4;

const int BACKWARD_BUTTON_PIN = 13;
const int FORWARD_BUTTON_PIN = 11;
const int RUN_SWITCH_PIN = 12;    // latching ON/OFF switch, wired to GND, use INPUT_PULLUP
const int LIMIT_SWITCH_PIN = 10;  // empty-state limit switch, wired to GND, use INPUT_PULLUP

const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 7;

// -----------------------------
// Stepper setup
// DRIVER mode = step + dir
// -----------------------------
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// -----------------------------
// User-editable variables
// -----------------------------
float flowRate_mL_min = 3.0;      // set desired flow rate here
float syringeDiameter_mm = 14.5;  // change for 10 mL vs 20 mL syringe
float lead_mm_per_rev = 2.0;      // set to 2.0 or 8.0 depending on your screw
int fullSteps_per_rev = 200;      // 1.8 deg stepper = 200 steps/rev
int microsteps = 8;
/** as of my last work on the board at 12PM 2/28/26, our hardware is set up for 1/8 steps - Elliot
*/

// -----------------------------
// Computed variables
// -----------------------------
float stepsPerSecond = 0.0;
float maxStepRate = 1000.0;  // per project sheet, setMaxSpeed(1000)

// -----------------------------
// State tracking
// -----------------------------
enum PumpState {
  RUNNING,
  BACKWARD,
  FORWARD,
  PAUSED,
  EMPTY,
};

PumpState state = PAUSED;

// -----------------------------
// Helper functions
// -----------------------------
float syringeArea_mm2(float diameter_mm) {
  float radius = diameter_mm / 2.0;
  return 3.14159265 * radius * radius;
}

float flowRateToStepsPerSecond(float flow_mL_min, float diameter_mm) {
  // Convert mL/min -> mm^3/min
  float flow_mm3_min = flow_mL_min * 1000.0;

  // Syringe area in mm^2
  float area_mm2 = syringeArea_mm2(diameter_mm);

  // Linear speed in mm/min
  float linearSpeed_mm_min = flow_mm3_min / area_mm2;

  // Motor rev/min required
  float rev_min = linearSpeed_mm_min / lead_mm_per_rev;

  // Steps/min
  float steps_min = rev_min * fullSteps_per_rev * microsteps;

  // Steps/sec
  return steps_min / 60.0;
}

void setLED(bool r, bool g, bool b) {
  digitalWrite(RED_PIN, r ? HIGH : LOW);
  digitalWrite(GREEN_PIN, g ? HIGH : LOW);
  digitalWrite(BLUE_PIN, b ? HIGH : LOW);
}

bool updateState() {

  bool backwardButtonOn = (digitalRead(BACKWARD_BUTTON_PIN) == LOW); //INPUT_PULLUP
  bool forwardButtonOn = (digitalRead(FORWARD_BUTTON_PIN) == LOW); //INPUT_PULLUP
  bool runSwitchOn = (digitalRead(RUN_SWITCH_PIN) == LOW);  // INPUT_PULLUP
  bool limitHit = (digitalRead(LIMIT_SWITCH_PIN) == HIGH);

  if (limitHit && backwardButtonOn) {
    state = BACKWARD;
    return backwardButtonOn;
  }

  else if (limitHit) {
    state = EMPTY;
    return limitHit;
  }

  else if (!runSwitchOn && backwardButtonOn && forwardButtonOn) {
    state = PAUSED;
    return !runSwitchOn;
  }

  else if (!runSwitchOn && backwardButtonOn) {
    state = BACKWARD;
    return backwardButtonOn;
  }

  else if (!runSwitchOn && forwardButtonOn) {
    state = FORWARD;
    return forwardButtonOn;
  }

  else if (!runSwitchOn) {
    state = PAUSED;
    return !runSwitchOn;
  }

  else if (runSwitchOn) {
    state = RUNNING;
    return runSwitchOn;
  }
  
  else {
    state = PAUSED;
    return false;
  }

}
/** this function updates the LEDs, but does not change the state of the machine
*/
void applyStateOutputs() {
  switch (state) {
    case RUNNING:
      // Green
      setLED(false, true, false);
      break;

    case PAUSED:
      // Yellow = red + green
      setLED(true, true, false);
      break;

    case EMPTY:
      // Red
      setLED(true, false, false);
      break;

    case BACKWARD:
      // Blue
      setLED(false, false, true);
      break;
    
    case FORWARD: 
    /*I kinda disagree with having a forward state since its somewhat redundant but it provides the machine with more information, and if you were to expand this code it
    would be useful*/
      // yellow
      setLED(true, true, false);
      break;
  }
}

void setup() {
  pinMode(RUN_SWITCH_PIN, INPUT_PULLUP);
  pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);
  pinMode(FORWARD_BUTTON_PIN, INPUT_PULLUP);
  pinMode(BACKWARD_BUTTON_PIN, INPUT_PULLUP);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Compute constant step rate once at startup
  stepsPerSecond = flowRateToStepsPerSecond(flowRate_mL_min, syringeDiameter_mm);

  if (sqrt(sq(stepsPerSecond)) > maxStepRate) {
    stepsPerSecond = maxStepRate;
  }

  stepper.setMaxSpeed(maxStepRate);

  applyStateOutputs(); //LED operations
}

void loop() {
  updateState();
  applyStateOutputs(); //LED operations

  if (state == RUNNING) {
    stepper.setSpeed(stepsPerSecond);
    stepper.runSpeed();
  }
  else if (state == BACKWARD) {
    stepper.setSpeed(-1000);
    stepper.runSpeed();
  }
  else if (state == FORWARD) {
    stepper.setSpeed(1000);
    stepper.runSpeed();
  }

  // If PAUSED or EMPTY, runSpeed() is intentionally not called
}

