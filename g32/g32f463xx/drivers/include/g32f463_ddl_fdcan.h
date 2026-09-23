/**
  *
  * @file    g32f463_ddl_fdcan.h
  * @brief   Header file of FDCAN DDL module.
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
  * Copyright (c) 2017 STMicroelectronics. Copyright (C) 2025 Geehy Semiconductor.
  * All rights reserved.
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32F463_DDL_FDCAN_H
#define G32F463_DDL_FDCAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (FDCAN)

/** @defgroup FDCAN_DDL FDCAN
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup FDCAN_DDL_Private_Variables FDCAN Private Variables
  * @{
  */
static const uint8_t OFFSET_TAB_RXFIFOx[] =
{
  0x00U,   /* 0: RXFIFO0  */
  0x10U,   /* 1: RXFIFO0 */
};

/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FDCAN_DDL_Private_Macros FDCAN Private Macros
  * @{
  */
/**
  * @brief  Get FDCAN Instance message sram address base.
  * @param  FDCAN Instance
  * @retval SRAM_ADDRESS in register 32 bits
  */
#if defined(FDCAN)
#define __DDL_FDCAN_GET_SRAM_ADDRESS(__FDCANx__)   ((uint32_t)(FDCAN_RAM_BASE))
#endif
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FDCAN_DDL_ES_INIT FDCAN Exported Init structures
  * @{
  */

/**
  * @brief DDL FDCAN Init Structure definition
  */
typedef struct
{
  uint32_t FrameFormat;                  /*!< Specifies the FDCAN frame format.
                                              This parameter can be any value of @ref FDCAN_DDL_EC_FRAME_FORMAT

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetFrameFormat().*/

  uint32_t Mode;                         /*!< Specifies the FDCAN mode.
                                              This parameter can be a value of @ref FDCAN_DDL_EC_OPERATION_MODE.

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetOperationMode().*/

  FunctionalState AutoRetransmission;    /*!< Enable or disable the automatic retransmission mode.
                                              This parameter can be set to ENABLE or DISABLE

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_EnableAutoRetransmission().*/

  FunctionalState TransmitPause;         /*!< Enable or disable the Transmit Pause feature.
                                              This parameter can be set to ENABLE or DISABLE

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_EnableTransmitPause().*/

  FunctionalState ProtocolException;      /*!< Enable or disable the Protocol Exception Handling.
                                              This parameter can be set to ENABLE or DISABLE

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_EnableProtocolException().*/

  uint32_t NominalPrescaler;             /*!< Specifies the value by which the oscillator frequency is divided for generating the nominal bit time quanta.
                                              This parameter must be a number between 1 and 512

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetNominalPrescaler().*/

  uint32_t NominalSyncJumpWidth;         /*!< Specifies the maximum number of time quanta the FDCAN hardware is allowed to lengthen or shorten a bit to perform resynchronization.
                                              This parameter must be a number between 1 and 128

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetNominalTimeSegment1().*/

  uint32_t NominalTimeSeg1;              /*!< Specifies the number of time quanta in Bit Segment 1.
                                              This parameter must be a number between 2 and 256

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetNominalTimeSegment2().*/

  uint32_t NominalTimeSeg2;              /*!< Specifies the number of time quanta in Bit Segment 2.
                                              This parameter must be a number between 2 and 128

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetNominalSyncJumpWidth().*/

  uint32_t DataPrescaler;                /*!< Specifies the value by which the oscillator frequency is divided for generating the data bit time quanta.
                                              This parameter must be a number between 1 and 32

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetDataPrescaler().*/

  uint32_t DataSyncJumpWidth;            /*!< Specifies the maximum number of time quanta the FDCAN hardware is allowed to lengthen or shorten a data bit to perform resynchronization.
                                              This parameter must be a number between 1 and 16

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetDataSyncJumpWidth().*/

  uint32_t DataTimeSeg1;                 /*!< Specifies the number of time quanta in Data Bit Segment 1.
                                              This parameter must be a number between 1 and 32

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetDataTimeSegment1().*/

  uint32_t DataTimeSeg2;                 /*!< Specifies the number of time quanta in Data Bit Segment 2.
                                              This parameter must be a number between 1 and 16

                                              This feature can be modified afterwards using unitary function @ref DDL_FDCAN_SetDataTimeSegment2().*/

  uint32_t MessageRAMOffset;             /*!< Specifies the message RAM start address.
                                              This parameter must be a number between 0 and 512 (unit: word)           */

  uint32_t StdFiltersNbr;                /*!< Specifies the number of standard Message ID filters.
                                              This parameter must be a number between 0 and 128            */

  uint32_t ExtFiltersNbr;                /*!< Specifies the number of extended Message ID filters.
                                              This parameter must be a number between 0 and 64             */

  uint32_t RxFifo0ElmtsNbr;              /*!< Specifies the number of Rx FIFO0 Elements.
                                              This parameter must be a number between 0 and 64             */

  uint32_t RxFifo0ElmtSize;              /*!< Specifies the Data Field Size in an Rx FIFO 0 element.
                                              This parameter can be a value of @ref FDCAN_DDL_EC_FILEDSIZE  */

  uint32_t RxFifo1ElmtsNbr;              /*!< Specifies the number of Rx FIFO 1 Elements.
                                              This parameter must be a number between 0 and 64             */

  uint32_t RxFifo1ElmtSize;              /*!< Specifies the Data Field Size in an Rx FIFO 1 element.
                                              This parameter can be a value of @ref FDCAN_DDL_EC_FILEDSIZE  */

  uint32_t RxBuffersNbr;                 /*!< Specifies the number of Dedicated Rx Buffer elements.
                                              This parameter must be a number between 0 and 64             */

  uint32_t RxBufferSize;                 /*!< Specifies the Data Field Size in an Rx Buffer element.
                                              This parameter can be a value of @ref FDCAN_DDL_EC_FILEDSIZE  */

  uint32_t TxEventsNbr;                  /*!< Specifies the number of Tx Event FIFO elements.
                                              This parameter must be a number between 0 and 32             */

  uint32_t TxBuffersNbr;                 /*!< Specifies the number of Dedicated Tx Buffers.
                                              This parameter must be a number between 0 and 32             */

  uint32_t TxFifoQueueElmtsNbr;          /*!< Specifies the number of Tx Buffers used for Tx FIFO/Queue.
                                              This parameter must be a number between 0 and 32             */

  uint32_t TxFifoQueueMode;              /*!< Tx FIFO/Queue Mode selection.
                                              This parameter can be a value of @ref FDCAN_DDL_EC_TX_MODE */

  uint32_t TxElmtSize;                   /*!< Specifies the Data Field Size in a Tx Element.
                                              This parameter can be a value of @ref FDCAN_DDL_EC_FILEDSIZE  */

} DDL_FDCAN_InitTypeDef;

/**
  * @brief DDL FDCAN Filter Structure definition
  */
typedef struct
{
  uint32_t IdType;           /*!< Specifies the identifier type.
                                  This parameter can be a value of @ref FDCAN_DDL_EC_ID_TYPE       */

  uint32_t FilterIndex;      /*!< Specifies the filter which will be initialized.
                                  This parameter must be a number between:
                                   - 0 and 127, if IdType is DDL_FDCAN_STANDARD_ID
                                   - 0 and 63,  if IdType is DDL_FDCAN_EXTENDED_ID */

  uint32_t FilterType;       /*!< Specifies the filter type.
                                  This parameter can be a value of @ref FDCAN_DDL_EC_FILTER_TYPE.  */

  uint32_t FilterConfig;     /*!< Specifies the filter configuration.
                                  This parameter can be a value of @ref FDCAN_DDL_EC_FILTER_CONFIG */

  uint32_t FilterID1;        /*!< Specifies the filter identification 1.
                                  This parameter must be a number between:
                                   - 0 and 0x7FF, if IdType is DDL_FDCAN_STANDARD_ID
                                   - 0 and 0x1FFFFFFF, if IdType is DDL_FDCAN_EXTENDED_ID       */

  uint32_t FilterID2;        /*!< Specifies the filter identification 2.
                                  This parameter must be a number between:
                                   - 0 and 0x7FF, if IdType is DDL_FDCAN_STANDARD_ID
                                   - 0 and 0x1FFFFFFF, if IdType is DDL_FDCAN_EXTENDED_ID       */

} DDL_FDCAN_FilterTypeDef;

/**
  * @brief DDL FDCAN Tx Message Structure definition
  */
typedef struct
{
  uint32_t IdType;                  /*!< Specifies the identifier type.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_ID_TYPE       */

  uint32_t Identifier;              /*!< Specifies the filter which will be initialized.
                                         This parameter must be a number between:
                                          - 0 and 0x7FF, if IdType is DDL_FDCAN_STANDARD_ID
                                          - 0 and 0x1FFFFFFF, if IdType is DDL_FDCAN_EXTENDED_ID       */

  uint32_t DataLength;              /*!< Specifies the data length.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_DATALENGTH_BYTES.  */

  uint32_t ErrorStateIndicator;     /*!< Specifies the Error State Indicator.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_ESI_TYPE */

  uint32_t FrameType;               /*!< Specifies the Tx Frame type.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_FRAME_TYPE */

  uint32_t EventFifoControl;        /*!< Specifies the Error State Indicator.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_EFC */

  uint32_t FDFrame;                 /*!< Specifies the FD Frame.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_FDFRAME */

  uint32_t BitRateSwitch;           /*!< Specifies the Bit Rate Switch is enable or disable.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_BITRATE_SWITCH */

  uint32_t MessageMarker;           /*!< Specifies the Message Marker to Copied into Tx Event FIFO element for identification of Tx message status.
                                         a number between: 0 and 0xFF */

  uint8_t *buffer;                  /*!< Specifies the Tx buffer address. */

} DDL_FDCAN_TxMessageTypeDef;

/**
  * @brief DDL FDCAN Rx Message Structure definition
  */
typedef struct
{
  uint32_t IdType;                  /*!< Specifies the identifier type.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_ID_TYPE       */

  uint32_t Identifier;              /*!< Specifies the filter which will be initialized.
                                         This parameter must be a number between:
                                          - 0 and 0x7FF, if IdType is DDL_FDCAN_STANDARD_ID
                                          - 0 and 0x1FFFFFFF, if IdType is DDL_FDCAN_EXTENDED_ID       */

  uint32_t DataLength;              /*!< Specifies the data length.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_DATALENGTH_BYTES.  */

  uint32_t ErrorStateIndicator;     /*!< Specifies the Error State Indicator.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_ESI_TYPE */

  uint32_t FrameType;               /*!< Specifies the Tx Frame type.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_FRAME_TYPE */

  uint32_t FilterIndex;             /*!< Specifies the filter which will be initialized.
                                         This parameter must be a number between:
                                          - 0 and 127, if IdType is DDL_FDCAN_STANDARD_ID
                                          - 0 and 63,  if IdType is DDL_FDCAN_EXTENDED_ID */

  uint32_t TimeStamp;               /*!< Specifies the time stamp.
                                         This parameter must be a number between 0 and 0xFFFF */

  uint32_t FDFrame;                 /*!< Specifies the FD Frame.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_FDFRAME */

  uint32_t BitRateSwitch;           /*!< Specifies the Bit Rate Switch is enable or disable.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_BITRATE_SWITCH */

  uint32_t FrameMatch;              /*!< Specifies the Message Marker to Copied into Tx Event FIFO element for identification of Tx message status.
                                         This parameter can be a value of @ref FDCAN_DDL_EC_FRAME_MATCH */

  uint8_t *buffer;                  /*!< Specifies the Tx buffer address. */

} DDL_FDCAN_RxMessageTypeDef;

/**
  * @brief  FDCAN Message RAM blocks
  */
typedef struct
{
  uint32_t StandardFilterSA; /*!< Specifies the Standard Filter List Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t ExtendedFilterSA; /*!< Specifies the Extended Filter List Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t RxFIFO0SA;        /*!< Specifies the Rx FIFO 0 Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t RxFIFO1SA;        /*!< Specifies the Rx FIFO 1 Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t RxBufferSA;       /*!< Specifies the Rx Buffer Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t TxEventFIFOSA;    /*!< Specifies the Tx Event FIFO Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t TxBufferSA;       /*!< Specifies the Tx Buffers Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t TxFIFOQSA;        /*!< Specifies the Tx FIFO/Queue Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t TTMemorySA;       /*!< Specifies the Trigger Memory Start Address.
                                  This parameter must be a 32-bit word address      */

  uint32_t EndAddress;       /*!< Specifies the End Address of the allocated RAM.
                                  This parameter must be a 32-bit word address      */

} DDL_FDCAN_MsgRamAddressTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup FDCAN_DDL_Exported_Constants FDCAN Exported Constants
  * @{
  */

/** @defgroup FDCAN_DDL_EC_BIT_MASK BIT MASK
  * @{
  */
#define DDL_FDCAN_BIT_MASK_BIT0         (0x00000001U)
#define DDL_FDCAN_BIT_MASK_BIT1         (0x00000002U)
#define DDL_FDCAN_BIT_MASK_BIT2         (0x00000004U)
#define DDL_FDCAN_BIT_MASK_BIT3         (0x00000008U)
#define DDL_FDCAN_BIT_MASK_BIT4         (0x00000010U)
#define DDL_FDCAN_BIT_MASK_BIT5         (0x00000020U)
#define DDL_FDCAN_BIT_MASK_BIT6         (0x00000040U)
#define DDL_FDCAN_BIT_MASK_BIT7         (0x00000080U)
#define DDL_FDCAN_BIT_MASK_BIT8         (0x00000100U)
#define DDL_FDCAN_BIT_MASK_BIT9         (0x00000200U)
#define DDL_FDCAN_BIT_MASK_BIT10        (0x00000400U)
#define DDL_FDCAN_BIT_MASK_BIT11        (0x00000800U)
#define DDL_FDCAN_BIT_MASK_BIT12        (0x00001000U)
#define DDL_FDCAN_BIT_MASK_BIT13        (0x00002000U)
#define DDL_FDCAN_BIT_MASK_BIT14        (0x00004000U)
#define DDL_FDCAN_BIT_MASK_BIT15        (0x00008000U)
#define DDL_FDCAN_BIT_MASK_BIT16        (0x00010000U)
#define DDL_FDCAN_BIT_MASK_BIT17        (0x00020000U)
#define DDL_FDCAN_BIT_MASK_BIT18        (0x00040000U)
#define DDL_FDCAN_BIT_MASK_BIT19        (0x00080000U)
#define DDL_FDCAN_BIT_MASK_BIT20        (0x00100000U)
#define DDL_FDCAN_BIT_MASK_BIT21        (0x00200000U)
#define DDL_FDCAN_BIT_MASK_BIT22        (0x00400000U)
#define DDL_FDCAN_BIT_MASK_BIT23        (0x00800000U)
#define DDL_FDCAN_BIT_MASK_BIT24        (0x01000000U)
#define DDL_FDCAN_BIT_MASK_BIT25        (0x02000000U)
#define DDL_FDCAN_BIT_MASK_BIT26        (0x04000000U)
#define DDL_FDCAN_BIT_MASK_BIT27        (0x08000000U)
#define DDL_FDCAN_BIT_MASK_BIT28        (0x10000000U)
#define DDL_FDCAN_BIT_MASK_BIT29        (0x20000000U)
#define DDL_FDCAN_BIT_MASK_BIT30        (0x40000000U)
#define DDL_FDCAN_BIT_MASK_BIT31        (0x80000000U)

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_ADDRESS_MASK ADDRESS MASK
  * @{
  */
#define DDL_FDCAN_ADDRESS_MASK         (0x0000FFFCU)
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FRAME_FORMAT FRAME FORMAT
  * @{
  */
#define DDL_FDCAN_FRAME_CLASSIC       (0x00000000U)                            /* Classic fromat */
#define DDL_FDCAN_FRAME_FD_NOBRS      FDCAN_CCCR_FDOE                          /* FD fromat with not bit rate switch */
#define DDL_FDCAN_FRAME_FD_BRS        (FDCAN_CCCR_FDOE | FDCAN_CCCR_BRSE)      /* FD fromat with bit rate switch */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_OPERATION_MODE OPERATION MODE
  * @{
  */
#define DDL_FDCAN_MODE_NORMAL                               (0x00000000U)     /* Normal mode */
#define DDL_FDCAN_MODE_BUS_MONITOR                          (0x00000001U)     /* Bus monitoring mode */
#define DDL_FDCAN_MODE_RESTRICTED                           (0x00000002U)     /* Restrictrd operation mode */
#define DDL_FDCAN_MODE_LOOPBACK_INTERNAL                    (0x00000003U)     /* Internal loop back mode */
#define DDL_FDCAN_MODE_LOOPBACK_EXTERNAL                    (0x00000004U)     /* External loop back mode */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_WIDE_MESSAGE_MODE WIDE MESSAGE MODE
  * @{
  */
#define DDL_FDCAN_WIDE_MESSAGE_8BIT          0x00000000U
#define DDL_FDCAN_WIDE_MESSAGE_16BIT         FDCAN_CCCR_WMM
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_SPEC SPECIFICATION
  * @{
  */
#define DDL_FDCAN_SPEC_ISO          (0x00000000U)          /* FD frame format according to ISO 11898-1:2015 */
#define DDL_FDCAN_SPEC_BOSCH        FDCAN_CCCR_NISO        /* FD frame format according to Bosch CAN FD Specification V1.0 */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_TIMESTAMP_SELECT TIMESTAMP SELECT
  * @{
  */
#define DDL_FDCAN_TIMESTAMP_NONE    (0x00000000U)         /* Timestamp counter value always 0x0000 */
#define DDL_FDCAN_TIMESTAMP_TCP     FDCAN_TSCC_TSS_0      /* Timestamp counter value incremented according to TCP */
#define DDL_FDCAN_TIMESTAMP_EXT     FDCAN_TSCC_TSS_1      /* External timestamp counter value used */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_TIMEOUT_MODE TIMEOUT MODE
  * @{
  */
#define DDL_FDCAN_TIMEOUTMODE_CINTINUE   (0x00000000U)                          /* Continuous operation */
#define DDL_FDCAN_TIMEOUTMODE_TXFIFO     FDCAN_TOCC_TOS_0                       /* Timeout controlled by Tx Event FIFO */
#define DDL_FDCAN_TIMEOUTMODE_RXFIFO0    FDCAN_TOCC_TOS_1                       /* Timeout controlled by Rx FIFO 0 */
#define DDL_FDCAN_TIMEOUTMODE_RXFIFO1    (FDCAN_TOCC_TOS_1 | FDCAN_TOCC_TOS_0)  /* Timeout controlled by Rx FIFO 1 */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_IT IT
  * @{
  */
#define DDL_FDCAN_IT_ARA               FDCAN_IE_ARAE      /* Access to Reserved Address Interrupt */
#define DDL_FDCAN_IT_PED               FDCAN_IE_PEDE      /* Protocol Error in Data Phase Interrupt */
#define DDL_FDCAN_IT_PEA               FDCAN_IE_PEAE      /* Protocol Error in Arbitration Phase Interrupt */
#define DDL_FDCAN_IT_WDI               FDCAN_IE_WDIE      /* Watchdog  Interrupt */
#define DDL_FDCAN_IT_BO                FDCAN_IE_BOE       /* Bus_Off Status Interrupt */
#define DDL_FDCAN_IT_EW                FDCAN_IE_EWE       /* Warning Status Interrupt */
#define DDL_FDCAN_IT_EP                FDCAN_IE_EPE       /* Error Passive Interrupt */
#define DDL_FDCAN_IT_ELO               FDCAN_IE_ELOE      /* Error Logging Overflow Interrupt */
#define DDL_FDCAN_IT_DRX               FDCAN_IE_DRXE      /* Message stored to Dedicated Rx Buffer Interrupt */
#define DDL_FDCAN_IT_TOO               FDCAN_IE_TOOE      /* Timeout Occurred Interrupt */
#define DDL_FDCAN_IT_MRAF              FDCAN_IE_MRAFE     /* Message RAM Access Failure Interrupt */
#define DDL_FDCAN_IT_TSW               FDCAN_IE_TSWE      /* Timestamp Wraparound Interrupt */
#define DDL_FDCAN_IT_TEFL              FDCAN_IE_TEFLE     /* Tx Event FIFO Event Lost Interrupt */
#define DDL_FDCAN_IT_TEFF              FDCAN_IE_TEFFE     /* Tx Event FIFO Full Interrupt */
#define DDL_FDCAN_IT_TEFW              FDCAN_IE_TEFWE     /* Tx Event FIFO Watermark Reached Interrupt */
#define DDL_FDCAN_IT_TEFN              FDCAN_IE_TEFNE     /* Tx Event FIFO New Entry Interrupt */
#define DDL_FDCAN_IT_TFE               FDCAN_IE_TFEE      /* Tx FIFO Empty Interrupt */
#define DDL_FDCAN_IT_TCF               FDCAN_IE_TCFE      /* Transmission Cancellation Finished Interrupt */
#define DDL_FDCAN_IT_TC                FDCAN_IE_TCE       /* Transmission Completed Interrupt */
#define DDL_FDCAN_IT_HPM               FDCAN_IE_HPME      /* High Priority Message Interrupt */
#define DDL_FDCAN_IT_RF1L              FDCAN_IE_RF1LE     /* Rx FIFO 1 Message Lost Interrupt */
#define DDL_FDCAN_IT_RF1F              FDCAN_IE_RF1FE     /* Rx FIFO 1 Full Interrupt */
#define DDL_FDCAN_IT_RF1W              FDCAN_IE_RF1WE     /* Rx FIFO 1 Watermark Reached Interrupt */
#define DDL_FDCAN_IT_RF1N              FDCAN_IE_RF1NE     /* Rx FIFO 1 New Message Interrupt */
#define DDL_FDCAN_IT_RF0L              FDCAN_IE_RF0LE     /* Rx FIFO 0 Message Lost Interrupt */
#define DDL_FDCAN_IT_RF0F              FDCAN_IE_RF0FE     /* Rx FIFO 0 Full Interrupt */
#define DDL_FDCAN_IT_RF0W              FDCAN_IE_RF0WE     /* Rx FIFO 0 Watermark Reached Interrupt */
#define DDL_FDCAN_IT_RF0N              FDCAN_IE_RF0NE     /* Rx FIFO 0 New Message Interrupt */
#define DDL_FDCAN_IT_MASK              (0x3FCFFFFFU)      /* Interrupt Mask */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_IT_LINE IT LINE
  * @{
  */
#define DDL_FDCAN_IT_LINE0           (0x00000000U)    /*  Interrupt Line 0 */
#define DDL_FDCAN_IT_LINE1           (0x00000001U)    /*  Interrupt Line 1 */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_EINT_LINE IT LINE
  * @{
  */
#define DDL_FDCAN_EINT_LINE0           FDCAN_ILE_EINT0    /*  EINT Line 0 */
#define DDL_FDCAN_EINT_LINE1           FDCAN_ILE_EINT1    /*  EINT Line 1 */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_NOMATCH_STD_FILTER NOMATCH_STD_FILTER
  * @{
  */
#define DDL_FDCAN_NOMATCH_STD_RXFIFO0           (0x00000000U)       /* Non-matching Frames Standard Accept in Rx FIFO 0 */
#define DDL_FDCAN_NOMATCH_STD_RXFIFO1           FDCAN_GFC_ANFS_0    /* Non-matching Frames Standard Accept in Rx FIFO 1*/
#define DDL_FDCAN_NOMATCH_STD_REJECT            FDCAN_GFC_ANFS_1    /* Reject Non-matching Frames Standard */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_NOMATCH_EXT_FILTER NOMATCH_EXT_FILTER
  * @{
  */
#define DDL_FDCAN_NOMATCH_EXT_RXFIFO0           (0x00000000U)       /* Non-matching Frames Extended Accept in Rx FIFO 0 */
#define DDL_FDCAN_NOMATCH_EXT_RXFIFO1           FDCAN_GFC_ANFE_0    /* Non-matching Frames Extended Accept in Rx FIFO 1*/
#define DDL_FDCAN_NOMATCH_EXT_REJECT            FDCAN_GFC_ANFE_1    /* Reject Non-matching Frames Extended */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_REMOTE_STD_FILTER REMOTE_STD_FILTER
  * @{
  */
#define DDL_FDCAN_REMOTE_STD_FILTER            (0x00000000U)       /* Filter Remote Frames Standard */
#define DDL_FDCAN_REMOTE_STD_REJECT            FDCAN_GFC_RRFS      /* Reject Remote Frames Standard */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_REMOTE_EXT_FILTER REMOTE_EXT_FILTER
  * @{
  */
#define DDL_FDCAN_REMOTE_EXT_FILTER            (0x00000000U)       /* Filter Remote Frames Standard */
#define DDL_FDCAN_REMOTE_EXT_REJECT            FDCAN_GFC_RRFE      /* Reject Remote Frames Standard */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_RXFIFO_NUM RXFIFO_NUM
  * @{
  */
#define DDL_FDCAN_RXFIFO_0           (0x00000000U)
#define DDL_FDCAN_RXFIFO_1           (0x00000001U)
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_RXMODE RXMODE
  * @{
  */
#define DDL_FDCAN_RXMODE_BLOCKING           (0x00000000U)        /* FIFO blocking mode */
#define DDL_FDCAN_RXMODE_OVERWRITE          FDCAN_RXF0C_F0OM     /* FIFO overwrite mode */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_TX_MODE RXFIFO_MODE
  * @{
  */
#define DDL_FDCAN_TXMODE_FIFO           (0x00000000U)        /* Tx FIFO operation */
#define DDL_FDCAN_TXMODE_QUEUE          FDCAN_TXBC_TFQM      /* Tx Queue operation */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FILEDSIZE FILEDSIZE
  * @{
  */
#define DDL_FDCAN_FILEDSIZE_8BYTE                (0x00000004U)        /* 8 bytes data field */
#define DDL_FDCAN_FILEDSIZE_12BYTE               (0x00000005U)        /* 12 bytes data field */
#define DDL_FDCAN_FILEDSIZE_16BYTE               (0x00000006U)        /* 16 bytes data field */
#define DDL_FDCAN_FILEDSIZE_20BYTE               (0x00000007U)        /* 20 bytes data field */
#define DDL_FDCAN_FILEDSIZE_24BYTE               (0x00000008U)        /* 24 bytes data field */
#define DDL_FDCAN_FILEDSIZE_32BYTE               (0x0000000AU)        /* 32 bytes data field */
#define DDL_FDCAN_FILEDSIZE_48BYTE               (0x0000000EU)        /* 48 bytes data field */
#define DDL_FDCAN_FILEDSIZE_64BYTE               (0x00000012U)        /* 64 bytes data field */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_ID_TYPE ID_TYPE
  * @{
  */
#define DDL_FDCAN_STANDARD_ID           (0x00000000U)
#define DDL_FDCAN_EXTENDED_ID           (0x40000000U)
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FILTER_TYPE  FILTER_TYPE
  * @{
  */
#define DDL_FDCAN_FILTER_TYPE_RANGE           (0x00000000U)   /* Range filter from ID1 to ID2 (ID2 ≥ ID1) */
#define DDL_FDCAN_FILTER_TYPE_DUAL            (0x00000001U)   /* Dual ID filter for ID1 or ID2 */
#define DDL_FDCAN_FILTER_TYPE_MASK            (0x00000002U)   /* Classic filter: ID1 = filter, ID2 = mask */
#define DDL_FDCAN_FILTER_TYPE_DISABLE         (0x00000003U)   /* Filter element disabled, only for DDL_FDCAN_STANDARD_ID*/
#define DDL_FDCAN_FILTER_TYPE_RANGE_NOMASK    (0x00000003U)   /* Range filter from EFID1 to EFID2 (EFID2 ≥ EFID1), XIDAM mask not applied, only for DDL_FDCAN_EXTENDED_ID */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FILTER_CONFIG  FILTER_CONFIG
  * @{
  */
#define DDL_FDCAN_FILTER_CONFIG_DISABLE           (0x00000000U)   /* Disable filter element */
#define DDL_FDCAN_FILTER_CONFIG_TO_FIFO0          (0x00000001U)   /* Store in Rx FIFO 0 if filter matches */
#define DDL_FDCAN_FILTER_CONFIG_TO_FIFO1          (0x00000002U)   /* Store in Rx FIFO 1 if filter matches */
#define DDL_FDCAN_FILTER_CONFIG_REJECT            (0x00000003U)   /* Reject ID if filter matches, not intended to be used with Sync messages */
#define DDL_FDCAN_FILTER_CONFIG_HP                (0x00000004U)   /* Set priority if filter matches, not intended to be used with Sync messages, no storage */
#define DDL_FDCAN_FILTER_CONFIG_TO_FIFO0_HP       (0x00000005U)   /* Set priority and store in FIFO 0 if filter matches */
#define DDL_FDCAN_FILTER_CONFIG_TO_FIFO1_HP       (0x00000006U)   /* Set priority and store in FIFO 1 if filter matches */
#define DDL_FDCAN_FILTER_CONFIG_TO_BUF            (0x00000007U)   /* Store into Rx Buffer or as debug message, configuration of SFT[1:0] ignored */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_ESI_TYPE  Error State Indicator
  * @{
  */
#define DDL_FDCAN_ESI_ACTIVE            (0x00000000U)
#define DDL_FDCAN_ESI_PASSIVE           (0x80000000U)
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FRAME_TYPE  FRAME_TYPE
  * @{
  */
#define DDL_FDCAN_FRAME_NORMAL           (0x00000000U)
#define DDL_FDCAN_FRAME_REMOTE           (0x20000000U)
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_DATALENGTH_BYTES  DATALENGTH_BYTES
  * @{
  */
#define DDL_FDCAN_DATALENGTH_BYTES_0       (0x00000000U)   /* 0 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_1       (0x00000001U)   /* 1 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_2       (0x00000002U)   /* 2 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_3       (0x00000003U)   /* 3 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_4       (0x00000004U)   /* 4 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_5       (0x00000005U)   /* 5 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_6       (0x00000006U)   /* 6 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_7       (0x00000007U)   /* 7 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_8       (0x00000008U)   /* 8 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_12      (0x00000009U)   /* 12 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_16      (0x0000000AU)   /* 16 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_20      (0x0000000BU)   /* 20 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_24      (0x0000000CU)   /* 24 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_32      (0x0000000DU)   /* 32 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_48      (0x0000000EU)   /* 48 bytes data field */
#define DDL_FDCAN_DATALENGTH_BYTES_64      (0x0000000FU)   /* 64 bytes data field */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_EFC  Event FIFO Control
  * @{
  */
#define DDL_FDCAN_EFC_DISABLE           (0x00000000U)      /* Don’t store Tx events */
#define DDL_FDCAN_EFC_STORE_TXEVENT     (0x00800000U)      /* Store Tx events */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FDFRAME  FDFRAME
  * @{
  */
#define DDL_FDCAN_FDFRAME_CLASSIC           (0x00000000U)      /* Frame transmitted in Classic CAN format */
#define DDL_FDCAN_FDFRAME_FD                (0x00200000U)      /* Frame transmitted in FD CAN format */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FRAME_MATCH  FRAME_MATCH
  * @{
  */
#define DDL_FDCAN_FRAME_MATCH              (0x00000000U)      /* Received frame matching filter index FIDX */
#define DDL_FDCAN_FRAME_NOMATCH            (0x80000000U)      /* Received frame did not match any Rx filter element */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_BITRATE_SWITCH  BITRATE_SWITCH
  * @{
  */
#define DDL_FDCAN_BRW_DISABLE           (0x00000000U)      /* CAN FD frames transmitted without bit rate switching */
#define DDL_FDCAN_BRW_ENABLE            (0x00100000U)      /* CAN FD frames transmitted with bit rate switching */
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_RXPIN_STATUS  RXPIN STATUS
  * @{
  */
#define DDL_FDCAN_RXPIN_DOMINANT           (0x00000000U)      /* Receive pin of CAN bus is dominant */
#define DDL_FDCAN_RXPIN_RECESSIVE          FDCAN_TEST_RX      /* Receive pin of CAN bus is recessive*/
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_TXPIN_MODE TXPIN MODE
  * @{
  */
#define DDL_FDCAN_TXPIN_RESET             (0x00000000U)                         /* Transmit pin of CAN bus is controlled by the CAN Core */
#define DDL_FDCAN_TXPIN_SAMPLING          FDCAN_TEST_TX_0                       /* Sample Point can be monitored at transmit pin of CAN bus */
#define DDL_FDCAN_TXPIN_DOMINANT          FDCAN_TEST_TX_1                       /* Transmit pin of CAN bus is dominant */
#define DDL_FDCAN_TXPIN_RECESSIVE         (FDCAN_TEST_TX_1 | FDCAN_TEST_TX_0)   /* Transmit pin of CAN bus is recessive*/
/**
  * @}
  */

/** @defgroup FDCAN_DDL_EC_FIFO_MESSAGE_STORED FIFO MESSAGE STORED
  * @{
  */
#define DDL_FDCAN_FIFO_MESSAGE_NO_FIFO          (0x00000000U)                            /* FIFO message stored */
#define DDL_FDCAN_FIFO_MESSAGE_LOST             (FDCAN_HPMS_MSI_0)                       /* FIFO message not stored */
#define DDL_FDCAN_FIFO_MESSAGE_STORED_FIFO0     (FDCAN_HPMS_MSI_1)                       /* FIFO message not stored */
#define DDL_FDCAN_FIFO_MESSAGE_STORED_FIFO1     (FDCAN_HPMS_MSI)                         /* FIFO message not stored */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup FDCAN_DDL_Exported_Macros FDCAN Exported Macros
  * @{
  */

/** @defgroup FDCAN_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in FDCAN register
  * @param  __INSTANCE__ FDCAN Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_FDCAN_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in FDCAN register
  * @param  __INSTANCE__ FDCAN Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_FDCAN_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/* Words (4/5/../18) -> ESC(0..7) */
#define DDL_FDCAN_ELTSIZE_TO_ESC(__WORDS__) \
  ((uint32_t)((const uint8_t[]){0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 5, 0, 0, 0, 6, 0, 0, 0, 7})[(__WORDS__)])

/* ESC(0..7) -> Words */
#define DDL_FDCAN_ESC_TO_ELTSIZE(__ESC__) \
  ((uint32_t)((const uint8_t[]){4, 5, 6, 7, 8, 10, 14, 18})[((__ESC__) & 0x7U)])

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup FDCAN_DDL_Exported_Functions FDCAN Exported Functions
  * @{
  */

/** @defgroup FDCAN_DDL_EF_Core_Release Core Release
  * @{
  */

/**
  * @brief  Get core release.
  * @param  FDCANx FDCAN instance
  * @retval A 32-bit value in the format 0xXYZ00000:
  *         -X = Core Release.
  *         -Y = Step of Core Release.
  *         -Z = Sub-step of Core Release.
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetCoreRelease(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CREL, FDCAN_CREL_REL | FDCAN_CREL_STEP | FDCAN_CREL_SUBSTEP));
}

/**
  * @brief  Get time stamp.
  * @param  FDCANx FDCAN instance
  * @retval A 32-bit value in the format 0x000XYYZZ:
  *         -X  = Time Stamp Year.
  *         -YY = Time Stamp Month.
  *         -ZZ = Time Stamp Day.
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTimeStamp(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CREL, FDCAN_CREL_YEAR | FDCAN_CREL_MON | FDCAN_CREL_DAY));
}

/**
  * @brief  Get Endianness Test Value.
  * @param  FDCANx FDCAN instance
  * @retval A 32-bit value.
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetEndian(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_REG(FDCANx->ENDN));
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_Control_Configuration Control Configuration
  * @{
  */

/**
  * @brief  Enable FDCAN initialization.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableInitMode(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_INIT);
}

/**
  * @brief  Disable FDCAN initialization.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableInitMode(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_INIT);
}

/**
  * @brief  Check FDCAN initialization is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledInitMode(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_INIT) == FDCAN_CCCR_INIT);
}

/**
  * @brief  Enable FDCAN write access.
  * @note   ALL write access bits are protected write, can only be written when CCCR.CCE is set AND CCCR.INIT is set.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableWriteAccess(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_CCE);
}

/**
  * @brief  Disable FDCAN write access.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableWriteAccess(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_CCE);
}

/**
  * @brief  Check FDCAN write access is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledWriteAccess(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_CCE) == FDCAN_CCCR_CCE);
}

/**
  * @brief  Set frame format.
  * @param  FDCANx FDCAN instance
  * @param  Format This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_FRAME_CLASSIC
  *         @arg @ref DDL_FDCAN_FRAME_FD_NOBRS
  *         @arg @ref DDL_FDCAN_FRAME_FD_BRS
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetFrameFormat(FDCAN_TypeDef *FDCANx, uint32_t Format)
{
  MODIFY_REG(FDCANx->CCCR, (FDCAN_CCCR_BRSE | FDCAN_CCCR_FDOE), Format);
}

/**
  * @brief  Get frame mode.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_FRAME_CLASSIC
  *         @arg @ref DDL_FDCAN_FRAME_FD_NOBRS
  *         @arg @ref DDL_FDCAN_FRAME_FD_BRS
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetFrameFormat(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->CCCR, (FDCAN_CCCR_BRSE | FDCAN_CCCR_FDOE));
}

/**
  * @brief  Set operation mode.
  * @param  FDCANx FDCAN instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_MODE_NORMAL
  *         @arg @ref DDL_FDCAN_MODE_BUS_MONITOR
  *         @arg @ref DDL_FDCAN_MODE_RESTRICTED
  *         @arg @ref DDL_FDCAN_MODE_LOOPBACK_INTERNAL
  *         @arg @ref DDL_FDCAN_MODE_LOOPBACK_EXTERNAL
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetOperationMode(FDCAN_TypeDef *FDCANx, uint32_t Mode)
{
  CLEAR_BIT(FDCANx->CCCR, (FDCAN_CCCR_MON | FDCAN_CCCR_ASM | FDCAN_CCCR_TEST));
  CLEAR_BIT(FDCANx->TEST, FDCAN_TEST_LBCK);

  if (Mode == DDL_FDCAN_MODE_BUS_MONITOR)
  {
    SET_BIT(FDCANx->CCCR, FDCAN_CCCR_MON);
  }
  else if (Mode == DDL_FDCAN_MODE_RESTRICTED)
  {
    SET_BIT(FDCANx->CCCR, FDCAN_CCCR_ASM);
  }
  else if (Mode == DDL_FDCAN_MODE_LOOPBACK_INTERNAL)
  {
    SET_BIT(FDCANx->CCCR, FDCAN_CCCR_TEST | FDCAN_CCCR_MON);
    SET_BIT(FDCANx->TEST, FDCAN_TEST_LBCK);
  }
  else if (Mode == DDL_FDCAN_MODE_LOOPBACK_EXTERNAL)
  {
    SET_BIT(FDCANx->CCCR, FDCAN_CCCR_TEST);
    SET_BIT(FDCANx->TEST, FDCAN_TEST_LBCK);
  }
}

/**
  * @brief  Get operation mode.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_MODE_NORMAL
  *         @arg @ref DDL_FDCAN_MODE_BUS_MONITOR
  *         @arg @ref DDL_FDCAN_MODE_RESTRICTED
  *         @arg @ref DDL_FDCAN_MODE_LOOPBACK_INTERNAL
  *         @arg @ref DDL_FDCAN_MODE_LOOPBACK_EXTERNAL
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetOperationMode(FDCAN_TypeDef *FDCANx)
{
  uint32_t cccr = READ_BIT(FDCANx->CCCR, (FDCAN_CCCR_MON | FDCAN_CCCR_ASM | FDCAN_CCCR_TEST));
  uint32_t lbck = READ_BIT(FDCANx->TEST, FDCAN_TEST_LBCK);

  if ((cccr & FDCAN_CCCR_ASM) != 0U)
  {
    return DDL_FDCAN_MODE_RESTRICTED;
  }

  if (lbck != 0U)
  {
    return ((cccr & FDCAN_CCCR_MON) != 0U) ? DDL_FDCAN_MODE_LOOPBACK_INTERNAL 
                                           : DDL_FDCAN_MODE_LOOPBACK_EXTERNAL;
  }

  if ((cccr & FDCAN_CCCR_MON) != 0U)
  {
    return DDL_FDCAN_MODE_BUS_MONITOR;
  }
  
  return DDL_FDCAN_MODE_NORMAL;
}

/**
  * @brief  Check loop back mode is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledLoopBackMode(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->TEST, FDCAN_TEST_LBCK) == FDCAN_TEST_LBCK);
}

/**
  * @brief  Enable FDCAN auto retransmission.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableAutoRetransmission(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_DAR);
}

/**
  * @brief  Disable FDCAN auto retransmission.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableAutoRetransmission(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_DAR);
}

/**
  * @brief  Check FDCAN auto retransmission is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledAutoRetransmission(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_DAR) != FDCAN_CCCR_DAR);
}


/**
  * @brief  Set Wide Message Marker.
  * @param  FDCANx FDCAN instance
  * @param  Wide This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_WIDE_MESSAGE_8BIT
  *         @arg @ref DDL_FDCAN_WIDE_MESSAGE_16BIT
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetWideMessageMarker(FDCAN_TypeDef *FDCANx, uint32_t Wide)
{
  MODIFY_REG(FDCANx->CCCR, FDCAN_CCCR_WMM, Wide);
}

/**
  * @brief  Get Wide Message Marker
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_WIDE_MESSAGE_8BIT
  *         @arg @ref DDL_FDCAN_WIDE_MESSAGE_16BIT
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetWideMessageMarker(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->CCCR, FDCAN_CCCR_WMM));
}

/**
  * @brief  Enable FDCAN protocol exception.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableProtocolException(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_PXHD);
}

/**
  * @brief  Disable FDCAN protocol exception.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableProtocolException(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_PXHD);
}

/**
  * @brief  Check FDCAN protocol exception is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledProtocolException(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_PXHD) != FDCAN_CCCR_PXHD);
}

/**
  * @brief  Enable FDCAN edge filtering during bus integration.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableEdgeFilter(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_EFBI);
}

/**
  * @brief  Disable FDCAN edge filtering during bus integration.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableEdgeFilter(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_EFBI);
}

/**
  * @brief  Check FDCAN edge filtering is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledEdgeFilter(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_EFBI) == FDCAN_CCCR_EFBI);
}

/**
  * @brief  Enable FDCAN transmit pause.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableTransmitPause(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_TXP);
}

/**
  * @brief  Disable FDCAN transmit pause.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableTransmitPause(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_TXP);
}

/**
  * @brief  Check FDCAN transmit pause is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledTransmitPause(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_TXP) == FDCAN_CCCR_TXP);
}

/**
  * @brief  Enable FDCAN clock stop request.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableClockStopRequest(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->CCCR, FDCAN_CCCR_CSR);
}

/**
  * @brief  Disable FDCAN clock stop request.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableClockStopRequest(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->CCCR, FDCAN_CCCR_CSR);
}

/**
  * @brief  Check FDCAN clock stop request is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledClockStopRequest(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->CCCR, FDCAN_CCCR_CSR) == FDCAN_CCCR_CSR);
}

/**
  * @brief  Set FDCAN specification.
  * @param  FDCANx FDCAN instance
  * @param  Specification This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_SPEC_ISO
  *         @arg @ref DDL_FDCAN_SPEC_BOSCH
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetSpecification(FDCAN_TypeDef *FDCANx, uint32_t Specification)
{
  MODIFY_REG(FDCANx->CCCR, FDCAN_CCCR_NISO, Specification);
}

/**
  * @brief  Get FDCAN specification.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_SPEC_ISO
  *         @arg @ref DDL_FDCAN_SPEC_BOSCH
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetSpecification(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->CCCR, FDCAN_CCCR_NISO);
}

/**
  * @brief  Get FDCAN Receive Pin status.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXPIN_DOMINANT
  *         @arg @ref DDL_FDCAN_RXPIN_RECESSIVE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxPinStatus(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TEST, FDCAN_TEST_RX);
}

/**
  * @brief  Set FDCAN Transmit Pin mode.
  * @param  FDCANx FDCAN instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_TXPIN_RESET
  *         @arg @ref DDL_FDCAN_TXPIN_SAMPLING
  *         @arg @ref DDL_FDCAN_TXPIN_DOMINANT
  *         @arg @ref DDL_FDCAN_TXPIN_RECESSIVE
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxPinMode(FDCAN_TypeDef *FDCANx, uint32_t Mode)
{
  MODIFY_REG(FDCANx->TEST, FDCAN_TEST_TX, Mode);
}

/**
  * @brief  Get FDCAN Transmit Pin mode.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_TXPIN_RESET
  *         @arg @ref DDL_FDCAN_TXPIN_SAMPLING
  *         @arg @ref DDL_FDCAN_TXPIN_DOMINANT
  *         @arg @ref DDL_FDCAN_TXPIN_RECESSIVE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxPinMode(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TEST, FDCAN_TEST_TX);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_Rate_Configuration Rate Configuration
  * @{
  */

/**
  * @brief  Configure data bit timing and prescaler.
  * @param  FDCANx FDCAN instance
  * @param  Prescaler between Min_Data=1 and Max_Data=32
  * @param  Segment1 between Min_Data=1 and Max_Data=32
  * @param  Segment2 between Min_Data=2 and Max_Data=16
  * @param  Width between Min_Data=1 and Max_Data=16
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DBTPConfig(FDCAN_TypeDef *FDCANx, uint32_t Prescaler, uint32_t Segment1, uint32_t Segment2, uint32_t Width)
{
  MODIFY_REG(FDCANx->DBTP, (FDCAN_DBTP_DBRP | FDCAN_DBTP_DTSEG1 | FDCAN_DBTP_DTSEG2 | FDCAN_DBTP_DSJW),
   (((Prescaler - 1) << FDCAN_DBTP_DBRP_Pos) | ((Segment1 - 1) << FDCAN_DBTP_DTSEG1_Pos) | ((Segment2 - 1) << FDCAN_DBTP_DTSEG2_Pos) | ((Width - 1) << FDCAN_DBTP_DSJW_Pos)));
}

/**
  * @brief  Set data bit rate prescaler.
  * @param  FDCANx FDCAN instance
  * @param  Prescaler between Min_Data=1 and Max_Data=32
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetDataPrescaler(FDCAN_TypeDef *FDCANx, uint32_t Prescaler)
{
  MODIFY_REG(FDCANx->DBTP, FDCAN_DBTP_DBRP, ((Prescaler - 1) << FDCAN_DBTP_DBRP_Pos));
}

/**
  * @brief  Get data bit prescaler.
  * @param  FDCANx FDCAN instance
  * @retval Prescaler (between Min_Data=1 and Max_Data=32)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetDataPrescaler(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->DBTP, FDCAN_DBTP_DBRP) >> FDCAN_DBTP_DBRP_Pos) + 1;
}

/**
  * @brief  Set data time segment1.
  * @param  FDCANx FDCAN instance
  * @param  Segment between Min_Data=1 and Max_Data=32
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetDataTimeSegment1(FDCAN_TypeDef *FDCANx, uint32_t Segment)
{
  MODIFY_REG(FDCANx->DBTP, FDCAN_DBTP_DTSEG1, (Segment - 1) << FDCAN_DBTP_DTSEG1_Pos);
}

/**
  * @brief  Get data time segment1.
  * @param  FDCANx FDCAN instance
  * @retval Prescaler (between Min_Data=1 and Max_Data=32)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetDataTimeSegment1(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->DBTP, FDCAN_DBTP_DTSEG1) >> FDCAN_DBTP_DTSEG1_Pos) + 1;
}

/**
  * @brief  Set data time segment2.
  * @param  FDCANx FDCAN instance
  * @param  Segment between Min_Data=1 and Max_Data=16
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetDataTimeSegment2(FDCAN_TypeDef *FDCANx, uint32_t Segment)
{
  MODIFY_REG(FDCANx->DBTP, FDCAN_DBTP_DTSEG2, (Segment - 1) << FDCAN_DBTP_DTSEG2_Pos);
}

/**
  * @brief  Get data time segment2.
  * @param  FDCANx FDCAN instance
  * @retval Prescaler (between Min_Data=1 and Max_Data=16)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetDataTimeSegment2(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->DBTP, FDCAN_DBTP_DTSEG2) >> FDCAN_DBTP_DTSEG2_Pos) + 1;
}

/**
  * @brief  Set data synchronization jump width.
  * @param  FDCANx FDCAN instance
  * @param  Sjw between Min_Data=1 and Max_Data=16
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetDataSyncJumpWidth(FDCAN_TypeDef *FDCANx, uint32_t Sjw)
{
  MODIFY_REG(FDCANx->DBTP, FDCAN_DBTP_DSJW, (Sjw - 1) << FDCAN_DBTP_DSJW_Pos);
}

/**
  * @brief  Get data synchronization jump width.
  * @param  FDCANx FDCAN instance
  * @retval Prescaler (between Min_Data=1 and Max_Data=16)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetDataSyncJumpWidth(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->DBTP, FDCAN_DBTP_DSJW) >> FDCAN_DBTP_DSJW_Pos) + 1;
}

/**
  * @brief  Configure nominal bit timing and prescaler.
  * @param  FDCANx FDCAN instance
  * @param  Prescaler between Min_Data=1 and Max_Data=512
  * @param  Segment1 between Min_Data=2 and Max_Data=256
  * @param  Segment2 between Min_Data=2 and Max_Data=128
  * @param  Width between Min_Data=1 and Max_Data=128
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_NBTPConfig(FDCAN_TypeDef *FDCANx, uint32_t Prescaler, uint32_t Segment1, uint32_t Segment2, uint32_t Width)
{
  MODIFY_REG(FDCANx->NBTP, (FDCAN_NBTP_NBRP | FDCAN_NBTP_NTSEG1 | FDCAN_NBTP_NTSEG2 | FDCAN_NBTP_NSJW),
   (((Prescaler - 1) << FDCAN_NBTP_NBRP_Pos) | ((Segment1 - 1) << FDCAN_NBTP_NTSEG1_Pos) | ((Segment2 - 1) << FDCAN_NBTP_NTSEG2_Pos) | ((Width - 1) << FDCAN_NBTP_NSJW_Pos)));
}

/**
  * @brief  Set nominal bit rate prescaler.
  * @param  FDCANx FDCAN instance
  * @param  Prescaler between Min_Data=1 and Max_Data=512
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetNominalPrescaler(FDCAN_TypeDef *FDCANx, uint32_t Prescaler)
{
  MODIFY_REG(FDCANx->NBTP, FDCAN_NBTP_NBRP, ((Prescaler - 1) << FDCAN_NBTP_NBRP_Pos));
}

/**
  * @brief  Get nominal bit prescaler.
  * @param  FDCANx FDCAN instance
  * @retval Prescaler (between Min_Data=1 and Max_Data=512)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetNominalPrescaler(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->NBTP, FDCAN_NBTP_NBRP) >> FDCAN_NBTP_NBRP_Pos) + 1;
}

/**
  * @brief  Set nominal time segment1.
  * @param  FDCANx FDCAN instance
  * @param  Segment between Min_Data=1 and Max_Data=256
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetNominalTimeSegment1(FDCAN_TypeDef *FDCANx, uint32_t Segment)
{
  MODIFY_REG(FDCANx->NBTP, FDCAN_NBTP_NTSEG1, ((Segment - 1) << FDCAN_NBTP_NTSEG1_Pos));
}

/**
  * @brief  Get nominal time segment1.
  * @param  FDCANx FDCAN instance
  * @retval Segment (between Min_Data=1 and Max_Data=256)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetNominalTimeSegment1(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->NBTP, FDCAN_NBTP_NTSEG1) >> FDCAN_NBTP_NTSEG1_Pos) + 1;
}

/**
  * @brief  Set nominal time segment2.
  * @param  FDCANx FDCAN instance
  * @param  Segment between Min_Data=1 and Max_Data=128
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetNominalTimeSegment2(FDCAN_TypeDef *FDCANx, uint32_t Segment)
{
  MODIFY_REG(FDCANx->NBTP, FDCAN_NBTP_NTSEG2, ((Segment - 1) << FDCAN_NBTP_NTSEG2_Pos));
}

/**
  * @brief  Get nominal time segment2.
  * @param  FDCANx FDCAN instance
  * @retval Segment (between Min_Data=1 and Max_Data=128)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetNominalTimeSegment2(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->NBTP, FDCAN_NBTP_NTSEG2) >> FDCAN_NBTP_NTSEG2_Pos) + 1;
}

/**
  * @brief  Set nominal synchronization jump width.
  * @param  FDCANx FDCAN instance
  * @param  Sjw between Min_Data=1 and Max_Data=128
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetNominalSyncJumpWidth(FDCAN_TypeDef *FDCANx, uint32_t Sjw)
{
  MODIFY_REG(FDCANx->NBTP, FDCAN_NBTP_NSJW, (Sjw - 1) << FDCAN_NBTP_NSJW_Pos);
}

/**
  * @brief  Get nominal synchronization jump width.
  * @param  FDCANx FDCAN instance
  * @retval Sjw (between Min_Data=1 and Max_Data=128)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetNominalSyncJumpWidth(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->NBTP, FDCAN_NBTP_NSJW) >> FDCAN_NBTP_NSJW_Pos) + 1;
}

/**
  * @brief  Enable Transmitter Delay Compensation.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableTDC(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->DBTP, FDCAN_DBTP_TDC);
}

/**
  * @brief  Disable Transmitter Delay Compensation.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableTDC(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->DBTP, FDCAN_DBTP_TDC);
}

/**
  * @brief  Check Transmitter Delay Compensation is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledTDC(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->DBTP, FDCAN_DBTP_TDC) == FDCAN_DBTP_TDC);
}

/**
  * @brief  Get Transmitter Delay Compensation Value.
  * @note   Some bit of PSR resgister will be reset on read, so it is recommended to use
  *          @ref DDL_FDCAN_GetProtocolStatus() to get all value.
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=127)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTDCValue(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->PSR, FDCAN_PSR_TDCV) >> FDCAN_PSR_TDCV_Pos);
}

/**
  * @brief  Get Transmitter Delay Compensation SSP Offset.
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=127)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTDCSSPOffset(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->TDCR, FDCAN_TDCR_TDCO) >> FDCAN_TDCR_TDCO_Pos);
}

/**
  * @brief  Get Transmitter Delay Compensation Filter Window Length.
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=127)
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTDCFilterWindowLength(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->TDCR, FDCAN_TDCR_TDCF));
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_Timestamp_Timeout Timestamp Timeout
  * @{
  */

/**
  * @brief  Set FDCAN Watchdog counter start value.
  * @param  FDCANx FDCAN instance
  * @param  Count between Min_Data=0 and Max_Data=255.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetWatchdogCounter(FDCAN_TypeDef *FDCANx, uint32_t Count)
{
  MODIFY_REG(FDCANx->RWD, FDCAN_RWD_WDC, Count);
}

/**
  * @brief  Get FDCAN Watchdog counter start value.
  * @param  FDCANx FDCAN instance
  * @retval Count (between Min_Data=0 and Max_Data=255).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetWatchdogCounter(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->RWD, FDCAN_RWD_WDC);
}

/**
  * @brief  Get FDCAN Watchdog counter value.
  * @param  FDCANx FDCAN instance
  * @retval Count (between Min_Data=0 and Max_Data=255).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetWatchdogValue(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->RWD, FDCAN_RWD_WDV) >> FDCAN_RWD_WDV_Pos);
}

/**
  * @brief  Select FDCAN timestamp counter.
  * @param  FDCANx FDCAN instance
  * @param  Specification This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_TIMESTAMP_NONE
  *         @arg @ref DDL_FDCAN_TIMESTAMP_TCP
  *         @arg @ref DDL_FDCAN_TIMESTAMP_EXT
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTSCntSel(FDCAN_TypeDef *FDCANx, uint32_t Sel)
{
  MODIFY_REG(FDCANx->TSCC, FDCAN_TSCC_TSS, Sel);
}

/**
  * @brief  Get FDCAN timestamp counter select.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_TIMESTAMP_NONE
  *         @arg @ref DDL_FDCAN_TIMESTAMP_TCP
  *         @arg @ref DDL_FDCAN_TIMESTAMP_EXT
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTSCntSel(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TSCC, FDCAN_TSCC_TSS);
}

/**
  * @brief  Set FDCAN timestamp counter Prescaler.
  * @param  FDCANx FDCAN instance
  * @param  Prescaler between Min_Data=0 and Max_Data=15
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTSCntPsc(FDCAN_TypeDef *FDCANx, uint32_t Psc)
{
  MODIFY_REG(FDCANx->TSCC, FDCAN_TSCC_TCP, Psc << FDCAN_TSCC_TCP_Pos);
}

/**
  * @brief  Get FDCAN timestamp counter source Prescaler.
  * @param  FDCANx FDCAN instance
  * @retval Prescaler (between Min_Data=0 and Max_Data=15).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTSCntPsc(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TSCC, FDCAN_TSCC_TCP) >> FDCAN_TSCC_TCP_Pos;
}

/**
  * @brief  Set FDCAN timestamp counter value.
  * @param  FDCANx FDCAN instance
  * @param  Value between Min_Data=0 and Max_Data=65535
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTSCntValue(FDCAN_TypeDef *FDCANx, uint32_t Value)
{
  MODIFY_REG(FDCANx->TSCV, FDCAN_TSCV_TSC, Value);
}

/**
  * @brief  Get FDCAN timestamp counter value.
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=65535).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTSCntValue(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TSCV, FDCAN_TSCV_TSC);
}

/**
  * @brief  Enable FDCAN timeout counter.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableTimeoutCnt(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->TOCC, FDCAN_TOCC_ETOC);
}

/**
  * @brief  Disable FDCAN timeout counter.
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableTimeoutCnt(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->TOCC, FDCAN_TOCC_ETOC);
}

/**
  * @brief  Check FDCAN timeout counter is enabled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledTimeoutCnt(FDCAN_TypeDef *FDCANx)
{
  return (uint32_t)(READ_BIT(FDCANx->TOCC, FDCAN_TOCC_ETOC) == FDCAN_TOCC_ETOC);
}

/**
  * @brief  Select FDCAN timeout mode.
  * @param  FDCANx FDCAN instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_CINTINUE
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_TXFIFO
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_RXFIFO0
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_RXFIFO1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTimeoutMode(FDCAN_TypeDef *FDCANx, uint32_t Mode)
{
  MODIFY_REG(FDCANx->TOCC, FDCAN_TOCC_TOS, Mode);
}

/**
  * @brief  Get FDCAN timeout mode select.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_CINTINUE
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_TXFIFO
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_RXFIFO0
  *         @arg @ref DDL_FDCAN_TIMEOUTMODE_RXFIFO1
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTimeoutMode(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TOCC, FDCAN_TOCC_TOS);
}

/**
  * @brief  Set FDCAN timeout period.
  * @param  FDCANx FDCAN instance
  * @param  Period between Min_Data=0 and Max_Data=65535
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTimeoutPeriod(FDCAN_TypeDef *FDCANx, uint32_t Period)
{
  MODIFY_REG(FDCANx->TOCC, FDCAN_TOCC_TOP, Period << FDCAN_TOCC_TOP_Pos);
}

/**
  * @brief  Get FDCAN timeout period.
  * @param  FDCANx FDCAN instance
  * @retval Period (between Min_Data=0 and Max_Data=65535).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTimeoutPeriod(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TOCC, FDCAN_TOCC_TOP) >> FDCAN_TOCC_TOP_Pos;
}

/**
  * @brief  Set FDCAN timestamp counter value.
  * @note   Only operating in Continous mode, this func can presets the Count.
  *         In other mode, this counter will be preseted by an empty FIFO.
  * @param  FDCANx FDCAN instance
  * @param  Count between Min_Data=0 and Max_Data=65535
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTimeoutCntValue(FDCAN_TypeDef *FDCANx, uint32_t Count)
{
  MODIFY_REG(FDCANx->TOCV, FDCAN_TOCV_TOC, Count);
}

/**
  * @brief  Get FDCAN timestamp counter value.
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=65535).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTimeoutCntValue(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TOCV, FDCAN_TOCV_TOC);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_ERROR_COUNTER ERROR COUNTER
  * @{
  */

/**
  * @brief  Get FDCAN CAN Error logging
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=255).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetErrorLog(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->ECR, FDCAN_ECR_CEL) >> FDCAN_ECR_CEL_Pos;
}

/**
  * @brief  Clear FDCAN CAN Error logging
  * @param  FDCANx FDCAN instance
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_ClearErrorLog(FDCAN_TypeDef *FDCANx)
{
  (void)READ_BIT(FDCANx->ECR, FDCAN_ECR_CEL);
}

/**
  * @brief  Get FDCAN Receive Error Counter
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=127).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxErrorCnt(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->ECR, FDCAN_ECR_REC) >> FDCAN_ECR_REC_Pos;
}

/**
  * @brief  Get FDCAN Transmit Error Counter
  * @param  FDCANx FDCAN instance
  * @retval Value (between Min_Data=0 and Max_Data=255).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxErrorCnt(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->ECR, FDCAN_ECR_TEC) >> FDCAN_ECR_TEC_Pos;
}

/**
  * @brief  Check if the Receive Error Passive Flag is set or not
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RP(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->ECR, FDCAN_ECR_RP) == FDCAN_ECR_RP ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_FILTER_Management FILTER_Management
  * @{
  */

/**
  * @brief  Config FDCAN filter.
  * @param  FDCANx FDCAN instance
  * @param  NoMatchStd This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_NOMATCH_STD_RXFIFO0
  *         @arg @ref DDL_FDCAN_NOMATCH_STD_RXFIFO1
  *         @arg @ref DDL_FDCAN_NOMATCH_STD_REJECT
  * @param  NoMatchExt This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_NOMATCH_EXT_RXFIFO0
  *         @arg @ref DDL_FDCAN_NOMATCH_EXT_RXFIFO1
  *         @arg @ref DDL_FDCAN_NOMATCH_EXT_REJECT
  * @param  RemoteStd This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_REMOTE_STD_FILTER
  *         @arg @ref DDL_FDCAN_REMOTE_STD_REJECT
  * @param  RemoteExt This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_REMOTE_EXT_FILTER
  *         @arg @ref DDL_FDCAN_REMOTE_EXT_REJECT
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_FilterConfig(FDCAN_TypeDef *FDCANx, uint32_t NoMatchStd,
                                            uint32_t NoMatchExt, uint32_t RemoteStd, uint32_t RemoteExt)
{
  MODIFY_REG(FDCANx->GFC, (FDCAN_GFC_RRFE | FDCAN_GFC_RRFS | FDCAN_GFC_ANFE | FDCAN_GFC_ANFS),
             (NoMatchStd | NoMatchExt | RemoteStd | RemoteExt));
}

/**
  * @brief  Set standard message filter element number.
  * @note   Values greater than 128 are interpreted as 128.
  * @param  Num between Min_Data=0 and Max_Data=128
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetStdFilterNum(FDCAN_TypeDef *FDCANx, uint32_t Num)
{
  MODIFY_REG(FDCANx->SIDFC, FDCAN_SIDFC_LSS, (Num << FDCAN_SIDFC_LSS_Pos));
}

/**
  * @brief  Get standard message filter element number.
  * @note   Values greater than 128 are interpreted as 128.
  * @param  FDCANx FDCAN instance
  * @retval Num (between Min_Data=0 and Max_Data=255).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetStdFilterNum(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->SIDFC, FDCAN_SIDFC_LSS) >> FDCAN_SIDFC_LSS_Pos);
}

/**
  * @brief  Set standard message filter start address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  Addr between Min_Data=0 and Max_Data=65535.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetStdFilterAddress(FDCAN_TypeDef *FDCANx, uint32_t Addr)
{
  MODIFY_REG(FDCANx->SIDFC, FDCAN_SIDFC_FLSSA, (Addr & DDL_FDCAN_ADDRESS_MASK));
}

/**
  * @brief  Get standard message filter start address.
  * @param  FDCANx FDCAN instance
  * @retval Addr (between Min_Data=0 and Max_Data=65535).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetStdFilterAddress(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->SIDFC, FDCAN_SIDFC_FLSSA);
}

/**
  * @brief  Set extended message filter element number.
  * @note   Values greater than 64 are interpreted as 64.
  * @param  Num between Min_Data=0 and Max_Data=64
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetExtFilterNum(FDCAN_TypeDef *FDCANx, uint32_t Num)
{
  MODIFY_REG(FDCANx->XIDFC, FDCAN_XIDFC_LSE, (Num << FDCAN_XIDFC_LSE_Pos));
}

/**
  * @brief  Get extended message filter element number.
  * @note   Values greater than 64 are interpreted as 64.
  * @param  FDCANx FDCAN instance
  * @retval Num (between Min_Data=0 and Max_Data=64).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetExtFilterNum(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->XIDFC, FDCAN_XIDFC_LSE) >> FDCAN_XIDFC_LSE_Pos);
}

/**
  * @brief  Set extended message filter start address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  Addr between Min_Data=0 and Max_Data=65535.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetExtFilterAddress(FDCAN_TypeDef *FDCANx, uint32_t Addr)
{
  MODIFY_REG(FDCANx->XIDFC, FDCAN_XIDFC_FLESA, Addr & DDL_FDCAN_ADDRESS_MASK);
}

/**
  * @brief  Get extended message filter start address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  FDCANx FDCAN instance
  * @retval Addr (between Min_Data=0 and Max_Data=65535).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetExtFilterAddress(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->XIDFC, FDCAN_XIDFC_FLESA);
}

/**
  * @brief  Set extended message filter start address.
  * @param  Mask between Min_Data=0 and Max_Data=0x1FFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetExtFilterMask(FDCAN_TypeDef *FDCANx, uint32_t Mask)
{
  MODIFY_REG(FDCANx->XIDAM, FDCAN_XIDAM_EIDM, Mask);
}

/**
  * @brief  Get extended message filter start address.
  * @param  FDCANx FDCAN instance
  * @retval Mask (between Min_Data=0 and Max_Data=0x1FFFFFFF).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetExtFilterMask(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->XIDAM, FDCAN_XIDAM_EIDM);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_Receive_Management Receive_Management
  * @{
  */

/**
  * @brief  Get high priority message filter list.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0):
  *           0:Standard Filter List
  *           1:Extended Filter List
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsExtFilterList(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->HPMS, FDCAN_HPMS_FLST) == FDCAN_HPMS_FLST);
}

/**
  * @brief  Get high priority message filter index.
  * @param  FDCANx FDCAN instance
  * @retval Index (between Min_Data=0 and Max_Data=(SIDFC.LSS - 1)or(XIDFC.LSE - 1)).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetFilterIndex(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->HPMS, FDCAN_HPMS_FIDX) >> FDCAN_HPMS_FIDX_Pos);
}

/**
  * @brief  Get high priority message filter index.
  * @param  FDCANx FDCAN instance
  * @retval value can be one of the following:
  *         @arg @ref DDL_FDCAN_FIFO_MESSAGE_NO_FIFO
  *         @arg @ref DDL_FDCAN_FIFO_MESSAGE_LOST
  *         @arg @ref DDL_FDCAN_FIFO_MESSAGE_STORED_FIFO0
  *         @arg @ref DDL_FDCAN_FIFO_MESSAGE_STORED_FIFO1
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetMsgFIFOIndex(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->HPMS, FDCAN_HPMS_MSI);
}

/**
  * @brief  Get high priority message buffer index.
  * @param  FDCANx FDCAN instance
  * @retval Index (between Min_Data=0 and Max_Data=63).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOIndex(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->HPMS, FDCAN_HPMS_BIDX);
}

/**
  * @brief  Get the New Data flags of Rx Buffers 0 to 63.
  * @param  FDCANx FDCAN instance
  * @param  BufferIndex between Min_Data=0 and Max_Data=63
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_NRD(FDCAN_TypeDef *FDCANx, uint32_t BufferIndex)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)&(FDCANx->NDAT1) + (BufferIndex < 32 ? 0 : 4));
  return READ_BIT(*pReg, 1U << (BufferIndex % 32)) == (1U << (BufferIndex % 32));
}

/**
  * @brief  Clear the New Data flags of Rx Buffers 0 to 31.
  * @param  FDCANx FDCAN instance
  * @param  BufferIndex between Min_Data=0 and Max_Data=63
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_NRD(FDCAN_TypeDef *FDCANx, uint32_t BufferIndex)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)&(FDCANx->NDAT1) + (BufferIndex < 32 ? 0 : 4));
  SET_BIT(*pReg, 1U << (BufferIndex % 32));
}

/**
  * @brief  Get the Any New Data flags of Rx Buffers 0 to 31.
  * @param  FDCANx FDCAN instance
  * @retval state of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsAnyActiveFlag_NRD(FDCAN_TypeDef *FDCANx)
{
  return (READ_REG(FDCANx->NDAT1) | READ_REG(FDCANx->NDAT2)) == 0 ? 0 : 1;
}

/**
  * @brief  Set FIFOx(0/1) operation mode.
  * @param  FDCANx FDCAN instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXMODE_BLOCKING
  *         @arg @ref DDL_FDCAN_RXMODE_OVERWRITE
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFOxMode(FDCAN_TypeDef *FDCANx, uint32_t Mode, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  MODIFY_REG(*pReg, FDCAN_RXF0C_F0OM, Mode);
}

/**
  * @brief  Get FIFOx(0/1) operation mode.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_MODE_BLOCKING
  *         @arg @ref DDL_FDCAN_RXFIFO_OVERWRITE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxMode(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  return READ_BIT(*pReg, FDCAN_RXF0C_F0OM);
}

/**
  * @brief  Set FIFOx(0/1) watermark.
  * @param  FDCANx FDCAN instance
  * @param  Watermark between Min_Data=0 and Max_Data=64.
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFOxWatermark(FDCAN_TypeDef *FDCANx, uint32_t Watermark, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  MODIFY_REG(*pReg, FDCAN_RXF0C_F0WM, (Watermark << FDCAN_RXF0C_F0WM_Pos));
}

/**
  * @brief  Get FIFOx(0/1) watermark.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Watermark (between Min_Data=0 and Max_Data=64).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxWatermark(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  return (READ_BIT(*pReg, FDCAN_RXF0C_F0WM) >> FDCAN_RXF0C_F0WM_Pos);
}

/**
  * @brief  Set FIFOx(0/1) watermark.
  * @note   The Rx FIFOx elements are indexed from 0 to F0S-1.
  * @param  FDCANx FDCAN instance
  * @param  Size between Min_Data=0 and Max_Data=64.
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFOxSize(FDCAN_TypeDef *FDCANx, uint32_t Size, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  MODIFY_REG(*pReg, FDCAN_RXF0C_F0S, (Size << FDCAN_RXF0C_F0S_Pos));
}

/**
  * @brief  Get FIFOx(0/1) watermark.
  * @note   The Rx FIFOx elements are indexed from 0 to F0S-1.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Size (between Min_Data=0 and Max_Data=64).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxSize(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  return (READ_BIT(*pReg, FDCAN_RXF0C_F0S) >> FDCAN_RXF0C_F0S_Pos);
}

/**
  * @brief  Set FIFOx(0/1) address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  FDCANx FDCAN instance
  * @param  Address between Min_Data=0 and Max_Data=0xFFFF.
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFOxAddress(FDCAN_TypeDef *FDCANx, uint32_t Address, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  MODIFY_REG(*pReg, FDCAN_RXF0C_F0SA, Address & DDL_FDCAN_ADDRESS_MASK);
}

/**
  * @brief  Get FIFOx(0/1) address.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Address (between Min_Data=0 and Max_Data=0xFFFF).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxAddress(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0C) + OFFSET_TAB_RXFIFOx[Fifo]));
  return READ_BIT(*pReg, FDCAN_RXF0C_F0SA);
}

/**
  * @brief  Check Rx FIFOx(0/1) message lost flag is set or not.
  * @note   This flag is a copy of interrupt flag IR.RF(0/1)L.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RFLM(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0S) + OFFSET_TAB_RXFIFOx[Fifo]));
  return (READ_BIT(*pReg, FDCAN_RXF0S_RF0L) == FDCAN_RXF0S_RF0L);
}

/**
  * @brief  Check Rx FIFOx(0/1) full flag is set or not.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RFF(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0S) + OFFSET_TAB_RXFIFOx[Fifo]));
  return (READ_BIT(*pReg, FDCAN_RXF0S_F0F) == FDCAN_RXF0S_F0F);
}

/**
  * @brief  Get FIFOx(0/1) put index.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Index (between Min_Data=0 and Max_Data=63).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxPutIndex(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0S) + OFFSET_TAB_RXFIFOx[Fifo]));
  return (READ_BIT(*pReg, FDCAN_RXF0S_F0PI) >> FDCAN_RXF0S_F0PI_Pos);
}

/**
  * @brief  Get FIFOx(0/1) get index.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Index (between Min_Data=0 and Max_Data=63).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxGetIndex(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0S) + OFFSET_TAB_RXFIFOx[Fifo]));
  return (READ_BIT(*pReg, FDCAN_RXF0S_F0GI) >> FDCAN_RXF0S_F0GI_Pos);
}

/**
  * @brief  Get FIFOx(0/1) full level.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Index (between Min_Data=0 and Max_Data=64).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxFullLevel(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0S) + OFFSET_TAB_RXFIFOx[Fifo]));
  return READ_BIT(*pReg, FDCAN_RXF0S_F0FL);
}

/**
  * @brief  Set FIFOx(0/1) acknowledge index.
  * @param  FDCANx FDCAN instance
  * @param  Index between Min_Data=0 and Max_Data=63.
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFOxAckIndex(FDCAN_TypeDef *FDCANx, uint32_t Index, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0A) + OFFSET_TAB_RXFIFOx[Fifo]));
  MODIFY_REG(*pReg, FDCAN_RXF0A_F0AI, Index << FDCAN_RXF0A_F0AI_Pos);
}

/**
  * @brief  Get FIFOx(0/1) acknowledge index.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @retval Index (between Min_Data=0 and Max_Data=63).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFOxAckIndex(FDCAN_TypeDef *FDCANx, uint32_t Fifo)
{
  __IO uint32_t *pReg = (__IO uint32_t *)((uint32_t)((uint32_t)&(FDCANx->RXF0A) + OFFSET_TAB_RXFIFOx[Fifo]));
  return READ_BIT(*pReg, FDCAN_RXF0A_F0AI);
}

/**
  * @brief  Set Rx buffer start address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  FDCANx FDCAN instance
  * @param  Address between Min_Data=0 and Max_Data=0xFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxBufferAddress(FDCAN_TypeDef *FDCANx, uint32_t Address)
{
  MODIFY_REG(FDCANx->RXBC, FDCAN_RXBC_RBSA, Address & DDL_FDCAN_ADDRESS_MASK);
}

/**
  * @brief  Get Rx buffer start address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  FDCANx FDCAN instance
  * @retval Address (between Min_Data=0 and Max_Data=0xFFFF).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxBufferAddress(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->RXBC, FDCAN_RXBC_RBSA);
}

/**
  * @brief  Set Rx buffer start address.
  * @param  FDCANx FDCAN instance
  * @param  FiledSize This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxBufferFiledSize(FDCAN_TypeDef *FDCANx, uint32_t FiledSize)
{
  MODIFY_REG(FDCANx->RXESC, FDCAN_RXESC_RBDS, (DDL_FDCAN_ELTSIZE_TO_ESC(FiledSize) << FDCAN_RXESC_RBDS_Pos));
}

/**
  * @brief  Get Rx buffer start address.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxBufferFiledSize(FDCAN_TypeDef *FDCANx)
{
  return DDL_FDCAN_ESC_TO_ELTSIZE(READ_BIT(FDCANx->RXESC, FDCAN_RXESC_RBDS) >> FDCAN_RXESC_RBDS_Pos);
}

/**
  * @brief  Set Rx FIFO 0 filed size.
  * @param  FDCANx FDCAN instance
  * @param  FiledSize This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFO0FiledSize(FDCAN_TypeDef *FDCANx, uint32_t FiledSize)
{
  MODIFY_REG(FDCANx->RXESC, FDCAN_RXESC_F0DS, DDL_FDCAN_ELTSIZE_TO_ESC(FiledSize));
}

/**
  * @brief  Get Rx FIFO 0 filed size.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFO0FiledSize(FDCAN_TypeDef *FDCANx)
{
  return DDL_FDCAN_ESC_TO_ELTSIZE(READ_BIT(FDCANx->RXESC, FDCAN_RXESC_F0DS));
}

/**
  * @brief  Set Rx FIFO 1 filed size.
  * @param  FDCANx FDCAN instance
  * @param  FiledSize This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetRxFIFO1FiledSize(FDCAN_TypeDef *FDCANx, uint32_t FiledSize)
{
  MODIFY_REG(FDCANx->RXESC, FDCAN_RXESC_F1DS, (DDL_FDCAN_ELTSIZE_TO_ESC(FiledSize) << FDCAN_RXESC_F1DS_Pos));
}

/**
  * @brief  Get Rx FIFO 1 filed size.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetRxFIFO1FiledSize(FDCAN_TypeDef *FDCANx)
{
  return DDL_FDCAN_ESC_TO_ELTSIZE(READ_BIT(FDCANx->RXESC, FDCAN_RXESC_F1DS) >> FDCAN_RXESC_F1DS_Pos);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_Transmit_Management Transmit_Management
  * @{
  */

/**
  * @brief  Set Tx operation mode.
  * @param  FDCANx FDCAN instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_TXMODE_FIFO
  *         @arg @ref DDL_FDCAN_TXMODE_QUEUE
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxOperationMode(FDCAN_TypeDef *FDCANx, uint32_t Mode)
{
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_TFQM, Mode);
}

/**
  * @brief  Get Tx operation mode.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_TXMODE_FIFO
  *         @arg @ref DDL_FDCAN_TXMODE_QUEUE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxOperationMode(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXBC, FDCAN_TXBC_TFQM);
}

/**
  * @brief  Set Transmit FIFO/Queue Size.
  * @note   Values greater than 32 are interpreted as 32
  * @param  FDCANx FDCAN instance
  * @param  Size between Min_Data=0 and Max_Data=32.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxFifoQueueSize(FDCAN_TypeDef *FDCANx, uint32_t Size)
{
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_TFQS, (Size << FDCAN_TXBC_TFQS_Pos));
}

/**
  * @brief  Get Transmit FIFO/Queue Size.
  * @note   Values greater than 32 are interpreted as 32
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=32).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxFifoQueueSize(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXBC, FDCAN_TXBC_TFQS) >> FDCAN_TXBC_TFQS_Pos);
}

/**
  * @brief  Set Transmit Dedicated Buffer Size.
  * @note   Values greater than 32 are interpreted as 32
  * @param  FDCANx FDCAN instance
  * @param  Size between Min_Data=0 and Max_Data=32.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxDBufferSize(FDCAN_TypeDef *FDCANx, uint32_t Size)
{
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_NDTB, (Size << FDCAN_TXBC_NDTB_Pos));
}

/**
  * @brief  Get Transmit Dedicated Buffer Size.
  * @note   Values greater than 32 are interpreted as 32
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=32).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxDBufferSize(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXBC, FDCAN_TXBC_NDTB) >> FDCAN_TXBC_NDTB_Pos);
}

/**
  * @brief  Set Tx Buffers Start Address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  FDCANx FDCAN instance
  * @param  Address between Min_Data=0 and Max_Data=0xFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxBufferAddress(FDCAN_TypeDef *FDCANx, uint32_t Address)
{
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_TBSA, Address & DDL_FDCAN_ADDRESS_MASK);
}

/**
  * @brief  Get Tx Buffers Start Address.
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=0xFFFF).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxBufferAddress(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXBC, FDCAN_TXBC_TBSA);
}

/**
  * @brief  Check Tx FIFO/Queue Full flag is set or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TFQF(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXFQS, FDCAN_TXFQS_TFQF) == FDCAN_TXFQS_TFQF);
}

/**
  * @brief  Get Tx FIFO Put Index.
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=31).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxFIFOPutIndex(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXFQS, FDCAN_TXFQS_TFQPI) >> FDCAN_TXFQS_TFQPI_Pos);
}

/**
  * @brief  Get Tx FIFO Get Index.
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=31).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxFIFOGetIndex(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXFQS, FDCAN_TXFQS_TFGI) >> FDCAN_TXFQS_TFGI_Pos);
}

/**
  * @brief  Get Tx FIFO Free Level.
  * @param  FDCANx FDCAN instance
  * @retval FreeLevel (between Min_Data=0 and Max_Data=32).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxFIFOFreeLevel(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXFQS, FDCAN_TXFQS_TFFL);
}

/**
  * @brief  Set Tx Buffer filed size.
  * @param  FDCANx FDCAN instance
  * @param  Fifo This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxBufferFiledSize(FDCAN_TypeDef *FDCANx, uint32_t FiledSize)
{
  MODIFY_REG(FDCANx->TXESC, FDCAN_TXESC_TBDS, DDL_FDCAN_ELTSIZE_TO_ESC(FiledSize));
}

/**
  * @brief  Get Tx Buffer filed size.
  * @param  FDCANx FDCAN instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FDCAN_FILEDSIZE_8BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_12BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_16BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_20BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_24BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_32BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_48BYTE
  *         @arg @ref DDL_FDCAN_FILEDSIZE_64BYTE
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxBufferFiledSize(FDCAN_TypeDef *FDCANx)
{
  return DDL_FDCAN_ESC_TO_ELTSIZE(READ_BIT(FDCANx->TXESC, FDCAN_TXESC_TBDS));
}

/**
  * @brief  Get Transmission Request Pending.
  * @param  FDCANx FDCAN instance
  * @param  PendingBit can be one of the following values:
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT0
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT1
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT2
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT3
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT4
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT5
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT6
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT7
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT8
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT9
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT10
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT11
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT12
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT13
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT14
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT15
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT16
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT17
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT18
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT19
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT20
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT21
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT22
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT23
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT24
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT25
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT26
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT27
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT28
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT29
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT30
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT31
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TRP(FDCAN_TypeDef *FDCANx, uint32_t PendingBit)
{
  return READ_BIT(FDCANx->TXBRP, PendingBit) == (PendingBit);
}

/**
  * @brief  Get Any Transmission Request Pending.
  * @param  FDCANx FDCAN instance
  * @param  PendingBit between Min_Data=0 and Max_Data=31.
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsAnyActiveFlag_TRP(FDCAN_TypeDef *FDCANx)
{
  return READ_REG(FDCANx->TXBRP) == 0 ? 0 : 1;
}

/**
  * @brief  Enable Transmission Request.
  * @param  FDCANx FDCAN instance
  * @param  RequestBit can be one of the following values:
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT0
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT1
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT2
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT3
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT4
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT5
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT6
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT7
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT8
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT9
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT10
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT11
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT12
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT13
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT14
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT15
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT16
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT17
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT18
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT19
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT20
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT21
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT22
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT23
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT24
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT25
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT26
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT27
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT28
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT29
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT30
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT31
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableTxRequest(FDCAN_TypeDef *FDCANx, uint32_t RequestBit)
{
  SET_BIT(FDCANx->TXBAR, RequestBit);
}

/**
  * @brief  Enable Transmission CancelRequest.
  * @param  FDCANx FDCAN instance
  * @param  RequestBit can be one of the following values:
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT0
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT1
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT2
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT3
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT4
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT5
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT6
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT7
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT8
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT9
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT10
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT11
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT12
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT13
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT14
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT15
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT16
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT17
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT18
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT19
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT20
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT21
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT22
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT23
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT24
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT25
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT26
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT27
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT28
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT29
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT30
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT31
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableTxCancelRequest(FDCAN_TypeDef *FDCANx, uint32_t RequestBit)
{
  SET_BIT(FDCANx->TXBCR, RequestBit);
}

/**
  * @brief  Get Transmission Occurred.
  * @param  FDCANx FDCAN instance
  * @param  OccurredBit can be one of the following values:
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT0
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT1
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT2
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT3
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT4
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT5
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT6
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT7
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT8
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT9
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT10
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT11
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT12
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT13
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT14
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT15
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT16
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT17
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT18
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT19
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT20
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT21
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT22
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT23
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT24
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT25
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT26
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT27
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT28
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT29
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT30
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT31
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TO(FDCAN_TypeDef *FDCANx, uint32_t OccurredBit)
{
  return READ_BIT(FDCANx->TXBTO, OccurredBit) == (OccurredBit);
}

/**
  * @brief  Get Transmission Cancellation Finished.
  * @param  FDCANx FDCAN instance
  * @param  CancelFinishBit can be one of the following values:
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT0
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT1
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT2
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT3
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT4
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT5
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT6
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT7
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT8
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT9
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT10
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT11
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT12
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT13
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT14
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT15
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT16
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT17
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT18
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT19
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT20
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT21
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT22
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT23
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT24
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT25
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT26
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT27
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT28
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT29
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT30
  *         @arg @ref DDL_FDCAN_BIT_MASK_BIT31
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TXBCF(FDCAN_TypeDef *FDCANx, uint32_t CancelFinishBit)
{
  return READ_BIT(FDCANx->TXBCF, CancelFinishBit) == (CancelFinishBit);
}

/**
  * @brief  Enable Tx Buffer Transmission Interrupt.
  * @param  FDCANx FDCAN instance
  * @param  buffer between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TXBT(FDCAN_TypeDef *FDCANx, uint32_t buffer)
{
  SET_BIT(FDCANx->TXBTIE, buffer);
}

/**
  * @brief  Disable Tx Buffer Transmission Interrupt.
  * @param  FDCANx FDCAN instance
  * @param  buffer between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TXBT(FDCAN_TypeDef *FDCANx, uint32_t buffer)
{
  CLEAR_BIT(FDCANx->TXBTIE, buffer);
}

/**
  * @brief  Check Tx Buffer Transmission Interrupt is enabled or disabled.
  * @param  FDCANx FDCAN instance
  * @param  buffer between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TXBT(FDCAN_TypeDef *FDCANx, uint32_t buffer)
{
  return (READ_BIT(FDCANx->TXBTIE, buffer) == buffer);
}

/**
  * @brief  Enable Tx Buffer Cancellation Finished Interrupt.
  * @param  FDCANx FDCAN instance
  * @param  buffer between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TXBC(FDCAN_TypeDef *FDCANx, uint32_t buffer)
{
  SET_BIT(FDCANx->TXBCIE, buffer);
}

/**
  * @brief  Disable Tx Buffer Cancellation Finished Interrupt.
  * @param  FDCANx FDCAN instance
  * @param  buffer between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TXBC(FDCAN_TypeDef *FDCANx, uint32_t buffer)
{
  CLEAR_BIT(FDCANx->TXBCIE, buffer);
}

/**
  * @brief  Check Tx Buffer Cancellation Finished Interrupt is enabled or disabled.
  * @param  FDCANx FDCAN instance
  * @param  buffer between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TXBC(FDCAN_TypeDef *FDCANx, uint32_t buffer)
{
  return (READ_BIT(FDCANx->TXBCIE, buffer) == buffer);
}

/**
  * @brief  Set Tx Event FIFO Watermark.
  * @param  FDCANx FDCAN instance
  * @param  Watermark between Min_Data=0 and Max_Data=32.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOWatermark(FDCAN_TypeDef *FDCANx, uint32_t Watermark)
{
  MODIFY_REG(FDCANx->TXEFC, FDCAN_TXEFC_EFWM, (Watermark << FDCAN_TXEFC_EFWM_Pos));
}

/**
  * @brief  Get Tx Event FIFO Watermark.
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=32).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOWatermark(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXEFC, FDCAN_TXEFC_EFWM) >> FDCAN_TXEFC_EFWM_Pos);
}

/**
  * @brief  Set Tx Event FIFO Size.
  * @param  FDCANx FDCAN instance
  * @param  Size between Min_Data=0 and Max_Data=32.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOSize(FDCAN_TypeDef *FDCANx, uint32_t Size)
{
  MODIFY_REG(FDCANx->TXEFC, FDCAN_TXEFC_EFS, (Size << FDCAN_TXEFC_EFS_Pos));
}

/**
  * @brief  Get Tx Event FIFO Size.
  * @param  FDCANx FDCAN instance
  * @retval Size (between Min_Data=0 and Max_Data=32).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOSize(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXEFC, FDCAN_TXEFC_EFS) >> FDCAN_TXEFC_EFS_Pos);
}

/**
  * @brief  Set Tx Event FIFO Address.
  * @note   Since addressing is performed in 32-bit words and the width of this bit field is 16 bits,
  *         the configurable start address is a 16-bit word address. In other words,
  *         only bit positions 2 to 15 of the address will be evaluated, and the lowest two bits will be ignored.
  * @param  FDCANx FDCAN instance
  * @param  Address between Min_Data=0 and Max_Data=0xFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOAddress(FDCAN_TypeDef *FDCANx, uint32_t Address)
{
  MODIFY_REG(FDCANx->TXEFC, FDCAN_TXEFC_EFSA, Address & DDL_FDCAN_ADDRESS_MASK);
}

/**
  * @brief  Get Tx Event FIFO Address.
  * @param  FDCANx FDCAN instance
  * @retval Address (between Min_Data=0 and Max_Data=0xFFFF).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOAddress(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXEFC, FDCAN_TXEFC_EFSA);
}

/**
  * @brief  Check Tx Event FIFO element lost flag is set or not.
  * @note   This flag is a copy of interrupt flag IR.TEFL.
  * @param  FDCANx FDCAN instance
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TXEFL(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXEFS, FDCAN_TXEFS_TEFL) == FDCAN_TXEFS_TEFL);
}

/**
  * @brief  Check Tx Event FIFO Full flag is set or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit(0 or 1).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_EFF(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->TXEFS, FDCAN_TXEFS_EFF) == FDCAN_TXEFS_EFF);
}

/**
  * @brief  Set Tx Event FIFO Put Index.
  * @param  FDCANx FDCAN instance
  * @param  PutIndex between Min_Data=0 and Max_Data=31.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOPutIndex(FDCAN_TypeDef *FDCANx, uint32_t PutIndex)
{
  MODIFY_REG(FDCANx->TXEFS, FDCAN_TXEFS_EFPI, (PutIndex << FDCAN_TXEFS_EFPI_Pos));
}

/**
  * @brief  Get Tx Event FIFO Put Index.
  * @param  FDCANx FDCAN instance
  * @retval PutIndex (between Min_Data=0 and Max_Data=31).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOPutIndex(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXEFS, FDCAN_TXEFS_EFPI) >> FDCAN_TXEFS_EFPI_Pos;
}

/**
  * @brief  Set Tx Event FIFO Get Index.
  * @param  FDCANx FDCAN instance
  * @param  GetIndex between Min_Data=0 and Max_Data=31.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOGetIndex(FDCAN_TypeDef *FDCANx, uint32_t GetIndex)
{
  MODIFY_REG(FDCANx->TXEFS, FDCAN_TXEFS_EFGI, (GetIndex << FDCAN_TXEFS_EFGI_Pos));
}

/**
  * @brief  Get Tx Event FIFO Get Index.
  * @param  FDCANx FDCAN instance
  * @retval GetIndex (between Min_Data=0 and Max_Data=31).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOGetIndex(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXEFS, FDCAN_TXEFS_EFGI) >> FDCAN_TXEFS_EFGI_Pos;
}

/**
  * @brief  Set Tx Event FIFO Fill Level.
  * @param  FDCANx FDCAN instance
  * @param  FillLevel between Min_Data=0 and Max_Data=32.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOFillLevel(FDCAN_TypeDef *FDCANx, uint32_t FillLevel)
{
  MODIFY_REG(FDCANx->TXEFS, FDCAN_TXEFS_EFFL, FillLevel);
}

/**
  * @brief  Get Tx Event FIFO Fill Level.
  * @param  FDCANx FDCAN instance
  * @retval FillLevel (between Min_Data=0 and Max_Data=32).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOFillLevel(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXEFS, FDCAN_TXEFS_EFFL);
}

/**
  * @brief  Set Tx Event FIFO Acknowledge Index.
  * @param  FDCANx FDCAN instance
  * @param  AckIndex between Min_Data=0 and Max_Data=31.
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetTxEventFIFOAckIndex(FDCAN_TypeDef *FDCANx, uint32_t AckIndex)
{
  MODIFY_REG(FDCANx->TXEFA, FDCAN_TXEFA_EFAI, AckIndex);
}

/**
  * @brief  Get Tx Event FIFO Acknowledge Index.
  * @param  FDCANx FDCAN instance
  * @retval AckIndex (between Min_Data=0 and Max_Data=31).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetTxEventFIFOAckIndex(FDCAN_TypeDef *FDCANx)
{
  return READ_BIT(FDCANx->TXEFA, FDCAN_TXEFA_EFAI);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get protocol status.
  * @param  FDCANx FDCAN instance
  * @retval Status Protocol status register.
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetProtocolStatus(FDCAN_TypeDef *FDCANx)
{
  return READ_REG(FDCANx->PSR);
}

/**
  * @brief  Check if the clock stop acknowledge is accessed or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_CSA(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->CCCR, FDCAN_CCCR_CSA) == (FDCAN_CCCR_CSA));
}

/**
  * @brief  Check if the reserved address is accessed or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_ARA(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_ARA) == (FDCAN_IR_ARA));
}

/**
  * @brief  Check if the protocol error in data phase is detected or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_PED(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_PED) == (FDCAN_IR_PED));
}

/**
  * @brief  Check if the protocol error in arbitration phase is detected or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_PEA(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_PEA) == (FDCAN_IR_PEA));
}

/**
  * @brief  Check if the Message RAM Watchdog event is occurred or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_WDI(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_WDI) == (FDCAN_IR_WDI));
}

/**
  * @brief  Check if the bus off status is changed or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_BO(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_BO) == (FDCAN_IR_BO));
}

/**
  * @brief  Check if the error warning status is changed or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_EW(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_EW) == (FDCAN_IR_EW));
}

/**
  * @brief  Check if the error passive status is changed or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_EP(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_EP) == (FDCAN_IR_EP));
}

/**
  * @brief  Check if the error logging counter is overflow or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_ELO(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_ELO) == (FDCAN_IR_ELO));
}

/**
  * @brief  Check if the Rx Buffer is updated or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_DRX(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_DRX) == (FDCAN_IR_DRX));
}

/**
  * @brief  Check if the time out is reached or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TOO(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TOO) == (FDCAN_IR_TOO));
}

/**
  * @brief  Check if the message RAM access failure is occurred or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_MRAF(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_MRAF) == (FDCAN_IR_MRAF));
}

/**
  * @brief  Check if the timestamp counter is wrapped around or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TSW(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TSW) == (FDCAN_IR_TSW));
}

/**
  * @brief  Check if the Tx Event FIFO element is losted or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TEFL(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TEFL) == (FDCAN_IR_TEFL));
}

/**
  * @brief  Check if the Tx Event FIFO element is fulled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TEFF(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TEFF) == (FDCAN_IR_TEFF));
}

/**
  * @brief  Check if the Tx Event FIFO fill level is reached watermark or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TEFW(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TEFW) == (FDCAN_IR_TEFW));
}

/**
  * @brief  Check if the Tx event FIFO element is wrote by Tx handler or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TEFN(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TEFN) == (FDCAN_IR_TEFN));
}

/**
  * @brief  Check if the Tx FIFO is empty or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TFE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TFE) == (FDCAN_IR_TFE));
}

/**
  * @brief  Check if the transmission cancellation is finished or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TCF(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TCF) == (FDCAN_IR_TCF));
}

/**
  * @brief  Check if the transmission is completed or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_TC(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_TC) == (FDCAN_IR_TC));
}

/**
  * @brief  Check if the high priority message is received or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_HPM(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_HPM) == (FDCAN_IR_HPM));
}

/**
  * @brief  Check if the Rx FIFO 1 message is losted or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF1L(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF1L) == (FDCAN_IR_RF1L));
}

/**
  * @brief  Check if the Rx FIFO 1 is fulled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF1F(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF1F) == (FDCAN_IR_RF1F));
}

/**
  * @brief  Check if the Rx FIFO 1 fill level is reached watermark or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF1W(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF1W) == (FDCAN_IR_RF1W));
}

/**
  * @brief  Check if the New message written to Rx FIFO 1 or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF1N(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF1N) == (FDCAN_IR_RF1N));
}

/**
  * @brief  Check if the Rx FIFO 0 message is losted or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF0L(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF0L) == (FDCAN_IR_RF0L));
}

/**
  * @brief  Check if the Rx FIFO 0 is fulled or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF0F(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF0F) == (FDCAN_IR_RF0F));
}

/**
  * @brief  Check if the Rx FIFO 0 fill level is reached watermark or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF0W(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF0W) == (FDCAN_IR_RF0W));
}

/**
  * @brief  Check if the New message written to Rx FIFO 0 or not.
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsActiveFlag_RF0N(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IR, FDCAN_IR_RF0N) == (FDCAN_IR_RF0N));
}

/**
  * @brief  Clear Access to Reserved Address Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_ARA(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_ARA);
}

/**
  * @brief  Clear Protocol Error in Data Phase Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_PED(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_PED);
}

/**
  * @brief  Clear Protocol Error in Arbitration Phase Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_PEA(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_PEA);
}

/**
  * @brief  Clear Watchdog Interrupt Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_WDI(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_WDI);
}

/**
  * @brief  Clear Bus_Off status changed Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_BO(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_BO);
}

/**
  * @brief  Clear Error_Warning status changed Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_EW(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_EW);
}

/**
  * @brief  Clear Error_Passive status changed Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_EP(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_EP);
}

/**
  * @brief  Clear Overflow of CAN Error Logging Counter occurred Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_ELO(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_ELO);
}

/**
  * @brief  Clear Rx Buffer updated Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_DRX(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_DRX);
}

/**
  * @brief  Clear Timeout reached Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TOO(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TOO);
}

/**
  * @brief  Clear Message RAM access failure occurred Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_MRAF(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_MRAF);
}

/**
  * @brief  Clear Timestamp counter wrapped around Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TSW(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TSW);
}

/**
  * @brief  Clear Tx Event FIFO element lost Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TEFL(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TEFL);
}

/**
  * @brief  Clear Tx Event FIFO full Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TEFF(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TEFF);
}

/**
  * @brief  Clear Tx Event FIFO fill level reached watermark Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TEFW(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TEFW);
}

/**
  * @brief  Clear Tx Handler wrote Tx Event FIFO element Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TEFN(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TEFN);
}

/**
  * @brief  Clear Tx FIFO empty Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TFE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TFE);
}

/**
  * @brief  Clear Transmission cancellation finished Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TCF(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TCF);
}

/**
  * @brief  Clear Transmission completed Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_TC(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_TC);
}

/**
  * @brief  Clear High priority message received Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_HPM(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_HPM);
}

/**
  * @brief  Clear Rx FIFO 1 message lost Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF1L(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF1L);
}

/**
  * @brief  Clear Rx FIFO 1 message full Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF1F(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF1F);
}

/**
  * @brief  Clear Rx FIFO 1 fill level reached watermark Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF1W(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF1W);
}

/**
  * @brief  Clear New message written to Rx FIFO 1 Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF1N(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF1N);
}

/**
  * @brief  Clear Rx FIFO 0 message lost Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF0L(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF0L);
}

/**
  * @brief  Clear Rx FIFO 0 message full Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF0F(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF0F);
}

/**
  * @brief  Clear Rx FIFO 0 fill level reached watermark Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF0W(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF0W);
}

/**
  * @brief  Clear New message written to Rx FIFO 0 Flag
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_ClearFlag_RF0N(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IR, FDCAN_IR_RF0N);
}

/**
  * @}
  */

/** @defgroup FDCAN_DDL_EF_INTERRUPT_Management INTERRUPT_Management
  * @{
  */

/**
  * @brief  Set FDCAN interrupt line select.
  * @param  FDCANx FDCAN instance
  * @param  interrupt This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_IT_ARA
  *         @arg @ref DDL_FDCAN_IT_PED
  *         @arg @ref DDL_FDCAN_IT_PEA
  *         @arg @ref DDL_FDCAN_IT_WDI
  *         @arg @ref DDL_FDCAN_IT_BO
  *         @arg @ref DDL_FDCAN_IT_EW
  *         @arg @ref DDL_FDCAN_IT_EP
  *         @arg @ref DDL_FDCAN_IT_ELO
  *         @arg @ref DDL_FDCAN_IT_DRX
  *         @arg @ref DDL_FDCAN_IT_TOO
  *         @arg @ref DDL_FDCAN_IT_MRAF
  *         @arg @ref DDL_FDCAN_IT_TSW
  *         @arg @ref DDL_FDCAN_IT_TEFL
  *         @arg @ref DDL_FDCAN_IT_TEFF
  *         @arg @ref DDL_FDCAN_IT_TEFW
  *         @arg @ref DDL_FDCAN_IT_TEFN
  *         @arg @ref DDL_FDCAN_IT_TFE
  *         @arg @ref DDL_FDCAN_IT_TCF
  *         @arg @ref DDL_FDCAN_IT_TC
  *         @arg @ref DDL_FDCAN_IT_HPM
  *         @arg @ref DDL_FDCAN_IT_RF1L
  *         @arg @ref DDL_FDCAN_IT_RF1F
  *         @arg @ref DDL_FDCAN_IT_RF1W
  *         @arg @ref DDL_FDCAN_IT_RF1N
  *         @arg @ref DDL_FDCAN_IT_RF0L
  *         @arg @ref DDL_FDCAN_IT_RF0F
  *         @arg @ref DDL_FDCAN_IT_RF0W
  *         @arg @ref DDL_FDCAN_IT_RF0N
  * @param  line This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_IT_LINE0
  *         @arg @ref DDL_FDCAN_IT_LINE1
  * @retval None.
  */
__STATIC_INLINE void DDL_FDCAN_SetITLines(FDCAN_TypeDef *FDCANx, uint32_t interrupts, uint32_t line)
{
  MODIFY_REG(FDCANx->ILS, (DDL_FDCAN_IT_MASK & interrupts), (interrupts * line));
}

/**
  * @brief  Get FDCAN interrupt line select.
  * @param  FDCANx FDCAN instance
  * @param  interrupt This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_IT_ARA
  *         @arg @ref DDL_FDCAN_IT_PED
  *         @arg @ref DDL_FDCAN_IT_PEA
  *         @arg @ref DDL_FDCAN_IT_WDI
  *         @arg @ref DDL_FDCAN_IT_BO
  *         @arg @ref DDL_FDCAN_IT_EW
  *         @arg @ref DDL_FDCAN_IT_EP
  *         @arg @ref DDL_FDCAN_IT_ELO
  *         @arg @ref DDL_FDCAN_IT_DRX
  *         @arg @ref DDL_FDCAN_IT_TOO
  *         @arg @ref DDL_FDCAN_IT_MRAF
  *         @arg @ref DDL_FDCAN_IT_TSW
  *         @arg @ref DDL_FDCAN_IT_TEFL
  *         @arg @ref DDL_FDCAN_IT_TEFF
  *         @arg @ref DDL_FDCAN_IT_TEFW
  *         @arg @ref DDL_FDCAN_IT_TEFN
  *         @arg @ref DDL_FDCAN_IT_TFE
  *         @arg @ref DDL_FDCAN_IT_TCF
  *         @arg @ref DDL_FDCAN_IT_TC
  *         @arg @ref DDL_FDCAN_IT_HPM
  *         @arg @ref DDL_FDCAN_IT_RF1L
  *         @arg @ref DDL_FDCAN_IT_RF1F
  *         @arg @ref DDL_FDCAN_IT_RF1W
  *         @arg @ref DDL_FDCAN_IT_RF1N
  *         @arg @ref DDL_FDCAN_IT_RF0L
  *         @arg @ref DDL_FDCAN_IT_RF0F
  *         @arg @ref DDL_FDCAN_IT_RF0W
  *         @arg @ref DDL_FDCAN_IT_RF0N
  * @retval value can be one of the following:
  *         @arg @ref DDL_FDCAN_IT_LINE0
  *         @arg @ref DDL_FDCAN_IT_LINE1
  */
__STATIC_INLINE uint32_t DDL_FDCAN_GetITLines(FDCAN_TypeDef *FDCANx, uint32_t interrupts)
{
  return (READ_BIT(FDCANx->ILS, (DDL_FDCAN_IT_MASK & interrupts)) == interrupts) ? DDL_FDCAN_IT_LINE1 : DDL_FDCAN_IT_LINE0;
}

/**
  * @brief  Enable Interrupt line.
  * @param  FDCANx FDCAN instance
  * @param  lines This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_EINT_LINE0
  *         @arg @ref DDL_FDCAN_EINT_LINE1
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableITLines(FDCAN_TypeDef *FDCANx, uint32_t lines)
{
  SET_BIT(FDCANx->ILE, lines);
}

/**
  * @brief  Disable Interrupt line.
  * @param  FDCANx FDCAN instance
  * @param  lines This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_EINT_LINE0
  *         @arg @ref DDL_FDCAN_EINT_LINE1
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableITLines(FDCAN_TypeDef *FDCANx, uint32_t lines)
{
  CLEAR_BIT(FDCANx->ILE, lines);
}

/**
  * @brief  Check the Interrupt line is enabled or disabled.
  * @param  FDCANx FDCAN instance
  * @param  lines This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_EINT_LINE0
  *         @arg @ref DDL_FDCAN_EINT_LINE1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledITLines(FDCAN_TypeDef *FDCANx, uint32_t lines)
{
  return (READ_BIT(FDCANx->ILE, lines) == lines);
}

/**
  * @brief  Enable Access to Reserved Address Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_ARAE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_ARAE);
}

/**
  * @brief  Disable Access to Reserved Address Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_ARAE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_ARAE);
}

/**
  * @brief  Check if the Access to Reserved Address Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_ARAE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_ARAE) == FDCAN_IE_ARAE);
}

/**
  * @brief  Enable Protocol Error in Data Phase Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_PEDE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_PEDE);
}

/**
  * @brief  Disable Protocol Error in Data Phase Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_PEDE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_PEDE);
}

/**
  * @brief  Check if the Protocol Error in Data Phase Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_PEDE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_PEDE) == FDCAN_IE_PEDE);
}

/**
  * @brief  Enable Protocol Error in Arbitration Phase Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_PEAE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_PEAE);
}

/**
  * @brief  Disable Protocol Error in Arbitration Phase Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_PEAE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_PEAE);
}

/**
  * @brief  Check if the Protocol Error in Arbitration Phase Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_PEAE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_PEAE) == FDCAN_IE_PEAE);
}

/**
  * @brief  Enable Watchdog Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_WDIE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_WDIE);
}

/**
  * @brief  Disable Watchdog Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_WDIE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_WDIE);
}

/**
  * @brief  Check if the Watchdog Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_WDIE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_WDIE) == FDCAN_IE_WDIE);
}

/**
  * @brief  Enable Bus_Off Status Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_BOE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_BOE);
}

/**
  * @brief  Disable Bus_Off Status Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_BOE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_BOE);
}

/**
  * @brief  Check if the Bus_Off Status Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_BOE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_BOE) == FDCAN_IE_BOE);
}

/**
  * @brief  Enable Warning Status Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_EWE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_EWE);
}

/**
  * @brief  Disable Warning Status Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_EWE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_EWE);
}

/**
  * @brief  Check if the Warning Status Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_EWE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_EWE) == FDCAN_IE_EWE);
}

/**
  * @brief  Enable Error Passive Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_EPE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_EPE);
}

/**
  * @brief  Disable Error Passive Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_EPE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_EPE);
}

/**
  * @brief  Check if the Error Passive Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_EPE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_EPE) == FDCAN_IE_EPE);
}

/**
  * @brief  Enable Error Logging Overflow Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_ELOE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_ELOE);
}

/**
  * @brief  Disable Error Logging Overflow Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_ELOE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_ELOE);
}

/**
  * @brief  Check if the Error Logging Overflow Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_ELOE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_ELOE) == FDCAN_IE_ELOE);
}

/**
  * @brief  Enable Message stored to Dedicated Rx Buffer Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_DRXE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_DRXE);
}

/**
  * @brief  Disable Message stored to Dedicated Rx Buffer Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_DRXE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_DRXE);
}

/**
  * @brief  Check if the Message stored to Dedicated Rx Buffer Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_DRXE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_DRXE) == FDCAN_IE_DRXE);
}

/**
  * @brief  Enable Timeout Occurred Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TOOE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TOOE);
}

/**
  * @brief  Disable Timeout Occurred Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TOOE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TOOE);
}

/**
  * @brief  Check if the Timeout Occurred Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TOOE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TOOE) == FDCAN_IE_TOOE);
}

/**
  * @brief  Enable Message RAM Access Failure Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_MRAFE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_MRAFE);
}

/**
  * @brief  Disable Message RAM Access Failure Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_MRAFE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_MRAFE);
}

/**
  * @brief  Check if the Message RAM Access Failure Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_MRAFE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_MRAFE) == FDCAN_IE_MRAFE);
}

/**
  * @brief  Enable Timestamp Wraparound Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TSWE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TSWE);
}

/**
  * @brief  Disable Timestamp Wraparound Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TSWE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TSWE);
}

/**
  * @brief  Check if the Timestamp Wraparound Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TSWE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TSWE) == FDCAN_IE_TSWE);
}

/**
  * @brief  Enable Tx Event FIFO Event Lost Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TEFLE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TEFLE);
}

/**
  * @brief  Disable Tx Event FIFO Event Lost Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TEFLE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TEFLE);
}

/**
  * @brief  Check if the Tx Event FIFO Event Lost Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TEFLE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TEFLE) == FDCAN_IE_TEFLE);
}

/**
  * @brief  Enable Tx Event FIFO Full Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TEFFE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TEFFE);
}

/**
  * @brief  Disable Tx Event FIFO Full Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TEFFE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TEFFE);
}

/**
  * @brief  Check if the Tx Event FIFO Full Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TEFFE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TEFFE) == FDCAN_IE_TEFFE);
}

/**
  * @brief  Enable Tx Event FIFO Watermark Reached Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TEFWE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TEFWE);
}

/**
  * @brief  Disable Tx Event FIFO Watermark Reached Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TEFWE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TEFWE);
}

/**
  * @brief  Check if the Tx Event FIFO Watermark Reached Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TEFWE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TEFWE) == FDCAN_IE_TEFWE);
}

/**
  * @brief  Enable Tx Event FIFO New Entry Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TEFNE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TEFNE);
}

/**
  * @brief  Disable Tx Event FIFO New Entry Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TEFNE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TEFNE);
}

/**
  * @brief  Check if the Tx Event FIFO New Entry Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TEFNE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TEFNE) == FDCAN_IE_TEFNE);
}

/**
  * @brief  Enable Tx FIFO Empty Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TFEE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TFEE);
}

/**
  * @brief  Disable Tx FIFO Empty Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TFEE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TFEE);
}

/**
  * @brief  Check if the Tx FIFO Empty Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TFEE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TFEE) == FDCAN_IE_TFEE);
}

/**
  * @brief  Enable Transmission Cancellation Finished Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TCFE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TCFE);
}

/**
  * @brief  Disable Transmission Cancellation Finished Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TCFE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TCFE);
}

/**
  * @brief  Check if the Transmission Cancellation Finished Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TCFE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TCFE) == FDCAN_IE_TCFE);
}

/**
  * @brief  Enable Transmission Completed Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_TCE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_TCE);
}

/**
  * @brief  Disable Transmission Completed Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_TCE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_TCE);
}

/**
  * @brief  Check if the Transmission Completed Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_TCE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_TCE) == FDCAN_IE_TCE);
}

/**
  * @brief  Enable High Priority Message Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_HPME(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_HPME);
}

/**
  * @brief  Disable High Priority Message Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_HPME(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_HPME);
}

/**
  * @brief  Check if the High Priority Message Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_HPME(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_HPME) == FDCAN_IE_HPME);
}

/**
  * @brief  Enable Rx FIFO 1 Message Lost Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RF1LE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF1LE);
}

/**
  * @brief  Disable Rx FIFO 1 Message Lost Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RF1LE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF1LE);
}

/**
  * @brief  Check if the Rx FIFO 1 Message Lost Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RF1LE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF1LE) == FDCAN_IE_RF1LE);
}

/**
  * @brief  Enable Rx FIFO 1 Full Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RF1FE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF1FE);
}

/**
  * @brief  Disable Rx FIFO 1 Full Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RF1FE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF1FE);
}

/**
  * @brief  Check if the Rx FIFO 1 Full Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RF1FE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF1FE) == FDCAN_IE_RF1FE);
}

/**
  * @brief  Enable Rx FIFO 1 Watermark Reached Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RE1WE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF1WE);
}

/**
  * @brief  Disable Rx FIFO 1 Watermark Reached Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RE1WE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF1WE);
}

/**
  * @brief  Check if the Rx FIFO 1 Watermark Reached Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RE1WE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF1WE) == FDCAN_IE_RF1WE);
}

/**
  * @brief  Enable Rx FIFO 1 New Message Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RF1NE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF1NE);
}

/**
  * @brief  Disable Rx FIFO 1 New Message Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RF1NE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF1NE);
}

/**
  * @brief  Check if the Rx FIFO 1 New Message Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RF1NE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF1NE) == FDCAN_IE_RF1NE);
}

/**
  * @brief  Enable Rx FIFO 0 Message Lost Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RF0LE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF0LE);
}

/**
  * @brief  Disable Rx FIFO 0 Message Lost Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RF0LE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF0LE);
}

/**
  * @brief  Check if the Rx FIFO 0 Message Lost Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RF0LE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF0LE) == FDCAN_IE_RF0LE);
}

/**
  * @brief  Enable Rx FIFO 0 Full Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RF0FE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF0FE);
}

/**
  * @brief  Disable Rx FIFO 0 Full Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RF0FE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF0FE);
}

/**
  * @brief  Check if the Rx FIFO 0 Full Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RF0FE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF0FE) == FDCAN_IE_RF0FE);
}

/**
  * @brief  Enable Rx FIFO 0 Watermark Reached Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RE0WE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF0WE);
}

/**
  * @brief  Disable Rx FIFO 0 Watermark Reached Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RE0WE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF0WE);
}

/**
  * @brief  Check if the Rx FIFO 0 Watermark Reached Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RE0WE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF0WE) == FDCAN_IE_RF0WE);
}

/**
  * @brief  Enable Rx FIFO 0 New Message Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_EnableIT_RF0NE(FDCAN_TypeDef *FDCANx)
{
  SET_BIT(FDCANx->IE, FDCAN_IE_RF0NE);
}

/**
  * @brief  Disable Rx FIFO 0 New Message Interrupt
  * @param  FDCANx FDCAN instance
  * @retval None
  */
__STATIC_INLINE void DDL_FDCAN_DisableIT_RF0NE(FDCAN_TypeDef *FDCANx)
{
  CLEAR_BIT(FDCANx->IE, FDCAN_IE_RF0NE);
}

/**
  * @brief  Check if the Rx FIFO 0 New Message Interrupt is enabled or disabled
  * @param  FDCANx FDCAN instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FDCAN_IsEnabledIT_RF0NE(FDCAN_TypeDef *FDCANx)
{
  return (READ_BIT(FDCANx->IE, FDCAN_IE_RF0NE) == FDCAN_IE_RF0NE);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FDCAN_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_FDCAN_DeInit(FDCAN_TypeDef *FDCANx);
ErrorStatus DDL_FDCAN_Init(FDCAN_TypeDef *FDCANx, DDL_FDCAN_InitTypeDef *FDCAN_InitStruct);
void        DDL_FDCAN_StructInit(DDL_FDCAN_InitTypeDef *FDCAN_InitStruct);
ErrorStatus DDL_FDCAN_FilterInit(FDCAN_TypeDef *FDCANx, DDL_FDCAN_FilterTypeDef *FDCAN_FilterStruct);
void        DDL_FDCAN_FilterStructInit(DDL_FDCAN_FilterTypeDef *FDCAN_FilterStruct);
ErrorStatus DDL_FDCAN_RxMessage(FDCAN_TypeDef *FDCANx, uint32_t RxFifoNumber, DDL_FDCAN_RxMessageTypeDef *FDCAN_RxMessageStruct);
ErrorStatus DDL_FDCAN_TxMessage(FDCAN_TypeDef *FDCANx, DDL_FDCAN_TxMessageTypeDef *FDCAN_TxMessageStruct);



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

#endif /* defined (FDCANA) || defined (FDCANB) || defined (FDCANC) || defined (FDCAND) || defined (FDCANE) || defined (FDCANF) || defined (FDCANG) || defined (FDCANH) || defined (FDCANI) || defined (FDCANJ) || defined (FDCANK) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_FDCAN_H */

