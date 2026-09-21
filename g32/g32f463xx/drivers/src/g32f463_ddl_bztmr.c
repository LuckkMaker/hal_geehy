/**
  *
  * @file    g32f463_ddl_bztmr.c
  * @brief   BZTMR DDL module driver.
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
#include "g32f463_ddl_bztmr.h"
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

#if defined (BZTMR)

/** @addtogroup BZTMR_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup BZTMR_DDL_Private_Macros
  * @{
  */
#define IS_DDL_BZTMR_DIVISION(__VALUE__)        ((__VALUE__) <= (0xFFFFU))
#define IS_DDL_BZTMR_DATAWIDTH(__VALUE__)       (((__VALUE__) == DDL_BZTMR_DATA_WIDTH_8)  ||\
                                                 ((__VALUE__) == DDL_BZTMR_DATA_WIDTH_16)  ||\
                                                 ((__VALUE__) == DDL_BZTMR_DATA_WIDTH_24)  ||\
                                                 ((__VALUE__) == DDL_BZTMR_DATA_WIDTH_32))
#define IS_DDL_BZTMR_OUTPUTFORMAT(__VALUE__)    (((__VALUE__) == DDL_BZTMR_OUTPUT_FORMAT_LSB) ||\
                                                 ((__VALUE__) == DDL_BZTMR_OUTPUT_FORMAT_MSB))
#define IS_DDL_BZTMR_OUTPUTPOLARITY(__VALUE__)  (((__VALUE__) == DDL_BZTMR_CHANNEL_POLARITY_LOW) ||\
                                                 ((__VALUE__) == DDL_BZTMR_CHANNEL_POLARITY_HIGH))
#define IS_DDL_BZTMR_OUTPUTREVERSAL(__VALUE__)  (((__VALUE__) == DISABLE) ||\
                                                 ((__VALUE__) == ENABLE))
#define IS_DDL_BZTMR_NBR_OF_TRANSFER(__VALUE__)    ((__VALUE__) <= (0x0AU))
#define IS_DDL_BZTMR_RESET_TIME(__VALUE__)    ((__VALUE__) <= (0xFFFFU))
#define IS_DDL_BZTMR_RESET_POLARITY(__VALUE__)   (((__VALUE__) == DDL_BZTMR_RESET_OUTPUT_LEVEL_LOW) ||\
                                                 ((__VALUE__) == DDL_BZTMR_RESET_OUTPUT_LEVEL_HIGH))
#define IS_DDL_BZTMR_CHANNELS(__VALUE__)       ((__VALUE__) <= (DDL_BZTMR_CHANNEL_CH9))
#define IS_DDL_BZTMR_RANKS(__VALUE__)          ((__VALUE__) <= (DDL_BZTMR_SEQ10))
#define IS_DDL_BZTMR_DATA_LENGTH(__VALUE__)   ((__VALUE__) <= (0x1FFU))
#define IS_DDL_BZTMR_END_LENGTH(__VALUE__)    ((__VALUE__) <= (0x1FU))
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup BZTMR_DDL_Exported_Functions
  * @{
  */

/** @addtogroup BZTMR_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize BZTMR registers (Registers restored to their default values).
  * @param  BZTMRx BZTMR instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BZTMR registers are de-initialized
  *          - ERROR:   Wrong BZTMR instance
  */
ErrorStatus DDL_BZTMR_DeInit(BZTMR_TypeDef *BZTMRx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_BZTMR_ALL_INSTANCE(BZTMRx));

  /* Force and Release reset on clock of BZTMR */
  if (BZTMRx == BZTMR)
  {
    DDL_APB2_GRP1_ForceReset(DDL_APB2_GRP1_PERIPH_BZTMR);
    DDL_APB2_GRP1_ReleaseReset(DDL_APB2_GRP1_PERIPH_BZTMR);
  }
  else
  {
    status = ERROR;
  }

  return (status);
}

