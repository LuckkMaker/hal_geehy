/**
  *
  * @file    g32f463_ddl_fdcan.c
  * @brief   FDCAN DDL module driver.
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
  *
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32f463_ddl_fdcan.h"
#include "g32f463_ddl_bus.h"

#ifdef USE_FULL_ASSERT
  #include "g32_assert.h"
#else
#ifndef ASSERT_PARAM
    #define ASSERT_PARAM(_PARAM_) ((void)(0U))
#endif
#endif

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (FDCAN)

/** @addtogroup FDCAN_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup FDCAN_DDL_Private_Variables Private_Variables
  * @{
  */
static const uint8_t DLCtoBytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};
/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/** @defgroup FDCAN_DDL_Private_Constants Private_Constants
  * @{
  */
#define FDCAN_MESSAGE_RAM_SIZE 0x800U  /* 2K = 512 words */
#define FDCAN_MESSAGE_RAM_END_ADDRESS (SRAMCAN_BASE + FDCAN_MESSAGE_RAM_SIZE - 0x4U) /* Message RAM width is 4 Bytes */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup FDCAN_DDL_Private_Macros
  * @{
  */
#define IS_DDL_FDCAN_FRAMEFORMAT(__VALUE__)        (((__VALUE__) == DDL_FDCAN_FRAME_CLASSIC)  ||\
                                                    ((__VALUE__) == DDL_FDCAN_FRAME_FD_NOBRS) ||\
                                                    ((__VALUE__) == DDL_FDCAN_FRAME_FD_BRS))

#define IS_DDL_FDCAN_MODE(__VALUE__)               (((__VALUE__) == DDL_FDCAN_MODE_NORMAL)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_MODE_BUS_MONITOR)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_MODE_RESTRICTED) ||\
                                                    ((__VALUE__) == DDL_FDCAN_MODE_LOOPBACK_INTERNAL) ||\
                                                    ((__VALUE__) == DDL_FDCAN_MODE_LOOPBACK_EXTERNAL))

#define IS_DDL_FDCAN_TX_MODE(__MODE__)               (((__MODE__) == DDL_FDCAN_TXMODE_FIFO)     ||\
                                                      ((__MODE__) == DDL_FDCAN_TXMODE_QUEUE))

#define IS_DDL_FDCAN_NOMINAL_PSC(__VALUE__)       (((1U) <= (__VALUE__)) && ((__VALUE__) <= (512U)))

#define IS_DDL_FDCAN_NOMINAL_SJW(__VALUE__)       (((1U) <= (__VALUE__)) && ((__VALUE__) <= (128U)))

#define IS_DDL_FDCAN_NOMINAL_TIMESEG1(__VALUE__)  (((1U) <= (__VALUE__)) && ((__VALUE__) <= (256U)))

#define IS_DDL_FDCAN_NOMINAL_TIMESEG2(__VALUE__)  (((1U) <= (__VALUE__)) && ((__VALUE__) <= (128U)))

#define IS_DDL_FDCAN_DATA_PSC(__VALUE__)          (((1U) <= (__VALUE__)) && ((__VALUE__) <= (32U)))

#define IS_DDL_FDCAN_DATA_SJW(__VALUE__)          (((1U) <= (__VALUE__)) && ((__VALUE__) <= (16U)))

#define IS_DDL_FDCAN_DATA_TIMESEG1(__VALUE__)     (((1U) <= (__VALUE__)) && ((__VALUE__) <= (32U)))

#define IS_DDL_FDCAN_DATA_TIMESEG2(__VALUE__)     (((1U) <= (__VALUE__)) && ((__VALUE__) <= (16U)))

#define IS_FDCAN_MAX_VALUE(__VALUE__, __MAX__)     (((__VALUE__) <= (__MAX__)))

#define IS_DDL_FDCAN_STD_FILTER_TYPE(__VALUE__)    (((__VALUE__) == DDL_FDCAN_FILTER_TYPE_RANGE)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_TYPE_DUAL)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_TYPE_MASK)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_TYPE_DISABLE))

#define IS_DDL_FDCAN_EXT_FILTER_TYPE(__VALUE__)    (((__VALUE__) == DDL_FDCAN_FILTER_TYPE_RANGE)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_TYPE_DUAL)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_TYPE_MASK)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_TYPE_RANGE_NOMASK))

#define IS_DDL_FDCAN_ID_TYPE(__VALUE__)            (((__VALUE__) == DDL_FDCAN_STANDARD_ID)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_EXTENDED_ID))

#define IS_DDL_FDCAN_FILTER_CONFIG(__VALUE__)      (((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_DISABLE)      ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_TO_FIFO0)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_TO_FIFO1)     ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_REJECT)       ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_HP)           ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_TO_FIFO0_HP)  ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_TO_FIFO1_HP)  ||\
                                                    ((__VALUE__) == DDL_FDCAN_FILTER_CONFIG_TO_BUF))

#define IS_DDL_FDCAN_ESI(__VALUE__)                (((__VALUE__) == DDL_FDCAN_ESI_ACTIVE)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_ESI_PASSIVE))

#define IS_DDL_FDCAN_FRAME_TYPE(__VALUE__)         (((__VALUE__) == DDL_FDCAN_FRAME_NORMAL)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_FRAME_REMOTE))

