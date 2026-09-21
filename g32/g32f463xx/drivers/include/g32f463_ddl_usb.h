/**
  *
  * @file    g32f463_ddl_usb.h
  * @brief   Header file of USB Low Layer DDL module.
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
#ifndef G32F463_DDL_USB_H
#define G32F463_DDL_USB_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (USB_OTG_HS)

/** @addtogroup USB_DDL
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  URB States definition
  */
typedef enum
{
  URB_IDLE = 0,
  URB_DONE,
  URB_NOTREADY,
  URB_NYET,
  URB_ERROR,
  URB_STALL
} USB_OTG_URBStateTypeDef;

/**
  * @brief  Host channel States  definition
  */
typedef enum
{
  HC_IDLE = 0,
  HC_XFRC,
  HC_HALTED,
  HC_NAKTIMEOUT,
  HC_NYET,
  HC_STALL,
  HC_XACTERR,
  HC_BBLERR,
  HC_DATATGLERR
} USB_OTG_HCStateTypeDef;

/**
 * @brief   USB endpoint type
 */
typedef enum
{
  EP_TYPE_CONTROL,
  EP_TYPE_ISO,
  EP_TYPE_BULK,
  EP_TYPE_INTERRUPT
} USB_EP_TYPE_T;

/**
 * @brief   USB endpoint direction
 */
typedef enum
{
  EP_DIR_OUT,
  EP_DIR_IN
} USB_EP_DIR_T;

/**
 * @brief   USB device endpoint id
 */
typedef enum
{
  USBD_EP_0,
  USBD_EP_1,
  USBD_EP_2,
  USBD_EP_3,
  USBD_EP_4,
  USBD_EP_5,
  USBD_EP_6,
  USBD_EP_7,
  USBD_EP_8,
} USBD_EP_ID_T;

/**
 * @brief USB host PID type of data
 */
typedef enum
{
    USBH_PID_SETUP,
    USBH_PID_DATA,
} USBH_PID_T;

/**
 * @brief   USB URB status
 */
typedef enum
{
    USB_URB_IDLE,
    USB_URB_NOREADY,
    USB_URB_STALL,
    USB_URB_ERROR,
    USB_URB_NYET,
    USB_URB_OK,
} USB_OTG_URB_STA_T;

/** @defgroup USB_DDL_ES_INIT USB Exported Init structure
  * @{
  */

/**
  * @brief  USB Instance Initialization Structure definition
  */
typedef struct
{
  uint32_t dev_endpoints;             /*!< Device Endpoints number.
                                         This parameter depends on the used USB core.
                                         This parameter must be a number between Min_Data = 1 and Max_Data = 9 */

  uint32_t host_channels;             /*!< Host Channels number.
                                         This parameter Depends on the used USB core.
                                         This parameter must be a number between Min_Data = 1 and Max_Data = 9 */

  uint32_t dma_channels;              /*!< DMA Channels number.
                                         This parameter Depends on the used USB core.
                                         This parameter must be a number between Min_Data = 1 and Max_Data = 8 */

  uint32_t speed;                     /*!< USB Core speed.
                                         This parameter can be any value of @ref USB_DDL_EC_USB_SPEED */

  uint32_t dma_enable;                /*!< Enable or disable of the USB embedded DMA */

  uint32_t sof_enable;                /*!< Enable or disable the output of the SOF signal.                        */

  uint32_t low_power_enable;          /*!< Enable or disable the low power mode.                                  */

  uint32_t vbus_sensing_enable;       /*!< Enable or disable the VBUS Sensing feature.                            */

} DDL_USB_OTG_InitTypeDef;

typedef struct
{
  uint8_t   num;                  /*!< Endpoint number
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 9   */

  uint8_t   is_in;                /*!< Endpoint direction
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

  uint8_t   is_stall;             /*!< Endpoint stall condition
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

  uint8_t   is_iso_incomplete;    /*!< Endpoint isoc condition
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

  uint8_t   type;                 /*!< Endpoint type
                                       This parameter can be any value of @ref USB_DDL_EP_Type                   */

  // uint8_t   data_pid_start;       /*!< Initial data PID
  //                                      This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

  // uint8_t   even_odd_frame;       /*!< IFrame parity
  //                                      This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

  // uint16_t  tx_fifo_num;          /*!< Transmission FIFO number
  //                                      This parameter must be a number between Min_Data = 1 and Max_Data = 15   */

  uint32_t  maxpacket;            /*!< Endpoint Max packet size
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 64KB */

  uint8_t   *xfer_buff;           /*!< Pointer to transfer buffer                                               */

  uint32_t  xfer_len;             /*!< Current transfer length                                                  */

  uint32_t  xfer_size;            /*!< requested transfer size                                                  */

  uint32_t  xfer_count;           /*!< Partial transfer length in case of multi packet transfer                 */
} DDL_USB_OTG_EPTypeDef;

