/**
  *
  * @file    g32f463_ddl_i2c3.c
  * @brief   I2C3 DDL module driver.
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

#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32f463_ddl_i2c3.h"
#include "g32f463_ddl_bus.h"
#include "g32f463_ddl_rcm.h"

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

#if defined (I2C3)

/** @defgroup I2C3_DDL I2C3
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C3_DDL_Private_Macros
  * @{
  */

/* Used for baudrate calculation */
#define SDA_HOLD_TIME_MIN_VALUE     1U
#define BUS_IDLE_MAX_VALUE          0xFFFU
#define SCL_SETUP_TIME_MIN_VALUE    2U
#define SCL_HIGH_MIN_VALUE          1U
#define SCL_HIGH_MAX_VALUE          0x3FU
#define SCL_LOW_MIN_VALUE           3U
#define SCL_LOW_MAX_VALUE           SCL_HIGH_MAX_VALUE
#define SCL_TOTAL_MAX_VALUE         (SCL_HIGH_MAX_VALUE + SCL_LOW_MAX_VALUE + 2U)

#define IS_DDL_I2C3_MODE(__VALUE__)              (((__VALUE__) == DDL_I2C3_MODE_STANDARD) || \
                                                 ((__VALUE__) == DDL_I2C3_MODE_FAST)      || \
                                                 ((__VALUE__) == DDL_I2C3_MODE_HIGHSPEED))

#define CHECK_I2C3_SPEED(__SPEED__, __MODE__)    ((__SPEED__) = (((__SPEED__) > (__MODE__)) ? (__MODE__) : (__SPEED__)))

#define IS_DDL_I2C3_SCL_FILTER(__VALUE__)        ((__VALUE__) <= 0x0000000FU)

#define IS_DDL_I2C3_SDA_FILTER(__VALUE__)        ((__VALUE__) <= 0x0000000FU)

#define IS_DDL_I2C3_TIMEOUT_CONFIG(__VALUE__)    (((__VALUE__) == DDL_I2C3_TIMEOUT_SCL) || \
                                                 ((__VALUE__) == DDL_I2C3_TIMEOUT_SCL_SDA))

#define IS_DDL_I2C3_IDLE_TIMEOUT(__VALUE__)      ((__VALUE__) <= 0x0000000FU)

#define IS_DDL_I2C3_PINLOW_TIMEOUT(__VALUE__)    ((__VALUE__) <= 0x0000000FU)

#define IS_DDL_I2C3_OWN_ADDRESS(__VALUE__)       ((__VALUE__) <= 0x000003FFU)

