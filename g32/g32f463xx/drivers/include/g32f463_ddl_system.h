/**
  *
  * @file    g32f463_ddl_system.h
  * @brief   Header file of SYSTEM DDL module.
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
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The DDL SYSTEM driver contains a set of generic APIs that can be
    used by user:
      (+) Some of the FLASH features need to be handled in the SYSTEM file.
      (+) Access to DBGCMU registers
      (+) Access to SYSCFG registers

  @endverbatim
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32F463_DDL_SYSTEM_H
#define G32F463_DDL_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (SYSCFG) || defined (DBGMCU)

/** @defgroup SYSTEM_DDL SYSTEM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup SYSTEM_DDL_Private_Constants SYSTEM Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup SYSTEM_DDL_Exported_Constants SYSTEM Exported Constants
  * @{
  */

/** @defgroup SYSTEM_DDL_EC_REMAP SYSCFG REMAP
* @{
*/
#define DDL_SYSCFG_REMAP_FLASH              (uint32_t)0x00000000                            /*!< Main Flash memory mapped at 0x00000000              */
#define DDL_SYSCFG_REMAP_SYSTEMFLASH        SYSCFG_MMSEL_MMSEL_0                            /*!< System Flash memory mapped at 0x00000000            */
#define DDL_SYSCFG_REMAP_QSPI               SYSCFG_MMSEL_MMSEL_1                            /*!< QSPI2 mapped at 0x00000000                          */
#define DDL_SYSCFG_REMAP_SRAM               (SYSCFG_MMSEL_MMSEL_1 | SYSCFG_MMSEL_MMSEL_0)   /*!< SRAM1 mapped at 0x00000000                          */

