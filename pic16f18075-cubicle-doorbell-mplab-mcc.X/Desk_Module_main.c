/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

#define NUM_FLASHES 3 // number of times LED array flashes

/*********NEOPIXEL FUNCTIONS************/
//Send a 1-code, a HIGH, using the correct timing to the NeoPixel
void onePulse(void){
    LATAbits.LATA0 = 1;
    LATAbits.LATA0 = 1;
    LATAbits.LATA0 = 1;
    LATAbits.LATA0 = 0;
}
//Send a 0-code, a LOW, using the correct timing to the NeoPixel
void zeroPulse(void){
    LATAbits.LATA0 = 1;
    LATAbits.LATA0 = 0;
}
//Check the K byte for if you should send a 1-code or 0-code
void ws_send_byte (unsigned char K){
    if (K % 0x80){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x40){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x20){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x10){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x8){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x4){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x2){
        onePulse();
    } else {
        zeroPulse();
    }
    if (K % 0x1){
        onePulse();
    } else {
        zeroPulse();
    }
}
//Input the values R,G,B (max of 255) to set the brightness for each color for an individual LED
//Sends in the correct order so the NeoPixel can understand
void LED_Array(unsigned char R, unsigned char G, unsigned char B){
    ws_send_byte(G);
    ws_send_byte(R);
    ws_send_byte(B);
}
//Make all 8 LEDs turn to the brightest Red possible
void RED(){
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    LED_Array(255, 0, 0);
    __delay_ms(10);
}
//Turn all 8 LEDs off
void OFF(){
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    LED_Array(0, 0, 0);
    __delay_ms(10);
}
//All 8 LEDs blink Red and then turn off at a 500ms interval
void RED_BLINK_500ms(){
        RED();
        __delay_ms(500);
        OFF();
        __delay_ms(500);
}

/*********RN4678 BLUETOOTH FUNCTIONS************/

//Set initial conditions for RN4678 Click
void BT_initialConditions(void){
    LATAbits.LATA1 = LOW;
    LATDbits.LATD0 = LOW;
    LATBbits.LATB5 = HIGH; 
}
//Put the RN4678 Click into a state where is it able to receive EUSART data
void BT_initialize(void){
    __delay_ms(15);
    LATAbits.LATA1 = HIGH;
    __delay_ms(40);
    LATDbits.LATD0 = HIGH;
    __delay_ms(435);
    LATBbits.LATB5 = LOW; 
    __delay_ms(40);  
}
//Sends the '$$$' command over EUSART which enters the RN4678 Click into Command Mode
void BT_enterCommandMode(void){
    for (uint8_t i = 0; i<3; i++){
        EUSART1_Write('$');
        __delay_ms(1);
    }
    __delay_ms(30);
}
//Scan for available Bluetooth Connections
void BT_scan(void){
    uint8_t scan[] = {'F','\r'};
    uint8_t len = sizeof(scan);
    for (uint8_t cnt = 0; cnt < len; cnt++){
        EUSART1_Write(scan[cnt]);
        __delay_ms(1);
    }
    __delay_ms(10040);  
    __delay_ms(12000); 
}
//Connect to the device which has the MAC Address E8EB1B9028FA
//If a different device is used then the MAC Address will be different
void BT_connect(void){
    //NOTE: Make sure to change this to the MAC Address of the device that is being used
    uint8_t MACadd[] = {'C',',','E','8','E','B','1','B','9','0','2','8','F','A','\r'};
    uint8_t len = sizeof(MACadd);
    for (uint8_t cnt = 0; cnt < len; cnt++){
        EUSART1_Write(MACadd[cnt]);
        __delay_ms(1);
    }
    __delay_ms(440);
}

int main(void)
{
    SYSTEM_Initialize();
    BT_initialConditions();
    BT_initialize();
    
    BT_enterCommandMode();
    BT_scan();
    BT_connect();
    __delay_ms(2000);
    
    uint8_t payload = 0;
    while(1)
    {
        payload= EUSART1_Read();
        __delay_ms(10);
        //Check to see if the payload is 1 AKA the doorbell has been pressed and blink the LED strip on and off NUM_FLASHES times 
        if(payload == '1'){ 
            for (uint8_t i = 0; i < NUM_FLASHES; i++){
                RED_BLINK_500ms();
            }
        }
        else{
            OFF();
        }
    }    
}