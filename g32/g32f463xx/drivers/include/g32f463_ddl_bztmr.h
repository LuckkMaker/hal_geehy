/**
  *
  * @file    g32f463_ddl_bztmr.h
  * @brief   Header file of BZTMR DDL module.
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
#ifndef G32F463_DDL_BZTMR_H
#define G32F463_DDL_BZTMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (BZTMR)

/** @defgroup BZTMR_DDL BZTMR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup TMR_DDL_Private_Variables TMR Private Variables
  * @{
  */
static const uint8_t OFFSET_TAB_OFRx[] =
{
  0x00U,   /* 0: BZTMR_CH1   */
  0x00U,   /* 1: BZTMR_CH2   */
  0x04U,   /* 2: BZTMR_CH3   */
  0x04U,   /* 3: BZTMR_CH4   */
  0x08U,   /* 4: BZTMR_CH5   */
  0x08U,   /* 5: BZTMR_CH6   */
  0x0CU,   /* 6: BZTMR_CH7   */
  0x0CU,   /* 7: BZTMR_CH8   */
  0x10U,   /* 8: BZTMR_CH9   */
  0x10U,   /* 9: BZTMR_CH10  */
};

static const uint8_t OFFSET_TAB_CSRx[] =
{
  0x00U,   /* 0: BZTMR_SEQ1  */
  0x00U,   /* 1: BZTMR_SEQ2  */
  0x00U,   /* 2: BZTMR_SEQ3  */
  0x00U,   /* 3: BZTMR_SEQ4  */
  0x00U,   /* 4: BZTMR_SEQ5  */
  0x00U,   /* 5: BZTMR_SEQ6  */
  0x00U,   /* 6: BZTMR_SEQ7  */
  0x04U,   /* 7: BZTMR_SEQ8  */
  0x04U,   /* 8: BZTMR_SEQ9  */
  0x04U,   /* 9: BZTMR_SEQ10 */
};

static const uint8_t SHIFT_TAB_EL[] =
{
  0x09U,   /* 0: OFR1_EL1  */
  0x19U,   /* 1: OFR1_EL2  */
  0x09U,   /* 2: OFR2_EL1  */
  0x19U,   /* 3: OFR2_EL2  */
  0x09U,   /* 4: OFR3_EL1  */
  0x19U,   /* 5: OFR3_EL2  */
  0x09U,   /* 6: OFR4_EL1  */
  0x19U,   /* 7: OFR4_EL2  */
  0x09U,   /* 8: OFR5_EL1  */
  0x19U,   /* 9: OFR5_EL2  */
};

static const uint8_t SHIFT_TAB_DL[] =
{
  0x00U,   /* 0: OFR1_DL1  */
  0x10U,   /* 1: OFR1_DL2  */
  0x00U,   /* 2: OFR2_DL1  */
  0x10U,   /* 3: OFR2_DL2  */
  0x00U,   /* 4: OFR3_DL1  */
  0x10U,   /* 5: OFR3_DL2  */
  0x00U,   /* 6: OFR4_DL1  */
  0x10U,   /* 7: OFR4_DL2  */
  0x00U,   /* 8: OFR5_DL1  */
  0x10U,   /* 9: OFR5_DL2  */
};

static const uint8_t SHIFT_TAB_SEQ[] =
{
  0x04U,   /* 0: CSR1_SEQ1  */
  0x08U,   /* 1: CSR1_SEQ2  */
  0x0CU,   /* 2: CSR1_SEQ3  */
  0x10U,   /* 3: CSR1_SEQ4  */
  0x14U,   /* 4: CSR1_SEQ5  */
  0x18U,   /* 5: CSR1_SEQ6  */
  0x1CU,   /* 6: CSR1_SEQ7  */
  0x00U,   /* 7: CSR2_SEQ8  */
  0x04U,   /* 8: CSR2_SEQ9  */
  0x08U,   /* 9: CSR2_SEQ10 */
};

/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup BZTMR_DDL_Private_Macros BZTMR Private Macros
  * @{
  */

/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup BZTMR_DDL_ES_INIT BZTMR Exported Init structures
  * @{
  */

/**
  * @brief LL BZTMR Init Structure definition
  */
typedef struct
{
  uint32_t Division;      /*!< Specifies the clock division.

                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetClockDivision().*/

  uint32_t DataWidth;     /*!< Specifies the data package width.
                              This parameter can be any value of @ref BZTMR_DDL_EC_DATA_WIDTH

                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetDataWidth().*/

  uint32_t OutputFormat;  /*!< Specifies the output format.
                              This parameter can be any value of @ref BZTMR_DDL_EC_OUTPUT_FORMAT

                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetOutputFormat().*/

  uint32_t ChannelPolarity;  /*!< Specifies the channel polarity.
                              This parameter can be any value of @ref BZTMR_DDL_EC_CHANNEL_POLARITY

                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetChannelPolarity().*/

  uint32_t OutputReversal;  /*!< Specifies whether the output is reversed.
                                This parameter can be a value of ENABLE or DISABLE.

                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_EnableOutputReverse().*/

  uint32_t SequencerLength;  /*!< Specifies the number of channels to be transferred.
                              This parameter can be a value between Min_Data = 0x00 and Max_Data = 0x0A.
                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetTransmitSequenceNumber().*/

  uint32_t Timing;        /*!< Specifies the timing configuration.
                              This parameter must be a combination of the following values:

                              - T0L:   BZTMR_DTR_T0L (8 bits)
                              - T0H:   BZTMR_DTR_T0H (8 bits)
                              - T1L:   BZTMR_DTR_T1L (8 bits)
                              - T1H:   BZTMR_DTR_T1H (8 bits)

                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetTiming().*/

  uint32_t ResetTime;    /*!< Specifies the reset time.
                              This parameter must be a number Min_Data = 0x00 and Max_Data = 0xFFFF
                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetResetTime().*/

  uint32_t ResetPolarity; /*!< Specifies the reset polarity.
                              This parameter can be a value of @ref BZTMR_DDL_EC_RESET_POLARITY
                              BZTMR HW configuration can be modified afterwards using unitary function @ref DDL_BZTMR_SetResetLevelSelect().*/
} DDL_BZTMR_InitTypeDef;

/**
  * @brief  Structure definition for BZTMR channel configuration
  */
typedef struct
{
  uint32_t Channel;      /*!< Specifies the BZTMR channel.
                              This parameter can be a value of @ref BZTMR_DDL_EC_CHANNEL */

  uint32_t Rank;         /*!< Specifies the rank in the sequencer.
                              This parameter can be a value of @ref BZTMR_DDL_EC_SEQUENCY */

  uint32_t DataLength;   /*!< Specifies the data package length for the channel.
                              This parameter must be a number Min_Data = 0x00 and Max_Data = 0x1FF */

  uint32_t EndLength;    /*!< Specifies the end package length for the channel.
                              This parameter must be a number Min_Data = 0x00 and Max_Data = 0x1F */
} DDL_BZTMR_CH_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup BZTMR_DDL_Exported_Constants BZTMR Exported Constants
  * @{
  */

/** @defgroup BZTMR_DDL_EC_CHANNEL Channel
  * @{
  */
#define DDL_BZTMR_CHANNEL_CH0                 0x00000000U
#define DDL_BZTMR_CHANNEL_CH1                 0x00000001U
#define DDL_BZTMR_CHANNEL_CH2                 0x00000002U
#define DDL_BZTMR_CHANNEL_CH3                 0x00000003U
#define DDL_BZTMR_CHANNEL_CH4                 0x00000004U
#define DDL_BZTMR_CHANNEL_CH5                 0x00000005U
#define DDL_BZTMR_CHANNEL_CH6                 0x00000006U
#define DDL_BZTMR_CHANNEL_CH7                 0x00000007U
#define DDL_BZTMR_CHANNEL_CH8                 0x00000008U
#define DDL_BZTMR_CHANNEL_CH9                 0x00000009U
/**
  * @}
  */

/** @defgroup BZTMR_DDL_EC_SEQUENCY Sequency
  * @{
  */
#define DDL_BZTMR_SEQ1                        0x00000000U
#define DDL_BZTMR_SEQ2                        0x00000001U
#define DDL_BZTMR_SEQ3                        0x00000002U
#define DDL_BZTMR_SEQ4                        0x00000003U
#define DDL_BZTMR_SEQ5                        0x00000004U
#define DDL_BZTMR_SEQ6                        0x00000005U
#define DDL_BZTMR_SEQ7                        0x00000006U
#define DDL_BZTMR_SEQ8                        0x00000007U
#define DDL_BZTMR_SEQ9                        0x00000008U
#define DDL_BZTMR_SEQ10                       0x00000009U
/**
  * @}
  */

/** @defgroup BZTMR_DDL_EC_DATA_WIDTH Data Width
  * @{
  */
#define DDL_BZTMR_DATA_WIDTH_8                0x00000000U
#define DDL_BZTMR_DATA_WIDTH_16               BZTMR_CR_DATA_WIDTH_0
#define DDL_BZTMR_DATA_WIDTH_24               BZTMR_CR_DATA_WIDTH_1
#define DDL_BZTMR_DATA_WIDTH_32               (BZTMR_CR_DATA_WIDTH_1 | BZTMR_CR_DATA_WIDTH_0)
/**
  * @}
  */

/** @defgroup BZTMR_DDL_EC_OUTPUT_FORMAT Output Format
  * @{
  */
#define DDL_BZTMR_OUTPUT_FORMAT_LSB           0x00000000U
#define DDL_BZTMR_OUTPUT_FORMAT_MSB           BZTMR_CR_FORMAT_OUTPUT
/**
  * @}
  */

/** @defgroup BZTMR_DDL_EC_CHANNEL_POLARITY Channel Polarity
  * @{
  */
#define DDL_BZTMR_CHANNEL_POLARITY_LOW        0x00000000U
#define DDL_BZTMR_CHANNEL_POLARITY_HIGH       BZTMR_CR_INIT_POL
/**
  * @}
  */

/** @defgroup BZTMR_DDL_EC_RESET_POLARITY Reset Polarity
  * @{
  */
#define DDL_BZTMR_RESET_OUTPUT_LEVEL_LOW      0x00000000U
#define DDL_BZTMR_RESET_OUTPUT_LEVEL_HIGH     BZTMR_RFR_RESET_SELECT
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup BZTMR_DDL_Exported_Macros BZTMR Exported Macros
  * @{
  */

/** @defgroup BZTMR_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in BZTMR register
  * @param  __INSTANCE__ BZTMR Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_BZTMR_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in BZTMR register
  * @param  __INSTANCE__ BZTMR Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_BZTMR_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup BZTMR_DDL_Exported_Functions BZTMR Exported Functions
  * @{
  */

/** @defgroup BZTMR_DDL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Enable BZTMR.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_Enable(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->CR, BZTMR_CR_BZTMREN);
}

/**
  * @brief  Disable BZTMR.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_Disable(BZTMR_TypeDef *BZTMRx)
{
  CLEAR_BIT(BZTMRx->CR, BZTMR_CR_BZTMREN);
}

/**
  * @brief  Enable BZTMR DMA request.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_EnableDMAReq(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->CR, BZTMR_CR_DMAEN);
}

/**
  * @brief  Disable BZTMR DMA request.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_DisableDMAReq(BZTMR_TypeDef *BZTMRx)
{
  CLEAR_BIT(BZTMRx->CR, BZTMR_CR_DMAEN);
}

/**
  * @brief  Configure initial value of channel polarity.
  * @param  BZTMRx BZTMR instance
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref DDL_BZTMR_CHANNEL_POLARITY_LOW
  *         @arg @ref DDL_BZTMR_CHANNEL_POLARITY_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetChannelPolarity(BZTMR_TypeDef *BZTMRx, uint32_t Polarity)
{
  MODIFY_REG(BZTMRx->CR, BZTMR_CR_INIT_POL, Polarity);
}

/**
  * @brief  Get initial value of channel polarity.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can be one of the following values:
  *         @arg @ref DDL_BZTMR_CHANNEL_POLARITY_LOW
  *         @arg @ref DDL_BZTMR_CHANNEL_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetChannelPolarity(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->CR, BZTMR_CR_INIT_POL));
}

/**
  * @brief  Configure output format.
  * @param  BZTMRx BZTMR instance
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref DDL_BZTMR_OUTPUT_FORMAT_LSB
  *         @arg @ref DDL_BZTMR_OUTPUT_FORMAT_MSB
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetOutputFormat(BZTMR_TypeDef *BZTMRx, uint32_t Format)
{
  MODIFY_REG(BZTMRx->CR, BZTMR_CR_FORMAT_OUTPUT, Format);
}

/**
  * @brief  Get output format.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can be one of the following values:
  *         @arg @ref DDL_BZTMR_OUTPUT_FORMAT_LSB
  *         @arg @ref DDL_BZTMR_OUTPUT_FORMAT_MSB
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetOutputFormat(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->CR, BZTMR_CR_FORMAT_OUTPUT));
}

/**
  * @brief  Enable output reverse.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_EnableOutputReverse(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->CR, BZTMR_CR_OUTPUT_REVERSE);
}

/**
  * @brief  Disable output reverse.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_DisableOutputReverse(BZTMR_TypeDef *BZTMRx)
{
  CLEAR_BIT(BZTMRx->CR, BZTMR_CR_OUTPUT_REVERSE);
}

/**
  * @brief  Configure data width.
  * @param  BZTMRx BZTMR instance
  * @param  Width This parameter can be one of the following values:
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_8
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_16
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_24
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_32
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetDataWidth(BZTMR_TypeDef *BZTMRx, uint32_t Width)
{
  MODIFY_REG(BZTMRx->CR, BZTMR_CR_DATA_WIDTH, Width);
}

/**
  * @brief  Get data width.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can be one of the following values:
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_8
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_16
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_24
  *         @arg @ref DDL_BZTMR_DATA_WIDTH_32
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetDataWidth(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->CR, BZTMR_CR_DATA_WIDTH));
}

/**
  * @brief  Configure low level time 0.
  * @param  BZTMRx BZTMR instance
  * @param  Time This parameter can between Min_num=0x0 and Max_num=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetLowLevelTime0(BZTMR_TypeDef *BZTMRx, uint32_t Time)
{
  MODIFY_REG(BZTMRx->DTR, BZTMR_DTR_T0L, Time << BZTMR_DTR_T0L_Pos);
}

/**
  * @brief  Get low level time 0.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetLowLevelTime0(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->DTR, BZTMR_DTR_T0L));
}

/**
  * @brief  Configure high level time 0.
  * @param  BZTMRx BZTMR instance
  * @param  Time This parameter can between Min_num=0x0 and Max_num=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetHighLevelTime0(BZTMR_TypeDef *BZTMRx, uint32_t Time)
{
  MODIFY_REG(BZTMRx->DTR, BZTMR_DTR_T0H, Time << BZTMR_DTR_T0H_Pos);
}

/**
  * @brief  Get high level time 0.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetHighLevelTime0(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->DTR, BZTMR_DTR_T0H) >> BZTMR_DTR_T0H_Pos);
}

/**
  * @brief  Configure low level time 1.
  * @param  BZTMRx BZTMR instance
  * @param  Time This parameter can between Min_num=0x0 and Max_num=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetLowLevelTime1(BZTMR_TypeDef *BZTMRx, uint32_t Time)
{
  MODIFY_REG(BZTMRx->DTR, BZTMR_DTR_T1L, Time << BZTMR_DTR_T1L_Pos);
}

/**
  * @brief  Get low level time 1.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetLowLevelTime1(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->DTR, BZTMR_DTR_T1L) >> BZTMR_DTR_T1L_Pos);
}

/**
  * @brief  Configure high level time 1.
  * @param  BZTMRx BZTMR instance
  * @param  Time This parameter can between Min_num=0x0 and Max_num=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetHighLevelTime1(BZTMR_TypeDef *BZTMRx, uint32_t Time)
{
  MODIFY_REG(BZTMRx->DTR, BZTMR_DTR_T1H, Time << BZTMR_DTR_T1H_Pos);
}

/**
  * @brief  Get high level time 1.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetHighLevelTime1(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->DTR, BZTMR_DTR_T1H) >> BZTMR_DTR_T1H_Pos);
}

/**
  * @brief  Configure timing.
  * @param  BZTMRx BZTMR instance
  * @param  Timing This parameter must be a combination of the following values:
  *         - T0L:   BZTMR_DTR_T0L (8 bits)
  *         - T0H:   BZTMR_DTR_T0H (8 bits)
  *         - T1L:   BZTMR_DTR_T1L (8 bits)
  *         - T1H:   BZTMR_DTR_T1H (8 bits)
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetTiming(BZTMR_TypeDef *BZTMRx, uint32_t Timing)
{
  WRITE_REG(BZTMRx->DTR, Timing);
}

/**
  * @brief  Get timing.
  * @param  BZTMRx BZTMR instance
  * @retval This return value is combination of the following values:
  *         - T0L:   BZTMR_DTR_T0L (8 bits)
  *         - T0H:   BZTMR_DTR_T0H (8 bits)
  *         - T1L:   BZTMR_DTR_T1L (8 bits)
  *         - T1H:   BZTMR_DTR_T1H (8 bits)
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetTiming(BZTMR_TypeDef *BZTMRx)
{
  return (READ_REG(BZTMRx->DTR));
}

/**
  * @brief  Enable reset output.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_EnableResetOutput(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->RFR, BZTMR_RFR_RSTEN);
}

/**
  * @brief  Disable reset output.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_DisableResetOutput(BZTMR_TypeDef *BZTMRx)
{
  CLEAR_BIT(BZTMRx->RFR, BZTMR_RFR_RSTEN);
}

/**
  * @brief  Configure reset level selection.
  * @param  BZTMRx BZTMR instance
  * @param  Level This parameter can be one of the following values:
  *         @arg @ref DDL_BZTMR_RESET_OUTPUT_LEVEL_LOW
  *         @arg @ref DDL_BZTMR_RESET_OUTPUT_LEVEL_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetResetLevelSelect(BZTMR_TypeDef *BZTMRx, uint32_t Level)
{
  MODIFY_REG(BZTMRx->RFR, BZTMR_RFR_RESET_SELECT, Level);
}

/**
  * @brief  Get reset level selection.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can be one of the following values:
  *         @arg @ref DDL_BZTMR_RESET_OUTPUT_LEVEL_LOW
  *         @arg @ref DDL_BZTMR_RESET_OUTPUT_LEVEL_HIGH
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetResetLevelSelect(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->RFR, BZTMR_RFR_RESET_SELECT));
}

/**
  * @brief  Configure reset time.
  * @param  BZTMRx BZTMR instance
  * @param  Time This parameter can between Min_num=0x0 and Max_num=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetResetTime(BZTMR_TypeDef *BZTMRx, uint32_t Time)
{
  MODIFY_REG(BZTMRx->RFR, BZTMR_RFR_RESET_TIME, Time << BZTMR_RFR_RESET_TIME_Pos);
}

/**
  * @brief  Get reset time.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetResetTime(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->RFR, BZTMR_RFR_RESET_TIME));
}

/**
  * @brief  Write data.
  * @param  BZTMRx BZTMR instance
  * @param  Time This parameter can between Min_num=0x0 and Max_num=0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_TxData(BZTMR_TypeDef *BZTMRx, uint32_t Data)
{
  WRITE_REG(BZTMRx->DR, Data);
}

/**
  * @brief  Read data.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetData(BZTMR_TypeDef *BZTMRx)
{
  return (READ_REG(BZTMRx->DR));
}

/**
  * @brief  Configura data package length.
  * @param  BZTMRx BZTMR instance
  * @param  Channel This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_CHANNEL_CH0
  *         @arg @ref DDL_BZTMR_CHANNEL_CH1
  *         @arg @ref DDL_BZTMR_CHANNEL_CH2
  *         @arg @ref DDL_BZTMR_CHANNEL_CH3
  *         @arg @ref DDL_BZTMR_CHANNEL_CH4
  *         @arg @ref DDL_BZTMR_CHANNEL_CH5
  *         @arg @ref DDL_BZTMR_CHANNEL_CH6
  *         @arg @ref DDL_BZTMR_CHANNEL_CH7
  *         @arg @ref DDL_BZTMR_CHANNEL_CH8
  *         @arg @ref DDL_BZTMR_CHANNEL_CH9
  * @param  Length This parameter can between Min_num=0x0 and Max_num=0x1F
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetPackageLength(BZTMR_TypeDef *BZTMRx, uint32_t Channel, uint32_t Length)
{
  __IO uint32_t* reg = (__IO uint32_t *)((uint32_t)(&BZTMRx->OFR1) + OFFSET_TAB_OFRx[Channel]);
  MODIFY_REG(*reg, (BZTMR_OFR1_CH1_DATA_LENGTH << SHIFT_TAB_DL[Channel]), (Length << SHIFT_TAB_DL[Channel]));
}

/**
  * @brief  Get data package length.
  * @param  BZTMRx BZTMR instance
  * @param  Channel This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_CHANNEL_CH0
  *         @arg @ref DDL_BZTMR_CHANNEL_CH1
  *         @arg @ref DDL_BZTMR_CHANNEL_CH2
  *         @arg @ref DDL_BZTMR_CHANNEL_CH3
  *         @arg @ref DDL_BZTMR_CHANNEL_CH4
  *         @arg @ref DDL_BZTMR_CHANNEL_CH5
  *         @arg @ref DDL_BZTMR_CHANNEL_CH6
  *         @arg @ref DDL_BZTMR_CHANNEL_CH7
  *         @arg @ref DDL_BZTMR_CHANNEL_CH8
  *         @arg @ref DDL_BZTMR_CHANNEL_CH9
  * @retval This return value can between Min_num=0x0 and Max_num=0x1F
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetPackageLength(BZTMR_TypeDef *BZTMRx, uint32_t Channel)
{
  __IO uint32_t* reg = (__IO uint32_t *)((uint32_t)(&BZTMRx->OFR1) + OFFSET_TAB_OFRx[Channel]);
  return (READ_BIT(*reg, (BZTMR_OFR1_CH1_DATA_LENGTH << SHIFT_TAB_DL[Channel])) >> SHIFT_TAB_DL[Channel]);
}

/**
  * @brief  Configure end package length.
  * @param  BZTMRx BZTMR instance
  * @param  Channel This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_CHANNEL_CH0
  *         @arg @ref DDL_BZTMR_CHANNEL_CH1
  *         @arg @ref DDL_BZTMR_CHANNEL_CH2
  *         @arg @ref DDL_BZTMR_CHANNEL_CH3
  *         @arg @ref DDL_BZTMR_CHANNEL_CH4
  *         @arg @ref DDL_BZTMR_CHANNEL_CH5
  *         @arg @ref DDL_BZTMR_CHANNEL_CH6
  *         @arg @ref DDL_BZTMR_CHANNEL_CH7
  *         @arg @ref DDL_BZTMR_CHANNEL_CH8
  *         @arg @ref DDL_BZTMR_CHANNEL_CH9
  * @param  Length This parameter can between Min_num=0x0 and Max_num=0x1F
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetEndPackageLength(BZTMR_TypeDef *BZTMRx, uint32_t Channel, uint32_t Length)
{
  __IO uint32_t* reg = (__IO uint32_t *)((uint32_t)(&BZTMRx->OFR1) + OFFSET_TAB_OFRx[Channel]);
  MODIFY_REG(*reg, (BZTMR_OFR1_CH1_END_LENGTH << (SHIFT_TAB_EL[Channel] - BZTMR_OFR1_CH1_END_LENGTH_Pos)), (Length << SHIFT_TAB_EL[Channel]));
}

/**
  * @brief  Get end package length.
  * @param  BZTMRx BZTMR instance
  * @param  Channel This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_CHANNEL_CH0
  *         @arg @ref DDL_BZTMR_CHANNEL_CH1
  *         @arg @ref DDL_BZTMR_CHANNEL_CH2
  *         @arg @ref DDL_BZTMR_CHANNEL_CH3
  *         @arg @ref DDL_BZTMR_CHANNEL_CH4
  *         @arg @ref DDL_BZTMR_CHANNEL_CH5
  *         @arg @ref DDL_BZTMR_CHANNEL_CH6
  *         @arg @ref DDL_BZTMR_CHANNEL_CH7
  *         @arg @ref DDL_BZTMR_CHANNEL_CH8
  *         @arg @ref DDL_BZTMR_CHANNEL_CH9
  * @retval This return value can between Min_num=0x0 and Max_num=0x1F
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetEndPackageLength(BZTMR_TypeDef *BZTMRx, uint32_t Channel)
{
  __IO uint32_t* reg = (__IO uint32_t *)((uint32_t)(&BZTMRx->OFR1) + OFFSET_TAB_OFRx[Channel]);
  return (READ_BIT(*reg, (BZTMR_OFR1_CH1_END_LENGTH << (SHIFT_TAB_EL[Channel] - BZTMR_OFR1_CH1_END_LENGTH_Pos))) >> SHIFT_TAB_EL[Channel]);
}

/**
  * @brief  Configure clock division.
  * @param  BZTMRx BZTMR instance
  * @param  Division This parameter can between Min_num=0x0 and Max_num=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetClockDivision(BZTMR_TypeDef *BZTMRx, uint32_t Division)
{
  MODIFY_REG(BZTMRx->CDR, BZTMR_CDR_PCLK_DIV, Division);
}

/**
  * @brief  Get clock division.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0x0 and Max_num=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetClockDivision(BZTMR_TypeDef *BZTMRx)
{
  return READ_BIT(BZTMRx->CDR, BZTMR_CDR_PCLK_DIV);
}

/**
  * @brief  Configure transmit sequence number.
  * @param  BZTMRx BZTMR instance
  * @param  Number This parameter can between Min_num=0x0 and Max_num=10
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetTransmitSequenceNumber(BZTMR_TypeDef *BZTMRx, uint32_t Number)
{
  MODIFY_REG(BZTMRx->CSR1, BZTMR_CSR1_SEQ_LEN, Number);
}

/**
  * @brief  Get transmit sequence number.
  * @param  BZTMRx BZTMR instance
  * @retval This return value can between Min_num=0 and Max_num=10
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetTransmitSequenceNumber(BZTMR_TypeDef *BZTMRx)
{
  return READ_BIT(BZTMRx->CSR1, BZTMR_CSR1_SEQ_LEN);
}

/**
  * @brief  Configure the channel for the transmit squence.
  * @param  BZTMRx BZTMR instance
  * @param  Sequence This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_SEQ1
  *         @arg @ref DDL_BZTMR_SEQ2
  *         @arg @ref DDL_BZTMR_SEQ3
  *         @arg @ref DDL_BZTMR_SEQ4
  *         @arg @ref DDL_BZTMR_SEQ5
  *         @arg @ref DDL_BZTMR_SEQ6
  *         @arg @ref DDL_BZTMR_SEQ7
  *         @arg @ref DDL_BZTMR_SEQ8
  *         @arg @ref DDL_BZTMR_SEQ9
  *         @arg @ref DDL_BZTMR_SEQ10
  * @param  Channel This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_CHANNEL_CH0
  *         @arg @ref DDL_BZTMR_CHANNEL_CH1
  *         @arg @ref DDL_BZTMR_CHANNEL_CH2
  *         @arg @ref DDL_BZTMR_CHANNEL_CH3
  *         @arg @ref DDL_BZTMR_CHANNEL_CH4
  *         @arg @ref DDL_BZTMR_CHANNEL_CH5
  *         @arg @ref DDL_BZTMR_CHANNEL_CH6
  *         @arg @ref DDL_BZTMR_CHANNEL_CH7
  *         @arg @ref DDL_BZTMR_CHANNEL_CH8
  *         @arg @ref DDL_BZTMR_CHANNEL_CH9
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_SetTransmitSequence(BZTMR_TypeDef *BZTMRx, uint32_t Sequence, uint32_t Channel)
{
  __IO uint32_t* reg = (__IO uint32_t *)((uint32_t)(&BZTMRx->CSR1) + OFFSET_TAB_CSRx[Sequence]);
  MODIFY_REG(*reg, (BZTMR_CSR2_SEQ8 << SHIFT_TAB_SEQ[Sequence]), ((Channel + 1) << SHIFT_TAB_SEQ[Sequence]));
}

/**
  * @brief  Get the channel for the transmit squence.
  * @param  BZTMRx BZTMR instance
  * @param  Sequence This parameter can be one of following parameter:
  *         @arg @ref DDL_BZTMR_SEQ1
  *         @arg @ref DDL_BZTMR_SEQ2
  *         @arg @ref DDL_BZTMR_SEQ3
  *         @arg @ref DDL_BZTMR_SEQ4
  *         @arg @ref DDL_BZTMR_SEQ5
  *         @arg @ref DDL_BZTMR_SEQ6
  *         @arg @ref DDL_BZTMR_SEQ7
  *         @arg @ref DDL_BZTMR_SEQ8
  *         @arg @ref DDL_BZTMR_SEQ9
  *         @arg @ref DDL_BZTMR_SEQ10
  * @retval This return value can be one of following parameter:
  *         @arg @ref DDL_BZTMR_CHANNEL_CH0
  *         @arg @ref DDL_BZTMR_CHANNEL_CH1
  *         @arg @ref DDL_BZTMR_CHANNEL_CH2
  *         @arg @ref DDL_BZTMR_CHANNEL_CH3
  *         @arg @ref DDL_BZTMR_CHANNEL_CH4
  *         @arg @ref DDL_BZTMR_CHANNEL_CH5
  *         @arg @ref DDL_BZTMR_CHANNEL_CH6
  *         @arg @ref DDL_BZTMR_CHANNEL_CH7
  *         @arg @ref DDL_BZTMR_CHANNEL_CH8
  *         @arg @ref DDL_BZTMR_CHANNEL_CH9
  */
__STATIC_INLINE uint32_t DDL_BZTMR_GetTransmitSequence(BZTMR_TypeDef *BZTMRx, uint32_t Sequence)
{
  __IO uint32_t* reg = (__IO uint32_t *)((uint32_t)(&BZTMRx->CSR1) + OFFSET_TAB_CSRx[Sequence]);
  return (READ_BIT(*reg, (BZTMR_CSR2_SEQ8 << SHIFT_TAB_SEQ[Sequence])) >> SHIFT_TAB_SEQ[Sequence]);
}

/**
  * @}
  */

/** @defgroup BZTMR_DDL_EF_IT_Management interrupt management
  * @{
  */

/**
  * @brief  Enable transmit complete interrupt.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_EnableIT_TC(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->IR, BZTMR_IR_TCIE);
}

/**
 * @brief  Disable transmit complete interrupt.
 * @param  BZTMRx BZTMR instance
 * @retval None
 */
__STATIC_INLINE void DDL_BZTMR_DisableIT_TC(BZTMR_TypeDef *BZTMRx)
{
    CLEAR_BIT(BZTMRx->IR, BZTMR_IR_TCIE);
}

/**
  * @brief  Check if transmit complete interrupt is enabled.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BZTMR_IsEnableIT_TC(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->IR, BZTMR_IR_TCIE) == BZTMR_IR_TCIE ? 1U : 0U);
}

/**
  * @brief  Enable data overflow inerrupt.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_EnableIT_ORE(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->IR, BZTMR_IR_OREIE);
}

/**
 * @brief  Disable data overflow inerrupt.
 * @param  BZTMRx BZTMR instance
 * @retval None
 */
__STATIC_INLINE void DDL_BZTMR_DisableIT_ORE(BZTMR_TypeDef *BZTMRx)
{
    CLEAR_BIT(BZTMRx->IR, BZTMR_IR_OREIE);
}

/**
  * @brief  Check if data overflow interrupt is enabled.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BZTMR_IsEnableIT_ORE(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->IR, BZTMR_IR_OREIE) == BZTMR_IR_OREIE ? 1U : 0U);
}

/**
  * @brief  Enable Tx buffer empty inerrupt.
  * @param  BZTMRx BZTMR instance
  * @retval None
  */
__STATIC_INLINE void DDL_BZTMR_EnableIT_TXE(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->IR, BZTMR_IR_TXEIE);
}

/**
 * @brief  Disable Tx buffer empty inerrupt.
 * @param  BZTMRx BZTMR instance
 * @retval None
 */
__STATIC_INLINE void DDL_BZTMR_DisableIT_TXE(BZTMR_TypeDef *BZTMRx)
{
    CLEAR_BIT(BZTMRx->IR, BZTMR_IR_TXEIE);
}

/**
  * @brief  Check if Tx buffer empty interrupt is enabled.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BZTMR_IsEnableIT_TXE(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->IR, BZTMR_IR_TXEIE) == BZTMR_IR_TXEIE ? 1U : 0U);
}

/**
  * @}
  */

/** @defgroup BZTMR_DDL_EF_IT_Management interrupt management
  * @{
  */
/**
  * @brief  Get transmit complete flag.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BZTMR_IsActiveFlag_TC(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->IR, BZTMR_IR_TC) == BZTMR_IR_TC ? 1U : 0U);
}

/**
  * @brief  Clear transmit complete flag.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void DDL_BZTMR_ClearFlag_TC(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->IR, BZTMR_IR_TC);
}

/**
  * @brief  Get data overflow flag.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BZTMR_IsActiveFlag_ORE(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->IR, BZTMR_IR_ORE) == BZTMR_IR_ORE ? 1U : 0U);
}

/**
  * @brief  Clear data overflow flag.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void DDL_BZTMR_ClearFlag_ORE(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->IR, BZTMR_IR_ORE);
}

/**
  * @brief  Get Tx buffer empty flag.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BZTMR_IsActiveFlag_TXE(BZTMR_TypeDef *BZTMRx)
{
  return (READ_BIT(BZTMRx->IR, BZTMR_IR_TXE) == BZTMR_IR_TXE ? 1U : 0U);
}

/**
  * @brief  Clear Tx buffer empty flag.
  * @param  BZTMRx BZTMR instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE void DDL_BZTMR_ClearFlag_TXE(BZTMR_TypeDef *BZTMRx)
{
  SET_BIT(BZTMRx->IR, BZTMR_IR_TXE);
}
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup BZTMR_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_BZTMR_DeInit(BZTMR_TypeDef *BZTMRx);
ErrorStatus DDL_BZTMR_Init(BZTMR_TypeDef *BZTMRx, DDL_BZTMR_InitTypeDef *BZTMR_InitStruct);
void        DDL_BZTMR_StructInit(DDL_BZTMR_InitTypeDef *BZTMR_InitStruct);
ErrorStatus DDL_BZTMR_CH_Init(BZTMR_TypeDef *BZTMRx, DDL_BZTMR_CH_InitTypeDef *BZTMR_CHInitStruct);
void        DDL_BZTMR_CH_StructInit(DDL_BZTMR_CH_InitTypeDef *BZTMR_CHInitStruct);

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

#endif /* defined (BZTMR) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_BZTMR_H */

