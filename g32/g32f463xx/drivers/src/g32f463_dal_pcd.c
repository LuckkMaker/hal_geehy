/**
  *
  * @file    g32f463_dal_pcd.c
  * @brief   PCD DAL module driver.
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
      The PCD DAL driver can be used as follows:

     (#) Declare a PCD_HandleTypeDef handle structure, for example:
         PCD_HandleTypeDef  hpcd;

     (#) Fill parameters of Init structure in HCD handle

     (#) Call DAL_PCD_Init() API to initialize the PCD peripheral (Core, Device core, ...)

     (#) Initialize the PCD low level resources through the DAL_PCD_MspInit() API:
         (##) Enable the PCD/USB Low Level interface clock using
              (+++) __DAL_RCM_USB_OTG_HS_CLK_ENABLE();

         (##) Initialize the related GPIO clocks
         (##) Configure PCD pin-out
         (##) Configure PCD NVIC interrupt

     (#)Associate the Upper USB device stack to the DAL PCD Driver:
         (##) hpcd.pData = pdev;

     (#)Enable PCD transmission and reception:
         (##) DAL_PCD_Start();

  @endverbatim
  *
  */

/* Includes ------------------------------------------------------------------*/
#include "g32f463_dal.h"

/** @addtogroup G32F463_DAL_Driver
  * @{
  */

/** @defgroup PCD PCD
  * @brief PCD DAL module driver
  * @{
  */

#ifdef DAL_PCD_MODULE_ENABLED

#if defined (USB_OTG_HS)

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

#define USBD_TEST_PACKET_SIZE  0x35U

