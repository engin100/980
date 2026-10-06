---
layout: spec
latex: true
---

# Lab 7 Prelab: KiCad Schematic to PCB

## Contents 

- [Lab 7 Prelab: KiCad Schematic to PCB](#lab-7-prelab-kicad-schematic-to-pcb)
  - [Contents](#contents)
  - [Resources](#resources)
  - [Procedure](#procedure)
    - [Onwards and Upwards (Upwards = to PCB Design)](#onwards-and-upwards-upwards--to-pcb-design)
    - [Design Rules](#design-rules)
    - [Design Rule Check](#design-rule-check)
    - [PCB General View and Sizing](#pcb-general-view-and-sizing)
    - [Editing Part Placement on PCB](#editing-part-placement-on-pcb)
    - [Traces](#traces)
    - [Layers to Worry About](#layers-to-worry-about)
    - [Polygon Ground Pour](#polygon-pour)
    - [Trace Width Guidelines](#trace-width-guidelines)
  - [Submission](#submission)

## Resources

- [ ] A computer running the latest stable version of KiCad
- [ ] [KiCad Power Board libraries .zip file](https://drive.google.com/file/d/1-PR87u7RzkhpizaJybwOJ49HODIKl4W9)
- [ ] [Youtube Tutorial](https://www.youtube.com/watch?v=NHHwZCHNMq8)
<!--
 [Spreadsheet of Footprints](https://drive.google.com/file/d/1tsC8cM-wiYfIB25BBM7o7ymhQ4F3gtD8)
 [Second Spreadsheet of Footprints](https://drive.google.com/file/d/1LVTbnMMa6W0KI2mwZwTfUbNu1QJWeqjq)
note these are outdated footprints which do not have the BME sensor.
-->

## Procedure

This is the second part of the introduction to KiCad. In this assignment, you will draw a schematic for a power board and then turn that schematic into a PCB. There has been a video created that walks through all of the steps of making the schematic and then making a PCB. It is a relatively long process (the video is about an hour), but it really shows you all of the steps of going through the process. [The video is here.](https://www.youtube.com/watch?v=NHHwZCHNMq8)

### Onwards and Upwards (Upwards = to PCB Design)

- Save your schematic document
- Go to PCB editor
- Tools -> Update PCB from schematic
- Now the fun begins!

### Design Rule Check

- Ensure you are achieving mechanical specs set by the manufacturer based on the fidelity of their equipment
- To edit a design rule, go to **File -> Board Setup -> Design Rules**
- Enter the value (and units) that is specified and click OK
- Once you have all rules edited per the guidelines, click **Inspect -> Design Rules Checker** to run the DRC
    - Click on Run Design Rule Check on bottom left
- You need ZERO errors and warnings before you can manufacture the design, we will require it as part of your final submission (unless it is a silkscreen error, those are just aesthetics)
- You will also need some pre-defined sizes. These are listed below in Design Rules

### Design Rules

- All below are minimum values
- 0.25 mm minimum clearance
- 0.15 mm trace width
- 0.25 mm copper to hole clearance
- 0.3 mm min through hole size
- 0.45 mm hole to hole clearance
- 0.15 mm annular width
- 1 mm copper to edge clearance
- **Predefined sizes**
     - Tracks - 0.4 mm and 0.5 mm
        - (0.5 mm traces will be used for power)
     - Vias - Diameter 0.6 mm, Hole 0.3 mm

<div class="primer-spec-callout danger" markdown="1">
Make sure when you are placing traces or vias, that you are selecting these predefined sizes. (I know the video doesn't go over this). Here's what that looks like
  
<img width="604" height="165" alt="image" src="https://github.com/user-attachments/assets/35e237e2-7fe1-4e3d-9b0a-cac2cde7e882" />
</div>

### PCB General View and Sizing

- In the PCB editor, use **View -> 3D Viewer** to see your board in 3D
    - Good to see your board in 3D and see components/traces on the top/bottom
    - Rotate in the 3D viewer using your left mouse button
- Use the tool shown here to view and select different layers
- <img width="262" height="173" alt="image" src="https://github.com/user-attachments/assets/5c0098a8-7e3f-4db0-b0b6-25ed41e1a063" />

### Editing Part Placement on PCB

- Click on part to drag it
- You can rotate the part by pressing R while clicking/dragging the component
- You can switch the component between top and bottom layers by toggling the F key while selecting the component
- HIGHLY HIGHLY suggest placing all the parts before you start connecting them
- Don’t worry if the cyan guide lines are intersecting; traces can be drawn around them if needed
- You can move parts around after you start connecting them if needed, just have a general idea of where they will all be on the board
- If you move parts after placing a ground pour, make sure to refill the zone afterward, we will talk about zones and ground planes later.
- After placing all the parts in a desired location
     - You will now make the shape of your PCB
- Go to the Edge Cuts layer
  <img width="204" height="332" alt="image" src="https://github.com/user-attachments/assets/21c94458-92db-413b-a7d4-91f6c69e9c14" />
  
- Then, use these tools here to draw any shape you want your PCB to be in
  <img width="41" height="97" alt="image" src="https://github.com/user-attachments/assets/13b182f6-dd76-4609-982a-0c4d63587185" />
  
  - Now, if you go to the 3D viewer, you can visualize the shape of your PCB


### Traces

- Route -> Route Single Track to place the trace, or use the hotkey X
- Make sure you know which layer of the board you are on
    - We are using a two layer so the only two layers traces should be on are “Top Layer” and “Bottom Layer”. These are by default named F.cu and B.cu
    - <img width="255" height="100" alt="image" src="https://github.com/user-attachments/assets/7cb89909-80c7-43e1-a82d-70036ca1e7ed" />
  
- Can adjust layer of trace after placing on board by right clicking on the trace -> properties -> Layer
- While routing, use the via tool to place a via (keyboard shortcut 'V')
    - A via allows you to switch to the other side of the board
- Trace Guidelines are provided at end of presentation

### Layers To Worry About

- Top Layer - Top of the board electrical connections (F.cu)
- Bottom Layer - Bottom of the board for electrical connections (B.cu)
- F.Silkscreen - Your silkscreen for the top layer; edit labels and add any text
- B.Silkscreen - Your silkscreen for the bottom layer; edit labels and add any text

### Polygon Pour

- A very common industry standard is to use a polygon pour so you don't have to run a lot of lines to ground and/or power
- A pour that is usually used is a (ground) GND over the entire bottom layer
- For example, if you add a Polygon pour for the GND net for the entire bottom layer, then all components that have GND pins in the bottom layer will all be connected and you do not need traces to connect them
- Make sure you have selected the layer you want to place your polygon pour (F.cu or B.cu)
 <img width="200" height="101" alt="image" src="https://github.com/user-attachments/assets/c03d753e-82f8-4259-b1e6-0cccb52bc62c" />
 
- Use the Add Filled Zone tool from the right toolbar (or Place -> Add Filled Zone)
<img width="200" height="66" alt="image" src="https://github.com/user-attachments/assets/e99fe28d-0ec8-43da-9bc4-4dbe93c1749e" />

- Click one corner of the PCB to start, it does not matter which corner.
- Under Net Options, select the net you’d like to connect to
    - The net should have been defined in your schematic (i.e. GND, 5V, BAT, 3.3V)
- Under layer, select the layer you’d like this pour to be on
- Click OK, then click around until you are satisfied with the shape, then press Esc to finish the outline. Use the **Fill All Zones** tool (or the toolbar button) to fill the zone.
    - You can adjust dimensions of the zone later if needed.
    - Every single time you adjust components from now on, you'll need to refill the zone afterward (this is why you may want to wait until the end to do the zone).
- You can use vias to connect your Surface Mount Components to the Ground pour, or do a ground pour on both the top and bottom layer. That will cover the surface mount components.


### Trace Width Guidelines

- Power lines to the input of the LDOs = 0.8 mm
- Output of LDOs to electrolytic capacitors and status LEDs = 0.6 mm
- All other traces = 0.4 mm


## Submission

On Canvas, you will submit ***ONE PDF*** that will include all of the following:

- [ ] A screenshot of the schematic you made
- [ ] Screenshots of the PCB you made (**Both sides**)
- [ ] Screenshot(s) of the PCB passing all design rule checks

Export/Download this document as a PDF and upload it. **DO NOT SUBMIT A GOOGLE DOC FILE**.

<div class="primer-spec-callout danger" markdown="1">
Submitting anything other than a single PDF may result in your work not being graded or your scores being heavily delayed.
</div>