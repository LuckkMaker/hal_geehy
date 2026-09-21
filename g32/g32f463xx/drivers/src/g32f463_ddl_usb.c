/**
  *
  * @file    g32f463_ddl_usb.c
  * @brief   USB Low Layer DDL module driver.
  * @version V1.0.0
  * @date    2025-08-08
  *
  *          This file provides firmware functions to manage the following
  *          functionalities of the USB Peripheral Controller:
  *           + Initialization/de-initialization functions
  *           + I/O operation functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
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
  *
  @verbatim
  ==============================================================================
                    ##### How to use this driver #####
  ==============================================================================
    [..]
      (#) Fill parameters of Init structure in USB_CfgTypeDef structure.

      (#) Call USB_CoreInit() API to initialize the USB Core peripheral.

      (#) The upper DAL HCD/PCD driver will call the right routines for its internal processes.

  @endverbatim

  *
  */

/* Includes ------------------------------------------------------------------*/
#include "g32f463_ddl_bus.h"
#include "g32f463_ddl_usb.h"

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

#if defined (USB_OTG_HS)

/** @addtogroup USB_DDL
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup USB_DDL_Private_Constants
  * @{
  */

/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @addtogroup USB_DDL_Private_Macros
  * @{
  */
#define IS_DDL_USB_EPNUM(__EP__)    ((__EP__) <= 8U)

#define IS_DDL_USB_SPEED(__SPEED__) \
  (((__SPEED__) == DDL_USB_LS_SPEED) || ((__SPEED__) == DDL_USB_FS_SPEED) || \
   ((__SPEED__) == DDL_USB_HS_SPEED))

#define IS_DDL_USB_EP_DIR(__DIR__) \
  (((__DIR__) == DDL_USB_EP_DIR_HOST_IN) || ((__DIR__) == DDL_USB_EP_DIR_HOST_OUT) || \
   ((__DIR__) == DDL_USB_EP_DIR_DEVICE_IN) || ((__DIR__) == DDL_USB_EP_DIR_DEVICE_OUT))
/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USB_DDL_Exported_Functions
  * @{
  */

/** @addtogroup USB_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize USB OTG controller registers for device mode (Registers restored to their default values).
  * @param  USBx USB Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: USB registers are de-initialized
  *          - ERROR: USB registers are not de-initialized
  */
ErrorStatus DDL_USB_DeInit(USB_OTG_TypeDef *USBx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_USB_ALL_INSTANCE(USBx));

  /* Force reset of USB clock */
  DDL_AHB1_GRP1_ForceReset(DDL_AHB1_GRP1_PERIPH_OTGHS);

  /* Release reset of USB clock */
  DDL_AHB1_GRP1_ReleaseReset(DDL_AHB1_GRP1_PERIPH_OTGHS);

  return status;
}

/**
  * @brief  Initializes the USB OTG controller registers for device mode
  * @param  USBx  USB Instance
  * @param  USB_InitStruct pointer to a DDL_USB_OTG_InitTypeDef structure
  *         that contains the configuration information for the specified USB peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: USB registers are de-initialized
  *          - ERROR: USB registers are not de-initialized
  */
ErrorStatus DDL_USB_Init(USB_OTG_TypeDef *USBx, DDL_USB_OTG_InitTypeDef *USB_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_USB_ALL_INSTANCE(USBx));
  ASSERT_PARAM(IS_DDL_USB_SPEED(USB_InitStruct->speed));

  /* Disable USB PHY bypass */
  /* Configure before PHY reset */
  DDL_USB_PHY_DisableBypass(USBx);

  /* Enable OTG function */
  /* Configure before PHY reset */
  DDL_USB_PHY_EnableOTGFunction(USBx);

  /* Configure before PHY reset */
  if (USB_InitStruct->vbus_sensing_enable != DISABLE)
  {
    DDL_USB_PHY_EnableVbusDetect(USBx);
  }
  else
  {
    DDL_USB_PHY_DisableVbusDetect(USBx);
  }

  /* Release USB PHY reset */
  DDL_USB_PHY_ReleaseReset(USBx);

  if (USB_InitStruct->speed == DDL_USB_HS_SPEED)
  {
    DDL_USB_EnableHighSpeed(USBx);
  }
  else
  {
    DDL_USB_DisableHighSpeed(USBx);
  }

  return status;
}