static uint8_t USBD_TestPacket[USBD_TEST_PACKET_SIZE] =
{
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0xaa,
  0xaa, 0xaa,
  0xaa, 0xaa,
  0xaa, 0xaa,
  0xaa, 0xee,
  0xee, 0xee,
  0xee, 0xee,
  0xee, 0xee,
  0xee, 0xfe, 
  0xff, 0xff,
  0xff, 0xff,
  0xff, 0xff,
  0xff, 0xff,
  0xff, 0xff, 
  0xff, 0x7f,
  0xbf, 0xdf,
  0xef, 0xf7,
  0xfb, 0xfd,
  0xfc, 0x7e,
  0xbf, 0xdf,
  0xef, 0xf7,
  0xfb, 0xfd,
  0x7e,
};

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup PCD_Private_Macros PCD Private Macros
  * @{
  */
#define PCD_MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define PCD_MAX(a, b)  (((a) > (b)) ? (a) : (b))
/**
  * @}
  */

/* Private functions prototypes ----------------------------------------------*/
/** @defgroup PCD_Private_Functions PCD Private Functions
  * @{
  */
static DAL_StatusTypeDef PCD_EP0_State(PCD_HandleTypeDef *hpcd);
static uint32_t PCD_EP_GetFifoSize(uint32_t mps, uint32_t *used_fifo_size);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PCD_Exported_Functions PCD Exported Functions
  * @{
  */

/** @defgroup PCD_Exported_Functions_Group1 Initialization and de-initialization functions
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
  * @brief  Initializes the PCD according to the specified
  *         parameters in the PCD_InitTypeDef and initialize the associated handle.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_Init(PCD_HandleTypeDef *hpcd)
{
  uint8_t i;

  /* Check the PCD handle allocation */
  if (hpcd == NULL)
  {
    return DAL_ERROR;
  }

  /* Check the parameters */
  ASSERT_PARAM(IS_PCD_ALL_INSTANCE(hpcd->Instance));

  if (hpcd->State == DAL_PCD_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hpcd->Lock = DAL_UNLOCKED;

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
    hpcd->SOFCallback = DAL_PCD_SOFCallback;
    hpcd->SetupStageCallback = DAL_PCD_SetupStageCallback;
    hpcd->ResetCallback = DAL_PCD_ResetCallback;
    hpcd->SuspendCallback = DAL_PCD_SuspendCallback;
    hpcd->ResumeCallback = DAL_PCD_ResumeCallback;
    hpcd->ConnectCallback = DAL_PCD_ConnectCallback;
    hpcd->DisconnectCallback = DAL_PCD_DisconnectCallback;
    hpcd->DataOutStageCallback = DAL_PCD_DataOutStageCallback;
    hpcd->DataInStageCallback = DAL_PCD_DataInStageCallback;
    hpcd->ISOOUTIncompleteCallback = DAL_PCD_ISOOUTIncompleteCallback;
    hpcd->ISOINIncompleteCallback = DAL_PCD_ISOINIncompleteCallback;
    hpcd->LPMCallback = DAL_PCDEx_LPM_Callback;
    hpcd->BCDCallback = DAL_PCDEx_BCD_Callback;
    hpcd->DmaCpltCallback = DAL_PCD_DmaCpltCallback;
    hpcd->DmaErrorCallback = DAL_PCD_DmaErrorCallback;

    if (hpcd->MspInitCallback == NULL)
    {
      hpcd->MspInitCallback = DAL_PCD_MspInit;
    }

    /* Init the low level hardware */
    hpcd->MspInitCallback(hpcd);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    DAL_PCD_MspInit(hpcd);
#endif /* (USE_DAL_PCD_REGISTER_CALLBACKS) */
  }

  hpcd->State = DAL_PCD_STATE_BUSY;

  /* Init the Core (common init.) */
  if (DDL_USB_Init(hpcd->Instance, &hpcd->Init) != SUCCESS)
  {
    hpcd->State = DAL_PCD_STATE_ERROR;
    return DAL_ERROR;
  }

  /* Init endpoints structures */
  for (i = 0U; i < hpcd->Init.dev_endpoints; i++)
  {
    /* Init ep structure */
    hpcd->IN_ep[i].is_in = 1U;
    hpcd->IN_ep[i].num = i;

    /* Control until ep is activated */
    hpcd->IN_ep[i].type = EP_TYPE_CTRL;
    hpcd->IN_ep[i].maxpacket = 0U;
    hpcd->IN_ep[i].xfer_buff = 0U;
    hpcd->IN_ep[i].xfer_len = 0U;
  }

  for (i = 0U; i < hpcd->Init.dev_endpoints; i++)
  {
    hpcd->OUT_ep[i].is_in = 0U;
    hpcd->OUT_ep[i].num = i;

    /* Control until ep is activated */
    hpcd->OUT_ep[i].type = EP_TYPE_CTRL;
    hpcd->OUT_ep[i].maxpacket = 0U;
    hpcd->OUT_ep[i].xfer_buff = 0U;
    hpcd->OUT_ep[i].xfer_len = 0U;
  }

  /* Init Device */
  if (DDL_USB_DevInit(hpcd->Instance, &hpcd->Init) != SUCCESS)
  {
    hpcd->State = DAL_PCD_STATE_ERROR;
    return DAL_ERROR;
  }

  hpcd->USB_Address = 0U;
  hpcd->FIFO_Address = DDL_USB_EP0_MPS;

  hpcd->State = DAL_PCD_STATE_READY;

  DDL_USB_Disconnect(hpcd->Instance);

  return DAL_OK;
}

/**
  * @brief  DeInitializes the PCD peripheral.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_DeInit(PCD_HandleTypeDef *hpcd)
{
  /* Check the PCD handle allocation */
  if (hpcd == NULL)
  {
    return DAL_ERROR;
  }

  hpcd->State = DAL_PCD_STATE_BUSY;

  /* Stop Device */
  if (DDL_USB_StopDevice(hpcd->Instance) != SUCCESS)
  {
    return DAL_ERROR;
  }

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
  if (hpcd->MspDeInitCallback == NULL)
  {
    hpcd->MspDeInitCallback = DAL_PCD_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware */
  hpcd->MspDeInitCallback(hpcd);
#else
  /* DeInit the low level hardware: CLOCK, NVIC.*/
  DAL_PCD_MspDeInit(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

  hpcd->State = DAL_PCD_STATE_RESET;

  return DAL_OK;
}

/**
  * @brief  Initializes the PCD MSP.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_MspInit(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes PCD MSP.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_MspDeInit(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_MspDeInit could be implemented in the user file
   */
}

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
/**
  * @brief  Register a User USB PCD Callback
  *         To be used instead of the weak predefined callback
  * @param  hpcd USB PCD handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref DAL_PCD_SOF_CB_ID USB PCD SOF callback ID
  *          @arg @ref DAL_PCD_SETUPSTAGE_CB_ID USB PCD Setup callback ID
  *          @arg @ref DAL_PCD_RESET_CB_ID USB PCD Reset callback ID
  *          @arg @ref DAL_PCD_SUSPEND_CB_ID USB PCD Suspend callback ID
  *          @arg @ref DAL_PCD_RESUME_CB_ID USB PCD Resume callback ID
  *          @arg @ref DAL_PCD_CONNECT_CB_ID USB PCD Connect callback ID
  *          @arg @ref DAL_PCD_DISCONNECT_CB_ID OTG PCD Disconnect callback ID
  *          @arg @ref DAL_PCD_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref DAL_PCD_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterCallback(PCD_HandleTypeDef *hpcd,
                                           DAL_PCD_CallbackIDTypeDef CallbackID,
                                           pPCD_CallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;
    return DAL_ERROR;
  }
  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    switch (CallbackID)
    {
      case DAL_PCD_SOF_CB_ID :
        hpcd->SOFCallback = pCallback;
        break;

      case DAL_PCD_SETUPSTAGE_CB_ID :
        hpcd->SetupStageCallback = pCallback;
        break;

      case DAL_PCD_RESET_CB_ID :
        hpcd->ResetCallback = pCallback;
        break;

      case DAL_PCD_SUSPEND_CB_ID :
        hpcd->SuspendCallback = pCallback;
        break;

      case DAL_PCD_RESUME_CB_ID :
        hpcd->ResumeCallback = pCallback;
        break;

      case DAL_PCD_CONNECT_CB_ID :
        hpcd->ConnectCallback = pCallback;
        break;

      case DAL_PCD_DISCONNECT_CB_ID :
        hpcd->DisconnectCallback = pCallback;
        break;

      case DAL_PCD_MSPINIT_CB_ID :
        hpcd->MspInitCallback = pCallback;
        break;

      case DAL_PCD_MSPDEINIT_CB_ID :
        hpcd->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else if (hpcd->State == DAL_PCD_STATE_RESET)
  {
    switch (CallbackID)
    {
      case DAL_PCD_MSPINIT_CB_ID :
        hpcd->MspInitCallback = pCallback;
        break;

      case DAL_PCD_MSPDEINIT_CB_ID :
        hpcd->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;
        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;
    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);
  return status;
}

/**
  * @brief  Unregister an USB PCD Callback
  *         USB PCD callback is redirected to the weak predefined callback
  * @param  hpcd USB PCD handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref DAL_PCD_SOF_CB_ID USB PCD SOF callback ID
  *          @arg @ref DAL_PCD_SETUPSTAGE_CB_ID USB PCD Setup callback ID
  *          @arg @ref DAL_PCD_RESET_CB_ID USB PCD Reset callback ID
  *          @arg @ref DAL_PCD_SUSPEND_CB_ID USB PCD Suspend callback ID
  *          @arg @ref DAL_PCD_RESUME_CB_ID USB PCD Resume callback ID
  *          @arg @ref DAL_PCD_CONNECT_CB_ID USB PCD Connect callback ID
  *          @arg @ref DAL_PCD_DISCONNECT_CB_ID OTG PCD Disconnect callback ID
  *          @arg @ref DAL_PCD_MSPINIT_CB_ID MspDeInit callback ID
  *          @arg @ref DAL_PCD_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterCallback(PCD_HandleTypeDef *hpcd, DAL_PCD_CallbackIDTypeDef CallbackID)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  /* Setup Legacy weak Callbacks  */
  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    switch (CallbackID)
    {
      case DAL_PCD_SOF_CB_ID :
        hpcd->SOFCallback = DAL_PCD_SOFCallback;
        break;

      case DAL_PCD_SETUPSTAGE_CB_ID :
        hpcd->SetupStageCallback = DAL_PCD_SetupStageCallback;
        break;

      case DAL_PCD_RESET_CB_ID :
        hpcd->ResetCallback = DAL_PCD_ResetCallback;
        break;

      case DAL_PCD_SUSPEND_CB_ID :
        hpcd->SuspendCallback = DAL_PCD_SuspendCallback;
        break;

      case DAL_PCD_RESUME_CB_ID :
        hpcd->ResumeCallback = DAL_PCD_ResumeCallback;
        break;

      case DAL_PCD_CONNECT_CB_ID :
        hpcd->ConnectCallback = DAL_PCD_ConnectCallback;
        break;

      case DAL_PCD_DISCONNECT_CB_ID :
        hpcd->DisconnectCallback = DAL_PCD_DisconnectCallback;
        break;

      case DAL_PCD_MSPINIT_CB_ID :
        hpcd->MspInitCallback = DAL_PCD_MspInit;
        break;

      case DAL_PCD_MSPDEINIT_CB_ID :
        hpcd->MspDeInitCallback = DAL_PCD_MspDeInit;
        break;

      default :
        /* Update the error code */
        hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else if (hpcd->State == DAL_PCD_STATE_RESET)
  {
    switch (CallbackID)
    {
      case DAL_PCD_MSPINIT_CB_ID :
        hpcd->MspInitCallback = DAL_PCD_MspInit;
        break;

      case DAL_PCD_MSPDEINIT_CB_ID :
        hpcd->MspDeInitCallback = DAL_PCD_MspDeInit;
        break;

      default :
        /* Update the error code */
        hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  DAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);
  return status;
}

/**
  * @brief  Register USB PCD Data OUT Stage Callback
  *         To be used instead of the weak DAL_PCD_DataOutStageCallback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD Data OUT Stage Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterDataOutStageCallback(PCD_HandleTypeDef *hpcd,
                                                       pPCD_DataOutStageCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DataOutStageCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD Data OUT Stage Callback
  *         USB PCD Data OUT Stage Callback is redirected to the weak DAL_PCD_DataOutStageCallback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterDataOutStageCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DataOutStageCallback = DAL_PCD_DataOutStageCallback; /* Legacy weak DataOutStageCallback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD Data IN Stage Callback
  *         To be used instead of the weak DAL_PCD_DataInStageCallback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD Data IN Stage Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterDataInStageCallback(PCD_HandleTypeDef *hpcd,
                                                      pPCD_DataInStageCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DataInStageCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD Data IN Stage Callback
  *         USB PCD Data OUT Stage Callback is redirected to the weak DAL_PCD_DataInStageCallback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterDataInStageCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DataInStageCallback = DAL_PCD_DataInStageCallback; /* Legacy weak DataInStageCallback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD Iso OUT incomplete Callback
  *         To be used instead of the weak DAL_PCD_ISOOUTIncompleteCallback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD Iso OUT incomplete Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterIsoOutIncpltCallback(PCD_HandleTypeDef *hpcd,
                                                       pPCD_IsoOutIncpltCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->ISOOUTIncompleteCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD Iso OUT incomplete Callback
  *         USB PCD Iso OUT incomplete Callback is redirected
  *         to the weak DAL_PCD_ISOOUTIncompleteCallback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterIsoOutIncpltCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->ISOOUTIncompleteCallback = DAL_PCD_ISOOUTIncompleteCallback; /* Legacy weak ISOOUTIncompleteCallback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD Iso IN incomplete Callback
  *         To be used instead of the weak DAL_PCD_ISOINIncompleteCallback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD Iso IN incomplete Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterIsoInIncpltCallback(PCD_HandleTypeDef *hpcd,
                                                      pPCD_IsoInIncpltCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->ISOINIncompleteCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD Iso IN incomplete Callback
  *         USB PCD Iso IN incomplete Callback is redirected
  *         to the weak DAL_PCD_ISOINIncompleteCallback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterIsoInIncpltCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->ISOINIncompleteCallback = DAL_PCD_ISOINIncompleteCallback; /* Legacy weak ISOINIncompleteCallback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD BCD Callback
  *         To be used instead of the weak DAL_PCDEx_BCD_Callback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD BCD Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterBcdCallback(PCD_HandleTypeDef *hpcd, pPCD_BcdCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->BCDCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD BCD Callback
  *         USB BCD Callback is redirected to the weak DAL_PCDEx_BCD_Callback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterBcdCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->BCDCallback = DAL_PCDEx_BCD_Callback; /* Legacy weak DAL_PCDEx_BCD_Callback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD LPM Callback
  *         To be used instead of the weak DAL_PCDEx_LPM_Callback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD LPM Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterLpmCallback(PCD_HandleTypeDef *hpcd, pPCD_LpmCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->LPMCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD LPM Callback
  *         USB LPM Callback is redirected to the weak DAL_PCDEx_LPM_Callback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterLpmCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->LPMCallback = DAL_PCDEx_LPM_Callback; /* Legacy weak DAL_PCDEx_LPM_Callback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD DMA Complete Callback
  *         To be used instead of the weak DAL_PCD_DmaCpltCallback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD DMA Complete Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterDmaCpltCallback(PCD_HandleTypeDef *hpcd,
                                               pPCD_DmaCpltCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DmaCpltCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD DMA Complete Callback
  *         USB DMA Complete Callback is redirected to the weak DAL_PCD_DmaCpltCallback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterDmaCpltCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DmaCpltCallback = DAL_PCD_DmaCpltCallback; /* Legacy weak DAL_PCD_DmaCpltCallback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Register USB PCD DMA Error Callback
  *         To be used instead of the weak DAL_PCD_DmaErrorCallback() predefined callback
  * @param  hpcd PCD handle
  * @param  pCallback pointer to the USB PCD DMA Error Callback function
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_RegisterDmaErrorCallback(PCD_HandleTypeDef *hpcd,
                                               pPCD_DmaErrorCallbackTypeDef pCallback)
{
  DAL_StatusTypeDef status = DAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    return DAL_ERROR;
  }

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DmaErrorCallback = pCallback;
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

/**
  * @brief  Unregister the USB PCD DMA Error Callback
  *         USB DMA Error Callback is redirected to the weak DAL_PCD_DmaErrorCallback() predefined callback
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_UnRegisterDmaErrorCallback(PCD_HandleTypeDef *hpcd)
{
  DAL_StatusTypeDef status = DAL_OK;

  /* Process locked */
  __DAL_LOCK(hpcd);

  if (hpcd->State == DAL_PCD_STATE_READY)
  {
    hpcd->DmaErrorCallback = DAL_PCD_DmaErrorCallback; /* Legacy weak DAL_PCD_DmaErrorCallback  */
  }
  else
  {
    /* Update the error code */
    hpcd->ErrorCode |= DAL_PCD_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  DAL_ERROR;
  }

  /* Release Lock */
  __DAL_UNLOCK(hpcd);

  return status;
}

#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup PCD_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   Data transfers functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to manage the PCD data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Start the USB device
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_Start(PCD_HandleTypeDef *hpcd)
{
  __DAL_LOCK(hpcd);

  DDL_USB_EnableSessionRequest(hpcd->Instance);
  DDL_USB_Connect(hpcd->Instance);
  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Stop the USB device.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_Stop(PCD_HandleTypeDef *hpcd)
{
  uint32_t i;

  __DAL_LOCK(hpcd);

  DDL_USB_Disconnect(hpcd->Instance);

  /* Flush TX FIFOs */
  for (i = 0U; i < hpcd->Init.dev_endpoints; i++)
  {
    DDL_USB_FlushFIFO(hpcd->Instance, i, DDL_USB_EP_DIR_DEVICE_IN);
  }

  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Handles PCD interrupt request.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
void DAL_PCD_IRQHandler(PCD_HandleTypeDef *hpcd)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint32_t usb_int_status;
  uint32_t usb_tx_int_status;
  uint32_t usb_rx_int_status;
  uint8_t old_ep_index;
  uint32_t i;
  uint32_t ep_num;
  uint32_t rx_count;
  uint32_t tx_count;
  uint32_t len;

  if (DDL_USB_IsActiveFlag_HOST(USBx) != RESET)
  {
    return;
  }

  usb_int_status = DDL_USB_ReadInterrupts(USBx);
  usb_tx_int_status = DDL_USB_ReadAllEpTxInterrupt(USBx);
  usb_rx_int_status = DDL_USB_ReadAllEpRxInterrupt(USBx);

  /* store current frame number */
  hpcd->FrameNumber = DDL_USB_GetCurrentFrame(USBx);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Handle Resume Interrupt */
  if ((usb_int_status & DDL_USB_IT_RESUME) != RESET)
  {
    /* Clear the suspend enable signaling */
    DDL_USB_DisableSuspendMode(USBx);

    if (hpcd->LPM_State == LPM_L1)
    {
      hpcd->LPM_State = LPM_L0;

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
      hpcd->LPMCallback(hpcd, PCD_LPM_L0_ACTIVE);
#else
      DAL_PCDEx_LPM_Callback(hpcd, PCD_LPM_L0_ACTIVE);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
    }
    else
    {
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
      hpcd->ResumeCallback(hpcd);
#else
      DAL_PCD_ResumeCallback(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
    }
  }

  /* Handle Suspend Interrupt */
  if ((usb_int_status & DDL_USB_IT_SUSPEND) != RESET)
  {
    DDL_USB_EnableSuspendMode(USBx);

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
        hpcd->SuspendCallback(hpcd);
#else
        DAL_PCD_SuspendCallback(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
  }

  /* Handle Disconnect Interrupt */
  if ((usb_int_status & DDL_USB_IT_DISCONNECT) != RESET)
  {
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
        hpcd->DisconnectCallback(hpcd);
#else
        DAL_PCD_DisconnectCallback(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
  }

  /* Handle Reset Interrupt */
  if ((usb_int_status & DDL_USB_IT_RESET) != RESET)
  {
    /* Disable all TX endpoints interrupts */
    DDL_USB_DisableEpTxInterrupt(USBx, DDL_USB_IT_EP_ALL);

    /* Disable all RX endpoints interrupts */
    DDL_USB_DisableEpRxInterrupt(USBx, DDL_USB_IT_EP_ALL);

    /* Enable EP0 interrupt */
    DDL_USB_EnableEpTxInterrupt(USBx, DDL_USB_IT_EP_0);

    for (i = 0U; i < hpcd->Init.dev_endpoints; i++)
    {
      /* Set the new endpoint index */
      DDL_USB_SetEpIndex(USBx, i & EP_ADDR_MSK);

#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
      USBx->TXFIFO_SZ = 0U;
      USBx->TXFIFO_ADD = 0U;
      USBx->RXFIFO_SZ = 0U;
      USBx->RXFIFO_ADD = 0U;
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */
    }

    /* Get the current device speed */
    hpcd->Init.speed = DDL_USB_GetDevSpeed(USBx);

    hpcd->EP0_State = DAL_PCD_EP0_SETUP;

    hpcd->FIFO_Address = DDL_USB_EP0_MPS;

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
      hpcd->ResetCallback(hpcd);
#else
      DAL_PCD_ResetCallback(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
  }

  /* Handle SOF Interrupt */
  if ((usb_int_status & DDL_USB_IT_SOF) != RESET)
  {
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
      hpcd->SOFCallback(hpcd);
#else
      DAL_PCD_SOFCallback(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
  }

  /* Endpoint 0 Interrupts */
  usb_tx_int_status &= USBx->INTR_TXE;
  if ((usb_tx_int_status & DDL_USB_IT_EP_0) != RESET)
  {
    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, 0U);
    PCD_EP0_State(hpcd);
    usb_tx_int_status &= ~DDL_USB_IT_EP_0;
  }

  /* IN Endpoint Interrupts */
  ep_num = 1U;
  while (usb_tx_int_status != 0U)
  {
    if ((usb_tx_int_status & (1U << ep_num)) != 0U)
    {
      /* Set the new endpoint index */
      DDL_USB_SetEpIndex(USBx, ep_num & EP_ADDR_MSK);

      if (DDL_USB_EPTX_IsActiveFlag_UNDERRUN(USBx) != RESET)
      {
        /* Clear the underrun flag */
        DDL_USB_EPTX_ClearActiveFlag_UNDERRUN(USBx);
      }

      if (hpcd->IN_ep[ep_num].xfer_len > hpcd->IN_ep[ep_num].maxpacket)
      {
        hpcd->IN_ep[ep_num].xfer_len -= hpcd->IN_ep[ep_num].maxpacket;
        hpcd->IN_ep[ep_num].xfer_buff += hpcd->IN_ep[ep_num].maxpacket;
        hpcd->IN_ep[ep_num].xfer_count += hpcd->IN_ep[ep_num].maxpacket;
      }
      else
      {
        hpcd->IN_ep[ep_num].xfer_buff += hpcd->IN_ep[ep_num].xfer_len;
        hpcd->IN_ep[ep_num].xfer_count += hpcd->IN_ep[ep_num].xfer_len;
        hpcd->IN_ep[ep_num].xfer_len = 0U;
      }

      if (hpcd->IN_ep[ep_num].xfer_len == 0U)
      {
        DDL_USB_DisableEpTxInterrupt(USBx, (1U << ep_num));
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
        hpcd->DataInStageCallback(hpcd, (uint8_t)ep_num);
#else
        DAL_PCD_DataInStageCallback(hpcd, (uint8_t)ep_num);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
      }
      else
      {
        if (hpcd->IN_ep[ep_num].xfer_len > hpcd->IN_ep[ep_num].maxpacket)
        {
          tx_count = hpcd->IN_ep[ep_num].maxpacket;
        }
        else
        {
          tx_count = hpcd->IN_ep[ep_num].xfer_len;
        }

        DDL_USB_WritePacket(USBx, hpcd->IN_ep[ep_num].xfer_buff, ep_num, tx_count);
        DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USBx);
      }

      /* Clear the IN EP interrupt flag */
      usb_tx_int_status &= ~(1U << ep_num);
    }
    ep_num++;
  }

  /* OUT Endpoint Interrupts */
  usb_rx_int_status &= USBx->INTR_RXE;
  ep_num = 1U;
  while (usb_rx_int_status != 0U)
  {
    if ((usb_rx_int_status & (1U << ep_num)) != 0U)
    {
      /* Set the new endpoint index */
      DDL_USB_SetEpIndex(USBx, ep_num & EP_ADDR_MSK);

      if (DDL_USB_EPRX_IsActiveFlag_RXPKTRDY(USBx) != RESET)
      {
        rx_count = DDL_USB_EPRX_GetRxDataCount(USBx);
        len = rx_count > hpcd->OUT_ep[ep_num].maxpacket ? hpcd->OUT_ep[ep_num].maxpacket : rx_count;

        hpcd->OUT_ep[ep_num].xfer_count += len;
        hpcd->OUT_ep[ep_num].xfer_len -= len;

        /* DMA handling */
        if (hpcd->Init.dma_enable == ENABLE)
        {
          if ((len < hpcd->OUT_ep[ep_num].maxpacket) && \
              (hpcd->OUT_ep[ep_num].xfer_len != 0U))
          {
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
            hpcd->DataOutStageCallback(hpcd, (uint8_t)ep_num);
#else
            DAL_PCD_DataOutStageCallback(hpcd, (uint8_t)ep_num);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

            DDL_USB_EPRX_ClearActiveFlag_RXPKTRDY(USBx);
            /* Disable the endpoint RX interrupt */
            DDL_USB_DisableEpRxInterrupt(USBx, (1U << ep_num));
          }
        }
        else
        {
          DDL_USB_ReadPacket(USBx, hpcd->OUT_ep[ep_num].xfer_buff, ep_num, len);
          DDL_USB_EPRX_ClearActiveFlag_RXPKTRDY(USBx);

          hpcd->OUT_ep[ep_num].xfer_buff += len;

          if ((len < hpcd->OUT_ep[ep_num].maxpacket) || \
              (hpcd->OUT_ep[ep_num].xfer_len == 0U))
          {
            /* Disable the endpoint RX interrupt */
            DDL_USB_DisableEpRxInterrupt(USBx, (1U << ep_num));
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
            hpcd->DataOutStageCallback(hpcd, (uint8_t)ep_num);
#else
            DAL_PCD_DataOutStageCallback(hpcd, (uint8_t)ep_num);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
          }
        }
      }

      /* Clear the OUT EP interrupt flag */
      usb_rx_int_status &= ~(1U << ep_num);
    }
    ep_num++;
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);
}

/**
  * @brief  Handles PCD Wakeup interrupt request.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
void DAL_PCD_WKUP_IRQHandler(PCD_HandleTypeDef *hpcd)
{
    /* Clear EINT pending Bit */
    __DAL_USB_OTG_HS_WAKEUP_EINT_CLEAR_FLAG();
}

/**
  * @brief  Handles PCD DMA interrupt request.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
void DAL_PCD_DMA_IRQHandler(PCD_HandleTypeDef *hpcd)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint32_t usb_dma_int_status;
  uint32_t ch_num;

  usb_dma_int_status = DDL_USB_DMA_ReadInterrupts(USBx);

  /* DMA Channel Interrupts */
  ch_num = 0U;
  while (usb_dma_int_status != 0U)
  {
    if ((usb_dma_int_status & (1U << ch_num)) != 0U)
    {
      /* DMA bus error */
      if (DDL_USB_DMA_IsActiveFlag_BUSERROR(USBx, ch_num) != RESET)
      {
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
        hpcd->DmaErrorCallback(hpcd, (uint8_t)ch_num);
#else
        DAL_PCD_DmaErrorCallback(hpcd, (uint8_t)ch_num);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

        /* Clear the bus error flag */
        DDL_USB_DMA_ClearActiveFlag_BUSERROR(USBx, ch_num);

        /* If a bus error occurs, skip the transfer complete handling */
        continue;
      }

      /* Call the transfer complete callback */
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
      hpcd->DmaCpltCallback(hpcd, (uint8_t)ch_num);
#else
      DAL_PCD_DmaCpltCallback(hpcd, (uint8_t)ch_num);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

      /* Clear the DMA channel interrupt flag */
      usb_dma_int_status &= ~(1U << ch_num);
    }
    ch_num++;
  }
}

/**
  * @brief  Data OUT stage callback.
  * @param  hpcd PCD handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void DAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_DataOutStageCallback could be implemented in the user file
   */
}

/**
  * @brief  Data IN stage callback
  * @param  hpcd PCD handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void DAL_PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_DataInStageCallback could be implemented in the user file
   */
}
/**
  * @brief  Setup stage callback
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_SetupStageCallback could be implemented in the user file
   */
}