typedef struct
{
  uint8_t   dev_addr;           /*!< USB device address.
                                     This parameter must be a number between Min_Data = 1 and Max_Data = 255    */

  uint8_t   ch_num;             /*!< Host channel number.
                                     This parameter must be a number between Min_Data = 1 and Max_Data = 15     */

  uint8_t   ep_num;             /*!< Endpoint number.
                                     This parameter must be a number between Min_Data = 1 and Max_Data = 15     */

  uint8_t   ep_is_in;           /*!< Endpoint direction
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

  uint8_t   speed;              /*!< USB Host Channel speed.
                                     This parameter can be any value of @ref HCD_Device_Speed:
                                                                             (HCD_DEVICE_SPEED_xxx)             */

  uint8_t   interval;           /*!< Polling interval for the channel (in 1ms or 125us units).
                                     This parameter must be a number between Min_Data = 1 and Max_Data = 255     */

  uint8_t   do_ping;            /*!< Enable or disable the use of the PING protocol for HS mode.                */

  uint8_t   process_ping;       /*!< Execute the PING protocol for HS mode.                                     */

  uint8_t   ep_type;            /*!< Endpoint Type.
                                     This parameter can be any value of @ref USB_DDL_EP_Type                     */

  uint16_t  max_packet;         /*!< Endpoint Max packet size.
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 64KB   */

  uint8_t   data_pid;           /*!< Initial data PID.
                                     This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

  uint8_t   *xfer_buff;         /*!< Pointer to transfer buffer.                                                */

  uint32_t  XferSize;             /*!< OTG Channel transfer size.                                               */

  uint32_t  xfer_len;           /*!< Current transfer length.                                                   */

  uint32_t  xfer_count;         /*!< Partial transfer length in case of multi packet transfer.                  */

  // uint8_t   toggle_in;          /*!< IN transfer current toggle flag.
  //                                    This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

  // uint8_t   toggle_out;         /*!< OUT transfer current toggle flag
  //                                    This parameter must be a number between Min_Data = 0 and Max_Data = 1      */

  uint32_t  dma_addr;           /*!< 32 bits aligned transfer buffer address.                                   */

  uint32_t  ErrCnt;             /*!< Host channel error count.                                                  */

  USB_OTG_URBStateTypeDef urb_state;  /*!< URB state.
                                            This parameter can be any value of @ref USB_OTG_URBStateTypeDef */

  USB_OTG_HCStateTypeDef state;       /*!< Host Channel state.
                                            This parameter can be any value of @ref USB_OTG_HCStateTypeDef  */
} DDL_USB_OTG_HCTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup USB_DDL_Exported_Constants PCD Exported Constants
  * @{
  */

/** @defgroup USB_DDL_EC_USB_SPEED USB Speed
  * @{
  */
#define DDL_USB_LS_SPEED            0x00000000UL                /*!< Low speed mode */
#define DDL_USB_FS_SPEED            0x00000001UL                /*!< Full speed mode */
#define DDL_USB_HS_SPEED            0x00000002UL                /*!< High speed mode */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_EP0_MPS Endpoint 0 Max Packet Size
  * @{
  */
#define DDL_USB_EP0_MPS             64U                         /*!< Control EP max packet size */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_EP_IT Endpoint Interrupts Index
  * @{
  */
#define DDL_USB_IT_EP_0             (1UL << 0)
#define DDL_USB_IT_EP_1             (1UL << 1)
#define DDL_USB_IT_EP_2             (1UL << 2)
#define DDL_USB_IT_EP_3             (1UL << 3)
#define DDL_USB_IT_EP_4             (1UL << 4)
#define DDL_USB_IT_EP_5             (1UL << 5)
#define DDL_USB_IT_EP_6             (1UL << 6)
#define DDL_USB_IT_EP_7             (1UL << 7)
#define DDL_USB_IT_EP_8             (1UL << 8)
#define DDL_USB_IT_EP_ALL           (0x000001FFUL)          /*!< All endpoints interrupts */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_EP_DIR Endpoint Direction
  * @{
  */
#define DDL_USB_EP_DIR_HOST_IN       0x00000000UL    /*!< Host IN Endpoint */
#define DDL_USB_EP_DIR_HOST_OUT      0x00000001UL    /*!< Host OUT Endpoint */
#define DDL_USB_EP_DIR_DEVICE_IN     0x00000001UL    /*!< Device IN Endpoint */
#define DDL_USB_EP_DIR_DEVICE_OUT    0x00000000UL    /*!< Device OUT Endpoint */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_TESTMODE Test Mode
  * @{
  */
#define DDL_USB_TEST_SE0_NAK        OTG_HS_TESTMODE_B_TEST_SE0_NAK
#define DDL_USB_TEST_J              OTG_HS_TESTMODE_B_TEST_J
#define DDL_USB_TEST_K              OTG_HS_TESTMODE_B_TEST_K
#define DDL_USB_TEST_PACKET         OTG_HS_TESTMODE_B_TEST_PACKET
/**
  * @}
  */

/** @defgroup USB_DDL_EC_DMA_REQ_MODE DMA Request Mode
  * @{
  */
#define DDL_USB_DMA_REQ_MODE_0       0x00000000UL                 /*!< DMA request mode 0 */
#define DDL_USB_DMA_REQ_MODE_1       0x00000001UL                 /*!< DMA request mode 1 */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_VBUS_LEVEL VBUS Level
  * @{
  */
#define DDL_USB_VBUS_NONE             0x00000000UL    /*!< Below session-end level */
#define DDL_USB_VBUS_SESSION          0x00000001UL    /*!< Above session-end, below avalid level */
#define DDL_USB_VBUS_AVALID           0x00000002UL    /*!< Above avalid, below vbus-valid level */
#define DDL_USB_VBUS_VALID            0x00000003UL    /*!< Above vbus-valid level */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_ROLE USB Role
  * @{
  */
#define DDL_USB_ROLE_A_SIDE           0x00000000UL    /*!< A-device */
#define DDL_USB_ROLE_B_SIDE           0x00000001UL    /*!< B-device */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_FIFO_SIZE FIFO Size
  * @{
  */
#define DDL_USB_FIFO_SIZE_8           0x00000000UL                                                                                    /*!< FIFO size 8 bytes */
#define DDL_USB_FIFO_SIZE_16          (OTG_HS_TXFIFOSZ_SIZE_0)                                                                   /*!< FIFO size 16 bytes */
#define DDL_USB_FIFO_SIZE_32          (OTG_HS_TXFIFOSZ_SIZE_1)                                                                   /*!< FIFO size 32 bytes */
#define DDL_USB_FIFO_SIZE_64          (OTG_HS_TXFIFOSZ_SIZE_1 | OTG_HS_TXFIFOSZ_SIZE_0)                                     /*!< FIFO size 64 bytes */
#define DDL_USB_FIFO_SIZE_128         (OTG_HS_TXFIFOSZ_SIZE_2)                                                                   /*!< FIFO size 128 bytes */
#define DDL_USB_FIFO_SIZE_256         (OTG_HS_TXFIFOSZ_SIZE_2 | OTG_HS_TXFIFOSZ_SIZE_0)                                     /*!< FIFO size 256 bytes */
#define DDL_USB_FIFO_SIZE_512         (OTG_HS_TXFIFOSZ_SIZE_2 | OTG_HS_TXFIFOSZ_SIZE_1)                                     /*!< FIFO size 512 bytes */
#define DDL_USB_FIFO_SIZE_1024        (OTG_HS_TXFIFOSZ_SIZE_2 | OTG_HS_TXFIFOSZ_SIZE_1 | OTG_HS_TXFIFOSZ_SIZE_0)       /*!< FIFO size 1024 bytes */
#define DDL_USB_FIFO_SIZE_2048        (OTG_HS_TXFIFOSZ_SIZE_3)                                                                   /*!< FIFO size 2048 bytes */
#define DDL_USB_FIFO_SIZE_4096        (OTG_HS_TXFIFOSZ_SIZE_3 | OTG_HS_TXFIFOSZ_SIZE_0)                                     /*!< FIFO size 4096 bytes */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_DMA_CHANNEL DMA Channel
  * @{
  */
#define DDL_USB_DMA_CHANNEL_0         0x00000000UL    /*!< DMA Channel 0 */
#define DDL_USB_DMA_CHANNEL_1         0x00000001UL    /*!< DMA Channel 1 */
#define DDL_USB_DMA_CHANNEL_2         0x00000002UL    /*!< DMA Channel 2 */
#define DDL_USB_DMA_CHANNEL_3         0x00000003UL    /*!< DMA Channel 3 */
#define DDL_USB_DMA_CHANNEL_4         0x00000004UL    /*!< DMA Channel 4 */
#define DDL_USB_DMA_CHANNEL_5         0x00000005UL    /*!< DMA Channel 5 */
#define DDL_USB_DMA_CHANNEL_6         0x00000006UL    /*!< DMA Channel 6 */
#define DDL_USB_DMA_CHANNEL_7         0x00000007UL    /*!< DMA Channel 7 */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_DMA_MODE DMA Mode
  * @{
  */
#define DDL_USB_DMA_MODE_0            0x00000000UL                    /*!< DMA mode 0 */
#define DDL_USB_DMA_MODE_1            0x00000001UL                    /*!< DMA mode 1 */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_DMA_DIR DMA Direction
  * @{
  */
#define DDL_USB_DMA_DIR_WRITE         0x00000000UL                   /*!< DMA write direction */
#define DDL_USB_DMA_DIR_READ          OTG_HS_DMA_CNTL_CNTRL_DIR  /*!< DMA read direction */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_DMA_BURST DMA Burst
  * @{
  */
#define DDL_USB_DMA_BURST_ANY         0x00000000UL                                                            /*!< DMA burst of unspecified length */
#define DDL_USB_DMA_BURST_INCR4       OTG_HS_DMA_CNTL_CNTRL_BURST_0                                       /*!< DMA burst INCR4 or unspecified length */
#define DDL_USB_DMA_BURST_INCR8       OTG_HS_DMA_CNTL_CNTRL_BURST_1                                       /*!< DMA burst INCR8, INCR4 or unspecified length */
#define DDL_USB_DMA_BURST_INCR16      (OTG_HS_DMA_CNTL_CNTRL_BURST_1 | OTG_HS_DMA_CNTL_CNTRL_BURST_0) /*!< DMA burst INCR16, INCR8, INCR4 or unspecified length */

/**
  * @}
  */

/** @defgroup USB_DDL_EC_INTR USB Interrupts
  * @{
  */
#define DDL_USB_IT_SUSPEND            OTG_HS_INTRUSB_INT_SUSPEND       /*!< USB Suspend Interrupt */
#define DDL_USB_IT_RESUME             OTG_HS_INTRUSB_INT_RESUME        /*!< USB Resume Interrupt */
#define DDL_USB_IT_RESET              OTG_HS_INTRUSB_INT_RESET         /*!< USB Reset Interrupt */
#define DDL_USB_IT_BABBLE             OTG_HS_INTRUSB_INT_BABBLE        /*!< USB Babble Interrupt */
#define DDL_USB_IT_SOF                OTG_HS_INTRUSB_INT_SOF           /*!< USB Start of Frame Interrupt */
#define DDL_USB_IT_CONNECT            OTG_HS_INTRUSB_INT_CONN          /*!< USB Connect Interrupt */
#define DDL_USB_IT_DISCONNECT         OTG_HS_INTRUSB_INT_DISCON        /*!< USB Disconnect Interrupt */
#define DDL_USB_IT_SESSION            OTG_HS_INTRUSB_INT_SESS_REQ      /*!< USB Session Request Interrupt */
#define DDL_USB_IT_VBUS_ERROR         OTG_HS_INTRUSB_INT_VBUS_ERROR    /*!< USB VBUS Error Interrupt */
/**
  * @}
  */

/** @defgroup USB_DDL_EC_TYPE USB Endpoint Type
  * @{
  */
#define DDL_USB_EP_TYPE_CTRL                  0x00000000UL                      /*!< Control Endpoint */
#define DDL_USB_EP_TYPE_ISOC                  (OTG_HS_TXTYPE_PROTOCOL_0)   /*!< Isochronous Endpoint */
#define DDL_USB_EP_TYPE_BULK                  (OTG_HS_TXTYPE_PROTOCOL_1)   /*!< Bulk Endpoint */
#define DDL_USB_EP_TYPE_INTR                  (OTG_HS_TXTYPE_PROTOCOL_1 | OTG_HS_TXTYPE_PROTOCOL_0) /*!< Interrupt Endpoint */
/**
  * @}
  */

#define EP_TYPE_CTRL                           0U
#define EP_TYPE_ISOC                           1U
#define EP_TYPE_BULK                           2U
#define EP_TYPE_INTR                           3U
#define EP_TYPE_MSK                            3U

#define TEST_J                                 1U
#define TEST_K                                 2U
#define TEST_SE0_NAK                           3U
#define TEST_PACKET                            4U
#define TEST_FORCE_EN                          5U

#define EP_ADDR_MSK                            0xFU

// #define HC_PID_DATA0                           0U
// #define HC_PID_DATA2                           1U
// #define HC_PID_DATA1                           2U
// #define HC_PID_SETUP                           3U
#define HC_PID_SETUP                         0xD0U
#define HC_PID_IN                            0x90U
#define HC_PID_OUT                           0x10U

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup USB_DDL_Exported_Macros USB Low Layer Exported Macros
  * @{
  */

#define USB_FIFO_BASE(__INSTANCE_BASE__, __EPNUM__)   ((__INSTANCE_BASE__) + USB_OTG_HS_FIFO_BASE + ((__EPNUM__) * USB_OTG_HS_FIFO_SIZE))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USB_DDL_Exported_Functions USB Low Layer Exported Functions
  * @{
  */

/** @defgroup USB_DDL_EF_Global USB Global functions
  * @{
  */

/**
  * @brief  Force USB PHY reset.
  * @param  USBx USB Instance
  * @retval None
*/
__STATIC_INLINE void DDL_USB_PHY_ForceReset(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->USBPHY_RESET, OTG_PHY_RESET_USB_PHY_RESET);
}

/**
  * @brief  Release USB PHY reset.
  * @param  USBx USB Instance
  * @retval None
*/
__STATIC_INLINE void DDL_USB_PHY_ReleaseReset(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->USBPHY_RESET, OTG_PHY_RESET_USB_PHY_RESET);
}

/**
  * @brief  Enable USB PHY bypass.
  * @param  USBx USB Instance
  * @retval None
*/
__STATIC_INLINE void DDL_USB_PHY_EnableBypass(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->OTG_SUSPENDM, OTG_PHY_OTG_SUSPENDM_USBPHY_BYPASS_EN);
}

/**
  * @brief  Disable USB PHY bypass.
  * @param  USBx USB Instance
  * @retval None
*/
__STATIC_INLINE void DDL_USB_PHY_DisableBypass(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->OTG_SUSPENDM, OTG_PHY_OTG_SUSPENDM_USBPHY_BYPASS_EN);
}

/**
  * @brief  Enable USB PHY VBUS detection.
  * @param  USBx USB Instance
  * @retval None
*/
__STATIC_INLINE void DDL_USB_PHY_EnableVbusDetect(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->OTG_SUSPENDM, OTG_PHY_OTG_SUSPENDM_VBUS_CHG_SEL);
}

/**
  * @brief  Disable USB PHY VBUS detection.
  * @param  USBx USB Instance
  * @retval None
*/
__STATIC_INLINE void DDL_USB_PHY_DisableVbusDetect(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->OTG_SUSPENDM, OTG_PHY_OTG_SUSPENDM_VBUS_CHG_SEL);
}

/**
  * @brief  Enable USB PHY OTG function.
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_PHY_EnableOTGFunction(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->OTG_SUSPENDM, OTG_PHY_OTG_SUSPENDM_OTG_SUSPENDM);
}

/**
  * @brief  Disable USB PHY OTG function.
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_PHY_DisableOTGFunction(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->OTG_SUSPENDM, OTG_PHY_OTG_SUSPENDM_OTG_SUSPENDM);
}

/**
  * @brief  Set the address
  * @param  USBx USB Instance
  * @param  Address This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7F
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetAddress(USB_OTG_TypeDef *USBx, uint8_t Address)
{
  MODIFY_REG(USBx->FADDR, OTG_HS_FADDR_FUNADDR, Address & OTG_HS_FADDR_FUNADDR);
}

/**
  * @brief  Get the address
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0x7F
  */
__STATIC_INLINE uint8_t DDL_USB_GetAddress(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_REG(USBx->FADDR));
}

/**
  * @brief  Enable USB ISO transfer update
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EnableIsoUpdate(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_ISOUPDATE);
}

/**
  * @brief  Disable USB ISO transfer update
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_DisableIsoUpdate(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->POWER, OTG_HS_POWER_ISOUPDATE);
}

/**
  * @brief  Check if USB ISO transfer update is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIsoUpdate(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_ISOUPDATE) == (OTG_HS_POWER_ISOUPDATE)) ? 1UL : 0UL);
}

/**
  * @brief  Connects the USB controller to the USB bus
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_Connect(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_SOFTCONNECT);
}

/**
  * @brief  Disconnects the USB controller from the USB bus
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_Disconnect(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->POWER, OTG_HS_POWER_SOFTCONNECT);
}

/**
  * @brief  Enable USB high speed negotiation
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableHighSpeed(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_HSENABLE);
}

/**
  * @brief  Disable USB high speed negotiation
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableHighSpeed(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->POWER, OTG_HS_POWER_HSENABLE);
}

/**
  * @brief  Check if USB high speed negotiation is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledHighSpeed(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_HSENABLE) == (OTG_HS_POWER_HSENABLE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable USB bus reset
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EnableBusReset(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_USBRESET);
}

/**
  * @brief  Disable USB bus reset
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_DisableBusReset(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->POWER, OTG_HS_POWER_USBRESET);
}

/**
  * @brief  Check if USB bus reset is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledBusReset(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_USBRESET) == (OTG_HS_POWER_USBRESET)) ? 1UL : 0UL);
}

/**
  * @brief  Enable USB bus resume signaling
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableBusResume(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_RESUME);
}

/**
  * @brief  Disable USB bus resume signaling
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableBusResume(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->POWER, OTG_HS_POWER_RESUME);
}

/**
  * @brief  Check if USB bus resume signaling is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledBusResume(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_RESUME) == (OTG_HS_POWER_RESUME)) ? 1UL : 0UL);
}

/**
  * @brief  Enable USB bus suspend
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EnableBusSuspend(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_SUSPENDMODE);
}

/**
  * @brief  Enable USB suspend mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableSuspendMode(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->POWER, OTG_HS_POWER_SUSPENDMEN);
}

/**
  * @brief  Disable USB suspend mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableSuspendMode(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->POWER, OTG_HS_POWER_SUSPENDMEN);
}

/**
  * @brief  Check if USB suspend mode is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledSuspendMode(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_SUSPENDMEN) == (OTG_HS_POWER_SUSPENDMEN)) ? 1UL : 0UL);
}

/**
  * @brief  Get the USB VBUS level
  * @param  USBx USB Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USB_VBUS_NONE
  *         @arg @ref DDL_USB_VBUS_SESSION
  *         @arg @ref DDL_USB_VBUS_AVALID
  *         @arg @ref DDL_USB_VBUS_VALID
  */
__STATIC_INLINE uint32_t DDL_USB_GetVBUSLevel(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_VBUS) >> OTG_HS_DEVCTL_VBUS_Pos);
}

/**
  * @brief  Enable the USB host session negotiation request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EnableHostSessionRequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_HOST_REQ);
}

/**
  * @brief  Disable the USB host session negotiation request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_DisableHostSessionRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_HOST_REQ);
}

/**
  * @brief  Check if the USB host session negotiation request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledHostSessionRequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_HOST_REQ) == (OTG_HS_DEVCTL_HOST_REQ)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the USB OTG session request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableSessionRequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_SESSION);
}

/**
  * @brief  Disable the USB session request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableSessionRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_SESSION);
}

/**
  * @brief  Check if the USB session request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledSessionRequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_SESSION) == (OTG_HS_DEVCTL_SESSION)) ? 1UL : 0UL);
}

/**
  * @brief  Get the USB role
  * @param  USBx USB Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USB_ROLE_A_SIDE
  *         @arg @ref DDL_USB_ROLE_B_SIDE
  */
__STATIC_INLINE uint32_t DDL_USB_GetRole(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_BDEVICE) >> OTG_HS_DEVCTL_BDEVICE_Pos);
}

/**
  * @brief  Set the watting time for the user to connect the USB controller
  * @param  USBx USB Instance
  * @param  Time This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x0F
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetWaitConnectTime(USB_OTG_TypeDef *USBx, uint8_t Time)
{
  MODIFY_REG(USBx->LINKINFO, OTG_HS_LINKINFO_WTCON, Time << OTG_HS_LINKINFO_WTCON_Pos);
}

/**
  * @brief  Get the watting time for the user to connect the USB controller
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0x0F
  */
__STATIC_INLINE uint8_t DDL_USB_GetWaitConnectTime(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_BIT(USBx->LINKINFO, OTG_HS_LINKINFO_WTCON) >> OTG_HS_LINKINFO_WTCON_Pos);
}

/**
  * @brief  Set the IDPULLUP time for the USB ID detection
  * @param  USBx USB Instance
  * @param  Time This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x0F
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetIdDetectTime(USB_OTG_TypeDef *USBx, uint8_t Time)
{
  MODIFY_REG(USBx->LINKINFO, OTG_HS_LINKINFO_WTID, Time & OTG_HS_LINKINFO_WTID);
}

/**
  * @brief  Get the IDPULLUP time for the USB ID detection
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0x0F
  */
__STATIC_INLINE uint8_t DDL_USB_GetIdDetectTime(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_BIT(USBx->LINKINFO, OTG_HS_LINKINFO_WTID) >> OTG_HS_LINKINFO_WTID_Pos);
}

/**
  * @brief  Set the VBUS charging pulse width
  * @param  USBx USB Instance
  * @param  PulseWidth This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetVBUSChargingPulseWidth(USB_OTG_TypeDef *USBx, uint8_t PulseWidth)
{
  MODIFY_REG(USBx->VPLEN, OTG_HS_VPLEN_VPLEN, PulseWidth & OTG_HS_VPLEN_VPLEN);
}

/**
  * @brief  Get the VBUS charging pulse width
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFF
  */
__STATIC_INLINE uint8_t DDL_USB_GetVBUSChargingPulseWidth(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_BIT(USBx->VPLEN, OTG_HS_VPLEN_VPLEN) >> OTG_HS_VPLEN_VPLEN_Pos);
}

