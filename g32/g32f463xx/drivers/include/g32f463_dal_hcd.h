/**
  *
  * @file    g32f463_dal_hcd.h
  * @brief   Header file of HCD DAL module.
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
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32F463_DAL_HCD_H
#define G32F463_DAL_HCD_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f463_ddl_usb.h"

#if defined (USB_OTG_HS)
/** @addtogroup G32F463_DAL_Driver
  * @{
  */

/** @addtogroup HCD HCD
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup HCD_Exported_Types HCD Exported Types
  * @{
  */

/** @defgroup HCD_Exported_Types_Group1 HCD State Structure definition
  * @{
  */
typedef enum
{
  DAL_HCD_STATE_RESET    = 0x00,
  DAL_HCD_STATE_READY    = 0x01,
  DAL_HCD_STATE_ERROR    = 0x02,
  DAL_HCD_STATE_BUSY     = 0x03,
  DAL_HCD_STATE_TIMEOUT  = 0x04
} HCD_StateTypeDef;

/**
  * @brief  HCD EP0 State structure definition
  */
typedef enum
{
  DAL_HCD_EP0_IDLE = 0x00,
  DAL_HCD_EP0_SETUP = 0x01,
  DAL_HCD_EP0_DATA_IN = 0x02,
  DAL_HCD_EP0_DATA_OUT = 0x03,
  DAL_HCD_EP0_STATUS_IN = 0x04,
  DAL_HCD_EP0_STATUS_OUT = 0x05,
  DAL_HCD_EP0_STALL = 0x06,
} HCD_EP0_StateTypeDef;

typedef USB_OTG_TypeDef           HCD_TypeDef;
typedef DDL_USB_OTG_InitTypeDef   HCD_InitTypeDef;
typedef DDL_USB_OTG_HCTypeDef     HCD_HCTypeDef;
typedef USB_OTG_URBStateTypeDef   HCD_URBStateTypeDef;
typedef USB_OTG_HCStateTypeDef    HCD_HCStateTypeDef;
/**
  * @}
  */

