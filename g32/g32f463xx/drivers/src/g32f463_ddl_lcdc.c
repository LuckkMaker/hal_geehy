/**
  *
  * @file    g32f463_ddl_lcdc.c
  * @brief   LCDC DDL module driver.
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
  * Copyright (c) 2017 STMicroelectronics. Copyright (C) 2023 Geehy Semiconductor.
  * All rights reserved.
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  */

#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32f463_ddl_lcdc.h"

#ifdef USE_FULL_ASSERT
  #include "g32_assert.h"
#else
#ifndef ASSERT_PARAM
    #define ASSERT_PARAM(_PARAM_) ((void)(0U))
#endif
#endif

/** @addtogroup G32F463_DAL_Driver
  * @{
  */

#if defined(LCDC)

/** @defgroup LCDC_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup LCDC_DDL_Private_Macros
  * @{
  */
#define IS_LCDC_MEMORY_WIDTH(__WIDTH__) (((__WIDTH__) == DDL_LCDC_MEM_BUS_WIDTH_8)  || \
                                         ((__WIDTH__) == DDL_LCDC_MEM_BUS_WIDTH_16))
#define IS_LCDC_WRITE_OPERATION(__OPERATION__) (((__OPERATION__) == DDL_LCDC_WRITE_OPERATION_DISABLE) || \
                                               ((__OPERATION__) == DDL_LCDC_WRITE_OPERATION_ENABLE))
#define IS_LCDC_EXTENDED_MODE(__MODE__) (((__MODE__) == DDL_LCDC_EXTENDED_MODE_DISABLE) || \
                                        ((__MODE__) == DDL_LCDC_EXTENDED_MODE_ENABLE))
#define IS_LCDC_CONTROL_SETUP_TIME(__TIME__) ((__TIME__) <= 15U)
#define IS_LCDC_DATASETUP_TIME(__TIME__) (((__TIME__) > 0U) && ((__TIME__) <= 255U))
#define IS_LCDC_TURNAROUND_TIME(__TIME__) ((__TIME__) <= 15U)
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup LCDC_DDL_Exported_Functions
  * @{
  */

/** @defgroup LCDC_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize the LCDC registers (Registers restored to their default values).
  * @param  LCDCx LCDC instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: LCDC registers are de-initialized
  *          - ERROR:   Wrong LCDC instance
  */
ErrorStatus DDL_LCDC_DeInit(LCDC_TypeDef *LCDCx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_LCDC_ALL_INSTANCE(LCDCx));

  if (LCDCx == LCDC)
  {
    LCDCx->CTRL = 0x000030D3U;
    LCDCx->TIM = 0x0FFFFFFFU;
    LCDCx->WRTTIM = 0x0FFFFFFFU;
  }
  else
  {
    status = ERROR;
  }

  return (status);
}

/**
  * @brief  Initialize the LCDC_device according to the specified
  *         control parameters in the DDL_LCDC_InitTypeDef
  * @param  LCDCx LCDC instance
  * @param  LCDC_InitStruct Pointer to a @ref DDL_LCDC_InitTypeDef structure
  *         that contains the configuration information for the specified LCDC peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: LCDC registers are initialized according to LCDC_InitStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_LCDC_Init(LCDC_TypeDef *LCDCx, DDL_LCDC_InitTypeDef *LCDC_InitStruct)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_LCDC_ALL_INSTANCE(LCDCx));
  ASSERT_PARAM(IS_LCDC_MEMORY_WIDTH(LCDC_InitStruct->MemoryDataWidth));
  ASSERT_PARAM(IS_LCDC_WRITE_OPERATION(LCDC_InitStruct->WriteOperation));
  ASSERT_PARAM(IS_LCDC_EXTENDED_MODE(LCDC_InitStruct->ExtendedMode));

  /* Set the data width */
  DDL_LCDC_SetDataWidth(LCDCx, LCDC_InitStruct->MemoryDataWidth);

  /* Set the write operation */
  MODIFY_REG(LCDCx->CTRL, LCDC_CTRL_WREN, LCDC_InitStruct->WriteOperation);

  /* Set the extended mode */
  MODIFY_REG(LCDCx->CTRL, LCDC_CTRL_EXTMODEEN, LCDC_InitStruct->ExtendedMode);

  return (SUCCESS);
}