/**
  * @brief  Set the time between last transaction and EOF in high speed transfer
  * @param  USBx USB Instance
  * @param  Time This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetHighSpeedEOFTime(USB_OTG_TypeDef *USBx, uint8_t Time)
{
  MODIFY_REG(USBx->HS_EOF1, OTG_HS_EOF1_HS_EOF1, Time & OTG_HS_EOF1_HS_EOF1);
}

/**
  * @brief  Get the time between last transaction and EOF in high speed transfer
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFF
  */
__STATIC_INLINE uint8_t DDL_USB_GetHighSpeedEOFTime(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_BIT(USBx->HS_EOF1, OTG_HS_EOF1_HS_EOF1) >> OTG_HS_EOF1_HS_EOF1_Pos);
}

/**
  * @brief  Set the time between last transaction and EOF in full speed transfer
  * @param  USBx USB Instance
  * @param  Time This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetFullSpeedEOFTime(USB_OTG_TypeDef *USBx, uint8_t Time)
{
  MODIFY_REG(USBx->FS_EOF1, OTG_FS_EOF1_FS_EOF1, Time & OTG_FS_EOF1_FS_EOF1);
}

/**
  * @brief  Get the time between last transaction and EOF in full speed transfer
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFF
  */
__STATIC_INLINE uint8_t DDL_USB_GetFullSpeedEOFTime(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_BIT(USBx->FS_EOF1, OTG_FS_EOF1_FS_EOF1) >> OTG_FS_EOF1_FS_EOF1_Pos);
}

/**
 * @brief  Set the time between last transaction and EOF in low speed transfer
 * @param  USBx USB Instance
 * @param  Time This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
 * @retval None
 */
__STATIC_INLINE void DDL_USB_SetLowSpeedEOFTime(USB_OTG_TypeDef *USBx, uint8_t Time)
{
  MODIFY_REG(USBx->LS_EOF1, OTG_LS_EOF1_LS_EOF1, Time & OTG_LS_EOF1_LS_EOF1);
}

/**
  * @brief  Get the time between last transaction and EOF in low speed transfer
  * @param  USBx USB Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFF
  */
__STATIC_INLINE uint8_t DDL_USB_GetLowSpeedEOFTime(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_BIT(USBx->LS_EOF1, OTG_LS_EOF1_LS_EOF1) >> OTG_LS_EOF1_LS_EOF1_Pos);
}

/**
 * @brief  Set the number of packets to request when transferring multiple bulk packets
 * @param  USBx USB Instance
 * @param  EpNum This parameter can be a number between Min_Data = 0x01 and Max_Data = 0x08
 * @param  Count The number of packets to request when transferring multiple bulk packets
 * @retval None
 */
__STATIC_INLINE void DDL_USB_SetMultiBulkPacketCount(USB_OTG_TypeDef *USBx, uint8_t EpNum, uint16_t Count)
{
  MODIFY_REG(USBx->RQPKT_COUNT[(EpNum - 1U)], OTG_HS_RQPKTCOUNT_RQPKTCOUNT, Count);
}

/**
 * @brief  Get the number of packets to request when transferring multiple bulk packets
 * @param  USBx USB Instance
 * @param  EpNum This parameter can be a number between Min_Data = 0x01 and Max_Data = 0x08
 * @retval Count The number of packets to request when transferring multiple bulk packets
 */
__STATIC_INLINE uint16_t DDL_USB_GetMultiBulkPacketCount(USB_OTG_TypeDef *USBx, uint8_t EpNum)
{
  return (uint16_t)(READ_BIT(USBx->RQPKT_COUNT[(EpNum - 1U)], OTG_HS_RQPKTCOUNT_RQPKTCOUNT));
}

/**
  * @brief  Set the active endpoint
  * @param  USBx USB Instance
  * @param  EpNum This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x08
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetEpIndex(USB_OTG_TypeDef *USBx, uint8_t EpNum)
{
  MODIFY_REG(USBx->INDEX, OTG_HS_INDEX_INDEX, EpNum & OTG_HS_INDEX_INDEX);
}

/**
  * @brief  Get current active endpoint
  * @param  USBx USB Instance
  * @retval The current active endpoint number
  */
__STATIC_INLINE uint8_t DDL_USB_GetEpIndex(USB_OTG_TypeDef *USBx)
{
  return (uint8_t)(READ_REG(USBx->INDEX));
}

/**
  * @brief  Enable force host mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableForceHostMode(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_HOST);
}

/**
  * @brief  Disable force host mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableForceHostMode(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_HOST);
}

/**
  * @brief  Check if force host mode is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledForceHostMode(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_HOST) == (OTG_HS_TESTMODE_B_FORCE_HOST)) ? 1UL : 0UL);
}

/**
  * @brief  Enable FIFO access
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableFifoAccess(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FIFO_ACCESS);
}

/**
  * @brief  Enable force full speed mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableForceFSMode(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_FS);
}

/**
  * @brief  Disable force full speed mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableForceFSMode(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_FS);
}

/**
  * @brief  Check if force full speed mode is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledForceFSMode(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_FS) == (OTG_HS_TESTMODE_B_FORCE_FS)) ? 1UL : 0UL);
}

/**
  * @brief  Enable force high speed mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableForceHSMode(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_HS);
}

/**
  * @brief  Disable force high speed mode
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableForceHSMode(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_HS);
}

/**
  * @brief  Check if force high speed mode is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledForceHSMode(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TESTMODE, OTG_HS_TESTMODE_B_FORCE_HS) == (OTG_HS_TESTMODE_B_FORCE_HS)) ? 1UL : 0UL);
}

/**
  * @brief  Set the test mode
  * @param  USBx USB Instance
  * @param  TestMode This parameter can be one of the following values:
  *         @arg @ref DDL_USB_TEST_SE0_NAK
  *         @arg @ref DDL_USB_TEST_J
  *         @arg @ref DDL_USB_TEST_K
  *         @arg @ref DDL_USB_TEST_PACKET
  * @retval None
  */