#define IS_DDL_FDCAN_EFC(__VALUE__)                (((__VALUE__) == DDL_FDCAN_EFC_DISABLE)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_EFC_STORE_TXEVENT))

#define IS_DDL_FDCAN_FDFRAME(__VALUE__)            (((__VALUE__) == DDL_FDCAN_FDFRAME_CLASSIC)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_FDFRAME_FD))

#define IS_DDL_FDCAN_BRW(__VALUE__)                (((__VALUE__) == DDL_FDCAN_BRW_DISABLE)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_BRW_ENABLE))

#define IS_DDL_FDCAN_DATA_LENGTH(__VALUE__)        (((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_0)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_1)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_2)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_3)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_4)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_5)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_6)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_7)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_8)    ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_12)   ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_16)   ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_20)   ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_24)   ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_32)   ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_48)   ||\
                                                    ((__VALUE__) == DDL_FDCAN_DATALENGTH_BYTES_64))

#define IS_DDL_FDCAN_RXFIFO_NUM(__FIFO__)          (((__FIFO__) == DDL_FDCAN_RXFIFO_0)    ||\
                                                    ((__FIFO__) == DDL_FDCAN_RXFIFO_1))

#define IS_FDCAN_DATA_SIZE(SIZE) (((SIZE) == DDL_FDCAN_FILEDSIZE_8BYTE ) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_12BYTE) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_16BYTE) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_20BYTE) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_24BYTE) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_32BYTE) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_48BYTE) || \
                                  ((SIZE) == DDL_FDCAN_FILEDSIZE_64BYTE))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
static ErrorStatus FDCAN_CalcultateRamBlockAddresses(FDCAN_TypeDef *FDCANx, DDL_FDCAN_InitTypeDef *FDCAN_InitStruct);

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FDCAN_DDL_Exported_Functions
  * @{
  */

/** @addtogroup FDCAN_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize FDCAN registers (Registers restored to their default values).
  * @param  FDCANx FDCAN Port
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: FDCAN registers are de-initialized
  *          - ERROR:   Wrong FDCAN Port
  */
ErrorStatus DDL_FDCAN_DeInit(FDCAN_TypeDef *FDCANx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_FDCAN_ALL_INSTANCE(FDCANx));

  /* Force and Release reset on clock of FDCANx Port */
  DDL_APB1_GRP1_ForceReset(DDL_APB1_GRP1_PERIPH_FDCAN);
  DDL_APB1_GRP1_ReleaseReset(DDL_APB1_GRP1_PERIPH_FDCAN);

  return (status);
}

/**
  * @brief  Initialize FDCAN registers according to the specified parameters in FDCAN_InitStruct.
  * @param  FDCANx FDCAN instance
  * @param  FDCAN_InitStruct pointer to a @ref DDL_FDCAN_InitTypeDef structure
  *         that contains the configuration information for the specified FDCAN peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: FDCAN registers are initialized according to FDCAN_InitStruct content
  *          - ERROR:   Not applicable
  * @note   After calling this function, the FDCAN module is in the initialization mode.
  */