/**
  * @brief Set each @ref DDL_USB_OTG_InitTypeDef field to default value.
  * @param USB_InitStruct Pointer to a @ref DDL_USB_OTG_InitTypeDef structure
  *                         whose fields will be set to default values.
  * @retval None
  */

void DDL_USB_StructInit(DDL_USB_OTG_InitTypeDef *USB_InitStruct)
{
  /* Set USB_InitStruct fields to default values */
  USB_InitStruct->speed = DDL_USB_FS_SPEED;
  USB_InitStruct->sof_enable = DISABLE;
  USB_InitStruct->low_power_enable = DISABLE;
  USB_InitStruct->vbus_sensing_enable = DISABLE;
}

/**
  * @brief  Initializes the USB OTG controller registers for device mode
  * @param  USBx USB Instance
  * @param  USB_InitStruct pointer to a DDL_USB_OTG_InitTypeDef structure
  *         that contains the configuration information for the specified USB peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: USB registers are de-initialized
  *          - ERROR: USB registers are not de-initialized
  */
ErrorStatus DDL_USB_DevInit(USB_OTG_TypeDef *USBx, DDL_USB_OTG_InitTypeDef *USB_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Disable all interrupts */
  USBx->INTRUSBE = 0U;

  /* Read and clear all pending interrupts */
  (void)DDL_USB_ReadInterrupts(USBx);

  /* Read and clear all pending TX endpoints interrupts */
  (void)DDL_USB_ReadAllEpTxInterrupt(USBx);

  /* Read and clear all pending RX endpoints interrupts */
  (void)DDL_USB_ReadAllEpRxInterrupt(USBx);

  /* Enable interrupts matching to the Device mode ONLY */
  USBx->INTRUSBE |= (DDL_USB_IT_SUSPEND | DDL_USB_IT_RESUME |
                          DDL_USB_IT_RESET | DDL_USB_IT_DISCONNECT);

  DDL_USB_DisableEpTxInterrupt(USBx, DDL_USB_IT_EP_ALL);
  DDL_USB_DisableEpRxInterrupt(USBx, DDL_USB_IT_EP_ALL);

  if (USB_InitStruct->sof_enable != DISABLE)
  {
    USBx->INTRUSBE |= DDL_USB_IT_SOF;
  }

  /* Enable EP0 interrupt */
  DDL_USB_EnableEpTxInterrupt(USBx, DDL_USB_IT_EP_0);

  return status;
}

/**
  * @brief  Initializes the USB OTG controller registers for host mode
  * @param  USBx USB Instance
  * @param  USB_InitStruct pointer to a DDL_USB_OTG_InitTypeDef structure
  *         that contains the configuration information for the specified USB peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: USB registers are de-initialized
  *          - ERROR: USB registers are not de-initialized
  */
ErrorStatus DDL_USB_HostInit(USB_OTG_TypeDef *USBx, DDL_USB_OTG_InitTypeDef *USB_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Disable all interrupts */
  USBx->INTRUSBE = 0U;

  /* Clear all pending interrupts */
  (void)DDL_USB_ReadInterrupts(USBx);

  /* Read and clear all pending TX endpoints interrupts */
  (void)DDL_USB_ReadAllEpTxInterrupt(USBx);

  /* Read and clear all pending RX endpoints interrupts */
  (void)DDL_USB_ReadAllEpRxInterrupt(USBx);

  /* Enable interrupts matching to the Device mode ONLY */
  USBx->INTRUSBE |= (DDL_USB_IT_SUSPEND | DDL_USB_IT_RESUME |
                          DDL_USB_IT_BABBLE | DDL_USB_IT_CONNECT |
                          DDL_USB_IT_DISCONNECT | DDL_USB_IT_SESSION |
                          DDL_USB_IT_VBUS_ERROR | DDL_USB_IT_SOF);

  DDL_USB_DisableEpTxInterrupt(USBx, DDL_USB_IT_EP_ALL);
  DDL_USB_DisableEpRxInterrupt(USBx, DDL_USB_IT_EP_ALL);

  /* Enable EP0 interrupt */
  DDL_USB_EnableEpTxInterrupt(USBx, DDL_USB_IT_EP_0);

  return status;
}

