<img width="2250" height="3450" alt="zine_page" src="https://github.com/user-attachments/assets/2ed36fa1-d9cc-4245-a218-4657d760afec" />


# CableProbe

A custom ESP32-based tool to analyze and verify USB-C cables.


## Features

### Analysis
- Basic connectivity check
- Problem detection
- Power troughput & quality
- Fast Charging / Power Delivery support
- General-purpose suitability testing


## Hardware

- ESP32 on a custom PCB
- 2x USB-C modules linked to GPIOs
- 128x64 SSD1306 OLED display
- Basic resistor setup for pin pulling


## Why?

Ever bought a pile of cheap USB-C cables from AliExpress only to find out they are bad? Or struggled to figure out which cable actually supports fast charging?

CableProbe was made to quickly sort through the cable drawer. It identifies the quality and features of almost any USB-C cable without needing a PC or complicated setup.


## Usage

Simply plug both ends of your cable into the USB-C modules and follow the instructions on the screen.

The ESP32 will run through the pins and display the results on the screen. It immediately tells you whether the cable is suitable for:
- charging only,
- fast charging,
- or high-speed applications.


## Images


### Case

<img width="1277" height="936" alt="image" src="https://github.com/user-attachments/assets/70759fb6-b77a-4ec2-95de-a82f57ab8058" />


### PCB
<img width="950" height="684" alt="pcb_bottom" src="https://github.com/user-attachments/assets/a61f7669-e9a4-4819-8e90-3f8fa5a18d07" />
<img width="950" height="725" alt="pcb_top" src="https://github.com/user-attachments/assets/ff244258-df8e-4393-8c57-e0848a2a25be" />

### ROUTING
<img width="950" height="975" alt="routing" src="https://github.com/user-attachments/assets/86a75d5e-221b-4848-80ac-b43251dbb5ac" />

### SCHEMATIC

<img width="1531" height="855" alt="image" src="https://github.com/user-attachments/assets/a469540a-6040-448a-a4f0-806cb2855b1d" />



# Build Your Own

## PCB and Parts

| Reference         | Qty | Value         | Description                                      | Price EUR | Pack Info | Link                                                        |
| ----------------- | --: | ------------- | ------------------------------------------------ | --------: | --------- | ----------------------------------------------------------- |
| Brd1              |   1 | 128x64 OLED   | SSD1306                                          |      2.89 | 1 pc      | [Buy](https://de.aliexpress.com/item/1005006514489341.html) |
| R1 R2 R3 R4 R5 R6 |   6 | 1k Ohm        | R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal |      3.30 | 20 pcs    | [Buy](https://amzn.eu/d/0aSOhZVj)                           |
| U1 U2             |   2 | USB-C Module  | USB-C connector module to connect the cable to   |      1.61 | 5 pcs     | [Buy](https://de.aliexpress.com/item/1005007314733520.html) |
| U3                |   1 | ESP32-DevKitC | ESP32 development board                          |      2.99 | 1 pc      | [Buy](https://de.aliexpress.com/item/1005006140555903.html) |


The PCB is a simple custom design made to hold the ESP32, USB-C modules, and OLED display in a compact enclosure.


## Soldering 


Recommended order:
1. Resisorts
2. ESP32
3. USB-C modules
4. OLED display

No special equipment needed. Steady hand could be useful.


## Case

3D print the provided STL files.

Both PLA and PETG work perfectly fine. I recommend to use pla. 


## Programming 

**Install the following libraries** (you can find them under code/libraries or the library manager:
- *Adafruit_GFX.h*
- *Adafruit_SSD1306.h*

  
**Flashing** is straightforward:
1. Open 'main.ino' form the 'code' folder in your prefered IDE.
2. Select the correct ESP32 board (ESP32 devkit).
3. Hit upload


## Assembly 

1. Drop the PCB into the bottom half of the case
2. Connect the battery to the charger module. (B+/- to charger module and output of that to V+/GND pin) it is not on the pcb on purpose as this saves up a lot of space and still works perfectly fine (even better, as bc of this the battery placement is more flexible. Just click the charger module in the space on the bottom of the case. It fits perfectly and whithholds a lot of strenght.
3. Allign the USB-C ports with the openings
4. Fit the OLED display into place
5. Close the enclosure

Everything is designed to fit snugly without additional hardware.