ErrorStatus DDL_FDCAN_Init(FDCAN_TypeDef *FDCANx, DDL_FDCAN_InitTypeDef *FDCAN_InitStruct)
{
  uint32_t delaytime = 0xFFFFFF;
  const uint32_t cvtEltSize[] = {0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 5, 0, 0, 0, 6, 0, 0, 0, 7};

  /* Check the parameters */
  ASSERT_PARAM(IS_FDCAN_ALL_INSTANCE(FDCANx));
  ASSERT_PARAM(IS_DDL_FDCAN_FRAMEFORMAT(FDCAN_InitStruct->FrameFormat));
  ASSERT_PARAM(IS_DDL_FDCAN_MODE(FDCAN_InitStruct->Mode));
  ASSERT_PARAM(IS_DDL_FDCAN_NOMINAL_PSC(FDCAN_InitStruct->NominalPrescaler));
  ASSERT_PARAM(IS_DDL_FDCAN_NOMINAL_SJW(FDCAN_InitStruct->NominalSyncJumpWidth));
  ASSERT_PARAM(IS_DDL_FDCAN_NOMINAL_TIMESEG1(FDCAN_InitStruct->NominalTimeSeg1));
  ASSERT_PARAM(IS_DDL_FDCAN_NOMINAL_TIMESEG2(FDCAN_InitStruct->NominalTimeSeg2));
  if (FDCAN_InitStruct->FrameFormat == DDL_FDCAN_FRAME_FD_BRS)
  {
    /* Check the data bit time parameters in BRS mode */
    ASSERT_PARAM(IS_DDL_FDCAN_DATA_PSC(FDCAN_InitStruct->DataPrescaler));
    ASSERT_PARAM(IS_DDL_FDCAN_DATA_SJW(FDCAN_InitStruct->DataSyncJumpWidth));
    ASSERT_PARAM(IS_DDL_FDCAN_DATA_TIMESEG1(FDCAN_InitStruct->DataTimeSeg1));
    ASSERT_PARAM(IS_DDL_FDCAN_DATA_TIMESEG2(FDCAN_InitStruct->DataTimeSeg2));
  }
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_InitStruct->StdFiltersNbr, 128U));
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_InitStruct->ExtFiltersNbr, 64U));
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_InitStruct->RxFifo0ElmtsNbr, 64U));
  if (FDCAN_InitStruct->RxFifo0ElmtsNbr > 0U)
  {
    ASSERT_PARAM(IS_FDCAN_DATA_SIZE(FDCAN_InitStruct->RxFifo0ElmtSize));
  }
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_InitStruct->RxFifo1ElmtsNbr, 64U));
  if (FDCAN_InitStruct->RxFifo1ElmtsNbr > 0U)
  {
    ASSERT_PARAM(IS_FDCAN_DATA_SIZE(FDCAN_InitStruct->RxFifo1ElmtSize));
  }
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_InitStruct->RxBuffersNbr, 64U));
  if (FDCAN_InitStruct->RxBuffersNbr > 0U)
  {
    ASSERT_PARAM(IS_FDCAN_DATA_SIZE(FDCAN_InitStruct->RxBufferSize));
  }
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_InitStruct->TxEventsNbr, 32U));
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE((FDCAN_InitStruct->TxBuffersNbr + FDCAN_InitStruct->TxFifoQueueElmtsNbr), 32U));
  if (FDCAN_InitStruct->TxFifoQueueElmtsNbr > 0U)
  {
    ASSERT_PARAM(IS_DDL_FDCAN_TX_MODE(FDCAN_InitStruct->TxFifoQueueMode));
  }
  if ((FDCAN_InitStruct->TxBuffersNbr + FDCAN_InitStruct->TxFifoQueueElmtsNbr) > 0U)
  {
    ASSERT_PARAM(IS_FDCAN_DATA_SIZE(FDCAN_InitStruct->TxElmtSize));
  }

  /* Exit from Sleep mode */
  DDL_FDCAN_DisableClockStopRequest(FDCANx);
  while (DDL_FDCAN_IsActiveFlag_CSA(FDCANx) != 0U)
  {
    delaytime--;
    if (delaytime == 0)
    {
        return ERROR;
    }
  }

  /* Request initialisation */
  DDL_FDCAN_EnableInitMode(FDCANx);
  while (DDL_FDCAN_IsEnabledInitMode(FDCANx) == 0U)
  {
    delaytime--;
    if (delaytime == 0)
    {
        return ERROR;
    }
  }

  /* Enable configuration change */
  DDL_FDCAN_EnableWriteAccess(FDCANx);

  /* Configuration FDCAN auto retransmission */
  if(FDCAN_InitStruct->AutoRetransmission == ENABLE)
  {
    DDL_FDCAN_EnableAutoRetransmission(FDCANx);
  }
  else
  {
    DDL_FDCAN_DisableAutoRetransmission(FDCANx);
  }

  /* Configuration FDCAN transmit pause */
  if(FDCAN_InitStruct->TransmitPause == ENABLE)
  {
    DDL_FDCAN_EnableTransmitPause(FDCANx);
  }
  else
  {
    DDL_FDCAN_DisableTransmitPause(FDCANx);
  }

  /* Configuration FDCAN protocol exception */
  if(FDCAN_InitStruct->ProtocolException == ENABLE)
  {
    DDL_FDCAN_EnableProtocolException(FDCANx);
  }
  else
  {
    DDL_FDCAN_DisableProtocolException(FDCANx);
  }

  /* Configuration FDCAN frame format */
  DDL_FDCAN_SetFrameFormat(FDCANx, FDCAN_InitStruct->FrameFormat);

  /* Set FDCAN Operating Mode:
               | Normal | Restricted |    Bus     | Internal | External
               |        | Operation  | Monitoring | LoopBack | LoopBack
     CCCR.TEST |   0    |     0      |     0      |    1     |    1
     CCCR.MON  |   0    |     0      |     1      |    1     |    0
     TEST.LBCK |   0    |     0      |     0      |    1     |    1
     CCCR.ASM  |   0    |     1      |     0      |    0     |    0
  */

  /* Configuration FDCAN operation mode */
  DDL_FDCAN_SetOperationMode(FDCANx, FDCAN_InitStruct->Mode);
  
  /* Configuration FDCAN Nominal Bit Timing & Prescaler  */
  DDL_FDCAN_NBTPConfig(FDCANx, FDCAN_InitStruct->NominalPrescaler,
                               FDCAN_InitStruct->NominalTimeSeg1,
                               FDCAN_InitStruct->NominalTimeSeg2,
                               FDCAN_InitStruct->NominalSyncJumpWidth);

  /* Configuration FDCAN Data Bit Timing & Prescaler   */
  if(FDCAN_InitStruct->FrameFormat == DDL_FDCAN_FRAME_FD_BRS)
  {
    DDL_FDCAN_DBTPConfig(FDCANx, FDCAN_InitStruct->DataPrescaler,
                                 FDCAN_InitStruct->DataTimeSeg1,
                                 FDCAN_InitStruct->DataTimeSeg2,
                                 FDCAN_InitStruct->DataSyncJumpWidth);
  }

  if (FDCAN_InitStruct->TxFifoQueueElmtsNbr > 0U)
  {
    /* Select between Tx FIFO and Tx Queue operation modes */
    DDL_FDCAN_SetTxOperationMode(FDCANx, FDCAN_InitStruct->TxFifoQueueMode);
  }

  /* Configure Tx element size */
  if ((FDCAN_InitStruct->TxBuffersNbr + FDCAN_InitStruct->TxFifoQueueElmtsNbr) > 0U)
  {
    MODIFY_REG(FDCANx->TXESC, FDCAN_TXESC_TBDS, cvtEltSize[FDCAN_InitStruct->TxElmtSize]);
  }

  /* Configure Rx FIFO 0 element size */
  if (FDCAN_InitStruct->RxFifo0ElmtsNbr > 0U)
  {
    MODIFY_REG(FDCANx->RXESC, FDCAN_RXESC_F0DS,
               (cvtEltSize[FDCAN_InitStruct->RxFifo0ElmtSize] << FDCAN_RXESC_F0DS_Pos));
  }
  
  /* Configure Rx FIFO 1 element size */
  if (FDCAN_InitStruct->RxFifo1ElmtsNbr > 0U)
  {
    MODIFY_REG(FDCANx->RXESC, FDCAN_RXESC_F1DS,
               (cvtEltSize[FDCAN_InitStruct->RxFifo1ElmtSize] << FDCAN_RXESC_F1DS_Pos));
  }

  /* Configure Rx buffer element size */
  if (FDCAN_InitStruct->RxBuffersNbr > 0U)
  {
    MODIFY_REG(FDCANx->RXESC, FDCAN_RXESC_RBDS,
               (cvtEltSize[FDCAN_InitStruct->RxBufferSize] << FDCAN_RXESC_RBDS_Pos));
  }

  /* Calculate each RAM block address */
  if (FDCAN_CalcultateRamBlockAddresses(FDCANx, FDCAN_InitStruct) != SUCCESS)
  {
    return ERROR;
  }

  return (SUCCESS);
}