/**
  * @brief  USB Start Of Frame callback.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_SOFCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_SOFCallback could be implemented in the user file
   */
}

/**
  * @brief  USB Reset callback.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_ResetCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_ResetCallback could be implemented in the user file
   */
}

/**
  * @brief  Suspend event callback.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_SuspendCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_SuspendCallback could be implemented in the user file
   */
}

/**
  * @brief  Resume event callback.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_ResumeCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_ResumeCallback could be implemented in the user file
   */
}

/**
  * @brief  Incomplete ISO OUT callback.
  * @param  hpcd PCD handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void DAL_PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_ISOOUTIncompleteCallback could be implemented in the user file
   */
}

/**
  * @brief  Incomplete ISO IN callback.
  * @param  hpcd PCD handle
  * @param  epnum endpoint number
  * @retval None
  */
__weak void DAL_PCD_ISOINIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(epnum);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_ISOINIncompleteCallback could be implemented in the user file
   */
}

/**
  * @brief  Connection event callback.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_ConnectCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_ConnectCallback could be implemented in the user file
   */
}

/**
  * @brief  Disconnection event callback.
  * @param  hpcd PCD handle
  * @retval None
  */
__weak void DAL_PCD_DisconnectCallback(PCD_HandleTypeDef *hpcd)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_DisconnectCallback could be implemented in the user file
   */
}

