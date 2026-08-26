/**
  *
  * @file    g32f463_dal_hcd.c
  * @brief   HCD DAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the USB Peripheral Controller:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
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
  * Copyright (c) 2016 STMicroelectronics. Copyright (C) 2023-2025 Geehy Semiconductor.
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
    (#)Declare a HCD_HandleTypeDef handle structure, for example:
       HCD_HandleTypeDef  hhcd;

    (#)Fill parameters of Init structure in HCD handle

    (#)Call DAL_HCD_Init() API to initialize the HCD peripheral (Core, Host core, ...)

    (#)Initialize the HCD low level resources through the DAL_HCD_MspInit() API:
        (##) Enable the HCD/USB Low Level interface clock using the following macros
             (+++) __DAL_RCM_USB_OTG_HS_CLK_ENABLE();

        (##) Initialize the related GPIO clocks
        (##) Configure HCD pin-out
        (##) Configure HCD NVIC interrupt

    (#)Associate the Upper USB Host stack to the DAL HCD Driver:
        (##) hhcd.pData = phost;

    (#)Enable HCD transmission and reception:
        (##) DAL_HCD_Start();

  @endverbatim
  *
  */

/* Includes ------------------------------------------------------------------*/
#include "g32f463_dal.h"

/** @addtogroup G32F463_DAL_Driver
  * @{
  */

#ifdef DAL_HCD_MODULE_ENABLED
#if defined (USB_OTG_HS)
/** @defgroup HCD HCD
  * @brief HCD DAL module driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup HCD_Private_Functions HCD Private Functions
  * @{
  */
static DAL_StatusTypeDef HCD_EP0_State(HCD_HandleTypeDef *hhcd);
static uint8_t HDC_GetChannelFromEP(HCD_HandleTypeDef *hhcd, uint8_t ep_num, uint8_t ep_dir);
static uint32_t HCD_CH_GetFifoSize(uint32_t mps, uint32_t *used_fifo_size);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup HCD_Exported_Functions HCD Exported Functions
  * @{
  */

/** @defgroup HCD_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
@verbatim
 ===============================================================================
          ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the host driver.
  * @param  hhcd HCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_Init(HCD_HandleTypeDef *hhcd)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
#if (USE_HCD_CUSTOM_FIFO_SETTING == 0U)
  uint32_t fifo_size;
  uint32_t fifo_offset;
#endif /* USE_HCD_CUSTOM_FIFO_SETTING */

  /* Check the HCD handle allocation */
  if (hhcd == NULL)
  {
    return DAL_ERROR;
  }

  /* Check the parameters */
  ASSERT_PARAM(IS_HCD_ALL_INSTANCE(hhcd->Instance));

  if (hhcd->State == DAL_HCD_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hhcd->Lock = DAL_UNLOCKED;

#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
    hhcd->SOFCallback = DAL_HCD_SOF_Callback;
    hhcd->ConnectCallback = DAL_HCD_Connect_Callback;
    hhcd->DisconnectCallback = DAL_HCD_Disconnect_Callback;
    hhcd->HC_NotifyURBChangeCallback = DAL_HCD_HC_NotifyURBChange_Callback;
    hhcd->ResumeCallback = DAL_HCD_Resume_Callback;
    hhcd->SessionRequestCallback = DAL_HCD_SessionRequest_Callback;
    hhcd->VbusErrorCallback = DAL_HCD_VbusError_Callback;
    hhcd->BabbleCallback = DAL_HCD_Babble_Callback;

    if (hhcd->MspInitCallback == NULL)
    {
      hhcd->MspInitCallback = DAL_HCD_MspInit;
    }

    /* Init the low level hardware */
    hhcd->MspInitCallback(hhcd);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    DAL_HCD_MspInit(hhcd);
#endif /* (USE_DAL_HCD_REGISTER_CALLBACKS) */
  }

  hhcd->State = DAL_HCD_STATE_BUSY;

  /* Init the Core (common init.) */
  if (DDL_USB_Init(hhcd->Instance, &hhcd->Init) != SUCCESS)
  {
    hhcd->State = DAL_HCD_STATE_ERROR;
    return DAL_ERROR;
  }

  /* Init Host */
  if (DDL_USB_HostInit(hhcd->Instance, &hhcd->Init) != SUCCESS)
  {
    hhcd->State = DAL_HCD_STATE_ERROR;
    return DAL_ERROR;
  }

  /* Configure the host channel FIFOs */
  DDL_USB_SetEpIndex(USBx, 0U);
  DDL_USB_EPTX_SetFifoSize(USBx, DDL_USB_FIFO_SIZE_64);
  DDL_USB_EPTX_SetFifoAddress(USBx, 0U);
  DDL_USB_EPRX_SetFifoSize(USBx, DDL_USB_FIFO_SIZE_64);
  DDL_USB_EPRX_SetFifoAddress(USBx, 0U);
  hhcd->FIFO_Address = DDL_USB_EP0_MPS;

#if (USE_HCD_CUSTOM_FIFO_SETTING == 0U)
  for (uint8_t i = 1U; i < hhcd->Init.host_channels; i++)
  {
    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, i);

    fifo_size = HCD_CH_GetFifoSize(512U, &fifo_offset);

    DDL_USB_EPTX_SetFifoSize(USBx, fifo_size);
    DDL_USB_EPTX_SetFifoAddress(USBx, hhcd->FIFO_Address >> 3U);
    hhcd->FIFO_Address += fifo_offset;

    DDL_USB_EPRX_SetFifoSize(USBx, fifo_size);
    DDL_USB_EPRX_SetFifoAddress(USBx, hhcd->FIFO_Address >> 3U);
    hhcd->FIFO_Address += fifo_offset;
  }
#endif /* USE_HCD_CUSTOM_FIFO_SETTING */

  DDL_USB_SetEpIndex(USBx, 0U);

  hhcd->State = DAL_HCD_STATE_READY;

  return DAL_OK;
}