/**
  * @brief Set each @ref DDL_FDCAN_InitTypeDef field to default value.
  * @param FDCAN_InitStruct pointer to a @ref DDL_FDCAN_InitTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */

void DDL_FDCAN_StructInit(DDL_FDCAN_InitTypeDef *FDCAN_InitStruct)
{
  /* Reset FDCAN init structure parameters values */
  FDCAN_InitStruct->FrameFormat            = DDL_FDCAN_FRAME_CLASSIC;
  FDCAN_InitStruct->Mode                   = DDL_FDCAN_MODE_NORMAL;
  FDCAN_InitStruct->AutoRetransmission     = DISABLE;
  FDCAN_InitStruct->TransmitPause          = DISABLE;
  FDCAN_InitStruct->ProtocolException      = DISABLE;
  FDCAN_InitStruct->NominalPrescaler       = 1U;
  FDCAN_InitStruct->NominalSyncJumpWidth   = 1U;
  FDCAN_InitStruct->NominalTimeSeg1        = 2U;
  FDCAN_InitStruct->NominalTimeSeg2        = 2U;
  FDCAN_InitStruct->DataPrescaler          = 1U;
  FDCAN_InitStruct->DataSyncJumpWidth      = 1U;
  FDCAN_InitStruct->DataTimeSeg1           = 1U;
  FDCAN_InitStruct->DataTimeSeg2           = 1U;
  FDCAN_InitStruct->MessageRAMOffset       = 0U;
  FDCAN_InitStruct->StdFiltersNbr          = 0U;
  FDCAN_InitStruct->ExtFiltersNbr          = 0U;
  FDCAN_InitStruct->RxFifo0ElmtsNbr        = 0U;
  FDCAN_InitStruct->RxFifo0ElmtSize        = DDL_FDCAN_FILEDSIZE_8BYTE;
  FDCAN_InitStruct->RxFifo1ElmtsNbr        = 0U;
  FDCAN_InitStruct->RxFifo1ElmtSize        = DDL_FDCAN_FILEDSIZE_8BYTE;
  FDCAN_InitStruct->RxBuffersNbr           = 0U;
  FDCAN_InitStruct->RxBufferSize           = DDL_FDCAN_FILEDSIZE_8BYTE;
  FDCAN_InitStruct->TxEventsNbr            = 0U;
  FDCAN_InitStruct->TxBuffersNbr           = 0U;
  FDCAN_InitStruct->TxFifoQueueElmtsNbr    = 0U;
  FDCAN_InitStruct->TxFifoQueueMode        = DDL_FDCAN_TXMODE_FIFO;
  FDCAN_InitStruct->TxElmtSize             = DDL_FDCAN_FILEDSIZE_8BYTE;
}