/**
  * @}
  */

/** @addtogroup USB_DDL_EF_Control
  * @{
  */

/**
 * @brief  Halt a host channel.
 * @param  USBx USB Instance
 * @param  ch_num Channel number
 *        This parameter can be a value from 0 to 9
 * @retval None
 */
void DDL_USB_HCHalt(USB_OTG_TypeDef *USBx, uint8_t ch_num)
{
  USBx->TXCSR = 0U;
  USBx->RXCSR = 0U;
  DDL_USB_FlushFIFO(USBx, ch_num, DDL_USB_EP_DIR_HOST_IN);
  DDL_USB_FlushFIFO(USBx, ch_num, DDL_USB_EP_DIR_HOST_OUT);
}

/**
  * @brief  Get the current speed of the USB device
  * @param  USBx USB Instance
  * @retval The current speed of the USB device
  *         This parameter can be one of these values:
  *           - DDL_USB_FS_SPEED: Full Speed
  *           - DDL_USB_HS_SPEED: High Speed
  */
uint8_t DDL_USB_GetDevSpeed(USB_OTG_TypeDef *USBx)
{
  uint8_t speed;

  if (DDL_USB_IsActiveFlag_HS(USBx) != RESET)
  {
    speed = DDL_USB_HS_SPEED;
  }
  else
  {
    speed = DDL_USB_FS_SPEED;
  }

  return speed;
}

/**
  * @brief  Get the current speed of the USB host
  * @param  USBx USB Instance
  * @retval The current speed of the USB host
  *         This parameter can be one of these values:
  *           - DDL_USB_LS_SPEED: Low Speed (*)
  *           - DDL_USB_FS_SPEED: Full Speed
  *           - DDL_USB_HS_SPEED: High Speed
  */
uint8_t DDL_USB_GetHostSpeed(USB_OTG_TypeDef *USBx)
{
  uint8_t speed = DDL_USB_FS_SPEED;

  if (DDL_USB_IsActiveFlag_HSDEV(USBx) != RESET)
  {
    speed = DDL_USB_HS_SPEED;
  }
  else if (DDL_USB_IsActiveFlag_FSDEV(USBx) != RESET)
  {
    speed = DDL_USB_FS_SPEED;
  }
  else if (DDL_USB_IsActiveFlag_LSDEV(USBx) != RESET)
  {
    speed = DDL_USB_LS_SPEED;
  }

  return speed;
}

/**
  * @brief  Activate remote wakeup signaling.
  * @param  USBx USB Instance
  * retval An ErrorStatus enumeration value:
  *         - SUCCESS: Remote wakeup activated
  *         - ERROR: Remote wakeup not activated
  */
ErrorStatus DDL_USB_ActivateRemoteWakeup(USB_OTG_TypeDef *USBx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_USB_ALL_INSTANCE(USBx));

  /* Enable Remote Wakeup */
  DDL_USB_EnableBusResume(USBx);

  return status;
}

/**
  * @brief  Deactivate remote wakeup signaling.
  * @param  USBx USB Instance
  * retval An ErrorStatus enumeration value:
  *        - SUCCESS: Remote wakeup deactivated
  *        - ERROR: Remote wakeup not deactivated
  */
ErrorStatus DDL_USB_DeActivateRemoteWakeup(USB_OTG_TypeDef *USBx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_USB_ALL_INSTANCE(USBx));

  /* Disable Remote Wakeup */
  DDL_USB_DisableBusResume(USBx);

  return status;
}

/**
 * @brief  Setup and starts a transfer over the endpoint 0
 * @param  USBx USB Instance
 * @param  Ep pointer to a DDL_USB_OTG_EPTypeDef structure
 * @param  Dma USB dma enable or disable
  *          This parameter can be one of these values:
  *           0 : DMA feature not used
  *           1 : DMA feature used
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: Transfer started
 *          - ERROR: Transfer not started
 */