/**
  * @brief  Initialize a host channel.
  * @param  hhcd HCD handle
  * @param  ch_num Channel number.
  *         This parameter can be a value from 1 to 15
  * @param  epnum Endpoint number.
  *          This parameter can be a value from 1 to 15
  * @param  dev_address Current device address
  *          This parameter can be a value from 0 to 255
  * @param  speed Current device speed.
  *          This parameter can be one of these values:
  *            HCD_DEVICE_SPEED_HIGH: High speed mode,
  *            HCD_DEVICE_SPEED_FULL: Full speed mode,
  *            HCD_DEVICE_SPEED_LOW: Low speed mode
  * @param  ep_type Endpoint Type.
  *          This parameter can be one of these values:
  *            EP_TYPE_CTRL: Control type,
  *            EP_TYPE_ISOC: Isochronous type,
  *            EP_TYPE_BULK: Bulk type,
  *            EP_TYPE_INTR: Interrupt type
  * @param  mps Max Packet Size.
  *          This parameter can be a value from 0 to 32K
  * @param  interval Polling interval for data transfers. This parameter is ignored for Bulk and Control endpoints.
  *          This parameter can be a value from 0 to 255
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_HC_Init(HCD_HandleTypeDef *hhcd,
                                  uint8_t ch_num,
                                  uint8_t epnum,
                                  uint8_t dev_address,
                                  uint8_t speed,
                                  uint8_t ep_type,
                                  uint16_t mps,
                                  uint8_t interval)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  DAL_StatusTypeDef status;
  uint8_t old_ep_index;

  __DAL_LOCK(hhcd);
  hhcd->hc[ch_num].do_ping = 0U;
  hhcd->hc[ch_num].dev_addr = dev_address;
  hhcd->hc[ch_num].max_packet = mps;
  hhcd->hc[ch_num].ch_num = ch_num;
  hhcd->hc[ch_num].ep_type = ep_type;
  hhcd->hc[ch_num].ep_num = epnum & 0x7FU;

  if ((epnum & 0x80U) == 0x80U)
  {
    hhcd->hc[ch_num].ep_is_in = 1U;
  }
  else
  {
    hhcd->hc[ch_num].ep_is_in = 0U;
  }

  hhcd->hc[ch_num].speed = speed;

  hhcd->hc[ch_num].interval = interval;

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, hhcd->hc[ch_num].ep_num);

  /* Enable the host channel interrupt */
  if (hhcd->hc[ch_num].ep_is_in == 1U)
  {
    DDL_USB_EnableEpRxInterrupt(USBx, 1UL << hhcd->hc[ch_num].ep_num);
  }
  else
  {
    DDL_USB_EnableEpTxInterrupt(USBx, 1UL << hhcd->hc[ch_num].ep_num);
  }

  DDL_USB_SetAddress(USBx, hhcd->hc[ch_num].dev_addr);

  if (hhcd->hc[ch_num].ep_num == 0U)
  {
    DDL_USB_EP0_SetNAKLimit(USBx, 0U);
  }
  else
  {
    if (hhcd->hc[ch_num].ep_is_in == 1U)
    {
      DDL_USB_EPTX_SetProtocol(USBx, hhcd->hc[ch_num].ep_type);
      DDL_USB_EPTX_SetMaxPacketSize(USBx, hhcd->hc[ch_num].max_packet);

      switch (hhcd->hc[ch_num].ep_type)
      {
        case EP_TYPE_INTR:
        case EP_TYPE_ISOC:
          DDL_USB_EPTX_SetInterval(USBx, hhcd->hc[ch_num].interval);
          break;

        case EP_TYPE_BULK:
          DDL_USB_EPTX_SetNAKLimit(USBx, hhcd->hc[ch_num].interval);
          break;

        default:
          status = DAL_ERROR;
          break;
      }
    }
    else
    {
      DDL_USB_EPRX_SetProtocol(USBx, hhcd->hc[ch_num].ep_type);
      DDL_USB_EPRX_SetMaxPacketSize(USBx, hhcd->hc[ch_num].max_packet);

      switch (hhcd->hc[ch_num].ep_type)
      {
        case EP_TYPE_INTR:
        case EP_TYPE_ISOC:
          DDL_USB_EPRX_SetInterval(USBx, hhcd->hc[ch_num].interval);
          break;

        case EP_TYPE_BULK:
          DDL_USB_EPRX_SetNAKLimit(USBx, hhcd->hc[ch_num].interval);
          break;

        default:
          status = DAL_ERROR;
          break;
      }
    }
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  __DAL_UNLOCK(hhcd);

  return status;
}

/**
  * @brief  Halt a host channel.
  * @param  hhcd HCD handle
  * @param  ch_num Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_HC_Halt(HCD_HandleTypeDef *hhcd, uint8_t ch_num)
{
  DAL_StatusTypeDef status = DAL_OK;
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  uint8_t old_ep_index;

  __DAL_LOCK(hhcd);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  DDL_USB_SetEpIndex(USBx, hhcd->hc[ch_num].ep_num);
  DDL_USB_HCHalt(USBx, hhcd->hc[ch_num].ep_num);

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  __DAL_UNLOCK(hhcd);

  return status;
}

/**
  * @brief  DeInitialize the host driver.
  * @param  hhcd HCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_DeInit(HCD_HandleTypeDef *hhcd)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;

  /* Check the HCD handle allocation */
  if (hhcd == NULL)
  {
    return DAL_ERROR;
  }

  hhcd->State = DAL_HCD_STATE_BUSY;

  if (DDL_USB_StopHost(USBx) != SUCCESS)
  {
    hhcd->State = DAL_HCD_STATE_ERROR;
    return DAL_ERROR;
  }

