/**
  *
  * @file    g32f463_ddl_lcdc.h
  * @brief   Header file of LCDC DDL module.
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
#ifndef G32F463_DDL_LCDC_H
#define G32F463_DDL_LCDC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

/** @addtogroup LCDC_DDL
  * @{
  */

/* Exported typedef ----------------------------------------------------------*/

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup LCDC_DDL_ES_INIT LCDC Exported Init structure
  * @{
  */

/**
  * @brief  LCDC Configuration Structure definition
  */
typedef struct
{
  uint32_t MemoryDataWidth;              /*!< Specifies the external memory device width.
                                              This parameter can be a value of @ref LCDC_Data_Width            */

  uint32_t WriteOperation;               /*!< Enables or disables the write operation in the selected device by the LCDC.
                                              This parameter can be a value of @ref LCDC_Write_Operation               */

  uint32_t ExtendedMode;                 /*!< Enables or disables the extended mode.
                                              This parameter can be a value of @ref LCDC_Extended_Mode                 */
} DDL_LCDC_InitTypeDef;

/**
  * @brief  LCDC Timing parameters structure definition
  */
typedef struct
{
  uint32_t ControlSetupTime;             /*!< Defines the number of HCLK cycles to configure
                                              the duration of the control signal setup time.
                                              This parameter can be a value between Min_Data = 0 and Max_Data = 15. */

  uint32_t DataSetupTime;                /*!< Defines the number of HCLK cycles to configure
                                              the duration of the data setup time.
                                              This parameter can be a value between Min_Data = 1 and Max_Data = 255. */

  uint32_t BusTurnAroundDuration;        /*!< Defines the number of HCLK cycles to configure
                                              the duration of the bus turnaround.
                                              This parameter can be a value between Min_Data = 0 and Max_Data = 15. */
} DDL_LCDC_TimingTypeDef;

/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @addtogroup LCDC_DDL_Exported_Constants LCDC Low Layer Exported Constants
  * @{
  */

/** @defgroup LCDC_Data_Width LCDC Data Width
  * @{
  */
#define DDL_LCDC_MEM_BUS_WIDTH_8                (0x00000000U)
#define DDL_LCDC_MEM_BUS_WIDTH_16               (LCDC_CTRL_IDWTH_0)
/**
  * @}
  */

/** @defgroup LCDC_Write_Operation LCDC Write Operation
  * @{
  */
#define DDL_LCDC_WRITE_OPERATION_DISABLE        (0x00000000U)
#define DDL_LCDC_WRITE_OPERATION_ENABLE         (LCDC_CTRL_WREN)
/**
  * @}
  */

/** @defgroup LCDC_Extended_Mode LCDC Extended Mode
  * @{
  */
#define DDL_LCDC_EXTENDED_MODE_DISABLE          (0x00000000U)
#define DDL_LCDC_EXTENDED_MODE_ENABLE           (LCDC_CTRL_EXTMODEEN)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup LCDC_DDL_Exported_Macros LCDC Exported Macros
  * @{
  */

/** @defgroup LCDC_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in LCDC register
  * @param  __INSTANCE__ LCDC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_LCDC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in LCDC register
  * @param  __INSTANCE__ LCDC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_LCDC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup LCDC_DDL_Exported_Functions LCDC DDL Exported Functions
  *  @{
  */

/** @defgroup LCDC_DDL_EF_Configuration Configuration
  *  @{
  */

/**
  * @brief  Enable the LCDC interface access.
  * @param  LCDCx LCDC Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_Enable(LCDC_TypeDef *LCDCx)
{
  SET_BIT(LCDCx->CTRL, LCDC_CTRL_EN);
}

/**
  * @brief  Disable the LCDC interface access.
  * @param  LCDCx LCDC Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_Disable(LCDC_TypeDef *LCDCx)
{
  CLEAR_BIT(LCDCx->CTRL, LCDC_CTRL_EN);
}

/**
  * @brief  Check if the LCDC interface is enabled or disabled.
  * @param  LCDCx LCDC Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_LCDC_IsEnabled(const LCDC_TypeDef *LCDCx)
{
  return ((READ_BIT(LCDCx->CTRL, LCDC_CTRL_EN) == (LCDC_CTRL_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure interface data bus width.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can be one of following value:
  *         @arg @ref DDL_LCDC_MEM_BUS_WIDTH_8
  *         @arg @ref DDL_LCDC_MEM_BUS_WIDTH_16
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_SetDataWidth(LCDC_TypeDef *LCDCx, uint32_t Width)
{
  MODIFY_REG(LCDCx->CTRL, LCDC_CTRL_IDWTH, Width);
}

/**
  * @brief  Get interface data bus width.
  * @param  LCDCx LCDC Instance.
  * @retval This value can be one of following value:
  *         @arg @ref DDL_LCDC_MEM_BUS_WIDTH_8
  *         @arg @ref DDL_LCDC_MEM_BUS_WIDTH_16
  */
__STATIC_INLINE uint32_t DDL_LCDC_GetDataWidth(LCDC_TypeDef *LCDCx)
{
  return READ_BIT(LCDCx->CTRL, LCDC_CTRL_IDWTH);
}

/**
  * @brief  Enable LCDC write.
  * @param  LCDCx LCDC Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_EnableWriteOperation(LCDC_TypeDef *LCDCx)
{
  SET_BIT(LCDCx->CTRL, LCDC_CTRL_WREN);
}

/**
  * @brief  Disable LCDC write.
  * @param  LCDCx LCDC Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_DisableWriteOperation(LCDC_TypeDef *LCDCx)
{
  CLEAR_BIT(LCDCx->CTRL, LCDC_CTRL_WREN);
}

/**
  * @brief  Enable LCDC extended mode.
  * @param  LCDCx LCDC Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_EnableExtendedMode(LCDC_TypeDef *LCDCx)
{
  SET_BIT(LCDCx->CTRL, LCDC_CTRL_EXTMODEEN);
}

/**
  * @brief  Disable LCDC extended mode.
  * @param  LCDCx LCDC Instance.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_DisableExtendedMode(LCDC_TypeDef *LCDCx)
{
  CLEAR_BIT(LCDCx->CTRL, LCDC_CTRL_EXTMODEEN);
}

/**
  * @}
  */

/** @defgroup LCDC_DDL_EF_Time Time
  *  @{
  */

/**
  * @brief  Configure DCX setup time.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can between Min_num=0x0 to Max_num=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_SetControlSetupTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->TIM, LCDC_TIM_DCXSETCFG, Time);
}

/**
  * @brief  Get DCX setup time.
  * @param  LCDCx LCDC Instance.
  * @retval This value can between Min_num=0x0 to Max_num=0xF.
  */
__STATIC_INLINE uint32_t DDL_LCDC_GetControlSetupTime(LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->TIM, LCDC_TIM_DCXSETCFG) >> LCDC_TIM_DCXSETCFG_Pos);
}

/**
  * @brief  Configure data setup time.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can between Min_num=0x01 to Max_num=0xFF.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_SetDataSetupTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->TIM, LCDC_TIM_DATASETCFG, Time);
}

/**
  * @brief  Get data setup time.
  * @param  LCDCx LCDC Instance.
  * @retval This value can between Min_num=0x01 to Max_num=0xFF.
  */
__STATIC_INLINE uint32_t DDL_LCDC_GetDataSetupTime(LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->TIM, LCDC_TIM_DATASETCFG) >> LCDC_TIM_DATASETCFG_Pos);
}

