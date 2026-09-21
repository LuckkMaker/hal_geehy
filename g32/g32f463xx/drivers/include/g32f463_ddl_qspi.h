/**
  *
  * @file    g32f463_ddl_qspi.h
  * @brief   Header file of QSPI DDL module.
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

#ifndef G32F463_DDL_QSPI_H
#define G32F463_DDL_QSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (QSPI1) || defined (QSPI2)

/** @defgroup QSPI_DDL QSPI
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup QSPI_DDL_ES_INIT QSPI Exported Init structure
  * @{
  */

/**
  * @brief  QSPI Init structures definition
  */
typedef struct
{
    uint32_t ClockPrescaler;        /*!< Specifies the prescaler factor for generating clock based on the AHB clock.
                                         This parameter can be a even number between 2 and 65534. */

    uint32_t ClockStretch;          /*!< Specifies the clock stretch enable/disable.
                                         This parameter can be a value of ENABLE or DISABLE */

    uint32_t TxFifoThreshold;       /*!< Specifies the threshold level of the transmit FIFO.
                                         This parameter can be a value between 0 and 7. */

    uint32_t TxFifoLevel;           /*!< Specifies the level of the transmit FIFO startup level.
                                         This parameter can be a value between 0 and 7. */

    uint32_t RxFifoThreshold;       /*!< Specifies the threshold level of the receive FIFO.
                                            This parameter can be a value between 0 and 7. */

    uint32_t ChipSelectToggle;      /*!< Specifies the Chip Select Toggle.
                                         This parameter can be a value of @ref QSPI_DDL_EC_ChipSelectToggle */
} DDL_QSPI_InitTypeDef;

/**
  * @brief  QSPI Command structure definition
  */
typedef struct
{
    uint32_t Instruction;       /*!< Specifies the Instruction to be sent.
                                     This parameter can be a value between 0x00 and 0xFF */

    uint32_t Address;           /*!< Specifies the Address to be sent.
                                     This parameter can be a value between 0x00 and 0xFFFFFFFF */

    uint32_t AddressSize;       /*!< Specifies the Address Size.
                                     This parameter can be a value of @ref QSPI_DDL_EC_ADDR_LEN */

    uint32_t InstructionMode;   /*!< Specifies the Instruction Mode.
                                     This parameter can be a value of @ref QSPI_DDL_EC_IAT */

    uint32_t InstructionSize;   /*!< Specifies the Instruction Size.
                                     This parameter can be a value of @ref QSPI_DDL_EC_INST_LEN */

    uint32_t TransferMode;      /*!< Specifies the Transfer Mode.
                                     This parameter can be a value of @ref QSPI_DDL_EC_TXMODE */

    uint32_t FrameFormat;       /*!< Specifies the frame format.
                                         This parameter can be a value of @ref QSPI_DDL_EC_FRAME_FORMAT */

    uint32_t DataFrameSize;     /*!< Specifies the data frame size.
                                         This parameter can be a value of @ref QSPI_DDL_EC_DFS */

    uint32_t DummyCycles;       /*!< Specifies the Number of Dummy Cycles.
                                     This parameter can be a number between 0 and 31 */

    uint16_t NbData;            /*!< Specifies the Number of Data to transfer.
                                     This parameter can be a number between 0 and 0xFFFF */
} DDL_QSPI_CommandTypeDef;

/**
  * @brief  QSPI XIP structure definition
  */