#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
  if (hhcd->MspDeInitCallback == NULL)
  {
    hhcd->MspDeInitCallback = DAL_HCD_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware */
  hhcd->MspDeInitCallback(hhcd);
#else
  /* DeInit the low level hardware: CLOCK, NVIC.*/
  DAL_HCD_MspDeInit(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */

  hhcd->State = DAL_HCD_STATE_RESET;

  return DAL_OK;
}

/**
  * @brief  Initialize the HCD MSP.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void  DAL_HCD_MspInit(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the HCD MSP.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void  DAL_HCD_MspDeInit(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_MspDeInit could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup HCD_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   HCD IO operation functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
 [..] This subsection provides a set of functions allowing to manage the USB Host Data
    Transfer

@endverbatim
  * @{
  */

/**
  * @brief  Submit a new URB for processing.
  * @param  hhcd HCD handle
  * @param  ch_num Channel number.
  *         This parameter can be a value from 1 to 15
  * @param  direction Channel number.
  *          This parameter can be one of these values:
  *           0 : Output / 1 : Input
  * @param  ep_type Endpoint Type.
  *          This parameter can be one of these values:
  *            EP_TYPE_CTRL: Control type/
  *            EP_TYPE_ISOC: Isochronous type/
  *            EP_TYPE_BULK: Bulk type/
  *            EP_TYPE_INTR: Interrupt type/
  * @param  token Endpoint Type.
  *          This parameter can be one of these values:
  *            0: HC_PID_SETUP / 1: HC_PID_DATA1
  * @param  pbuff pointer to URB data
  * @param  length Length of URB data
  * @param  do_ping activate do ping protocol (for high speed only).
  *          This parameter can be one of these values:
  *           0 : do ping inactive / 1 : do ping active
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_HC_SubmitRequest(HCD_HandleTypeDef *hhcd,
                                           uint8_t ch_num,
                                           uint8_t direction,
                                           uint8_t ep_type,
                                           uint8_t token,
                                           uint8_t *pbuff,
                                           uint16_t length,
                                           uint8_t do_ping)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  uint8_t old_ep_index;
  uint32_t len;

  hhcd->hc[ch_num].ep_is_in = direction;
  hhcd->hc[ch_num].ep_type  = ep_type;

  if (token == USBH_PID_SETUP)
  {
    hhcd->hc[ch_num].data_pid = HC_PID_SETUP;
    hhcd->hc[ch_num].do_ping = do_ping;
  }
  else
  {
    if (hhcd->hc[ch_num].ep_is_in == 1U)
    {
      hhcd->hc[ch_num].data_pid = HC_PID_IN;
    }
    else
    {
      hhcd->hc[ch_num].data_pid = HC_PID_OUT;
    }
  }

  hhcd->hc[ch_num].xfer_buff = pbuff;
  hhcd->hc[ch_num].xfer_len  = length;
  hhcd->hc[ch_num].urb_state = URB_IDLE;
  hhcd->hc[ch_num].xfer_count = 0U;
  hhcd->hc[ch_num].ch_num = ch_num;
  hhcd->hc[ch_num].state = HC_IDLE;

  if ((hhcd->Init.speed == HCD_DEVICE_SPEED_HIGH) && \
    (token == USBH_PID_SETUP))
  {
    if (hhcd->hc[ch_num].do_ping == 1U)
    {
      USBx->CSR0 &= OTG_HS_CSR0_DISPING;
    }
    else
    {
      USBx->CSR0 |= OTG_HS_CSR0_DISPING;
    }
  }

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, hhcd->hc[ch_num].ep_num);

  if (hhcd->hc[ch_num].ep_type == EP_TYPE_CTRL)
  {
    if (hhcd->hc[ch_num].data_pid == HC_PID_SETUP)
    {
      hhcd->EP0_State = DAL_HCD_EP0_SETUP;
      DDL_USB_EP0_FlushFIFO(USBx);
      DDL_USB_WritePacket(USBx, hhcd->hc->xfer_buff, hhcd->hc[ch_num].ep_num, 8U);
      USBx->CSR0 |= (OTG_HS_CSR0_SETUPPKT | OTG_HS_CSR0_TXPKTRDY);
    }
    else if (hhcd->hc[ch_num].data_pid == HC_PID_IN)
    {
      if (hhcd->hc[ch_num].xfer_len > 0U)
      {
        hhcd->EP0_State = DAL_HCD_EP0_DATA_IN;
        USBx->CSR0 |= OTG_HS_CSR0_REQPKT;
      }
      else
      {
        hhcd->EP0_State = DAL_HCD_EP0_STATUS_IN;
        USBx->CSR0 |= OTG_HS_CSR0_REQPKT | OTG_HS_CSR0_STATUSPKT;
      }
    }
    else if (hhcd->hc[ch_num].data_pid == HC_PID_OUT)
    {
      if (hhcd->hc[ch_num].xfer_len > 0U)
      {
        hhcd->EP0_State = DAL_HCD_EP0_DATA_OUT;
        len = hhcd->hc[ch_num].xfer_len > 64U ? 64U : hhcd->hc[ch_num].xfer_len;
        DDL_USB_WritePacket(USBx, hhcd->hc->xfer_buff, hhcd->hc[ch_num].ep_num, len);
        DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USBx);
        hhcd->hc[ch_num].xfer_buff += len;
        hhcd->hc[ch_num].xfer_count += len;
      }
      else
      {
        hhcd->EP0_State = DAL_HCD_EP0_STATUS_OUT;
        USBx->CSR0 |= OTG_HS_CSR0_TXPKTRDY | OTG_HS_CSR0_STATUSPKT;
      }
    }
  }
  else if (hhcd->hc[ch_num].ep_type == EP_TYPE_BULK)
  {
    DDL_USB_SetAddress(USBx, hhcd->hc[ch_num].dev_addr);

    if (hhcd->hc[ch_num].data_pid == HC_PID_IN)
    {
      DDL_USB_EPRX_SetProtocol(USBx, DDL_USB_EP_TYPE_BULK);
      DDL_USB_EPRX_SetTargetEndpoint(USBx, hhcd->hc[ch_num].ep_num);
      DDL_USB_EPRX_EnableInPacketRequest(USBx);
    }
    else if (hhcd->hc[ch_num].data_pid == HC_PID_OUT)
    {
      DDL_USB_EPTX_SetProtocol(USBx, DDL_USB_EP_TYPE_BULK);
      DDL_USB_EPTX_SetTargetEndpoint(USBx, hhcd->hc[ch_num].ep_num);
      DDL_USB_EPTX_FlushFIFO(USBx);

      len = hhcd->hc[ch_num].xfer_len > hhcd->hc[ch_num].max_packet ? \
            hhcd->hc[ch_num].max_packet : hhcd->hc[ch_num].xfer_len;
      DDL_USB_WritePacket(USBx, hhcd->hc[ch_num].xfer_buff, hhcd->hc[ch_num].ep_num, len);
      DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USBx);
    }
  }
  else if (hhcd->hc[ch_num].ep_type == EP_TYPE_INTR)
  {
    DDL_USB_SetAddress(USBx, hhcd->hc[ch_num].dev_addr);

    if (hhcd->hc[ch_num].data_pid == HC_PID_IN)
    {
      DDL_USB_EPRX_SetProtocol(USBx, DDL_USB_EP_TYPE_INTR);
      DDL_USB_EPRX_SetTargetEndpoint(USBx, hhcd->hc[ch_num].ep_num);
      DDL_USB_EPRX_EnableInPacketRequest(USBx);
    }
    else if (hhcd->hc[ch_num].data_pid == HC_PID_OUT)
    {
      DDL_USB_EPTX_SetProtocol(USBx, DDL_USB_EP_TYPE_INTR);
      DDL_USB_EPTX_SetTargetEndpoint(USBx, hhcd->hc[ch_num].ep_num);
      DDL_USB_EPTX_FlushFIFO(USBx);

      len = hhcd->hc[ch_num].xfer_len > hhcd->hc[ch_num].max_packet ? \
            hhcd->hc[ch_num].max_packet : hhcd->hc[ch_num].xfer_len;
      DDL_USB_WritePacket(USBx, hhcd->hc[ch_num].xfer_buff, hhcd->hc[ch_num].ep_num, len);
      DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USBx);
    }
  }
  else if (hhcd->hc[ch_num].ep_type == EP_TYPE_ISOC)
  {
    //TODO
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  return DAL_OK;
}

/**
  * @brief  Handle HCD interrupt request.
  * @param  hhcd HCD handle
  * @retval None
  */
void DAL_HCD_IRQHandler(HCD_HandleTypeDef *hhcd)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  uint32_t usb_int_status;
  uint32_t usb_tx_int_status;
  uint32_t usb_rx_int_status;
  uint32_t ep_status;
  uint8_t old_ep_index;
  uint8_t ep_num;
  uint8_t ch_num;
  uint32_t len;
  uint32_t rx_count;

  usb_int_status = DDL_USB_ReadInterrupts(USBx);
  usb_tx_int_status = DDL_USB_ReadAllEpTxInterrupt(USBx);
  usb_rx_int_status = DDL_USB_ReadAllEpRxInterrupt(USBx);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Handle Resume Interrupt */
  if ((usb_int_status & DDL_USB_IT_RESUME) != RESET)
  {
    /* Clear the suspend enable signaling */
    DDL_USB_DisableSuspendMode(USBx);

#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
    hhcd->ResumeCallback(hhcd);
#else
    DAL_HCD_Resume_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
  }

  /* Handle Session Request Interrupt */
  if ((usb_int_status & DDL_USB_IT_SESSION) != RESET)
  {
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
    hhcd->SessionRequestCallback(hhcd);
#else
    DAL_HCD_SessionRequest_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
    DDL_USB_EnableSessionRequest(USBx);
  }

  /* Handle VBUS Error Interrupt */
  if ((usb_int_status & DDL_USB_IT_VBUS_ERROR) != RESET)
  {
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
    hhcd->VbusErrorCallback(hhcd);
#else
    DAL_HCD_VbusError_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
  }

  /* Handle Connect Interrupt */
  if ((usb_int_status & DDL_USB_IT_CONNECT) != RESET)
  {
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->ConnectCallback(hhcd);
#else
      DAL_HCD_Connect_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
  }

  /* Handle Disconnect Interrupt */
  if ((usb_int_status & DDL_USB_IT_DISCONNECT) != RESET)
  {
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
        hhcd->DisconnectCallback(hhcd);
#else
        DAL_HCD_Disconnect_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
  }

  /* Handle Babble Interrupt */
  if ((usb_int_status & DDL_USB_IT_BABBLE) != RESET)
  {
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->BabbleCallback(hhcd);
#else
      DAL_HCD_Babble_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
  }

  /* Handle SOF Interrupt */
  if ((usb_int_status & DDL_USB_IT_SOF) != RESET)
  {
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
      hhcd->SOFCallback(hhcd);
#else
      DAL_HCD_SOF_Callback(hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
  }

  /* Endpoint 0 Interrupts */
  usb_tx_int_status &= USBx->INTR_TXE;
  if ((usb_tx_int_status & DDL_USB_IT_EP_0) != RESET)
  {
    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, 0U);
    HCD_EP0_State(hhcd);
    usb_tx_int_status &= ~DDL_USB_IT_EP_0;
  }

  /* IN Endpoint Interrupts */
  ep_num = 1U;
  while (usb_rx_int_status != 0U)
  {
    if ((usb_rx_int_status & (1U << ep_num)) != 0U)
    {
      ch_num = HDC_GetChannelFromEP(hhcd, ep_num, 1U);
      if (ch_num == 0xFFU)
      {
        /* Clear the IN EP interrupt flag */
        usb_rx_int_status &= ~(1U << ep_num);
        continue;
      }

      /* Set the new endpoint index */
      DDL_USB_SetEpIndex(USBx, ep_num & EP_ADDR_MSK);

      /* Get the endpoint status */
      ep_status = USBx->RX_CSR;

      if ((ep_status & OTG_HS_RX_CSR_ERROR) != RESET)
      {
        USBx->RX_CSR = 0U;

        hhcd->hc[ch_num].state = HC_XACTERR;
        hhcd->hc[ch_num].urb_state = URB_ERROR;
      }
      else if ((ep_status & OTG_HS_RX_CSR_DATAERROR_NAKTIMEOUT) != RESET)
      {
        USBx->RX_CSR = 0U;
        DDL_USB_EPRX_FlushFIFO(USBx);
        DDL_USB_EPRX_ClearDataToggle(USBx);
        hhcd->hc[ch_num].state = HC_NAKTIMEOUT;
        hhcd->hc[ch_num].urb_state = URB_NOTREADY;
      }
      else if ((ep_status & OTG_HS_RX_CSR_SENTSTALL) != RESET)
      {
        // USBx->RX_CSR = 0U;
        // DDL_USB_EPRX_FlushFIFO(USBx);
        DDL_USB_EPRX_ClearDataToggle(USBx);
        hhcd->hc[ch_num].state = HC_STALL;
        hhcd->hc[ch_num].urb_state = URB_STALL;
      }
      else if ((ep_status & OTG_HS_RX_CSR_RXPKTRDY) != RESET)
      {
        /* Get the length of the packet */
        len = (hhcd->hc[ch_num].xfer_len > hhcd->hc[ch_num].max_packet) ? hhcd->hc[ch_num].max_packet : hhcd->hc[ch_num].xfer_len;
        rx_count = DDL_USB_EPRX_GetRxDataCount(USBx);

        len = (rx_count > len) ? len : rx_count;

        /* Read the packet from the FIFO */
        if ((len > 0U) && (hhcd->hc[ch_num].xfer_buff != (void *)0))
        {
          (void)DDL_USB_ReadPacket(USBx, hhcd->hc[ch_num].xfer_buff, ep_num, len);
          hhcd->hc[ch_num].xfer_buff += len;
          hhcd->hc[ch_num].xfer_count += len;

          DDL_USB_EPRX_FlushFIFO(USBx);
          USBx->RX_CSR &= ~OTG_HS_RX_CSR_RXPKTRDY;

          if ((hhcd->hc[ch_num].xfer_count >= hhcd->hc[ch_num].xfer_len) || len < hhcd->hc[ch_num].max_packet)
          {
            hhcd->hc[ch_num].state = HC_XFRC;
            hhcd->hc[ch_num].urb_state = URB_DONE;
          }
          else
          {
              /* Prepare the next IN transfer */
              DDL_USB_EPRX_EnableInPacketRequest(USBx);
          }
        }
        else
        {
          USBx->RX_CSR &= ~OTG_HS_RX_CSR_RXPKTRDY;
          hhcd->hc[ch_num].urb_state = URB_ERROR;
        }
      }

      /* Clear the IN EP interrupt flag */
      usb_rx_int_status &= ~(1U << ep_num);
    }
    ep_num++;
  }


  /* OUT Endpoint Interrupts */
  ep_num = 1U;
  while (usb_tx_int_status != 0U)
  {
    if ((usb_tx_int_status & (1U << ep_num)) != 0U)
    {
      ch_num = HDC_GetChannelFromEP(hhcd, ep_num, 0U);
      if (ch_num == 0xFFU)
      {
        /* Clear the OUT EP interrupt flag */
        usb_tx_int_status &= ~(1U << ep_num);
        continue;
      }

      /* Set the new endpoint index */
      DDL_USB_SetEpIndex(USBx, ep_num & EP_ADDR_MSK);

      /* Get the endpoint status */
      ep_status = USBx->TX_CSR;

      if ((ep_status & OTG_HS_TX_CSR_ERROR) != RESET)
      {
        USBx->TX_CSR = 0U;

        hhcd->hc[ch_num].state = HC_XACTERR;
        hhcd->hc[ch_num].urb_state = URB_ERROR;
      }
      else if ((ep_status & OTG_HS_TX_CSR_NAKTIMEOUT) != RESET)
      {
        // USBx->TX_CSR = 0U;
        hhcd->hc[ch_num].state = HC_NAKTIMEOUT;
        hhcd->hc[ch_num].urb_state = URB_NOTREADY;
      }
      else if ((ep_status & OTG_HS_TX_CSR_SENTSTALL) != RESET)
      {
        // USBx->RX_CSR = 0U;
        // DDL_USB_EPRX_FlushFIFO(USBx);
        DDL_USB_EPTX_ClearDataToggle(USBx);
        hhcd->hc[ch_num].state = HC_STALL;
        hhcd->hc[ch_num].urb_state = URB_STALL;
      }
      else if ((ep_status & OTG_HS_TX_CSR_TXPKTRDY) == RESET)
      {
        len = hhcd->hc[ch_num].xfer_len - hhcd->hc[ch_num].xfer_count;
        len = (len > hhcd->hc[ch_num].max_packet) ? hhcd->hc[ch_num].max_packet : len;

        hhcd->hc[ch_num].xfer_buff += len;
        hhcd->hc[ch_num].xfer_count += len;

        if (hhcd->hc[ch_num].xfer_count < hhcd->hc[ch_num].xfer_len)
        {
          DDL_USB_WritePacket(USBx, hhcd->hc[ch_num].xfer_buff, hhcd->hc[ch_num].ep_num, len);
          DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USBx);
        }
        else
        {
          hhcd->hc[ch_num].state = HC_XFRC;
          hhcd->hc[ch_num].urb_state = URB_DONE;
        }
      }

      /* Clear the OUT EP interrupt flag */
      usb_tx_int_status &= ~(1U << ep_num);
    }
    ep_num++;
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);
}


