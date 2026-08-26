/**
  *
  * @file    g32f463_ddl_bus.h
  * @brief   Header file of BUS DDL module.
  * @version V1.0.0
  * @date    2025-08-08

  @verbatim
                      ##### RCM Limitations #####
  ==============================================================================
    [..]
      A delay between an RCM peripheral clock enable and the effective peripheral
      enabling should be taken into account in order to manage the peripheral read/write
      from/to registers.
      (+) This delay depends on the peripheral mapping.
        (++) AHB & APB peripherals, 1 dummy read is necessary

    [..]
      Workarounds:
      (#) For AHB & APB peripherals, a dummy read to the peripheral register has been
          inserted in each DDL_{BUS}_GRP{x}_EnableClock() function.

  @endverbatim
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
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32F463_DDL_BUS_H
#define G32F463_DDL_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined(RCM)

/** @defgroup BUS_DDL BUS
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup BUS_DDL_Exported_Constants BUS Exported Constants
  * @{
  */

/** @defgroup BUS_DDL_EC_AHB1_GRP1_PERIPH  AHB1 GRP1 PERIPH
  * @{
  */
#define DDL_AHB1_GRP1_PERIPH_ALL             0xFFFFFFFFU
#if defined(RCM_AHB1CLKEN_PAEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOA           RCM_AHB1CLKEN_PAEN
#endif /* RCM_AHB1CLKEN_PAEN */
#if defined(RCM_AHB1CLKEN_PBEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOB           RCM_AHB1CLKEN_PBEN
#endif /* RCM_AHB1CLKEN_PBEN */
#if defined(RCM_AHB1CLKEN_PCEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOC           RCM_AHB1CLKEN_PCEN
#endif /* RCM_AHB1CLKEN_PCEN */
#if defined(RCM_AHB1CLKEN_PDEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOD           RCM_AHB1CLKEN_PDEN
#endif /* RCM_AHB1CLKEN_PDEN */
#if defined(RCM_AHB1CLKEN_PEEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOE           RCM_AHB1CLKEN_PEEN
#endif /* RCM_AHB1CLKEN_PEEN */
#if defined(RCM_AHB1CLKEN_PFEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOF           RCM_AHB1CLKEN_PFEN
#endif /* RCM_AHB1CLKEN_PFEN */
#if defined(RCM_AHB1CLKEN_PGEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOG           RCM_AHB1CLKEN_PGEN
#endif /* RCM_AHB1CLKEN_PGEN */
#if defined(RCM_AHB1CLKEN_PHEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOH           RCM_AHB1CLKEN_PHEN
#endif /* RCM_AHB1CLKEN_PHEN */
#if defined(RCM_AHB1CLKEN_PIEN)
#define DDL_AHB1_GRP1_PERIPH_GPIOI           RCM_AHB1CLKEN_PIEN
#endif /* RCM_AHB1CLKEN_PIEN */
#define DDL_AHB1_GRP1_PERIPH_CRC             RCM_AHB1CLKEN_CRCEN
#if defined(RCM_AHB1CLKEN_BKPSRAMEN)
#define DDL_AHB1_GRP1_PERIPH_BKPSRAM         RCM_AHB1CLKEN_BKPSRAMEN
#endif /* RCM_AHB1CLKEN_BKPSRAMEN */
#if defined(RCM_AHB1CLKEN_DRAMEN)
#define DDL_AHB1_GRP1_PERIPH_CCMDATARAM      RCM_AHB1CLKEN_DRAMEN
#endif /* RCM_AHB1CLKEN_DRAMEN */
#define DDL_AHB1_GRP1_PERIPH_DMA1            RCM_AHB1CLKEN_DMA1EN
#define DDL_AHB1_GRP1_PERIPH_DMA2            RCM_AHB1CLKEN_DMA2EN
#if defined(RCM_AHB1CLKEN_OTGHSEN)
#define DDL_AHB1_GRP1_PERIPH_OTGHS           RCM_AHB1CLKEN_OTGHSEN
#endif /* RCM_AHB1CLKEN_OTGHSEN */
#if defined(RCM_LPAHB1CLKEN_FMCEN)
#define DDL_AHB1_GRP1_PERIPH_FLITF           RCM_LPAHB1CLKEN_FMCEN
#endif /* RCM_LPAHB1CLKEN_FMCEN */
#if defined(RCM_LPAHB1CLKEN_SRAM1EN)
#define DDL_AHB1_GRP1_PERIPH_SRAM1           RCM_LPAHB1CLKEN_SRAM1EN
#endif /* RCM_LPAHB1CLKEN_SRAM1EN */
#if defined(RCM_LPAHB1CLKEN_SRAM2EN)
#define DDL_AHB1_GRP1_PERIPH_SRAM2           RCM_LPAHB1CLKEN_SRAM2EN
#endif /* RCM_LPAHB1CLKEN_SRAM2EN */
/**
  * @}
  */