ErrorStatus DDL_USB_EP0StartXfer(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep, uint8_t Dma)
{
  ErrorStatus status = SUCCESS;
  uint32_t epnum = (uint32_t)Ep->num;
  uint32_t len = Ep->xfer_len;

  UNUSED(Dma);

  /* IN endpoint */
  if (Ep->is_in == 1U)
  {
    /* Zero Length Packet */
    if (len == 0U)
    {
      // Send ZLP only need to set DATAEND, if set TXPKTRDY together, will cause TXPKTRDY and RXPKTRDY both set, then error caused
      DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USBx);
      DDL_USB_EP0_EnableDataEnd(USBx);
    }
    else
    {
      if (len > Ep->maxpacket)
      {
        len = Ep->maxpacket;
      }

      DDL_USB_WritePacket(USBx, Ep->xfer_buff, 0U, len);
      DDL_USB_EnableEpTxInterrupt(USBx, (1U << epnum));

      if (len < Ep->maxpacket)
      {
        DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USBx);
        DDL_USB_EP0_EnableDataEnd(USBx);
      }
      else
      {
        DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USBx);
      }
    }
  }
  else /* OUT endpoint */
  {
    /* Do nothing for OUT endpoint 0 */
  }

  return status;
}

/**
 * @brief  Setup and starts a transfer over an endpoint
 * @param  USBx USB Instance
 * @param  Ep pointer to a DDL_USB_OTG_EPTypeDef structure
 * @param  Dma USB dma enable or disable
  *          This parameter can be one of these values:
  *           0 : DMA feature not used
  *           1 : DMA feature used
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: Transfer started
 *          - ERROR: Transfer not started
 */
ErrorStatus DDL_USB_EPStartXfer(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep, uint8_t Dma)
{
  ErrorStatus status = SUCCESS;
  uint32_t epnum = (uint32_t)Ep->num;
  uint32_t len = Ep->xfer_len;

  UNUSED(Dma);

  /* IN endpoint */
  if (Ep->is_in == 1U)
  {
    /* Zero Length Packet */
    if (len == 0U)
    {
      DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USBx);
      DDL_USB_EnableEpTxInterrupt(USBx, (1U << epnum));
    }
    else
    {
      if (len > Ep->maxpacket)
      {
        len = Ep->maxpacket;
      }

      DDL_USB_WritePacket(USBx, Ep->xfer_buff, epnum, len);
      DDL_USB_EnableEpTxInterrupt(USBx, (1U << epnum));

      DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USBx);
    }
  }
  else /* OUT endpoint */
  {
    DDL_USB_EnableEpRxInterrupt(USBx, (1U << epnum));
  }

  return status;
}

/**
  * @brief  Set a STALL condition over an endpoint
  * @param  USBx USB Instance
  * @param  Ep pointer to a DDL_USB_OTG_EPTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *         - SUCCESS: Endpoint stalled
  *         - ERROR: Endpoint not stalled
  */
ErrorStatus DDL_USB_EPSetStall(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep)
{
  ErrorStatus status = SUCCESS;
  uint32_t epnum = (uint32_t)Ep->num;

  if (epnum == 0U)
  {
    /* Clear RXPKTRDY */
    DDL_USB_EP0_ClearActiveFlag_SERRXPKTRDY(USBx);
    DDL_USB_EP0_EnableStall(USBx);
  }
  else
  {
    /* IN endpoint */
    if (Ep->is_in == 1U)
    {
      DDL_USB_EPTX_EnableStall(USBx);
    }
    else /* OUT endpoint */
    {
      DDL_USB_EPRX_EnableStall(USBx);
    }
  }

  return status;
}

/**
  * @brief  Clear a STALL condition over an endpoint
  * @param  USBx USB Instance
  * @param  Ep pointer to a DDL_USB_OTG_EPTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *        - SUCCESS: Endpoint unstalled
  *        - ERROR: Endpoint not unstalled
  */
ErrorStatus DDL_USB_EPClearStall(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep)
{
  ErrorStatus status = SUCCESS;
  uint32_t epnum = (uint32_t)Ep->num;

  if (epnum == 0U)
  {
    DDL_USB_EP0_ClearActiveFlag_STALL(USBx);
  }
  else
  {
    /* IN endpoint */
    if (Ep->is_in == 1U)
    {
      DDL_USB_EPTX_DisableStall(USBx);
      DDL_USB_EPTX_ClearActiveFlag_STALL(USBx);

      /* Reset the data toggle to DATA0 */
      DDL_USB_EPTX_ClearDataToggle(USBx);
    }
    else /* OUT endpoint */
    {
      DDL_USB_EPRX_DisableStall(USBx);
      DDL_USB_EPRX_ClearActiveFlag_STALL(USBx);

      /* Reset the data toggle to DATA0 */
      DDL_USB_EPRX_ClearDataToggle(USBx);
    }
  }

  return status;
}