typedef struct
{
    uint32_t Instruction;             /*!< Specifies the Instruction to be sent.
                                            This parameter can be a value between 0x00 and 0xFF */

    uint32_t WrapCode;                /*!< Specifies the Wrap transfer code.
                                            This parameter can be a value between 0x00 and 0xFF */

    uint32_t AddressSize;             /*!< Specifies the Address Size.
                                            This parameter can be a value of @ref QSPI_DDL_EC_XIP_ADDR_LEN */

    uint32_t InstructionMode;         /*!< Specifies the Instruction Mode.
                                            This parameter can be a value of @ref QSPI_DDL_EC_XIP_IAT */

    uint32_t InstructionSize;         /*!< Specifies the Instruction Size.
                                            This parameter can be a value of @ref QSPI_DDL_EC_XIP_INST_LEN */

    uint32_t FrameFormat;             /*!< Specifies the frame format.
                                            This parameter can be a value of @ref QSPI_DDL_EC_XIP_FRAME_FORMAT */

    uint32_t DummyCycles;             /*!< Specifies the Number of Dummy Cycles.
                                            This parameter can be a number between 0 and 31 */

    uint32_t Endianness;              /*!< Specifies the Endianness for external memory access.
                                            This parameter can be a value of @ref QSPI_DDL_EC_XIP_MEM_ACCESS */

    FunctionalState ContinuousMode;    /*!< Specifies the Continuous Mode.
                                            This parameter can be a value of ENABLE or DISABLE */

    FunctionalState PrefetchMode;      /*!< Specifies the Prefetch Mode.
                                            This parameter can be a value of ENABLE or DISABLE */
} DDL_QSPI_XIPTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup QSPI_DDL_Exported_Macros QSPI Exported Macros
  * @{
  */

/** @defgroup QSPI_DDL_EC_DFS Data Frame Size
  * @{
  */
#define DDL_QSPI_DFS_BIT_01     0x00000000                                                                                      /*!< Reserved */
#define DDL_QSPI_DFS_BIT_02     QSPI_CTRL1_DFS_0                                                                                /*!< Reserved */
#define DDL_QSPI_DFS_BIT_03     (QSPI_CTRL1_DFS_1)                                                                              /*!< Reserved */
#define DDL_QSPI_DFS_BIT_04     (QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                                                           /*!< 04-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_05     (QSPI_CTRL1_DFS_2)                                                                              /*!< 05-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_06     (QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_0)                                                           /*!< 06-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_07     (QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1)                                                           /*!< 07-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_08     (QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                                        /*!< 08-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_09     (QSPI_CTRL1_DFS_3)                                                                              /*!< 09-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_10     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_0)                                                           /*!< 10-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_11     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_1)                                                           /*!< 11-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_12     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                                        /*!< 12-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_13     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2)                                                           /*!< 13-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_14     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_0)                                        /*!< 14-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_15     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1)                                        /*!< 15-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_16     (QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                     /*!< 16-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_17     (QSPI_CTRL1_DFS_4)                                                                              /*!< 17-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_18     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_0)                                                           /*!< 18-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_19     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_1)                                                           /*!< 19-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_20     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                                        /*!< 20-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_21     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_2)                                                           /*!< 21-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_22     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_0)                                        /*!< 22-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_23     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1)                                        /*!< 23-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_24     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                     /*!< 24-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_25     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3)                                                           /*!< 25-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_26     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_0)                                        /*!< 26-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_27     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_1)                                        /*!< 27-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_28     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)                     /*!< 28-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_29     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2)                                        /*!< 29-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_30     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_0)                     /*!< 30-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_31     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1)                     /*!< 31-bit Serial Data Transmission */
#define DDL_QSPI_DFS_BIT_32     (QSPI_CTRL1_DFS_4 | QSPI_CTRL1_DFS_3 | QSPI_CTRL1_DFS_2 | QSPI_CTRL1_DFS_1 | QSPI_CTRL1_DFS_0)  /*!< 32-bit Serial Data Transmission */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_TXMODE Transmission Mode
  * @{
  */
#define DDL_QSPI_TXMODE_TX_AND_RX       0x00000000             /*!< Send and Receive  */
#define DDL_QSPI_TXMODE_TX_ONLY         QSPI_CTRL1_TXMODE_0    /*!< Send Only Mode    */
#define DDL_QSPI_TXMODE_RX_ONLY         QSPI_CTRL1_TXMODE_1    /*!< Receive Only Mode */
#define DDL_QSPI_TXMODE_EEPROM_READ     QSPI_CTRL1_TXMODE      /*!< EEPROM Read Mode  */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_ChipSelectToggle QSPI Chip Select ChipSelectToggle
  * @{
  */
#define DDL_QSPI_CS_TOGGLE_DISABLE        0x00000000U               /*!< QSPI chip select signal doesn't toggle between frames */
#define DDL_QSPI_CS_TOGGLE_ENABLE         QSPI_CTRL1_SSTEN          /*!< QSPI chip select signal toggles between frames        */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_FRAME_FORMAT Transmission Frame Format
  * @{
  */
#define DDL_QSPI_FRAME_FORMAT_STANDARD     0x00000000          /*!< Standard SPI Mode  */
#define DDL_QSPI_FRAME_FORMAT_DUAL         QSPI_CTRL1_FRF_0    /*!< Dual SPI Mode    */
#define DDL_QSPI_FRAME_FORMAT_QUAD         QSPI_CTRL1_FRF_1    /*!< Quad SPI Mode */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_RSE RXD sample edge
  * @{
  */
#define DDL_QSPI_RSE_RISING          0x00000000             /*!< Rising edge sample  */
#define DDL_QSPI_RSE_FALLING         QSPI_RSD_RSE           /*!< Falling edge sample */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_IAT instruction and address type
  * @{
  */
#define DDL_QSPI_IAT_STANDARD_INST_ADDR     0x00000000          /*!< Tx instruction in standard SPI mode,Tx address in standard SPI mode  */
#define DDL_QSPI_IAT_STANDARD_INST          QSPI_CTRL3_IAT_0    /*!< Tx instruction in standard SPI mode,Tx address in mode of SPI_FRF    */
#define DDL_QSPI_IAT_FRF_INST_ADDR          QSPI_CTRL3_IAT_1    /*!< Tx instruction in mode of SPI_FRF,Tx address in mode of SPI_FRF      */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_ADDR_LEN address length
  * @{
  */
#define DDL_QSPI_ADDR_LEN_0               0x00000000                                                            /*!< no address            */
#define DDL_QSPI_ADDR_LEN_4BIT            QSPI_CTRL3_ADDRLEN_0                                                  /*!< 4-bit address length  */
#define DDL_QSPI_ADDR_LEN_8BIT            QSPI_CTRL3_ADDRLEN_1                                                  /*!< 8-bit address length  */
#define DDL_QSPI_ADDR_LEN_12BIT           (QSPI_CTRL3_ADDRLEN_1 | QSPI_CTRL3_ADDRLEN_0)                         /*!< 12-bit address length  */
#define DDL_QSPI_ADDR_LEN_16BIT           (QSPI_CTRL3_ADDRLEN_2)                                                /*!< 16-bit address length  */
#define DDL_QSPI_ADDR_LEN_20BIT           (QSPI_CTRL3_ADDRLEN_2 | QSPI_CTRL3_ADDRLEN_0)                         /*!< 20-bit address length  */
#define DDL_QSPI_ADDR_LEN_24BIT           (QSPI_CTRL3_ADDRLEN_2 | QSPI_CTRL3_ADDRLEN_1)                         /*!< 24-bit address length  */
#define DDL_QSPI_ADDR_LEN_28BIT           (QSPI_CTRL3_ADDRLEN_2 | QSPI_CTRL3_ADDRLEN_1 | QSPI_CTRL3_ADDRLEN_0)  /*!< 28-bit address length  */
#define DDL_QSPI_ADDR_LEN_32BIT           (QSPI_CTRL3_ADDRLEN_3)                                                /*!< 32-bit address length  */
#define DDL_QSPI_ADDR_LEN_36BIT           (QSPI_CTRL3_ADDRLEN_3 | QSPI_CTRL3_ADDRLEN_0)                         /*!< 36-bit address length  */
#define DDL_QSPI_ADDR_LEN_40BIT           (QSPI_CTRL3_ADDRLEN_3 | QSPI_CTRL3_ADDRLEN_1)                         /*!< 40-bit address length  */
#define DDL_QSPI_ADDR_LEN_44BIT           (QSPI_CTRL3_ADDRLEN_3 | QSPI_CTRL3_ADDRLEN_1 | QSPI_CTRL3_ADDRLEN_0)  /*!< 44-bit address length  */
#define DDL_QSPI_ADDR_LEN_48BIT           (QSPI_CTRL3_ADDRLEN_3 | QSPI_CTRL3_ADDRLEN_2)                         /*!< 48-bit address length  */
#define DDL_QSPI_ADDR_LEN_52BIT           (QSPI_CTRL3_ADDRLEN_3 | QSPI_CTRL3_ADDRLEN_2 | QSPI_CTRL3_ADDRLEN_0)  /*!< 52-bit address length  */
#define DDL_QSPI_ADDR_LEN_56BIT           (QSPI_CTRL3_ADDRLEN_3 | QSPI_CTRL3_ADDRLEN_2 | QSPI_CTRL3_ADDRLEN_1)  /*!< 56-bit address length  */
#define DDL_QSPI_ADDR_LEN_60BIT           (QSPI_CTRL3_ADDRLEN)                                                  /*!< 60-bit address length  */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_INST_LEN instruction length
  * @{
  */
#define DDL_QSPI_INST_LEN_0         0x00000000              /*!< no instruction     */
#define DDL_QSPI_INST_LEN_4BIT      QSPI_CTRL3_INSLEN_0     /*!< 4-bit instruction  */
#define DDL_QSPI_INST_LEN_8BIT      QSPI_CTRL3_INSLEN_1     /*!< 8-bit instruction  */
#define DDL_QSPI_INST_LEN_16BIT     QSPI_CTRL3_INSLEN       /*!< 16-bit instruction */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_XIP_MEM_ACCESS instruction length
  * @{
  */
#define DDL_QSPI_XIP_MEM_ACCESS_BIG_ENDIAN       0x00000000                       /*!< Big endian     */
#define DDL_QSPI_XIP_MEM_ACCESS_LITTLE_ENDIAN    QSPI_SWITCH_LITTLE_ENDIAN     /*!< Little endian  */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_XIP_FRAME_FORMAT XIP Transmission Frame Format
  * @{
  */
#define DDL_QSPI_XIP_FRAME_FORMAT_DUAL         QSPI_XIP_CTRL_FRF_0    /*!< Dual SPI Mode    */
#define DDL_QSPI_XIP_FRAME_FORMAT_QUAD         QSPI_XIP_CTRL_FRF_1    /*!< Quad SPI Mode    */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_XIP_IAT XIP instruction and address type
  * @{
  */
#define DDL_QSPI_XIP_IAT_STANDARD_INST_ADDR     0x00000000                    /*!< Tx instruction in standard SPI mode,Tx address in standard SPI mode  */
#define DDL_QSPI_XIP_IAT_STANDARD_INST          QSPI_XIP_CTRL_TRANS_TYPE_0    /*!< Tx instruction in standard SPI mode,Tx address in mode of XIP_CTRL[FRF]    */
#define DDL_QSPI_XIP_IAT_FRF_INST_ADDR          QSPI_XIP_CTRL_TRANS_TYPE_1    /*!< Tx instruction in mode of SPI_FRF,Tx address in mode of XIP_CTRL[FRF]      */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_XIP_ADDR_LEN XIP address length
  * @{
  */
#define DDL_QSPI_XIP_ADDR_LEN_0               0x00000000                                                                 /*!< no address            */
#define DDL_QSPI_XIP_ADDR_LEN_4BIT            QSPI_XIP_CTRL_ADDR_L_0                                                     /*!< 4-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_8BIT            QSPI_XIP_CTRL_ADDR_L_1                                                     /*!< 8-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_12BIT           (QSPI_XIP_CTRL_ADDR_L_1 | QSPI_XIP_CTRL_ADDR_L_0)                          /*!< 12-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_16BIT           (QSPI_XIP_CTRL_ADDR_L_2)                                                   /*!< 16-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_20BIT           (QSPI_XIP_CTRL_ADDR_L_2 | QSPI_XIP_CTRL_ADDR_L_0)                          /*!< 20-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_24BIT           (QSPI_XIP_CTRL_ADDR_L_2 | QSPI_XIP_CTRL_ADDR_L_1)                          /*!< 24-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_28BIT           (QSPI_XIP_CTRL_ADDR_L_2 | QSPI_XIP_CTRL_ADDR_L_1 | QSPI_XIP_CTRL_ADDR_L_0) /*!< 28-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_32BIT           (QSPI_XIP_CTRL_ADDR_L_3)                                                   /*!< 32-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_36BIT           (QSPI_XIP_CTRL_ADDR_L_3 | QSPI_XIP_CTRL_ADDR_L_0)                          /*!< 36-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_40BIT           (QSPI_XIP_CTRL_ADDR_L_3 | QSPI_XIP_CTRL_ADDR_L_1)                          /*!< 40-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_44BIT           (QSPI_XIP_CTRL_ADDR_L_3 | QSPI_XIP_CTRL_ADDR_L_1 | QSPI_XIP_CTRL_ADDR_L_0) /*!< 44-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_48BIT           (QSPI_XIP_CTRL_ADDR_L_3 | QSPI_XIP_CTRL_ADDR_L_2)                          /*!< 48-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_52BIT           (QSPI_XIP_CTRL_ADDR_L_3 | QSPI_XIP_CTRL_ADDR_L_2 | QSPI_XIP_CTRL_ADDR_L_0) /*!< 52-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_56BIT           (QSPI_XIP_CTRL_ADDR_L_3 | QSPI_XIP_CTRL_ADDR_L_2 | QSPI_XIP_CTRL_ADDR_L_1) /*!< 56-bit address length  */
#define DDL_QSPI_XIP_ADDR_LEN_60BIT           (QSPI_XIP_CTRL_ADDR_L)                                                     /*!< 60-bit address length  */
/**
  * @}
  */

/** @defgroup QSPI_DDL_EC_XIP_INST_LEN XIP instruction length
  * @{
  */
#define DDL_QSPI_XIP_INST_LEN_0         0x00000000                 /*!< no instruction     */
#define DDL_QSPI_XIP_INST_LEN_4BIT      QSPI_XIP_CTRL_INST_L_0     /*!< 4-bit instruction  */
#define DDL_QSPI_XIP_INST_LEN_8BIT      QSPI_XIP_CTRL_INST_L_1     /*!< 8-bit instruction  */
#define DDL_QSPI_XIP_INST_LEN_16BIT     QSPI_XIP_CTRL_INST_L       /*!< 16-bit instruction */
/**
  * @}
  */



/** @defgroup QSPI_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in QSPI register
  * @param  __INSTANCE__ QSPI Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_QSPI_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in QSPI register
  * @param  __INSTANCE__ QSPI Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_QSPI_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup QSPI_DDL_Exported_Functions QSPI Exported Functions
  * @{
  */

/**
  * @brief  Set Data Frame Size (DFS)
  * @param  QSPIx QSPI Instance
  * @param  dfs This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_DFS_BIT_01
  *         @arg @ref DDL_QSPI_DFS_BIT_02
  *         @arg @ref DDL_QSPI_DFS_BIT_03
  *         @arg @ref DDL_QSPI_DFS_BIT_04
  *         @arg @ref DDL_QSPI_DFS_BIT_05
  *         @arg @ref DDL_QSPI_DFS_BIT_06
  *         @arg @ref DDL_QSPI_DFS_BIT_07
  *         @arg @ref DDL_QSPI_DFS_BIT_08
  *         @arg @ref DDL_QSPI_DFS_BIT_09
  *         @arg @ref DDL_QSPI_DFS_BIT_10
  *         @arg @ref DDL_QSPI_DFS_BIT_11
  *         @arg @ref DDL_QSPI_DFS_BIT_12
  *         @arg @ref DDL_QSPI_DFS_BIT_13
  *         @arg @ref DDL_QSPI_DFS_BIT_14
  *         @arg @ref DDL_QSPI_DFS_BIT_15
  *         @arg @ref DDL_QSPI_DFS_BIT_16
  *         @arg @ref DDL_QSPI_DFS_BIT_17
  *         @arg @ref DDL_QSPI_DFS_BIT_18
  *         @arg @ref DDL_QSPI_DFS_BIT_19
  *         @arg @ref DDL_QSPI_DFS_BIT_20
  *         @arg @ref DDL_QSPI_DFS_BIT_21
  *         @arg @ref DDL_QSPI_DFS_BIT_22
  *         @arg @ref DDL_QSPI_DFS_BIT_23
  *         @arg @ref DDL_QSPI_DFS_BIT_24
  *         @arg @ref DDL_QSPI_DFS_BIT_25
  *         @arg @ref DDL_QSPI_DFS_BIT_26
  *         @arg @ref DDL_QSPI_DFS_BIT_27
  *         @arg @ref DDL_QSPI_DFS_BIT_28
  *         @arg @ref DDL_QSPI_DFS_BIT_29
  *         @arg @ref DDL_QSPI_DFS_BIT_30
  *         @arg @ref DDL_QSPI_DFS_BIT_31
  *         @arg @ref DDL_QSPI_DFS_BIT_32
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetDataFrameSize(QSPI_TypeDef *QSPIx, uint32_t dfs)
{
    MODIFY_REG(QSPIx->CTRL1, QSPI_CTRL1_DFS, dfs);
}

/**
  * @brief  Get Data Frame Size (DFS)
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_DFS_BIT_01
  *         @arg @ref DDL_QSPI_DFS_BIT_02
  *         @arg @ref DDL_QSPI_DFS_BIT_03
  *         @arg @ref DDL_QSPI_DFS_BIT_04
  *         @arg @ref DDL_QSPI_DFS_BIT_05
  *         @arg @ref DDL_QSPI_DFS_BIT_06
  *         @arg @ref DDL_QSPI_DFS_BIT_07
  *         @arg @ref DDL_QSPI_DFS_BIT_08
  *         @arg @ref DDL_QSPI_DFS_BIT_09
  *         @arg @ref DDL_QSPI_DFS_BIT_10
  *         @arg @ref DDL_QSPI_DFS_BIT_11
  *         @arg @ref DDL_QSPI_DFS_BIT_12
  *         @arg @ref DDL_QSPI_DFS_BIT_13
  *         @arg @ref DDL_QSPI_DFS_BIT_14
  *         @arg @ref DDL_QSPI_DFS_BIT_15
  *         @arg @ref DDL_QSPI_DFS_BIT_16
  *         @arg @ref DDL_QSPI_DFS_BIT_17
  *         @arg @ref DDL_QSPI_DFS_BIT_18
  *         @arg @ref DDL_QSPI_DFS_BIT_19
  *         @arg @ref DDL_QSPI_DFS_BIT_20
  *         @arg @ref DDL_QSPI_DFS_BIT_21
  *         @arg @ref DDL_QSPI_DFS_BIT_22
  *         @arg @ref DDL_QSPI_DFS_BIT_23
  *         @arg @ref DDL_QSPI_DFS_BIT_24
  *         @arg @ref DDL_QSPI_DFS_BIT_25
  *         @arg @ref DDL_QSPI_DFS_BIT_26
  *         @arg @ref DDL_QSPI_DFS_BIT_27
  *         @arg @ref DDL_QSPI_DFS_BIT_28
  *         @arg @ref DDL_QSPI_DFS_BIT_29
  *         @arg @ref DDL_QSPI_DFS_BIT_30
  *         @arg @ref DDL_QSPI_DFS_BIT_31
  *         @arg @ref DDL_QSPI_DFS_BIT_32
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetDataFrameSize(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL1, QSPI_CTRL1_DFS));
}

/**
  * @brief  Set Transmission Mode
  * @param  QSPIx QSPI Instance
  * @param  txmode This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_TXMODE_TX_AND_RX
  *         @arg @ref DDL_QSPI_TXMODE_TX_ONLY
  *         @arg @ref DDL_QSPI_TXMODE_RX_ONLY
  *         @arg @ref DDL_QSPI_TXMODE_EEPROM_READ
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetTansMode(QSPI_TypeDef *QSPIx, uint32_t txmode)
{
    MODIFY_REG(QSPIx->CTRL1, QSPI_CTRL1_TXMODE, txmode);
}

/**
  * @brief  Get Transmission Mode
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_TXMODE_TX_AND_RX
  *         @arg @ref DDL_QSPI_TXMODE_TX_ONLY
  *         @arg @ref DDL_QSPI_TXMODE_RX_ONLY
  *         @arg @ref DDL_QSPI_TXMODE_EEPROM_READ
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetTansMode(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL1, QSPI_CTRL1_TXMODE));
}

/**
  * @brief  Enable Chip Select Toggle
  * @param  QSPIx QSPI Instance
  * @param  csToggle This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_CS_TOGGLE_DISABLE
  *         @arg @ref DDL_QSPI_CS_TOGGLE_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetChipSelectToggle(QSPI_TypeDef *QSPIx, uint32_t csToggle)
{
    MODIFY_REG(QSPIx->CTRL1, QSPI_CTRL1_SSTEN, csToggle);
}

/**
  * @brief  Disable Chip Select Toggle
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_CS_TOGGLE_DISABLE
  *         @arg @ref DDL_QSPI_CS_TOGGLE_ENABLE
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetChipSelectToggle(QSPI_TypeDef *QSPIx)
{
    return READ_BIT(QSPIx->CTRL1, QSPI_CTRL1_SSTEN);
}

/**
  * @brief  Check if Chip Select Toggle is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledChipSelectToggle(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->CTRL1, QSPI_CTRL1_SSTEN) == QSPI_CTRL1_SSTEN) ? 1UL : 0UL);
}

/**
  * @brief  Set Frame Format (FRF)
  * @param  QSPIx QSPI Instance
  * @param  frameFormat This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_FRAME_FORMAT_STANDARD
  *         @arg @ref DDL_QSPI_FRAME_FORMAT_DUAL
  *         @arg @ref DDL_QSPI_FRAME_FORMAT_QUAD
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetFrameFormat(QSPI_TypeDef *QSPIx, uint32_t frameFormat)
{
    MODIFY_REG(QSPIx->CTRL1, QSPI_CTRL1_FRF, frameFormat);
}

/**
  * @brief  Get Frame Format (FRF)
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_FRAME_FORMAT_STANDARD
  *         @arg @ref DDL_QSPI_FRAME_FORMAT_DUAL
  *         @arg @ref DDL_QSPI_FRAME_FORMAT_QUAD
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetFrameFormat(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL1, QSPI_CTRL1_FRF));
}


/**
  * @brief  Set Number of Data Frames
  * @param  QSPIx QSPI Instance
  * @param  franeNum Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetFrameNum(QSPI_TypeDef *QSPIx, uint32_t franeNum)
{
    MODIFY_REG(QSPIx->CTRL2, QSPI_CTRL2_NDF, franeNum << QSPI_CTRL2_NDF_Pos);
}

/**
  * @brief  Get Number of Data Frames
  * @param  QSPIx QSPI Instance
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetFrameNum(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->CTRL2, QSPI_CTRL2_NDF)) >> QSPI_CTRL2_NDF_Pos);
}


/**
  * @brief  Enable QSPI
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_Enable(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->SSIEN, QSPI_SSIEN_EN);
}

/**
  * @brief  Disable QSPI
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_Disable(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->SSIEN, QSPI_SSIEN_EN);
}

/**
  * @brief  Check if QSPI is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabled(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->SSIEN, QSPI_SSIEN_EN) == QSPI_SSIEN_EN) ? 1UL : 0UL);
}


/**
  * @brief  Enable QSPI Slave
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_EnableSlave(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->SLAEN, QSPI_SLAEN_SLAEN);
}

/**
  * @brief  Disable QSPI Slave
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_DisableSlave(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->SLAEN, QSPI_SLAEN_SLAEN);
}

/**
  * @brief  Check if QSPI Slave is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledSlave(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->SLAEN, QSPI_SLAEN_SLAEN) == QSPI_SLAEN_SLAEN) ? 1UL : 0UL);
}


/**
  * @brief  Set Baudrate Divider
  * @param  QSPIx QSPI Instance
  * @param  clkDiv Divider value can be any even number between 2 and 65534.
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetBaudRateDiv(QSPI_TypeDef *QSPIx, uint32_t clkDiv)
{
    MODIFY_REG(QSPIx->BR, QSPI_BR_CLKDIV, clkDiv << QSPI_BR_CLKDIV_Pos);
}

/**
  * @brief  Get Baudrate Divider
  * @param  QSPIx QSPI Instance
  * @retval Divider value can be any even number between 2 and 65534.
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetBaudRateDiv(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->BR, QSPI_BR_CLKDIV) >> QSPI_BR_CLKDIV_Pos);
}


/**
  * @brief  Set TX FIFO Threshold
            When the number of entries in the transmit FIFO is less than or equal to this value,
            a transmit FIFO empty interrupt will be triggered.
  * @param  QSPIx QSPI Instance
  * @param  threshold Threshold value  (0~7)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetTxFifoThreshold(QSPI_TypeDef *QSPIx, uint32_t threshold)
{
    MODIFY_REG(QSPIx->TFTL, QSPI_TFTL_TFT, (threshold) << QSPI_TFTL_TFT_Pos);
}

/**
  * @brief  Get TX FIFO Threshold.
  * @param  QSPIx QSPI Instance
  * @retval Threshold value (0~7)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetTxFifoThreshold(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->TFTL, QSPI_TFTL_TFT) >> QSPI_TFTL_TFT_Pos);
}

/**
  * @brief  Set TX FIFO Level
            When the number of entries in the transmit FIFO is higher than this value,
            a transmit start will be triggered.
  * @param  QSPIx QSPI Instance
  * @param  level Threshold value (0~7)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetTxFifoLevel(QSPI_TypeDef *QSPIx, uint32_t level)
{
    MODIFY_REG(QSPIx->TFTL, QSPI_TFTL_TFTH, (level) << QSPI_TFTL_TFTH_Pos);
}

/**
  * @brief  Get TX FIFO Level
  * @param  QSPIx QSPI Instance
  * @retval Threshold value (0~7)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetTxFifoLevel(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->TFTL, QSPI_TFTL_TFTH) >> QSPI_TFTL_TFTH_Pos);
}


/**
  * @brief  Set RX FIFO Threshold
  * @param  QSPIx QSPI Instance
  * @param  rft Threshold value (0~7)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetRxFifoThreshold(QSPI_TypeDef *QSPIx, uint32_t rft)
{
    MODIFY_REG(QSPIx->RFTL, QSPI_RFTL_RFT, (rft) << QSPI_RFTL_RFT_Pos);
}

/**
  * @brief  Get RX FIFO Threshold
  * @param  QSPIx QSPI Instance
  * @retval Threshold value (0~7)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRxFifoThreshold(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->RFTL, QSPI_RFTL_RFT) >> QSPI_RFTL_RFT_Pos);
}

/**
  * @brief  Get TX FIFO Level Counts
  * @param  QSPIx QSPI Instance
  * @retval FIFO level (0~15)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetTxFifoLevelCounts(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->TFL, QSPI_TFL_TFL));
}


/**
  * @brief  Get RX FIFO Level Counts
  * @param  QSPIx QSPI Instance
  * @retval FIFO level (0~15)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRxFifoLevelCounts(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->RFL, QSPI_RFL_RFL));
}

/**
  * @brief  Check if BUSYF flag is set
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveFlag_Busy(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->STS, QSPI_STS_BUSYF) == QSPI_STS_BUSYF) ? 1UL : 0UL);
}

/**
  * @brief  Check if Transmit FIFO Not Full flag is set
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveFlag_TFNF(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->STS, QSPI_STS_TFNF) == QSPI_STS_TFNF) ? 1UL : 0UL);
}

/**
  * @brief  Check if Transmit FIFO Empty Full flag is set
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveFlag_TFE(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->STS, QSPI_STS_TFEF) == QSPI_STS_TFEF) ? 1UL : 0UL);
}

/**
  * @brief  Check if Receive FIFO Not Empty flag is set
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveFlag_RFNE(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->STS, QSPI_STS_RFNEF) == QSPI_STS_RFNEF) ? 1UL : 0UL);
}

/**
  * @brief  Check if Receive FIFO Full flag is set
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveFlag_RFF(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->STS, QSPI_STS_RFFF) == QSPI_STS_RFFF) ? 1UL : 0UL);
}

/**
  * @brief  Enable Transmit FIFO Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_EnableIT_TF(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->INTEN, QSPI_INTEN_TFEIE);
}

/**
  * @brief  Disable Transmit FIFO Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_DisableIT_TF(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->INTEN, QSPI_INTEN_TFEIE);
}

/**
  * @brief  Check if Transmit FIFO Interrupt is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledIT_TF(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->INTEN, QSPI_INTEN_TFEIE) == QSPI_INTEN_TFEIE) ? 1UL : 0UL);
}

/**
  * @brief  Enable Transmit FIFO Overflow Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_EnableIT_TFO(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->INTEN, QSPI_INTEN_TFOIE);
}

/**
  * @brief  Disable Transmit FIFO Overflow Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_DisableIT_TFO(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->INTEN, QSPI_INTEN_TFOIE);
}

/**
  * @brief  Check if Transmit FIFO Overflow Interrupt is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledIT_TFO(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->INTEN, QSPI_INTEN_TFOIE) == QSPI_INTEN_TFOIE) ? 1UL : 0UL);
}

/**
  * @brief  Enable Receive FIFO Underflow Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_EnableIT_RFU(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->INTEN, QSPI_INTEN_RFUIE);
}

/**
  * @brief  Disable Receive FIFO Underflow Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_DisableIT_RFU(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->INTEN, QSPI_INTEN_RFUIE);
}

/**
  * @brief  Check if Receive FIFO Underflow Interrupt is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledIT_RFU(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->INTEN, QSPI_INTEN_RFUIE) == QSPI_INTEN_RFUIE) ? 1UL : 0UL);
}

/**
  * @brief  Enable Receive FIFO Overflow Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_EnableIT_RFO(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->INTEN, QSPI_INTEN_RFOIE);
}

/**
  * @brief  Disable Receive FIFO Overflow Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_DisableIT_RFO(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->INTEN, QSPI_INTEN_RFOIE);
}

/**
  * @brief  Check if Receive FIFO Overflow Interrupt is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledIT_RFO(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->INTEN, QSPI_INTEN_RFOIE) == QSPI_INTEN_RFOIE) ? 1UL : 0UL);
}

/**
  * @brief  Enable Receive FIFO Full Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_EnableIT_RFF(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->INTEN, QSPI_INTEN_RFFIE);
}

/**
  * @brief  Disable Receive FIFO Full Interrupt
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_DisableIT_RFF(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->INTEN, QSPI_INTEN_RFFIE);
}

/**
  * @brief  Check if Receive FIFO Full Interrupt is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledIT_RFF(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->INTEN, QSPI_INTEN_RFFIE) == QSPI_INTEN_RFFIE) ? 1UL : 0UL);
}

/**
  * @brief  Get Transmit FIFO Empty interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveITFlag_TFE(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->ISTS, QSPI_ISTS_TFEIF) == QSPI_ISTS_TFEIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Transmit FIFO Overflow interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveITFlag_TFO(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->ISTS, QSPI_ISTS_TFOIF) == QSPI_ISTS_TFOIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Receive FIFO Underflow interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveITFlag_RFU(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->ISTS, QSPI_ISTS_RFUIF) == QSPI_ISTS_RFUIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Receive FIFO Overflow interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveITFlag_RFO(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->ISTS, QSPI_ISTS_RFOIF) == QSPI_ISTS_RFOIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Receive FIFO Full interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsActiveITFlag_RFF(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->ISTS, QSPI_ISTS_RFFIF) == QSPI_ISTS_RFFIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Transmit FIFO Empty raw interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRawITStatus_TFE(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->RIS, QSPI_RIS_TFEIF) == QSPI_RIS_TFEIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Transmit FIFO Overflow raw interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRawITStatus_TFO(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->RIS, QSPI_RIS_TFOIF) == QSPI_RIS_TFOIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Receive FIFO Underflow raw interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRawITStatus_RFU(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->RIS, QSPI_RIS_RFUIF) == QSPI_RIS_RFUIF) ? 1UL : 0UL);
}

/**
  * @brief  Get Receive FIFO Overflow raw interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRawITStatus_RFO(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->RIS, QSPI_RIS_RXOIR) == QSPI_RIS_RXOIR) ? 1UL : 0UL);
}

/**
  * @brief  Get Receive FIFO Full raw interrupt status
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRawITStatus_RFF(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->RIS, QSPI_RIS_RXFIR) == QSPI_RIS_RXFIR) ? 1UL : 0UL);
}

/**
  * @brief  Clear Transmit FIFO Overflow interrupt
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_ClearFlag_TFO(QSPI_TypeDef *QSPIx)
{
    uint32_t tmpreg;
    tmpreg = READ_BIT(QSPIx->TFOIC, QSPI_TFOIC_TFOIC);
    (void)(tmpreg);
}

/**
  * @brief  Clear  Receive FIFO Overflow interrupt
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_ClearFlag_RFO(QSPI_TypeDef *QSPIx)
{
    uint32_t tmpreg;
    tmpreg = READ_BIT(QSPIx->RFOIC, QSPI_RFOIC_RFOIC);
    (void)(tmpreg);
}

/**
  * @brief  Clear Receive FIFO Underflow interrupt
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_ClearFlag_RFU(QSPI_TypeDef *QSPIx)
{
    uint32_t tmpreg;
    tmpreg = READ_BIT(QSPIx->RFUIC, QSPI_RFUIC_RFUIC);
    (void)(tmpreg);
}

/**
  * @brief  Clear interrupt flag
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_ClearFlag_ICF(QSPI_TypeDef *QSPIx)
{
    uint32_t tmpreg;
    tmpreg = READ_BIT(QSPIx->ICF, QSPI_ICF_ICF);
    (void)(tmpreg);
}

/**
  * @brief  Enable RX DMA
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_EnableRxDMA(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->DMACTRL, QSPI_DMACTRL_RDMAEN);
}

/**
  * @brief  Disable RX DMA
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_DisableRxDMA(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->DMACTRL, QSPI_DMACTRL_RDMAEN);
}

/**
  * @brief  Enable TX DMA
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_EnableTxDMA(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->DMACTRL, QSPI_DMACTRL_TDMAEN);
}

/**
  * @brief  Disable TX DMA
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_DisableTxDMA(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->DMACTRL, QSPI_DMACTRL_TDMAEN);
}


/**
  * @brief  Set DMA TX Data Level
  * @param  QSPIx QSPI Instance
  * @param  level Level value (0~7)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetTxFifoDMALevel(QSPI_TypeDef *QSPIx, uint32_t level)
{
    MODIFY_REG(QSPIx->DMATDL, QSPI_DMATDL_DMATDL, level << QSPI_DMATDL_DMATDL_Pos);
}

/**
  * @brief  Get DMA TX Data Level
  * @param  QSPIx QSPI Instance
  * @retval Level value (0~7)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetTxFifoDMALevel(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->DMATDL, QSPI_DMATDL_DMATDL) >> QSPI_DMATDL_DMATDL_Pos);
}


/**
  * @brief  Set DMA RX Data Level
  * @param  QSPIx QSPI Instance
  * @param  level Level value (0~7)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetRxFifoDMALevel(QSPI_TypeDef *QSPIx, uint32_t level)
{
    MODIFY_REG(QSPIx->DMARDL, QSPI_DMARDL_DMARDL, level << QSPI_DMARDL_DMARDL_Pos);
}

/**
  * @brief  Get DMA RX Data Level
  * @param  QSPIx QSPI Instance
  * @retval Level value (0~7)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRxFifoDMALevel(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->DMARDL, QSPI_DMARDL_DMARDL) >> QSPI_DMARDL_DMARDL_Pos);
}


/**
  * @brief  Write Data
  * @param  QSPIx QSPI Instance
  * @param  data Data value (32-bit)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_WriteData(QSPI_TypeDef *QSPIx, uint32_t data)
{
    WRITE_REG(QSPIx->DATA, data);
}

/**
  * @brief  Read Data
  * @param  QSPIx QSPI Instance
  * @retval Data value (32-bit)
  */
__STATIC_INLINE uint32_t DDL_QSPI_ReadData(QSPI_TypeDef *QSPIx)
{
    return READ_REG(QSPIx->DATA);
}

/**
  * @brief  Set Receive Data (RXD) Sampling Delay
  * @param  QSPIx QSPI Instance
  * @param  delay Delay value (0~255)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetRXDSampleDelay(QSPI_TypeDef *QSPIx, uint32_t delay)
{
    MODIFY_REG(QSPIx->RSD, QSPI_RSD_RSD, delay << QSPI_RSD_RSD_Pos);
}

/**
  * @brief  Get Receive Data (RXD) Sampling Delay
  * @param  QSPIx QSPI Instance
  * @retval Delay value (0~255)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRXDSampleDelay(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->RSD, QSPI_RSD_RSD) >> QSPI_RSD_RSD_Pos);
}

/**
  * @brief  Set Receive Data (RXD) Sampling Edge with Rising
  * @param  QSPIx QSPI Instance
  * @param  edge This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_RSE_RISING
  *         @arg @ref DDL_QSPI_RSE_FALLING
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetRXDSampleEdge(QSPI_TypeDef *QSPIx, uint32_t edge)
{
    MODIFY_REG(QSPIx->RSD, QSPI_RSD_RSE, edge);
}

/**
  * @brief  Get Receive Data (RXD) Sample Edge
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_RSE_RISING
  *         @arg @ref DDL_QSPI_RSE_FALLING
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetRXDSampleEdge(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->RSD, QSPI_RSD_RSE));
}

/**
  * @brief  Set IAT (Instruction Address Transfer Mode)
  * @param  QSPIx QSPI Instance
  * @param  iat This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_IAT_STANDARD_INST_ADDR
  *         @arg @ref DDL_QSPI_IAT_STANDARD_INST
  *         @arg @ref DDL_QSPI_IAT_FRF_INST_ADDR
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetInstAddrType(QSPI_TypeDef *QSPIx, uint32_t iat)
{
    MODIFY_REG(QSPIx->CTRL3, QSPI_CTRL3_IAT, iat);
}

/**
  * @brief  Get IAT (Instruction Address Transfer Mode)
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_IAT_STANDARD_INST_ADDR
  *         @arg @ref DDL_QSPI_IAT_STANDARD_INST
  *         @arg @ref DDL_QSPI_IAT_FRF_INST_ADDR
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetInstAddrType(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL3, QSPI_CTRL3_IAT));
}

/**
  * @brief  Set Transmitted Address Length
  * @param  QSPIx QSPI Instance
  * @param  addrlen This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_ADDR_LEN_0
  *         @arg @ref DDL_QSPI_ADDR_LEN_4BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_8BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_12BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_16BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_20BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_24BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_28BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_32BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_36BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_40BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_44BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_48BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_52BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_56BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_60BIT
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetAddrLen(QSPI_TypeDef *QSPIx, uint32_t addrlen)
{
    MODIFY_REG(QSPIx->CTRL3, QSPI_CTRL3_ADDRLEN, addrlen);
}

/**
  * @brief  Get Transmitted Address Length
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_ADDR_LEN_0
  *         @arg @ref DDL_QSPI_ADDR_LEN_4BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_8BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_12BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_16BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_20BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_24BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_28BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_32BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_36BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_40BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_44BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_48BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_52BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_56BIT
  *         @arg @ref DDL_QSPI_ADDR_LEN_60BIT
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetAddrLen(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL3, QSPI_CTRL3_ADDRLEN));
}

/**
  * @brief  Set Instruction Length in Four-wire Mode
  * @param  QSPIx QSPI Instance
  * @param  inslen This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_INST_LEN_0
  *         @arg @ref DDL_QSPI_INST_LEN_4BIT
  *         @arg @ref DDL_QSPI_INST_LEN_8BIT
  *         @arg @ref DDL_QSPI_INST_LEN_16BIT
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetInstLen(QSPI_TypeDef *QSPIx, uint32_t inslen)
{
    MODIFY_REG(QSPIx->CTRL3, QSPI_CTRL3_INSLEN, inslen);
}

/**
  * @brief  Get Instruction Length in Four-wire Mode
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_INST_LEN_0
  *         @arg @ref DDL_QSPI_INST_LEN_4BIT
  *         @arg @ref DDL_QSPI_INST_LEN_8BIT
  *         @arg @ref DDL_QSPI_INST_LEN_16BIT
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetInstLen(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL3, QSPI_CTRL3_INSLEN));
}

/**
  * @brief  Set Wait Cycle Number
  * @param  QSPIx QSPI Instance
  * @param  waitcyc Wait cycle value (0~31)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_SetWaitCycle(QSPI_TypeDef *QSPIx, uint32_t waitcyc)
{
    MODIFY_REG(QSPIx->CTRL3, QSPI_CTRL3_WAITCYC, waitcyc << QSPI_CTRL3_WAITCYC_Pos);
}

/**
  * @brief  Get Wait Cycle Number
  * @param  QSPIx QSPI Instance
  * @retval Wait cycle value (0~31)
  */
__STATIC_INLINE uint32_t DDL_QSPI_GetWaitCycle(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->CTRL3, QSPI_CTRL3_WAITCYC) >> QSPI_CTRL3_WAITCYC_Pos);
}

/**
  * @brief  Enable Clock Stretch
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_EnableClockStretch(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->CTRL3, QSPI_CTRL3_CSEN);
}

/**
  * @brief  Disable Clock Stretch
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_DisableClockStretch(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->CTRL3, QSPI_CTRL3_CSEN);
}

/**
  * @brief  Check if Clock Stretch is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_IsEnabledClockStretch(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->CTRL3, QSPI_CTRL3_CSEN) == QSPI_CTRL3_CSEN) ? 1UL : 0UL);
}

/**
  * @brief  Set QSPI external memory access format
  * @param  format This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_MEM_ACCESS_BIG_ENDIAN
  *         @arg @ref DDL_QSPI_XIP_MEM_ACCESS_LITTLE_ENDIAN
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetExtMemAccessFormat(QSPI_TypeDef *QSPIx, uint32_t format)
{
    MODIFY_REG(QSPIx->SWITCH, QSPI_SWITCH_LITTLE_ENDIAN, format);
}

/**
  * @brief  Disable Little Endian
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_MEM_ACCESS_BIG_ENDIAN
  *         @arg @ref DDL_QSPI_XIP_MEM_ACCESS_LITTLE_ENDIAN
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetExtMemAccessFormat(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->SWITCH, QSPI_SWITCH_LITTLE_ENDIAN));
}

#if defined (QSPI2)

/**
  * @brief  Enable XIP Transmit Data Frame Size.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_EnableDataFrameSize(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_DFS_HC);
}

/**
  * @brief  Disable XIP Transmit Data Frame Size.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_DisableDataFrameSize(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_DFS_HC);
}

/**
  * @brief  Check if XIP Transmit Data Frame Size is Enabled.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_IsEnabledDataFrameSize(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_DFS_HC) == QSPI_XIP_CTRL_DFS_HC) ? 1UL : 0UL);
}

/**
  * @brief  Enable XIP Transmit Instruction.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_EnableInstruction(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_INST_EN);
}

/**
  * @brief  Disable XIP Transmit Instruction.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_DisableInstruction(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_INST_EN);
}

/**
  * @brief  Check if XIP Transmit Instruction is Enabled.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_IsEnabledInstruction(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_INST_EN) == QSPI_XIP_CTRL_INST_EN) ? 1UL : 0UL);
}

/**
  * @brief  Enable XIP Transmit Continuous.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_EnableContinuous(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_CONT_XFER_EN);
}

/**
  * @brief  Disable XIP Transmit Continuous.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_DisableContinuous(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_CONT_XFER_EN);
}

/**
  * @brief  Check if XIP Transmit Continuous is Enabled.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_IsEnabledContinuous(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_CONT_XFER_EN) == QSPI_XIP_CTRL_CONT_XFER_EN) ? 1UL : 0UL);
}

/**
  * @brief  Enable XIP Transmit Prefetch.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_EnablePrefetch(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_XIP_PREFETCH_EN);
}

/**
  * @brief  Disable XIP Transmit Prefetch.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE void DDL_QSPI_XIP_DisablePrefetch(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_XIP_PREFETCH_EN);
}

/**
  * @brief  Check if XIP Transmit Prefetch is valid.
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_IsEnabledPrefetch (QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_XIP_PREFETCH_EN) == QSPI_XIP_CTRL_XIP_PREFETCH_EN) ? 1UL : 0UL);
}

/**
  * @brief  Set Instruction Operation Code for INCR type transfer request in XIP
  * @param  incr Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetOpcodeForINCR(QSPI_TypeDef *QSPIx, uint32_t incr)
{
    MODIFY_REG(QSPIx->XIP_INCR_INST, QSPI_XIP_INCR_INST_INCR_INST, incr << QSPI_XIP_INCR_INST_INCR_INST_Pos);
}

/**
  * @brief  Get Instruction Operation Code for INCR type transfer request in XIP
  * @param  QSPIx QSPI Instance
  * @retval Instruction Operation Code Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetOpcodeForINCR(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_INCR_INST, QSPI_XIP_INCR_INST_INCR_INST)) >> QSPI_XIP_INCR_INST_INCR_INST_Pos;
}

/**
  * @brief  Set Instruction Operation Code for WRAP type transfer request in XIP
  * @param  wrap Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetOpcodeForWRAP(QSPI_TypeDef *QSPIx, uint32_t wrap)
{
    MODIFY_REG(QSPIx->XIP_WRAP_INST, QSPI_XIP_WRAP_INST_WRAP_INST, wrap << QSPI_XIP_WRAP_INST_WRAP_INST_Pos);
}

/**
  * @brief  Get Instruction Operation Code for WRAP type transfer request in XIP
  * @param  QSPIx QSPI Instance
  * @retval Instruction Operation Code Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetOpcodeForWRAP(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_WRAP_INST, QSPI_XIP_WRAP_INST_WRAP_INST)) >> QSPI_XIP_WRAP_INST_WRAP_INST_Pos;
}


/**
  * @brief  Set XIP Frame Format (FRF)
  * @param  QSPIx QSPI Instance
  * @param  frameFormat This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_FRAME_FORMAT_DUAL
  *         @arg @ref DDL_QSPI_XIP_FRAME_FORMAT_QUAD
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetFrameFormat(QSPI_TypeDef *QSPIx, uint32_t frameFormat)
{
    MODIFY_REG(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_FRF, frameFormat);
}

/**
  * @brief  Get XIP Frame Format (FRF)
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_FRAME_FORMAT_DUAL
  *         @arg @ref DDL_QSPI_XIP_FRAME_FORMAT_QUAD
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetFrameFormat(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_FRF));
}

/**
  * @brief  Set XIP IAT (Instruction Address Transfer Mode)
  * @param  QSPIx QSPI Instance
  * @param  iat This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_IAT_STANDARD_INST_ADDR
  *         @arg @ref DDL_QSPI_XIP_IAT_STANDARD_INST
  *         @arg @ref DDL_QSPI_XIP_IAT_FRF_INST_ADDR
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetInstAddrType(QSPI_TypeDef *QSPIx, uint32_t iat)
{
    MODIFY_REG(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_TRANS_TYPE, iat);
}

/**
  * @brief  Get XIP IAT (Instruction Address Transfer Mode)
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_IAT_STANDARD_INST_ADDR
  *         @arg @ref DDL_QSPI_XIP_IAT_STANDARD_INST
  *         @arg @ref DDL_QSPI_XIP_IAT_FRF_INST_ADDR
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetInstAddrType(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_TRANS_TYPE));
}


/**
  * @brief  Set XIP Transmitted Address Length
  * @param  QSPIx QSPI Instance
  * @param  addrlen This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_0
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_4BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_8BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_12BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_16BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_20BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_24BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_28BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_32BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_36BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_40BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_44BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_48BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_52BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_56BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_60BIT
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetAddrLen(QSPI_TypeDef *QSPIx, uint32_t addrlen)
{
    MODIFY_REG(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_ADDR_L, addrlen);
}

/**
  * @brief  Get XIP Transmitted Address Length
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_0
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_4BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_8BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_12BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_16BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_20BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_24BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_28BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_32BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_36BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_40BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_44BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_48BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_52BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_56BIT
  *         @arg @ref DDL_QSPI_XIP_ADDR_LEN_60BIT
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetAddrLen(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_ADDR_L));
}


/**
  * @brief  Set XIP Instruction Length in Four-wire Mode
  * @param  QSPIx QSPI Instance
  * @param  inslen This parameter can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_0
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_4BIT
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_8BIT
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_16BIT
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetInstLen(QSPI_TypeDef *QSPIx, uint32_t inslen)
{
    MODIFY_REG(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_INST_L, inslen);
}

/**
  * @brief  Get XIP Instruction Length in Four-wire Mode
  * @param  QSPIx QSPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_0
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_4BIT
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_8BIT
  *         @arg @ref DDL_QSPI_XIP_INST_LEN_16BIT
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetInstLen(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_INST_L));
}


/**
  * @brief  Set XIP Wait Cycle Number
  * @param  QSPIx QSPI Instance
  * @param  waitcyc Wait cycle value (0~31)
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_SetWaitCycle(QSPI_TypeDef *QSPIx, uint32_t waitcyc)
{
    MODIFY_REG(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_WAIT_CYCLES, waitcyc << QSPI_XIP_CTRL_WAIT_CYCLES_Pos);
}

/**
  * @brief  Get XIP Wait Cycle Number
  * @param  QSPIx QSPI Instance
  * @retval Wait cycle value (0~31)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_GetWaitCycle(QSPI_TypeDef *QSPIx)
{
    return (READ_BIT(QSPIx->XIP_CTRL, QSPI_XIP_CTRL_WAIT_CYCLES) >> QSPI_XIP_CTRL_WAIT_CYCLES_Pos);
}

/**
  * @brief  Enable XIP QSPI Slave
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_EnableSlave(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->XIP_SER, QSPI_XIP_SER_SER);
}

/**
  * @brief  Disable XIP QSPI Slave
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_DisableSlave(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->XIP_SER, QSPI_XIP_SER_SER);
}

/**
  * @brief  Check if XIP QSPI Slave is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_IsEnabledSlave(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->XIP_SER, QSPI_XIP_SER_SER) == QSPI_XIP_SER_SER) ? 1UL : 0UL);
}

/**
  * @brief  Enable XIP
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_Enable(QSPI_TypeDef *QSPIx)
{
    SET_BIT(QSPIx->XIP_EN, QSPI_XIP_EN_XIP_EN);
}

/**
  * @brief  Disable XIP
  * @param  QSPIx QSPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_QSPI_XIP_Disable(QSPI_TypeDef *QSPIx)
{
    CLEAR_BIT(QSPIx->XIP_EN, QSPI_XIP_EN_XIP_EN);
}

/**
  * @brief  Check if XIP is enabled
  * @param  QSPIx QSPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_QSPI_XIP_IsEnabled(QSPI_TypeDef *QSPIx)
{
    return ((READ_BIT(QSPIx->XIP_EN, QSPI_XIP_EN_XIP_EN) == QSPI_XIP_EN_XIP_EN) ? 1UL : 0UL);
}

#endif

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FDCAN_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus DDL_QSPI_Init(QSPI_TypeDef *QSPIx, DDL_QSPI_InitTypeDef *QSPI_InitStruct);
ErrorStatus DDL_QSPI_DeInit(QSPI_TypeDef *QSPIx);
ErrorStatus DDL_QSPI_Command(QSPI_TypeDef *QSPIx, DDL_QSPI_CommandTypeDef *cmd);
ErrorStatus DDL_QSPI_TransmitReceive(QSPI_TypeDef *QSPIx,
                                     uint8_t *pTxdata,
                                     uint8_t *pRxdata,
                                     uint32_t size);
ErrorStatus DDL_QSPI_Transmit(QSPI_TypeDef *QSPIx, uint8_t *pTxData);
ErrorStatus DDL_QSPI_Receive(QSPI_TypeDef *QSPIx, uint8_t *pRxData);
/**
  * @}
  */

/** @defgroup QSPI_DDL_EF_XIP XIP Management
  * @{
  */
ErrorStatus DDL_QSPI_MemoryMapped(QSPI_TypeDef *QSPIx, DDL_QSPI_XIPTypeDef *xipConfig);
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
  * @}
  */
#endif /* defined (QSPI1) || defined (QSPI2) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_QSPI_H */
