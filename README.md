<img width="2250" height="3450" alt="zine_page" src="https://github.com/user-attachments/assets/b4015808-6fad-4db4-896c-b59ee94b27cf" />



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
<img width="1321" height="752" alt="image" src="https://github.com/user-attachments/assets/cbb0d944-4f7a-4fd6-b226-9f199946800d" />
<img width="1288" height="892" alt="image" src="https://github.com/user-attachments/assets/97d341bf-0228-41b6-9c3c-042bd5814bf6" />


### ROUTING
<img width="950" height="975" alt="routing" src="https://github.com/user-attachments/assets/86a75d5e-221b-4848-80ac-b43251dbb5ac" />

### SCHEMATIC

<img width="1531" height="855" alt="image" src="https://github.com/user-attachments/assets/a469540a-6040-448a-a4f0-806cb2855b1d" />

### CASE
## IMPORTANT: THIS IS NOT THE NEWEST VERSION OF THE CASE BUT IT USES THE EXACT SAME FRICTION FIT SO IT ALSO WORKS ON THE NEW VERSION.

https://github.com/user-attachments/assets/e5118ca8-60bc-48c1-94f0-9f646d53b27a

### PROOF THAT MY FRICTION FIT WORKS

https://github.com/user-attachments/assets/f6ddad3f-a20b-4f4a-b254-9df56e5059d4







# Build Your Own

## PCB and Parts

| Reference         | Qty | Value         | Description                                      | Price EUR | Pack Info | Link                                                        |
| ----------------- | --: | ------------- | ------------------------------------------------ | --------: | --------- | ----------------------------------------------------------- |
| Brd1              |   1 | 128x64 OLED   | SSD1306                                          |      2.89 | 1 pc      | [Buy](https://de.aliexpress.com/item/1005006514489341.html) |
| R1 R2 R3 R4 R5 R6 |   6 | 1k Ohm        | R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal |      3.30 | 20 pcs    | [Buy](https://amzn.eu/d/0aSOhZVj)                           |
| U1 U2             |   2 | USB-C Module  | USB-C connector module to connect the cable to   |      1.61 | 5 pcs     | [Buy](https://de.aliexpress.com/item/1005007314733520.html) |
| U3                |   1 | ESP32-DevKitC | ESP32 development board                          |      2.99 | 1 pc      | [Buy](https://de.aliexpress.com/item/1005006140555903.html) |
| Battery | 1 | 654060 Li-Po 200mAh | Lithium polymer battery | 9.90 | 1 pc | [Buy]([https://de.aliexpress.com/item/1005005970679252.html) |
| Charger Module | 1 | TP4057 | USB-C charging module | 3.83 | 1 pc | [Buy](https://de.aliexpress.com/item/1005010764961491.html) |


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
I printed the case already the friction fit works perfectly fine and the battery mount fits exactly as it should also the code and pcb are working perfectly too I tested it all already. 


## Programming 

**Install the following libraries** (you can find them under firmware/libraries or the library manager:
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


To the reviewer if you wonder about the 3d models of the usb-c ports on the pcb I sadly couldnt find any 3d models of it and I was told to just keep it like this. 

Everything is designed to fit snugly without additional hardware.