/**
 * @brief  Stop the USB host mode
 * @param  USBx USB Instance
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: USB host mode stopped
 *          - ERROR: USB host mode not stopped
 */
ErrorStatus DDL_USB_StopHost(USB_OTG_TypeDef *USBx)
{
  ErrorStatus status = SUCCESS;

  /* Clear all pending interrupts */
  (void)DDL_USB_ReadInterrupts(USBx);

  /* Disable all TX endpoints interrupts */
  DDL_USB_DisableEpTxInterrupt(USBx, DDL_USB_IT_EP_ALL);

  /* Clear all pending TX endpoints interrupts */
  (void)DDL_USB_ReadAllEpTxInterrupt(USBx);

  /* Disable all RX endpoints interrupts */
  DDL_USB_DisableEpRxInterrupt(USBx, DDL_USB_IT_EP_ALL);

  /* Clear all pending RX endpoints interrupts */
  (void)DDL_USB_ReadAllEpRxInterrupt(USBx);

  for (uint32_t i = 0U; i < 9U; i++)
  {
    DDL_USB_SetEpIndex(USBx, i);
    DDL_USB_FlushFIFO(USBx, i, DDL_USB_EP_DIR_HOST_IN);
    DDL_USB_FlushFIFO(USBx, i, DDL_USB_EP_DIR_HOST_OUT);
  }

  DDL_USB_SetEpIndex(USBx, 0U);

  return status;
}

/**
 * @brief  Stop the USB device mode
 * @param  USBx USB Instance
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: USB device mode stopped
 *          - ERROR: USB device mode not stopped
 */
ErrorStatus DDL_USB_StopDevice(USB_OTG_TypeDef *USBx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_USB_ALL_INSTANCE(USBx));

  /* Disable all interrupts */
  USBx->INTRUSBE = 0U;

  /* Clear all pending interrupts */
  (void)DDL_USB_ReadInterrupts(USBx);

  /* Disable all TX endpoints interrupts */
  DDL_USB_DisableEpTxInterrupt(USBx, DDL_USB_IT_EP_ALL);

  /* Clear all pending TX endpoints interrupts */
  (void)DDL_USB_ReadAllEpTxInterrupt(USBx);

  /* Disable all RX endpoints interrupts */
  DDL_USB_DisableEpRxInterrupt(USBx, DDL_USB_IT_EP_ALL);

  /* Clear all pending RX endpoints interrupts */
  (void)DDL_USB_ReadAllEpRxInterrupt(USBx);

  for (uint32_t i = 0U; i < 9U; i++)
  {
    DDL_USB_SetEpIndex(USBx, i);
    DDL_USB_FlushFIFO(USBx, i, DDL_USB_EP_DIR_DEVICE_IN);
    DDL_USB_FlushFIFO(USBx, i, DDL_USB_EP_DIR_DEVICE_OUT);
  }

  DDL_USB_SetEpIndex(USBx, 0U);

  return status;
}

/**
  * @brief  Flushes the FIFO of the specified endpoint.
  * @param  USBx USB Instance
  * @param  EpNum Endpoint Number
  * @param  EpDir Endpoint Direction
  *         @arg @ref DDL_USB_EP_DIR_HOST_IN
  *         @arg @ref DDL_USB_EP_DIR_HOST_OUT
  *         @arg @ref DDL_USB_EP_DIR_DEVICE_IN
  *         @arg @ref DDL_USB_EP_DIR_DEVICE_OUT
  * @retval None
  */