/**
  * @brief  Handles HCD Wakeup interrupt request.
  * @param  hhcd HCD handle
  * @retval DAL status
  */
void DAL_HCD_WKUP_IRQHandler(HCD_HandleTypeDef *hhcd)
{
  UNUSED(hhcd);
}


/**
  * @brief  SOF callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_SOF_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_SOF_Callback could be implemented in the user file
   */
}

/**
  * @brief Connection Event callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_Connect_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_Connect_Callback could be implemented in the user file
   */
}

/**
  * @brief  Disconnection Event callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_Disconnect_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_Disconnect_Callback could be implemented in the user file
   */
}

/**
  * @brief  Notify URB state change callback.
  * @param  hhcd HCD handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @param  urb_state:
  *          This parameter can be one of these values:
  *            URB_IDLE/
  *            URB_DONE/
  *            URB_NOTREADY/
  *            URB_NYET/
  *            URB_ERROR/
  *            URB_STALL/
  * @retval None
  */
__weak void DAL_HCD_HC_NotifyURBChange_Callback(HCD_HandleTypeDef *hhcd, uint8_t chnum, HCD_URBStateTypeDef urb_state)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);
  UNUSED(chnum);
  UNUSED(urb_state);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_HC_NotifyURBChange_Callback could be implemented in the user file
   */
}