/**
  * @brief  Initialize FDCAN filter sram according to the specified parameters in FDCAN_FilterStruct.
  * @param  FDCANx FDCAN instance
  * @param  FDCAN_FilterStruct pointer to a @ref DDL_FDCAN_FilterTypeDef structure
  *         that contains the configuration information for the specified FDCAN peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: FDCAN registers are initialized according to FDCAN_FilterStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_FDCAN_FilterInit(FDCAN_TypeDef *FDCANx, DDL_FDCAN_FilterTypeDef *FDCAN_FilterStruct)
{
  uint32_t SramAddressBase = 0;
  uint32_t *filteraddr = (void *)0;
  uint32_t filtertmp1 = 0;
  uint32_t filtertmp2 = 0;
  uint32_t filtercnt = 0;

  /* Check function parameters */
  ASSERT_PARAM(IS_FDCAN_ALL_INSTANCE(FDCANx));
  ASSERT_PARAM(IS_DDL_FDCAN_ID_TYPE(FDCAN_FilterStruct->IdType));
  ASSERT_PARAM(IS_DDL_FDCAN_FILTER_CONFIG(FDCAN_FilterStruct->FilterConfig));

  /* Get the base address of FDCANx */
  SramAddressBase = __DDL_FDCAN_GET_SRAM_ADDRESS(FDCANx);

  if (FDCAN_FilterStruct->IdType == DDL_FDCAN_STANDARD_ID)
  {
    /* Get standard message filter element number */
    filtercnt = DDL_FDCAN_GetStdFilterNum(FDCANx);

    /* Check function parameters */
    ASSERT_PARAM(IS_DDL_FDCAN_STD_FILTER_TYPE(FDCAN_FilterStruct->FilterType));
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_FilterStruct->FilterIndex, filtercnt));
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_FilterStruct->FilterID1, 0x7FF));
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_FilterStruct->FilterID2, 0x7FF));

    filtertmp1 = ((FDCAN_FilterStruct->FilterType << 30U) | (FDCAN_FilterStruct->FilterConfig << 27U) |
                 (FDCAN_FilterStruct->FilterID1 << 16) | FDCAN_FilterStruct->FilterID2);

    filteraddr = (uint32_t *)(SramAddressBase + DDL_FDCAN_GetStdFilterAddress(FDCANx) + FDCAN_FilterStruct->FilterIndex * 4U);

    *filteraddr = filtertmp1;
  }
  else
  {
    /* Get extended message filter element number */
    filtercnt = DDL_FDCAN_GetExtFilterNum(FDCANx);

    /* Check function parameters */
    ASSERT_PARAM(IS_DDL_FDCAN_EXT_FILTER_TYPE(FDCAN_FilterStruct->FilterType));
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_FilterStruct->FilterIndex, filtercnt));
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_FilterStruct->FilterID1, 0x1FFFFFFF));
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_FilterStruct->FilterID2, 0x1FFFFFFF));

    filtertmp1 = ((FDCAN_FilterStruct->FilterConfig << 29U) | FDCAN_FilterStruct->FilterID1);

    filtertmp2 = ((FDCAN_FilterStruct->FilterType << 30U) | FDCAN_FilterStruct->FilterID2);

    filteraddr = (uint32_t *)(SramAddressBase + DDL_FDCAN_GetExtFilterAddress(FDCANx) + FDCAN_FilterStruct->FilterIndex * 8U);

    *filteraddr = filtertmp1;
    filteraddr++;
    *filteraddr = filtertmp2;
  }
  (void)filtercnt;

  return (SUCCESS);
}

/**
  * @brief Set each @ref DDL_FDCAN_FilterTypeDef field to default value.
  * @param FDCAN_FilterStruct pointer to a @ref DDL_FDCAN_FilterTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */

void DDL_FDCAN_FilterStructInit(DDL_FDCAN_FilterTypeDef *FDCAN_FilterStruct)
{
  /* Reset FDCAN filter structure parameters values */
  FDCAN_FilterStruct->IdType        = DDL_FDCAN_STANDARD_ID;
  FDCAN_FilterStruct->FilterIndex   = 0U;
  FDCAN_FilterStruct->FilterType    = DDL_FDCAN_FILTER_TYPE_RANGE;
  FDCAN_FilterStruct->FilterConfig  = DDL_FDCAN_FILTER_CONFIG_DISABLE;
  FDCAN_FilterStruct->FilterID1     = 0x7FF;
  FDCAN_FilterStruct->FilterID2     = 0x7FF;
}