/**
  * @brief  DMA complete callback.
  * @param  hpcd PCD handle
  * @param  dma_ch DMA channel number
  * @retval None
  */
__weak void DAL_PCD_DmaCpltCallback(PCD_HandleTypeDef *hpcd, uint8_t dma_ch)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(dma_ch);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_DmaCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  DMA error callback.
  * @param  hpcd PCD handle
  * @param  dma_ch DMA channel number
  * @retval None
  */
__weak void DAL_PCD_DmaErrorCallback(PCD_HandleTypeDef *hpcd, uint8_t dma_ch)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(dma_ch);

  /* NOTE : This function should not be modified, when the callback is needed,
            the DAL_PCD_DmaErrorCallback could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup PCD_Exported_Functions_Group3 Peripheral Control functions
  *  @brief   management functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the PCD data
    transfers.

@endverbatim
  * @{
  */

/**
  * @brief  Connect the USB device
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_DevConnect(PCD_HandleTypeDef *hpcd)
{
  __DAL_LOCK(hpcd);

  DDL_USB_Connect(hpcd->Instance);
  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Disconnect the USB device.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_DevDisconnect(PCD_HandleTypeDef *hpcd)
{
  __DAL_LOCK(hpcd);

  DDL_USB_Disconnect(hpcd->Instance);

  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Set the USB Device address.
  * @param  hpcd PCD handle
  * @param  address new device address
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_SetAddress(PCD_HandleTypeDef *hpcd, uint8_t address)
{
  __DAL_LOCK(hpcd);
  hpcd->USB_Address = address;
  /* Note: G32F463 need to send ZLP first then set address */
  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Open the DMA for a specific endpoint.
  * @param  hpcd PCD handle
  * @param  dma_ch DMA channel number
  * @param  ep_addr endpoint address
  * @param  address memory address
  * @param  length length of data to be transferred
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_DMA_Open(PCD_HandleTypeDef *hpcd, uint8_t dma_ch, uint8_t ep_addr, uint32_t address, uint32_t length)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint32_t tempreg = 0U;
  uint16_t mps;
  uint8_t ep_dir;
  uint8_t old_ep_index;
  PCD_EPTypeDef *ep;

  if ((dma_ch >= hpcd->Init.dma_channels) || (length == 0U))
  {
    return DAL_ERROR;
  }

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    return DAL_ERROR;
  }

  __DAL_LOCK(hpcd);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  tempreg |= OTG_HS_DMA_CNTL_CNTRL_EN;        // DMA enable
  tempreg |= OTG_HS_DMA_CNTL_CNTRL_INTEN;     // Interrupt enable
  tempreg |= (ep_addr & EP_ADDR_MSK) << OTG_HS_DMA_CNTL_CNTRL_EPNUM_Pos;               // Endpoint number
  tempreg |= (OTG_HS_DMA_CNTL_CNTRL_BURST_0 |  // Burst size
              OTG_HS_DMA_CNTL_CNTRL_BURST_1);

  ep_dir = ep_addr & 0x80U;
  /* IN endpoint */
  if (ep_dir)
  {
    ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];
    /* Read DMA memory data to TX EP */
    tempreg |= DDL_USB_DMA_DIR_READ;  // DMA direction
    mps = ep->maxpacket;
  }
  else /* OUT endpoint */
  {
    ep = &hpcd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->xfer_len = length;
    ep->xfer_count = 0U;
    /* Write RX EP data to memory */
    tempreg |= DDL_USB_DMA_DIR_WRITE; // DMA direction
    mps = ep->maxpacket;
  }

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep_addr & EP_ADDR_MSK);

  if (ep_dir)
  {
    /* Multiple packet - MODE 1 */
    if (length >= mps)
    {
      tempreg |= OTG_HS_DMA_CNTL_CNTRL_MODE;
      /* Enable EP TX DMA request */
      DDL_USB_EPTX_EnableDmaRequest(USBx, DDL_USB_DMA_MODE_1);
    }
    else
    {
      /* Enable EP TX interrupt */
      // DDL_USB_EnableEpTxInterrupt(USBx, (1U << (ep_addr & EP_ADDR_MSK)));
    }
  }
  else
  {
    /* Enable EP RX interrupt */
    DDL_USB_EnableEpRxInterrupt(USBx, (1U << (ep_addr & EP_ADDR_MSK)));

    /* Multiple packet - MODE 1 */
    if (length >= mps)
    {
      /* Limit length to multiple of mps */
      length = mps;
      tempreg |= OTG_HS_DMA_CNTL_CNTRL_MODE;
      /* Enable EP RX DMA request */
      DDL_USB_EPRX_EnableDmaRequest(USBx, DDL_USB_DMA_MODE_1);
    }
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  /* Note: Unlock before enable DMA channel */
  __DAL_UNLOCK(hpcd);

  /* Configure the DMA channel */
  USBx->DMA_CH[dma_ch].DMA_ADDR = address;
  USBx->DMA_CH[dma_ch].DMA_COUNT = length;
  USBx->DMA_CH[dma_ch].DMA_CNTL = tempreg;

  return DAL_OK;
}