/**
  * @brief  Resume callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_Resume_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_Resume_Callback could be implemented in the user file
   */
}

/**
  * @brief  Session Request callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_SessionRequest_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_SessionRequest_Callback could be implemented in the user file
   */
}

/**
  * @brief  VBUS Error callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_VbusError_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_VbusError_Callback could be implemented in the user file
   */
}

/**
  * @brief  Babble Error callback.
  * @param  hhcd HCD handle
  * @retval None
  */
__weak void DAL_HCD_Babble_Callback(HCD_HandleTypeDef *hhcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_Babble_Callback could be implemented in the user file
   */
}

/**
  * @brief  Delay callback used in the HCD Driver.
  * @param  hhcd HCD handle
  * @param  Delay: Delay in ms
  * @retval None
  */
__weak void DAL_HCD_Delay_Callback(HCD_HandleTypeDef *hhcd, uint32_t Delay)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hhcd);
  UNUSED(Delay);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_HCD_Delay_Callback could be implemented in the user file
   */
}

#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
/**
  * @brief  Register a User USB HCD Callback
  *         To be used instead of the weak predefined callback
  * @param  hhcd USB HCD handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref DAL_HCD_SOF_CB_ID USB HCD SOF callback ID
  *          @arg @ref DAL_HCD_CONNECT_CB_ID USB HCD Connect callback ID
  *          @arg @ref DAL_HCD_DISCONNECT_CB_ID OTG HCD Disconnect callback ID
  *          @arg @ref DAL_HCD_RESUME_CB_ID USB HCD Resume callback ID
  *          @arg @ref DAL_HCD_SESSION_REQUEST_CB_ID USB HCD Session Request callback ID
  *          @arg @ref DAL_HCD_VBUS_ERROR_CB_ID USB HCD VBUS Error callback ID
  *          @arg @ref DAL_HCD_BABBLE_CB_ID USB HCD Babble Error callback ID
  *          @arg @ref DAL_HCD_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref DAL_HCD_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_RegisterCallback(HCD_HandleTypeDef *hhcd,
                                           DAL_HCD_CallbackIDTypeDef CallbackID,
                                           pHCD_CallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;
    return DAL_ERROR;
  }
  /* Process locked */
  __DAL_LOCK(hhcd);

  if (hhcd->State == DAL_HCD_STATE_READY)
  {
    switch (CallbackID)
    {
      case DAL_HCD_SOF_CB_ID :
        hhcd->SOFCallback = pCallback;
        break;

      case DAL_HCD_CONNECT_CB_ID :
        hhcd->ConnectCallback = pCallback;
        break;

      case DAL_HCD_DISCONNECT_CB_ID :
        hhcd->DisconnectCallback = pCallback;
        break;

      case DAL_HCD_RESUME_CB_ID :
        hhcd->ResumeCallback = pCallback;
        break;

      case DAL_HCD_SESSION_REQUEST_CB_ID :
        hhcd->SessionRequestCallback = pCallback;
        break;

      case DAL_HCD_VBUS_ERROR_CB_ID :
        hhcd->VbusErrorCallback = pCallback;
        break;

      case DAL_HCD_BABBLE_CB_ID :
        hhcd->BabbleCallback = pCallback;
        break;

      case DAL_HCD_MSPINIT_CB_ID :
        hhcd->MspInitCallback = pCallback;
        break;

      case DAL_HCD_MSPDEINIT_CB_ID :
        hhcd->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else if (hhcd->State == DAL_HCD_STATE_RESET)
  {
    switch (CallbackID)
    {
      case DAL_HCD_MSPINIT_CB_ID :
        hhcd->MspInitCallback = pCallback;
        break;

      case DAL_HCD_MSPDEINIT_CB_ID :
        hhcd->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hhcd);
  return status;
}

/**
  * @brief  Unregister an USB HCD Callback
  *         USB HCD callback is redirected to the weak predefined callback
  * @param  hhcd USB HCD handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref DAL_HCD_SOF_CB_ID USB HCD SOF callback ID
  *          @arg @ref DAL_HCD_CONNECT_CB_ID USB HCD Connect callback ID
  *          @arg @ref DAL_HCD_DISCONNECT_CB_ID OTG HCD Disconnect callback ID
  *          @arg @ref DAL_HCD_RESUME_CB_ID USB HCD Resume callback ID
  *          @arg @ref DAL_HCD_SESSION_REQUEST_CB_ID USB HCD Session Request callback ID
  *          @arg @ref DAL_HCD_VBUS_ERROR_CB_ID USB HCD VBUS Error callback ID
  *          @arg @ref DAL_HCD_BABBLE_CB_ID USB HCD Babble Error callback ID
  *          @arg @ref DAL_HCD_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref DAL_HCD_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_UnRegisterCallback(HCD_HandleTypeDef *hhcd, DAL_HCD_CallbackIDTypeDef CallbackID)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hhcd);

  /* Setup Legacy weak Callbacks  */
  if (hhcd->State == DAL_HCD_STATE_READY)
  {
    switch (CallbackID)
    {
      case DAL_HCD_SOF_CB_ID :
        hhcd->SOFCallback = DAL_HCD_SOF_Callback;
        break;

      case DAL_HCD_CONNECT_CB_ID :
        hhcd->ConnectCallback = DAL_HCD_Connect_Callback;
        break;

      case DAL_HCD_DISCONNECT_CB_ID :
        hhcd->DisconnectCallback = DAL_HCD_Disconnect_Callback;
        break;

      case DAL_HCD_RESUME_CB_ID :
        hhcd->ResumeCallback = DAL_HCD_Resume_Callback;
        break;

      case DAL_HCD_SESSION_REQUEST_CB_ID :
        hhcd->SessionRequestCallback = DAL_HCD_SessionRequest_Callback;
        break;

      case DAL_HCD_VBUS_ERROR_CB_ID :
        hhcd->VbusErrorCallback = DAL_HCD_VbusError_Callback;
        break;

      case DAL_HCD_BABBLE_CB_ID :
        hhcd->BabbleCallback = DAL_HCD_Babble_Callback;
        break;

      case DAL_HCD_MSPINIT_CB_ID :
        hhcd->MspInitCallback = DAL_HCD_MspInit;
        break;

      case DAL_HCD_MSPDEINIT_CB_ID :
        hhcd->MspDeInitCallback = DAL_HCD_MspDeInit;
        break;

      default :
        /* Update the error code */
        hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else if (hhcd->State == DAL_HCD_STATE_RESET)
  {
    switch (CallbackID)
    {
      case DAL_HCD_MSPINIT_CB_ID :
        hhcd->MspInitCallback = DAL_HCD_MspInit;
        break;

      case DAL_HCD_MSPDEINIT_CB_ID :
        hhcd->MspDeInitCallback = DAL_HCD_MspDeInit;
        break;

      default :
        /* Update the error code */
        hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hhcd);
  return status;
}

/**
  * @brief  Register USB HCD Host Channel Notify URB Change Callback
  *         To be used instead of the weak DAL_HCD_HC_NotifyURBChange_Callback() predefined callback
  * @param  hhcd HCD handle
  * @param  pCallback pointer to the USB HCD Host Channel Notify URB Change Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_RegisterHC_NotifyURBChangeCallback(HCD_HandleTypeDef *hhcd,
                                                             pHCD_HC_NotifyURBChangeCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hhcd);

  if (hhcd->State == DAL_HCD_STATE_READY)
  {
    hhcd->HC_NotifyURBChangeCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hhcd);

  return status;
}

/**
  * @brief  Unregister the USB HCD Host Channel Notify URB Change Callback
  *         USB HCD Host Channel Notify URB Change Callback is redirected
  *         to the weak DAL_HCD_HC_NotifyURBChange_Callback() predefined callback
  * @param  hhcd HCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_UnRegisterHC_NotifyURBChangeCallback(HCD_HandleTypeDef *hhcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hhcd);

  if (hhcd->State == DAL_HCD_STATE_READY)
  {
    hhcd->HC_NotifyURBChangeCallback = DAL_HCD_HC_NotifyURBChange_Callback; /* Legacy weak DataOutStageCallback  */
  }
  else
  {
    /* Update the error code */
    hhcd->ErrorCode |= DAL_HCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hhcd);

  return status;
}
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup HCD_Exported_Functions_Group3 Peripheral Control functions
  *  @brief   Management functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the HCD data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Start the host driver.
  * @param  hhcd HCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_Start(HCD_HandleTypeDef *hhcd)
{
  __DAL_LOCK(hhcd);

  DDL_USB_Connect(hhcd->Instance);
  DDL_USB_EnableSessionRequest(hhcd->Instance);

  __DAL_UNLOCK(hhcd);

  return DAL_OK;
}

/**
  * @brief  Stop the host driver.
  * @param  hhcd HCD handle
  * @retval DAL status
  */

DAL_StatusTypeDef DAL_HCD_Stop(HCD_HandleTypeDef *hhcd)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;

  __DAL_LOCK(hhcd);

  DDL_USB_StopHost(USBx);

  __DAL_UNLOCK(hhcd);

  return DAL_OK;
}

/**
  * @brief  Reset the host port.
  * @param  hhcd HCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_ResetPort(HCD_HandleTypeDef *hhcd)
{
  DDL_USB_EnableBusReset(hhcd->Instance);

  DAL_HCD_Delay_Callback(hhcd, 30);

  DDL_USB_DisableBusReset(hhcd->Instance);

  DAL_HCD_Delay_Callback(hhcd, 30);

  return DAL_OK;
}

/**
  * @}
  */

/** @defgroup HCD_Exported_Functions_Group4 Peripheral State functions
  *  @brief   Peripheral State functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Return the HCD handle state.
  * @param  hhcd HCD handle
  * @retval DAL state
  */
HCD_StateTypeDef DAL_HCD_GetState(HCD_HandleTypeDef *hhcd)
{
  return hhcd->State;
}

/**
  * @brief  Return  URB state for a channel.
  * @param  hhcd HCD handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval URB state.
  *          This parameter can be one of these values:
  *            URB_IDLE/
  *            URB_DONE/
  *            URB_NOTREADY/
  *            URB_NYET/
  *            URB_ERROR/
  *            URB_STALL
  */
HCD_URBStateTypeDef DAL_HCD_HC_GetURBState(HCD_HandleTypeDef *hhcd, uint8_t chnum)
{
  return hhcd->hc[chnum].urb_state;
}


/**
  * @brief  Return the last host transfer size.
  * @param  hhcd HCD handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval last transfer size in byte
  */
uint32_t DAL_HCD_HC_GetXferCount(HCD_HandleTypeDef *hhcd, uint8_t chnum)
{
  return hhcd->hc[chnum].xfer_count;
}

/**
  * @brief  Return the Host Channel state.
  * @param  hhcd HCD handle
  * @param  chnum Channel number.
  *         This parameter can be a value from 1 to 15
  * @retval Host channel state
  *          This parameter can be one of these values:
  *            HC_IDLE/
  *            HC_XFRC/
  *            HC_DALTED/
  *            HC_NYET/
  *            HC_NAK/
  *            HC_STALL/
  *            HC_XACTERR/
  *            HC_BBLERR/
  *            HC_DATATGLERR
  */
HCD_HCStateTypeDef  DAL_HCD_HC_GetState(HCD_HandleTypeDef *hhcd, uint8_t chnum)
{
  return hhcd->hc[chnum].state;
}

/**
  * @brief  Return the current Host frame number.
  * @param  hhcd HCD handle
  * @retval Current Host frame number
  */
uint32_t DAL_HCD_GetCurrentFrame(HCD_HandleTypeDef *hhcd)
{
  return (DDL_USB_GetCurrentFrame(hhcd->Instance));
}

/**
  * @brief  Return the Host enumeration speed.
  * @param  hhcd HCD handle
  * @retval Enumeration speed
  */
uint32_t DAL_HCD_GetCurrentSpeed(HCD_HandleTypeDef *hhcd)
{
  return (DDL_USB_GetHostSpeed(hhcd->Instance));
}

/**
  * @brief  Set the USB Host high speed test mode.
  * @param  hhcd HCD handle
  * @param  testmode USB Host high speed test mode
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_SetTestMode(HCD_HandleTypeDef *hhcd, uint8_t testmode)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  uint8_t old_ep_index;

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, 0U);

  switch (testmode)
  {
    case TEST_J:
      DDL_USB_SetTestMode(USBx, DDL_USB_TEST_J);
      while(1);  /* Exit by reset */

    case TEST_K:
      DDL_USB_SetTestMode(USBx, DDL_USB_TEST_K);
      while(1);  /* Exit by reset */

    case TEST_SE0_NAK:
      DDL_USB_SetTestMode(USBx, DDL_USB_TEST_SE0_NAK);
      while(1);  /* Exit by reset */

    case TEST_PACKET:
      DDL_USB_EnableSessionRequest(USBx);
      DDL_USB_SetTestMode(USBx, DDL_USB_TEST_PACKET);
      while(1);  /* Exit by reset */

    default:
      DAL_HCD_HC_Halt(hhcd, 0U);
      break;
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  return DAL_OK;
}