__STATIC_INLINE void DDL_USB_SetTestMode(USB_OTG_TypeDef *USBx, uint32_t TestMode)
{
  MODIFY_REG(USBx->TESTMODE, OTG_HS_TESTMODE_B_TESTMODE, TestMode & OTG_HS_TESTMODE_B_TESTMODE);
}

/**
  * @brief  Get the current test mode
  * @param  USBx USB Instance
  * @retval The current test mode
  */
__STATIC_INLINE uint32_t DDL_USB_GetTestMode(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->TESTMODE) & OTG_HS_TESTMODE_B_TESTMODE);
}

/**
  * @brief  Get the current frame number
  * @param  USBx USB Instance
  * @retval The last received frame number
  */
__STATIC_INLINE uint32_t DDL_USB_GetCurrentFrame(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->FRAMENUM));
}

/**
  * @brief  Return the USB endpoints TX interrupt status
  * @param  USBx USB Instance
  * @retval Returned value is the status of the USB endpoints TX interrupt
  */
__STATIC_INLINE uint16_t DDL_USB_ReadAllEpTxInterrupt(USB_OTG_TypeDef *USBx)
{
  return (uint16_t)(READ_REG(USBx->INTRTX));
}

/**
  * @brief  Return the USB endpoints RX interrupt status
  * @param  USBx USB Instance
  * @retval Returned value is the status of the USB endpoints RX interrupt
  */
__STATIC_INLINE uint16_t DDL_USB_ReadAllEpRxInterrupt(USB_OTG_TypeDef *USBx)
{
  return (uint16_t)(READ_REG(USBx->INTRRX));
}

/**
  * @brief  Return the USB endpoint TX interrupt status
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a combination of the following values:
  *         @arg @ref DDL_USB_IT_EP_0
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval Returned value is the status of the USB endpoint TX interrupt
  */
__STATIC_INLINE uint16_t DDL_USB_ReadEpTxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  return (uint16_t)(READ_BIT(USBx->INTRTX, EpNum));
}

/**
  * @brief  Return the USB endpoint RX interrupt status
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a combination of the following values:
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval Returned value is the status of the USB endpoint RX interrupt
  */
__STATIC_INLINE uint16_t DDL_USB_ReadEpRxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  return (uint16_t)(READ_BIT(USBx->INTRRX, EpNum));
}

/**
  * @brief  Enable the USB endpoint TX interrupt
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a combination of the following values:
  *         @arg @ref DDL_USB_IT_EP_0
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableEpTxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  SET_BIT(USBx->INTRTXE, EpNum);
}

/**
  * @brief  Disable the USB endpoint TX interrupt
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a combination of the following values:
  *         @arg @ref DDL_USB_IT_EP_0
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableEpTxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  CLEAR_BIT(USBx->INTRTXE, EpNum);
}

/**
  * @brief  Return the USB endpoint TX interrupt status
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be one of the following values:
  *         @arg @ref DDL_USB_IT_EP_0
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledEpTxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  return ((READ_BIT(USBx->INTRTXE, EpNum) == (EpNum)) ? 1UL : 0UL);
}

/**
 *  @brief  Enable the USB endpoint RX interrupt
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a combination of the following values:
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableEpRxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  SET_BIT(USBx->INTRRXE, EpNum);
}

/**
  * @brief  Disable the USB endpoint RX interrupt
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a combination of the following values:
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableEpRxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  CLEAR_BIT(USBx->INTRRXE, EpNum);
}

/**
  * @brief  Return the USB endpoint RX interrupt status
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be one of the following values:
  *         @arg @ref DDL_USB_IT_EP_1
  *         @arg @ref DDL_USB_IT_EP_2
  *         @arg @ref DDL_USB_IT_EP_3
  *         @arg @ref DDL_USB_IT_EP_4
  *         @arg @ref DDL_USB_IT_EP_5
  *         @arg @ref DDL_USB_IT_EP_6
  *         @arg @ref DDL_USB_IT_EP_7
  *         @arg @ref DDL_USB_IT_EP_8
  *         @arg @ref DDL_USB_IT_EP_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledEpRxInterrupt(USB_OTG_TypeDef *USBx, uint16_t EpNum)
{
  return ((READ_BIT(USBx->INTRRXE, EpNum) == (EpNum)) ? 1UL : 0UL);
}

/**
  * @brief  Return the global USB interrupt status
  * @param  USBx USB Instance
  * @retval Returned value is the status of the USB global interrupt
  */
__STATIC_INLINE uint32_t DDL_USB_ReadInterrupts(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->INTRUSB));
}

/**
  * @brief  Enable SUSPEND interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_SUSPEND(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SUSPENDE);
}

/**
  * @brief  Disable SUSPEND interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_SUSPEND(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SUSPENDE);
}

/**
  * @brief  Check if SUSPEND interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_SUSPEND(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SUSPENDE) == (OTG_HS_INTRUSBE_INT_SUSPENDE) ? 1UL : 0UL);
}

/**
  * @brief  Enable RESUME interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_RESUME(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_RESUMEE);
}

/**
  * @brief  Disable RESUME interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_RESUME(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_RESUMEE);
}

/**
  * @brief  Check if RESUME interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_RESUME(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_RESUMEE) == (OTG_HS_INTRUSBE_INT_RESUMEE) ? 1UL : 0UL);
}

/**
  * @brief  Enable RESET or BABBLE interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_RESET(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_RESET_BABBLE);
}

/**
  * @brief  Disable RESET or BABBLE interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_RESET(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_RESET_BABBLE);
}

/**
  * @brief  Check if RESET or BABBLE interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_RESET(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_RESET_BABBLE) == (OTG_HS_INTRUSBE_INT_RESET_BABBLE) ? 1UL : 0UL);
}

/**
  * @brief  Enable SOF interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_SOF(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SOFE);
}

/**
  * @brief  Disable SOF interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_SOF(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SOFE);
}

/**
  * @brief  Check if SOF interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_SOF(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SOFE) == (OTG_HS_INTRUSBE_INT_SOFE) ? 1UL : 0UL);
}

/**
 * @brief  Enable CONNECT interrupt
 * @param  USBx USB Instance
 * @retval None
 */
__STATIC_INLINE void DDL_USB_EnableIT_CONNECT(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_CONNE);
}

/**
  * @brief  Disable CONNECT interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_CONNECT(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_CONNE);
}

/**
  * @brief  Check if CONNECT interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_CONNECT(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_CONNE) == (OTG_HS_INTRUSBE_INT_CONNE) ? 1UL : 0UL);
}

/**
  * @brief  Enable DISCONNECT interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_DISCONNECT(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_DISCONE);
}

/**
  * @brief  Disable DISCONNECT interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_DISCONNECT(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_DISCONE);
}

/**
  * @brief  Check if DISCONNECT interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_DISCONNECT(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_DISCONE) == (OTG_HS_INTRUSBE_INT_DISCONE) ? 1UL : 0UL);
}

/**
  * @brief  Enable A-SESSION REQUEST interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_SESSREQ(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SESS_REQE);
}

/**
  * @brief  Disable A-SESSION REQUEST interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_SESSREQ(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SESS_REQE);
}

/**
  * @brief  Check if A-SESSION REQUEST interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_SESSREQ(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_SESS_REQE) == (OTG_HS_INTRUSBE_INT_SESS_REQE) ? 1UL : 0UL);
}

/**
  * @brief  Enable VBUS ERROR interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EnableIT_VBUSERROR(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_VBUS_ERRORE);
}

/**
  * @brief  Disable VBUS ERROR interrupt
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DisableIT_VBUSERROR(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_VBUS_ERRORE);
}

/**
  * @brief  Check if VBUS ERROR interrupt is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsEnabledIT_VBUSERROR(USB_OTG_TypeDef *USBx)
{
  return (READ_BIT(USBx->INTRUSBE, OTG_HS_INTRUSBE_INT_VBUS_ERRORE) == (OTG_HS_INTRUSBE_INT_VBUS_ERRORE) ? 1UL : 0UL);
}

/**
  * @brief  Get USB high speed mode
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_HS(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_HSMODE) == (OTG_HS_POWER_HSMODE)) ? 1UL : 0UL);
}

/**
  * @brief  Get USB bus reset state
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_USBRESET(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_USBRESET) == (OTG_HS_POWER_USBRESET)) ? 1UL : 0UL);
}

/**
  * @brief  Check if USB bus suspend state is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_SUSPEND(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->POWER, OTG_HS_POWER_SUSPENDMODE) == (OTG_HS_POWER_SUSPENDMODE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USB device is low speed
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_LSDEV(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_LSDEV) == (OTG_HS_DEVCTL_LSDEV)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USB device is full speed
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_FSDEV(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_FSDEV) == (OTG_HS_DEVCTL_FSDEV) && \
          (READ_BIT(USBx->POWER, OTG_HS_POWER_HSMODE) == RESET)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USB device is high speed
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_HSDEV(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_FSDEV) == (OTG_HS_DEVCTL_FSDEV) && \
          (READ_BIT(USBx->POWER, OTG_HS_POWER_HSMODE) == (OTG_HS_POWER_HSMODE))) ? 1UL : 0UL);
}

/**
 * @brief  Check if the USB is in host mode
 * @param  USBx USB Instance
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t DDL_USB_IsActiveFlag_HOST(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->DEVCTL, OTG_HS_DEVCTL_HOST_MODE) == (OTG_HS_DEVCTL_HOST_MODE)) ? 1UL : 0UL);
}

/**
 * @brief  Read the USB DMA interrupt status
 * @param  USBx USB Instance
 * @retval Returned value is the status of the USB DMA interrupt
 */
__STATIC_INLINE uint32_t DDL_USB_DMA_ReadInterrupts(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->DMA_INTR));
}

