---
title: "Syringe Pump"
excerpt: "An automated syringe pump capable of creating a steady volumetric flow rate of 1.0 mL/min from a source syringe of either 10 mL or 20 mL."
header:
  image: assets/img/Syringe Pump Real.png
  teaser: /assets/img/Syringe Pump Render.png
gallery:
  - image_path: /assets/img/Syringe Pump Mount.jpg
  - image_path: /assets/img/Syringe Pump Open.png
  - image_path: /assets/img/Syringe Pump Wiring.png
   
---

# Features

* **Syringe Mounted Linear Actuator** The syringe pump works by using a stepper motor to rotate a lead screw. The rotation of this screw causes a carriage to move either forward or backward along the linear actuator. The movement of this carriage moves the pump of a syringe to extrude liquid. The syringe pump is compatible with both 10 mL and 20 mL syringes.
* **1.0 mL/min Volumetric Flow Rate** The syringe pump is pre-programmed to create a constant volumetric flow of 1.0 mL/min after the start button is pressed. It will continue to run until the start button is pressed again, or the carriage runs into the switch to automatically shut off the pump when the syringe is empty.
* **Forward and Backward Carriage Control** The syringe pump has forward and backward momentary buttons that move the carriage more quickly than the automated flow rate to allow for easy syringe positioning.
* **LED State Indicator** The syringe pump has an LED indicator light that displays what state the pump is currently in. Green indicates that the syringe pump is actively running, yellow indicates that the pump is paused, and red indicates that the loaded syringe is empty.  

# CAD Model
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH90d2dQT28d5b6028111faa711e61596051?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe>

# Required Parts

| Off-The-Shelf Part      | Quantity |
| ----------- | ----------- |
|  M5x8mm Bolt     |    10    |
|  M5 Tee Nut  |    10     |
|   M5x16mm Bolt    |    4    |
|  M5 Threaded Heat Insert  |     4    |
|   M3x10mm Bolt    |    4    |
|  M3x8mm Thread Forming Screw  |     4    |
|   M2.5x8mm Thread Forming Screw    |    2    |
|  F68822 Flanged Ball Bearing  |     2    |
| [Linear Rod Lock Collar](https://www.amazon.com/10PCS-Shaft-Collar-Aluminum-Linear/dp/B0C46G8G1R/ref=asc_df_B0C46G8G1R?tag=bingshoppinga-20&linkCode=df0&hvadid=80814314503139&hvnetw=o&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=83973&hvtargid=pla-4584413793770717&hvocijid=17867946872889471524-B0C46G8G1R-&hvexpln=0&th=1)      |    2    |
|  [Lead Screw Lock Collar](https://www.amazon.com/Shaft-Collar-Aluminum-Alloy-Linear/dp/B0BFL3ZD6D/ref=asc_df_B0BFL3ZD6D?tag=bingshoppinga-20&linkCode=df0&hvadid=80814314503139&hvnetw=o&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=83973&hvtargid=pla-4584413793532618&hvocijid=12744195799096762271-B0BFL3ZD6D-&hvexpln=0&th=1)  |     2    |
|  [Lead Screw w/ Nut](https://www.amazon.com/dp/B07R1H5ZMV?lv=shuf&psc=1&_encoding=UTF8&channelId=701&ref_=cm_sw_em_r_mt_dp_0YZ13D4HQBGW2Z86PBV1&plpRedirect=mhFallback)  |     1    |
|   1/4" x 8mm Flexible Coupling    |    1    |
|  200mm Rod w/ 8mm Diameter  |    1     |
|  LM8UU Linear Bearing for 8mm Diameter Rod  |     1    |
|    NEMA 17 Stepper Motor   |    1    |
|  [AC-DC Power Supply](https://www.amazon.com/dp/B005T9HGLI?lv=shuf&psc=1&_encoding=UTF8&channelId=701&ref_=cm_sw_em_r_mt_dp_A8CZ056TM52EJGZTGZGR&plpRedirect=mhFallback)  |     1    |
| [Arduino Uno](https://www.amazon.com/dp/B007R9TUJE?lv=shuf&channelId=701&ref_=cm_sw_em_r_mt_dp_TY8JGK0CJD1JEJM4BNNJ&plpRedirect=mhFallback)   |    1     |
|   A4988 Stepper Driver    |     1   |
|  [Latching Button](https://www.amazon.com/dp/B07XTBL1NP?smid=A2NNH5C5IP9N3O&linkCode=sl1&tag=drd0cf-20&linkId=43b42a7cb2a088ebd85d65cb9da46725&language=en_US&ref_=as_li_ss_tl&th=1)  |     1    |
|  Small Breadboard  |     1    |
|   [Limit Switch](https://www.amazon.com/gp/product/B07X142VGC)    |    1    |
|  RGB Common Cathode LED  |     1    |
|  [Momentary Push Button](https://www.amazon.com/dp/B08SKJ6V7Z?lv=shuf&social_share=cm_sw_r_cp_ud_dp_31RXPM7MRDVYD95T6Z81&channelId=751&ref_=cm_sw_r_cp_ud_dp_31RXPM7MRDVYD95T6Z81&plpRedirect=mhFallback&th=1)  |     2    |

Note: LCD screen is pictured in the model and images but has no function due to time constraints of the project.

| 3D Printed Part (All qty of 1)     | Material |
| ----------- | ----------- |
|   Enclosure Body   |    PLA   |
|  Enclosure Lid  |    PLA     |
|   Motor Mounting Plate   |    ABS   |
|  Syringe Mounted End Support  |    PLA    |
|   Basic End Support   |    PLA    |
|   Carriage   |    PLA   |
|   LED Loop Attachment   |    TPU   |

# Instructions for Use

1. Plug the system into a wall outlet. This automatically turns on the system making it ready for use.
2. Use forward and backwards buttons to position the carriage to fit size of syringe.
3. Insert the syringe into the holder by sliding it all the way into the appropriate slot on the end support and attach the pump to the carriage slot.
4. Press the latching button to start the pump.
5. To pause the pump at any time, press the latching button again.
6. During operation, monitor the system to ensure proper fluid delivery.
7. When the syringe reaches the end, the limit switch will be triggered, automatically stopping the motor.
8. After the pump stops, remove the empty syringe and replace it if needed.

{% include gallery caption="Syringe Pump" %}