/**
  * @brief  Close the DMA for a specific endpoint.
  * @param  hpcd PCD handle
  * @param  dma_ch DMA channel number
  * @param  ep_addr endpoint address
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_DMA_Close(PCD_HandleTypeDef *hpcd, uint8_t dma_ch, uint8_t ep_addr)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint8_t ep_dir;
  uint8_t old_ep_index;

  if (dma_ch >= hpcd->Init.dma_channels)
  {
    return DAL_ERROR;
  }

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    return DAL_ERROR;
  }

  __DAL_LOCK(hpcd);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep_addr & EP_ADDR_MSK);

  ep_dir = ep_addr & 0x80U;
  /* IN endpoint */
  if (ep_dir)
  {
    /* Disable EP TX DMA request */
    DDL_USB_EPTX_DisableDmaRequest(USBx);
  }
  else /* OUT endpoint */
  {
    /* Disable EP RX DMA request */
    DDL_USB_EPRX_DisableDmaRequest(USBx);
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Open and configure an endpoint.
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @param  ep_mps endpoint max packet size
  * @param  ep_type endpoint type
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_Open(PCD_HandleTypeDef *hpcd, uint8_t ep_addr,
                                  uint16_t ep_mps, uint8_t ep_type)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  DAL_StatusTypeDef  ret = DAL_OK;
  PCD_EPTypeDef *ep;
  uint8_t old_ep_index;

#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
  uint16_t fifo_size;
  uint32_t fifo_offset;
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */

  if ((ep_addr & 0x80U) == 0x80U)
  {
    ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &hpcd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 0U;
  }

  ep->num = ep_addr & EP_ADDR_MSK;
  ep->maxpacket = ep_mps;
  ep->type = ep_type;

  __DAL_LOCK(hpcd);
  if (ep->num != 0U)
  {
    /* Save the old endpoint index */
    old_ep_index = DDL_USB_GetEpIndex(USBx);

    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, ep->num);

    if (ep->is_in == 1U)
    {
      DDL_USB_EPTX_SetMaxPacketSize(USBx, ep->maxpacket);

      if (ep->type == EP_TYPE_ISOC)
      {
        DDL_USB_EPTX_EnableIsoTransfer(USBx);
      }

      /* Reset the data toggle to DATA0 */
      if (DDL_USB_EPTX_IsActiveFlag_TXPKTRDY(USBx) != RESET)
      {
        DDL_USB_EPTX_FlushFIFO(USBx);
        DDL_USB_EPTX_ClearDataToggle(USBx);
      }
      else
      {
        DDL_USB_EPTX_ClearDataToggle(USBx);
      }

#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
      fifo_size = PCD_EP_GetFifoSize(ep->maxpacket, &fifo_offset);
      /* Set the Tx FIFO size and address */
      DDL_USB_EPTX_SetFifoSize(USBx, fifo_size);
      DDL_USB_EPTX_SetFifoAddress(USBx, (hpcd->FIFO_Address >> 3U));

      hpcd->FIFO_Address += fifo_offset;
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */
    }
    else
    {
      DDL_USB_EPRX_SetMaxPacketSize(USBx, ep->maxpacket);

      if (ep->type == EP_TYPE_ISOC)
      {
        DDL_USB_EPRX_EnableIsoTransfer(USBx);
      }
      else if (ep->type == EP_TYPE_BULK)
      {
        /* Do nothing */
      }
      else if (ep->type == EP_TYPE_INTR)
      {
        /* Interrupt OUT endpoint: Disable NYET response */
        DDL_USB_EPRX_DisableNYET(USBx);
      }

      /* Reset the data toggle to DATA0 */
      if (DDL_USB_EPRX_IsActiveFlag_RXPKTRDY(USBx) != RESET)
      {
        DDL_USB_EPRX_FlushFIFO(USBx);
        DDL_USB_EPRX_ClearDataToggle(USBx);
      }
      else
      {
        DDL_USB_EPRX_ClearDataToggle(USBx);
      }

#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
      fifo_size = PCD_EP_GetFifoSize(ep->maxpacket, &fifo_offset);
      /* Set the Rx FIFO size and address */
      DDL_USB_EPRX_SetFifoSize(USBx, fifo_size);
      DDL_USB_EPRX_SetFifoAddress(USBx, (hpcd->FIFO_Address >> 3U));

      hpcd->FIFO_Address += fifo_offset;
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */
    }

    /* Restore the old endpoint index */
    DDL_USB_SetEpIndex(USBx, old_ep_index);
  }
  __DAL_UNLOCK(hpcd);

  return ret;
}

/**
  * @brief  Deactivate an endpoint.
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_Close(PCD_HandleTypeDef *hpcd, uint8_t ep_addr)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  PCD_EPTypeDef *ep;
  uint8_t old_ep_index;

#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
  uint32_t fifo_offset;
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */

  if ((ep_addr & 0x80U) == 0x80U)
  {
    ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &hpcd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 0U;
  }
  ep->num = ep_addr & EP_ADDR_MSK;

  __DAL_LOCK(hpcd);
  if (ep->num != 0U)
  {
    /* Save the old endpoint index */
    old_ep_index = DDL_USB_GetEpIndex(USBx);

    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, ep->num);

    if (ep->is_in == 1U)
    {
#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
      (void)PCD_EP_GetFifoSize(ep->maxpacket, &fifo_offset);
      if (hpcd->FIFO_Address > DDL_USB_EP0_MPS)
      {
        hpcd->FIFO_Address -= fifo_offset;
      }
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */
      DDL_USB_DisableEpTxInterrupt(USBx, (1UL << ep->num));
    }
    else
    {
#if (USE_PCD_CUSTOM_FIFO_SETTING == 0U)
      (void)PCD_EP_GetFifoSize(ep->maxpacket, &fifo_offset);
      if (hpcd->FIFO_Address > DDL_USB_EP0_MPS)
      {
        hpcd->FIFO_Address -= fifo_offset;
      }
#endif /* USE_PCD_CUSTOM_FIFO_SETTING */
      DDL_USB_DisableEpRxInterrupt(USBx, (1UL << ep->num));
    }

    /* Restore the old endpoint index */
    DDL_USB_SetEpIndex(USBx, old_ep_index);
  }
  __DAL_UNLOCK(hpcd);
  return DAL_OK;
}


/**
  * @brief  Receive an amount of data.
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @param  pBuf pointer to the reception buffer
  * @param  len amount of data to be received
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_Receive(PCD_HandleTypeDef *hpcd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  PCD_EPTypeDef *ep;
  uint8_t old_ep_index;

  ep = &hpcd->OUT_ep[ep_addr & EP_ADDR_MSK];

  /*setup and start the Xfer */
  ep->xfer_buff = pBuf;
  ep->xfer_len = len;
  ep->xfer_count = 0U;
  ep->is_in = 0U;
  ep->num = ep_addr & EP_ADDR_MSK;

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep->num);

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    if (ep->xfer_len == 0U)
    {
      hpcd->EP0_State = DAL_PCD_EP0_SETUP;
    }
    else
    {
      hpcd->EP0_State = DAL_PCD_EP0_DATA_OUT;
    }

    (void)DDL_USB_EP0StartXfer(hpcd->Instance, ep, (uint8_t)hpcd->Init.dma_enable);
  }
  else
  {
    (void)DDL_USB_EPStartXfer(hpcd->Instance, ep, (uint8_t)hpcd->Init.dma_enable);
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  return DAL_OK;
}

/**
  * @brief  Get Received Data Size
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @retval Data Size
  */
uint32_t DAL_PCD_EP_GetRxCount(PCD_HandleTypeDef *hpcd, uint8_t ep_addr)
{
  return hpcd->OUT_ep[ep_addr & EP_ADDR_MSK].xfer_count;
}
/**
  * @brief  Send an amount of data
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @param  pBuf pointer to the transmission buffer
  * @param  len amount of data to be sent
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_Transmit(PCD_HandleTypeDef *hpcd, uint8_t ep_addr, uint8_t *pBuf, uint32_t len)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  PCD_EPTypeDef *ep;
  uint8_t old_ep_index;

  ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];

  /*setup and start the Xfer */
  ep->xfer_buff = pBuf;
  ep->xfer_len = len;
  ep->xfer_count = 0U;
  ep->is_in = 1U;
  ep->num = ep_addr & EP_ADDR_MSK;

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep->num);

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    if (ep->xfer_len == 0U)
    {
      /* Send ZLP via hardware, then set state SETUP to receive next SETUP */
      hpcd->EP0_State = DAL_PCD_EP0_SETUP;
    }
    else
    {
      hpcd->EP0_State = DAL_PCD_EP0_DATA_IN;
    }

    (void)DDL_USB_EP0StartXfer(hpcd->Instance, ep, (uint8_t)hpcd->Init.dma_enable);
  }
  else
  {
    (void)DDL_USB_EPStartXfer(hpcd->Instance, ep, (uint8_t)hpcd->Init.dma_enable);
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  return DAL_OK;
}

/**
  * @brief  Set a STALL condition over an endpoint
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_SetStall(PCD_HandleTypeDef *hpcd, uint8_t ep_addr)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  PCD_EPTypeDef *ep;
  uint8_t old_ep_index;

  if (((uint32_t)ep_addr & EP_ADDR_MSK) > hpcd->Init.dev_endpoints)
  {
    return DAL_ERROR;
  }

  if ((0x80U & ep_addr) == 0x80U)
  {
    ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &hpcd->OUT_ep[ep_addr];
    ep->is_in = 0U;
  }

  if ((ep_addr & EP_ADDR_MSK) == 0U)
  {
    hpcd->EP0_State = DAL_PCD_EP0_STALL;
  }

  ep->is_stall = 1U;
  ep->num = ep_addr & EP_ADDR_MSK;

  __DAL_LOCK(hpcd);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep->num);

  (void)DDL_USB_EPSetStall(hpcd->Instance, ep);

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Clear a STALL condition over in an endpoint
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_ClrStall(PCD_HandleTypeDef *hpcd, uint8_t ep_addr)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  PCD_EPTypeDef *ep;
  uint8_t old_ep_index;

  if (((uint32_t)ep_addr & 0x0FU) > hpcd->Init.dev_endpoints)
  {
    return DAL_ERROR;
  }

  if ((0x80U & ep_addr) == 0x80U)
  {
    ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 1U;
  }
  else
  {
    ep = &hpcd->OUT_ep[ep_addr & EP_ADDR_MSK];
    ep->is_in = 0U;
  }

  ep->is_stall = 0U;
  ep->num = ep_addr & EP_ADDR_MSK;

  __DAL_LOCK(hpcd);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep->num);

  (void)DDL_USB_EPClearStall(hpcd->Instance, ep);

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}


/**
 * @brief     USB device get EP stall status
 *
 * @param     usbdh: USB device handler
 *
 * @param     epAddr: endpoint address
 *
 * @retval    Stall status
 */
uint8_t DAL_PCD_EP_ReadStallStatus(PCD_HandleTypeDef *hpcd, uint8_t epAddr)
{
  if ((epAddr & 0x80) == 0x80)
  {
    return (hpcd->IN_ep[epAddr & 0x7F].is_stall);
  }
  else
  {
    return (hpcd->OUT_ep[epAddr & 0x7F].is_stall);
  }
}

/**
   * @brief  Abort an USB EP transaction.
   * @param  hpcd PCD handle
   * @param  ep_addr endpoint address
   * @retval DAL status
   */
DAL_StatusTypeDef DAL_PCD_EP_Abort(PCD_HandleTypeDef *hpcd, uint8_t ep_addr)
{
//  DAL_StatusTypeDef ret;
//  PCD_EPTypeDef *ep;

//  if ((0x80U & ep_addr) == 0x80U)
//  {
//    ep = &hpcd->IN_ep[ep_addr & EP_ADDR_MSK];
//  }
//  else
//  {
//    ep = &hpcd->OUT_ep[ep_addr & EP_ADDR_MSK];
//  }

  /* Stop Xfer */
  // ret = USB_EPStopXfer(hpcd->Instance, ep);
  //TODO(linwei): Add ISO abort support

  return DAL_OK;
}

/**
  * @brief  Flush an endpoint
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_EP_Flush(PCD_HandleTypeDef *hpcd, uint8_t ep_addr)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint8_t old_ep_index;

  __DAL_LOCK(hpcd);

  /* Save the old endpoint index */
  old_ep_index = DDL_USB_GetEpIndex(USBx);

  /* Set the new endpoint index */
  DDL_USB_SetEpIndex(USBx, ep_addr & EP_ADDR_MSK);

  if ((ep_addr & 0x80U) == 0x80U)
  {
    DDL_USB_FlushFIFO(hpcd->Instance, (uint32_t)ep_addr & EP_ADDR_MSK, DDL_USB_EP_DIR_DEVICE_IN);
  }
  else
  {
    DDL_USB_FlushFIFO(hpcd->Instance, (uint32_t)ep_addr & EP_ADDR_MSK, DDL_USB_EP_DIR_DEVICE_OUT);
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  __DAL_UNLOCK(hpcd);

  return DAL_OK;
}

/**
  * @brief  Activate remote wakeup signalling
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_ActivateRemoteWakeup(PCD_HandleTypeDef *hpcd)
{
  if (DDL_USB_ActivateRemoteWakeup(hpcd->Instance) != SUCCESS)
  {
    return DAL_ERROR;
  }

  return DAL_OK;
}

/**
  * @brief  De-activate remote wakeup signalling.
  * @param  hpcd PCD handle
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_DeActivateRemoteWakeup(PCD_HandleTypeDef *hpcd)
{
  if (DDL_USB_DeActivateRemoteWakeup(hpcd->Instance) != SUCCESS)
  {
    return DAL_ERROR;
  }

  return DAL_OK;
}

//TODO(linwei):Add support for double buffer endpoints

/**
  * @brief  Configure the Tx/Rx FIFO size and address
  * @param  hpcd PCD handle
  * @param  ep_addr endpoint address
  * @param  size FIFO size
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_SetFiFo(PCD_HandleTypeDef *hpcd, uint8_t ep_addr, uint16_t size)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  DAL_StatusTypeDef  ret = DAL_OK;
  uint8_t old_ep_index;
  uint8_t ep_num = ep_addr & EP_ADDR_MSK;
  uint8_t ep_dir = (ep_addr & 0x80U) ? 1U : 0U;
  uint16_t fifo_size;
  uint32_t fifo_offset;

  __DAL_LOCK(hpcd);

  if (ep_num != 0U)
  {
    /* Save the old endpoint index */
    old_ep_index = DDL_USB_GetEpIndex(USBx);

    /* Set the new endpoint index */
    DDL_USB_SetEpIndex(USBx, ep_num);

    if (ep_dir == 1U)
    {
      fifo_size = PCD_EP_GetFifoSize(size, &fifo_offset);

      /* Set the Tx FIFO size and address */
      DDL_USB_EPTX_SetFifoSize(USBx, fifo_size);
      DDL_USB_EPTX_SetFifoAddress(USBx, (hpcd->FIFO_Address >> 3U));

      hpcd->FIFO_Address += fifo_offset;
    }
    else
    {
      fifo_size = PCD_EP_GetFifoSize(size, &fifo_offset);

      /* Set the Rx FIFO size and address */
      DDL_USB_EPRX_SetFifoSize(USBx, fifo_size);
      DDL_USB_EPRX_SetFifoAddress(USBx, (hpcd->FIFO_Address >> 3U));

      hpcd->FIFO_Address += fifo_offset;
    }

    /* Restore the old endpoint index */
    DDL_USB_SetEpIndex(USBx, old_ep_index);
  }

  __DAL_UNLOCK(hpcd);

  return ret;
}