/**
  * @brief  Enable the USB DMA channel
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_EnableChannel(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  SET_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
            OTG_HS_DMA_CNTL_CNTRL_EN);
}

/**
  * @brief  Disable the USB DMA channel
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_DisableChannel(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  CLEAR_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
              OTG_HS_DMA_CNTL_CNTRL_EN);
}

/**
  * @brief  Check if the USB DMA channel is enabled
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_IsEnabledChannel(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
                   OTG_HS_DMA_CNTL_CNTRL_EN) == (OTG_HS_DMA_CNTL_CNTRL_EN) ? 1UL : 0UL);
}

/**
  * @brief  Set the USB DMA channel data transfer direction
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_DIR_WRITE
  *         @arg @ref DDL_USB_DMA_DIR_READ
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_SetDataTransferDirection(USB_OTG_TypeDef *USBx, uint32_t Channel, uint32_t Direction)
{
  MODIFY_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_DIR, Direction);
}

/**
  * @brief  Get the USB DMA channel data transfer direction
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval The current transfer direction of the USB DMA channel
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_GetDataTransferDirection(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_DIR));
}

/**
 * @brief  Set the USB DMA channel mode
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_MODE_0
  *         @arg @ref DDL_USB_DMA_MODE_1
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_SetMode(USB_OTG_TypeDef *USBx, uint32_t Channel, uint32_t Mode)
{
  MODIFY_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_MODE, Mode << OTG_HS_DMA_CNTL_CNTRL_MODE_POS);
}

/**
  * @brief  Get the USB DMA channel mode
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval The current mode of the USB DMA channel
  *         @arg @ref DDL_USB_DMA_MODE_0
  *         @arg @ref DDL_USB_DMA_MODE_1
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_GetMode(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_MODE) >> OTG_HS_DMA_CNTL_CNTRL_MODE_POS);
}

/**
  * @brief  Enable the USB DMA channel interrupt
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_EnableInterrupt(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  SET_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
            OTG_HS_DMA_CNTL_CNTRL_INTEN);
}

/**
  * @brief  Disable the USB DMA channel interrupt
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_DisableInterrupt(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  CLEAR_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
              OTG_HS_DMA_CNTL_CNTRL_INTEN);
}

/**
  * @brief  Check if the USB DMA channel interrupt is enabled
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_IsEnabledInterrupt(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
                   OTG_HS_DMA_CNTL_CNTRL_INTEN) == (OTG_HS_DMA_CNTL_CNTRL_INTEN) ? 1UL : 0UL);
}

/**
  * @brief  Set the USB DMA channel endpoint number
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @param  EpNum This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x08
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_SetEndpoint(USB_OTG_TypeDef *USBx, uint32_t Channel, uint8_t EpNum)
{
  MODIFY_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_EPNUM, EpNum << OTG_HS_DMA_CNTL_CNTRL_EPNUM_Pos);
}

/**
  * @brief  Get the USB DMA channel endpoint number
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval The current endpoint number of the USB DMA channel
  */
__STATIC_INLINE uint8_t DDL_USB_DMA_GetEndpoint(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (uint8_t)(READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_EPNUM) >> OTG_HS_DMA_CNTL_CNTRL_EPNUM_Pos);
}

/**
 * @brief  Set the USB DMA channel transfer burst length
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @param  Length This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_BURST_ANY
  *         @arg @ref DDL_USB_DMA_BURST_INCR4
  *         @arg @ref DDL_USB_DMA_BURST_INCR8
  *         @arg @ref DDL_USB_DMA_BURST_INCR16
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_SetBurstLength(USB_OTG_TypeDef *USBx, uint32_t Channel, uint32_t Length)
{
  MODIFY_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_BURST, Length);
}

/**
  * @brief  Get the USB DMA channel transfer burst length
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval The current transfer burst length of the USB DMA channel
  *         @arg @ref DDL_USB_DMA_BURST_ANY
  *         @arg @ref DDL_USB_DMA_BURST_INCR4
  *         @arg @ref DDL_USB_DMA_BURST_INCR8
  *         @arg @ref DDL_USB_DMA_BURST_INCR16
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_GetBurstLength(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
             OTG_HS_DMA_CNTL_CNTRL_BURST));
}

/**
  * @brief  Check if the USB DMA channel bus error flag is set
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_IsActiveFlag_BUSERROR(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (READ_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
                   OTG_HS_DMA_CNTL_CNTRL_BUSERR) == (OTG_HS_DMA_CNTL_CNTRL_BUSERR) ? 1UL : 0UL);
}

/**
  * @brief  Clear the USB DMA channel bus error flag
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_ClearActiveFlag_BUSERROR(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  CLEAR_BIT(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_CNTL, \
            OTG_HS_DMA_CNTL_CNTRL_BUSERR);
}

/**
  * @brief  Set the USB DMA memory address
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @param  Address Between Min_Data = 0x00000000 and Max_Data = 0xFFFFFFFF
  * @retval None
  * @note   The address must be aligned to 4 bytes.
  */
__STATIC_INLINE void DDL_USB_DMA_SetMemoryAddress(USB_OTG_TypeDef *USBx, uint32_t Channel, uint32_t Address)
{
  WRITE_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_ADDR, \
            Address);
}

/**
  * @brief  Get the USB DMA memory address
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval The current memory address of the USB DMA channel
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_GetMemoryAddress(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (uint32_t)(READ_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_ADDR));
}

/**
  * @brief  Set the USB DMA channel number of bytes to transfer
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @param  NbData Between Min_Data = 0x00000000 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_DMA_SetDataLength(USB_OTG_TypeDef *USBx, uint32_t Channel, uint32_t NbData)
{
  WRITE_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_COUNT, \
            NbData);
}

/**
  * @brief  Get the USB DMA channel number of bytes to transfer
  * @param  USBx USB Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_CHANNEL_0
  *         @arg @ref DDL_USB_DMA_CHANNEL_1
  *         @arg @ref DDL_USB_DMA_CHANNEL_2
  *         @arg @ref DDL_USB_DMA_CHANNEL_3
  *         @arg @ref DDL_USB_DMA_CHANNEL_4
  *         @arg @ref DDL_USB_DMA_CHANNEL_5
  *         @arg @ref DDL_USB_DMA_CHANNEL_6
  *         @arg @ref DDL_USB_DMA_CHANNEL_7
  * @retval The current number of bytes to transfer for the USB DMA channel
  */
__STATIC_INLINE uint32_t DDL_USB_DMA_GetDataLength(USB_OTG_TypeDef *USBx, uint32_t Channel)
{
  return (uint32_t)(READ_REG(((USB_OTG_DMA_CH_TypeDef *)((uint32_t)((uint32_t)USBx + USB_OTG_HS_DMA_CNTL_BASE + (0x10U * Channel))))->DMA_COUNT));
}

/**
  * @}
  */

/** @defgroup USB_DDL_EF_Endpoint Endpoint control functions
  * @{
  */

/**
  * @brief  Set the endpoint 0 NAK limit
  * @param  USBx USB Instance
  * @param  Limit This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x10
  * @return None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_SetNAKLimit(USB_OTG_TypeDef *USBx, uint32_t Limit)
{
  MODIFY_REG(USBx->NAKLIMIT0, OTG_HS_NAKLIMIT0_NAKLIMIT0, Limit);
}

/**
  * @brief  Get the endpoint 0 NAK limit
  * @param  USBx USB Instance
  * @return The current NAK limit for endpoint 0
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_GetNAKLimit(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_BIT(USBx->NAKLIMIT0, OTG_HS_NAKLIMIT0_NAKLIMIT0));
}

/**
  * @brief  Enable the endpoint 0 packet PING
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_EnablePing(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_DISPING);
}

/**
  * @brief  Disable the endpoint 0 packet PING
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_DisablePing(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_DISPING);
}

/**
  * @brief  Check if the endpoint 0 packet PING is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsEnabledPing(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_DISPING) == (OTG_HS_CSR0_DISPING)) ? 0UL : 1UL);
}

/**
  * @brief  Flush the endpoint 0 FIFO
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EP0_FlushFIFO(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_FLUSHFIFO);
}

/**
  * @brief  Check if the endpoint 0 SetupEnd flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsActiveFlag_SETUPEND(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_SETUPEND) == (OTG_HS_CSR0_SETUPEND)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint 0 SetupEnd flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EP0_ClearActiveFlag_SETUPEND(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_SERVICEDSETUPEND);
}

/**
  * @brief  Check if the endpoint 0 NAK timeout flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsActiveFlag_NAKTIMEOUT(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_NAKTIMEOUT) == (OTG_HS_CSR0_NAKTIMEOUT)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint 0 NAK timeout flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_ClearActiveFlag_NAKTIMEOUT(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_NAKTIMEOUT);
}

/**
  * @brief  Clear the endpoint 0 RxPktRdy flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EP0_ClearActiveFlag_SERRXPKTRDY(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_SERVICEDRXPKTRDY);
}

/**
  * @brief  Enable the endpoint 0 status packet
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_EnableStatusPacket(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_STATUSPKT);
}

/**
  * @brief  Disable the endpoint 0 status packet
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_DisableStatusPacket(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_STATUSPKT);
}

/**
  * @brief  Check if the endpoint 0 status packet is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsEnabledStatusPacket(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_STATUSPKT) == (OTG_HS_CSR0_STATUSPKT)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint 0 stall
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EP0_EnableStall(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_SENDSTALL);
}

/**
  * @brief  Enable the endpoint 0 IN packet request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_EnableInPacketRequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_REQPKT);
}

/**
  * @brief  Disable the endpoint 0 IN packet request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_DisableInPacketRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_REQPKT);
}

/**
  * @brief  Check if the endpoint 0 IN packet request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsEnabledInPacketRequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_REQPKT) == (OTG_HS_CSR0_REQPKT)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the endpoint 0 packet status error flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsActiveFlag_ERROR(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_ERROR) == (OTG_HS_CSR0_ERROR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint 0 packet status error flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_ClearActiveFlag_ERROR(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_ERROR);
}

/**
  * @brief  Enable the endpoint 0 DATAEND
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EP0_EnableDataEnd(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_DATAEND);
}

/**
  * @brief  Enable the endpoint 0 SETUP packet
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_EnableSetupPacket(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_SETUPPKT);
}

/**
  * @brief  Disable the endpoint 0 SETUP packet
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EP0_DisableSetupPacket(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_SETUPPKT);
}

/**
  * @brief  Check if the endpoint 0 SETUP packet is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsEnabledSetupPacket(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_SETUPPKT) == (OTG_HS_CSR0_SETUPPKT)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the endpoint 0 stall is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsActiveFlag_STALL(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_SENTSTALL) == (OTG_HS_CSR0_SENTSTALL)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint 0 stall
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EP0_ClearActiveFlag_STALL(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_SENTSTALL);
}

/**
  * @brief  Check if the endpoint 0 TxPktRdy flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsActiveFlag_TXPKTRDY(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_TXPKTRDY) == (OTG_HS_CSR0_TXPKTRDY)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint 0 TxPktRdy
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EP0_SetActiveFlag_TXPKTRDY(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->CSR0, OTG_HS_CSR0_TXPKTRDY);
}

/**
  * @brief  Check if the endpoint 0 RxPktRdy flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_IsActiveFlag_RXPKTRDY(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->CSR0, OTG_HS_CSR0_RXPKTRDY) == (OTG_HS_CSR0_RXPKTRDY)) ? 1UL : 0UL);
}

/**
 * @brief  Clear the endpoint 0 RxPktRdy flag
 * @param  USBx USB Instance
 * @retval None
 * @note   This function only available for host mode.
 */
__STATIC_INLINE void DDL_USB_EP0_ClearActiveFlag_RXPKTRDY(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->CSR0, OTG_HS_CSR0_RXPKTRDY);
}

/**
  * @brief  Get the endpoint 0 received data count
  * @param  USBx USB Instance
  * @retval The endpoint 0 received data count
  */
__STATIC_INLINE uint32_t DDL_USB_EP0_GetRxDataCount(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->COUNT0) & OTG_HS_COUNT0_COUNT0);
}

/**
  * @brief  Enable the endpoint TX DMA request
  * @param  USBx USB Instance
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_MODE_0
  *         @arg @ref DDL_USB_DMA_MODE_1
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableDmaRequest(USB_OTG_TypeDef *USBx, uint32_t mode)
{
  MODIFY_REG(USBx->TXCSR, OTG_HS_TXCSR_AUTOSET | OTG_HS_TXCSR_DMAREQENAB | OTG_HS_TXCSR_DMAREQMODE,
              OTG_HS_TXCSR_AUTOSET | OTG_HS_TXCSR_DMAREQENAB | mode << OTG_HS_TXCSR_DMAREQMODE_Pos);
}

/**
  * @brief  Disable the endpoint TX DMA request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableDmaRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_AUTOSET | OTG_HS_TXCSR_DMAREQENAB | OTG_HS_TXCSR_DMAREQMODE);
}

/**
  * @brief  Set the endpoint TX protocol
  * @param  USBx USB Instance
  * @param  Protocol This parameter can be one of the following values:
  *         @arg @ref DDL_USB_EP_TYPE_CTRL
  *         @arg @ref DDL_USB_EP_TYPE_ISOC
  *         @arg @ref DDL_USB_EP_TYPE_BULK
  *         @arg @ref DDL_USB_EP_TYPE_INTR
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_SetProtocol(USB_OTG_TypeDef *USBx, uint32_t Protocol)
{
  MODIFY_REG(USBx->TXTYPE, OTG_HS_TXTYPE_PROTOCOL, Protocol);
}

/**
  * @brief  Get the endpoint TX protocol
  * @param  USBx USB Instance
  * @retval The endpoint TX protocol
  *         @arg @ref DDL_USB_EP_TYPE_CTRL
  *         @arg @ref DDL_USB_EP_TYPE_ISOC
  *         @arg @ref DDL_USB_EP_TYPE_BULK
  *         @arg @ref DDL_USB_EP_TYPE_INTR
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_GetProtocol(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->TXTYPE) & OTG_HS_TXTYPE_PROTOCOL);
}

/**
  * @brief  Set the target endpoint number for the TX direction
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a number between Min_Data = 0x01 and Max_Data = 0x08
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_SetTargetEndpoint(USB_OTG_TypeDef *USBx, uint32_t EpNum)
{
  MODIFY_REG(USBx->TXTYPE, OTG_HS_TXTYPE_TARGET_ENDPOINT_NUMBER, EpNum);
}

/**
  * @brief  Get the target endpoint number for the TX direction
  * @param  USBx USB Instance
  * @retval The target endpoint number for the TX direction
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_GetTargetEndpoint(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->TXTYPE) & OTG_HS_TXTYPE_TARGET_ENDPOINT_NUMBER);
}

/**
  * @brief  Set the endpoint TX interval
  * @param  USBx USB Instance
  * @param  Interval This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval None
  * @note   This function only available for host mode.
  * @note   The interval can be set only for interrupt and isochronous endpoints.
  */
__STATIC_INLINE void DDL_USB_EPTX_SetInterval(USB_OTG_TypeDef *USBx, uint32_t Interval)
{
  MODIFY_REG(USBx->TXINTERVAL, OTG_HS_TXINTERVAL_TXINTERVAL_NAKLIMIT, Interval);
}

/**
  * @brief  Get the endpoint TX interval
  * @param  USBx USB Instance
  * @retval The endpoint TX interval
  * @note   This function only available for host mode.
  * @note   The interval can be set only for interrupt and isochronous endpoints.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_GetInterval(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->TXINTERVAL) & OTG_HS_TXINTERVAL_TXINTERVAL_NAKLIMIT);
}

/**
  * @brief  Set the endpoint TX NAK limit
  * @param  USBx USB Instance
  * @param  Limit This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x10
  * @retval None
  * @note   This function only available for host mode.
  * @note   The NAK limit can be set only for bulk endpoints.
  */
__STATIC_INLINE void DDL_USB_EPTX_SetNAKLimit(USB_OTG_TypeDef *USBx, uint32_t Limit)
{
  MODIFY_REG(USBx->TXINTERVAL, OTG_HS_TXINTERVAL_TXINTERVAL_NAKLIMIT, Limit);
}

/**
  * @brief  Get the endpoint TX NAK limit
  * @param  USBx USB Instance
  * @retval The current NAK limit for the endpoint TX
  * @note   This function only available for host mode.
  * @note   The NAK limit can be set only for bulk endpoints.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_GetNAKLimit(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_BIT(USBx->TXINTERVAL, OTG_HS_TXINTERVAL_TXINTERVAL_NAKLIMIT));
}

/**
  * @brief  Set the endpoint TX FIFO size
  * @param  USBx USB Instance
  * @param  Size This parameter can be one of the following values:
  *         @arg @ref DDL_USB_FIFO_SIZE_8
  *         @arg @ref DDL_USB_FIFO_SIZE_16
  *         @arg @ref DDL_USB_FIFO_SIZE_32
  *         @arg @ref DDL_USB_FIFO_SIZE_64
  *         @arg @ref DDL_USB_FIFO_SIZE_128
  *         @arg @ref DDL_USB_FIFO_SIZE_256
  *         @arg @ref DDL_USB_FIFO_SIZE_512
  *         @arg @ref DDL_USB_FIFO_SIZE_1024
  *         @arg @ref DDL_USB_FIFO_SIZE_2048
  *         @arg @ref DDL_USB_FIFO_SIZE_4096
  *  @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_SetFifoSize(USB_OTG_TypeDef *USBx, uint32_t Size)
{
  MODIFY_REG(USBx->TXFIFOSZ, OTG_HS_TXFIFOSZ_SIZE, Size & OTG_HS_TXFIFOSZ_SIZE);
}

/**
  * @brief  Get the endpoint TX FIFO size
  * @param  USBx USB Instance
  * @retval The endpoint TX FIFO size
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_GetFifoSize(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->TXFIFOSZ) & OTG_HS_TXFIFOSZ_SIZE);
}

/**
  * @brief  Enable the endpoint TX FIFO double packet buffer
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableFifoDPB(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXFIFOSZ, OTG_HS_TXFIFOSZ_DPB);
}

/**
  * @brief  Disable the endpoint TX FIFO double packet buffer
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableFifoDPB(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXFIFOSZ, OTG_HS_TXFIFOSZ_DPB);
}

/**
  * @brief  Check if the endpoint TX FIFO double packet buffer is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledFifoDPB(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXFIFOSZ, OTG_HS_TXFIFOSZ_DPB) == (OTG_HS_TXFIFOSZ_DPB)) ? 1UL : 0UL);
}

/**
  * @brief  Set the endpoint TX FIFO address
  * @param  USBx USB Instance
  * @param  Address This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_SetFifoAddress(USB_OTG_TypeDef *USBx, uint16_t Address)
{
  MODIFY_REG(USBx->TXFIFOADD, OTG_HS_TXFIFOADD_ADD, Address & OTG_HS_TXFIFOADD_ADD);
}

/**
  * @brief  Get the endpoint TX FIFO address
  * @param  USBx USB Instance
  * @retval The endpoint TX FIFO address
  */
__STATIC_INLINE uint16_t DDL_USB_EPTX_GetFifoAddress(USB_OTG_TypeDef *USBx)
{
  return (uint16_t)(READ_REG(USBx->TXFIFOADD) & OTG_HS_TXFIFOADD_ADD);
}

/**
  * @brief  Enable the endpoint TX ISO 3 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableIso3TM(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXMAX, OTG_HS_TXMAX_TX_3T_M);
}

/**
  * @brief  Disable the endpoint TX ISO 3 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableIso3TM(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXMAX, OTG_HS_TXMAX_TX_3T_M);
}

/**
  * @brief  Check if the endpoint TX ISO 3 transaction / microframe is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledIso3TM(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXMAX, OTG_HS_TXMAX_TX_3T_M) == (OTG_HS_TXMAX_TX_3T_M)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint TX ISO 2 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableIso2TM(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXMAX, OTG_HS_TXMAX_TX_2T_M);
}

/**
  * @brief  Disable the endpoint TX ISO 2 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableIso2TM(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXMAX, OTG_HS_TXMAX_TX_2T_M);
}

/**
  * @brief  Check if the endpoint TX ISO 2 transaction / microframe is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledIso2TM(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXMAX, OTG_HS_TXMAX_TX_2T_M) == (OTG_HS_TXMAX_TX_2T_M)) ? 1UL : 0UL);
}

/**
  * @brief  Set the endpoint TX maximum packet size
  * @param  USBx USB Instance
  * @param  MaxPacketSize This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7FF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_SetMaxPacketSize(USB_OTG_TypeDef *USBx, uint16_t MaxPacketSize)
{
  MODIFY_REG(USBx->TXMAX, OTG_HS_TXMAX_TXMAX, MaxPacketSize & OTG_HS_TXMAX_TXMAX);
}

/**
  * @brief  Get the endpoint TX maximum packet size
  * @param  USBx USB Instance
  * @retval The IN endpoint maximum packet size
  */
__STATIC_INLINE uint16_t DDL_USB_EPTX_GetMaxPacketSize(USB_OTG_TypeDef *USBx)
{
  return (uint16_t)(READ_REG(USBx->TXMAX) & OTG_HS_TXMAX_TXMAX);
}