/**
  * @brief  Initialize the LCDC registers according to the specified parameters in LCDC_TimingStruct
  * @param  LCDCx LCDC instance
  * @param  LCDC_TimingStruct Pointer to a @ref DDL_LCDC_TimingTypeDef structure
  *         that contains the configuration information for the specified LCDC peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: LCDC registers are initialized according to LCDC_TimingStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_LCDC_Timing_Init(LCDC_TypeDef *LCDCx, DDL_LCDC_TimingTypeDef *LCDC_TimingStruct)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_LCDC_ALL_INSTANCE(LCDCx));
  ASSERT_PARAM(IS_LCDC_CONTROL_SETUP_TIME(LCDC_TimingStruct->ControlSetupTime));
  ASSERT_PARAM(IS_LCDC_DATASETUP_TIME(LCDC_TimingStruct->DataSetupTime));
  ASSERT_PARAM(IS_LCDC_TURNAROUND_TIME(LCDC_TimingStruct->BusTurnAroundDuration));

  /* Set the control setup time */
  DDL_LCDC_SetControlSetupTime(LCDCx, LCDC_TimingStruct->ControlSetupTime);

  /* Set the data setup time */
  DDL_LCDC_SetDataSetupTime(LCDCx, LCDC_TimingStruct->DataSetupTime);

  /* Set the bus turn around duration */
  DDL_LCDC_SetBusTurnAroundDuration(LCDCx, LCDC_TimingStruct->BusTurnAroundDuration);

  return (SUCCESS);
}

/**
  * @brief  Initialize the LCDC_Extended mode Timing according to the specified
  *         parameters in the DDL_LCDC_TimingTypeDef
  * @param  LCDCx LCDC instance
  * @param  LCDC_TimingStruct Pointer to a @ref DDL_LCDC_TimingTypeDef structure
  *         that contains the configuration information for the specified LCDC peripheral.
  * @param  ExtendedMode LCDC Extended Mode
  *          This parameter can be one of the following values:
  *            @arg DDL_LCDC_EXTENDED_MODE_DISABLE
  *            @arg DDL_LCDC_EXTENDED_MODE_ENABLE
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: LCDC registers are initialized according to LCDC_TimingStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_LCDC_Extended_Timing_Init(LCDC_TypeDef *LCDCx, DDL_LCDC_TimingTypeDef *LCDC_TimingStruct, uint32_t ExtendedMode)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_LCDC_EXTENDED_MODE(ExtendedMode));

  /* Set device timing register for write configuration, if extended mode is used */
  if (ExtendedMode == DDL_LCDC_EXTENDED_MODE_ENABLE)
  {
    /* Check the parameters */
    ASSERT_PARAM(IS_LCDC_ALL_INSTANCE(LCDCx));
    ASSERT_PARAM(IS_LCDC_CONTROL_SETUP_TIME(LCDC_TimingStruct->ControlSetupTime));
    ASSERT_PARAM(IS_LCDC_DATASETUP_TIME(LCDC_TimingStruct->DataSetupTime));
    ASSERT_PARAM(IS_LCDC_TURNAROUND_TIME(LCDC_TimingStruct->BusTurnAroundDuration));

    /* Set the control setup time */
    DDL_LCDC_Ex_SetControlSetupTime(LCDCx, LCDC_TimingStruct->ControlSetupTime);

    /* Set the data setup time */
    DDL_LCDC_Ex_SetDataSetupTime(LCDCx, LCDC_TimingStruct->DataSetupTime);

    /* Set the bus turn around duration */
    DDL_LCDC_Ex_SetBusTurnAroundDuration(LCDCx, LCDC_TimingStruct->BusTurnAroundDuration);

  }
  else
  {
    LCDCx->WRTTIM = 0x0FFFFFFFU;
  }

  return (SUCCESS);
}

/**
  * @brief Set each @ref DDL_LCDC_InitTypeDef field to default value.
  * @param LCDC_InitStruct pointer to a @ref DDL_LCDC_InitTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */

void DDL_LCDC_StructInit(DDL_LCDC_InitTypeDef *LCDC_InitStruct)
{
  /* Reset LCDC init structure parameters values */
  LCDC_InitStruct->MemoryDataWidth  = DDL_LCDC_MEM_BUS_WIDTH_8;
  LCDC_InitStruct->WriteOperation   = DDL_LCDC_WRITE_OPERATION_DISABLE;
  LCDC_InitStruct->ExtendedMode     = DDL_LCDC_EXTENDED_MODE_DISABLE;
}

/**
  * @brief Set each @ref DDL_LCDC_TimingTypeDef field to default value.
  * @param LCDC_TimingStruct pointer to a @ref DDL_LCDC_TimingTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */
void DDL_LCDC_TimingStructInit(DDL_LCDC_TimingTypeDef *LCDC_TimingStruct)
{
  /* Reset LCDC init structure parameters values */
  LCDC_TimingStruct->ControlSetupTime       = 0xF;
  LCDC_TimingStruct->DataSetupTime          = 0xFF;
  LCDC_TimingStruct->BusTurnAroundDuration  = 0xF;
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

#endif /* defined (LCDC) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
