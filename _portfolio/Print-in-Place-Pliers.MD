---
title: "Print-in-Place Pliers"
excerpt: "A pair of pliers designed to be printed as one multimaterial file capable of picking up small objects like resistors."
header:
  image: /assets/img/Pliers_Top.JPG
  teaser: /assets/img/Pliers_Assembly_Rendering.png
gallery:
  - image_path: /assets/img/Pliers_Closed.JPG
  - image_path: /assets/img/Pliers_Jaws.JPG
  - image_path: /assets/img/Pliers_Dovetail_It1.JPG
  - image_path: /assets/img/Pliers_Dovetail_It2.JPG
  - image_path: /assets/img/Pliers_It1.JPG

# Table of Conents
toc: true
toc_label: "Table of Contents"
toc_sticky: true
toc_icon: bars
   
---

  
# Overview 
Many FFF designs contain multiple components with moving parts. While these parts can be printed separately and put together afterwards using fasteners or part geometry, sometimes these designs can be printed in a single print. These designs are called print-in-place models, and they are much easier to fabricate because they don't require any assembly after they're printed. Print-in-place designs are created by designing a single assembly with interlocking joints and then printing the assembly in such a way that the components remain stationary until they are removed from the build plate. Print-in-place designs have many cosmetic and practical uses (see examples below). Generally, print-in-place designs work better for materials with similar mechanical properties and surface tensions because they adhere to each other better. However, by using intentional part geometry, multi-material objects can be printed in place.  

The goal of this project was to design multi-material, print-in-place pliers that can grip and pick up through-hole resistors. The pliers were required to include a flexible spring component that returns them to a resting open position and a rigid component for support. To achieve this, TPU was used for the flexible components, and PLA was used for the rigid components. These two materials have very different surface tensions and mechanical properties, so part geometry was important to make them print-in-place.  

**Print-in-place examples:**  
[Fidget Cube](https://www.thingiverse.com/thing:230139)  
[Dragon](https://www.thingiverse.com/thing:6446798)  
[Ball Bearing](https://www.thingiverse.com/thing:520238) 


  
# Demonstration 
![Pliers GIF](/assets/img/Pliers_GIF.GIF) 


  
# Features 
* **Print-in-Place Multi-Material Design** The pliers were designed with the ability to print all components using a single, multi-material printer in a single print. When printed like this, they can be used without having to assemble any pieces. Despite this, the final version was printed in pieces due to printer constraints. 
* **Flexible TPU Jaws** The plier jaws are designed to be printed out of flexible TPU 95A. When the trigger is pulled, the jaws bend to a closed position, and when the trigger is released, they return to an open position. Using this approach integrates the spring component needed for the plier to return to open position into the jaw design, while simultaneously providing grip for the jaws.  
* **PLA Handle and Trigger System** The handle and trigger of the pliers are designed to be printed out of PLA for comfort and stability. The handle includes curved contours to allow for multiple grip preferences. 
* **Slanted Point for Improved Attack Angle** The tips of the plier’s jaws are tapered upward to all the user to change the attack angle of the jaws while maintaining sufficient surface area contact. The attack angle was increased for the final iteration. 
* **Circular Dovetail Fastening** The jaws use a circular dovetail shape to fasten to the handle and trigger. This is used because PLA and TPU do not adhere to each other when printed. A smaller version of this feature was printed to test the fit. The final fit used was a clearance fit of 0.2 mm.  
* **Thicker Jaws for Stability** The jaw thickness was increased from the first iteration of the design to allow for stabler handling of the pliers. This also allows it to pick up objects that are a little larger than resistors as well. 


  
# CAD Model 
<iframe src="https://vanderbilt643.autodesk360.com/shares/public/SH90d2dQT28d5b6028117c310205d326b193?mode=embed" width="640" height="480" allowfullscreen="true" webkitallowfullscreen="true" mozallowfullscreen="true"  frameborder="0"></iframe> 

 

  
# Specifications 

| Dimension | Value | Unit |
| ----------- | ----------- | ----------- | 
|   Plier Height   |    18     |   mm   | 
|  Jaw Length  |    140    |   mm   | 
|  Jaw Thickness (outer)  |   8   |   mm   | 
|  Jaw Thickness (inner)  |   2.4   |   mm   | 
|   Handle Length   |     160    |    mm    | 
|    Handle Width    |    70    |   mm   | 
|    Trigger Inner Diameter    |    38.4    |   mm   | 
|   Attack Angle   |    30    |    degrees    | 


  
# Print Settings 
## TPU Components 

| Changed Setting | Value |  Reason for Change|  
| ----------- | ----------- | ----------- | 
|   Perimeters   |    3     |   sturdier jaws; stronger dovetail   |  
|   Infill   |   25%; gyroid     |    default   | 
|   Speed   |    25 mm/s     |   smoother surface   | 
|   Nozzle Diameter   |     0.6 mm    |   default   | 

## PLA Components

| Changed Setting | Value |  Reason for Change | 
| ----------- | ----------- | ----------- | 
|   Perimeters   |    3     |   default   |  
|   Infill   |   15%; gyroid     |   default  | 
|   Speed   |    70 mm/s     |   smoother surface   | 
|   Nozzle Diameter   |     0.6 mm    |   default   | 


  
# Image Gallery 

{% include gallery caption="In order (left to right; top to bottom): Final Iteration Pliers, Final Iteration Jaws, Dovetail Test 1, Dovetail Test 2, and Iteration 1 Pliers" %}