/**
  * @brief  Enable the endpoint TX auto set
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableAutoSet(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_AUTOSET);
}

/**
  * @brief  Disable the endpoint TX auto set
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableAutoSet(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_AUTOSET);
}

/**
  * @brief  Check if the endpoint TX auto set is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledAutoSet(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_AUTOSET) == (OTG_HS_TXCSR_AUTOSET)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint TX ISO transfer
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableIsoTransfer(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_ISO);
}

/**
  * @brief  Disable the endpoint TX ISO transfer
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableIsoTransfer(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_ISO);
}

/**
  * @brief  Check if the endpoint TX ISO transfer is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledIsoTransfer(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_ISO) == (OTG_HS_TXCSR_ISO)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint TX DMA request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableDMARequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_DMAREQENAB);
}

/**
  * @brief  Disable the endpoint TX DMA request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableDMARequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_DMAREQENAB);
}

/**
  * @brief  Check if the endpoint TX DMA request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledDMARequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_DMAREQENAB) == (OTG_HS_TXCSR_DMAREQENAB)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint TX force data toggle
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableForceDataToggle(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_FRCDATATOG);
}

/**
  * @brief  Disable the endpoint TX force data toggle
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableForceDataToggle(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_FRCDATATOG);
}

/**
  * @brief  Check if the endpoint TX force data toggle is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledForceDataToggle(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_FRCDATATOG) == (OTG_HS_TXCSR_FRCDATATOG)) ? 1UL : 0UL);
}

/**
  * @brief  Set the endpoint TX DMA request mode
  * @param  USBx USB Instance
  * @param  Mode This parameter can be one of the following values:
  *        @arg @ref DDL_USB_DMA_REQ_MODE_0
  *        @arg @ref DDL_USB_DMA_REQ_MODE_1
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_SetDMARequestMode(USB_OTG_TypeDef *USBx, uint32_t Mode)
{
  MODIFY_REG(USBx->TXCSR, OTG_HS_TXCSR_DMAREQMODE, Mode << OTG_HS_TXCSR_DMAREQMODE_Pos);
}

/**
  * @brief  Get the endpoint TX DMA request mode
  * @param  USBx USB Instance
  * @retval The IN endpoint DMA request mode
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_GetDMARequestMode(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->TXCSR) & OTG_HS_TXCSR_DMAREQMODE);
}

/**
  * @brief  Clear the endpoint TX data toggle
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearDataToggle(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_CLRDATATOG);
}

/**
  * @brief  Enable the endpoint TX stall
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_EnableStall(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_SENDSTALL);
}

/**
  * @brief  Disable the endpoint TX stall
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_DisableStall(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_SENDSTALL);
}

/**
  * @brief  Check if the endpoint TX stall is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsEnabledStall(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_SENDSTALL) == (OTG_HS_TXCSR_SENDSTALL)) ? 1UL : 0UL);
}

/**
  * @brief  Flush the endpoint TX FIFO
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_FlushFIFO(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_FLUSHFIFO);
}

/**
  * @brief  Check if the endpoint TX high bandwidth transfer is finished
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_HBTX(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_INCOMPTX) == (OTG_HS_TXCSR_INCOMPTX)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint TX high bandwidth transfer finished flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearActiveFlag_HBTX(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_INCOMPTX);
}

/**
  * @brief  Check if the endpoint TX NAK timeout is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_NAKTIMEOUT(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_NAKTIMEOUT) == (OTG_HS_TXCSR_NAKTIMEOUT)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint TX NAK timeout flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearActiveFlag_NAKTIMEOUT(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_NAKTIMEOUT);
}

/**
  * @brief  Check if the endpoint TX stall is set(received)
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_STALL(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_SENTSTALL) == (OTG_HS_TXCSR_SENTSTALL)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint TX stall
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearActiveFlag_STALL(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_SENTSTALL);
}

/**
  * @brief  Check if the endpoint TX underrun flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_UNDERRUN(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_UNDERRUN) == (OTG_HS_TXCSR_UNDERRUN)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint TX underrun flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearActiveFlag_UNDERRUN(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_UNDERRUN);
}

/**
  * @brief  Check if the endpoint TX packet status error flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_ERROR(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_ERROR) == (OTG_HS_TXCSR_ERROR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint TX packet status error flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearActiveFlag_ERROR(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_ERROR);
}

/**
  * @brief  Check if the endpoint TX FIFO is not empty
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_FNE(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_FIFONOTEMPTY) == (OTG_HS_TXCSR_FIFONOTEMPTY)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint TX FIFO not empty flag
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_ClearActiveFlag_FNE(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->TXCSR, OTG_HS_TXCSR_FIFONOTEMPTY);
}

/**
  * @brief  Check if the endpoint TX FIFO packet is ready
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPTX_IsActiveFlag_TXPKTRDY(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->TXCSR, OTG_HS_TXCSR_TXPKTRDY) == (OTG_HS_TXCSR_TXPKTRDY)) ? 1UL : 0UL);
}

/**
  * @brief  Set the endpoint TX FIFO packet ready
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPTX_SetActiveFlag_TXPKTRDY(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->TXCSR, OTG_HS_TXCSR_TXPKTRDY);
}

/**
  * @brief  Enable the endpoint RX DMA request
  * @param  USBx USB Instance
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref DDL_USB_DMA_MODE_0
  *         @arg @ref DDL_USB_DMA_MODE_1
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableDmaRequest(USB_OTG_TypeDef *USBx, uint32_t mode)
{
  MODIFY_REG(USBx->RXCSR, OTG_HS_RXCSR_AUTOCLEAR | OTG_HS_RXCSR_DMAREQENAB | OTG_HS_RXCSR_DMAREQMODE,
              OTG_HS_RXCSR_AUTOCLEAR | OTG_HS_RXCSR_DMAREQENAB | mode << OTG_HS_RXCSR_DMAREQMODE_Pos);
}

/**
  * @brief  Disable the endpoint RX DMA request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableDmaRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOCLEAR | OTG_HS_RXCSR_DMAREQENAB | OTG_HS_RXCSR_DMAREQMODE);
}

/**
  * @brief  Set the endpoint RX protocol
  * @param  USBx USB Instance
  * @param  Protocol This parameter can be one of the following values:
  *         @arg @ref DDL_USB_EP_TYPE_CTRL
  *         @arg @ref DDL_USB_EP_TYPE_ISOC
  *         @arg @ref DDL_USB_EP_TYPE_BULK
  *         @arg @ref DDL_USB_EP_TYPE_INTR
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_SetProtocol(USB_OTG_TypeDef *USBx, uint32_t Protocol)
{
  MODIFY_REG(USBx->RXTYPE, OTG_HS_RXTYPE_PROTOCOL, Protocol);
}

/**
  * @brief  Get the endpoint RX protocol
  * @param  USBx USB Instance
  * @retval The endpoint RX protocol
  *         @arg @ref DDL_USB_EP_TYPE_CTRL
  *         @arg @ref DDL_USB_EP_TYPE_ISOC
  *         @arg @ref DDL_USB_EP_TYPE_BULK
  *         @arg @ref DDL_USB_EP_TYPE_INTR
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetProtocol(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->RXTYPE) & OTG_HS_RXTYPE_PROTOCOL);
}

/**
  * @brief  Set the target endpoint number for the RX direction
  * @param  USBx USB Instance
  * @param  EpNum This parameter can be a number between Min_Data = 0x01 and Max_Data = 0x08
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_SetTargetEndpoint(USB_OTG_TypeDef *USBx, uint32_t EpNum)
{
  MODIFY_REG(USBx->RXTYPE, OTG_HS_RXTYPE_TARGET_ENDPOINT_NUMBER, EpNum);
}

/**
  * @brief  Get the target endpoint number for the RX direction
  * @param  USBx USB Instance
  * @retval The target endpoint number for the RX direction
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetTargetEndpoint(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->RXTYPE) & OTG_HS_RXTYPE_TARGET_ENDPOINT_NUMBER);
}

/**
  * @brief  Set the endpoint RX interval
  * @param  USBx USB Instance
  * @param  Interval This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval None
  * @note   This function only available for host mode.
  * @note   The interval can be set only for interrupt and isochronous endpoints.
  */
__STATIC_INLINE void DDL_USB_EPRX_SetInterval(USB_OTG_TypeDef *USBx, uint32_t Interval)
{
  MODIFY_REG(USBx->RXINTERVAL, OTG_HS_RXINTERVAL_RXINTERVAL, Interval);
}

/**
  * @brief  Get the endpoint RX interval
  * @param  USBx USB Instance
  * @retval The endpoint RX interval
  * @note   This function only available for host mode.
  * @note   The interval can be set only for interrupt and isochronous endpoints.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetInterval(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->RXINTERVAL) & OTG_HS_RXINTERVAL_RXINTERVAL);
}

/**
  * @brief  Set the endpoint RX NAK limit
  * @param  USBx USB Instance
  * @param  Limit This parameter can be a number between Min_Data = 0x00 and Max_Data = 0x10
  * @retval None
  * @note   This function only available for host mode.
  * @note   The NAK limit can be set only for bulk endpoints.
  */
__STATIC_INLINE void DDL_USB_EPRX_SetNAKLimit(USB_OTG_TypeDef *USBx, uint32_t Limit)
{
  MODIFY_REG(USBx->RXINTERVAL, OTG_HS_RXINTERVAL_RXINTERVAL, Limit);
}

/**
  * @brief  Get the endpoint RX NAK limit
  * @param  USBx USB Instance
  * @retval The current NAK limit for the endpoint RX
  * @note   This function only available for host mode.
  * @note   The NAK limit can be set only for bulk endpoints.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetNAKLimit(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_BIT(USBx->RXINTERVAL, OTG_HS_RXINTERVAL_RXINTERVAL));
}

/**
  * @brief  Set the endpoint RX FIFO size
  * @param  USBx USB Instance
  * @param  Size This parameter can be one of the following values:
  *         @arg @ref DDL_USB_FIFO_SIZE_8
  *         @arg @ref DDL_USB_FIFO_SIZE_16
  *         @arg @ref DDL_USB_FIFO_SIZE_32
  *         @arg @ref DDL_USB_FIFO_SIZE_64
  *         @arg @ref DDL_USB_FIFO_SIZE_128
  *         @arg @ref DDL_USB_FIFO_SIZE_256
  *         @arg @ref DDL_USB_FIFO_SIZE_512
  *         @arg @ref DDL_USB_FIFO_SIZE_1024
  *         @arg @ref DDL_USB_FIFO_SIZE_2048
  *         @arg @ref DDL_USB_FIFO_SIZE_4096
  *  @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_SetFifoSize(USB_OTG_TypeDef *USBx, uint32_t Size)
{
  MODIFY_REG(USBx->RXFIFOSZ, OTG_HS_RXFIFOSZ_SIZE, Size & OTG_HS_RXFIFOSZ_SIZE);
}

/**
  * @brief  Get the endpoint RX FIFO size
  * @param  USBx USB Instance
  * @retval The endpoint RX FIFO size
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetFifoSize(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->RXFIFOSZ) & OTG_HS_RXFIFOSZ_SIZE);
}

/**
  * @brief  Enable the endpoint RX FIFO double packet buffer
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableFifoDPB(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXFIFOSZ, OTG_HS_RXFIFOSZ_DPB);
}

/**
  * @brief  Disable the endpoint RX FIFO double packet buffer
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableFifoDPB(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXFIFOSZ, OTG_HS_RXFIFOSZ_DPB);
}

/**
  * @brief  Check if the endpoint RX FIFO double packet buffer is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledFifoDPB(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXFIFOSZ, OTG_HS_RXFIFOSZ_DPB) == (OTG_HS_RXFIFOSZ_DPB)) ? 1UL : 0UL);
}

/**
  * @brief  Set the endpoint RX FIFO address
  * @param  USBx USB Instance
  * @param  Address This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_SetFifoAddress(USB_OTG_TypeDef *USBx, uint16_t Address)
{
  MODIFY_REG(USBx->RXFIFOADD, OTG_HS_RXFIFOADD_ADD, Address & OTG_HS_RXFIFOADD_ADD);
}

/**
  * @brief  Get the endpoint RX FIFO address
  * @param  USBx USB Instance
  * @retval The endpoint RX FIFO address
  */
__STATIC_INLINE uint16_t DDL_USB_EPRX_GetFifoAddress(USB_OTG_TypeDef *USBx)
{
  return (uint16_t)(READ_REG(USBx->RXFIFOADD) & OTG_HS_RXFIFOADD_ADD);
}