/**
  * @brief  Configure Bus turn around phase duration.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can between Min_num=0x0 to Max_num=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_SetBusTurnAroundDuration(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->TIM, LCDC_TIM_BUSTURNCFG, Time);
}

/**
  * @brief  Get Bus turn around phase duration.
  * @param  LCDCx LCDC Instance.
  * @retval This value can between Min_num=0x0 to Max_num=0xF.
  */
__STATIC_INLINE uint32_t DDL_LCDC_GetBusTurnAroundDuration(LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->TIM, LCDC_TIM_BUSTURNCFG) >> LCDC_TIM_BUSTURNCFG_Pos);
}

/**
  * @brief  Configure write DCX setup time.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can between Min_num=0x0 to Max_num=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_Ex_SetControlSetupTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->WRTTIM, LCDC_WRTTIM_DCXSETCFG, Time);
}

/**
  * @brief  Get write DCX setup time.
  * @param  LCDCx LCDC Instance.
  * @retval This value can between Min_num=0x0 to Max_num=0xF.
  */
__STATIC_INLINE uint32_t DDL_LCDC_Ex_GetControlSetupTime(LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->WRTTIM, LCDC_WRTTIM_DCXSETCFG) >> LCDC_WRTTIM_DCXSETCFG_Pos);
}

/**
  * @brief  Configure data setup time.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can between Min_num=0x01 to Max_num=0xFF.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_Ex_SetDataSetupTime(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->WRTTIM, LCDC_WRTTIM_DATASETCFG, Time);
}

/**
  * @brief  Get data setup time.
  * @param  LCDCx LCDC Instance.
  * @retval This value can between Min_num=0x01 to Max_num=0xFF.
  */
__STATIC_INLINE uint32_t DDL_LCDC_Ex_GetDataSetupTime(LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->WRTTIM, LCDC_WRTTIM_DATASETCFG) >> LCDC_WRTTIM_DATASETCFG_Pos);
}

/**
  * @brief  Configure Bus turn around phase duration.
  * @param  LCDCx LCDC Instance.
  * @param  Width This value can between Min_num=0x0 to Max_num=0xF.
  * @retval None
  */
__STATIC_INLINE void DDL_LCDC_Ex_SetBusTurnAroundDuration(LCDC_TypeDef *LCDCx, uint32_t Time)
{
  MODIFY_REG(LCDCx->WRTTIM, LCDC_WRTTIM_BUSTURNCFG, Time);
}

/**
  * @brief  Get Bus turn around phase duration.
  * @param  LCDCx LCDC Instance.
  * @retval This value can between Min_num=0x0 to Max_num=0xF.
  */
__STATIC_INLINE uint32_t DDL_LCDC_Ex_GetBusTurnAroundDuration(LCDC_TypeDef *LCDCx)
{
  return (READ_BIT(LCDCx->WRTTIM, LCDC_WRTTIM_BUSTURNCFG) >> LCDC_WRTTIM_BUSTURNCFG_Pos);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup LCDC_DDL_EF_Init Initialization and de-initialization functions
  *  @{
  */
ErrorStatus  DDL_LCDC_DeInit(LCDC_TypeDef *LCDCx);
ErrorStatus  DDL_LCDC_Init(LCDC_TypeDef *LCDCx, DDL_LCDC_InitTypeDef *LCDC_InitStruct);
ErrorStatus  DDL_LCDC_Timing_Init(LCDC_TypeDef *LCDCx, DDL_LCDC_TimingTypeDef *LCDC_TimingStruct);
ErrorStatus  DDL_LCDC_Extended_Timing_Init(LCDC_TypeDef *LCDCx, DDL_LCDC_TimingTypeDef *LCDC_TimingStruct, uint32_t ExtendedMode);
void         DDL_LCDC_StructInit(DDL_LCDC_InitTypeDef *LCDC_InitStruct);
void         DDL_LCDC_TimingStructInit(DDL_LCDC_TimingTypeDef *LCDC_TimingStruct);
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

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_LCDC_H */
