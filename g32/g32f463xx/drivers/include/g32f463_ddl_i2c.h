/**
  *
  * @file    g32f463_ddl_i2c.h
  * @brief   Header file of I2C DDL module.
  * @version V1.0.0
  * @date    2025-08-08
  * 
  * @attention
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of the copyright holder nor the names of its contributors
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  * The original code has been modified by Geehy Semiconductor.
  * Copyright (c) 2016 STMicroelectronics. Copyright (C) 2025 Geehy Semiconductor.
  * All rights reserved.
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32F463_DDL_I2C_H
#define G32F463_DDL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (I2C1) || defined (I2C2)

/** @defgroup I2C_DDL I2C
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2C_DDL_Private_Constants I2C Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup I2C_DDL_Private_Macros I2C Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup I2C_DDL_ES_INIT I2C Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t PeripheralMode;      /*!< Specifies the peripheral mode.
                                     This parameter can be a value of @ref I2C_DDL_EC_PERIPHERAL_MODE.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C_SetMode(). */

  uint32_t Timing;              /*!< Specifies the SDA setup, hold time and the SCL high, low period values.
                                     The helper macro @ref __DDL_I2C_CONVERT_TIMINGS().

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C_SetTiming(). */

  uint32_t DigitalFilter;       /*!< Configures the digital noise filter.
                                     This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x0F.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C_SetDigitalFilter(). */

  uint32_t OwnAddress1;         /*!< Specifies the device own address 1.
                                     This parameter must be a value between Min_Data = 0x00 and Max_Data = 0x3FF.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C_SetOwnAddress1(). */

  uint32_t TypeAcknowledge;     /*!< Specifies the ACKnowledge or Non ACKnowledge condition after the address receive
                                     match code or next received byte.
                                     This parameter can be a value of @ref I2C_DDL_EC_I2C_ACKNOWLEDGE.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C_AcknowledgeNextData(). */

  uint32_t OwnAddrSize;         /*!< Specifies the device own address 1 size (7-bit or 10-bit).
                                     This parameter can be a value of @ref I2C_DDL_EC_OWNADDRESS1.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C_SetOwnAddress1(). */
} DDL_I2C_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup I2C_DDL_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_DDL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with DDL_I2C_WriteReg function
  * @{
  */
#define DDL_I2C_INTFCLR_ADDRMCLR                I2C_INTFCLR_ADDRMCLR        /*!< Address Matched flag   */
#define DDL_I2C_INTFCLR_NACKCLR                 I2C_INTFCLR_NACKCLR         /*!< Not Acknowledge flag   */
#define DDL_I2C_INTFCLR_STOPCLR                 I2C_INTFCLR_STOPCLR         /*!< Stop detection flag    */
#define DDL_I2C_INTFCLR_BERRCLR                 I2C_INTFCLR_BERRCLR         /*!< Bus error flag         */
#define DDL_I2C_INTFCLR_ALCLR                   I2C_INTFCLR_ALCLR           /*!< Arbitration Lost flag  */
#define DDL_I2C_INTFCLR_OVRURCLR                I2C_INTFCLR_OVRURCLR        /*!< Overrun/Underrun flag  */
#define DDL_I2C_INTFCLR_PECECLR                 I2C_INTFCLR_PECECLR         /*!< PEC error flag         */
#define DDL_I2C_INTFCLR_TTECLR                  I2C_INTFCLR_TTECLR          /*!< Timeout detection flag */
#define DDL_I2C_INTFCLR_SMBALTCLR               I2C_INTFCLR_SMBALTCLR       /*!< Alert flag             */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with DDL_I2C_ReadReg function
  * @{
  */
#define DDL_I2C_STS_TXBEFLG                     I2C_STS_TXBEFLG             /*!< Transmit data register empty        */
#define DDL_I2C_STS_TXINTFLG                    I2C_STS_TXINTFLG            /*!< Transmit interrupt status           */
#define DDL_I2C_STS_RXBNEFLG                    I2C_STS_RXBNEFLG            /*!< Receive data register not empty     */
#define DDL_I2C_STS_ADDRMFLG                    I2C_STS_ADDRMFLG            /*!< Address matched (slave mode)        */
#define DDL_I2C_STS_NACKFLG                     I2C_STS_NACKFLG             /*!< Not Acknowledge received flag       */
#define DDL_I2C_STS_STOPFLG                     I2C_STS_STOPFLG             /*!< Stop detection flag                 */
#define DDL_I2C_STS_TXCFLG                      I2C_STS_TXCFLG              /*!< Transfer Complete (master mode)     */
#define DDL_I2C_STS_TXCRFLG                     I2C_STS_TXCRFLG             /*!< Transfer Complete Reload            */
#define DDL_I2C_STS_BERRFLG                     I2C_STS_BERRFLG             /*!< Bus error                           */
#define DDL_I2C_STS_ALFLG                       I2C_STS_ALFLG               /*!< Arbitration lost                    */
#define DDL_I2C_STS_OVRURFLG                    I2C_STS_OVRURFLG            /*!< Overrun/Underrun (slave mode)       */
#define DDL_I2C_STS_PECEFLG                     I2C_STS_PECEFLG             /*!< PEC Error in reception (SMBus mode) */
#define DDL_I2C_STS_TTEFLG                      I2C_STS_TTEFLG              /*!< Timeout detection flag (SMBus mode) */
#define DDL_I2C_STS_SMBALTFLG                   I2C_STS_SMBALTFLG           /*!< SMBus alert (SMBus mode)            */
#define DDL_I2C_STS_BUSBSYFLG                   I2C_STS_BUSBSYFLG           /*!< Bus busy                            */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_IT IT Defines
  * @brief    IT defines which can be used with DDL_I2C_ReadReg and  DDL_I2C_WriteReg functions
  * @{
  */
#define DDL_I2C_CTRL1_TXIEN                     I2C_CTRL1_TXIEN             /*!< TX Interrupt enable                         */
#define DDL_I2C_CTRL1_RXIEN                     I2C_CTRL1_RXIEN             /*!< RX Interrupt enable                         */
#define DDL_I2C_CTRL1_SADDRMIEN                 I2C_CTRL1_SADDRMIEN         /*!< Address match Interrupt enable (slave only) */
#define DDL_I2C_CTRL1_NACKRXIEN                 I2C_CTRL1_NACKRXIEN         /*!< Not acknowledge received Interrupt enable   */
#define DDL_I2C_CTRL1_STOPIEN                   I2C_CTRL1_STOPIEN           /*!< STOP detection Interrupt enable             */
#define DDL_I2C_CTRL1_TXCIEN                    I2C_CTRL1_TXCIEN            /*!< Transfer Complete interrupt enable          */
#define DDL_I2C_CTRL1_ERRIEN                    I2C_CTRL1_ERRIEN            /*!< Error interrupts enable                     */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_PERIPHERAL_MODE Peripheral Mode
  * @{
  */
#define DDL_I2C_MODE_I2C                    0x00000000U               /*!< I2C Master or Slave mode                 */
#define DDL_I2C_MODE_SMBUS_HOST             I2C_CTRL1_HADDREN         /*!< SMBus Host address acknowledge           */
#define DDL_I2C_MODE_SMBUS_DEVICE           0x00000000U               /*!< SMBus Device default mode
                                                                         (Default address not acknowledge)        */
#define DDL_I2C_MODE_SMBUS_DEVICE_ARP       I2C_CTRL1_DEADDREN        /*!< SMBus Device Default address acknowledge */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_ADDRESSING_MODE Master Addressing Mode
  * @{
  */
#define DDL_I2C_ADDRESSING_MODE_7BIT         0x00000000U              /*!< Master operates in 7-bit addressing mode. */
#define DDL_I2C_ADDRESSING_MODE_10BIT        I2C_CTRL2_SADDRLEN       /*!< Master operates in 10-bit addressing mode.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_OWNADDRESS1 Own Address 1 Length
  * @{
  */
#define DDL_I2C_OWNADDRESS1_7BIT             0x00000000U             /*!< Own address 1 is a 7-bit address. */
#define DDL_I2C_OWNADDRESS1_10BIT            I2C_ADDR1_ADDR1LEN      /*!< Own address 1 is a 10-bit address.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_OWNADDRESS2 Own Address 2 Masks
  * @{
  */
#define DDL_I2C_OWNADDRESS2_NOMASK           0x00000000U              /*!< Own Address2 No mask.                 */
#define DDL_I2C_OWNADDRESS2_MASK01           I2C_ADDR2_ADDR2MSK01     /*!< Only Address2 bits[7:2] are compared. */
#define DDL_I2C_OWNADDRESS2_MASK02           I2C_ADDR2_ADDR2MSK02     /*!< Only Address2 bits[7:3] are compared. */
#define DDL_I2C_OWNADDRESS2_MASK03           I2C_ADDR2_ADDR2MSK03     /*!< Only Address2 bits[7:4] are compared. */
#define DDL_I2C_OWNADDRESS2_MASK04           I2C_ADDR2_ADDR2MSK04     /*!< Only Address2 bits[7:5] are compared. */
#define DDL_I2C_OWNADDRESS2_MASK05           I2C_ADDR2_ADDR2MSK05     /*!< Only Address2 bits[7:6] are compared. */
#define DDL_I2C_OWNADDRESS2_MASK06           I2C_ADDR2_ADDR2MSK06     /*!< Only Address2 bits[7] are compared.   */
#define DDL_I2C_OWNADDRESS2_MASK07           I2C_ADDR2_ADDR2MSK07     /*!< No comparison is done.
                                                                         All Address2 are acknowledged.        */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_I2C_ACKNOWLEDGE Acknowledge Generation
  * @{
  */
#define DDL_I2C_ACK                          0x00000000U              /*!< ACK is sent after current received byte. */
#define DDL_I2C_NACK                         I2C_CTRL2_NACKEN         /*!< NACK is sent after current received byte.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_ADDRSLAVE Slave Address Length
  * @{
  */
#define DDL_I2C_ADDRSLAVE_7BIT               0x00000000U              /*!< Slave Address in 7-bit. */
#define DDL_I2C_ADDRSLAVE_10BIT              I2C_CTRL2_SADDRLEN            /*!< Slave Address in 10-bit.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_REQUEST Transfer Request Direction
  * @{
  */
#define DDL_I2C_REQUEST_WRITE                0x00000000U              /*!< Master request a write transfer. */
#define DDL_I2C_REQUEST_READ                 I2C_CTRL2_TXDIR          /*!< Master request a read transfer.  */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_MODE Transfer End Mode
  * @{
  */
#define DDL_I2C_MODE_RELOAD                  I2C_CTRL2_RELOADEN         /*!< Enable I2C Reload mode.     */
#define DDL_I2C_MODE_AUTOEND                 I2C_CTRL2_ENDCFG           /*!< Enable I2C Automatic end mode
                                                                          with no HW PEC comparison.  */
#define DDL_I2C_MODE_SOFTEND                 0x00000000U              /*!< Enable I2C Software end mode
                                                                          with no HW PEC comparison.  */
#define DDL_I2C_MODE_SMBUS_RELOAD            DDL_I2C_MODE_RELOAD       /*!< Enable SMBUS Automatic end mode
                                                                          with HW PEC comparison.     */
#define DDL_I2C_MODE_SMBUS_AUTOEND_NO_PEC    DDL_I2C_MODE_AUTOEND      /*!< Enable SMBUS Automatic end mode
                                                                          with HW PEC comparison.     */
#define DDL_I2C_MODE_SMBUS_SOFTEND_NO_PEC    DDL_I2C_MODE_SOFTEND      /*!< Enable SMBUS Software end mode
                                                                          with HW PEC comparison.     */
#define DDL_I2C_MODE_SMBUS_AUTOEND_WITH_PEC  (uint32_t)(DDL_I2C_MODE_AUTOEND | I2C_CTRL2_PEC)
/*!< Enable SMBUS Automatic end mode with HW PEC comparison.   */
#define DDL_I2C_MODE_SMBUS_SOFTEND_WITH_PEC  (uint32_t)(DDL_I2C_MODE_SOFTEND | I2C_CTRL2_PEC)
/*!< Enable SMBUS Software end mode with HW PEC comparison.    */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_GENERATE Start And Stop Generation
  * @{
  */
#define DDL_I2C_GENERATE_NOSTARTSTOP         0x00000000U
/*!< Don't Generate Stop and Start condition. */
#define DDL_I2C_GENERATE_STOP                (uint32_t)(0x80000000U | I2C_CTRL2_STOP)
/*!< Generate Stop condition (Size should be set to 0).      */
#define DDL_I2C_GENERATE_START_READ          (uint32_t)(0x80000000U | I2C_CTRL2_START | I2C_CTRL2_TXDIR)
/*!< Generate Start for read request. */
#define DDL_I2C_GENERATE_START_WRITE         (uint32_t)(0x80000000U | I2C_CTRL2_START)
/*!< Generate Start for write request. */
#define DDL_I2C_GENERATE_RESTART_7BIT_READ   (uint32_t)(0x80000000U | I2C_CTRL2_START | I2C_CTRL2_TXDIR)
/*!< Generate Restart for read request, slave 7Bit address.  */
#define DDL_I2C_GENERATE_RESTART_7BIT_WRITE  (uint32_t)(0x80000000U | I2C_CTRL2_START)
/*!< Generate Restart for write request, slave 7Bit address. */
#define DDL_I2C_GENERATE_RESTART_10BIT_READ  (uint32_t)(0x80000000U | I2C_CTRL2_START | \
                                                       I2C_CTRL2_TXDIR | I2C_CTRL2_ADDR10)
/*!< Generate Restart for read request, slave 10Bit address. */
#define DDL_I2C_GENERATE_RESTART_10BIT_WRITE (uint32_t)(0x80000000U | I2C_CTRL2_START)
/*!< Generate Restart for write request, slave 10Bit address.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_DIRECTION Read Write Direction
  * @{
  */
#define DDL_I2C_DIRECTION_WRITE              0x00000000U              /*!< Write transfer request by master,
                                                                          slave enters receiver mode.  */
#define DDL_I2C_DIRECTION_READ               I2C_STS_TXDIRFLG         /*!< Read transfer request by master,
                                                                          slave enters transmitter mode.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_DMA_REG_DATA DMA Register Data
  * @{
  */
#define DDL_I2C_DMA_REG_DATA_TRANSMIT        0x00000000U              /*!< Get address of data register used for
                                                                          transmission */
#define DDL_I2C_DMA_REG_DATA_RECEIVE         0x00000001U              /*!< Get address of data register used for
                                                                          reception */
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_SMBUS_TIMEOUTA_MODE SMBus TimeoutA Mode SCL SDA Timeout
  * @{
  */
#define DDL_I2C_SMBUS_TIMEOUTA_MODE_SCL_LOW      0x00000000U          /*!< TimeoutA is used to detect
                                                                          SCL low level timeout.              */
#define DDL_I2C_SMBUS_TIMEOUTA_MODE_SDA_SCL_HIGH I2C_TIMEOUT_IDLECLKTO   /*!< TimeoutA is used to detect
                                                                          both SCL and SDA high level timeout.*/
/**
  * @}
  */

/** @defgroup I2C_DDL_EC_SMBUS_TIMEOUT_SELECTION SMBus Timeout Selection
  * @{
  */
#define DDL_I2C_SMBUS_TIMEOUTA               I2C_TIMEOUT_CLKTOEN                 /*!< TimeoutA enable bit          */
#define DDL_I2C_SMBUS_TIMEOUTB               I2C_TIMEOUT_EXCLKTOEN                   /*!< TimeoutB (extended clock)
                                                                                       enable bit                   */
#define DDL_I2C_SMBUS_ALL_TIMEOUT            (uint32_t)(I2C_TIMEOUT_CLKTOEN | \
                                                       I2C_TIMEOUT_EXCLKTOEN)       /*!< TimeoutA and TimeoutB
(extended clock) enable bits */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup I2C_DDL_Exported_Macros I2C Exported Macros
  * @{
  */

/** @defgroup I2C_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in I2C register
  * @param  __INSTANCE__ I2C Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_I2C_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in I2C register
  * @param  __INSTANCE__ I2C Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_I2C_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup I2C_DDL_EM_CONVERT_TIMINGS Convert SDA SCL timings
  * @{
  */
/**
  * @brief  Configure the SDA setup, hold time and the SCL high, low period.
  * @param  __PRESCALER__ This parameter must be a value between  Min_Data=0 and Max_Data=0xF.
  * @param  __SETUP_TIME__ This parameter must be a value between Min_Data=0 and Max_Data=0xF.
                           (tscldel = (SCLDEL+1)xtpresc)
  * @param  __HOLD_TIME__  This parameter must be a value between Min_Data=0 and Max_Data=0xF.
                           (tsdadel = SDADELxtpresc)
  * @param  __SCLH_PERIOD__ This parameter must be a value between Min_Data=0 and Max_Data=0xFF.
                            (tsclh = (SCLH+1)xtpresc)
  * @param  __SCLL_PERIOD__ This parameter must be a value between  Min_Data=0 and Max_Data=0xFF.
                            (tscll = (SCLL+1)xtpresc)
  * @retval Value between Min_Data=0 and Max_Data=0xFFFFFFFF
  */
#define __DDL_I2C_CONVERT_TIMINGS(__PRESCALER__, __SETUP_TIME__, __HOLD_TIME__, __SCLH_PERIOD__, __SCLL_PERIOD__) \
  ((((uint32_t)(__PRESCALER__)    << I2C_TIMING_TIMINGPSC_Pos)  & I2C_TIMING_TIMINGPSC)   | \
   (((uint32_t)(__SETUP_TIME__)   << I2C_TIMING_DATAT_Pos) & I2C_TIMING_DATAT)  | \
   (((uint32_t)(__HOLD_TIME__)    << I2C_TIMING_DATAHT_Pos) & I2C_TIMING_DATAHT)  | \
   (((uint32_t)(__SCLH_PERIOD__)  << I2C_TIMING_SCLH_Pos)   & I2C_TIMING_SCLH)    | \
   (((uint32_t)(__SCLL_PERIOD__)  << I2C_TIMING_SCLL_Pos)   & I2C_TIMING_SCLL))
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup I2C_DDL_Exported_Functions I2C Exported Functions
  * @{
  */

/** @defgroup I2C_DDL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Enable I2C peripheral
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_Enable(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_I2CEN);
}

/**
  * @brief  Disable I2C peripheral
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_Disable(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_I2CEN);
}

/**
  * @brief  Check if the I2C peripheral is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabled(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_I2CEN) == (I2C_CTRL1_I2CEN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure Noise Filters (Analog and Digital).
  * @note   If the analog filter is also enabled, the digital filter is added to analog filter.
  *         The filters can only be programmed when the I2C is disabled.
  * @param  I2Cx I2C Instance.
  * @param  DigitalFilter This parameter must be a value between Min_Data=0x00 (Digital filter disabled)
                          and Max_Data=0x0F (Digital filter enabled and filtering capability up to 15*ti2cclk).
  *         This parameter is used to configure the digital noise filter on SDA and SCL input.
  *         The digital filter will filter spikes with a length of up to DNF[3:0]*ti2cclk.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ConfigFilters(I2C_TypeDef *I2Cx, uint32_t DigitalFilter)
{
  MODIFY_REG(I2Cx->CTRL1, I2C_CTRL1_DNFCFG, DigitalFilter << I2C_CTRL1_DNFCFG_Pos);
}

/**
  * @brief  Configure Digital Noise Filter.
  * @note   If the analog filter is also enabled, the digital filter is added to analog filter.
  *         This filter can only be programmed when the I2C is disabled.
  * @param  I2Cx I2C Instance.
  * @param  DigitalFilter This parameter must be a value between Min_Data=0x00 (Digital filter disabled)
                          and Max_Data=0x0F (Digital filter enabled and filtering capability up to 15*ti2cclk).
  *         This parameter is used to configure the digital noise filter on SDA and SCL input.
  *         The digital filter will filter spikes with a length of up to DNF[3:0]*ti2cclk.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetDigitalFilter(I2C_TypeDef *I2Cx, uint32_t DigitalFilter)
{
  MODIFY_REG(I2Cx->CTRL1, I2C_CTRL1_DNFCFG, DigitalFilter << I2C_CTRL1_DNFCFG_Pos);
}

/**
  * @brief  Get the current Digital Noise Filter configuration.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetDigitalFilter(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CTRL1, I2C_CTRL1_DNFCFG) >> I2C_CTRL1_DNFCFG_Pos);
}

/**
  * @brief  Enable Software Reset.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableSoftwareReset(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_SWRST);
}

/**
  * @brief  Enable DMA transmission requests.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableDMAReq_TX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_DMATXEN);
}

/**
  * @brief  Disable DMA transmission requests.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableDMAReq_TX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_DMATXEN);
}

/**
  * @brief  Check if DMA transmission requests are enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledDMAReq_TX(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_DMATXEN) == (I2C_CTRL1_DMATXEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA reception requests.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableDMAReq_RX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_DMARXEN);
}

/**
  * @brief  Disable DMA reception requests.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableDMAReq_RX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_DMARXEN);
}

/**
  * @brief  Check if DMA reception requests are enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledDMAReq_RX(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_DMARXEN) == (I2C_CTRL1_DMARXEN)) ? 1UL : 0UL);
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @param  I2Cx I2C Instance
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_DMA_REG_DATA_TRANSMIT
  *         @arg @ref DDL_I2C_DMA_REG_DATA_RECEIVE
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t DDL_I2C_DMA_GetRegAddr(const I2C_TypeDef *I2Cx, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == DDL_I2C_DMA_REG_DATA_TRANSMIT)
  {
    /* return address of TXDATA register */
    data_reg_addr = (uint32_t) &(I2Cx->TXDATA);
  }
  else
  {
    /* return address of RXDATA register */
    data_reg_addr = (uint32_t) &(I2Cx->RXDATA);
  }

  return data_reg_addr;
}

/**
  * @brief  Enable Clock stretching.
  * @note   This bit can only be programmed when the I2C is disabled.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableClockStretching(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_CLKSTRETCHD);
}

/**
  * @brief  Disable Clock stretching.
  * @note   This bit can only be programmed when the I2C is disabled.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableClockStretching(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_CLKSTRETCHD);
}

/**
  * @brief  Check if Clock stretching is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledClockStretching(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_CLKSTRETCHD) != (I2C_CTRL1_CLKSTRETCHD)) ? 1UL : 0UL);
}

/**
  * @brief  Enable hardware byte control in slave mode.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableSlaveByteControl(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_SBCEN);
}

/**
  * @brief  Disable hardware byte control in slave mode.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableSlaveByteControl(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_SBCEN);
}

/**
  * @brief  Check if hardware byte control in slave mode is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledSlaveByteControl(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_SBCEN) == (I2C_CTRL1_SBCEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable General Call.
  * @note   When enabled the Address 0x00 is ACKed.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableGeneralCall(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_RBEN);
}

/**
  * @brief  Disable General Call.
  * @note   When disabled the Address 0x00 is NACKed.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableGeneralCall(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_RBEN);
}

/**
  * @brief  Check if General Call is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledGeneralCall(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_RBEN) == (I2C_CTRL1_RBEN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the Master to operate in 7-bit or 10-bit addressing mode.
  * @note   Changing this bit is not allowed, when the START bit is set.
  * @param  I2Cx I2C Instance.
  * @param  AddressingMode This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_ADDRESSING_MODE_7BIT
  *         @arg @ref DDL_I2C_ADDRESSING_MODE_10BIT
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetMasterAddressingMode(I2C_TypeDef *I2Cx, uint32_t AddressingMode)
{
  MODIFY_REG(I2Cx->CTRL2, I2C_CTRL2_SADDRLEN, AddressingMode);
}

/**
  * @brief  Get the Master addressing mode.
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_I2C_ADDRESSING_MODE_7BIT
  *         @arg @ref DDL_I2C_ADDRESSING_MODE_10BIT
  */
__STATIC_INLINE uint32_t DDL_I2C_GetMasterAddressingMode(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CTRL2, I2C_CTRL2_SADDRLEN));
}

/**
  * @brief  Set the Own Address1.
  * @param  I2Cx I2C Instance.
  * @param  OwnAddress1 This parameter must be a value between Min_Data=0 and Max_Data=0x3FF.
  * @param  OwnAddrSize This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_OWNADDRESS1_7BIT
  *         @arg @ref DDL_I2C_OWNADDRESS1_10BIT
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetOwnAddress1(I2C_TypeDef *I2Cx, uint32_t OwnAddress1, uint32_t OwnAddrSize)
{
  MODIFY_REG(I2Cx->ADDR1, I2C_ADDR1_ADDR1 | I2C_ADDR1_ADDR1LEN, (OwnAddress1 << I2C_ADDR1_ADDR1_Pos) | OwnAddrSize);
}

/**
  * @brief  Enable acknowledge on Own Address1 match address.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableOwnAddress1(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ADDR1, I2C_ADDR1_ADDR1EN);
}

/**
  * @brief  Disable acknowledge on Own Address1 match address.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableOwnAddress1(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->ADDR1, I2C_ADDR1_ADDR1EN);
}

/**
  * @brief  Check if Own Address1 acknowledge is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledOwnAddress1(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ADDR1, I2C_ADDR1_ADDR1EN) == (I2C_ADDR1_ADDR1EN)) ? 1UL : 0UL);
}

/**
  * @brief  Set the 7bits Own Address2.
  * @note   This action has no effect if own address2 is enabled.
  * @param  I2Cx I2C Instance.
  * @param  OwnAddress2 Value between Min_Data=0 and Max_Data=0x7F.
  * @param  OwnAddrMask This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_OWNADDRESS2_NOMASK
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK01
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK02
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK03
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK04
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK05
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK06
  *         @arg @ref DDL_I2C_OWNADDRESS2_MASK07
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetOwnAddress2(I2C_TypeDef *I2Cx, uint32_t OwnAddress2, uint32_t OwnAddrMask)
{
  MODIFY_REG(I2Cx->ADDR2, I2C_ADDR2_ADDR2 | I2C_ADDR2_ADDR2MSK, (OwnAddress2 << I2C_ADDR2_ADDR2_Pos) | OwnAddrMask);
}

/**
  * @brief  Enable acknowledge on Own Address2 match address.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableOwnAddress2(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ADDR2, I2C_ADDR2_ADDR2EN);
}

/**
  * @brief  Disable  acknowledge on Own Address2 match address.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableOwnAddress2(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->ADDR2, I2C_ADDR2_ADDR2EN);
}

/**
  * @brief  Check if Own Address1 acknowledge is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledOwnAddress2(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ADDR2, I2C_ADDR2_ADDR2EN) == (I2C_ADDR2_ADDR2EN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the SDA setup, hold time and the SCL high, low period.
  * @note   This bit can only be programmed when the I2C is disabled.
  * @param  I2Cx I2C Instance.
  * @param  Timing This parameter must be a value between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetTiming(I2C_TypeDef *I2Cx, uint32_t Timing)
{
  WRITE_REG(I2Cx->TIMING, Timing);
}

/**
  * @brief  Configure the Timing Prescaler setting.
  * @param  I2Cx I2C Instance.
  * @param  Prescaler This value between Min_Data=0x0 and Max_Data=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetTimingPrescaler(I2C_TypeDef *I2Cx, uint32_t Prescaler)
{
  MODIFY_REG(I2Cx->TIMING, I2C_TIMING_TIMINGPSC, Prescaler << I2C_TIMING_TIMINGPSC_Pos);
}

/**
  * @brief  Get the Timing Prescaler setting.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetTimingPrescaler(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMING, I2C_TIMING_TIMINGPSC) >> I2C_TIMING_TIMINGPSC_Pos);
}

/**
  * @brief  Configure the SCL low period setting.
  * @param  I2Cx I2C Instance.
  * @param  Period This value between Min_Data=0x00 and Max_Data=0xFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetClockLowPeriod(I2C_TypeDef *I2Cx, uint32_t Period)
{
  MODIFY_REG(I2Cx->TIMING, I2C_TIMING_SCLL, Period << I2C_TIMING_SCLL_Pos);
}

/**
  * @brief  Get the SCL low period setting.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetClockLowPeriod(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMING, I2C_TIMING_SCLL) >> I2C_TIMING_SCLL_Pos);
}

/**
  * @brief  Configure the SCL high period setting.
  * @param  I2Cx I2C Instance.
  * @param  Period This value between Min_Data=0x00 and Max_Data=0xFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetClockHighPeriod(I2C_TypeDef *I2Cx, uint32_t Period)
{
  MODIFY_REG(I2Cx->TIMING, I2C_TIMING_SCLH, Period << I2C_TIMING_SCLH_Pos);
}

/**
  * @brief  Get the SCL high period setting.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetClockHighPeriod(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMING, I2C_TIMING_SCLH) >> I2C_TIMING_SCLH_Pos);
}

/**
  * @brief  Configure the SCL high period setting.
  * @param  I2Cx I2C Instance.
  * @param  Period This value between Min_Data=0x00 and Max_Data=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetDataHoldTime(I2C_TypeDef *I2Cx, uint32_t Period)
{
  MODIFY_REG(I2Cx->TIMING, I2C_TIMING_DATAHT, Period << I2C_TIMING_DATAHT_Pos);
}

/**
  * @brief  Get the SDA hold time.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xF.
  */
__STATIC_INLINE uint32_t DDL_I2C_GetDataHoldTime(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMING, I2C_TIMING_DATAHT) >> I2C_TIMING_DATAHT_Pos);
}

/**
  * @brief  Configure the SDA setup time.
  * @param  I2Cx I2C Instance.
  * @param  Period This value between Min_Data=0x00 and Max_Data=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetDataSetupTime(I2C_TypeDef *I2Cx, uint32_t Period)
{
  MODIFY_REG(I2Cx->TIMING, I2C_TIMING_DATAT, Period << I2C_TIMING_DATAT_Pos);
}

/**
  * @brief  Get the SDA setup time.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetDataSetupTime(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMING, I2C_TIMING_DATAT) >> I2C_TIMING_DATAT_Pos);
}

/**
  * @brief  Configure peripheral mode.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @param  PeripheralMode This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_MODE_I2C
  *         @arg @ref DDL_I2C_MODE_SMBUS_HOST
  *         @arg @ref DDL_I2C_MODE_SMBUS_DEVICE
  *         @arg @ref DDL_I2C_MODE_SMBUS_DEVICE_ARP
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetMode(I2C_TypeDef *I2Cx, uint32_t PeripheralMode)
{
  MODIFY_REG(I2Cx->CTRL1, I2C_CTRL1_HADDREN | I2C_CTRL1_DEADDREN, PeripheralMode);
}

/**
  * @brief  Get peripheral mode.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_I2C_MODE_I2C
  *         @arg @ref DDL_I2C_MODE_SMBUS_HOST
  *         @arg @ref DDL_I2C_MODE_SMBUS_DEVICE
  *         @arg @ref DDL_I2C_MODE_SMBUS_DEVICE_ARP
  */
__STATIC_INLINE uint32_t DDL_I2C_GetMode(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CTRL1, I2C_CTRL1_HADDREN | I2C_CTRL1_DEADDREN));
}

/**
  * @brief  Enable SMBus alert (Host or Device mode)
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   SMBus Device mode:
  *         - SMBus Alert pin is drived low and
  *           Alert Response Address Header acknowledge is enabled.
  *         SMBus Host mode:
  *         - SMBus Alert pin management is supported.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableSMBusAlert(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_ALTEN);
}

/**
  * @brief  Disable SMBus alert (Host or Device mode)
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   SMBus Device mode:
  *         - SMBus Alert pin is not drived (can be used as a standard GPIO) and
  *           Alert Response Address Header acknowledge is disabled.
  *         SMBus Host mode:
  *         - SMBus Alert pin management is not supported.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableSMBusAlert(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_ALTEN);
}

/**
  * @brief  Check if SMBus alert (Host or Device mode) is enabled or disabled.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledSMBusAlert(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_ALTEN) == (I2C_CTRL1_ALTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable SMBus Packet Error Calculation.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableSMBusPEC(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_PECEN);
}

/**
  * @brief  Disable SMBus Packet Error Calculation.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableSMBusPEC(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_PECEN);
}

/**
  * @brief  Check if SMBus Packet Error Calculation (PEC) is enabled or disabled.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledSMBusPEC(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_PECEN) == (I2C_CTRL1_PECEN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the SMBus Clock Timeout.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   This configuration can only be programmed when associated Timeout is disabled (TimeoutA and/orTimeoutB).
  * @param  I2Cx I2C Instance.
  * @param  TimeoutA This parameter must be a value between  Min_Data=0 and Max_Data=0xFFF.
  * @param  TimeoutAMode This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA_MODE_SCL_LOW
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA_MODE_SDA_SCL_HIGH
  * @param  TimeoutB This parameter must be a value between  Min_Data=0 and Max_Data=0xFFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ConfigSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t TimeoutA, uint32_t TimeoutAMode,
                                               uint32_t TimeoutB)
{
  MODIFY_REG(I2Cx->TIMEOUT, I2C_TIMEOUT_TIMEOUTA | I2C_TIMEOUT_IDLECLKTO | I2C_TIMEOUT_TIMEOUTB,
             (TimeoutA << I2C_TIMEOUT_TIMEOUTA_Pos) | TimeoutAMode | (TimeoutB << I2C_TIMEOUT_TIMEOUTB_Pos));
}

/**
  * @brief  Configure the SMBus Clock TimeoutA (SCL low timeout or SCL and SDA high timeout depends on TimeoutA mode).
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   These bits can only be programmed when TimeoutA is disabled.
  * @param  I2Cx I2C Instance.
  * @param  TimeoutA This parameter must be a value between  Min_Data=0 and Max_Data=0xFFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetSMBusTimeoutA(I2C_TypeDef *I2Cx, uint32_t TimeoutA)
{
  WRITE_REG(I2Cx->TIMEOUT, TimeoutA);
}

/**
  * @brief  Get the SMBus Clock TimeoutA setting.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0 and Max_Data=0xFFF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetSMBusTimeoutA(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMEOUT, I2C_TIMEOUT_TIMEOUTA));
}

/**
  * @brief  Set the SMBus Clock TimeoutA mode.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   This bit can only be programmed when TimeoutA is disabled.
  * @param  I2Cx I2C Instance.
  * @param  TimeoutAMode This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA_MODE_SCL_LOW
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA_MODE_SDA_SCL_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetSMBusTimeoutAMode(I2C_TypeDef *I2Cx, uint32_t TimeoutAMode)
{
  WRITE_REG(I2Cx->TIMEOUT, TimeoutAMode);
}

/**
  * @brief  Get the SMBus Clock TimeoutA mode.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA_MODE_SCL_LOW
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA_MODE_SDA_SCL_HIGH
  */
__STATIC_INLINE uint32_t DDL_I2C_GetSMBusTimeoutAMode(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMEOUT, I2C_TIMEOUT_IDLECLKTO));
}

/**
  * @brief  Configure the SMBus Extended Cumulative Clock TimeoutB (Master or Slave mode).
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   These bits can only be programmed when TimeoutB is disabled.
  * @param  I2Cx I2C Instance.
  * @param  TimeoutB This parameter must be a value between  Min_Data=0 and Max_Data=0xFFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetSMBusTimeoutB(I2C_TypeDef *I2Cx, uint32_t TimeoutB)
{
  WRITE_REG(I2Cx->TIMEOUT, TimeoutB << I2C_TIMEOUT_TIMEOUTB_Pos);
}

/**
  * @brief  Get the SMBus Extended Cumulative Clock TimeoutB setting.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0 and Max_Data=0xFFF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetSMBusTimeoutB(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMEOUT, I2C_TIMEOUT_TIMEOUTB) >> I2C_TIMEOUT_TIMEOUTB_Pos);
}

/**
  * @brief  Enable the SMBus Clock Timeout.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @param  ClockTimeout This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTB
  *         @arg @ref DDL_I2C_SMBUS_ALL_TIMEOUT
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t ClockTimeout)
{
  SET_BIT(I2Cx->TIMEOUT, ClockTimeout);
}

/**
  * @brief  Disable the SMBus Clock Timeout.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @param  ClockTimeout This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTB
  *         @arg @ref DDL_I2C_SMBUS_ALL_TIMEOUT
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableSMBusTimeout(I2C_TypeDef *I2Cx, uint32_t ClockTimeout)
{
  CLEAR_BIT(I2Cx->TIMEOUT, ClockTimeout);
}

/**
  * @brief  Check if the SMBus Clock Timeout is enabled or disabled.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @param  ClockTimeout This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTA
  *         @arg @ref DDL_I2C_SMBUS_TIMEOUTB
  *         @arg @ref DDL_I2C_SMBUS_ALL_TIMEOUT
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledSMBusTimeout(const I2C_TypeDef *I2Cx, uint32_t ClockTimeout)
{
  return ((READ_BIT(I2Cx->TIMEOUT, (I2C_TIMEOUT_CLKTOEN | I2C_TIMEOUT_EXCLKTOEN)) == \
           (ClockTimeout)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C_DDL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable TXINT interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_TX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_TXIEN);
}

/**
  * @brief  Disable TXINT interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_TX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_TXIEN);
}

/**
  * @brief  Check if the TXINT Interrupt is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_TX(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_TXIEN) == (I2C_CTRL1_TXIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable RXBNE interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_RX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_RXIEN);
}

/**
  * @brief  Disable RXBNE interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_RX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_RXIEN);
}

/**
  * @brief  Check if the RXBNE Interrupt is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_RX(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_RXIEN) == (I2C_CTRL1_RXIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Address match interrupt (slave mode only).
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_ADDR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_SADDRMIEN);
}

/**
  * @brief  Disable Address match interrupt (slave mode only).
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_ADDR(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_SADDRMIEN);
}

/**
  * @brief  Check if Address match interrupt is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_ADDR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_SADDRMIEN) == (I2C_CTRL1_SADDRMIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Not acknowledge received interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_NACK(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_NACKRXIEN);
}

/**
  * @brief  Disable Not acknowledge received interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_NACK(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_NACKRXIEN);
}

/**
  * @brief  Check if Not acknowledge received interrupt is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_NACK(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_NACKRXIEN) == (I2C_CTRL1_NACKRXIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable STOP detection interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_STOP(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_STOPIEN);
}

/**
  * @brief  Disable STOP detection interrupt.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_STOP(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_STOPIEN);
}

/**
  * @brief  Check if STOP detection interrupt is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_STOP(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_STOPIEN) == (I2C_CTRL1_STOPIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Transfer Complete interrupt.
  * @note   Any of these events will generate interrupt :
  *         Transfer Complete (TC)
  *         Transfer Complete Reload (TCR)
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_TC(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_TXCIEN);
}

/**
  * @brief  Disable Transfer Complete interrupt.
  * @note   Any of these events will generate interrupt :
  *         Transfer Complete (TC)
  *         Transfer Complete Reload (TCR)
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_TC(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_TXCIEN);
}

/**
  * @brief  Check if Transfer Complete interrupt is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_TC(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_TXCIEN) == (I2C_CTRL1_TXCIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Error interrupts.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   Any of these errors will generate interrupt :
  *         Arbitration Loss (ARLO)
  *         Bus Error detection (BERR)
  *         Overrun/Underrun (OVR)
  *         SMBus Timeout detection (TIMEOUT)
  *         SMBus PEC error detection (PECERR)
  *         SMBus Alert pin event detection (ALERT)
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableIT_ERR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL1, I2C_CTRL1_ERRIEN);
}

/**
  * @brief  Disable Error interrupts.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   Any of these errors will generate interrupt :
  *         Arbitration Loss (ARLO)
  *         Bus Error detection (BERR)
  *         Overrun/Underrun (OVR)
  *         SMBus Timeout detection (TIMEOUT)
  *         SMBus PEC error detection (PECERR)
  *         SMBus Alert pin event detection (ALERT)
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableIT_ERR(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL1, I2C_CTRL1_ERRIEN);
}

/**
  * @brief  Check if Error interrupts are enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledIT_ERR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL1, I2C_CTRL1_ERRIEN) == (I2C_CTRL1_ERRIEN)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C_DDL_EF_FLAG_management FLAG_management
  * @{
  */

/**
  * @brief  Indicate the status of Transmit data register empty flag.
  * @note   RESET: When next data is written in Transmit data register.
  *         SET: When Transmit data register is empty.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_TXE(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_TXBEFLG) == (I2C_STS_TXBEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Transmit interrupt flag.
  * @note   RESET: When next data is written in Transmit data register.
  *         SET: When Transmit data register is empty.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_TXIS(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_TXINTFLG) == (I2C_STS_TXINTFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Receive data register not empty flag.
  * @note   RESET: When Receive data register is read.
  *         SET: When the received data is copied in Receive data register.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_RXNE(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_RXBNEFLG) == (I2C_STS_RXBNEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Address matched flag (slave mode).
  * @note   RESET: Clear default value.
  *         SET: When the received slave address matched with one of the enabled slave address.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_ADDR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_ADDRMFLG) == (I2C_STS_ADDRMFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Not Acknowledge received flag.
  * @note   RESET: Clear default value.
  *         SET: When a NACK is received after a byte transmission.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_NACK(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_NACKFLG) == (I2C_STS_NACKFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Stop detection flag.
  * @note   RESET: Clear default value.
  *         SET: When a Stop condition is detected.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_STOP(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_STOPFLG) == (I2C_STS_STOPFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Transfer complete flag (master mode).
  * @note   RESET: Clear default value.
  *         SET: When RELOAD=0, AUTOEND=0 and NBYTES data have been transferred.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_TC(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_TXCFLG) == (I2C_STS_TXCFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Transfer complete flag (master mode).
  * @note   RESET: Clear default value.
  *         SET: When RELOAD=1 and NBYTES data have been transferred.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_TCR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_TXCRFLG) == (I2C_STS_TXCRFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Bus error flag.
  * @note   RESET: Clear default value.
  *         SET: When a misplaced Start or Stop condition is detected.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_BERR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_BERRFLG) == (I2C_STS_BERRFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Arbitration lost flag.
  * @note   RESET: Clear default value.
  *         SET: When arbitration lost.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_ARLO(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_ALFLG) == (I2C_STS_ALFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Overrun/Underrun flag (slave mode).
  * @note   RESET: Clear default value.
  *         SET: When an overrun/underrun error occurs (Clock Stretching Disabled).
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_OVR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_OVRURFLG) == (I2C_STS_OVRURFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of SMBus PEC error flag in reception.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   RESET: Clear default value.
  *         SET: When the received PEC does not match with the PEC register content.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveSMBusFlag_PECERR(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_PECEFLG) == (I2C_STS_PECEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of SMBus Timeout detection flag.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   RESET: Clear default value.
  *         SET: When a timeout or extended clock timeout occurs.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveSMBusFlag_TIMEOUT(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_TTEFLG) == (I2C_STS_TTEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of SMBus alert flag.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   RESET: Clear default value.
  *         SET: When SMBus host configuration, SMBus alert enabled and
  *              a falling edge event occurs on SMBA pin.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveSMBusFlag_ALERT(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_SMBALTFLG) == (I2C_STS_SMBALTFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Bus Busy flag.
  * @note   RESET: Clear default value.
  *         SET: When a Start condition is detected.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsActiveFlag_BUSY(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STS, I2C_STS_BUSBSYFLG) == (I2C_STS_BUSBSYFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Address Matched flag.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearFlag_ADDR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_ADDRMCLR);
}

/**
  * @brief  Clear Not Acknowledge flag.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearFlag_NACK(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_NACKCLR);
}

/**
  * @brief  Clear Stop detection flag.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearFlag_STOP(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_STOPCLR);
}

/**
  * @brief  Clear Bus error flag.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearFlag_BERR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_BERRCLR);
}

/**
  * @brief  Clear Arbitration lost flag.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearFlag_ARLO(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_ALCLR);
}

/**
  * @brief  Clear Overrun/Underrun flag.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearFlag_OVR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_OVRURCLR);
}

/**
  * @brief  Clear SMBus PEC error flag.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearSMBusFlag_PECERR(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_PECECLR);
}

/**
  * @brief  Clear SMBus Timeout detection flag.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearSMBusFlag_TIMEOUT(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_TTECLR);
}

/**
  * @brief  Clear SMBus Alert flag.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearSMBusFlag_ALERT(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTFCLR, I2C_INTFCLR_SMBALTCLR);
}

/**
  * @}
  */

/** @defgroup I2C_DDL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Enable automatic STOP condition generation (master mode).
  * @note   Automatic end mode : a STOP condition is automatically sent when NBYTES data are transferred.
  *         This bit has no effect in slave mode or when RELOAD bit is set.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableAutoEndMode(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL2, I2C_CTRL2_ENDCFG);
}

/**
  * @brief  Disable automatic STOP condition generation (master mode).
  * @note   Software end mode : TC flag is set when NBYTES data are transferre, stretching SCL low.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableAutoEndMode(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL2, I2C_CTRL2_ENDCFG);
}

/**
  * @brief  Check if automatic STOP condition is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledAutoEndMode(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL2, I2C_CTRL2_ENDCFG) == (I2C_CTRL2_ENDCFG)) ? 1UL : 0UL);
}

/**
  * @brief  Enable reload mode (master mode).
  * @note   The transfer is not completed after the NBYTES data transfer, NBYTES will be reloaded when TCR flag is set.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableReloadMode(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL2, I2C_CTRL2_RELOADEN);
}

/**
  * @brief  Disable reload mode (master mode).
  * @note   The transfer is completed after the NBYTES data transfer(STOP or RESTART will follow).
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableReloadMode(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL2, I2C_CTRL2_RELOADEN);
}

/**
  * @brief  Check if reload mode is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledReloadMode(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL2, I2C_CTRL2_RELOADEN) == (I2C_CTRL2_RELOADEN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the number of bytes for transfer.
  * @note   Changing these bits when START bit is set is not allowed.
  * @param  I2Cx I2C Instance.
  * @param  TransferSize This parameter must be a value between Min_Data=0x00 and Max_Data=0xFF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetTransferSize(I2C_TypeDef *I2Cx, uint32_t TransferSize)
{
  MODIFY_REG(I2Cx->CTRL2, I2C_CTRL2_NUMBYT, TransferSize << I2C_CTRL2_NUMBYT_Pos);
}

/**
  * @brief  Get the number of bytes configured for transfer.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetTransferSize(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CTRL2, I2C_CTRL2_NUMBYT) >> I2C_CTRL2_NUMBYT_Pos);
}

/**
  * @brief  Prepare the generation of a ACKnowledge or Non ACKnowledge condition after the address receive match code
            or next received byte.
  * @note   Usage in Slave mode only.
  * @param  I2Cx I2C Instance.
  * @param  TypeAcknowledge This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_ACK
  *         @arg @ref DDL_I2C_NACK
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_AcknowledgeNextData(I2C_TypeDef *I2Cx, uint32_t TypeAcknowledge)
{
  MODIFY_REG(I2Cx->CTRL2, I2C_CTRL2_NACKEN, TypeAcknowledge);
}

/**
  * @brief  Generate a START or RESTART condition
  * @note   The START bit can be set even if bus is BUSY or I2C is in slave mode.
  *         This action has no effect when RELOAD is set.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_GenerateStartCondition(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL2, I2C_CTRL2_START);
}

/**
  * @brief  Generate a STOP condition after the current byte transfer (master mode).
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_GenerateStopCondition(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL2, I2C_CTRL2_STOP);
}

/**
  * @brief  Enable automatic RESTART Read request condition for 10bit address header (master mode).
  * @note   The master sends the complete 10bit slave address read sequence :
  *         Start + 2 bytes 10bit address in Write direction + Restart + first 7 bits of 10bit address
            in Read direction.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableAuto10BitRead(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CTRL2, I2C_CTRL2_ADDR10);
}

/**
  * @brief  Disable automatic RESTART Read request condition for 10bit address header (master mode).
  * @note   The master only sends the first 7 bits of 10bit address in Read direction.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_DisableAuto10BitRead(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL2, I2C_CTRL2_ADDR10);
}

/**
  * @brief  Check if automatic RESTART Read request condition for 10bit address header is enabled or disabled.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledAuto10BitRead(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL2, I2C_CTRL2_ADDR10) != (I2C_CTRL2_ADDR10)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the transfer direction (master mode).
  * @note   Changing these bits when START bit is set is not allowed.
  * @param  I2Cx I2C Instance.
  * @param  TransferRequest This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_REQUEST_WRITE
  *         @arg @ref DDL_I2C_REQUEST_READ
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetTransferRequest(I2C_TypeDef *I2Cx, uint32_t TransferRequest)
{
  MODIFY_REG(I2Cx->CTRL2, I2C_CTRL2_TXDIR, TransferRequest);
}

/**
  * @brief  Get the transfer direction requested (master mode).
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_I2C_REQUEST_WRITE
  *         @arg @ref DDL_I2C_REQUEST_READ
  */
__STATIC_INLINE uint32_t DDL_I2C_GetTransferRequest(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CTRL2, I2C_CTRL2_TXDIR));
}

/**
  * @brief  Configure the slave address for transfer (master mode).
  * @note   Changing these bits when START bit is set is not allowed.
  * @param  I2Cx I2C Instance.
  * @param  SlaveAddr This parameter must be a value between Min_Data=0x00 and Max_Data=0x3FF.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_SetSlaveAddr(I2C_TypeDef *I2Cx, uint32_t SlaveAddr)
{
  MODIFY_REG(I2Cx->CTRL2, I2C_CTRL2_SADDR, SlaveAddr);
}

/**
  * @brief  Get the slave address programmed for transfer.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0x3FF.
  */
__STATIC_INLINE uint32_t DDL_I2C_GetSlaveAddr(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CTRL2, I2C_CTRL2_SADDR));
}

/**
  * @brief  Handles I2Cx communication when starting transfer or during transfer (TC or TCR flag are set).
  * @param  I2Cx I2C Instance.
  * @param  SlaveAddr Specifies the slave address to be programmed.
  * @param  SlaveAddrSize This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_ADDRSLAVE_7BIT
  *         @arg @ref DDL_I2C_ADDRSLAVE_10BIT
  * @param  TransferSize Specifies the number of bytes to be programmed.
  *                       This parameter must be a value between Min_Data=0 and Max_Data=255.
  * @param  EndMode This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_MODE_RELOAD
  *         @arg @ref DDL_I2C_MODE_AUTOEND
  *         @arg @ref DDL_I2C_MODE_SOFTEND
  *         @arg @ref DDL_I2C_MODE_SMBUS_RELOAD
  *         @arg @ref DDL_I2C_MODE_SMBUS_AUTOEND_NO_PEC
  *         @arg @ref DDL_I2C_MODE_SMBUS_SOFTEND_NO_PEC
  *         @arg @ref DDL_I2C_MODE_SMBUS_AUTOEND_WITH_PEC
  *         @arg @ref DDL_I2C_MODE_SMBUS_SOFTEND_WITH_PEC
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref DDL_I2C_GENERATE_NOSTARTSTOP
  *         @arg @ref DDL_I2C_GENERATE_STOP
  *         @arg @ref DDL_I2C_GENERATE_START_READ
  *         @arg @ref DDL_I2C_GENERATE_START_WRITE
  *         @arg @ref DDL_I2C_GENERATE_RESTART_7BIT_READ
  *         @arg @ref DDL_I2C_GENERATE_RESTART_7BIT_WRITE
  *         @arg @ref DDL_I2C_GENERATE_RESTART_10BIT_READ
  *         @arg @ref DDL_I2C_GENERATE_RESTART_10BIT_WRITE
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_HandleTransfer(I2C_TypeDef *I2Cx, uint32_t SlaveAddr, uint32_t SlaveAddrSize,
                                           uint32_t TransferSize, uint32_t EndMode, uint32_t Request)
{
  /* Declaration of tmp to prevent undefined behavior of volatile usage */
  uint32_t tmp = ((uint32_t)(((uint32_t)SlaveAddr & I2C_CTRL2_SADDR) | \
                             ((uint32_t)SlaveAddrSize & I2C_CTRL2_SADDRLEN) | \
                             (((uint32_t)TransferSize << I2C_CTRL2_NUMBYT_Pos) & I2C_CTRL2_NUMBYT) | \
                             (uint32_t)EndMode | (uint32_t)Request) & (~0x80000000U));

  /* update CTRL2 register */
  MODIFY_REG(I2Cx->CTRL2, I2C_CTRL2_SADDR | I2C_CTRL2_SADDRLEN | I2C_CTRL2_ADDR10 |
             (I2C_CTRL2_TXDIR & (uint32_t)(Request >> (31U - I2C_CTRL2_TXDIR_Pos))) |
             I2C_CTRL2_START | I2C_CTRL2_STOP | I2C_CTRL2_NUMBYT |
             I2C_CTRL2_RELOADEN | I2C_CTRL2_ENDCFG | I2C_CTRL2_PEC,
             tmp);
}

/**
  * @brief  Indicate the value of transfer direction (slave mode).
  * @note   RESET: Write transfer, Slave enters in receiver mode.
  *         SET: Read transfer, Slave enters in transmitter mode.
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_I2C_DIRECTION_WRITE
  *         @arg @ref DDL_I2C_DIRECTION_READ
  */
__STATIC_INLINE uint32_t DDL_I2C_GetTransferDirection(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->STS, I2C_STS_TXDIRFLG));
}

/**
  * @brief  Return the slave matched address.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0x7F
  */
__STATIC_INLINE uint32_t DDL_I2C_GetAddressMatchCode(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->STS, I2C_STS_ADDRCMFLG) >> I2C_STS_ADDRCMFLG_Pos << 1);
}

/**
  * @brief  Enable internal comparison of the SMBus Packet Error byte (transmission or reception mode).
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @note   This feature is cleared by hardware when the PEC byte is transferred, or when a STOP condition
            or an Address Matched is received.
  *         This bit has no effect when RELOAD bit is set.
  *         This bit has no effect in device mode when SBC bit is not set.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_EnableSMBusPECCompare(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CTRL2, I2C_CTRL2_PEC);
}

/**
  * @brief  Check if the SMBus Packet Error byte internal comparison is requested or not.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C_IsEnabledSMBusPECCompare(const I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CTRL2, I2C_CTRL2_PEC) == (I2C_CTRL2_PEC)) ? 1UL : 0UL);
}

/**
  * @brief  Get the SMBus Packet Error byte calculated.
  * @note   The macro IS_SMBUS_ALL_INSTANCE(I2Cx) can be used to check whether or not
  *         SMBus feature is supported by the I2Cx Instance.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t DDL_I2C_GetSMBusPEC(const I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->PEC, I2C_PEC_PEC));
}

/**
  * @brief  Read Receive Data register.
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t DDL_I2C_ReceiveData8(const I2C_TypeDef *I2Cx)
{
  return (uint8_t)(READ_BIT(I2Cx->RXDATA, I2C_RXDATA_RXDATA));
}

/**
  * @brief  Write in Transmit Data Register.
  * @param  I2Cx I2C Instance.
  * @param  Data Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_TransmitData8(I2C_TypeDef *I2Cx, uint8_t Data)
{
  WRITE_REG(I2Cx->TXDATA, Data);
}

/**
  * @brief  Clear I2C transmit data register.
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C_ClearTxData(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->STS, I2C_STS_TXBEFLG);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup I2C_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_I2C_Init(I2C_TypeDef *I2Cx, DDL_I2C_InitTypeDef *I2C_InitStruct);
ErrorStatus DDL_I2C_DeInit(I2C_TypeDef *I2Cx);
void DDL_I2C_StructInit(DDL_I2C_InitTypeDef *I2C_InitStruct);


/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* I2C1 || I2C2 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_I2C_H */