/** @defgroup HCD_Exported_Types_Group2 HCD Handle Structure definition
  * @{
  */
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
typedef struct __HCD_HandleTypeDef
#else
typedef struct
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
{
  HCD_TypeDef                 *Instance;    /*!< Register base address    */
  HCD_InitTypeDef             Init;         /*!< HCD required parameters  */
  __IO uint32_t               FIFO_Address; /*!< FIFO address             */
  HCD_HCTypeDef               hc[16];       /*!< Host channels parameters */
    __IO HCD_EP0_StateTypeDef EP0_State;    /*!< Endpoint 0 state         */
  DAL_LockTypeDef             Lock;         /*!< HCD peripheral status    */
  __IO HCD_StateTypeDef       State;        /*!< HCD communication state  */
  __IO  uint32_t              ErrorCode;    /*!< HCD Error code           */
  void                        *pData;       /*!< Pointer Stack Handler    */
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
  void (* SOFCallback)(struct __HCD_HandleTypeDef *hhcd);                               /*!< USB OTG HCD SOF callback                */
  void (* ConnectCallback)(struct __HCD_HandleTypeDef *hhcd);                           /*!< USB OTG HCD Connect callback            */
  void (* DisconnectCallback)(struct __HCD_HandleTypeDef *hhcd);                        /*!< USB OTG HCD Disconnect callback         */
  void (* PortEnabledCallback)(struct __HCD_HandleTypeDef *hhcd);                       /*!< USB OTG HCD Port Enable callback        */
  void (* PortDisabledCallback)(struct __HCD_HandleTypeDef *hhcd);                      /*!< USB OTG HCD Port Disable callback       */
  void (* HC_NotifyURBChangeCallback)(struct __HCD_HandleTypeDef *hhcd, uint8_t chnum,
                                      HCD_URBStateTypeDef urb_state);                   /*!< USB OTG HCD Host Channel Notify URB Change callback  */
  void (* ResumeCallback)(struct __HCD_HandleTypeDef *hhcd);                            /*!< USB OTG hCD Resume callback             */
  void (* SessionRequestCallback)(struct __HCD_HandleTypeDef *hhcd);                    /*!< USB OTG HCD Session Request callback    */
  void (* VbusErrorCallback)(struct __HCD_HandleTypeDef *hhcd);                         /*!< USB OTG HCD VBUS Error callback         */
  void (* BabbleCallback)(struct __HCD_HandleTypeDef *hhcd);                            /*!< USB OTG HCD Babble callback             */

  void (* MspInitCallback)(struct __HCD_HandleTypeDef *hhcd);                           /*!< USB OTG HCD Msp Init callback           */
  void (* MspDeInitCallback)(struct __HCD_HandleTypeDef *hhcd);                         /*!< USB OTG HCD Msp DeInit callback         */
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
} HCD_HandleTypeDef;
/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup HCD_Exported_Constants HCD Exported Constants
  * @{
  */

/** @defgroup HCD_Speed HCD Speed
  * @{
  */
#define HCD_SPEED_HIGH               DDL_USB_HS_SPEED
#define HCD_SPEED_FULL               DDL_USB_FS_SPEED
#define HCD_SPEED_LOW                DDL_USB_LS_SPEED
/**
  * @}
  */

/** @defgroup HCD_Device_Speed HCD Device Speed
  * @{
  */
#define HCD_DEVICE_SPEED_HIGH               DDL_USB_HS_SPEED
#define HCD_DEVICE_SPEED_FULL               DDL_USB_FS_SPEED
#define HCD_DEVICE_SPEED_LOW                DDL_USB_LS_SPEED
/**
  * @}
  */

/** @defgroup HCD_PHY_Module HCD PHY Module
  * @{
  */
#define HCD_PHY_ULPI                 1U
#define HCD_PHY_EMBEDDED             2U
/**
  * @}
  */

/** @defgroup HCD_Error_Code_definition HCD Error Code definition
  * @brief  HCD Error Code definition
  * @{
  */
#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
#define  DAL_HCD_ERROR_INVALID_CALLBACK                        (0x00000010U)    /*!< Invalid Callback error  */
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup HCD_Exported_Macros HCD Exported Macros
  *  @brief macros to handle interrupts and specific clock configurations
  * @{
  */

#define __DAL_HCD_IS_INVALID_INTERRUPT(__HANDLE__)         (DDL_USB_ReadInterrupts((__HANDLE__)->Instance) == 0U)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup HCD_Exported_Functions HCD Exported Functions
  * @{
  */

/** @defgroup HCD_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
DAL_StatusTypeDef DAL_HCD_Init(HCD_HandleTypeDef *hhcd);
DAL_StatusTypeDef DAL_HCD_DeInit(HCD_HandleTypeDef *hhcd);
DAL_StatusTypeDef DAL_HCD_HC_Init(HCD_HandleTypeDef *hhcd, uint8_t ch_num,
                                  uint8_t epnum, uint8_t dev_address,
                                  uint8_t speed, uint8_t ep_type, uint16_t mps, uint8_t interval);

DAL_StatusTypeDef DAL_HCD_HC_Halt(HCD_HandleTypeDef *hhcd, uint8_t ch_num);
void              DAL_HCD_MspInit(HCD_HandleTypeDef *hhcd);
void              DAL_HCD_MspDeInit(HCD_HandleTypeDef *hhcd);

#if (USE_DAL_HCD_REGISTER_CALLBACKS == 1U)
/** @defgroup DAL_HCD_Callback_ID_enumeration_definition DAL USB OTG HCD Callback ID enumeration definition
  * @brief  DAL USB OTG HCD Callback ID enumeration definition
  * @{
  */
typedef enum
{
  DAL_HCD_SOF_CB_ID            = 0x01,        /*!< USB HCD SOF callback ID           */
  DAL_HCD_CONNECT_CB_ID        = 0x02,        /*!< USB HCD Connect callback ID       */
  DAL_HCD_DISCONNECT_CB_ID     = 0x03,        /*!< USB HCD Disconnect callback ID    */

  DAL_HCD_MSPINIT_CB_ID        = 0x06,        /*!< USB HCD MspInit callback ID       */
  DAL_HCD_MSPDEINIT_CB_ID      = 0x07,        /*!< USB HCD MspDeInit callback ID     */
  DAL_HCD_RESUME_CB_ID         = 0x08,        /*!< USB HCD Resume callback ID        */
  DAL_HCD_SESSION_REQUEST_CB_ID = 0x09,       /*!< USB HCD Session Request callback ID */
  DAL_HCD_VBUS_ERROR_CB_ID    = 0x0A,         /*!< USB HCD VBUS Error callback ID    */
  DAL_HCD_BABBLE_CB_ID         = 0x0B,        /*!< USB HCD Babble callback ID        */

} DAL_HCD_CallbackIDTypeDef;
/**
  * @}
  */

/** @defgroup DAL_HCD_Callback_pointer_definition DAL USB OTG HCD Callback pointer definition
  * @brief  DAL USB OTG HCD Callback pointer definition
  * @{
  */

typedef void (*pHCD_CallbackTypeDef)(HCD_HandleTypeDef *hhcd);                   /*!< pointer to a common USB OTG HCD callback function  */
typedef void (*pHCD_HC_NotifyURBChangeCallbackTypeDef)(HCD_HandleTypeDef *hhcd,
                                                       uint8_t epnum,
                                                       HCD_URBStateTypeDef urb_state);   /*!< pointer to USB OTG HCD host channel  callback */
/**
  * @}
  */

DAL_StatusTypeDef DAL_HCD_RegisterCallback(HCD_HandleTypeDef *hhcd,
                                           DAL_HCD_CallbackIDTypeDef CallbackID,
                                           pHCD_CallbackTypeDef pCallback);

DAL_StatusTypeDef DAL_HCD_UnRegisterCallback(HCD_HandleTypeDef *hhcd,
                                             DAL_HCD_CallbackIDTypeDef CallbackID);

DAL_StatusTypeDef DAL_HCD_RegisterHC_NotifyURBChangeCallback(HCD_HandleTypeDef *hhcd,
                                                             pHCD_HC_NotifyURBChangeCallbackTypeDef pCallback);

DAL_StatusTypeDef DAL_HCD_UnRegisterHC_NotifyURBChangeCallback(HCD_HandleTypeDef *hhcd);
#endif /* USE_DAL_HCD_REGISTER_CALLBACKS */
/**
  * @}
  */

/* I/O operation functions  ***************************************************/
/** @addtogroup HCD_Exported_Functions_Group2 Input and Output operation functions
  * @{
  */
DAL_StatusTypeDef DAL_HCD_HC_SubmitRequest(HCD_HandleTypeDef *hhcd, uint8_t ch_num,
                                           uint8_t direction, uint8_t ep_type,
                                           uint8_t token, uint8_t *pbuff,
                                           uint16_t length, uint8_t do_ping);

/* Non-Blocking mode: Interrupt */
void DAL_HCD_IRQHandler(HCD_HandleTypeDef *hhcd);
void DAL_HCD_WKUP_IRQHandler(HCD_HandleTypeDef *hhcd);
void DAL_HCD_SOF_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_Connect_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_Disconnect_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_HC_NotifyURBChange_Callback(HCD_HandleTypeDef *hhcd, uint8_t chnum,
                                         HCD_URBStateTypeDef urb_state);
void DAL_HCD_Resume_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_SessionRequest_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_VbusError_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_Babble_Callback(HCD_HandleTypeDef *hhcd);
void DAL_HCD_Delay_Callback(HCD_HandleTypeDef *hhcd, uint32_t Delay);
/**
  * @}
  */

/* Peripheral Control functions  **********************************************/
/** @addtogroup HCD_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */
DAL_StatusTypeDef DAL_HCD_ResetPort(HCD_HandleTypeDef *hhcd);
DAL_StatusTypeDef DAL_HCD_Start(HCD_HandleTypeDef *hhcd);
DAL_StatusTypeDef DAL_HCD_Stop(HCD_HandleTypeDef *hhcd);
/**
  * @}
  */

/* Peripheral State functions  ************************************************/
/** @addtogroup HCD_Exported_Functions_Group4 Peripheral State functions
  * @{
  */
HCD_StateTypeDef        DAL_HCD_GetState(HCD_HandleTypeDef *hhcd);
HCD_URBStateTypeDef     DAL_HCD_HC_GetURBState(HCD_HandleTypeDef *hhcd, uint8_t chnum);
HCD_HCStateTypeDef      DAL_HCD_HC_GetState(HCD_HandleTypeDef *hhcd, uint8_t chnum);
uint32_t                DAL_HCD_HC_GetXferCount(HCD_HandleTypeDef *hhcd, uint8_t chnum);
uint32_t                DAL_HCD_GetCurrentFrame(HCD_HandleTypeDef *hhcd);
uint32_t                DAL_HCD_GetCurrentSpeed(HCD_HandleTypeDef *hhcd);
DAL_StatusTypeDef       DAL_HCD_SetTestMode(HCD_HandleTypeDef *hhcd, uint8_t testmode);
DAL_StatusTypeDef       DAL_HCD_SetFiFo(HCD_HandleTypeDef *hhcd, uint8_t ch_num, uint16_t size);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup HCD_Private_Macros HCD Private Macros
  * @{
  */
/**
  * @}
  */
/* Private functions prototypes ----------------------------------------------*/

/**
  * @}
  */
/**
  * @}
  */
#endif /* defined (USB_OTG_HS) */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DAL_HCD_H */