/**
  * @brief  Configure the Tx/Rx FIFO size and address
  * @param  hhcd HCD handle
  * @param  ch_num Channel number
  * @param  size FIFO size
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_HCD_SetFiFo(HCD_HandleTypeDef *hhcd, uint8_t ch_num, uint16_t size)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  DAL_StatusTypeDef  ret = DAL_OK;
  uint8_t old_ep_index;
  uint16_t fifo_size;
  uint32_t fifo_offset;

  __DAL_LOCK(hhcd);

  if (ch_num != 0U)
  {
    /* Save the old endpoint index */
    old_ep_index = DDL_USB_GetEpIndex(USBx);

    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, ch_num);

    fifo_size = HCD_CH_GetFifoSize(size, &fifo_offset);

    /* Set the Tx FIFO size and address */
    DDL_USB_EPTX_SetFifoSize(USBx, fifo_size);
    DDL_USB_EPTX_SetFifoAddress(USBx, (hhcd->FIFO_Address >> 3U));

    hhcd->FIFO_Address += fifo_offset;

    /* Set the Rx FIFO size and address */
    DDL_USB_EPRX_SetFifoSize(USBx, fifo_size);
    DDL_USB_EPRX_SetFifoAddress(USBx, (hhcd->FIFO_Address >> 3U));

    hhcd->FIFO_Address += fifo_offset;

    /* Restore the old endpoint index */
    DDL_USB_SetEpIndex(USBx, old_ep_index);
  }

  __DAL_UNLOCK(hhcd);

  return ret;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup HCD_Private_Functions
  * @{
  */

/**
  * @brief  process EP 0 state
  * @param  hhcd HCD handle
  * @retval DAL status
  */
static DAL_StatusTypeDef HCD_EP0_State(HCD_HandleTypeDef *hhcd)
{
  USB_OTG_TypeDef *USBx = hhcd->Instance;
  uint32_t ep0_status;
  DAL_StatusTypeDef ret = DAL_OK;
  uint32_t len;
  uint8_t ch_num_in = HDC_GetChannelFromEP(hhcd, 0U, 1U);
  uint8_t ch_num_out = HDC_GetChannelFromEP(hhcd, 0U, 0U);

  /* Get the EP0 status */
  ep0_status = USBx->CSR0;

  if ((ep0_status & OTG_HS_CSR0_ERROR) != RESET)
  {
    USBx->CSR0 = 0U;

    hhcd->hc[ch_num_in].state = HC_XACTERR;
    hhcd->hc[ch_num_in].urb_state = URB_ERROR;
    hhcd->hc[ch_num_out].state = HC_XACTERR;
    hhcd->hc[ch_num_out].urb_state = URB_ERROR;
    return DAL_ERROR;
  }

  if ((ep0_status & OTG_HS_CSR0_NAKTIMEOUT) != RESET)
  {
    DDL_USB_EP0_ClearActiveFlag_NAKTIMEOUT(USBx);
    hhcd->hc[ch_num_in].state = HC_NAKTIMEOUT;
    hhcd->hc[ch_num_in].urb_state = URB_NOTREADY;
    return DAL_ERROR;
  }

  if ((ep0_status & OTG_HS_CSR0_RXSTALL) != RESET)
  {
    DDL_USB_EP0_ClearActiveFlag_STALL(USBx);
    hhcd->hc[ch_num_in].state = HC_STALL;
    hhcd->hc[ch_num_in].urb_state = URB_STALL;
    hhcd->hc[ch_num_out].state = HC_STALL;
    hhcd->hc[ch_num_out].urb_state = URB_STALL;

    hhcd->EP0_State = DAL_HCD_EP0_STALL;
    return DAL_ERROR;
  }

  switch (hhcd->EP0_State)
  {
    case DAL_HCD_EP0_SETUP:
      hhcd->hc[ch_num_out].urb_state = URB_DONE;
      break;

    case DAL_HCD_EP0_DATA_IN:
      if ((ep0_status & OTG_HS_CSR0_RXPKTRDY) != RESET)
      {
        len = DDL_USB_EP0_GetRxDataCount(USBx);

        if ((len > 0U) && (hhcd->hc[ch_num_in].xfer_buff != (void *)0))
        {
          (void)DDL_USB_ReadPacket(USBx, hhcd->hc[ch_num_in].xfer_buff, 0U, len);
          hhcd->hc[ch_num_in].xfer_buff += len;
          hhcd->hc[ch_num_in].xfer_count += len;

          DDL_USB_EP0_FlushFIFO(USBx);
          USBx->CSR0 &= ~OTG_HS_CSR0_RXPKTRDY;

          if ((hhcd->hc[ch_num_in].xfer_count >= hhcd->hc[ch_num_in].xfer_len) || (len < hhcd->hc[ch_num_in].max_packet))
          {
            hhcd->hc[ch_num_in].urb_state = URB_DONE;
            // hhcd->EP0_State = DAL_HCD_EP0_IDLE;
          }
          else
          {
            USBx->CSR0 |= OTG_HS_CSR0_REQPKT;
          }
        }
        else
        {
          USBx->CSR0 &= ~OTG_HS_CSR0_RXPKTRDY;
          hhcd->hc[ch_num_in].urb_state = URB_ERROR;
        }
      }
      break;

    case DAL_HCD_EP0_DATA_OUT:
      if (hhcd->hc[ch_num_out].xfer_count < hhcd->hc[ch_num_out].xfer_len)
      {
        if ((ep0_status & OTG_HS_CSR0_TXPKTRDY) == RESET)
        {
          len = hhcd->hc[ch_num_out].xfer_len - hhcd->hc[ch_num_out].xfer_count;
          len = len > 64U ? 64U : len;

          DDL_USB_WritePacket(USBx, hhcd->hc[ch_num_out].xfer_buff, 0U, len);
          DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USBx);
          hhcd->hc[ch_num_out].xfer_buff += len;
          hhcd->hc[ch_num_out].xfer_count += len;
        }
      }
      else
      {
        hhcd->hc[ch_num_out].urb_state = URB_DONE;
        // hhcd->EP0_State = DAL_HCD_EP0_IDLE;
      }
      break;

    case DAL_HCD_EP0_STATUS_IN:
      if (((ep0_status & OTG_HS_CSR0_RXPKTRDY) != RESET) &&
          ((ep0_status & OTG_HS_CSR0_STATUSPKT) != RESET))
      {
        USBx->CSR0 &= ~(OTG_HS_CSR0_RXPKTRDY | OTG_HS_CSR0_STATUSPKT);
        hhcd->hc[ch_num_in].urb_state = URB_DONE;
        hhcd->EP0_State = DAL_HCD_EP0_IDLE;
      }
      break;

    case DAL_HCD_EP0_STATUS_OUT:
      if ((ep0_status & OTG_HS_CSR0_TXPKTRDY) == RESET)
      {
        hhcd->hc[ch_num_out].urb_state = URB_DONE;
        hhcd->EP0_State = DAL_HCD_EP0_IDLE;
      }
      break;

    default:
      ret = DAL_ERROR;
      break;
  }

  return ret;
}