/**
  * @brief  Enable the endpoint RX ISO 3 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableIso3TM(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXMAX, OTG_HS_RXMAX_RX_3T_M);
}

/**
  * @brief  Disable the endpoint RX ISO 3 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableIso3TM(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXMAX, OTG_HS_RXMAX_RX_3T_M);
}

/**
  * @brief  Check if the endpoint RX ISO 3 transaction / microframe is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledIso3TM(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXMAX, OTG_HS_RXMAX_RX_3T_M) == (OTG_HS_RXMAX_RX_3T_M)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint RX ISO 2 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableIso2TM(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXMAX, OTG_HS_RXMAX_RX_2T_M);
}

/**
  * @brief  Disable the endpoint RX ISO 2 transaction / microframe
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableIso2TM(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXMAX, OTG_HS_RXMAX_RX_2T_M);
}

/**
  * @brief  Check if the endpoint RX ISO 2 transaction / microframe is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledIso2TM(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXMAX, OTG_HS_RXMAX_RX_2T_M) == (OTG_HS_RXMAX_RX_2T_M)) ? 1UL : 0UL);
}

/**
  * @brief  Set the endpoint RX maximum packet size
  * @param  USBx USB Instance
  * @param  MaxPacketSize This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7FF
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_SetMaxPacketSize(USB_OTG_TypeDef *USBx, uint16_t MaxPacketSize)
{
  MODIFY_REG(USBx->RXMAX, OTG_HS_RXMAX_RXMAX, MaxPacketSize & OTG_HS_RXMAX_RXMAX);
}

/**
  * @brief  Get the endpoint RX maximum packet size
  * @param  USBx USB Instance
  * @retval The OUT endpoint maximum packet size
  */
__STATIC_INLINE uint16_t DDL_USB_EPRX_GetMaxPacketSize(USB_OTG_TypeDef *USBx)
{
  return (uint16_t)(READ_REG(USBx->RXMAX) & OTG_HS_RXMAX_RXMAX);
}

/**
  * @brief  Enable the endpoint RX auto clear
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableAutoClear(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOCLEAR);
}

/**
  * @brief  Disable the endpoint RX auto clear
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableAutoClear(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOCLEAR);
}

/**
  * @brief  Check if the endpoint RX auto clear is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledAutoClear(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOCLEAR) == (OTG_HS_RXCSR_AUTOCLEAR)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint RX ISO transfer
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableIsoTransfer(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_ISO);
}

/**
  * @brief  Disable the endpoint RX ISO transfer
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableIsoTransfer(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_ISO);
}

/**
  * @brief  Check if the endpoint RX ISO transfer is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledIsoTransfer(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_ISO) == (OTG_HS_RXCSR_ISO)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint RX auto request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableAutoRequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOREQ);
}

/**
  * @brief  Disable the endpoint RX auto request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableAutoRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOREQ);
}

/**
  * @brief  Check if the endpoint RX auto request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledAutoRequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_AUTOREQ) == (OTG_HS_RXCSR_AUTOREQ)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint RX DMA request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableDMARequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_DMAREQENAB);
}

/**
  * @brief  Disable the endpoint RX DMA request
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableDMARequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_DMAREQENAB);
}

/**
  * @brief  Check if the endpoint RX DMA request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledDMARequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_DMAREQENAB) == (OTG_HS_RXCSR_DMAREQENAB)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint RX NYET
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableNYET(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_DISNYET_PIDERR);
}

/**
  * @brief  Disable the endpoint RX NYET
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableNYET(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_DISNYET_PIDERR);
}

/**
  * @brief  Check if the endpoint RX NYET is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledNYET(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_DISNYET_PIDERR) == (OTG_HS_RXCSR_DISNYET_PIDERR)) ? 0UL : 1UL);
}

/**
  * @brief  Set the endpoint RX DMA request mode
  * @param  USBx USB Instance
  * @param  Mode This parameter can be one of the following values:
  *        @arg @ref DDL_USB_DMA_REQ_MODE_0
  *        @arg @ref DDL_USB_DMA_REQ_MODE_1
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_SetDMARequestMode(USB_OTG_TypeDef *USBx, uint32_t Mode)
{
  MODIFY_REG(USBx->RXCSR, OTG_HS_RXCSR_DMAREQMODE, Mode << OTG_HS_RXCSR_DMAREQMODE_Pos);
}

/**
  * @brief  Get the endpoint RX DMA request mode
  * @param  USBx USB Instance
  * @retval The OUT endpoint DMA request mode
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetDMARequestMode(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->RXCSR) & OTG_HS_RXCSR_DMAREQMODE);
}

/**
  * @brief  Check if the endpoint RX high bandwidth transfer is finished
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_HBRX(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_INCOMPRX) == (OTG_HS_RXCSR_INCOMPRX)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX high bandwidth transfer finished flag
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_HBRX(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_INCOMPRX);
}

/**
  * @brief  Clear the endpoint RX data toggle
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearDataToggle(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_CLRDATATOG);
}

/**
  * @brief  Check if the endpoint RX stall is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_STALL(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_SENTSTALL) == (OTG_HS_RXCSR_SENTSTALL)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX stall
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_STALL(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_SENTSTALL);
}

/**
 * @brief  Enable the endpoint RX IN packet request
 * @param  USBx USB Instance
 * @retval None
 * @note   This function only available for host mode.
 */
__STATIC_INLINE void DDL_USB_EPRX_EnableInPacketRequest(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_REQPKT);
}

/**
  * @brief  Disable the endpoint RX IN packet request
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableInPacketRequest(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_REQPKT);
}

/**
  * @brief  Check if the endpoint RX IN packet request is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledInPacketRequest(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_REQPKT) == (OTG_HS_RXCSR_REQPKT)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the endpoint RX stall
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_EnableStall(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_SENDSTALL);
}

/**
  * @brief  Disable the endpoint RX stall
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_DisableStall(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_SENDSTALL);
}

/**
  * @brief  Check if the endpoint RX stall is enabled
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsEnabledStall(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_SENDSTALL) == (OTG_HS_RXCSR_SENDSTALL)) ? 1UL : 0UL);
}

/**
  * @brief  Flush the endpoint RX FIFO
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_FlushFIFO(USB_OTG_TypeDef *USBx)
{
  SET_BIT(USBx->RXCSR, OTG_HS_RXCSR_FLUSHFIFO);
}

/**
  * @brief  Get the endpoint RX received data count
  * @param  USBx USB Instance
  * @retval The OUT endpoint received data count
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_GetRxDataCount(USB_OTG_TypeDef *USBx)
{
  return (uint32_t)(READ_REG(USBx->RXCOUNT) & OTG_HS_RXCOUNT_RXCOUNT);
}

/**
  * @brief  Check if the endpoint RX ISO transfer is PID error
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_PIDERR(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_DISNYET_PIDERR) == (OTG_HS_RXCSR_DISNYET_PIDERR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX ISO transfer PID error flag
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_PIDERR(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_DISNYET_PIDERR);
}

/**
  * @brief  Check if the endpoint RX ISO data error flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_DATAERR(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_DATAERROR) == (OTG_HS_RXCSR_DATAERROR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX ISO data error flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_DATAERR(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_DATAERROR);
}

/**
 * @brief  Check if the endpoint RX NAK timeout flag is set
 * @param  USBx USB Instance
 * @retval State of bit (1 or 0).
 * @note   This function only available for host mode.
 */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_NAKTIMEOUT(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_DATAERROR_NAKTIMEOUT) == (OTG_HS_RXCSR_DATAERROR_NAKTIMEOUT)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX NAK timeout flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_NAKTIMEOUT(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_DATAERROR_NAKTIMEOUT);
}

/**
  * @brief  Check if the endpoint RX ISO overrun flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for device mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_OVERRUN(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_OVERRUN) == (OTG_HS_RXCSR_OVERRUN)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX ISO overrun flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for device mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_OVERRUN(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_OVERRUN);
}

/**
  * @brief  Check if the endpoint RX packet status error flag is set
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  * @note   This function only available for host mode.
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_ERROR(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_ERROR) == (OTG_HS_RXCSR_ERROR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX packet status error flag
  * @param  USBx USB Instance
  * @retval None
  * @note   This function only available for host mode.
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_ERROR(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_ERROR);
}

/**
  * @brief  Check if the endpoint RX FIFO is full
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_FIFOFULL(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_FIFOFULL) == (OTG_HS_RXCSR_FIFOFULL)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the endpoint RX FIFO packet is ready
  * @param  USBx USB Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USB_EPRX_IsActiveFlag_RXPKTRDY(USB_OTG_TypeDef *USBx)
{
  return ((READ_BIT(USBx->RXCSR, OTG_HS_RXCSR_RXPKTRDY) == (OTG_HS_RXCSR_RXPKTRDY)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the endpoint RX FIFO packet ready flag
  * @param  USBx USB Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USB_EPRX_ClearActiveFlag_RXPKTRDY(USB_OTG_TypeDef *USBx)
{
  CLEAR_BIT(USBx->RXCSR, OTG_HS_RXCSR_RXPKTRDY);
}

/**
  * @}
  */

/** @defgroup USB_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus DDL_USB_DeInit(USB_OTG_TypeDef *USBx);
ErrorStatus DDL_USB_Init(USB_OTG_TypeDef *USBx, DDL_USB_OTG_InitTypeDef *USB_InitStruct);
void DDL_USB_StructInit(DDL_USB_OTG_InitTypeDef *USB_InitStruct);

ErrorStatus DDL_USB_DevInit(USB_OTG_TypeDef *USBx, DDL_USB_OTG_InitTypeDef *USB_InitStruct);

ErrorStatus DDL_USB_HostInit(USB_OTG_TypeDef *USBx, DDL_USB_OTG_InitTypeDef *USB_InitStruct);

/**
  * @}
  */

/** @defgroup USB_DDL_EF_Control Control functions
  * @{
  */
void DDL_USB_HCHalt(USB_OTG_TypeDef *USBx, uint8_t ch_num);
uint8_t DDL_USB_GetDevSpeed(USB_OTG_TypeDef *USBx);
uint8_t DDL_USB_GetHostSpeed(USB_OTG_TypeDef *USBx);
ErrorStatus DDL_USB_StopDevice(USB_OTG_TypeDef *USBx);
ErrorStatus DDL_USB_StopHost(USB_OTG_TypeDef *USBx);
ErrorStatus DDL_USB_ActivateRemoteWakeup(USB_OTG_TypeDef *USBx);
ErrorStatus DDL_USB_DeActivateRemoteWakeup(USB_OTG_TypeDef *USBx);
ErrorStatus DDL_USB_EP0StartXfer(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep, uint8_t Dma);
ErrorStatus DDL_USB_EPStartXfer(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep, uint8_t Dma);
ErrorStatus DDL_USB_EPSetStall(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep);
ErrorStatus DDL_USB_EPClearStall(USB_OTG_TypeDef *USBx, DDL_USB_OTG_EPTypeDef *Ep);
void DDL_USB_FlushFIFO(USB_OTG_TypeDef *USBx, uint32_t EpNum, uint32_t EpDir);
ErrorStatus DDL_USB_WritePacket(USB_OTG_TypeDef *USBx, uint8_t *Src, uint8_t EpNum, uint16_t Len);
ErrorStatus DDL_USB_ReadPacket(USB_OTG_TypeDef *USBx, uint8_t *Dst, uint8_t EpNum, uint16_t Len);
/**
  * @}
  */

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

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* G32F463_DDL_USB_H */
