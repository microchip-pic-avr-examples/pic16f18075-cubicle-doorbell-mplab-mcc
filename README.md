<!-- Please do not change this logo with link -->
[![MCHP](images/microchip.png)](https://www.microchip.com)

# Wireless Cubicle Doorbell

This example shows how to create a wireless cubicle doorbell for an office setting, using a capacitive touch button, two Bluetooth® modules and a NeoPixel® LED strip.

## Related Documentation

- [PIC16F18075 Data Sheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC16F18054-55-74-75-28-40-Pin-Micorocontroller-Data-Sheet-40002338.pdf)
- [PIC16F18075 Family Product Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic16f18076?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github)
- [Wireless Cubicle Doorbell Application Note](https://www.microchip.com/en-us/application-notes/an3313)
- [RNBD451 User Guide](https://onlinedocs.microchip.com/oxy/GUID-26457D23-798C-47B0-9F40-C5DA6E995C6F-en-US-1/index.html)



## Software Used

- [MPLAB® X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github) 6.10 or newer
- [MPLAB XC8](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github) 2.41 or a newer compiler 
- [MPLAB Code Configurator (MCC)](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github) 5.7.7 or newer 
- [MPLAB Melody Library](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github) 2.5.0 or newer 
- [Microchip PIC16F1xxxx Series Device Support pack](https://packs.download.microchip.com/) 1.18.352 or newer Device Pack

## Hardware Used
- [PIC16F18075 Microcontroller](https://www.microchip.com/en-us/product/pic16f18075?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github) (x2)
- [Curiosity High Pin Count (HPC) Development Board](https://www.microchip.com/en-us/development-tool/DM164136?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github) (x2)
- [RNBD451 Bluetooth Low Energy (BLE) Module](https://www.microchip.com/en-us/development-tool/EV25F14A?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github&utm_bu=MCU08) x2
- [MikroElektronika Cap Touch Click Board™](https://www.mikroe.com/cap-touch-click)
- [Adafruit® NeoPixel® 8 x 5050 RGB LED Stick](https://www.adafruit.com/product/1426)
- Jumper wires

## Setup - Wiring

two separate components connected wirelessly through their respective Bluetooth modules. These components include the door module, which functions as the conventional doorbell in the demonstration, and the desk module, which serves as the traditional door chime in the demonstration.

**Note:** This demo was initially created using Bluetooth classic technology with the [RN4876 module](https://www.mikroe.com/rn4678-click), but was later adapted for BLE using the [RNBD451 module](https://www.microchip.com/en-us/development-tool/EV25F14A?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic16f18076&utm_content=pic16f18075-cubicle-doorbell-mplab-mcc-github&utm_bu=MCU08). The two modules are interchangeable, except for one line of code. However, the configuration is expected to function for both modules.

### Door Module Wiring

The door module uses a Cap Touch Click as the button, and a RNBD451 Bluetooth module to send the signal wirelessly to the desk module.

The Cap Touch Click connects to the PIC16F18075 by linking the OUT pin on the Click board to an input pin (RB0) of the microcontroller. The MOD pin on the Click board determines the mode of operation (Fast/Low Power mode) and is on RD1 of the PIC16F18075.

The RNBD451 Bluetooth module connects to the PIC16F18075 through the RTS, CTS, RXD, TXD, RST, and SW_RST pins. The CTS and TXD pins are configured as input pins on the PIC16F18075, while the RTS, RXD, RST and SW_RST pins are configured as output pins.

Figure 1 shows the connections made between the Cap Touch Click, the RNBD451 Bluetooth module and the PIC16F18075 for the door module.

*Figure 1 - Door Module Circuit Diagram*

![Door Module - Wiring Diagram](images/Full_Door_Module_to_PIC_Connections.png)

### Desk Module Wiring
The desk module includes the Adafruit NeoPixel Stick and one RN4678 Bluetooth Click. The RN4678 Bluetooth Click is used to receive the signal from the door module when somebody presses the capacitive touch button, then the Adafruit NeoPixel Stick flashes to get the attention of the person inside the cubicle.

The Adafruit NeoPixel Stick connects to the PIC16F18075 by linking the DIN pin to any output pin of the microcontroller. In this example, RA0 was selected as the output pin. A 4-pin header will need to be soldered onto the back of the Adafruit NeoPixel before connecting to the PIC16F18075.  Figure 2 shows where to connect the 4-pin header (see the red box).

*Figure 2 - Adafruit NeoPixel - Back Side*

![Adafruit NeoPixel - back side](images/Adafruit_NeoPixel_back_side.png)

The RNBD451 Bluetooth module connects to the PIC16F18075 the same way as on the door module.

Figure 3 shows the connections made between the Adafruit NeoPixel Stick, RNBD451 Bluetooth Module and the PIC16F18075 for the desk module.

*Figure 3 - Desk Module Circuit Diagram*

![Desk Module - Wiring Diagram](images/Full_Desk_Module_to_PIC_Connections.png)

## Setup - Programming
### Door/Desk Module Environment Setup
- Download, install and open MPLABX IDE version 6.00 (or newer)

- Download and install the XC8 C-Compiler version 2.36 (or newer)

- Open the `pic16f18075-cubicle-doorbell-mplab-mcc.X` project as shown in Figure 4

*Figure 4 - Open Project Menu in MPLABX*

![Open Project Menu in MPLABX](images/Open_Project_Menu_in_MPLABX.PNG)

### Program Code, Configurations and Functions Overview

The project file above includes all the needed code and configurations for both the Door and Desk modules.  There are two `main.c` files that contain the driving code for each of the modules (Figure 5 below).  By selecting the configuration that matches the module and free/pro status (see Table 1 and Figure 6 below), one of the `main.c files` will be excluded from being programmed (gray `Desk_Module_main.c` file in Figure 5). This exclusion results in the correct `main.c` file being programmed to the device for the selected module, so that the same MPLABX project can be used for the door module and desk modules.

*Figure 5 - Main.c File Organization Using the pro_door Configuration Setting*

![Pro Door Main.c visual](images/pro_door_main-c_visual.png)


*Figure 6 - Configuration List for MPLABX*

![Configuration List for MPLABX](images/Configuration_List_for_MPLABX.png)


*Table 1 - Configuration List Selection by Module and Free/Pro Setting*

| Module      | Free/Pro | Configuration     |
| :---        |    :----:   |          ---: |
| Door      | Pro       | pro_door   |
| Door   | Free        | free_door      |
| Desk   | Pro        | pro_desk      |
| Desk   | Free        | free_desk      |

Each of the `main.c` files will use a series of functions that are built utilizing the existing APIs generated from the Melody configuration.  Tables 2 and 3 below each give an overview of the functions used for either the NeoPixel or RNBD451 Bluetooth Module. 

#### NeoPixel Functions
There are seven custom-written functions used to control the NeoPixel in this example. Table 2 provides a list of each function along with its description. These functions can be found within the `Desk_Module_main.c` file.

*Table 2 - NeoPixel Functions and Descriptions*

| Function      | Description |
| :----:        |    :----:   |
| ``` onePulse() ```      | Sends a 1-code (HIGH) to the NeoPixel using the correct timing       |
| ``` zeroPulse() ```   | Sends a 0-code (LOW) to the NeoPixel using the correct timing        |
| ``` LED_send_byte(K) ```  | Checks the K byte to see if a 1-code or 0-code needs to be sent        |
| ```LED_Array(R, G, B)```| Inputs the R/G/B values (max of 255) to set the brightness of each color for an individual LED and sends in the correct order for the NeoPixel to interpret them accurately |
| ``` RED() ```   | Makes all eight LEDs display the highest intensity red |
| ``` OFF() ```   | Turns all eight LEDs off        |
| ``` RED_BLINK_500ms() ```| All eight LEDs blink red and then turn off at a 500 ms interval        |

#### RNBD451 Functions
There are 5 custom-written functions used to control the RNBD451 in this example. Table 3 provides a list of each function along with its description. These functions can be found within both the `Desk_Module_main.c` file and the `Door_Module_main.c` file.
  
*Table 3 - RNBD451 Functions and Descriptions*

| Function   | Description |
| :----:       |    :----:   |
| ``` BT_initialConditions() ```  | Sets the initial conditions for the RNBD451 Bluetooth module |
| ``` BT_initialize() ```  | Puts the RNBD451 Bluetooth module into a state where is it able to receive EUSART data |
| ``` BT_enterCommandMode() ```  | Sends the `$$$` command over EUSART which shifts the RNBD451 Bluetooth module into Command mode |
| ``` BT_connect() ```  | Connects to the device which matches the specificed MAC address (stored within the function)  |

There are 4 `#defines` that need to be changed depending on your configuration in `Desk_Module_main.c`, lines 23-27:

```c
#define NUM_FLASHES 3 // number of times LED array flashes
#define NUM_LEDS 8 // number of LEDs used
#define MAC_ADDR "9C956E40667B" // MAC address of device
#define RNBD451 // this module makes code run BLE commands
//#define RN4678 // this module makes code run BT classic commands
```
[This webpage](https://onlinedocs.microchip.com/oxy/GUID-A87FCFF4-A9D1-4EA7-905C-92DA42132554-en-US-1/GUID-113B0BEA-BE7E-4BA9-AD01-09DD06A2C917.html) details how to find the MAC address for the RNBD451 module, and [this one](https://ww1.microchip.com/downloads/en/DeviceDoc/RN4678-Bluetooth-Dual-Mode-Module-Command-Reference-User-Guide-DS50002506C.pdf) shows for the RN4678 module.

## Programming the PIC16F18075
The Curiosity HPC board includes a programmer that can program the PIC16F18075. Connect it to your computer via USB and click the **Make and Program Device** button for the the device to program. Check that the correct configuration is selected from the configuration list drop-down menu for the programmed device, either desk or door side.

*Figure 8 - Make and Program Device Button*

![Make and Program Device Button](images/Make_and_Program_Device_Button.png)

*Figure 9 - Device Programming Successful*

![Device Programming Successful](images/Device_Programming_Successful.png)

## Operation
After programming the desk and door modules, you can now touch the capacitive touch click to "ring" the doorbell.

*Functional Doorbell*

![Cap Touch Click being Pressed and the Adafruit NeoPixel flashing](images/Cap_Touch_click_pressed_and_NeoPixel_Flashing.gif)

### How to change Any Other Bluetooth Settings

The RNBD451 Bluetooth Click has many different settings that are not described within this example.  For any additional setting changes, follow these steps:
     
1. Make sure that all the RNBD451 Bluetooth Click pins are connected to the PIC16F18075 (see Figure 1  or 3 above).

2. Disconnect the TXD and RXD connections between the PIC16F18075 and the RN4678 Bluetooth Click.

3. Using a USB-to-UART device, connect the TXD and RXD pins from the RNBD451 Bluetooth Module to that device.

4. Now follow the instructions used with the command guide for changing any of the settings.  The command guide can be found in the [RNBD451 User Guide](https://onlinedocs.microchip.com/oxy/GUID-26457D23-798C-47B0-9F40-C5DA6E995C6F-en-US-1/index.html).
     
## Summary
This example has shown how to use a Cap Touch Click, an AdaFruit NeoPixel and two RNBD451 Bluetooth modules to create a cubicle doorbell system that uses the PIC16F18075 microcontroller.