/**
  * @brief  Get the channel number associated to an endpoint.
  * @param  hhcd HCD handle
  * @param  ep_num Endpoint number.
  *         This parameter can be a value from 1 to 15
  * @param  ep_dir Endpoint direction.
  *         This parameter can be one of these values:
  *            EP_DIR_OUT/
  *            EP_DIR_IN
  * @retval Channel number.
  *         If the endpoint is not found the function returns 0xFF
  */
static uint8_t HDC_GetChannelFromEP(HCD_HandleTypeDef *hhcd, uint8_t ep_num, uint8_t ep_dir)
{
  for (uint8_t ch_num = 0U; ch_num < hhcd->Init.host_channels; ch_num++)
  {
    if ((hhcd->hc[ch_num].ep_num == ep_num) && (hhcd->hc[ch_num].ep_is_in == ep_dir))
    {
      return ch_num;
    }
  }

  return 0xFFU;
}

/**
  * @brief  Get the FIFO size of the specified channel.
  * @param  mps max packet size of the channel
  * @param  used_fifo_size pointer to the used FIFO size
  * @retval FIFO size
  */
static uint32_t HCD_CH_GetFifoSize(uint32_t mps, uint32_t *used_fifo_size)
{
  uint32_t i;
  uint32_t fifo_size;

  for (i = DDL_USB_FIFO_SIZE_8; i <= DDL_USB_FIFO_SIZE_4096; i++)
  {
    fifo_size = (8U << i);
    if (fifo_size >= mps)
    {
      *used_fifo_size = fifo_size;
      return i;
    }
  }

  *used_fifo_size = 0U;

  return DDL_USB_FIFO_SIZE_8;
}

/**
  * @}
  */

/**
  * @}
  */
#endif /* defined (USB_OTG_HS) */
#endif /* DAL_HCD_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */
