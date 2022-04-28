/**
 * EUSART1 Generated Driver API Header File
 *
 * @file eusart1.h
 *
 * @defgroup eusart1 EUSART1
 *
 * @brief This header file provides APIs for the EUSART1 driver.
 *
 * @version EUSART1 Driver Version 2.1.1
*/

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

#ifndef EUSART1_H
#define EUSART1_H

/**
 * Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "uart_interface.h"

/**
 * Section: Macro Declarations
*/

#define EUSART1_DataReady  (EUSART1_IsRxReady())

/**
 * @ingroup eusart1
 * @typedef union eusart1_status_t
 * @brief These are the Data type definitions
 */
typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}eusart1_status_t;

//*********************************************************************************************************
/**
 * @deprecated
 * Deprecated APIs start
 */
//*********************************************************************************************************

bool __attribute__(( deprecated )) EUSART1_is_tx_ready(void);
bool __attribute__(( deprecated )) EUSART1_is_rx_ready(void);
bool __attribute__(( deprecated )) EUSART1_is_tx_done(void);
eusart1_status_t EUSART1_get_last_status(void);

/*************************************************************************************************************
 * Deprecated APIs end
 *************************************************************************************************************/

extern const struct UART_INTERFACE EUSART1_Interface;

/**
 * Section: EUSART1 APIs
*/

/**
 * @ingroup eusart1
 * @brief This routine initializes the EUSART1 driver.
 *        This routine must be called before any other EUSART1 routine is called.
 * @param none
 * @return none
 */
void EUSART1_Initialize(void);

/**
 * @ingroup eusart1
 * @brief This routine checks if EUSART1 transmitter is ready
 *        to accept and transmit data byte.
 * @param none
 * @retval True  - EUSART1 transmitter is ready
 * @retval False - EUSART1 transmitter is not ready
 */
bool EUSART1_IsTxReady(void);

/**
 * @ingroup eusart1
 * @brief This routine checks if EUSART1 receiver has received data
 *        and ready to be read.
 * @param none
 * @retval True  - EUSART1 receiver is ready for reading
 * @retval False - EUSART1 receiver is not ready for reading
 */
bool EUSART1_IsRxReady(void);

/**
 * @ingroup eusart1
 * @brief This function return the status of transmit shift register.
 * @param none
 * @retval True  - Data completely shifted out from EUSART1 shift register
 * @retval False - Data is not completely shifted out from EUSART1 shift register
 */
bool EUSART1_IsTxDone(void);

/**
 * @ingroup eusart1
 * @brief This routine gets the error status of the last read byte.
 * @param none
 * @return eusart1_status_t - the status of the last read byte.
 */
eusart1_status_t EUSART1_GetLastStatus(void);

/**
 * @ingroup eusart1
 * @brief This routine reads a byte of data from the EUSART1.
 * @param none
 * @return uint8_t - A data byte received by the driver.
 */
uint8_t EUSART1_Read(void);

/**
 * @ingroup eusart1
 * @brief This routine writes a byte of data to the EUSART1.
 * @param uint8_t txData - Data byte to write to the EUSART1
 * @return none
 */
void EUSART1_Write(uint8_t txData);



/**
 * @ingroup eusart1
 * @brief This API sets the function to be called upon EUSART1 framing error
 * @param void (* interruptHandler)(void) - A pointer to the function to be set as framing error handler
 * @return none
 */
void EUSART1_SetFramingErrorHandler(void (* interruptHandler)(void));

/**
 * @ingroup eusart1
 * @brief This API sets the function to be called upon EUSART1 overrun error
 * @param void (* interruptHandler)(void) - A pointer to the function to be set as overrun error handler
 * @return none
 */
void EUSART1_SetOverrunErrorHandler(void (* interruptHandler)(void));

/**
 * @ingroup eusart1
 * @brief This API sets the function to be called upon EUSART1 error
 * @param void (* interruptHandler)(void) - A pointer to the function to be set as error handler
 * @return none
 */
void EUSART1_SetErrorHandler(void (* interruptHandler)(void));



#endif  // EUSART1_H
/**
 End of File
*/