/**
  * @brief  Initialize BZTMR registers according to the specified parameters in BZTMR_InitStruct.
  * @param  BZTMRx BZTMR instance
  * @param  BZTMR_InitStruct pointer to a @ref DDL_BZTMR_InitTypeDef structure
  *         that contains the configuration information for the specified BZTMR peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BZTMR registers are initialized according to BZTMR_InitStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_BZTMR_Init(BZTMR_TypeDef *BZTMRx, DDL_BZTMR_InitTypeDef *BZTMR_InitStruct)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_BZTMR_ALL_INSTANCE(BZTMRx));
  ASSERT_PARAM(IS_DDL_BZTMR_DIVISION(BZTMR_InitStruct->Division));
  ASSERT_PARAM(IS_DDL_BZTMR_DATAWIDTH(BZTMR_InitStruct->DataWidth));
  ASSERT_PARAM(IS_DDL_BZTMR_OUTPUTFORMAT(BZTMR_InitStruct->OutputFormat));
  ASSERT_PARAM(IS_DDL_BZTMR_OUTPUTPOLARITY(BZTMR_InitStruct->ChannelPolarity));
  ASSERT_PARAM(IS_DDL_BZTMR_OUTPUTREVERSAL(BZTMR_InitStruct->OutputReversal));
  ASSERT_PARAM(IS_DDL_BZTMR_NBR_OF_TRANSFER(BZTMR_InitStruct->SequencerLength));
  ASSERT_PARAM(IS_DDL_BZTMR_RESET_TIME(BZTMR_InitStruct->ResetTime));
  ASSERT_PARAM(IS_DDL_BZTMR_RESET_POLARITY(BZTMR_InitStruct->ResetPolarity));

  /* Set the clock division */
  DDL_BZTMR_SetClockDivision(BZTMRx, BZTMR_InitStruct->Division);

  /* Set the data width */
  DDL_BZTMR_SetDataWidth(BZTMRx, BZTMR_InitStruct->DataWidth);

  /* Set the output format */
  DDL_BZTMR_SetOutputFormat(BZTMRx, BZTMR_InitStruct->OutputFormat);

  /* Set the channel polarity */
  DDL_BZTMR_SetChannelPolarity(BZTMRx, BZTMR_InitStruct->ChannelPolarity);

  /* Set the output reversal */
  MODIFY_REG(BZTMRx->CR, BZTMR_CR_OUTPUT_REVERSAL, (BZTMR_InitStruct->OutputReversal) << BZTMR_CR_OUTPUT_REVERSAL_Pos);

  /* Set the number of transfers */
  DDL_BZTMR_SetTransmitSequenceNumber(BZTMRx, BZTMR_InitStruct->SequencerLength);

  /* Set the timing configuration */
  DDL_BZTMR_SetTiming(BZTMRx, BZTMR_InitStruct->Timing);

  /* Set the reset time */
  DDL_BZTMR_SetResetTime(BZTMRx, BZTMR_InitStruct->ResetTime);

  /* Set the reset polarity */
  DDL_BZTMR_SetResetLevelSelect(BZTMRx, BZTMR_InitStruct->ResetPolarity);

  return (SUCCESS);
}

/**
  * @brief Set each @ref DDL_BZTMR_InitTypeDef field to default value.
  * @param BZTMR_InitStruct pointer to a @ref DDL_BZTMR_InitTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */

void DDL_BZTMR_StructInit(DDL_BZTMR_InitTypeDef *BZTMR_InitStruct)
{
  /* Reset BZTMR init structure parameters values */
  BZTMR_InitStruct->Division        = 0U;
  BZTMR_InitStruct->DataWidth       = DDL_BZTMR_DATA_WIDTH_8;
  BZTMR_InitStruct->OutputFormat    = DDL_BZTMR_OUTPUT_FORMAT_LSB;
  BZTMR_InitStruct->ChannelPolarity = DDL_BZTMR_CHANNEL_POLARITY_LOW;
  BZTMR_InitStruct->OutputReversal  = DISABLE;
  BZTMR_InitStruct->SequencerLength = 0U;
  BZTMR_InitStruct->Timing          = 0U;
  BZTMR_InitStruct->ResetTime       = 0U;
  BZTMR_InitStruct->ResetPolarity   = DDL_BZTMR_RESET_OUTPUT_LEVEL_LOW;
}

/**
  * @brief  Initialize BZTMR channel according to the specified parameters in BZTMR_CHInitStruct.
  * @param  BZTMRx BZTMR instance
  * @param  BZTMR_CHInitStruct pointer to a @ref DDL_BZTMR_CH_InitTypeDef structure
  *         that contains the configuration information for the specified BZTMR channel.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BZTMR channel is initialized according to BZTMR_CHInitStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_BZTMR_CH_Init(BZTMR_TypeDef *BZTMRx, DDL_BZTMR_CH_InitTypeDef *BZTMR_CHInitStruct)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_BZTMR_ALL_INSTANCE(BZTMRx));
  ASSERT_PARAM(IS_DDL_BZTMR_CHANNELS(BZTMR_CHInitStruct->Channel));
  ASSERT_PARAM(IS_DDL_BZTMR_RANKS(BZTMR_CHInitStruct->Rank));
  ASSERT_PARAM(IS_DDL_BZTMR_DATA_LENGTH(BZTMR_CHInitStruct->DataLength));
  ASSERT_PARAM(IS_DDL_BZTMR_END_LENGTH(BZTMR_CHInitStruct->EndLength));

  /* Configure the selected channel */
  DDL_BZTMR_SetTransmitSequence(BZTMRx, BZTMR_CHInitStruct->Rank, BZTMR_CHInitStruct->Channel);
  DDL_BZTMR_SetPackageLength(BZTMRx, BZTMR_CHInitStruct->Channel, BZTMR_CHInitStruct->DataLength);
  DDL_BZTMR_SetEndPackageLength(BZTMRx, BZTMR_CHInitStruct->Channel, BZTMR_CHInitStruct->EndLength);

  return (SUCCESS);
}

/**
  * @brief Set each @ref DDL_BZTMR_CH_InitTypeDef field to default value.
  * @param BZTMR_CHInitStruct pointer to a @ref DDL_BZTMR_CH_InitTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */
void DDL_BZTMR_CH_StructInit(DDL_BZTMR_CH_InitTypeDef *BZTMR_CHInitStruct)
{
  /* Reset BZTMR channel init structure parameters values */
  BZTMR_CHInitStruct->Channel    = DDL_BZTMR_CHANNEL_CH0;
  BZTMR_CHInitStruct->Rank       = DDL_BZTMR_SEQ1;
  BZTMR_CHInitStruct->DataLength = 0U;
  BZTMR_CHInitStruct->EndLength  = 0U;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (BZTMR) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

