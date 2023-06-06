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

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    BT_initialConditions();
    BT_initialize();

    uint8_t payload = 0;
    
    while (1)
    {
        if (PORTBbits.RB0 == HIGH){ 
            while(PORTBbits.RB0 == HIGH); // wait for button to be released
            __delay_ms(10);
            payload = '1';
            EUSART1_Write(payload);
            __delay_ms(10);
        }
    }    
}