/**
  * @}
  */

/** @defgroup PCD_Exported_Functions_Group4 Peripheral State functions
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
  * @brief  Return the PCD handle state.
  * @param  hpcd PCD handle
  * @retval DAL state
  */
PCD_StateTypeDef DAL_PCD_GetState(PCD_HandleTypeDef *hpcd)
{
  return hpcd->State;
}

/**
  * @brief  Set the USB Device high speed test mode.
  * @param  hpcd PCD handle
  * @param  testmode USB Device high speed test mode
  * @retval DAL status
  */
DAL_StatusTypeDef DAL_PCD_SetTestMode(PCD_HandleTypeDef *hpcd, uint8_t testmode)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint8_t old_ep_index;

  for (uint32_t i = 0; i < 2000U; i++);  /* Delay to ensure IN status is sent */

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
      /* Prepare the test packet */
      DDL_USB_WritePacket(USBx, (uint8_t *)USBD_TestPacket, 0U, USBD_TEST_PACKET_SIZE);
      DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USBx);
      DDL_USB_EP0_EnableDataEnd(USBx);

      DDL_USB_SetTestMode(USBx, DDL_USB_TEST_PACKET);
      while(1);  /* Exit by reset */

    default:
      DAL_PCD_EP_SetStall(hpcd, 0x00U);
      DAL_PCD_EP_SetStall(hpcd, 0x80U);
      break;
  }

  /* Restore the old endpoint index */
  DDL_USB_SetEpIndex(USBx, old_ep_index);

  return DAL_OK;
}
/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @addtogroup PCD_Private_Functions
  * @{
  */

/**
  * @brief  process EP 0 state
  * @param  hpcd PCD handle
  * @retval DAL status
  */
static DAL_StatusTypeDef PCD_EP0_State(PCD_HandleTypeDef *hpcd)
{
  USB_OTG_TypeDef *USBx = hpcd->Instance;
  uint32_t ep0_status;
  DAL_StatusTypeDef ret = DAL_OK;
  uint16_t wLength;
  uint32_t rx_count;
  uint32_t len;

  /* Get the EP0 status */
  ep0_status = USBx->CSR0;

  if ((ep0_status & OTG_HS_CSR0_SENTSTALL) != RESET)
  {
    /* Clear the STALL flag */
    DDL_USB_EP0_ClearActiveFlag_STALL(USBx);
    hpcd->EP0_State = DAL_PCD_EP0_SETUP;
    return DAL_OK;
  }

  if ((ep0_status & OTG_HS_CSR0_SETUPEND) == OTG_HS_CSR0_SETUPEND)
  {
    /* Clear the SETUPEND flag */
    DDL_USB_EP0_ClearActiveFlag_SETUPEND(USBx);
    /* When SETUPEND is received, all the OUT data must be ignored until a new SETUP */
    hpcd->EP0_State = DAL_PCD_EP0_SETUP;
  }

  if (hpcd->USB_Address > 0U)
  {
      DDL_USB_SetAddress(USBx, hpcd->USB_Address);
      hpcd->USB_Address = 0U;
  }

  switch (hpcd->EP0_State)
  {
    case DAL_PCD_EP0_SETUP:
      if ((ep0_status & OTG_HS_CSR0_RXPKTRDY) != RESET)
      {
        rx_count = DDL_USB_EP0_GetRxDataCount(USBx);
        if (rx_count != 8U)
        {
          ret = DAL_ERROR;
        }

        DDL_USB_ReadPacket(USBx, hpcd->Setup, 0U, 8U);
        hpcd->OUT_ep[0].xfer_count += rx_count;

        wLength = (uint16_t)(hpcd->Setup[6] | (hpcd->Setup[7] << 8U));

        if (wLength > 0U)
        {
          DDL_USB_EP0_ClearActiveFlag_SERRXPKTRDY(USBx);
        }
        else
        {
          DDL_USB_EP0_ClearActiveFlag_SERRXPKTRDY(USBx);
          DDL_USB_EP0_EnableDataEnd(USBx);
        }

        /* Inform the upper layer that a setup packet is available */
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
        hpcd->SetupStageCallback(hpcd);
#else
        DAL_PCD_SetupStageCallback(hpcd);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
      }
      break;

    case DAL_PCD_EP0_DATA_IN:
      if (hpcd->IN_ep[0].xfer_len >= hpcd->IN_ep[0].maxpacket)
      {
        hpcd->IN_ep[0].xfer_buff += hpcd->IN_ep[0].maxpacket;
      }

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
      hpcd->DataInStageCallback(hpcd, 0U);
#else
      DAL_PCD_DataInStageCallback(hpcd, 0U);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */
      break;

    case DAL_PCD_EP0_DATA_OUT:
      if ((ep0_status & OTG_HS_CSR0_RXPKTRDY) != RESET)
      {
        rx_count = DDL_USB_EP0_GetRxDataCount(USBx);
        len = rx_count > hpcd->OUT_ep[0].maxpacket ? hpcd->OUT_ep[0].maxpacket : rx_count;

        DDL_USB_ReadPacket(USBx, hpcd->OUT_ep[0].xfer_buff, 0U, len);
        hpcd->OUT_ep[0].xfer_buff += len;
        hpcd->OUT_ep[0].xfer_count += len;

        if (len < hpcd->OUT_ep[0].maxpacket)
        {
#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
          hpcd->DataOutStageCallback(hpcd, 0U);
#else
          DAL_PCD_DataOutStageCallback(hpcd, 0U);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

          DDL_USB_EP0_ClearActiveFlag_SERRXPKTRDY(USBx);
          DDL_USB_EP0_EnableDataEnd(USBx);
          hpcd->EP0_State = DAL_PCD_EP0_STATUS_IN;
        }
        else
        {
          DDL_USB_EP0_ClearActiveFlag_SERRXPKTRDY(USBx);

#if (USE_DAL_PCD_REGISTER_CALLBACKS == 1U)
          hpcd->DataOutStageCallback(hpcd, 0U);
#else
          DAL_PCD_DataOutStageCallback(hpcd, 0U);
#endif /* USE_DAL_PCD_REGISTER_CALLBACKS */

        }
      }
      break;

    case DAL_PCD_EP0_STATUS_IN:
      hpcd->EP0_State = DAL_PCD_EP0_SETUP;
      break;

    default:
      ret = DAL_ERROR;
      break;
  }

  return ret;
}

/**
  * @brief  Get the FIFO size of the specified endpoint.
  * @param  mps max packet size of the endpoint
  * @param  used_fifo_size pointer to the used FIFO size
  * @retval FIFO size
  */
static uint32_t PCD_EP_GetFifoSize(uint32_t mps, uint32_t *used_fifo_size)
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
#endif /* defined (USB_OTG_HS) */
#endif /* DAL_PCD_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */
