/**
  *
  * @file    g32f463_ddl_i2c3.h
  * @brief   Header file of I2C3 DDL module.
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
#ifndef G32F463_DDL_I2C3_H
#define G32F463_DDL_I2C3_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (I2C3)

/** @defgroup I2C3_DDL I2C3
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2C3_DDL_Private_Constants I2C3 Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup I2C3_DDL_Private_Macros I2C3 Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup I2C3_DDL_ES_INIT I2C3 Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t Mode;                /*!< Specifies the I2C3 work mode.
                                     This parameter can be a value of @ref I2C3_DDL_EC_MODE. */

  uint32_t Baudrate;            /*!< Specifies the I2C3 baudrate.
                                     This parameter can be a value between Min_Data = 0 and Max_Data = 1000000. */

  uint32_t SCLFilter;           /*!< Specifies the SCL filter.
                                     This parameter can be a value between Min_Data = 0x00 and Max_Data = 0x0F.

                                     This feature can be modified afterwards using unitary functions
                                     @ref DDL_I2C3_Master_SetSCLFilter(). */

  uint32_t SDAFilter;           /*!< Specifies the SDA filter.
                                     This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x0F.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Master_SetSDAFilter(). */

  uint32_t TimeoutConfig;       /*!< Specifies the timeout configuration.
                                     This parameter must be a value of @ref I2C3_DDL_EC_TIMEOUT_CONFIG.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Master_SetTimeoutConfig(). */

  uint32_t IdleTimeout;         /*!< Specifies the timeout value of the idle bus.
                                     This parameter can be a a number between Min_Data = 0x00 and Max_Data = 0xFFF.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Master_SetIdleTimeout(). */

  uint32_t PinLowTimeout;       /*!< Specifies the timeout value of the pin low.
                                     This parameter can be a a number between Min_Data = 0x00 and Max_Data = 0xFFF.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Master_SetPinLowTimeout(). */
} DDL_I2C3_MasterInitTypeDef;

typedef struct
{
  uint32_t Mode;                /*!< Specifies the I2C3 work mode.
                                     This parameter can be a value of @ref I2C3_DDL_EC_MODE. */

  uint32_t SCLFilter;           /*!< Specifies the SCL filter.
                                     This parameter can be a value between Min_Data = 0x00 and Max_Data = 0x0F.

                                     This feature can be modified afterwards using unitary functions
                                     @ref DDL_I2C3_Slave_SetSCLFilter(). */

  uint32_t SDAFilter;           /*!< Specifies the SDA filter.
                                     This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x0F.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Slave_SetSDAFilter(). */

  uint32_t OwnAddress0;          /*!< Specifies the device own address 0.
                                     This parameter must be a value between Min_Data = 0x000 and Max_Data = 0x3FF.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Slave_SetAddr0(). */

  uint32_t OwnAddress1;          /*!< Specifies the device own address 1.
                                     This parameter must be a value between Min_Data = 0x000 and Max_Data = 0x3FF.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Slave_SetAddr1(). */

  uint32_t AddressMatch;        /*!< Specifies the condition for match address 0 and address 1.
                                     This parameter must be a value of @I2C3_DDL_EC_ADDR_MATCH_CONFIG.

                                     This feature can be modified afterwards using unitary function
                                     @ref DDL_I2C3_Slave_SetAddrMatchConfig(). */

} DDL_I2C3_SlaveInitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup I2C3_DDL_Exported_Constants I2C3 Exported Constants
  * @{
  */

/** @defgroup I2C3_DDL_EC_MODE I2C3 Mode Defines
  * @{
  */
#define DDL_I2C3_MODE_STANDARD                  (100000U)           /*!< Standard mode                       */
#define DDL_I2C3_MODE_FAST                      (200000U)           /*!< Fast mode                           */
#define DDL_I2C3_MODE_HIGHSPEED                 (400000U)           /*!< High-speed mode                     */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_NACKMODE I2C3 NACK Mode Defines
  * @{
  */
#define DDL_I2C3_NACKMODE_RECEIVED              (0x00000000U)       /*!< Received ACK and NACK nomarly          */
#define DDL_I2C3_NACKMODE_IGNORE                I2C3_MCFGR1_IGNACK  /*!< Received NACK regarded as received ACK */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_GET_MASTER_FLAG Get Master Flags Defines
  * @brief    Flags defines which can be used with DDL_I2C3_ReadReg function.
  * @{
  */
#define DDL_I2C3_MASTER_TDF                     I2C3_MSR_TDF        /*!< Transmit data                       */
#define DDL_I2C3_MASTER_RDF                     I2C3_MSR_RDF        /*!< Receive data                        */
#define DDL_I2C3_MASTER_EPF                     I2C3_MSR_EPF        /*!< End package flag                    */
#define DDL_I2C3_MASTER_SDF                     I2C3_MSR_SDF        /*!< Stop detection flag                 */
#define DDL_I2C3_MASTER_NDF                     I2C3_MSR_NDF        /*!< Not Acknowledge detection flag      */
#define DDL_I2C3_MASTER_ALF                     I2C3_MSR_ALF        /*!< Arbitration lost                    */
#define DDL_I2C3_MASTER_FEF                     I2C3_MSR_FEF        /*!< FIFO error flag                     */
#define DDL_I2C3_MASTER_PLTF                    I2C3_MSR_PLTF       /*!< Pin low-level timeout               */
#define DDL_I2C3_MASTER_DMF                     I2C3_MSR_DMF        /*!< Data match                          */
#define DDL_I2C3_MASTER_MBF                     I2C3_MSR_MBF        /*!< Master busy                         */
#define DDL_I2C3_MASTER_BBF                     I2C3_MSR_BBF        /*!< Bus busy                            */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_GET_SLAVE_FLAG Get Slave Flags Defines
  * @brief    Flags defines which can be used with DDL_I2C3_ReadReg function.
  * @{
  */
#define DDL_I2C3_SLAVE_TDF                      I2C3_SSR_TDF        /*!< Transmit data                       */
#define DDL_I2C3_SLAVE_RDF                      I2C3_SSR_RDF        /*!< Receive data                        */
#define DDL_I2C3_SLAVE_AVF                      I2C3_SSR_AVF        /*!< Receive data register not empty     */
#define DDL_I2C3_SLAVE_TAF                      I2C3_SSR_TAF        /*!< Address matched (slave mode)        */
#define DDL_I2C3_SLAVE_RSF                      I2C3_SSR_RSF        /*!< Not Acknowledge received flag       */
#define DDL_I2C3_SLAVE_SDF                      I2C3_SSR_SDF        /*!< Stop detection flag                 */
#define DDL_I2C3_SLAVE_BEF                      I2C3_SSR_BEF        /*!< Transfer Complete (master mode)     */
#define DDL_I2C3_SLAVE_FEF                      I2C3_SSR_FEF        /*!< FIFO error flag                     */
#define DDL_I2C3_SLAVE_AM0F                     I2C3_SSR_AM0F       /*!< Bus error                           */
#define DDL_I2C3_SLAVE_AM1F                     I2C3_SSR_AM1F       /*!< Arbitration lost                    */
#define DDL_I2C3_SLAVE_GCF                      I2C3_SSR_GCF        /*!< Overrun/Underrun (slave mode)       */
#define DDL_I2C3_SLAVE_SARF                     I2C3_SSR_SARF       /*!< PEC Error in reception (SMBus mode) */
#define DDL_I2C3_SLAVE_SBF                      I2C3_SSR_SBF        /*!< Timeout detection flag (SMBus mode) */
#define DDL_I2C3_SLAVE_BBF                      I2C3_SSR_BBF        /*!< SMBus alert (SMBus mode)            */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_MASTER_IT Master IT Defines
  * @brief    IT defines which can be used with DDL_I2C3_ReadReg and DDL_I2C3_WriteReg functions.
  * @{
  */
#define DDL_I2C3_MASTER_TDIE                    I2C3_MIER_TDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_RDIE                    I2C3_MIER_RDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_EPIE                    I2C3_MIER_EPIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_SDIE                    I2C3_MIER_SDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_NDIE                    I2C3_MIER_NDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_ALIE                    I2C3_MIER_ALIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_FEIE                    I2C3_MIER_FEIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_PLTIE                   I2C3_MIER_PLTIE     /*!< TX Interrupt enable                 */
#define DDL_I2C3_MASTER_DMIE                    I2C3_MIER_DMIE      /*!< TX Interrupt enable                 */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_SLAVE_IT Slave IT Defines
  * @brief    IT defines which can be used with DDL_I2C3_ReadReg and DDL_I2C3_WriteReg functions.
  * @{
  */
#define DDL_I2C3_SLAVE_TDIE                     I2C3_SIER_TDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_RDIE                     I2C3_SIER_RDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_AVIE                     I2C3_SIER_AVIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_TAIE                     I2C3_SIER_TAIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_RSIE                     I2C3_SIER_RSIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_SDIE                     I2C3_SIER_SDIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_BEIE                     I2C3_SIER_BEIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_FEIE                     I2C3_SIER_FEIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_AM0IE                    I2C3_SIER_AM0IE     /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_AM1IE                    I2C3_SIER_AM1IE     /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_GCIE                     I2C3_SIER_GCIE      /*!< TX Interrupt enable                 */
#define DDL_I2C3_SLAVE_ASRIE                    I2C3_SIER_ASRIE     /*!< TX Interrupt enable                 */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_I2C3_ACKNOWLEDGE Acknowledge Generation
  * @{
  */
#define DDL_I2C3_ACK                            0x00000000U         /*!< ACK is sent after current received byte. */
#define DDL_I2C3_NACK                           I2C3_STAR_TXNACK    /*!< NACK is sent after current received byte.*/
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_DMA_REG_DATA DMA Register Data
  * @{
  */
#define DDL_I2C3_DMA_REG_DATA_TRANSMIT          0x00000000U         /*!< Get address of data register used for transmission */
#define DDL_I2C3_DMA_REG_DATA_RECEIVE           0x00000001U         /*!< Get address of data register used for reception */
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_TIMEOUT_CONFIG I2C3 Timeout Configuration
  * @{
  */
#define DDL_I2C3_TIMEOUT_SCL                    (0x00000000U)
#define DDL_I2C3_TIMEOUT_SCL_SDA                (I2C3_MCFGR1_TIMECFG)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_MATCH_MODE I2C3 Match Mode
  * @{
  */
#define DDL_I2C3_MATCHMODE_DISABLE              (0x00)
#define DDL_I2C3_MATCHMODE_FIRST_OR             (0x02)
#define DDL_I2C3_MATCHMODE_ANY_OR               (0x03)
#define DDL_I2C3_MATCHMODE_FIRST_AND_SECOND     (0x04)
#define DDL_I2C3_MATCHMODE_ANY_AND_SECOND       (0x05)
#define DDL_I2C3_MATCHMODE_FIRST_MASK           (0x06)
#define DDL_I2C3_MATCHMODE_ANY_MASK             (0x07)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_ADDR_MATCH_CONFIG I2C3 Addr Match CONFIG
  * @{
  */
#define DDL_I2C3_MATCH_ADDR0_7BIT                  (0x00000000U)
#define DDL_I2C3_MATCH_ADDR0_10BIT                 (I2C3_SCFGR1_ADDRCFG_0)
#define DDL_I2C3_MATCH_ADDR0_7BIT_OR_ADDR1_7BIT    (I2C3_SCFGR1_ADDRCFG_1)
#define DDL_I2C3_MATCH_ADDR0_10BIT_OR_ADDR1_10BIT  (I2C3_SCFGR1_ADDRCFG_1 | I2C3_SCFGR1_ADDRCFG_0)
#define DDL_I2C3_MATCH_ADDR0_7BIT_OR_ADDR1_10BIT   (I2C3_SCFGR1_ADDRCFG_2)
#define DDL_I2C3_MATCH_ADDR0_10BIT_OR_ADDR1_7BIT   (I2C3_SCFGR1_ADDRCFG_2 | I2C3_SCFGR1_ADDRCFG_0)
#define DDL_I2C3_MATCH_ADDR0_7BIT_AND_ADDR1_7BIT   (I2C3_SCFGR1_ADDRCFG_2 | I2C3_SCFGR1_ADDRCFG_1)
#define DDL_I2C3_MATCH_ADDR0_10BIT_AND_ADDR1_10BIT (I2C3_SCFGR1_ADDRCFG_2 | I2C3_SCFGR1_ADDRCFG_1 | I2C3_SCFGR1_ADDRCFG_0)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_PIN_MODE I2C3 Pin Mode
  * @{
  */
#define DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN                       (0x00)
#define DDL_I2C3_PINMODE_2WIRE_OUTPUT_ONLY                      (0x02)
#define DDL_I2C3_PINMODE_2WIRE_PUSH_PULL                        (0x03)
#define DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN_WITH_SEPARATE_SLVAE   (0x04)
#define DDL_I2C3_PINMODE_2WIRE_OUTPUT_ONLY_WITH_SEPARATE_SLVAE  (0x05)
#define DDL_I2C3_PINMODE_2WIRE_PUSH_PULL_WITH_SEPARATE_SLVAE    (0x06)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_TX_FLAG_CONDITION Tx Flag Condition
  * @{
  */
#define DDL_I2C3_TXFLAG_DR_EMPTY_AND_TRANSMITTING  (0x00000000U)
#define DDL_I2C3_TXFLAG_DR_EMPTY                   (I2C3_SCFGR1_TXCFG)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_RX_FLAG_CONDITION Rx Flag Condition
  * @{
  */
#define DDL_I2C3_RXFLAG_READ_DATA                  (0x00000000U)
#define DDL_I2C3_RXFLAG_READ_DATA_AND_ADDR         (I2C3_SCFGR1_RXCFG)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EC_CMD I2C3 Command
  * @{
  */
#define DDL_I2C3_CMD_WRITE                      (0x00000000U)
#define DDL_I2C3_CMD_READ                       (0x00000001U)
#define DDL_I2C3_CMD_STOP                       (0x00000002U)
#define DDL_I2C3_CMD_DISCARD                    (0x00000003U)
#define DDL_I2C3_CMD_ADDR_WITH_NACK             (0x00000004U)
#define DDL_I2C3_CMD_ADDR_WITH_ACK              (0x00000005U)
#define DDL_I2C3_CMD_ADDR_WITH_ACK_HS           (0x00000006U)
#define DDL_I2C3_CMD_ADDR_WITH_NACK_HS          (0x00000007U)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup I2C3_DDL_Exported_Macros I2C3 Exported Macros
  * @{
  */

/** @defgroup I2C3_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in I2C3 register.
  * @param  __INSTANCE__ I2C3 Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_I2C3_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in I2C3 register.
  * @param  __INSTANCE__ I2C3 Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_I2C3_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup I2C3_DDL_EM_CONVERT_TIMINGS Convert SDA SCL timings
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
#define __DDL_I2C3_CONVERT_TIMINGS(__PRESCALER__, __SETUP_TIME__, __HOLD_TIME__, __SCLH_PERIOD__, __SCLL_PERIOD__) \
  ((((uint32_t)(__PRESCALER__)    << I2C3_TIMING_TIMINGPSC_Pos)  & I2C3_TIMING_TIMINGPSC)   | \
   (((uint32_t)(__SETUP_TIME__)   << I2C3_TIMING_DATAT_Pos) & I2C3_TIMING_DATAT)  | \
   (((uint32_t)(__HOLD_TIME__)    << I2C3_TIMING_DATAHT_Pos) & I2C3_TIMING_DATAHT)  | \
   (((uint32_t)(__SCLH_PERIOD__)  << I2C3_TIMING_SCLH_Pos)   & I2C3_TIMING_SCLH)    | \
   (((uint32_t)(__SCLL_PERIOD__)  << I2C3_TIMING_SCLL_Pos)   & I2C3_TIMING_SCLL))
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup I2C3_DDL_Exported_Functions I2C3 Exported Functions
  * @{
  */

/** @defgroup I2C3_DDL_EF_Version Version
  * @{
  */

/**
  * @brief  Get feature version ID.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can be one offollowing values:
  *         @arg 0010b: only support master device.
  *         @arg 0011b: support master or slave device.
  */
__STATIC_INLINE uint32_t DDL_I2C3_GetFeatureID(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->VERID, I2C3_VERID_FEATURE) >> I2C3_VERID_FEATURE_Pos);
}

/**
  * @brief  Get minor version ID.
  * @param  I2C3x I2C3 Instance.
  * @retval The minor version ID
  */
__STATIC_INLINE uint32_t DDL_I2C3_GetMinorID(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->VERID, I2C3_VERID_MINOR) >> I2C3_VERID_MINOR_Pos);
}

/**
  * @brief  Get major version ID.
  * @param  I2C3x I2C3 Instance.
  * @retval The major version ID
  */
__STATIC_INLINE uint32_t DDL_I2C3_GetMajorID(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->VERID, I2C3_VERID_MAJOR) >> I2C3_VERID_MAJOR_Pos);
}
/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Parameter Parameter
  * @{
  */

/**
  * @brief  Get the size of Tx FIFO.
  * @param  I2C3x I2C3 Instance.
  * @retval The size of master Tx FIFO.
  */
__STATIC_INLINE uint32_t DDL_I2C3_GetTxFIFOSize(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->PARAM, I2C3_PARAM_MTXFIFO) >> I2C3_PARAM_MTXFIFO_Pos);
}

/**
  * @brief  Get the size of Rx FIFO.
  * @param  I2C3x I2C3 Instance.
  * @retval The size of master receive FIFO.
  */
__STATIC_INLINE uint32_t DDL_I2C3_GetRxFIFOSize(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->PARAM, I2C3_PARAM_MRXFIFO) >> I2C3_PARAM_MRXFIFO_Pos);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Master_Configuration Master Configuration
  * @{
  */

/**
  * @brief  Enable I2C3 master peripheral.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_Enable(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MCR, I2C3_MCR_MEN);
}

/**
  * @brief  Disable I2C3 master peripheral.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_Disable(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MCR, I2C3_MCR_MEN);
}

/**
  * @brief  Check if the I2C3 master peripheral is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabled(I2C3_TypeDef *I2C3x)
{
  return ((READ_BIT(I2C3x->MCR, I2C3_MCR_MEN) == (I2C3_MCR_MEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable I2C3 master peripheral reset.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableSoftwareReset(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MCR, I2C3_MCR_RST);
}

/**
  * @brief  Disable I2C3 master peripheral reset.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableSoftwareReset(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MCR, I2C3_MCR_RST);
}

/**
  * @brief  Enable I2C3 master peripheral in debug mode.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableDebug(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MCR, I2C3_MCR_DBGEN);
}

/**
  * @brief  Disable I2C3 master peripheral in debug mode.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableDebug(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MCR, I2C3_MCR_DBGEN);
}

/**
  * @brief  Enable I2C3 master circular FIFO.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableCircularFIFO(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MCFGR0, I2C3_MCFGR0_CIRFIFO);
}

/**
  * @brief  Disable I2C3 master circular FIFO.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableCircularFIFO(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MCFGR0, I2C3_MCFGR0_CIRFIFO);
}

/**
  * @brief  Enable I2C3 master only receive match data.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableReceiveMatchDataOnly(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MCFGR0, I2C3_MCFGR0_RDMO);
}

/**
  * @brief  Disable I2C3 master only receive match data.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableReceiveMatchDataOnly(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MCFGR0, I2C3_MCFGR0_RDMO);
}

/**
  * @brief  Set I2C3 master prescale.
  * @param  I2C3x I2C3 Instance.
  * @param  Prescale This value can between Max_num=7 and Min_num=0.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetPrescale(I2C3_TypeDef *I2C3x, uint32_t Prescale)
{
  MODIFY_REG(I2C3x->MCFGR1, I2C3_MCFGR1_PRESCALE, Prescale);
}

/**
  * @brief  Get I2C3 master prescale.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=7 and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetPrescale(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_PRESCALE));
}

/**
  * @brief  Enable I2C3 master automatic STOP condition generation.
  * @note   Automatic end mode : a STOP condition is automatically sent
  *         when tranmit FIFO is empty and master in busy.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableAutoEndMode(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_AUTOSTOP);
}

/**
  * @brief  Disable I2C3 master automatic STOP condition generation.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableAutoEndMode(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_AUTOSTOP);
}

/**
  * @brief  Set I2C3 master NACK mode.
  * @param  I2C3x I2C3 Instance.
  * @param  NACKMode This parameter can be one of following value:
  *         @arg @ref DDL_I2C3_NACKMODE_RECEIVED
  *         @arg @ref DDL_I2C3_NACKMODE_IGNORE
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetNACKMode(I2C3_TypeDef *I2C3x, uint32_t NACKMode)
{
  MODIFY_REG(I2C3x->MCFGR1, I2C3_MCFGR1_IGNACK, NACKMode);
}

/**
  * @brief  Get I2C3 master NACK mode.
  * @param  I2C3x I2C3 Instance.
  * @retval Return value can be one of following value:
  *         @arg @ref DDL_I2C3_NACKMODE_RECEIVED
  *         @arg @ref DDL_I2C3_NACKMODE_IGNORE
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetNACKMode(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_IGNACK));
}

/**
  * @brief  Set I2C3 master timeout configuration.
  * @param  I2C3x I2C3 Instance.
  * @param  Configure This value can be one of following values:
  *         @arg @def DDL_I2C3_TIMEOUT_SCL
  *         @arg @def DDL_I2C3_TIMEOUT_SCL_SDA
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetTimeoutConfig(I2C3_TypeDef *I2C3x, uint32_t Configure)
{
  MODIFY_REG(I2C3x->MCFGR1, I2C3_MCFGR1_TIMECFG, Configure);
}

/**
  * @brief  Disable I2C3 master auto stop.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can be one of following values:
  *         @arg @def DDL_I2C3_TIMEOUT_SCL
  *         @arg @def DDL_I2C3_TIMEOUT_SCL_SDA
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetTimeoutConfig(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_TIMECFG));
}

/**
  * @brief  Configure I2C3 master match mode.
  * @param  I2C3x I2C3 Instance.
  * @param  Mode This value can be one of following values:
  *         @arg @def DDL_I2C3_MATCHMODE_DISABLE
  *         @arg @def DDL_I2C3_MATCHMODE_FIRST_OR
  *         @arg @def DDL_I2C3_MATCHMODE_ANY_OR
  *         @arg @def DDL_I2C3_MATCHMODE_FIRST_AND_SECOND
  *         @arg @def DDL_I2C3_MATCHMODE_ANY_AND_SECOND
  *         @arg @def DDL_I2C3_MATCHMODE_FIRST_MASK
  *         @arg @def DDL_I2C3_MATCHMODE_ANY_MASK
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetMatchMode(I2C3_TypeDef *I2C3x, uint32_t Mode)
{
  SET_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_MATCFG);
}

/**
  * @brief  Get I2C3 master match mode.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can be one of following values:
  *         @arg @def DDL_I2C3_MATCHMODE_DISABLE
  *         @arg @def DDL_I2C3_MATCHMODE_FIRST_OR
  *         @arg @def DDL_I2C3_MATCHMODE_ANY_OR
  *         @arg @def DDL_I2C3_MATCHMODE_FIRST_AND_SECOND
  *         @arg @def DDL_I2C3_MATCHMODE_ANY_AND_SECOND
  *         @arg @def DDL_I2C3_MATCHMODE_FIRST_MASK
  *         @arg @def DDL_I2C3_MATCHMODE_ANY_MASK
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetMatchMode(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_MATCFG));
}

/**
  * @brief  Configure I2C3 master pin mode.
  * @param  I2C3x I2C3 Instance.
  * @param  Mode This value can be one of following values:
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OUTPUT_ONLY
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_PUSH_PULL
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN_WITH_SEPARATE_SLVAE
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OUTPUT_ONLY_WITH_SEPARATE_SLVAE
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_PUSH_PULL_WITH_SEPARATE_SLVAE
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetPinMode(I2C3_TypeDef *I2C3x, uint32_t Mode)
{
  MODIFY_REG(I2C3x->MCFGR1, I2C3_MCFGR1_PINCFG, Mode << I2C3_MCFGR1_PINCFG_Pos);
}

/**
  * @brief  Get I2C3 master pin mode.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can be one of following values:
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OUTPUT_ONLY
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_PUSH_PULL
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN_WITH_SEPARATE_SLVAE
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_OUTPUT_ONLY_WITH_SEPARATE_SLVAE
  *         @arg @def DDL_I2C3_PINMODE_2WIRE_PUSH_PULL_WITH_SEPARATE_SLVAE
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetPinMode(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR1, I2C3_MCFGR1_PINCFG) >> I2C3_MCFGR1_PINCFG_Pos);
}

/**
  * @brief  Configure I2C3 master bus idle timeout time.
  * @param  I2C3x I2C3 Instance.
  * @param  Timeout This value can between Max_num=0xFFF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetIdleTimeout(I2C3_TypeDef *I2C3x, uint32_t Timeout)
{
  MODIFY_REG(I2C3x->MCFGR2, I2C3_MCFGR2_BUSIDLE, Timeout);
}

/**
  * @brief  Get I2C3 master bus idle timeout time.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFFF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetIdleTimeout(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR2, I2C3_MCFGR2_BUSIDLE));
}

/**
  * @brief  Configure I2C3 master SCL fitler value.
  * @param  I2C3x I2C3 Instance.
  * @param  Filter This value can between Max_num=0xF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSCLFilter(I2C3_TypeDef *I2C3x, uint32_t Filter)
{
  MODIFY_REG(I2C3x->MCFGR2, I2C3_MCFGR2_FILTSCL, (Filter << I2C3_MCFGR2_FILTSCL_Pos));
}

/**
  * @brief  Get I2C3 master SCL fitler value.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFFF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetSCLFilter(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR2, I2C3_MCFGR2_FILTSCL) >> I2C3_MCFGR2_FILTSCL_Pos);
}

/**
  * @brief  Configure I2C3 master SDA fitler value.
  * @param  I2C3x I2C3 Instance.
  * @param  Filter This value can between Max_num=0xF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSDAFilter(I2C3_TypeDef *I2C3x, uint32_t Filter)
{
  MODIFY_REG(I2C3x->MCFGR2, I2C3_MCFGR2_FILTSDA, (Filter << I2C3_MCFGR2_FILTSDA_Pos));
}

/**
  * @brief  Get I2C3 master SDA fitler value.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetSDAFilter(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR2, I2C3_MCFGR2_FILTSDA) >> I2C3_MCFGR2_FILTSDA_Pos);
}

/**
  * @brief  Configure I2C3 master Bus timeout time.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0xFFF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetPinLowTimeout(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCFGR3, I2C3_MCFGR3_PINLOW, (Time << I2C3_MCFGR3_PINLOW_Pos));
}

/**
  * @brief  Get I2C3 master Bus timeout time.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFFF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetPinLowTimeout(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCFGR3, I2C3_MCFGR3_PINLOW) >> I2C3_MCFGR3_PINLOW_Pos);
}

/**
  * @brief  Configure I2C3 master match0.
  * @param  I2C3x I2C3 Instance.
  * @param  Match This value can between Max_num=0xFF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetMatch0(I2C3_TypeDef *I2C3x, uint32_t Match)
{
  MODIFY_REG(I2C3x->MDMR, I2C3_MDMR_MATCH0, (Match << I2C3_MDMR_MATCH0_Pos));
}

/**
  * @brief  Get I2C3 master match0.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetMatch0(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MDMR, I2C3_MDMR_MATCH0) >> I2C3_MDMR_MATCH0_Pos);
}

/**
  * @brief  Configure I2C3 master match1.
  * @param  I2C3x I2C3 Instance.
  * @param  Match This value can between Max_num=0xFFF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetMatch1(I2C3_TypeDef *I2C3x, uint32_t Match)
{
  MODIFY_REG(I2C3x->MDMR, I2C3_MDMR_MATCH1, (Match << I2C3_MDMR_MATCH1_Pos));
}

/**
  * @brief  Get I2C3 master match1.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFFF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetMatch1(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MDMR, I2C3_MDMR_MATCH1) >> I2C3_MDMR_MATCH1_Pos);
}

/**
  * @brief  Configure I2C3 master clock low level cycle.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSCLLowPeriod(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCCR0, I2C3_MCCR0_CLKLO, (Time << I2C3_MCCR0_CLKLO_Pos));
}

/**
  * @brief  Get I2C3 master clock low level cycle.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetClockLowLevelTime(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR0, I2C3_MCCR0_CLKLO) >> I2C3_MCCR0_CLKLO_Pos);
}

/**
  * @brief  Configure I2C3 master clock high level cycle.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSCLHighPeriod(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCCR0, I2C3_MCCR0_CLKHI, (Time << I2C3_MCCR0_CLKHI_Pos));
}

/**
  * @brief  Get I2C3 master clock high level cycle.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetClockHighLevelTime(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR0, I2C3_MCCR0_CLKHI) >> I2C3_MCCR0_CLKHI_Pos);
}

/**
  * @brief  Configure I2C3 master hold cycle.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSetupHoldDelay(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCCR0, I2C3_MCCR0_SETHOLD, (Time << I2C3_MCCR0_SETHOLD_Pos));
}

/**
  * @brief  Get I2C3 master hold cycle.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetSetupHoldDelay(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR0, I2C3_MCCR0_SETHOLD) >> I2C3_MCCR0_SETHOLD_Pos);
}

/**
  * @brief  Configure I2C3 master data valid delay.
  * @param  I2C3x I2C3 Instance.
  * @param  Delay This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetDataValidDelay(I2C3_TypeDef *I2C3x, uint32_t Delay)
{
  MODIFY_REG(I2C3x->MCCR0, I2C3_MCCR0_DATAVD, (Delay << I2C3_MCCR0_DATAVD_Pos));
}

/**
  * @brief  Get I2C3 master data valid delay.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetDataValidDelay(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR0, I2C3_MCCR0_DATAVD) >> I2C3_MCCR0_DATAVD_Pos);
}

/**
  * @brief  Configure I2C3 master clock low level cycle in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSCLLowPeriod_HS(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCCR1, I2C3_MCCR1_CLKLO, (Time << I2C3_MCCR1_CLKLO_Pos));
}

/**
  * @brief  Get I2C3 master clock low level cycle in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetClockLowLevelTime_HS(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR1, I2C3_MCCR1_CLKLO) >> I2C3_MCCR1_CLKLO_Pos);
}

/**
  * @brief  Configure I2C3 master clock high level cycle in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSCLHighPeriod_HS(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCCR1, I2C3_MCCR1_CLKHI, (Time << I2C3_MCCR1_CLKHI_Pos));
}

/**
  * @brief  Get I2C3 master clock high level cycle in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetClockHighLevelTime_HS(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR1, I2C3_MCCR1_CLKHI) >> I2C3_MCCR1_CLKHI_Pos);
}

/**
  * @brief  Configure I2C3 master hold cycle in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetSetupHoldDelay_HS(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->MCCR1, I2C3_MCCR1_SETHOLD, (Time << I2C3_MCCR1_SETHOLD_Pos));
}

/**
  * @brief  Get I2C3 master hold cycle in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetSetupHoldDelay_HS(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR1, I2C3_MCCR1_SETHOLD) >> I2C3_MCCR1_SETHOLD_Pos);
}

/**
  * @brief  Configure I2C3 master data valid delay in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @param  Delay This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetDataValidDelay_HS(I2C3_TypeDef *I2C3x, uint32_t Delay)
{
  MODIFY_REG(I2C3x->MCCR1, I2C3_MCCR1_DATAVD, (Delay << I2C3_MCCR1_DATAVD_Pos));
}

/**
  * @brief  Get I2C3 master data valid delay in high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetDataValidDelay_HS(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCCR1, I2C3_MCCR1_DATAVD) >> I2C3_MCCR1_DATAVD_Pos);
}

/**
  * @brief  Configure I2C3 master Tx FIFO water.
  * @param  I2C3x I2C3 Instance.
  * @param  Delay This value can between Max_num=0x3 and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetTxFIFOWater(I2C3_TypeDef *I2C3x, uint32_t Delay)
{
  MODIFY_REG(I2C3x->MFCR, I2C3_MFCR_TXWATER, (Delay << I2C3_MFCR_TXWATER_Pos));
}

/**
  * @brief  Get I2C3 master Tx FIFO water.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3 and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetTxFIFOWater(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MFCR, I2C3_MFCR_TXWATER) >> I2C3_MFCR_TXWATER_Pos);
}

/**
  * @brief  Configure I2C3 master Rx FIFO water.
  * @param  I2C3x I2C3 Instance.
  * @param  Delay This value can between Max_num=0x3 and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetRxFIFOWater(I2C3_TypeDef *I2C3x, uint32_t Delay)
{
  MODIFY_REG(I2C3x->MFCR, I2C3_MFCR_RXWATER, (Delay << I2C3_MFCR_RXWATER_Pos));
}

/**
  * @brief  Get I2C3 master Rx FIFO water.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3 and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetRxFIFOWater(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MFCR, I2C3_MFCR_RXWATER) >> I2C3_MFCR_RXWATER_Pos);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Master_Data Master Data
  * @{
  */

/**
  * @brief  Get I2C3 master Tx FIFO count.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x7 and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetTxFIFOCount(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MFSR, I2C3_MFSR_TXCOUNT) >> I2C3_MFSR_TXCOUNT_Pos);
}

/**
  * @brief  Get I2C3 master Rx FIFO count.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x7 and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_GetRxFIFOCount(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MFSR, I2C3_MFSR_RXCOUNT) >> I2C3_MFSR_RXCOUNT_Pos);
}

/**
  * @brief  I2C3 master transmit data.
  * @param  I2C3x I2C3 Instance.
  * @param  data This value can between Max_num=0xFF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_TxData(I2C3_TypeDef *I2C3x, uint8_t Data)
{
  SET_BIT(I2C3x->MTDR, (Data << I2C3_MTDR_DATA_Pos));
}

/**
  * @brief  Set I2C3 master transmit command.
  * @note   Set command will affect the operation of the next data.
  * @param  I2C3x I2C3 Instance.
  * @param  data This value can be one of following values:
  *         @arg @def DDL_I2C3_CMD_WRITE
  *         @arg @def DDL_I2C3_CMD_READ
  *         @arg @def DDL_I2C3_CMD_STOP
  *         @arg @def DDL_I2C3_CMD_DISCARD
  *         @arg @def DDL_I2C3_CMD_ADDR_WITH_NACK
  *         @arg @def DDL_I2C3_CMD_ADDR_WITH_ACK
  *         @arg @def DDL_I2C3_CMD_ADDR_WITH_ACK_HS
  *         @arg @def DDL_I2C3_CMD_ADDR_WITH_NACK_HS
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_SetTxCmd(I2C3_TypeDef *I2C3x, uint8_t Cmd)
{
  SET_BIT(I2C3x->MTDR, (Cmd << I2C3_MTDR_CMD_Pos));
}

/**
  * @brief  I2C3 master transmit data.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFF and Min_num=0
  */
__STATIC_INLINE uint8_t DDL_I2C3_Master_RxData(I2C3_TypeDef *I2C3x)
{
  return (uint8_t)(READ_BIT(I2C3x->MRDR, I2C3_MRDR_DATA) >> I2C3_MRDR_DATA_Pos);
}

/**
  * @brief  Check if I2C3 master Rx FIFO is empty.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0).
  */
__STATIC_INLINE uint8_t DDL_I2C3_Master_IsRxFIFOEmpty(I2C3_TypeDef *I2C3x)
{
  return (uint8_t)(READ_BIT(I2C3x->MRDR, I2C3_MRDR_RXEMPTY) == I2C3_MRDR_RXEMPTY ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Master_Flag_Management Master Flag Management
  * @{
  */

/**
  * @brief  Check if the repeat transmit flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_RT(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCR, I2C3_MCR_RTF) == I2C3_MCR_RTF ? 1UL : 0UL);
}

/**
  * @brief  Check if the repeat receive flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_RR(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MCR, I2C3_MCR_RRF) == I2C3_MCR_RRF ? 1UL : 0UL);
}

/**
  * @brief  Check if the transmit data flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_TD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_TDF) == I2C3_MSR_TDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the receive data flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_RD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_RDF) == I2C3_MSR_RDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the end package flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_EP(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_EPF) == I2C3_MSR_EPF ? 1UL : 0UL);
}

/**
  * @brief  Check if the stop detect flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_SD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_SDF) == I2C3_MSR_SDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the NACK detect flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_ND(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_NDF) == I2C3_MSR_NDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the arbitration loss flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_AL(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_ALF) == I2C3_MSR_ALF ? 1UL : 0UL);
}

/**
  * @brief  Check if the FIFO error flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_FE(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_FEF) == I2C3_MSR_FEF ? 1UL : 0UL);
}

/**
  * @brief  Check if the Bus timeout flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_PLT(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_PLTF) == I2C3_MSR_PLTF ? 1UL : 0UL);
}

/**
  * @brief  Check if the data match flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_DM(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_DMF) == I2C3_MSR_DMF ? 1UL : 0UL);
}

/**
  * @brief  Check if the master busy flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_MB(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_MBF) == I2C3_MSR_MBF ? 1UL : 0UL);
}

/**
  * @brief  Check if the bus busy flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsActiveFlag_BB(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MSR, I2C3_MSR_BBF) == I2C3_MSR_BBF ? 1UL : 0UL);
}

/**
  * @}
  */


/** @defgroup I2C3_DDL_EF_Master_IT_Management Master Interrupt Management
  * @{
  */

/**
  * @brief  Enable the transmit data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_TD(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_TDIE);
}

/**
  * @brief  Disable the transmit data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_TD(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_TDIE);
}

/**
  * @brief  Check if the transmit data interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_TD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_TDIE) == I2C3_MIER_TDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the receive data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_RD(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_RDIE);
}

/**
  * @brief  Disable the receive data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_RD(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_RDIE);
}

/**
  * @brief  Check if the receive data interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_RD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_RDIE) == I2C3_MIER_RDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the end package interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_EP(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_EPIE);
}

/**
  * @brief  Disable the end package interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_EP(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_EPIE);
}

/**
  * @brief  Check if the end package interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_EP(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_EPIE) == I2C3_MIER_EPIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the stop detect interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_SD(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_SDIE);
}

/**
  * @brief  Disable the stop detect interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_SD(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_SDIE);
}

/**
  * @brief  Check if the stop detect interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_SD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_SDIE) == I2C3_MIER_SDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the NACK detect interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_ND(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_NDIE);
}

/**
  * @brief  Disable the NACK detect interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_ND(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_NDIE);
}

/**
  * @brief  Check if the NACK detect interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_ND(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_NDIE) == I2C3_MIER_NDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the arbitration loss interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_AL(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_ALIE);
}

/**
  * @brief  Disable the arbitration loss interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_AL(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_ALIE);
}

/**
  * @brief  Check if the arbitration loss interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_AL(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_ALIE) == I2C3_MIER_ALIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the FIFO error interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_FE(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_FEIE);
}

/**
  * @brief  Disable the FIFO error interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_FE(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_FEIE);
}

/**
  * @brief  Check if the FIFO error interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_FE(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_FEIE) == I2C3_MIER_FEIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the Bus timeout interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_PLT(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_PLTIE);
}

/**
  * @brief  Disable the Bus timeout interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_PLT(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_PLTIE);
}

/**
  * @brief  Check if the Bus timeout interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_PLT(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_PLTIE) == I2C3_MIER_PLTIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the data match interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableIT_DM(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MIER, I2C3_MIER_DMIE);
}

/**
  * @brief  Disable the data match interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableIT_DM(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MIER, I2C3_MIER_DMIE);
}

/**
  * @brief  Check if the data match interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledIT_DM(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MIER, I2C3_MIER_DMIE) == I2C3_MIER_DMIE ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Master_DMA_Management Master DMA Management
  * @{
  */

/**
  * @brief  Enable the transmit data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableDMAReq_Tx(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MDER, I2C3_MDER_TDDE);
}

/**
  * @brief  Disable the transmit data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableDMAReq_Tx(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MDER, I2C3_MDER_TDDE);
}

/**
  * @brief  Check if the transmit data DMA request is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledDMAReq_Tx(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MDER, I2C3_MDER_TDDE) == I2C3_MDER_TDDE ? 1UL : 0UL);
}

/**
  * @brief  Enable the receive data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_EnableDMAReq_Rx(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->MDER, I2C3_MDER_RDDE);
}

/**
  * @brief  Disable the receive data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Master_DisableDMAReq_Rx(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->MDER, I2C3_MDER_RDDE);
}

/**
  * @brief  Check if the receive data DMA request is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_IsEnabledDMAReq_Rx(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->MDER, I2C3_MDER_RDDE) == I2C3_MDER_RDDE ? 1UL : 0UL);
}

/**
  * @brief  Get the data register address used for DMA transfer.
  * @param  I2C3x I2C3 Instance
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref DDL_I2C3_DMA_REG_DATA_TRANSMIT
  *         @arg @ref DDL_I2C3_DMA_REG_DATA_RECEIVE
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t DDL_I2C3_Master_DMA_GetRegAddr(const I2C3_TypeDef *I2C3x, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == DDL_I2C3_DMA_REG_DATA_TRANSMIT)
  {
    /* return address of MTDR register */
    data_reg_addr = (uint32_t) &(I2C3x->MTDR);
  }
  else
  {
    /* return address of MRDR register */
    data_reg_addr = (uint32_t) &(I2C3x->MRDR);
  }

  return data_reg_addr;
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Slave_Configuration Slave Configuration
  * @{
  */

/**
  * @brief  Enable I2C3 slave peripheral.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_Enable(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCR, I2C3_SCR_SEN);
}

/**
  * @brief  Disable I2C3 slave peripheral.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_Disable(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCR, I2C3_SCR_SEN);
}

/**
  * @brief  Check if the I2C3 slave peripheral is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabled(I2C3_TypeDef *I2C3x)
{
  return ((READ_BIT(I2C3x->SCR, I2C3_SCR_SEN) == (I2C3_SCR_SEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable I2C3 slave peripheral reset.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableSoftwareReset(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCR, I2C3_SCR_RST);
}

/**
  * @brief  Disable I2C3 slave peripheral reset.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableSoftwareReset(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCR, I2C3_SCR_RST);
}

/**
  * @brief  Enable I2C3 slave filter.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableFilter(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCR, I2C3_SCR_FILTEN);
}

/**
  * @brief  Disable I2C3 slave filter.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableFilter(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCR, I2C3_SCR_FILTEN);
}

/**
  * @brief  Enable I2C3 slave the SCL to stretch when the address is valid.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableAddressStall(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_ADRSTALL);
}

/**
  * @brief  Disable I2C3 slave the SCL to stretch when the address is valid.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableAddressStall(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_ADRSTALL);
}

/**
  * @brief  Enable I2C3 slave the SCL to stretch when receive data.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableRxStall(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_RXSTAL);
}

/**
  * @brief  Disable I2C3 slave the SCL to stretch when receive data.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableRxStall(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_RXSTAL);
}

/**
  * @brief  Enable I2C3 slave the SCL to stretch when transmit data.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableTxStall(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_TXDSTALL);
}

/**
  * @brief  Disable I2C3 slave the SCL to stretch when transmit data.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableTxStall(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_TXDSTALL);
}

/**
  * @brief  Enable I2C3 slave the SCL to stretch before transmit ACK.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableACKStall(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_ACKDSTALL);
}

/**
  * @brief  Disable I2C3 slave the SCL to stretch before transmit ACK.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableACKStall(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_ACKDSTALL);
}

/**
  * @brief  Enable I2C3 slave general call.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableGeneralCall(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_GCEN);
}

/**
  * @brief  Disable I2C3 slave general call.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableGeneralCall(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_GCEN);
}

/**
  * @brief  Enable I2C3 slave SMBus alarm.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableSMBusAlarm(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_SAEN);
}

/**
  * @brief  Disable I2C3 slave SMBus alarm.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableSMBusAlarm(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_SAEN);
}
// TODO change name
/**
  * @brief  Configure I2C3 slave Tx flag setting condition.
  * @param  I2C3x I2C3 Instance.
  * @param  Condition This value can be one of following value:
  *         @arg @def DDL_I2C3_TXFLAG_DR_EMPTY_AND_TRANSMITTING
  *         @arg @def DDL_I2C3_TXFLAG_DR_EMPTY
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_ConfigTxFlagSettingCondition(I2C3_TypeDef *I2C3x, uint32_t Condition)
{
  MODIFY_REG(I2C3x->SCFGR1, I2C3_SCFGR1_TXCFG, Condition);
}

/**
  * @brief  Get I2C3 slave Tx flag setting condition.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can be one of following value:
  *         @arg @def DDL_I2C3_TXFLAG_DR_EMPTY_AND_TRANSMITTING
  *         @arg @def DDL_I2C3_TXFLAG_DR_EMPTY
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetTxFlagSettingCondition(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_TXCFG));
}

/**
  * @brief  Configure I2C3 slave Rx operation.
  * @param  I2C3x I2C3 Instance.
  * @param  Condition This value can be one of following value:
  *         @arg @def DDL_I2C3_RXFLAG_READ_DATA
  *         @arg @def DDL_I2C3_RXFLAG_READ_DATA_AND_ADDR
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_ConfigRxDataCondition(I2C3_TypeDef *I2C3x, uint32_t Condition)
{
  MODIFY_REG(I2C3x->SCFGR1, I2C3_SCFGR1_RXCFG, Condition);
}

/**
  * @brief  Get I2C3 slave Rx operation.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can be one of following value:
  *         @arg @def DDL_I2C3_RXFLAG_READ_DATA
  *         @arg @def DDL_I2C3_RXFLAG_READ_DATA_AND_ADDR
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetRxDataCondition(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_RXCFG));
}

/**
  * @brief  Enable I2C3 slave ignore NACK.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIgnoreNACK(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_IGNACK);
}

/**
  * @brief  Disable I2C3 slave ignore NACK.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIgnoreNACK(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_IGNACK);
}

/**
  * @brief  Enable I2C3 slave high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableHighSpeedMode(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_HSMEN);
}

/**
  * @brief  Disable I2C3 slave high speed mode.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableHighSpeedMode(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_HSMEN);
}

/**
  * @brief  Set I2C3 slave address match condition.
  * @param  I2C3x I2C3 Instance.
  * @param  MatchConfig This parameter can be one of following value:
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT_OR_ADDR1_7BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT_OR_ADDR1_10BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT_OR_ADDR1_10BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT_OR_ADDR1_7BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT_AND_ADDR1_7BIT
  *                @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT_AND_ADDR1_10BIT
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetAddrMatchConfig(I2C3_TypeDef *I2C3x, uint32_t MatchConfig)
{
  MODIFY_REG(I2C3x->SCFGR1, I2C3_SCFGR1_ADDRCFG, MatchConfig);
}

/**
  * @brief  Get I2C3 slave address match condition.
  * @param  I2C3x I2C3 Instance.
  * @retval This parameter can be one of following value:
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT_OR_ADDR1_7BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT_OR_ADDR1_10BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT_OR_ADDR1_10BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT_OR_ADDR1_7BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_7BIT_AND_ADDR1_7BIT
  *         @arg @ref DDL_I2C3_MATCH_ADDR0_10BIT_AND_ADDR1_10BIT
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetAddrMatchConfig(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR1, I2C3_SCFGR1_ADDRCFG));
}

/**
  * @brief  Set I2C3 slave clock hold time.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0xF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetClockHoldTime(I2C3_TypeDef *I2C3x, uint32_t Time)
{
  MODIFY_REG(I2C3x->SCFGR2, I2C3_SCFGR2_CLKHOLD, (Time << I2C3_SCFGR2_CLKHOLD_Pos));
}

/**
  * @brief  Get I2C3 slave clock hold time.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetClockHoldTime(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR2, I2C3_SCFGR2_CLKHOLD) >> I2C3_SCFGR2_CLKHOLD_Pos);
}

/**
  * @brief  Set I2C3 slave data valid delay.
  * @param  I2C3x I2C3 Instance.
  * @param  Time This value can between Max_num=0x3F and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetDataValidDelay(I2C3_TypeDef *I2C3x, uint32_t Delay)
{
  MODIFY_REG(I2C3x->SCFGR2, I2C3_SCFGR2_DATAVD, (Delay << I2C3_SCFGR2_DATAVD_Pos));
}

/**
  * @brief  Get I2C3 slave data valid delay.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3F and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetDataValidDelay(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR2, I2C3_SCFGR2_DATAVD) >> I2C3_SCFGR2_DATAVD_Pos);
}

/**
  * @brief  Configure I2C3 slave SCL fitler value.
  * @param  I2C3x I2C3 Instance.
  * @param  Filter This value can between Max_num=0xF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetSCLFilter(I2C3_TypeDef *I2C3x, uint32_t Filter)
{
  MODIFY_REG(I2C3x->SCFGR2, I2C3_SCFGR2_FILTSCL, (Filter << I2C3_SCFGR2_FILTSCL_Pos));
}

/**
  * @brief  Get I2C3 slave SCL fitler value.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetSCLFilter(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR2, I2C3_SCFGR2_FILTSCL) >> I2C3_SCFGR2_FILTSCL_Pos);
}

/**
  * @brief  Configure I2C3 slave SDA fitler value.
  * @param  I2C3x I2C3 Instance.
  * @param  Filter This value can between Max_num=0xF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetSDAFilter(I2C3_TypeDef *I2C3x, uint32_t Filter)
{
  MODIFY_REG(I2C3x->SCFGR2, I2C3_SCFGR2_FILTSDA, (Filter << I2C3_SCFGR2_FILTSDA_Pos));
}

/**
  * @brief  Get I2C3 slave SDA fitler value.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetSDAFilter(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCFGR2, I2C3_SCFGR2_FILTSDA) >> I2C3_SCFGR2_FILTSDA_Pos);
}

/**
  * @brief  Set I2C3 slave address0.
  * @param  I2C3x I2C3 Instance.
  * @param  Addr This value can between Max_num=0x3FF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetAddr0(I2C3_TypeDef *I2C3x, uint32_t Addr)
{
  MODIFY_REG(I2C3x->SAMR, I2C3_SAMR_ADDR0, (Addr << I2C3_SAMR_ADDR0_Pos));
}

/**
  * @brief  Get I2C3 slave address0.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3FF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetAddr0(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SAMR, I2C3_SAMR_ADDR0) >> I2C3_SAMR_ADDR0_Pos);
}

/**
  * @brief  Set I2C3 slave address1.
  * @param  I2C3x I2C3 Instance.
  * @param  Addr This value can between Max_num=0x3FF and Min_num=0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetAddr1(I2C3_TypeDef *I2C3x, uint32_t Addr)
{
  MODIFY_REG(I2C3x->SAMR, I2C3_SAMR_ADDR1, (Addr << I2C3_SAMR_ADDR1_Pos));
}

/**
  * @brief  Get I2C3 slave address1.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x3FF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetAddr1(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SAMR, I2C3_SAMR_ADDR1) >> I2C3_SAMR_ADDR1_Pos);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Slave_Data Slave Data
  * @{
  */

/**
  * @brief  Get I2C3 slave receive address.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0x7FF and Min_num=0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_GetRxAddr(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SASR, I2C3_SASR_RADDR) >> I2C3_SASR_RADDR_Pos);
}

/**
  * @brief  Check if the receive address is valid.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsValid_RxAddr(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SASR, I2C3_SASR_ANV) == I2C3_SASR_ANV ? 1UL : 0UL);
}

/**
  * @brief  Set I2C3 slave transmit ACK mode.
  * @note   Each time receive a byte, will send a ACK or NACK.
  * @param  I2C3x I2C3 Instance.
  * @param  ACK This value can be one of following value:
  *         @arg @def DDL_I2C3_ACK
  *         @arg @def DDL_I2C3_NACK
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_SetTxACKMode(I2C3_TypeDef *I2C3x, uint32_t ACK)
{
  MODIFY_REG(I2C3x->STAR, I2C3_STAR_TXNACK, (ACK << I2C3_STAR_TXNACK_Pos));
}

/**
  * @brief  I2C3 slave transmit data.
  * @param  I2C3x I2C3 Instance.
  * @param  Data This value can between Max_num=0xFF and Min_num=0x0
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_TxData(I2C3_TypeDef *I2C3x, uint32_t Data)
{
  MODIFY_REG(I2C3x->STDR, I2C3_STDR_DATA, (Data << I2C3_STDR_DATA_Pos));
}

/**
  * @brief  I2C3 slave receive data.
  * @param  I2C3x I2C3 Instance.
  * @retval This value can between Max_num=0xFF and Min_num=0x0
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_RxData(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SRDR, I2C3_SRDR_DATA) >> I2C3_SRDR_DATA_Pos);
}

/**
  * @brief  Check if the I2C3 slave Rx register is empty.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsRxEmpty(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SRDR, I2C3_SRDR_RXEMPTY) == I2C3_SRDR_RXEMPTY ? 1UL : 0UL);
}

/**
  * @brief  Check if the I2C3 slave.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsFrameStart(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SRDR, I2C3_SRDR_SOF) == I2C3_SRDR_SOF ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Slave_Flag_Management Slave Flag Management
  * @{
  */

/**
  * @brief  Check if the repeat transmit flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_RT(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCR, I2C3_SCR_RTF) == I2C3_SCR_RTF ? 1UL : 0UL);
}

/**
  * @brief  Check if the repeat receive flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_RR(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SCR, I2C3_SCR_RRF) == I2C3_SCR_RRF ? 1UL : 0UL);
}

/**
  * @brief  Check if the transmit data flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_TD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_TDF) == I2C3_SSR_TDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the receive data flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_RD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_RDF) == I2C3_SSR_RDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the address valid flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_AV(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_AVF) == I2C3_SSR_AVF ? 1UL : 0UL);
}

/**
  * @brief  Check if the transmit ACK flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_TA(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_TAF) == I2C3_SSR_TAF ? 1UL : 0UL);
}

/**
  * @brief  Check if the repeat start flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_RS(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_RSF) == I2C3_SSR_RSF ? 1UL : 0UL);
}

/**
  * @brief  Check if the stop detect flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_SD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_SDF) == I2C3_SSR_SDF ? 1UL : 0UL);
}

/**
  * @brief  Check if the bit error flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_BE(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_BEF) == I2C3_SSR_BEF ? 1UL : 0UL);
}

/**
  * @brief  Check if the FIFO error flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_FE(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_FEF) == I2C3_SSR_FEF ? 1UL : 0UL);
}

/**
  * @brief  Check if the address match 0 flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_AM0(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_AM0F) == I2C3_SSR_AM0F ? 1UL : 0UL);
}

/**
  * @brief  Check if the address match 1 flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_AM1(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_AM1F) == I2C3_SSR_AM1F ? 1UL : 0UL);
}

/**
  * @brief  Check if the general call flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_GC(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_GCF) == I2C3_SSR_GCF ? 1UL : 0UL);
}

/**
  * @brief  Check if the SMBus alarm respon flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_SAR(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_SARF) == I2C3_SSR_SARF ? 1UL : 0UL);
}

/**
  * @brief  Check if the slave busy flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_SB(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_SBF) == I2C3_SSR_SBF ? 1UL : 0UL);
}

/**
  * @brief  Check if the bus busy flag is activated.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsActiveFlag_BB(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SSR, I2C3_SSR_BBF) == I2C3_SSR_BBF ? 1UL : 0UL);
}

/**
  * @}
  */


/** @defgroup I2C3_DDL_EF_Slave_IT_Management Slave Interrupt Management
  * @{
  */

/**
  * @brief  Enable the transmit data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_TD(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_TDIE);
}

/**
  * @brief  Disable the transmit data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_TD(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_TDIE);
}

/**
  * @brief  Check if the transmit data interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_TD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_TDIE) == I2C3_SIER_TDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the receive data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_RD(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_RDIE);
}

/**
  * @brief  Disable the receive data interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_RD(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_RDIE);
}

/**
  * @brief  Check if the receive data interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_RD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_RDIE) == I2C3_SIER_RDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the address valid interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_AV(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_AVIE);
}

/**
  * @brief  Disable the address valid interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_AV(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_AVIE);
}

/**
  * @brief  Check if the address valid interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_AV(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_AVIE) == I2C3_SIER_AVIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the transmit ACK interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_TA(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_TAIE);
}

/**
  * @brief  Disable the transmit ACK interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_TA(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_TAIE);
}

/**
  * @brief  Check if the transmit ACK interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_TA(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_TAIE) == I2C3_SIER_TAIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the repeat start interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_RS(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_RSIE);
}

/**
  * @brief  Disable the repeat start interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_RS(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_RSIE);
}

/**
  * @brief  Check if the repeat start interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_RS(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_RSIE) == I2C3_SIER_RSIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the stop detect interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_SD(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_SDIE);
}

/**
  * @brief  Disable the stop detect interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_SD(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_SDIE);
}

/**
  * @brief  Check if the stop detect interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_SD(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_SDIE) == I2C3_SIER_SDIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the bit error interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_BE(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_BEIE);
}

/**
  * @brief  Disable the bit error interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_BE(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_BEIE);
}

/**
  * @brief  Check if the bit error interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_BE(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_BEIE) == I2C3_SIER_BEIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the FIFO error interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_FE(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_FEIE);
}

/**
  * @brief  Disable the FIFO error interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_FE(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_FEIE);
}

/**
  * @brief  Check if the FIFO error interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_FE(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_FEIE) == I2C3_SIER_FEIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the address match 0 interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_AM0(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_AM0IE);
}

/**
  * @brief  Disable the address match 0 interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_AM0(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_AM0IE);
}

/**
  * @brief  Check if the address match 0 interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_AM0(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_AM0IE) == I2C3_SIER_AM0IE ? 1UL : 0UL);
}

/**
  * @brief  Enable the address match 1 interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_AM1(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_AM1IE);
}

/**
  * @brief  Disable the address match 1 interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_AM1(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_AM1IE);
}

/**
  * @brief  Check if the address match 1 interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_AM1(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_AM1IE) == I2C3_SIER_AM1IE ? 1UL : 0UL);
}

/**
  * @brief  Enable the general call interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_GC(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_GCIE);
}

/**
  * @brief  Disable the general call interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_GC(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_GCIE);
}

/**
  * @brief  Check if the general call interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_GC(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_GCIE) == I2C3_SIER_GCIE ? 1UL : 0UL);
}

/**
  * @brief  Enable the SMBus alarm respon interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableIT_ASR(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SIER, I2C3_SIER_ASRIE);
}

/**
  * @brief  Disable the SMBus alarm respon interrupt.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableIT_ASR(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SIER, I2C3_SIER_ASRIE);
}

/**
  * @brief  Check if the SMBus alarm respon interrupt is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledIT_ASR(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SIER, I2C3_SIER_ASRIE) == I2C3_SIER_ASRIE ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C3_DDL_EF_Slave_DMA_Management Slave DMA Management
  * @{
  */

/**
  * @brief  Enable the transmit data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableDMAReq_Tx(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SDER, I2C3_SDER_TDDE);
}

/**
  * @brief  Disable the transmit data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableDMAReq_Tx(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SDER, I2C3_SDER_TDDE);
}

/**
  * @brief  Check if the transmit data DMA request is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledDMAReq_Tx(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SDER, I2C3_SDER_TDDE) == I2C3_SDER_TDDE ? 1UL : 0UL);
}

/**
  * @brief  Enable the receive data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableDMAReq_Rx(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SDER, I2C3_SDER_RDDE);
}

/**
  * @brief  Disable the receive data DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableDMAReq_Rx(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SDER, I2C3_SDER_RDDE);
}

/**
  * @brief  Check if the receive data DMA request is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledDMAReq_Rx(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SDER, I2C3_SDER_RDDE) == I2C3_SDER_RDDE ? 1UL : 0UL);
}

/**
  * @brief  Enable the address valid DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_EnableDMAReq_AV(I2C3_TypeDef *I2C3x)
{
  SET_BIT(I2C3x->SDER, I2C3_SDER_AVDE);
}

/**
  * @brief  Disable the address valid DMA request.
  * @param  I2C3x I2C3 Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_I2C3_Slave_DisableDMAReq_AV(I2C3_TypeDef *I2C3x)
{
  CLEAR_BIT(I2C3x->SDER, I2C3_SDER_AVDE);
}

/**
  * @brief  Check if the address valid DMA request is enabled.
  * @param  I2C3x I2C3 Instance.
  * @retval The state bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_IsEnabledDMAReq_AV(I2C3_TypeDef *I2C3x)
{
  return (uint32_t)(READ_BIT(I2C3x->SDER, I2C3_SDER_AVDE) == I2C3_SDER_AVDE ? 1UL : 0UL);
}

/**
  * @brief  Get the data register address used for DMA transfer.
  * @param  I2C3x I2C3 Instance
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref DDL_I2C3_DMA_REG_DATA_TRANSMIT
  *         @arg @ref DDL_I2C3_DMA_REG_DATA_RECEIVE
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t DDL_I2C3_Slave_DMA_GetRegAddr(const I2C3_TypeDef *I2C3x, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == DDL_I2C3_DMA_REG_DATA_TRANSMIT)
  {
    /* return address of STDR register */
    data_reg_addr = (uint32_t) &(I2C3x->STDR);
  }
  else
  {
    /* return address of SRDR register */
    data_reg_addr = (uint32_t) &(I2C3x->SRDR);
  }

  return data_reg_addr;
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup I2C3_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_I2C3_DeInit(I2C3_TypeDef *I2C3x);

ErrorStatus DDL_I2C3_Master_Init(I2C3_TypeDef *I2C3x, DDL_I2C3_MasterInitTypeDef *I2C3_InitStruct);
void DDL_I2C3_Master_StructInit(DDL_I2C3_MasterInitTypeDef *I2C3_InitStruct);

ErrorStatus DDL_I2C3_Slave_Init(I2C3_TypeDef *I2C3x, DDL_I2C3_SlaveInitTypeDef *I2C3_InitStruct);
void DDL_I2C3_Slave_StructInit(DDL_I2C3_SlaveInitTypeDef *I2C3_InitStruct);

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

#endif /* I2C3 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_I2C3_H */