/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_EINT_PORT SYSCFG EINT PORT
  * @{
  */
#define DDL_SYSCFG_EINT_PORTA               (uint32_t)0               /*!< EINT PORT A                        */
#define DDL_SYSCFG_EINT_PORTB               (uint32_t)1               /*!< EINT PORT B                        */
#define DDL_SYSCFG_EINT_PORTC               (uint32_t)2               /*!< EINT PORT C                        */
#define DDL_SYSCFG_EINT_PORTD               (uint32_t)3               /*!< EINT PORT D                        */
#if defined(GPIOE)
#define DDL_SYSCFG_EINT_PORTE               (uint32_t)4               /*!< EINT PORT E                        */
#endif /* GPIOE */
#if defined(GPIOF)
#define DDL_SYSCFG_EINT_PORTF               (uint32_t)5               /*!< EINT PORT F                        */
#endif /* GPIOF */
#if defined(GPIOG)
#define DDL_SYSCFG_EINT_PORTG               (uint32_t)6               /*!< EINT PORT G                        */
#endif /* GPIOG */
#define DDL_SYSCFG_EINT_PORTH               (uint32_t)7               /*!< EINT PORT H                        */
#if defined(GPIOI)
#define DDL_SYSCFG_EINT_PORTI               (uint32_t)8               /*!< EINT PORT I                        */
#endif /* GPIOI */
#if defined(GPIOJ)
#define DDL_SYSCFG_EINT_PORTJ               (uint32_t)9               /*!< EINT PORT J                        */
#endif /* GPIOJ */
#if defined(GPIOK)
#define DDL_SYSCFG_EINT_PORTK               (uint32_t)10              /*!< EINT PORT k                        */
#endif /* GPIOK */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_EINT_LINE SYSCFG EINT LINE
  * @{
  */
#define DDL_SYSCFG_EINT_LINE0               (uint32_t)(0x000FU << 16 | 0)  /*!< EINT_POSITION_0  | EINTCFG[0] */
#define DDL_SYSCFG_EINT_LINE1               (uint32_t)(0x00F0U << 16 | 0)  /*!< EINT_POSITION_4  | EINTCFG[0] */
#define DDL_SYSCFG_EINT_LINE2               (uint32_t)(0x0F00U << 16 | 0)  /*!< EINT_POSITION_8  | EINTCFG[0] */
#define DDL_SYSCFG_EINT_LINE3               (uint32_t)(0xF000U << 16 | 0)  /*!< EINT_POSITION_12 | EINTCFG[0] */
#define DDL_SYSCFG_EINT_LINE4               (uint32_t)(0x000FU << 16 | 1)  /*!< EINT_POSITION_0  | EINTCFG[1] */
#define DDL_SYSCFG_EINT_LINE5               (uint32_t)(0x00F0U << 16 | 1)  /*!< EINT_POSITION_4  | EINTCFG[1] */
#define DDL_SYSCFG_EINT_LINE6               (uint32_t)(0x0F00U << 16 | 1)  /*!< EINT_POSITION_8  | EINTCFG[1] */
#define DDL_SYSCFG_EINT_LINE7               (uint32_t)(0xF000U << 16 | 1)  /*!< EINT_POSITION_12 | EINTCFG[1] */
#define DDL_SYSCFG_EINT_LINE8               (uint32_t)(0x000FU << 16 | 2)  /*!< EINT_POSITION_0  | EINTCFG[2] */
#define DDL_SYSCFG_EINT_LINE9               (uint32_t)(0x00F0U << 16 | 2)  /*!< EINT_POSITION_4  | EINTCFG[2] */
#define DDL_SYSCFG_EINT_LINE10              (uint32_t)(0x0F00U << 16 | 2)  /*!< EINT_POSITION_8  | EINTCFG[2] */
#define DDL_SYSCFG_EINT_LINE11              (uint32_t)(0xF000U << 16 | 2)  /*!< EINT_POSITION_12 | EINTCFG[2] */
#define DDL_SYSCFG_EINT_LINE12              (uint32_t)(0x000FU << 16 | 3)  /*!< EINT_POSITION_0  | EINTCFG[3] */
#define DDL_SYSCFG_EINT_LINE13              (uint32_t)(0x00F0U << 16 | 3)  /*!< EINT_POSITION_4  | EINTCFG[3] */
#define DDL_SYSCFG_EINT_LINE14              (uint32_t)(0x0F00U << 16 | 3)  /*!< EINT_POSITION_8  | EINTCFG[3] */
#define DDL_SYSCFG_EINT_LINE15              (uint32_t)(0xF000U << 16 | 3)  /*!< EINT_POSITION_12 | EINTCFG[3] */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_CCM_EN CCM Enable
  * @{
  */
#define DDL_SYSCFG_CCM_DISABLE           (uint32_t)0x00000000U               /*!< Disable CCM */
#define DDL_SYSCFG_CCM_ENABLE_1_4        SYSCFG_CCM_EN_CCM_EN_0              /*!< Enable CCM 1 block */
#define DDL_SYSCFG_CCM_ENABLE_2_4        SYSCFG_CCM_EN_CCM_EN_1              /*!< Enable CCM 2 blocks */
#define DDL_SYSCFG_CCM_ENABLE_3_4        SYSCFG_CCM_EN_CCM_EN_2              /*!< Enable CCM 3 blocks */
#define DDL_SYSCFG_CCM_ENABLE_ALL        SYSCFG_CCM_EN_CCM_EN_3              /*!< Enable all CCM blocks */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_CCM_EN_KEY CCM Enable Key
  * @{
  */
#define DDL_SYSCFG_CCM_EN_KEY            (uint32_t)0x5AA5U                  /*!< CCM Key */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_TRACE DBGMCU TRACE Pin Assignment
  * @{
  */
#define DDL_DBGMCU_TRACE_NONE               0x00000000U                                       /*!< TRACE pins not assigned (default state) */
#define DDL_DBGMCU_TRACE_ASYNCH             DBGMCU_CFG_TRACE_IOEN                             /*!< TRACE pin assignment for Asynchronous Mode */
#define DDL_DBGMCU_TRACE_SYNCH_SIZE1        (DBGMCU_CFG_TRACE_IOEN | DBGMCU_CFG_TRACE_MODE_0) /*!< TRACE pin assignment for Synchronous Mode with a TRACEDATA size of 1 */
#define DDL_DBGMCU_TRACE_SYNCH_SIZE2        (DBGMCU_CFG_TRACE_IOEN | DBGMCU_CFG_TRACE_MODE_1) /*!< TRACE pin assignment for Synchronous Mode with a TRACEDATA size of 2 */
#define DDL_DBGMCU_TRACE_SYNCH_SIZE4        (DBGMCU_CFG_TRACE_IOEN | DBGMCU_CFG_TRACE_MODE)   /*!< TRACE pin assignment for Synchronous Mode with a TRACEDATA size of 4 */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_APB1_GRP1_STOP_IP DBGMCU APB1 GRP1 STOP IP
  * @{
  */
#if defined(DBGMCU_APB1F_TMR2_STS)
#define DDL_DBGMCU_APB1_GRP1_TMR2_STOP      DBGMCU_APB1F_TMR2_STS          /*!< TMR2 counter stopped when core is halted */
#endif /* DBGMCU_APB1F_TMR2_STS */
#if defined(DBGMCU_APB1F_TMR3_STS)
#define DDL_DBGMCU_APB1_GRP1_TMR3_STOP      DBGMCU_APB1F_TMR3_STS          /*!< TMR3 counter stopped when core is halted */
#endif /* DBGMCU_APB1F_TMR3_STS */
#if defined(DBGMCU_APB1F_TMR4_STS)
#define DDL_DBGMCU_APB1_GRP1_TMR4_STOP      DBGMCU_APB1F_TMR4_STS          /*!< TMR4 counter stopped when core is halted */
#endif /* DBGMCU_APB1F_TMR4_STS */
#define DDL_DBGMCU_APB1_GRP1_TMR5_STOP      DBGMCU_APB1F_TMR5_STS          /*!< TMR5 counter stopped when core is halted */
#if defined(DBGMCU_APB1F_TMR6_STS)
#define DDL_DBGMCU_APB1_GRP1_TMR6_STOP      DBGMCU_APB1F_TMR6_STS          /*!< TMR6 counter stopped when core is halted */
#endif /* DBGMCU_APB1F_TMR6_STS */
#if defined(DBGMCU_APB1F_TMR7_STS)
#define DDL_DBGMCU_APB1_GRP1_TMR7_STOP      DBGMCU_APB1F_TMR7_STS          /*!< TMR7 counter stopped when core is halted */
#endif /* DBGMCU_APB1F_TMR7_STOP */
#define DDL_DBGMCU_APB1_GRP1_RTC_STOP       DBGMCU_APB1F_RTC_STS           /*!< RTC counter stopped when core is halted */
#define DDL_DBGMCU_APB1_GRP1_WWDT_STOP      DBGMCU_APB1F_WWDT_STS          /*!< Debug Window Watchdog stopped when Core is halted */
#define DDL_DBGMCU_APB1_GRP1_IWDT_STOP      DBGMCU_APB1F_IWDT_STS          /*!< Debug Independent Watchdog stopped when Core is halted */
#define DDL_DBGMCU_APB1_GRP1_I2C1_STOP      DBGMCU_APB1F_I2C1_SMBUS_TIMEOUT_STS /*!< I2C1 SMBUS timeout mode stopped when Core is halted */
#define DDL_DBGMCU_APB1_GRP1_I2C2_STOP      DBGMCU_APB1F_I2C2_SMBUS_TIMEOUT_STS /*!< I2C2 SMBUS timeout mode stopped when Core is halted */
#if defined(DBGMCU_APB1F_CAN1_STS)
#define DDL_DBGMCU_APB1_GRP1_CAN1_STOP      DBGMCU_APB1F_CAN1_STS          /*!< CAN1 debug stopped when Core is halted  */
#endif /* DBGMCU_APB1F_CAN1_STS */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_APB2_GRP1_STOP_IP DBGMCU APB2 GRP1 STOP IP
  * @{
  */
#define DDL_DBGMCU_APB2_GRP1_TMR1_STOP      DBGMCU_APB2F_TMR1_STS   /*!< TMR1 counter stopped when core is halted */
#if defined(DBGMCU_APB2F_TMR8_STS)
#define DDL_DBGMCU_APB2_GRP1_TMR8_STOP      DBGMCU_APB2F_TMR8_STS   /*!< TMR8 counter stopped when core is halted */
#endif /* DBGMCU_APB2F_TMR8_STS */
/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EC_I2C3_FILTER I2C3 FILTER
  * @{
  */
#define DDL_SYSCFG_PIN_PA8  0U
#define DDL_SYSCFG_PIN_PA9  1U
#define DDL_SYSCFG_PIN_PB3  2U
#define DDL_SYSCFG_PIN_PB4  3U
#define DDL_SYSCFG_PIN_PB10 4U
#define DDL_SYSCFG_PIN_PB11 5U

#define DDL_SYSCFG_I2C3_FILTER_130NS    0x00000000U
#define DDL_SYSCFG_I2C3_FILTER_30NS     (SYSCFG_I2C3_FILTER_PA8_FILTER_0)
#define DDL_SYSCFG_I2C3_FILTER_25NS     (SYSCFG_I2C3_FILTER_PA8_FILTER_1)
#define DDL_SYSCFG_I2C3_FILTER_15NS     (SYSCFG_I2C3_FILTER_PA8_FILTER)

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup SYSTEM_DDL_Exported_Functions SYSTEM Exported Functions
  * @{
  */

/** @defgroup SYSTEM_DDL_EF_SYSCFG SYSCFG
  * @{
  */
/**
  * @brief  Set memory mapping at address 0x00000000
  * @param  Memory This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_REMAP_FLASH
  *         @arg @ref DDL_SYSCFG_REMAP_SYSTEMFLASH
  *         @arg @ref DDL_SYSCFG_REMAP_QSPI
  *         @arg @ref DDL_SYSCFG_REMAP_SRAM
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_SetRemapMemory(uint32_t Memory)
{
  MODIFY_REG(SYSCFG->MMSEL, SYSCFG_MMSEL_MMSEL, Memory);
}

/**
  * @brief  Get memory mapping at address 0x00000000
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SYSCFG_REMAP_FLASH
  *         @arg @ref DDL_SYSCFG_REMAP_SYSTEMFLASH
  *         @arg @ref DDL_SYSCFG_REMAP_QSPI
  *         @arg @ref DDL_SYSCFG_REMAP_SRAM
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_GetRemapMemory(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->MMSEL, SYSCFG_MMSEL_MMSEL));
}

/**
  * @brief  Enables the Compensation cell Power Down
  * @note   The I/O compensation cell can be used only when the device supply
  *         voltage ranges from 2.4 to 3.6 V
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_EnableCompensationCell(void)
{
  SET_BIT(SYSCFG->CCCTRL, SYSCFG_CCCTRL_CCPD);
}

/**
  * @brief  Disables the Compensation cell Power Down
  * @note   The I/O compensation cell can be used only when the device supply
  *         voltage ranges from 2.4 to 3.6 V
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_DisableCompensationCell(void)
{
  CLEAR_BIT(SYSCFG->CCCTRL, SYSCFG_CCCTRL_CCPD);
}

/**
  * @brief  Get Compensation Cell ready Flag
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_IsActiveFlag_CMPCR(void)
{
  return (READ_BIT(SYSCFG->CCCTRL, SYSCFG_CCCTRL_RDYFLG) == (SYSCFG_CCCTRL_RDYFLG));
}

/**
  * @brief  Configure source input for the EINT external interrupt.
  * @param  Port This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_EINT_PORTA
  *         @arg @ref DDL_SYSCFG_EINT_PORTB
  *         @arg @ref DDL_SYSCFG_EINT_PORTC
  *         @arg @ref DDL_SYSCFG_EINT_PORTD
  *         @arg @ref DDL_SYSCFG_EINT_PORTH
  *
  *         (*) value not defined in all devices
  * @param  Line This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_EINT_LINE0
  *         @arg @ref DDL_SYSCFG_EINT_LINE1
  *         @arg @ref DDL_SYSCFG_EINT_LINE2
  *         @arg @ref DDL_SYSCFG_EINT_LINE3
  *         @arg @ref DDL_SYSCFG_EINT_LINE4
  *         @arg @ref DDL_SYSCFG_EINT_LINE5
  *         @arg @ref DDL_SYSCFG_EINT_LINE6
  *         @arg @ref DDL_SYSCFG_EINT_LINE7
  *         @arg @ref DDL_SYSCFG_EINT_LINE8
  *         @arg @ref DDL_SYSCFG_EINT_LINE9
  *         @arg @ref DDL_SYSCFG_EINT_LINE10
  *         @arg @ref DDL_SYSCFG_EINT_LINE11
  *         @arg @ref DDL_SYSCFG_EINT_LINE12
  *         @arg @ref DDL_SYSCFG_EINT_LINE13
  *         @arg @ref DDL_SYSCFG_EINT_LINE14
  *         @arg @ref DDL_SYSCFG_EINT_LINE15
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_SetEINTSource(uint32_t Port, uint32_t Line)
{
  MODIFY_REG(SYSCFG->EINTCFG[Line & 0xFF], (Line >> 16), Port << POSITION_VAL((Line >> 16)));
}

/**
  * @brief  Get the configured defined for specific EINT Line
  * @param  Line This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_EINT_LINE0
  *         @arg @ref DDL_SYSCFG_EINT_LINE1
  *         @arg @ref DDL_SYSCFG_EINT_LINE2
  *         @arg @ref DDL_SYSCFG_EINT_LINE3
  *         @arg @ref DDL_SYSCFG_EINT_LINE4
  *         @arg @ref DDL_SYSCFG_EINT_LINE5
  *         @arg @ref DDL_SYSCFG_EINT_LINE6
  *         @arg @ref DDL_SYSCFG_EINT_LINE7
  *         @arg @ref DDL_SYSCFG_EINT_LINE8
  *         @arg @ref DDL_SYSCFG_EINT_LINE9
  *         @arg @ref DDL_SYSCFG_EINT_LINE10
  *         @arg @ref DDL_SYSCFG_EINT_LINE11
  *         @arg @ref DDL_SYSCFG_EINT_LINE12
  *         @arg @ref DDL_SYSCFG_EINT_LINE13
  *         @arg @ref DDL_SYSCFG_EINT_LINE14
  *         @arg @ref DDL_SYSCFG_EINT_LINE15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SYSCFG_EINT_PORTA
  *         @arg @ref DDL_SYSCFG_EINT_PORTB
  *         @arg @ref DDL_SYSCFG_EINT_PORTC
  *         @arg @ref DDL_SYSCFG_EINT_PORTD
  *         @arg @ref DDL_SYSCFG_EINT_PORTH
  *         (*) value not defined in all devices
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_GetEINTSource(uint32_t Line)
{
  return (uint32_t)(READ_BIT(SYSCFG->EINTCFG[Line & 0xFF], (Line >> 16)) >> POSITION_VAL(Line >> 16));
}

/**
  * @brief  Enable the Vref buffer
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_EnableVrefBuf(void)
{
  SET_BIT(SYSCFG->VREFBUF_CTRL, SYSCFG_VREFBUF_CTRL_VREF_ON);
}

/**
  * @brief  Disable the Vref buffer
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_DisableVrefBuf(void)
{
  CLEAR_BIT(SYSCFG->VREFBUF_CTRL, SYSCFG_VREFBUF_CTRL_VREF_ON);
}

/**
  * @brief  Check whether the Vref buffer is enabled or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_IsEnabledVrefBuf(void)
{
  return (READ_BIT(SYSCFG->VREFBUF_CTRL, SYSCFG_VREFBUF_CTRL_VREF_ON) == (SYSCFG_VREFBUF_CTRL_VREF_ON));
}

/**
  * @brief  Enable the Vref0V8
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_EnableVref0P8V(void)
{
  SET_BIT(SYSCFG->VREFBUF_CTRL, SYSCFG_VREFBUF_CTRL_VREF0P8V_ON);
}

/**
  * @brief  Disable the Vref0V8
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_DisableVref0P8V(void)
{
  CLEAR_BIT(SYSCFG->VREFBUF_CTRL, SYSCFG_VREFBUF_CTRL_VREF0P8V_ON);
}

/**
  * @brief  Check whether the Vref0V8 is enabled or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_IsEnabledVref0P8V(void)
{
  return (READ_BIT(SYSCFG->VREFBUF_CTRL, SYSCFG_VREFBUF_CTRL_VREF0P8V_ON) == (SYSCFG_VREFBUF_CTRL_VREF0P8V_ON));
}

/**
  * @brief  Set CCM Block Enable
  * @param  Block This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_CCM_DISABLE
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_1_4
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_2_4
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_3_4
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_SetCCMBlockEnable(uint32_t Block)
{
  MODIFY_REG(SYSCFG->CCM_EN, SYSCFG_CCM_EN_CCM_EN, Block);
}

/**
  * @brief  Get CCM Block Enable
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SYSCFG_CCM_DISABLE
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_1_4
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_2_4
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_3_4
  *         @arg @ref DDL_SYSCFG_CCM_ENABLE_ALL
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_GetCCMBlockEnable(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCM_EN, SYSCFG_CCM_EN_CCM_EN));
}

/**
  * @brief  Enable CCM write access
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_EnableCCMWriteAccess(void)
{
  SET_BIT(SYSCFG->CCM_EN, DDL_SYSCFG_CCM_EN_KEY << SYSCFG_CCM_EN_KEY_Pos);
}

/**
  * @}
  */

/** @defgroup SYSTEM_DDL_EF_I2C3_FILTER I2C3_FILTER
  * @{
  */

/**
  * @brief  Set I2C3 FILTER
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_PIN_PA8
  *         @arg @ref DDL_SYSCFG_PIN_PA9
  *         @arg @ref DDL_SYSCFG_PIN_PB3
  *         @arg @ref DDL_SYSCFG_PIN_PB4
  *         @arg @ref DDL_SYSCFG_PIN_PB10
  *         @arg @ref DDL_SYSCFG_PIN_PB11
  * @param  Filter This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_130NS
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_30NS
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_25NS
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_15NS
  * @retval None
  */
__STATIC_INLINE void DDL_SYSCFG_SetI2C3Filter(uint32_t Pin, uint32_t Filter)
{
  MODIFY_REG(SYSCFG->I2C3_FILTER, SYSCFG_I2C3_FILTER_PA8_FILTER << Pin, Filter << Pin);
}

/**
  * @brief  Get I2C3 FILTER
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_SYSCFG_PIN_PA8
  *         @arg @ref DDL_SYSCFG_PIN_PA9
  *         @arg @ref DDL_SYSCFG_PIN_PB3
  *         @arg @ref DDL_SYSCFG_PIN_PB4
  *         @arg @ref DDL_SYSCFG_PIN_PB10
  *         @arg @ref DDL_SYSCFG_PIN_PB11
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_130NS
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_30NS
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_25NS
  *         @arg @ref DDL_SYSCFG_I2C3_FILTER_15NS
  */
__STATIC_INLINE uint32_t DDL_SYSCFG_GetI2C3Filter(uint32_t Pin)
{
  return (uint32_t)(READ_BIT(SYSCFG->I2C3_FILTER, SYSCFG_I2C3_FILTER_PA8_FILTER << Pin) >> Pin);
}

  /**
  * @}
  */

/** @defgroup SYSTEM_DDL_EF_DBGMCU DBGMCU
  * @{
  */

//TODO(linwei): Check the device ID and revision ID for G32F463
/**
  * @brief  Return the device identifier
  * @note For G32F463xx devices, the device ID is 0x419
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFF
  */
__STATIC_INLINE uint32_t DDL_DBGMCU_GetDeviceID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_EQR));
}

/**
  * @brief  Return the device revision identifier
  * @note This field indicates the revision of the device.
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_DBGMCU_GetRevisionID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_WVR) >> DBGMCU_IDCODE_WVR_Pos);
}

/**
  * @brief  Enable the Debug Module during SLEEP mode
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CFG, DBGMCU_CFG_SLEEP_CLK_STS);
}

/**
  * @brief  Disable the Debug Module during SLEEP mode
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CFG, DBGMCU_CFG_SLEEP_CLK_STS);
}

/**
  * @brief  Enable the Debug Module during STOP mode
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CFG, DBGMCU_CFG_STOP_CLK_STS);
}

/**
  * @brief  Disable the Debug Module during STOP mode
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CFG, DBGMCU_CFG_STOP_CLK_STS);
}

/**
  * @brief  Enable the Debug Module during STANDBY mode
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CFG, DBGMCU_CFG_STANDBY_CLK_STS);
}

/**
  * @brief  Disable the Debug Module during STANDBY mode
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CFG, DBGMCU_CFG_STANDBY_CLK_STS);
}

/**
  * @brief  Set Trace pin assignment control
  * @param  PinAssignment This parameter can be one of the following values:
  *         @arg @ref DDL_DBGMCU_TRACE_NONE
  *         @arg @ref DDL_DBGMCU_TRACE_ASYNCH
  *         @arg @ref DDL_DBGMCU_TRACE_SYNCH_SIZE1
  *         @arg @ref DDL_DBGMCU_TRACE_SYNCH_SIZE2
  *         @arg @ref DDL_DBGMCU_TRACE_SYNCH_SIZE4
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_SetTracePinAssignment(uint32_t PinAssignment)
{
  MODIFY_REG(DBGMCU->CFG, DBGMCU_CFG_TRACE_IOEN | DBGMCU_CFG_TRACE_MODE, PinAssignment);
}

/**
  * @brief  Get Trace pin assignment control
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_DBGMCU_TRACE_NONE
  *         @arg @ref DDL_DBGMCU_TRACE_ASYNCH
  *         @arg @ref DDL_DBGMCU_TRACE_SYNCH_SIZE1
  *         @arg @ref DDL_DBGMCU_TRACE_SYNCH_SIZE2
  *         @arg @ref DDL_DBGMCU_TRACE_SYNCH_SIZE4
  */
__STATIC_INLINE uint32_t DDL_DBGMCU_GetTracePinAssignment(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->CFG, DBGMCU_CFG_TRACE_IOEN | DBGMCU_CFG_TRACE_MODE));
}

/**
  * @brief  Freeze APB1 peripherals (group1 peripherals)
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR2_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR3_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR4_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR5_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR6_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR7_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_RTC_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_WWDT_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_IWDT_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_I2C2_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_CAN1_STOP
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_APB1_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB1F, Periphs);
}

/**
  * @brief  Unfreeze APB1 peripherals (group1 peripherals)
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR2_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR3_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR4_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR5_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR6_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_TMR7_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_RTC_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_WWDT_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_IWDT_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_I2C2_STOP
  *         @arg @ref DDL_DBGMCU_APB1_GRP1_CAN1_STOP
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_APB1_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB1F, Periphs);
}

/**
  * @brief  Freeze APB2 peripherals
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_DBGMCU_APB2_GRP1_TMR1_STOP
  *         @arg @ref DDL_DBGMCU_APB2_GRP1_TMR8_STOP
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_APB2_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB2F, Periphs);
}

/**
  * @brief  Unfreeze APB2 peripherals
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_DBGMCU_APB2_GRP1_TMR1_STOP
  *         @arg @ref DDL_DBGMCU_APB2_GRP1_TMR8_STOP
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void DDL_DBGMCU_APB2_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB2F, Periphs);
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

#endif /* defined (SYSCFG) || defined (DBGMCU) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_SYSTEM_H */