#define IS_DDL_I2C3_BUADRATE(__VALUE__)          ((__VALUE__) <= 1000000U)

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup I2C3_DDL_Exported_Functions
  * @{
  */

/** @addtogroup I2C3_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize the I2C3 registers to their default reset values.
  * @param  I2C3x I2C3 Instance.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C3 registers are de-initialized
  *          - ERROR: I2C3 registers are not de-initialized
  */
ErrorStatus DDL_I2C3_DeInit(I2C3_TypeDef *I2C3x)
{
  ErrorStatus status = SUCCESS;

  /* Check the I2C3 Instance I2C3x */
  ASSERT_PARAM(IS_I2C3_ALL_INSTANCE(I2C3x));

  if (I2C3x == I2C3)
  {
    /* Force reset of I2C3 clock */
    DDL_APB3_GRP1_ForceReset(DDL_APB3_GRP1_PERIPH_I2C3);

    /* Release reset of I2C3 clock */
    DDL_APB3_GRP1_ReleaseReset(DDL_APB3_GRP1_PERIPH_I2C3);
  }
  else
  {
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Set I2C3 master baudrate.
  * @param  I2C3x I2C3 Instance.
  * @param  Mode I2C3 mode.
  *           @arg DDL_I2C3_MODE_STANDARD
  *           @arg DDL_I2C3_MODE_FAST
  *           @arg DDL_I2C3_MODE_HIGHSPEED
  * @param  Baudrate I2C3 baudrate.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C3 set baudrate successfully
  *          - ERROR: I2C3 set baudrate failed
  */
ErrorStatus I2C3_Master_SetBaudrate(I2C3_TypeDef *I2C3x, uint32_t Mode, uint32_t Baudrate)
{
  uint32_t InputClock   = 0U;
  uint32_t Prescaler    = 0U;
  uint32_t PrescalerMin = 0U;
  uint32_t SCLTotal    = 0U;
  uint32_t SCLHigh     = 0U;
  uint32_t SCLLow      = 0U;
  uint32_t SetHold     = 0U;
  uint32_t DataVaild   = 0U;

  CHECK_I2C3_SPEED(Baudrate, Mode);

  /* Read the protocol clock frequency */
  InputClock = DDL_RCM_GetI2C3ClockFreq();

  DDL_I2C3_Master_Disable(I2C3);

  if (Baudrate == 0U)
  {
    SCLTotal = SCL_TOTAL_MAX_VALUE;
    Prescaler = 7;
  }
  else
  {
    PrescalerMin = (InputClock / (Baudrate * SCL_TOTAL_MAX_VALUE));
  }

  for (Prescaler = 0U; Prescaler < 7U; Prescaler++)
  {
    if ((1U << Prescaler) >= PrescalerMin)
    {
        break;
    }
  }

  SCLTotal = (InputClock + ((Baudrate * Prescaler) >> 1U)) / (Baudrate * Prescaler);
  SCLTotal = (SCLTotal > SCL_TOTAL_MAX_VALUE) ? SCL_TOTAL_MAX_VALUE : SCLTotal;

  if (SCLTotal > 2U)
  {
    SCLHigh = (SCLTotal - 2U) / 2U;
    SCLLow = SCLTotal - 2U - SCLHigh;
  }
  SCLLow = (SCLLow < SCL_LOW_MIN_VALUE) ? SCL_LOW_MIN_VALUE : SCLLow;
  SCLHigh = (SCLHigh < SCL_HIGH_MIN_VALUE) ? SCL_HIGH_MIN_VALUE : SCLHigh;

  SetHold = SCLLow;
  SetHold = (SetHold < SCL_SETUP_TIME_MIN_VALUE) ? SCL_SETUP_TIME_MIN_VALUE : SetHold;

  DataVaild = SCLLow >> 1U;
  DataVaild = (DataVaild < SDA_HOLD_TIME_MIN_VALUE) ? SDA_HOLD_TIME_MIN_VALUE : DataVaild;

  DDL_I2C3_Master_SetPrescale(I2C3x, Prescaler);
  DDL_I2C3_Master_SetSCLLowPeriod(I2C3x, SCLLow);
  DDL_I2C3_Master_SetSCLHighPeriod(I2C3x, SCLHigh);
  DDL_I2C3_Master_SetSetupHoldDelay(I2C3x, SetHold);
  DDL_I2C3_Master_SetDataValidDelay(I2C3x, DataVaild);

  DDL_I2C3_Master_SetPinMode(I2C3x, DDL_I2C3_PINMODE_2WIRE_OPEN_DRAIN);
  DDL_I2C3_Master_SetNACKMode(I2C3x, DDL_I2C3_NACKMODE_RECEIVED);

  return SUCCESS;
}

/**
  * @brief  Initialize the I2C3 registers according to the specified parameters in I2C3_InitStruct.
  * @param  I2C3x I2C3 Instance.
  * @param  I2C3_InitStruct pointer to a @ref DDL_I2C3_MasterInitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C3 registers are initialized
  *          - ERROR: Not applicable
  */
ErrorStatus DDL_I2C3_Master_Init(I2C3_TypeDef *I2C3x, DDL_I2C3_MasterInitTypeDef *I2C3_InitStruct)
{
  /* Check the I2C3 Instance I2C3x */
  ASSERT_PARAM(IS_I2C3_ALL_INSTANCE(I2C3x));

  /* Check the I2C3 parameters from I2C3_InitStruct */
  ASSERT_PARAM(IS_DDL_I2C3_MODE(I2C3_InitStruct->Mode));
  ASSERT_PARAM(IS_DDL_I2C3_SCL_FILTER(I2C3_InitStruct->SCLFilter));
  ASSERT_PARAM(IS_DDL_I2C3_SDA_FILTER(I2C3_InitStruct->SDAFilter));
  ASSERT_PARAM(IS_DDL_I2C3_TIMEOUT_CONFIG(I2C3_InitStruct->TimeoutConfig));
  ASSERT_PARAM(IS_DDL_I2C3_IDLE_TIMEOUT(I2C3_InitStruct->IdleTimeout));
  ASSERT_PARAM(IS_DDL_I2C3_PINLOW_TIMEOUT(I2C3_InitStruct->PinLowTimeout));

  /* Disable the selected I2C3x Peripheral */
  DDL_I2C3_Master_Disable(I2C3x);

  /* Reset I2C3 Master register */
  DDL_I2C3_Master_EnableSoftwareReset(I2C3x);
  I2C3x->MCR = 0x00000000U;

  I2C3_Master_SetBaudrate(I2C3x, I2C3_InitStruct->Mode, I2C3_InitStruct->Baudrate);

  DDL_I2C3_Master_SetSCLFilter(I2C3x, I2C3_InitStruct->SCLFilter);
  DDL_I2C3_Master_SetSDAFilter(I2C3x, I2C3_InitStruct->SDAFilter);

  DDL_I2C3_Master_Enable(I2C3);

  return SUCCESS;
}

/**
  * @brief  Initialize the I2C3 registers according to the specified parameters in I2C3_InitStruct.
  * @param  I2C3x I2C3 Instance.
  * @param  I2C3_InitStruct pointer to a @ref DDL_I2C3_SlaveInitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C3 registers are initialized
  *          - ERROR: Not applicable
  */
ErrorStatus DDL_I2C3_Slave_Init(I2C3_TypeDef *I2C3x, DDL_I2C3_SlaveInitTypeDef *I2C3_InitStruct)
{
  /* Check the I2C3 Instance I2C3x */
  ASSERT_PARAM(IS_I2C3_ALL_INSTANCE(I2C3x));

  /* Check the I2C3 parameters from I2C3_InitStruct */
  ASSERT_PARAM(IS_DDL_I2C3_MODE(I2C3_InitStruct->Mode));
  ASSERT_PARAM(IS_DDL_I2C3_SCL_FILTER(I2C3_InitStruct->SCLFilter));
  ASSERT_PARAM(IS_DDL_I2C3_SDA_FILTER(I2C3_InitStruct->SDAFilter));

  /* Disable the selected I2C3x Peripheral */
  DDL_I2C3_Slave_Disable(I2C3x);

  /* Reset I2C3 Slave register */
  DDL_I2C3_Slave_EnableSoftwareReset(I2C3x);
  I2C3x->SCR = 0x00000000U;

  DDL_I2C3_Slave_SetSCLFilter(I2C3x, I2C3_InitStruct->SCLFilter);
  DDL_I2C3_Slave_SetSDAFilter(I2C3x, I2C3_InitStruct->SDAFilter);

  DDL_I2C3_Slave_SetAddrMatchConfig(I2C3x, I2C3_InitStruct->AddressMatch);
  DDL_I2C3_Slave_SetAddr0(I2C3x, I2C3_InitStruct->OwnAddress0);
  DDL_I2C3_Slave_SetAddr1(I2C3x, I2C3_InitStruct->OwnAddress1);

  DDL_I2C3_Slave_Enable(I2C3);

  return SUCCESS;
}

/**
  * @brief  Set each @ref DDL_I2C3_MasterInitTypeDef field to default value.
  * @param  I2C3_InitStruct Pointer to a @ref DDL_I2C3_MasterInitTypeDef structure.
  * @retval None
  */
void DDL_I2C3_Master_StructInit(DDL_I2C3_MasterInitTypeDef *I2C3_InitStruct)
{
  /* Set DDL_I2C3_MasterInitTypeDef fields to default values */
  I2C3_InitStruct->Mode            = DDL_I2C3_MODE_STANDARD;
  I2C3_InitStruct->Baudrate        = 0U;
  I2C3_InitStruct->SCLFilter       = 0U;
  I2C3_InitStruct->SDAFilter       = 0U;
  I2C3_InitStruct->TimeoutConfig   = DDL_I2C3_TIMEOUT_SCL;
  I2C3_InitStruct->IdleTimeout     = 0U;
  I2C3_InitStruct->PinLowTimeout   = 0U;
}

/**
  * @brief  Set each @ref DDL_I2C3_SlaveInitTypeDef field to default value.
  * @param  I2C3_InitStruct Pointer to a @ref DDL_I2C3_SlaveInitTypeDef structure.
  * @retval None
  */
void DDL_I2C3_Slave_StructInit(DDL_I2C3_SlaveInitTypeDef *I2C3_InitStruct)
{
  /* Set DDL_I2C3_SlaveInitTypeDef fields to default values */
  I2C3_InitStruct->Mode            = DDL_I2C3_MODE_STANDARD;
  I2C3_InitStruct->SCLFilter       = 0U;
  I2C3_InitStruct->SDAFilter       = 0U;
  I2C3_InitStruct->OwnAddress0     = 0U;
  I2C3_InitStruct->OwnAddress1     = 0U;
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

#endif /* I2C3 */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