/**
  * @brief  Set Tx message to Tx buffer element according to the specified parameters in FDCAN_TxMessageStruct.
  * @param  FDCANx FDCAN instance
  * @param  FDCAN_TxMessageStruct pointer to a @ref DDL_FDCAN_TxMessageTypeDef structure
  *         that contains the configuration information for the specified FDCAN peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: FDCAN registers are initialized according to FDCAN_TxMessageStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_FDCAN_TxMessage(FDCAN_TypeDef *FDCANx, DDL_FDCAN_TxMessageTypeDef *FDCAN_TxMessageStruct)
{
  uint32_t SramAddressBase = 0;
  uint32_t PutIndex = 0;
  uint32_t *TxAddress = (void *)0;
  uint32_t BytesCnt = 0;
  uint32_t TxElmtBytes = 0;

  /* Check function parameters */
  ASSERT_PARAM(IS_FDCAN_ALL_INSTANCE(FDCANx));
  ASSERT_PARAM(IS_DDL_FDCAN_ID_TYPE(FDCAN_TxMessageStruct->IdType));
  ASSERT_PARAM(IS_DDL_FDCAN_ESI(FDCAN_TxMessageStruct->ErrorStateIndicator));
  ASSERT_PARAM(IS_DDL_FDCAN_FRAME_TYPE(FDCAN_TxMessageStruct->FrameType));
  ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_TxMessageStruct->MessageMarker, 0xFF));
  ASSERT_PARAM(IS_DDL_FDCAN_EFC(FDCAN_TxMessageStruct->EventFifoControl));
  ASSERT_PARAM(IS_DDL_FDCAN_FDFRAME(FDCAN_TxMessageStruct->FDFrame));
  ASSERT_PARAM(IS_DDL_FDCAN_BRW(FDCAN_TxMessageStruct->BitRateSwitch));
  ASSERT_PARAM(IS_DDL_FDCAN_DATA_LENGTH(FDCAN_TxMessageStruct->DataLength));

  /* Get the base address of FDCANx */
  SramAddressBase = __DDL_FDCAN_GET_SRAM_ADDRESS(FDCANx);

  /* Check FDCAN Tx FIFO is full or not */
  if(FDCANx->TXFQS & FDCAN_TXFQS_TFQF)
  {
    return ERROR;
  }

  /* Calculte the Tx FIFO element index */
  PutIndex = DDL_FDCAN_GetTxFIFOPutIndex(FDCANx);
  /* Element size in bytes = RAM words * 4 */
  TxElmtBytes = DDL_FDCAN_GetTxBufferFiledSize(FDCANx) * 4U;
  /* Calculte the Tx FIFO element address */
  TxAddress = (uint32_t *)(SramAddressBase + DDL_FDCAN_GetTxBufferAddress(FDCANx) + PutIndex * TxElmtBytes);

  /* Fill the data into the first word of the Tx FIFO.  */
  if (FDCAN_TxMessageStruct->IdType == DDL_FDCAN_STANDARD_ID)
  {
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_TxMessageStruct->Identifier, 0x7FF));

    *TxAddress = (FDCAN_TxMessageStruct->ErrorStateIndicator | DDL_FDCAN_STANDARD_ID |
                  FDCAN_TxMessageStruct->FrameType | (FDCAN_TxMessageStruct->Identifier << 18U));
  }
  else
  {
    ASSERT_PARAM(IS_FDCAN_MAX_VALUE(FDCAN_TxMessageStruct->Identifier, 0x1FFFFFFF));

    *TxAddress = (FDCAN_TxMessageStruct->ErrorStateIndicator | DDL_FDCAN_EXTENDED_ID |
                  FDCAN_TxMessageStruct->FrameType | FDCAN_TxMessageStruct->Identifier);
  }
  /* Increment RxAddress pointer to second word of Rx FIFO element */
  TxAddress ++;

  /* Fill the data into the second word of the Tx FIFO.  */
  *TxAddress = (FDCAN_TxMessageStruct->MessageMarker << 24U) | FDCAN_TxMessageStruct->EventFifoControl |
               FDCAN_TxMessageStruct->FDFrame | FDCAN_TxMessageStruct->BitRateSwitch |
               FDCAN_TxMessageStruct->DataLength << 16U;

  /* Increment TxAddress pointer to data of Tx FIFO element */
  TxAddress++;
  for(BytesCnt = 0; BytesCnt < DLCtoBytes[FDCAN_TxMessageStruct->DataLength]; BytesCnt+=4)
  {
    *TxAddress = (FDCAN_TxMessageStruct->buffer[BytesCnt] | (FDCAN_TxMessageStruct->buffer[BytesCnt+1] << 8U) |
                  (FDCAN_TxMessageStruct->buffer[BytesCnt+2] << 16U) | (FDCAN_TxMessageStruct->buffer[BytesCnt+3] << 24U));
    TxAddress++;
  }

  DDL_FDCAN_EnableTxRequest(FDCANx, (uint32_t)(1U << PutIndex));
  while(DDL_FDCAN_IsActiveFlag_TRP(FDCANx, 1U << PutIndex));

  return (SUCCESS);
}

/**
  * @brief  Get Rx message to Tx buffer element according to the specified parameters in FDCAN_TxMessageStruct.
  * @param  FDCANx FDCAN instance
  * @param  RxFifoNumber This parameter can be one of the following values:
  *         @arg @ref DDL_FDCAN_RXFIFO_0
  *         @arg @ref DDL_FDCAN_RXFIFO_1
  * @param  FDCAN_TxMessageStruct pointer to a @ref DDL_FDCAN_TxMessageTypeDef structure
  *         that contains the configuration information for the specified FDCAN peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: FDCAN registers are initialized according to FDCAN_TxMessageStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_FDCAN_RxMessage(FDCAN_TypeDef *FDCANx, uint32_t RxFifoNumber, DDL_FDCAN_RxMessageTypeDef *FDCAN_RxMessageStruct)
{
  uint32_t GetIndex = 0;
  uint32_t *RxAddress = (void *)0;
  uint8_t *pDATA = (void *)0;
  uint32_t BytesCnt = 0;
  uint32_t SramAddressBase = 0;
  uint32_t RxElmtBytes = 0;

  /* Check function parameters */
  ASSERT_PARAM(IS_FDCAN_ALL_INSTANCE(FDCANx));
  ASSERT_PARAM(IS_DDL_FDCAN_RXFIFO_NUM(RxFifoNumber));

  /* Get the base address of FDCANx */
  SramAddressBase = __DDL_FDCAN_GET_SRAM_ADDRESS(FDCANx);

  /* Check that the Rx FIFO has an allocated area into the RAM */
  if (DDL_FDCAN_GetRxFIFOxSize(FDCANx, RxFifoNumber) == 0U)
  {
    return ERROR;
  }

  /* Check Rx FIFO is empty or not */
  if(DDL_FDCAN_GetRxFIFOxFullLevel(FDCANx, RxFifoNumber) == 0U)
  {
    return ERROR;
  }

  /* When an Rx FIFO is operated in overwrite mode and an Rx FIFO full condition is signalled, reading
  of the Rx FIFO elements should start at least at get index + 1 */
  if(DDL_FDCAN_GetRxFIFOxMode(FDCANx, RxFifoNumber) == DDL_FDCAN_RXMODE_OVERWRITE &&
    DDL_FDCAN_IsActiveFlag_RFF(FDCANx, RxFifoNumber))
  {
    GetIndex = 1;
  }

  /* Calculate the Rx FIFO element index */
  GetIndex += DDL_FDCAN_GetRxFIFOxGetIndex(FDCANx, RxFifoNumber);

  /* Element size in bytes = RAM words * 4 */
  if (RxFifoNumber == DDL_FDCAN_RXFIFO_0)
  {
    RxElmtBytes = DDL_FDCAN_GetRxFIFO0FiledSize(FDCANx) * 4U;
  }
  else
  {
    RxElmtBytes = DDL_FDCAN_GetRxFIFO1FiledSize(FDCANx) * 4U;
  }

  /* Calculate the Rx FIFO element address */
  RxAddress = (uint32_t *)(SramAddressBase + DDL_FDCAN_GetRxFIFOxAddress(FDCANx, RxFifoNumber) + GetIndex * RxElmtBytes);

  /* Retrieve IdType */
  FDCAN_RxMessageStruct->IdType = *RxAddress & DDL_FDCAN_EXTENDED_ID;

  /* Retrieve ErrorStateIndicator */
  FDCAN_RxMessageStruct->ErrorStateIndicator = *RxAddress & DDL_FDCAN_ESI_PASSIVE;

  /* Retrieve FrameType */
  FDCAN_RxMessageStruct->FrameType = *RxAddress & DDL_FDCAN_FRAME_REMOTE;

  /* Retrieve Identifier */
  if(FDCAN_RxMessageStruct->IdType == DDL_FDCAN_STANDARD_ID)
  {
    FDCAN_RxMessageStruct->Identifier = (*RxAddress >> 18U) & 0x7FFU;
  }
  else
  {
    FDCAN_RxMessageStruct->Identifier = *RxAddress & 0x1FFFFFFFU;
  }

  /* Increment RxAddress pointer to second word of Rx FIFO element */
  RxAddress++;
  /* Retrieve FrameMatch */
  FDCAN_RxMessageStruct->FrameMatch = *RxAddress & DDL_FDCAN_FRAME_NOMATCH;

  /* Retrieve FilterIndex */
  FDCAN_RxMessageStruct->FilterIndex = (*RxAddress >> 24U) & 0x7FU;

  /* Retrieve FDFrame */
  FDCAN_RxMessageStruct->FDFrame = *RxAddress & DDL_FDCAN_FDFRAME_FD;

  /* Retrieve BitRateSwitch */
  FDCAN_RxMessageStruct->BitRateSwitch = *RxAddress & DDL_FDCAN_BRW_ENABLE;

  /* Retrieve DataLength */
  FDCAN_RxMessageStruct->DataLength = (*RxAddress >> 16U) & 0xFU;

  /* Retrieve TimeStamp */
  FDCAN_RxMessageStruct->TimeStamp = *RxAddress & 0xFFFFU;

  /* Increment RxAddress pointer to Rx FIFO data element */
  RxAddress++;
  pDATA = (uint8_t *)RxAddress;
  /* Retrieve Data */
  for (BytesCnt = 0; BytesCnt < DLCtoBytes[FDCAN_RxMessageStruct->DataLength]; BytesCnt++)
  {
    FDCAN_RxMessageStruct->buffer[BytesCnt] = pDATA[BytesCnt];
  }

  DDL_FDCAN_SetRxFIFOxAckIndex(FDCANx, GetIndex, RxFifoNumber);

  return (SUCCESS);
}
/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FDCAN_DDL_Private_Functions FDCAN Private Functions
  * @{
  */

/**
  * @brief  Calculate each RAM block start address and size
  * @param  FDCANx FDCAN instance
  * @param  FDCAN_InitStruct pointer to a @ref DDL_FDCAN_InitTypeDef structure
  *         that contains the configuration information for the specified FDCAN peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: FDCAN registers are initialized according to FDCAN_InitStruct content
  *          - ERROR:   Not applicable
 */
static ErrorStatus FDCAN_CalcultateRamBlockAddresses(FDCAN_TypeDef *FDCANx, DDL_FDCAN_InitTypeDef *FDCAN_InitStruct)
{
  uint32_t RAMcounter;
  uint32_t startAddress;
  DDL_FDCAN_MsgRamAddressTypeDef msgRamAddress;

  startAddress = FDCAN_InitStruct->MessageRAMOffset;

  /* Standard filter list start address */
  MODIFY_REG(FDCANx->SIDFC, FDCAN_SIDFC_FLSSA, (startAddress << FDCAN_SIDFC_FLSSA_Pos));

  /* Standard filter elements number */
  MODIFY_REG(FDCANx->SIDFC, FDCAN_SIDFC_LSS, (FDCAN_InitStruct->StdFiltersNbr << FDCAN_SIDFC_LSS_Pos));

  /* Extended filter list start address */
  startAddress += FDCAN_InitStruct->StdFiltersNbr;
  MODIFY_REG(FDCANx->XIDFC, FDCAN_XIDFC_FLESA, (startAddress << FDCAN_XIDFC_FLESA_Pos));

  /* Extended filter elements number */
  MODIFY_REG(FDCANx->XIDFC, FDCAN_XIDFC_LSE, (FDCAN_InitStruct->ExtFiltersNbr << FDCAN_XIDFC_LSE_Pos));

  /* Rx FIFO 0 start address */
  startAddress += (FDCAN_InitStruct->ExtFiltersNbr * 2U);
  MODIFY_REG(FDCANx->RXF0C, FDCAN_RXF0C_F0SA, (startAddress << FDCAN_RXF0C_F0SA_Pos));

  /* Rx FIFO 0 elements number */
  MODIFY_REG(FDCANx->RXF0C, FDCAN_RXF0C_F0S, (FDCAN_InitStruct->RxFifo0ElmtsNbr << FDCAN_RXF0C_F0S_Pos));

  /* Rx FIFO 1 start address */
  startAddress += (FDCAN_InitStruct->RxFifo0ElmtsNbr * FDCAN_InitStruct->RxFifo0ElmtSize);
  MODIFY_REG(FDCANx->RXF1C, FDCAN_RXF1C_F1SA, (startAddress << FDCAN_RXF1C_F1SA_Pos));

  /* Rx FIFO 1 elements number */
  MODIFY_REG(FDCANx->RXF1C, FDCAN_RXF1C_F1S, (FDCAN_InitStruct->RxFifo1ElmtsNbr << FDCAN_RXF1C_F1S_Pos));

  /* Rx buffer list start address */
  startAddress += (FDCAN_InitStruct->RxFifo1ElmtsNbr * FDCAN_InitStruct->RxFifo1ElmtSize);
  MODIFY_REG(FDCANx->RXBC, FDCAN_RXBC_RBSA, (startAddress << FDCAN_RXBC_RBSA_Pos));

  /* Tx event FIFO start address */
  startAddress += (FDCAN_InitStruct->RxBuffersNbr * FDCAN_InitStruct->RxBufferSize);
  MODIFY_REG(FDCANx->TXEFC, FDCAN_TXEFC_EFSA, (startAddress << FDCAN_TXEFC_EFSA_Pos));

  /* Tx event FIFO elements number */
  MODIFY_REG(FDCANx->TXEFC, FDCAN_TXEFC_EFS, (FDCAN_InitStruct->TxEventsNbr << FDCAN_TXEFC_EFS_Pos));

  /* Tx buffer list start address */
  startAddress += (FDCAN_InitStruct->TxEventsNbr * 2U);
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_TBSA, (startAddress << FDCAN_TXBC_TBSA_Pos));

  /* Dedicated Tx buffers number */
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_NDTB, (FDCAN_InitStruct->TxBuffersNbr << FDCAN_TXBC_NDTB_Pos));

  /* Tx FIFO/queue elements number */
  MODIFY_REG(FDCANx->TXBC, FDCAN_TXBC_TFQS, (FDCAN_InitStruct->TxFifoQueueElmtsNbr << FDCAN_TXBC_TFQS_Pos));

  msgRamAddress.StandardFilterSA = SRAMCAN_BASE + (FDCAN_InitStruct->MessageRAMOffset * 4U);
  msgRamAddress.ExtendedFilterSA = msgRamAddress.StandardFilterSA + (FDCAN_InitStruct->StdFiltersNbr * 4U);
  msgRamAddress.RxFIFO0SA = msgRamAddress.ExtendedFilterSA + (FDCAN_InitStruct->ExtFiltersNbr * 2U * 4U);
  msgRamAddress.RxFIFO1SA = msgRamAddress.RxFIFO0SA +
                             (FDCAN_InitStruct->RxFifo0ElmtsNbr * FDCAN_InitStruct->RxFifo0ElmtSize * 4U);
  msgRamAddress.RxBufferSA = msgRamAddress.RxFIFO1SA +
                              (FDCAN_InitStruct->RxFifo1ElmtsNbr * FDCAN_InitStruct->RxFifo1ElmtSize * 4U);
  msgRamAddress.TxEventFIFOSA = msgRamAddress.RxBufferSA +
                                 (FDCAN_InitStruct->RxBuffersNbr * FDCAN_InitStruct->RxBufferSize * 4U);
  msgRamAddress.TxBufferSA = msgRamAddress.TxEventFIFOSA + (FDCAN_InitStruct->TxEventsNbr * 2U * 4U);
  msgRamAddress.TxFIFOQSA = msgRamAddress.TxBufferSA + (FDCAN_InitStruct->TxBuffersNbr * FDCAN_InitStruct->TxElmtSize * 4U);

  msgRamAddress.EndAddress = msgRamAddress.TxFIFOQSA +
                              (FDCAN_InitStruct->TxFifoQueueElmtsNbr * FDCAN_InitStruct->TxElmtSize * 4U);

  /* Last address of the Message RAM */
  if (msgRamAddress.EndAddress > FDCAN_MESSAGE_RAM_END_ADDRESS) 
  {
    return ERROR;
  }
  else
  {
    /* Flush the allocated Message RAM area */
    for (RAMcounter = msgRamAddress.StandardFilterSA; RAMcounter < msgRamAddress.EndAddress; RAMcounter += 4U)
    {
      *(uint32_t *)(RAMcounter) = 0x00000000U;
    }
  }

  return SUCCESS;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (FDCAN) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