void DDL_USB_FlushFIFO(USB_OTG_TypeDef *USBx, uint32_t EpNum, uint32_t EpDir)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_USB_ALL_INSTANCE(USBx));
  ASSERT_PARAM(IS_DDL_USB_EPNUM(EpNum));

  if (EpNum == 0U)
  {
    if (DDL_USB_EP0_IsActiveFlag_TXPKTRDY(USBx) || DDL_USB_EP0_IsActiveFlag_RXPKTRDY(USBx))
    {
      DDL_USB_EP0_FlushFIFO(USBx);
    }
  }
  else
  {
    /* Endpoint TX */
    if (EpDir & (DDL_USB_EP_DIR_HOST_OUT | DDL_USB_EP_DIR_DEVICE_IN))
    {
      if (DDL_USB_EPTX_IsActiveFlag_TXPKTRDY(USBx))
      {
        DDL_USB_EPTX_FlushFIFO(USBx);
      }
    }
    else
    {
      /* Endpoint RX */
      if (DDL_USB_EPRX_IsActiveFlag_RXPKTRDY(USBx))
      {
        DDL_USB_EPRX_FlushFIFO(USBx);
      }
    }
  }
}

/**
  * @brief  Writes a packet into the Tx FIFO associated with the EP
  * @param  USBx USB Instance
  * @param  Src Pointer to source buffer
  * @param  EpNum Endpoint Number
  * @param  Len Number of bytes to write
  * @retval An ErrorStatus enumeration value:
  *         - SUCCESS: Data is written
  *         - ERROR: Data is not written
  */
ErrorStatus DDL_USB_WritePacket(USB_OTG_TypeDef *USBx, uint8_t *Src, uint8_t EpNum, uint16_t Len)
{
  ErrorStatus status = SUCCESS;
  uint32_t *pSrc32;
  uint8_t *pSrc8;
  uint32_t i;
  uint32_t count32;
  uint32_t count8;

  if ((uint32_t)Src & 3U)
  {
    pSrc8 = Src;
    for (i = 0U; i < Len; i++)
    {
      *(__IO uint8_t *)USB_FIFO_BASE((uint32_t)USBx, (uint32_t)EpNum) = *pSrc8++;
    }
  }
  else
  {
    pSrc32 = (uint32_t *)Src;
    count32 = ((uint32_t)Len) >> 2U;
    count8 = ((uint32_t)Len) & 3U;

    for (i = 0U; i < count32; i++)
    {
      *(__IO uint32_t *)USB_FIFO_BASE((uint32_t)USBx, (uint32_t)EpNum) = *pSrc32++;
    }

    pSrc8 = (uint8_t *)pSrc32;
    for (i = 0U; i < count8; i++)
    {
      *(__IO uint8_t *)USB_FIFO_BASE((uint32_t)USBx, (uint32_t)EpNum) = *pSrc8++;
    }
  }

  return status;
}

/**
  * @brief  Reads a packet from the Rx FIFO associated with the EP
  * @param  USBx USB Instance
  * @param  Dst Pointer to destination buffer
  * @param  EpNum Endpoint Number
  * @param  Len Number of bytes to read
  * @retval An ErrorStatus enumeration value:
  *         - SUCCESS: Data is read
  *         - ERROR: Data is not read
  */
ErrorStatus DDL_USB_ReadPacket(USB_OTG_TypeDef *USBx, uint8_t *Dst, uint8_t EpNum, uint16_t Len)
{
  ErrorStatus status = SUCCESS;
  uint32_t *pDst32;
  uint8_t *pDst8;
  uint32_t i;
  uint32_t count32;
  uint32_t count8;

  if ((uint32_t)Dst & 3U)
  {
    pDst8 = Dst;
    for (i = 0U; i < Len; i++)
    {
      *pDst8++ = *(__IO uint8_t *)USB_FIFO_BASE((uint32_t)USBx, (uint32_t)EpNum);
    }
  }
  else
  {
    pDst32 = (uint32_t *)Dst;
    count32 = ((uint32_t)Len) >> 2U;
    count8 = ((uint32_t)Len) & 3U;

    for (i = 0U; i < count32; i++)
    {
      *pDst32++ = *(__IO uint32_t *)USB_FIFO_BASE((uint32_t)USBx, (uint32_t)EpNum);
    }

    pDst8 = (uint8_t *)pDst32;
    for (i = 0U; i < count8; i++)
    {
      *pDst8++ = *(__IO uint8_t *)USB_FIFO_BASE((uint32_t)USBx, (uint32_t)EpNum);
    }
  }

  return status;
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

#endif /* USB_OTG_HS */

/**
  * @}
  */