#if defined(RCM_AHB2_SUPPORT)
/** @defgroup BUS_DDL_EC_AHB2_GRP1_PERIPH  AHB2 GRP1 PERIPH
  * @{
  */
#define DDL_AHB2_GRP1_PERIPH_ALL            0xFFFFFFFFU
#if defined(RCM_AHB2CLKEN_LCDCEN)
#define DDL_AHB2_GRP1_PERIPH_LCDC           RCM_AHB2CLKEN_LCDCEN
#endif /* RCM_AHB2CLKEN_LCDCEN */
#if defined(RCM_AHB2CLKEN_QSPI1EN)
#define DDL_AHB2_GRP1_PERIPH_QSPI1          RCM_AHB2CLKEN_QSPI1EN
#endif /* RCM_AHB2CLKEN_QSPI1EN */
#if defined(RCM_AHB2CLKEN_QSPI2EN)
#define DDL_AHB2_GRP1_PERIPH_QSPI2          RCM_AHB2CLKEN_QSPI2EN
#endif /* RCM_AHB2CLKEN_QSPI2EN */
/**
  * @}
  */
#endif /* RCM_AHB2_SUPPORT */

/** @defgroup BUS_DDL_EC_APB1_GRP1_PERIPH  APB1 GRP1 PERIPH
  * @{
  */
#define DDL_APB1_GRP1_PERIPH_ALL            0xFFFFFFFFU
#if defined(TMR2)
#define DDL_APB1_GRP1_PERIPH_TMR2           RCM_APB1CLKEN_TMR2EN
#endif /* TMR2 */
#if defined(TMR3)
#define DDL_APB1_GRP1_PERIPH_TMR3           RCM_APB1CLKEN_TMR3EN
#endif /* TMR3 */
#if defined(TMR4)
#define DDL_APB1_GRP1_PERIPH_TMR4           RCM_APB1CLKEN_TMR4EN
#endif /* TMR4 */
#define DDL_APB1_GRP1_PERIPH_TMR5           RCM_APB1CLKEN_TMR5EN
#if defined(TMR6)
#define DDL_APB1_GRP1_PERIPH_TMR6           RCM_APB1CLKEN_TMR6EN
#endif /* TMR6 */
#if defined(TMR7)
#define DDL_APB1_GRP1_PERIPH_TMR7           RCM_APB1CLKEN_TMR7EN
#endif /* TMR7 */
#define DDL_APB1_GRP1_PERIPH_WWDT           RCM_APB1CLKEN_WWDTEN
#if defined(SPI2)
#define DDL_APB1_GRP1_PERIPH_SPI2           RCM_APB1CLKEN_SPI2EN
#endif /* SPI2 */
#if defined(SPI3)
#define DDL_APB1_GRP1_PERIPH_SPI3           RCM_APB1CLKEN_SPI3EN
#endif /* SPI3 */
#define DDL_APB1_GRP1_PERIPH_USART2         RCM_APB1CLKEN_USART2EN
#if defined(USART3)
#define DDL_APB1_GRP1_PERIPH_USART3         RCM_APB1CLKEN_USART3EN
#endif /* USART3 */
#if defined(UART4)
#define DDL_APB1_GRP1_PERIPH_UART4          RCM_APB1CLKEN_UART4EN
#endif /* UART4 */
#define DDL_APB1_GRP1_PERIPH_I2C1           RCM_APB1CLKEN_I2C1EN
#if defined(I2C2)
#define DDL_APB1_GRP1_PERIPH_I2C2           RCM_APB1CLKEN_I2C2EN
#endif /* I2C2 */
#if defined(FDCAN1)
#define DDL_APB1_GRP1_PERIPH_FDCAN1         RCM_APB1CLKEN_CAN1EN
#endif /* FDCAN1 */
#define DDL_APB1_GRP1_PERIPH_PMU            RCM_APB1CLKEN_PMUEN
#if defined(DAC1)
#define DDL_APB1_GRP1_PERIPH_DAC1           RCM_APB1CLKEN_DACEN
#endif /* DAC1 */
/**
  * @}
  */

/** @defgroup BUS_DDL_EC_APB2_GRP1_PERIPH  APB2 GRP1 PERIPH
  * @{
  */
#define DDL_APB2_GRP1_PERIPH_ALL          0xFFFFFFFFU
#define DDL_APB2_GRP1_PERIPH_TMR1         RCM_APB2CLKEN_TMR1EN
#if defined(TMR8)
#define DDL_APB2_GRP1_PERIPH_TMR8         RCM_APB2CLKEN_TMR8EN
#endif /* TMR8 */
#define DDL_APB2_GRP1_PERIPH_USART1       RCM_APB2CLKEN_USART1EN
#if defined(BZTMR)
#define DDL_APB2_GRP1_PERIPH_BZTMR        RCM_APB2CLKEN_BZ_TMREN
#endif /* BZTMR */
#define DDL_APB2_GRP1_PERIPH_SPI1         RCM_APB2CLKEN_SPI1EN
#if defined(SYSCFG)
#define DDL_APB2_GRP1_PERIPH_SYSCFG       RCM_APB2CLKEN_SYSCFGEN
#endif /* SYSCFG */
/**
  * @}
  */

/** @defgroup BUS_DDL_EC_APB3_GRP1_PERIPH  APB3 GRP1 PERIPH
  * @{
  */
#define DDL_APB3_GRP1_PERIPH_ALL          0xFFFFFFFFU
#define DDL_APB3_GRP1_PERIPH_ADC1         RCM_APB3CLKEN_ADC1EN
#if defined(ADC2)
#define DDL_APB3_GRP1_PERIPH_ADC2         RCM_APB3CLKEN_ADC2EN
#endif /* ADC2 */
#if defined(ADC3)
#define DDL_APB3_GRP1_PERIPH_ADC3         RCM_APB3CLKEN_ADC3EN
#endif /* ADC3 */
#if defined(RCM_APB3RST_ADCRST)
#define DDL_APB3_GRP1_PERIPH_ADC          RCM_APB3RST_ADCRST
#endif /* RCM_APB3RST_ADCRST */
#if defined(I2C3)
#define DDL_APB3_GRP1_PERIPH_I2C3         RCM_APB3CLKEN_I2C3EN
#endif /* I2C3 */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @defgroup BUS_DDL_Exported_Functions BUS Exported Functions
  * @{
  */

/** @defgroup BUS_DDL_EF_AHB1 AHB1
  * @{
  */

/**
  * @brief  Enable AHB1 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_BKPSRAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CCMDATARAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->AHB1CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->AHB1CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if AHB1 peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_BKPSRAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CCMDATARAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS
  *
  *         (*) value not defined in all devices.
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_AHB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCM->AHB1CLKEN, Periphs) == Periphs);
}

/**
  * @brief  Disable AHB1 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_BKPSRAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CCMDATARAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCM->AHB1CLKEN, Periphs);
}

/**
  * @brief  Force AHB1 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_ALL
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCM->AHB1RST, Periphs);
}

/**
  * @brief  Release AHB1 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_ALL
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS

  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCM->AHB1RST, Periphs);
}

#if defined(RCM_LPAHB1_SUPPORT)
/**
  * @brief  Enable AHB1 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_BKPSRAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_FLITF
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_SRAM1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_SRAM2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB1_GRP1_EnableClockLowPower(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->LPAHB1CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->LPAHB1CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Disable AHB1 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOD
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_GPIOH
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_BKPSRAM
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_FLITF
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_SRAM1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_SRAM2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_DMA2
  *         @arg @ref DDL_AHB1_GRP1_PERIPH_OTGHS
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB1_GRP1_DisableClockLowPower(uint32_t Periphs)
{
  CLEAR_BIT(RCM->LPAHB1CLKEN, Periphs);
}

#endif /* RCM_LPAHB1_SUPPORT */

/**
  * @}
  */

#if defined(RCM_AHB2_SUPPORT)
/** @defgroup BUS_DDL_EF_AHB2 AHB2
  * @{
  */

/**
  * @brief  Enable AHB2 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->AHB2CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->AHB2CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if AHB2 peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_AHB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCM->AHB2CLKEN, Periphs) == Periphs);
}

/**
  * @brief  Disable AHB2 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCM->AHB2CLKEN, Periphs);
}

/**
  * @brief  Force AHB2 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_ALL
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCM->AHB2RST, Periphs);
}

/**
  * @brief  Release AHB2 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_ALL
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCM->AHB2RST, Periphs);
}

#if defined(RCM_LPAHB2_SUPPORT)

/**
  * @brief  Enable AHB2 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB2_GRP1_EnableClockLowPower(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->LPAHB2CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->LPAHB2CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Disable AHB2 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_LCDC
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI1
  *         @arg @ref DDL_AHB2_GRP1_PERIPH_QSPI2
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_AHB2_GRP1_DisableClockLowPower(uint32_t Periphs)
{
  CLEAR_BIT(RCM->LPAHB2CLKEN, Periphs);
}

#endif /* RCM_LPAHB2_SUPPORT */

/**
  * @}
  */
#endif /* RCM_AHB2_SUPPORT */

/** @defgroup BUS_DDL_EF_APB1 APB1
  * @{
  */

/**
  * @brief  Enable APB1 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->APB1CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->APB1CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if APB1 peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_APB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCM->APB1CLKEN, Periphs) == Periphs);
}

/**
  * @brief  Disable APB1 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCM->APB1CLKEN, Periphs);
}

/**
  * @brief  Force APB1 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCM->APB1RST, Periphs);
}

/**
  * @brief  Release APB1 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCM->APB1RST, Periphs);
}

#if defined(RCM_LPAPB1_SUPPORT)

/**
  * @brief  Enable APB1 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB1_GRP1_EnableClockLowPower(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->LPAPB1CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->LPAPB1CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Disable APB1 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR5
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR6
  *         @arg @ref DDL_APB1_GRP1_PERIPH_TMR7
  *         @arg @ref DDL_APB1_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_SPI3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_USART3
  *         @arg @ref DDL_APB1_GRP1_PERIPH_UART4
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_I2C2
  *         @arg @ref DDL_APB1_GRP1_PERIPH_FDCAN1
  *         @arg @ref DDL_APB1_GRP1_PERIPH_PMU
  *         @arg @ref DDL_APB1_GRP1_PERIPH_DAC1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB1_GRP1_DisableClockLowPower(uint32_t Periphs)
{
  CLEAR_BIT(RCM->LPAPB1CLKEN, Periphs);
}

#endif /* RCM_LPAPB1_SUPPORT */

/**
  * @}
  */

/** @defgroup BUS_DDL_EF_APB2 APB2
  * @{
  */

/**
  * @brief  Enable APB2 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->APB2CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->APB2CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if APB2 peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_APB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCM->APB2CLKEN, Periphs) == Periphs);
}

/**
  * @brief  Disable APB2 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCM->APB2CLKEN, Periphs);
}

/**
  * @brief  Force APB2 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_ALL
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval None
  * @note   ADC1 and ADC2 are not available on all devices.
*/
__STATIC_INLINE void DDL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCM->APB2RST, Periphs);
}

/**
  * @brief  Release APB2 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_ALL
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval None
  * @note   ADC1 and ADC2 are not available on all devices.
*/
__STATIC_INLINE void DDL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCM->APB2RST, Periphs);
}

#if defined(RCM_LPAPB2_SUPPORT)

/**
  * @brief  Enable APB2 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB2_GRP1_EnableClockLowPower(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->LPAPB2CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->LPAPB2CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Disable APB2 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_TMR8
  *         @arg @ref DDL_APB2_GRP1_PERIPH_USART1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref DDL_APB2_GRP1_PERIPH_SYSCFG
  *         @arg @ref DDL_APB2_GRP1_PERIPH_BZTMR
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB2_GRP1_DisableClockLowPower(uint32_t Periphs)
{
  CLEAR_BIT(RCM->LPAPB2CLKEN, Periphs);
}

#endif /* RCM_LPAPB2_SUPPORT */

/**
  * @}
  */

/** @defgroup BUS_DDL_EF_APB3 APB3
  * @{
  */

/**
  * @brief  Enable APB3 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC1
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC2
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC3
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB3_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->APB3CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->APB3CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if APB3 peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC1
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC2
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC3
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_APB3_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCM->APB3CLKEN, Periphs) == Periphs);
}

/**
  * @brief  Disable APB3 peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC1
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC2
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC3
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB3_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCM->APB3CLKEN, Periphs);
}

/**
  * @brief  Force APB3 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ALL
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB3_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCM->APB3RST, Periphs);
}

/**
  * @brief  Release APB3 peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ALL
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB3_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCM->APB3RST, Periphs);
}

#if defined(RCM_LPAPB3_SUPPORT)

/**
  * @brief  Enable APB3 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC1
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC2
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC3
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB3_GRP1_EnableClockLowPower(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCM->LPAPB3CLKEN, Periphs);
  /* Delay after an RCM peripheral clock enabling */
  tmpreg = READ_BIT(RCM->LPAPB3CLKEN, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Disable APB3 peripheral clocks in low-power mode
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC1
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC2
  *         @arg @ref DDL_APB3_GRP1_PERIPH_ADC3
  *         @arg @ref DDL_APB3_GRP1_PERIPH_I2C3
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void DDL_APB3_GRP1_DisableClockLowPower(uint32_t Periphs)
{
  CLEAR_BIT(RCM->LPAPB3CLKEN, Periphs);
}

#endif /* RCM_LPAPB3_SUPPORT */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RCM) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_BUS_H */

