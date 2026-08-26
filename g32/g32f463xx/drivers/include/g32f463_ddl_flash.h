/**
  *
  * @file    g32f463_ddl_flash.h
  * @brief   Header file of FLASH DDL module.
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

#ifndef G32F463_DDL_FLASH_H
#define G32F463_DDL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32f4xx.h"

/** @addtogroup G32F463_DDL_Driver
  * @{
  */

#if defined (FLASH)

/** @defgroup FLASH_DDL FLASH
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup FLASH_DDL_ES_Private_Constants FLASH Private Constants
  * @{
  */

/**
  * @brief   ACCTRL register byte 0 (Bits[7:0]) base address
  */
#define DDL_ACCTRL_BYTE0_ADDRESS          FLASH_R_BASE
/**
  * @brief   OPTCTRL register byte 0 (Bits[7:0]) base address
  */
#define DDL_OPTCTRL_BYTE0_ADDRESS         (FLASH_R_BASE + 0x14)
/**
  * @brief   OPTCTRL register byte 1 (Bits[15:8]) base address
  */
#define DDL_OPTCTRL_BYTE1_ADDRESS         (FLASH_R_BASE + 0x15)
/**
  * @brief   OPTCTRL register byte 2 (Bits[23:16]) base address
  */
#define DDL_OPTCTRL_BYTE2_ADDRESS         (FLASH_R_BASE + 0x16)
/**
  * @brief   OPTCTRL register byte 3 (Bits[31:24]) base address
  */
#define DDL_OPTCTRL_BYTE3_ADDRESS         (FLASH_R_BASE + 0x17)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FLASH_DDL_ES_INIT FLASH Exported Init structure
  * @{
  */
/**
  * @brief  FLASH Erase structure definition
  */
typedef struct
{
  uint32_t TypeErase;       /*!< Mass erase or sector Erase.
                                 This parameter can be a value of @ref FLASH_DDL_EC_Type_Erase */

  uint32_t Sector;          /*!< Initial FLASH sector to erase when Mass erase is disabled
                                 This parameter must be a value of @ref FLASH_DDL_EC_Sectors */

  uint32_t NbSectors;       /*!< Number of sectors to be erased.
                                 This parameter must be a value between 1 and (max number of sectors - value of Initial sector)*/

  uint32_t Block;           /*!< Initial FLASH block to erase when Mass erase is disabled
                                 This parameter must be a value of @ref FLASH_DDL_EC_BLOCKS */

  uint32_t NbBlocks;        /*!< Number of blocks to be erased.
                                  This parameter must be a value between 1 and (max number of blocks - value of Initial block)*/

} DDL_FLASH_EraseInitTypeDef;

/**
  * @brief  FLASH Option Bytes USER Config
  */
typedef struct
{
  uint32_t Iwdt;         /*!< Option byte to be configured.
                              This parameter can be a value of @ref FLASH_DDL_EC_OB_IWDT */

  uint32_t StopEn;       /*!< Enable/Disable reset event when entering STOP mode.
                                This parameter can be a value of @arg ENABLE or @arg DISABLE */

  uint32_t StdbyEn;      /*!< Enable/Disable reset event when entering Standby mode.
                              This parameter can be a value of @arg ENABLE or @arg DISABLE */
} DDL_FLASH_OB_USERConfig;

/**
  * @brief  FLASH Option Bytes Program structure definition
  */
typedef struct
{
  uint32_t OptionType;   /*!< Option byte to be configured.
                              This parameter can be a value of @ref FLASH_DDL_EC_Option_Type */

  uint32_t WRPState;     /*!< Write protection activation or deactivation.
                              This parameter can be a value of @ref FLASH_DDL_EC_WRP_State */

  uint32_t WRPSector;    /*!< Specifies the sector(s) to be write protected.
                              The value of this parameter depend on device used within the same series
                              This parameter must be a value of @ref FLASH_DDL_EC_OB_WRP */

  uint32_t RDPLevel;     /*!< Set the read protection level.
                              This parameter can be a value of @ref FLASH_DDL_EC_OB_RDP */

  uint32_t BORLevel;     /*!< Set the BOR Level.
                              This parameter can be a value of @ref FLASH_DDL_EC_OB_BOR_LEVEL */

  DDL_FLASH_OB_USERConfig  USERConfig;   /*!< Program the FLASH User Option Byte: IWDT_SW / RST_STOP_EN / RST_STDBY_EN. */

  uint32_t DataWRPState;  /*!< Write protection activation or deactivation.
                              This parameter can be a value of @arg ENABLE or @arg DISABLE */

  uint32_t DataRDPState;  /*!< Read protection activation or deactivation.
                              This parameter can be a value of @arg ENABLE or @arg DISABLE */

  uint32_t SysInfoBootSel; /*!< Set the System Info Boot selection.
                              This parameter can be a value of @ref FLASH_DDL_EC_OB_SYSINFO_BOOT */
} DDL_FLASH_OBProgramInitTypeDef;

/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/** @defgroup FLASH_DDL_Exported_Macros FLASH Exported Macros
  * @{
  */

/** @defgroup FLASH_DDL_EC_OPERATION_MASK FLASH Operation Mask
  * @{
  */
#define DDL_FLASH_OPERATION_MASK        (FLASH_CTRL_PG | FLASH_CTRL_SERS | FLASH_CTRL_DSERS | FLASH_CTRL_BERS | FLASH_CTRL_MERS)  /*!< FLASH Operation Mask */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_Type_Program FLASH Type Program
  * @{
  */
#define DDL_FLASH_TYPEPROGRAM_BYTE        0x00000000U  /*!< Program byte (8-bit) at a specified address           */
#define DDL_FLASH_TYPEPROGRAM_HALFWORD    0x00000001U  /*!< Program a half-word (16-bit) at a specified address   */
#define DDL_FLASH_TYPEPROGRAM_WORD        0x00000002U  /*!< Program a word (32-bit) at a specified address        */
#define DDL_FLASH_TYPEPROGRAM_DOUBLEWORD  0x00000003U  /*!< Program a double word (64-bit) at a specified address */
#define DDL_FLASH_TYPEPROGRAM_QUADWORD    0x00000004U  /*!< Program a quad word (128-bit) at a specified address  */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_Type_Erase FLASH Type Erase
  * @{
  */
#define DDL_FLASH_TYPEERASE_SECTORS         0x00000000U  /*!< Sectors erase only            */
#define DDL_FLASH_TYPEERASE_MASSERASE       0x00000001U  /*!< Flash Mass erase activation   */
#define DDL_FLASH_TYPEERASE_BLOCKSERASE     0x00000002U  /*!< Flash Blocks erase activation */
#define DDL_FLASH_TYPEERASE_DATASECTORS     0x00000003U  /*!< Flash Data Sectors erase      */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_BLOCKS FLASH Blocks
  * @{
  */
#define DDL_FLASH_BLOCK_TOTAL 32U
#define DDL_FLASH_BLOCK_0     0U  /*!< BLOCK 0   */
#define DDL_FLASH_BLOCK_1     1U  /*!< BLOCK 1   */
#define DDL_FLASH_BLOCK_2     2U  /*!< BLOCK 2   */
#define DDL_FLASH_BLOCK_3     3U  /*!< BLOCK 3   */
#define DDL_FLASH_BLOCK_4     4U  /*!< BLOCK 4   */
#define DDL_FLASH_BLOCK_5     5U  /*!< BLOCK 5   */
#define DDL_FLASH_BLOCK_6     6U  /*!< BLOCK 6   */
#define DDL_FLASH_BLOCK_7     7U  /*!< BLOCK 7   */
#define DDL_FLASH_BLOCK_8     8U  /*!< BLOCK 8   */
#define DDL_FLASH_BLOCK_9     9U  /*!< BLOCK 9   */
#define DDL_FLASH_BLOCK_10    10U /*!< BLOCK 10  */
#define DDL_FLASH_BLOCK_11    11U /*!< BLOCK 11  */
#define DDL_FLASH_BLOCK_12    12U /*!< BLOCK 12  */
#define DDL_FLASH_BLOCK_13    13U /*!< BLOCK 13  */
#define DDL_FLASH_BLOCK_14    14U /*!< BLOCK 14  */
#define DDL_FLASH_BLOCK_15    15U /*!< BLOCK 15  */
#define DDL_FLASH_BLOCK_16    16U /*!< BLOCK 16  */
#define DDL_FLASH_BLOCK_17    17U /*!< BLOCK 17  */
#define DDL_FLASH_BLOCK_18    18U /*!< BLOCK 18  */
#define DDL_FLASH_BLOCK_19    19U /*!< BLOCK 19  */
#define DDL_FLASH_BLOCK_20    20U /*!< BLOCK 20  */
#define DDL_FLASH_BLOCK_21    21U /*!< BLOCK 21  */
#define DDL_FLASH_BLOCK_22    22U /*!< BLOCK 22  */
#define DDL_FLASH_BLOCK_23    23U /*!< BLOCK 23  */
#define DDL_FLASH_BLOCK_24    24U /*!< BLOCK 24  */
#define DDL_FLASH_BLOCK_25    25U /*!< BLOCK 25  */
#define DDL_FLASH_BLOCK_26    26U /*!< BLOCK 26  */
#define DDL_FLASH_BLOCK_27    27U /*!< BLOCK 27  */
#define DDL_FLASH_BLOCK_28    28U /*!< BLOCK 28  */
#define DDL_FLASH_BLOCK_29    29U /*!< BLOCK 29  */
#define DDL_FLASH_BLOCK_30    30U /*!< BLOCK 30  */
#define DDL_FLASH_BLOCK_31    31U /*!< BLOCK 31  */

/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_Sectors FLASH Sectors
  * @{
  */
#define DDL_FLASH_SECTOR_TOTAL 255U
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_DataSectors FLASH Data Sectors
  * @{
  */
#define DDL_FLASH_DATASECTOR_TOTAL  4U
#define DDL_FLASH_DATASECTOR_0      0U
#define DDL_FLASH_DATASECTOR_1      1U
#define DDL_FLASH_DATASECTOR_2      2U
#define DDL_FLASH_DATASECTOR_3      3U
#define DDL_FLASH_DATASECTOR_4      4U
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_Option_Type FLASH Option Type
  * @{
  */
#define DDL_OPTIONBYTE_WRP            0x00000001U   /*!< WRP option byte configuration  */
#define DDL_OPTIONBYTE_RDP            0x00000002U   /*!< RDP option byte configuration  */
#define DDL_OPTIONBYTE_USER           0x00000004U   /*!< USER option byte configuration */
#define DDL_OPTIONBYTE_BOR            0x00000008U   /*!< BOR option byte configuration  */
#define DDL_OPTIONBYTE_DATA_RDP       0x00000010U   /*!< DATA RDP option byte configuration  */
#define DDL_OPTIONBYTE_DATA_WRP       0x00000020U   /*!< DATA WRP option byte configuration  */
#define DDL_OPTIONBYTE_SYSINFO_BOOT   0x00000040U   /*!< SYSINFO_BOOT option byte configuration  */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_WRP_State FLASH WRP State
  * @{
  */
#define DDL_OB_WRPSTATE_DISABLE       0x00000000U  /*!< Disable the write protection of the desired bank 1 sectors */
#define DDL_OB_WRPSTATE_ENABLE        0x00000001U  /*!< Enable the write protection of the desired bank 1 sectors  */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_LATENCY FLASH Latency
  * @{
  */
#define DDL_FLASH_LATENCY_0                FLASH_ACCTRL_WAITP_0WS
#define DDL_FLASH_LATENCY_1                FLASH_ACCTRL_WAITP_1WS
#define DDL_FLASH_LATENCY_2                FLASH_ACCTRL_WAITP_2WS
#define DDL_FLASH_LATENCY_3                FLASH_ACCTRL_WAITP_3WS
#define DDL_FLASH_LATENCY_4                FLASH_ACCTRL_WAITP_4WS
#define DDL_FLASH_LATENCY_5                FLASH_ACCTRL_WAITP_5WS
#define DDL_FLASH_LATENCY_6                FLASH_ACCTRL_WAITP_6WS
#define DDL_FLASH_LATENCY_7                FLASH_ACCTRL_WAITP_7WS
#define DDL_FLASH_LATENCY_8                FLASH_ACCTRL_WAITP_8WS
#define DDL_FLASH_LATENCY_9                FLASH_ACCTRL_WAITP_9WS
#define DDL_FLASH_LATENCY_10               FLASH_ACCTRL_WAITP_10WS
#define DDL_FLASH_LATENCY_11               FLASH_ACCTRL_WAITP_11WS
#define DDL_FLASH_LATENCY_12               FLASH_ACCTRL_WAITP_12WS
#define DDL_FLASH_LATENCY_13               FLASH_ACCTRL_WAITP_13WS
#define DDL_FLASH_LATENCY_14               FLASH_ACCTRL_WAITP_14WS
#define DDL_FLASH_LATENCY_15               FLASH_ACCTRL_WAITP_15WS
#define DDL_FLASH_LATENCY_16               FLASH_ACCTRL_WAITP_16WS
#define DDL_FLASH_LATENCY_17               FLASH_ACCTRL_WAITP_17WS
#define DDL_FLASH_LATENCY_18               FLASH_ACCTRL_WAITP_18WS
#define DDL_FLASH_LATENCY_19               FLASH_ACCTRL_WAITP_19WS
#define DDL_FLASH_LATENCY_20               FLASH_ACCTRL_WAITP_20WS
#define DDL_FLASH_LATENCY_21               FLASH_ACCTRL_WAITP_21WS
#define DDL_FLASH_LATENCY_22               FLASH_ACCTRL_WAITP_22WS
#define DDL_FLASH_LATENCY_23               FLASH_ACCTRL_WAITP_23WS
#define DDL_FLASH_LATENCY_24               FLASH_ACCTRL_WAITP_24WS
#define DDL_FLASH_LATENCY_25               FLASH_ACCTRL_WAITP_25WS
#define DDL_FLASH_LATENCY_26               FLASH_ACCTRL_WAITP_26WS
#define DDL_FLASH_LATENCY_27               FLASH_ACCTRL_WAITP_27WS
#define DDL_FLASH_LATENCY_28               FLASH_ACCTRL_WAITP_28WS
#define DDL_FLASH_LATENCY_29               FLASH_ACCTRL_WAITP_29WS
#define DDL_FLASH_LATENCY_30               FLASH_ACCTRL_WAITP_30WS
#define DDL_FLASH_LATENCY_31               FLASH_ACCTRL_WAITP_31WS
#define DDL_FLASH_LATENCY_32               FLASH_ACCTRL_WAITP_32WS
#define DDL_FLASH_LATENCY_33               FLASH_ACCTRL_WAITP_33WS
#define DDL_FLASH_LATENCY_34               FLASH_ACCTRL_WAITP_34WS
#define DDL_FLASH_LATENCY_35               FLASH_ACCTRL_WAITP_35WS
#define DDL_FLASH_LATENCY_36               FLASH_ACCTRL_WAITP_36WS
#define DDL_FLASH_LATENCY_37               FLASH_ACCTRL_WAITP_37WS
#define DDL_FLASH_LATENCY_38               FLASH_ACCTRL_WAITP_38WS
#define DDL_FLASH_LATENCY_39               FLASH_ACCTRL_WAITP_39WS
#define DDL_FLASH_LATENCY_40               FLASH_ACCTRL_WAITP_40WS
#define DDL_FLASH_LATENCY_41               FLASH_ACCTRL_WAITP_41WS
#define DDL_FLASH_LATENCY_42               FLASH_ACCTRL_WAITP_42WS
#define DDL_FLASH_LATENCY_43               FLASH_ACCTRL_WAITP_43WS
#define DDL_FLASH_LATENCY_44               FLASH_ACCTRL_WAITP_44WS
#define DDL_FLASH_LATENCY_45               FLASH_ACCTRL_WAITP_45WS
#define DDL_FLASH_LATENCY_46               FLASH_ACCTRL_WAITP_46WS
#define DDL_FLASH_LATENCY_47               FLASH_ACCTRL_WAITP_47WS
#define DDL_FLASH_LATENCY_48               FLASH_ACCTRL_WAITP_48WS
#define DDL_FLASH_LATENCY_49               FLASH_ACCTRL_WAITP_49WS
#define DDL_FLASH_LATENCY_50               FLASH_ACCTRL_WAITP_50WS
#define DDL_FLASH_LATENCY_51               FLASH_ACCTRL_WAITP_51WS
#define DDL_FLASH_LATENCY_52               FLASH_ACCTRL_WAITP_52WS
#define DDL_FLASH_LATENCY_53               FLASH_ACCTRL_WAITP_53WS
#define DDL_FLASH_LATENCY_54               FLASH_ACCTRL_WAITP_54WS
#define DDL_FLASH_LATENCY_55               FLASH_ACCTRL_WAITP_55WS
#define DDL_FLASH_LATENCY_56               FLASH_ACCTRL_WAITP_56WS
#define DDL_FLASH_LATENCY_57               FLASH_ACCTRL_WAITP_57WS
#define DDL_FLASH_LATENCY_58               FLASH_ACCTRL_WAITP_58WS
#define DDL_FLASH_LATENCY_59               FLASH_ACCTRL_WAITP_59WS
#define DDL_FLASH_LATENCY_60               FLASH_ACCTRL_WAITP_60WS
#define DDL_FLASH_LATENCY_61               FLASH_ACCTRL_WAITP_61WS
#define DDL_FLASH_LATENCY_62               FLASH_ACCTRL_WAITP_62WS
#define DDL_FLASH_LATENCY_63               FLASH_ACCTRL_WAITP_63WS
#define DDL_FLASH_LATENCY_64               FLASH_ACCTRL_WAITP_64WS
#define DDL_FLASH_LATENCY_65               FLASH_ACCTRL_WAITP_65WS
#define DDL_FLASH_LATENCY_66               FLASH_ACCTRL_WAITP_66WS
#define DDL_FLASH_LATENCY_67               FLASH_ACCTRL_WAITP_67WS
#define DDL_FLASH_LATENCY_68               FLASH_ACCTRL_WAITP_68WS
#define DDL_FLASH_LATENCY_69               FLASH_ACCTRL_WAITP_69WS
#define DDL_FLASH_LATENCY_70               FLASH_ACCTRL_WAITP_70WS
#define DDL_FLASH_LATENCY_71               FLASH_ACCTRL_WAITP_71WS
#define DDL_FLASH_LATENCY_72               FLASH_ACCTRL_WAITP_72WS
#define DDL_FLASH_LATENCY_73               FLASH_ACCTRL_WAITP_73WS
#define DDL_FLASH_LATENCY_74               FLASH_ACCTRL_WAITP_74WS
#define DDL_FLASH_LATENCY_75               FLASH_ACCTRL_WAITP_75WS
#define DDL_FLASH_LATENCY_76               FLASH_ACCTRL_WAITP_76WS
#define DDL_FLASH_LATENCY_77               FLASH_ACCTRL_WAITP_77WS
#define DDL_FLASH_LATENCY_78               FLASH_ACCTRL_WAITP_78WS
#define DDL_FLASH_LATENCY_79               FLASH_ACCTRL_WAITP_79WS
#define DDL_FLASH_LATENCY_80               FLASH_ACCTRL_WAITP_80WS
#define DDL_FLASH_LATENCY_81               FLASH_ACCTRL_WAITP_81WS
#define DDL_FLASH_LATENCY_82               FLASH_ACCTRL_WAITP_82WS
#define DDL_FLASH_LATENCY_83               FLASH_ACCTRL_WAITP_83WS
#define DDL_FLASH_LATENCY_84               FLASH_ACCTRL_WAITP_84WS
#define DDL_FLASH_LATENCY_85               FLASH_ACCTRL_WAITP_85WS
#define DDL_FLASH_LATENCY_86               FLASH_ACCTRL_WAITP_86WS
#define DDL_FLASH_LATENCY_87               FLASH_ACCTRL_WAITP_87WS
#define DDL_FLASH_LATENCY_88               FLASH_ACCTRL_WAITP_88WS
#define DDL_FLASH_LATENCY_89               FLASH_ACCTRL_WAITP_89WS
#define DDL_FLASH_LATENCY_90               FLASH_ACCTRL_WAITP_90WS
#define DDL_FLASH_LATENCY_91               FLASH_ACCTRL_WAITP_91WS
#define DDL_FLASH_LATENCY_92               FLASH_ACCTRL_WAITP_92WS
#define DDL_FLASH_LATENCY_93               FLASH_ACCTRL_WAITP_93WS
#define DDL_FLASH_LATENCY_94               FLASH_ACCTRL_WAITP_94WS
#define DDL_FLASH_LATENCY_95               FLASH_ACCTRL_WAITP_95WS
#define DDL_FLASH_LATENCY_96               FLASH_ACCTRL_WAITP_96WS
#define DDL_FLASH_LATENCY_97               FLASH_ACCTRL_WAITP_97WS
#define DDL_FLASH_LATENCY_98               FLASH_ACCTRL_WAITP_98WS
#define DDL_FLASH_LATENCY_99               FLASH_ACCTRL_WAITP_99WS
#define DDL_FLASH_LATENCY_100              FLASH_ACCTRL_WAITP_100WS
#define DDL_FLASH_LATENCY_101              FLASH_ACCTRL_WAITP_101WS
#define DDL_FLASH_LATENCY_102              FLASH_ACCTRL_WAITP_102WS
#define DDL_FLASH_LATENCY_103              FLASH_ACCTRL_WAITP_103WS
#define DDL_FLASH_LATENCY_104              FLASH_ACCTRL_WAITP_104WS
#define DDL_FLASH_LATENCY_105              FLASH_ACCTRL_WAITP_105WS
#define DDL_FLASH_LATENCY_106              FLASH_ACCTRL_WAITP_106WS
#define DDL_FLASH_LATENCY_107              FLASH_ACCTRL_WAITP_107WS
#define DDL_FLASH_LATENCY_108              FLASH_ACCTRL_WAITP_108WS
#define DDL_FLASH_LATENCY_109              FLASH_ACCTRL_WAITP_109WS
#define DDL_FLASH_LATENCY_110              FLASH_ACCTRL_WAITP_110WS
#define DDL_FLASH_LATENCY_111              FLASH_ACCTRL_WAITP_111WS
#define DDL_FLASH_LATENCY_112              FLASH_ACCTRL_WAITP_112WS
#define DDL_FLASH_LATENCY_113              FLASH_ACCTRL_WAITP_113WS
#define DDL_FLASH_LATENCY_114              FLASH_ACCTRL_WAITP_114WS
#define DDL_FLASH_LATENCY_115              FLASH_ACCTRL_WAITP_115WS
#define DDL_FLASH_LATENCY_116              FLASH_ACCTRL_WAITP_116WS
#define DDL_FLASH_LATENCY_117              FLASH_ACCTRL_WAITP_117WS
#define DDL_FLASH_LATENCY_118              FLASH_ACCTRL_WAITP_118WS
#define DDL_FLASH_LATENCY_119              FLASH_ACCTRL_WAITP_119WS
#define DDL_FLASH_LATENCY_120              FLASH_ACCTRL_WAITP_120WS
#define DDL_FLASH_LATENCY_121              FLASH_ACCTRL_WAITP_121WS
#define DDL_FLASH_LATENCY_122              FLASH_ACCTRL_WAITP_122WS
#define DDL_FLASH_LATENCY_123              FLASH_ACCTRL_WAITP_123WS
#define DDL_FLASH_LATENCY_124              FLASH_ACCTRL_WAITP_124WS
#define DDL_FLASH_LATENCY_125              FLASH_ACCTRL_WAITP_125WS
#define DDL_FLASH_LATENCY_126              FLASH_ACCTRL_WAITP_126WS
#define DDL_FLASH_LATENCY_127              FLASH_ACCTRL_WAITP_127WS
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_PREFETCH_MODE FLASH Prefetch Mode
  * @{
  */
#define FLASH_PREFETCH_MODE_DOUBLE_ACCESS    0x00000000U                          /* Prefetch initiated after cacheline accessed twice */
#define FLASH_PREFETCH_MODE_SINGLE_ACCESS    ((uint32_t)FLASH_ACCTRL_PREF_CTRL) /* Prefetch initiated after single cache/buffer access */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_READ_INT_MODE FLASH Read Interrupt Mode
  * @{
  */
#define DDL_FLASH_READ_INT_MODE_FAST    0x00000000U                            /* Read Interrupt Fast Mode */
#define DDL_FLASH_READ_INT_MODE_SLOW    ((uint32_t)FLASH_ACCTRL_RD_INT_TIMING) /* Read Interrupt Slow Mode */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_FLAG FLASH Flag definition
  * @{
  */
#define DDL_FLASH_FLAG_EOP                 FLASH_STS_OPRCMP             /*!< FLASH End of Operation flag               */
#define DDL_FLASH_FLAG_OPERR               FLASH_STS_OPRERR             /*!< FLASH Operation Error flag                */
#define DDL_FLASH_FLAG_PGVERR              FLASH_STS_PGVERR             /*!< FLASH Programming Validation Error flag   */
#define DDL_FLASH_FLAG_OPTERR              FLASH_STS_OPTERR             /*!< FLASH Option Byte Error flag              */
#define DDL_FLASH_FLAG_WRPERR              FLASH_STS_WPROTERR           /*!< FLASH Write protected error flag          */
#define DDL_FLASH_FLAG_PGAERR              FLASH_STS_PGALGERR           /*!< FLASH Programming Alignment error flag    */
#define DDL_FLASH_FLAG_PGPERR              FLASH_STS_PGPRLERR           /*!< FLASH Programming Parallelism error flag  */
#define DDL_FLASH_FLAG_PGSERR              FLASH_STS_PGSEQERR           /*!< FLASH Programming Sequence error flag     */
#define DDL_FLASH_FLAG_BSY                 FLASH_STS_BUSY               /*!< FLASH Busy flag                           */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_Error_Code FLASH Error Code
  * @brief    FLASH Error Code
  * @{
  */
#define DDL_FLASH_ERROR_NONE         0x00000000U    /*!< No error                      */
#define DDL_FLASH_ERROR_RD           0x00000001U    /*!< Read Protection error         */
#define DDL_FLASH_ERROR_PGS          0x00000002U    /*!< Programming Sequence error    */
#define DDL_FLASH_ERROR_PGP          0x00000004U    /*!< Programming Parallelism error */
#define DDL_FLASH_ERROR_PGA          0x00000008U    /*!< Programming Alignment error   */
#define DDL_FLASH_ERROR_WRP          0x00000010U    /*!< Write protection error        */
#define DDL_FLASH_ERROR_OPERATION    0x00000020U    /*!< Operation Error               */
#define DDL_FLASH_ERROR_PGV          0x00000040U    /*!< Programming Validation error  */
#define DDL_FLASH_ERROR_OPT          0x00000080U    /*!< Option Byte error             */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_Program_Parallelism FLASH Program Parallelism
  * @{
  */
#define DDL_FLASH_PSIZE_BYTE           0x00000000U
#define DDL_FLASH_PSIZE_HALF_WORD      FLASH_CTRL_PGSIZE_0
#define DDL_FLASH_PSIZE_WORD           (FLASH_CTRL_PGSIZE_1)
#define DDL_FLASH_PSIZE_DOUBLE_WORD    (FLASH_CTRL_PGSIZE_1 | FLASH_CTRL_PGSIZE_0)
#define DDL_FLASH_PSIZE_QUAD_WORD      (FLASH_CTRL_PGSIZE_2)
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_KEY FLASH Keys
  * @{
  */
#define DDL_FLASH_RDP_KEY            ((uint16_t)0x00A5)
#define DDL_FLASH_KEY1               0x45670123U
#define DDL_FLASH_KEY2               0xCDEF89ABU
#define DDL_FLASH_OPT_KEY1           0x08192A3BU
#define DDL_FLASH_OPT_KEY2           0x4C5D6E7FU
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_OB_BOR_LEVEL FLASH BOR Level
  * @{
  */
#define DDL_FLASH_OB_BOR_LEVEL3          ((uint8_t)0x00)  /*!< Supply voltage ranges from 2.70 to 3.60 V */
#define DDL_FLASH_OB_BOR_LEVEL2          ((uint8_t)0x04)  /*!< Supply voltage ranges from 2.40 to 2.70 V */
#define DDL_FLASH_OB_BOR_LEVEL1          ((uint8_t)0x08)  /*!< Supply voltage ranges from 2.10 to 2.40 V */
#define DDL_FLASH_OB_BOR_OFF             ((uint8_t)0x0C)  /*!< Supply voltage ranges from 1.8 to 2.10 V */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_OB_IWDT FLASH Option Bytes IWatchdog
  * @{
  */
#define DDL_FLASH_OB_IWDT_HW                     ((uint8_t)0x00)                    /*!< Hardware IWDT selected */
#define DDL_FLASH_OB_IWDT_SW                     ((uint8_t)FLASH_OPTCTRL1_WDTSEL)   /*!< Software IWDT selected */

/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_OB_RDP FLASH Option Bytes Read Protection
  * @{
  */
#define DDL_FLASH_OB_RDP_LEVEL_0   ((uint8_t)0xAA)
#define DDL_FLASH_OB_RDP_LEVEL_1   ((uint8_t)0x55)
#define DDL_FLASH_OB_RDP_LEVEL_2   ((uint8_t)0xCC) /*!< Warning: When enabling read protection level 2
                                              it s no more possible to go back to level 1 or 0 */
/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_OB_SYSINFO_BOOT FLASH Option Bytes System Info Boot
  * @{
  */
#define DDL_FLASH_OB_BOOTREMAP_SYSINFO_1   (0x00000000U)                  /*!< System Info mapped at 0x1FFF0000 */
#define DDL_FLASH_OB_BOOTREMAP_SYSINFO_2   (FLASH_OPTCTRL1_SYS_BOOT_SEL)  /*!< System Info mapped at 0x1FFF8400 */

/**
  * @}
  */

/** @defgroup FLASH_DDL_EC_OB_WRP FLASH Option Bytes Write Protection
  * @{
  */
#define DDL_FLASH_OB_WRP_BLOCK_0      0x00000001U /*!< Write protection of Block0     */
#define DDL_FLASH_OB_WRP_BLOCK_1      0x00000002U /*!< Write protection of Block1     */
#define DDL_FLASH_OB_WRP_BLOCK_2      0x00000004U /*!< Write protection of Block2     */
#define DDL_FLASH_OB_WRP_BLOCK_3      0x00000008U /*!< Write protection of Block3     */
#define DDL_FLASH_OB_WRP_BLOCK_4      0x00000010U /*!< Write protection of Block4     */
#define DDL_FLASH_OB_WRP_BLOCK_5      0x00000020U /*!< Write protection of Block5     */
#define DDL_FLASH_OB_WRP_BLOCK_6      0x00000040U /*!< Write protection of Block6     */
#define DDL_FLASH_OB_WRP_BLOCK_7      0x00000080U /*!< Write protection of Block7     */
#define DDL_FLASH_OB_WRP_BLOCK_8      0x00000100U /*!< Write protection of Block8     */
#define DDL_FLASH_OB_WRP_BLOCK_9      0x00000200U /*!< Write protection of Block9     */
#define DDL_FLASH_OB_WRP_BLOCK_10     0x00000400U /*!< Write protection of Block10    */
#define DDL_FLASH_OB_WRP_BLOCK_11     0x00000800U /*!< Write protection of Block11    */
#define DDL_FLASH_OB_WRP_BLOCK_12     0x00001000U /*!< Write protection of Block12    */
#define DDL_FLASH_OB_WRP_BLOCK_13     0x00002000U /*!< Write protection of Block13    */
#define DDL_FLASH_OB_WRP_BLOCK_14     0x00004000U /*!< Write protection of Block14    */
#define DDL_FLASH_OB_WRP_BLOCK_15     0x00008000U /*!< Write protection of Block15    */
#define DDL_FLASH_OB_WRP_BLOCK_16     0x00010000U /*!< Write protection of Block16    */
#define DDL_FLASH_OB_WRP_BLOCK_17     0x00020000U /*!< Write protection of Block17    */
#define DDL_FLASH_OB_WRP_BLOCK_18     0x00040000U /*!< Write protection of Block18    */
#define DDL_FLASH_OB_WRP_BLOCK_19     0x00080000U /*!< Write protection of Block19    */
#define DDL_FLASH_OB_WRP_BLOCK_20     0x00100000U /*!< Write protection of Block20    */
#define DDL_FLASH_OB_WRP_BLOCK_21     0x00200000U /*!< Write protection of Block21    */
#define DDL_FLASH_OB_WRP_BLOCK_22     0x00400000U /*!< Write protection of Block22    */
#define DDL_FLASH_OB_WRP_BLOCK_23     0x00800000U /*!< Write protection of Block23    */
#define DDL_FLASH_OB_WRP_BLOCK_24     0x01000000U /*!< Write protection of Block24    */
#define DDL_FLASH_OB_WRP_BLOCK_25     0x02000000U /*!< Write protection of Block25    */
#define DDL_FLASH_OB_WRP_BLOCK_26     0x04000000U /*!< Write protection of Block26    */
#define DDL_FLASH_OB_WRP_BLOCK_27     0x08000000U /*!< Write protection of Block27    */
#define DDL_FLASH_OB_WRP_BLOCK_28     0x10000000U /*!< Write protection of Block28    */
#define DDL_FLASH_OB_WRP_BLOCK_29     0x20000000U /*!< Write protection of Block29    */
#define DDL_FLASH_OB_WRP_BLOCK_30     0x40000000U /*!< Write protection of Block30    */
#define DDL_FLASH_OB_WRP_BLOCK_31     0x80000000U /*!< Write protection of Block31    */
#define DDL_FLASH_OB_WRP_BLOCK_All    0xFFFFFFFFU /*!< Write protection of all Blocks */

/*-----------------------------------------------------------------------------------------------------*/

/**
  * @}
  */



/** @defgroup FLASH_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_FLASH_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_FLASH_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_DDL_Exported_Functions FLASH Exported Functions
  * @{
  */


/**
 * @brief   Set FLASH Latency
 * @param   waitp  Value (DDL_FLASH_LATENCY_0~DDL_FLASH_LATENCY_127)
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_SetLatency(uint32_t waitp)
{
    MODIFY_REG(FLASH->ACCTRL, FLASH_ACCTRL_WAITP, waitp);
}

/**
 * @brief   Get FLASH Latency
 * @retval  Value (DDL_FLASH_LATENCY_0~DDL_FLASH_LATENCY_127)
 */
__STATIC_INLINE uint32_t DDL_FLASH_GetLatency(void)
{
    return READ_BIT(FLASH->ACCTRL, FLASH_ACCTRL_WAITP);
}

/**
 * @brief   Enable FLASH Prefetch
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnablePrefetch(void)
{
    SET_BIT(FLASH->ACCTRL, FLASH_ACCTRL_PREFEN);
}

/**
 * @brief   Disable FLASH Prefetch
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisablePrefetch(void)
{
    CLEAR_BIT(FLASH->ACCTRL, FLASH_ACCTRL_PREFEN);
}

/**
 * @brief   Check if FLASH Prefetch is enabled
 * @retval  State of bit (1 or 0)
 */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabled_Prefetch(void)
{
    return ((READ_BIT(FLASH->ACCTRL, FLASH_ACCTRL_PREFEN) == FLASH_ACCTRL_PREFEN) ? 1UL : 0UL);
}

/**
 * @brief   Enable FLASH Instruction Cache
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableInstCache(void)
{
    SET_BIT(FLASH->ACCTRL, FLASH_ACCTRL_ICACHEEN);
}

/**
 * @brief   Disable FLASH Instruction Cache
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableInstCache(void)
{
    CLEAR_BIT(FLASH->ACCTRL, FLASH_ACCTRL_ICACHEEN);
}

/**
 * @brief   Enable FLASH Data Cache
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableDataCache(void)
{
    SET_BIT(FLASH->ACCTRL, FLASH_ACCTRL_DCACHEEN);
}

/**
 * @brief   Disable FLASH Data Cache
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableDataCache(void)
{
    CLEAR_BIT(FLASH->ACCTRL, FLASH_ACCTRL_DCACHEEN);
}

/**
 * @brief   Reset FLASH Instruction Cache
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableInstCacheReset(void)
{
    SET_BIT(FLASH->ACCTRL, FLASH_ACCTRL_ICACHERST);
    CLEAR_BIT(FLASH->ACCTRL, FLASH_ACCTRL_ICACHERST);
}

/**
 * @brief   Reset FLASH Data Cache
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableDataCacheReset(void)
{
    SET_BIT(FLASH->ACCTRL, FLASH_ACCTRL_DCACHERST);
    CLEAR_BIT(FLASH->ACCTRL, FLASH_ACCTRL_DCACHERST);
}

/**
 * @brief   Enable prefetch policy control
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnablePrefetchPolicyCtrl(void)
{
    SET_BIT(FLASH->ACCTRL, FLASH_ACCTRL_PREF_CTRL);
}

/**
 * @brief   Disable prefetch policy control
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisablePrefetchPolicyCtrl(void)
{
    CLEAR_BIT(FLASH->ACCTRL, FLASH_ACCTRL_PREF_CTRL);
}

/**
 * @brief   Get FLASH Status Flag
 * @param   flag This parameter can be one of the following values:
 *          @arg @ref DDL_FLASH_FLAG_EOP
 *          @arg @ref DDL_FLASH_FLAG_OPERR
 *          @arg @ref DDL_FLASH_FLAG_PGVERR
 *          @arg @ref DDL_FLASH_FLAG_OPTERR
 *          @arg @ref DDL_FLASH_FLAG_WRPERR
 *          @arg @ref DDL_FLASH_FLAG_PGAERR
 *          @arg @ref DDL_FLASH_FLAG_PGPERR
 *          @arg @ref DDL_FLASH_FLAG_PGSERR
 *          @arg @ref DDL_FLASH_FLAG_BSY
 * @retval  State of bit (1 or 0)
 */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag(uint32_t flag)
{
    return ((READ_BIT(FLASH->STS, flag) == flag) ? 1UL : 0UL);
}

/**
 * @brief   Clear FLASH Status Flag
 * @param   flag This parameter can be one of the following values:
 *          @arg @ref DDL_FLASH_FLAG_EOP
 *          @arg @ref DDL_FLASH_FLAG_OPERR
 *          @arg @ref DDL_FLASH_FLAG_PGVERR
 *          @arg @ref DDL_FLASH_FLAG_WRPERR
 *          @arg @ref DDL_FLASH_FLAG_PGAERR
 *          @arg @ref DDL_FLASH_FLAG_PGPERR
 *          @arg @ref DDL_FLASH_FLAG_PGSERR
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_ClearFlag(uint32_t flag)
{
    SET_BIT(FLASH->STS, flag);
}

/**
 * @brief   Enable FLASH Programming
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableProgram(void)
{
    MODIFY_REG(FLASH->CTRL, DDL_FLASH_OPERATION_MASK, FLASH_CTRL_PG);
}

/**
 * @brief   Disable FLASH Programming
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableProgram(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_PG);
}

/**
 * @brief   Enable FLASH Sector Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableSectorErase(void)
{
    MODIFY_REG(FLASH->CTRL, DDL_FLASH_OPERATION_MASK, FLASH_CTRL_SERS);
}

/**
 * @brief   Disable FLASH Sector Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableSectorErase(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_SERS);
}

/**
 * @brief   Enable FLASH Data Sector Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableDataSectorErase(void)
{
    MODIFY_REG(FLASH->CTRL, DDL_FLASH_OPERATION_MASK, FLASH_CTRL_DSERS);
}

/**
 * @brief   Disable FLASH Data Sector Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableDataSectorErase(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_DSERS);
}

/**
 * @brief   Enable FLASH Block Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableBlockErase(void)
{
    MODIFY_REG(FLASH->CTRL, DDL_FLASH_OPERATION_MASK, FLASH_CTRL_BERS);
}

/**
 * @brief   Disable FLASH Block Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableBlockErase(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_BERS);
}

/**
 * @brief   Enable FLASH Mass Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_EnableMassErase(void)
{
    MODIFY_REG(FLASH->CTRL, DDL_FLASH_OPERATION_MASK, FLASH_CTRL_MERS);
}

/**
 * @brief   Disable FLASH Mass Erase
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_DisableMassErase(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_MERS);
}

/**
 * @brief   Set FLASH Sector Number
 * @param   snum   Value (0~255)
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_SetSectorNumber(uint32_t snum)
{
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_SNUM, (snum << FLASH_CTRL_SNUM_Pos));
}

/**
 * @brief   Get FLASH Sector Number
 * @retval  Value (0~255)
 */
__STATIC_INLINE uint32_t DDL_FLASH_GetSectorNumber(void)
{
    return ((READ_BIT(FLASH->CTRL, FLASH_CTRL_SNUM)) >> FLASH_CTRL_SNUM_Pos);
}

/**
 * @brief   Set FLASH Program Size
 * @param   pgsize This parameter can be one of the following values:
 *          @arg @ref DDL_FLASH_PSIZE_BYTE
 *          @arg @ref DDL_FLASH_PSIZE_HALF_WORD
 *          @arg @ref DDL_FLASH_PSIZE_WORD
 *          @arg @ref DDL_FLASH_PSIZE_DOUBLE_WORD
 *          @arg @ref DDL_FLASH_PSIZE_QUAD_WORD
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_SetProgramSize(uint32_t pgsize)
{
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_PGSIZE, pgsize);
}

/**
 * @brief   Get FLASH Program Size
 * @retval  Returned value can be one of the following values:
 *          @arg @ref DDL_FLASH_PSIZE_BYTE
 *          @arg @ref DDL_FLASH_PSIZE_HALF_WORD
 *          @arg @ref DDL_FLASH_PSIZE_WORD
 *          @arg @ref DDL_FLASH_PSIZE_DOUBLE_WORD
 *          @arg @ref DDL_FLASH_PSIZE_QUAD_WORD
 */
__STATIC_INLINE uint32_t DDL_FLASH_GetProgramSize(void)
{
    return (READ_BIT(FLASH->CTRL, FLASH_CTRL_PGSIZE));
}

/**
 * @brief   Start FLASH Operation
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_Start(void)
{
    SET_BIT(FLASH->CTRL, FLASH_CTRL_START);
}


/**
  * @brief  Enable error interrupt
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_ERR(void)
{
    SET_BIT(FLASH->CTRL, FLASH_CTRL_ERRINTEN);
}

/**
  * @brief  Disable error interrupt
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_ERR(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_ERRINTEN);
}

/**
  * @brief  Check whether the error interrupt is enabled
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_ERR(void)
{
    return (READ_BIT(FLASH->CTRL, FLASH_CTRL_ERRINTEN) == (FLASH_CTRL_ERRINTEN));
}

/**
  * @brief  Enable Operation End Interrupt
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_OPE(void)
{
    SET_BIT(FLASH->CTRL, FLASH_CTRL_OPCINTEN);
}

/**
  * @brief  Disable Operation End Interrupt
  * @param  FLASHx FLASH Instance
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_OPE(void)
{
    CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_OPCINTEN);
}

/**
  * @brief  Check whether the operation complete interrupt is enabled
  * @param  FLASHx FLASH Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_OPE(void)
{
    return (READ_BIT(FLASH->CTRL, FLASH_CTRL_OPCINTEN) == (FLASH_CTRL_OPCINTEN));
}
/**
 * @brief   Lock FLASH Control Register
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_Lock(void)
{
    SET_BIT(FLASH->CTRL, FLASH_CTRL_LOCK);
}

/**
 * @brief   Unlock FLASH Control Register
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_Unlock(void)
{
    WRITE_REG(FLASH->KEY, DDL_FLASH_KEY1);
    WRITE_REG(FLASH->KEY, DDL_FLASH_KEY2);
}

/**
 * @brief   Lock the FLASH Option Control Registers access.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_Lock(void)
{
    SET_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL_OPTLOCK);
}

/**
 * @brief   Unlock the FLASH Option Control Registers access.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_Unlock(void)
{
    WRITE_REG(FLASH->OPTKEY, DDL_FLASH_OPT_KEY1);
    WRITE_REG(FLASH->OPTKEY, DDL_FLASH_OPT_KEY2);
}

/**
 * @brief   Launch the option byte loading.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_Launch(void)
{
    SET_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL_OPTSTART);
}

/**
 * @brief   Set FLASH BOR Level
 * @param   borlvl specifies the Option Bytes BOR Reset Level.
 *          This parameter can be one of the following values:
 *            @arg DDL_FLASH_OB_BOR_LEVEL3
 *            @arg DDL_FLASH_OB_BOR_LEVEL2
 *            @arg DDL_FLASH_OB_BOR_LEVEL1
 *            @arg DDL_FLASH_OB_BOR_OFF
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_BOR_LevelConfig(uint32_t borlvl)
{
    MODIFY_REG(FLASH->OPTCTRL1, FLASH_OPTCTRL1_BORLVL, borlvl);
}

/**
 * @brief   Get FLASH BOR Level
 * @retval  Returned value can be one of the following values:
 *          @arg @ref DDL_FLASH_OB_BOR_LEVEL3
 *          @arg @ref DDL_FLASH_OB_BOR_LEVEL2
 *          @arg @ref DDL_FLASH_OB_BOR_LEVEL1
 *          @arg @ref DDL_FLASH_OB_BOR_OFF
 */
__STATIC_INLINE uint32_t DDL_FLASH_OB_GetBOR(void)
{
    return (READ_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_BORLVL));
}

/**
 * @brief   Set FLASH Watchdog Select
 * @param   wdt This parameter can be one of the following values:
 *          @arg @ref DDL_FLASH_OB_IWDT_HW
 *          @arg @ref DDL_FLASH_OB_IWDT_SW
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_SetWDTSelect(uint32_t wdt)
{
    MODIFY_REG(FLASH->OPTCTRL1, FLASH_OPTCTRL1_WDTSEL, wdt);
}

/**
 * @brief   Get FLASH Watchdog Select
 * @retval  Returned value can be one of the following values:
 *          @arg @ref DDL_FLASH_OB_IWDT_HW
 *          @arg @ref DDL_FLASH_OB_IWDT_SW
 */
__STATIC_INLINE uint32_t DDL_FLASH_OB_GetWDTSelect(void)
{
    return (READ_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_WDTSEL));
}

/**
 * @brief   Enable reset event when entering STOP mode.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_EnableStopRST(void)
{
    CLEAR_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NRSTSTOP);
}

/**
 * @brief   Disable reset event when entering STOP mode.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_DisableStopRST(void)
{
    SET_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NRSTSTOP);
}

/**
 * @brief   Enable reset event when entering Standby mode.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_EnableStandbyRST(void)
{
    CLEAR_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NRSTSTDB);
}

/**
 * @brief   Disable reset event when entering Standby mode.
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_DisableStandbyRST(void)
{
    SET_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NRSTSTDB);
}

/**
 * @brief   Set FLASH Read Protect
 * @param   rplvl specifies the Option Bytes BOR Reset Level.
 *          This parameter can be one of the following values:
 *            @arg DDL_FLASH_OB_RDP_LEVEL_0
 *            @arg DDL_FLASH_OB_RDP_LEVEL_1
 *            @arg DDL_FLASH_OB_RDP_LEVEL_2
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_RDP_LevelConfig(uint32_t rplvl)
{
    MODIFY_REG(FLASH->OPTCTRL1, FLASH_OPTCTRL1_RPROT, rplvl << FLASH_OPTCTRL1_RPROT_Pos);
}

/**
 * @brief   Get FLASH Read Protect
 * @retval  Returned value can be one of the following values:
 *            @arg DDL_FLASH_OB_RDP_LEVEL_0
 *            @arg DDL_FLASH_OB_RDP_LEVEL_1
 *            @arg DDL_FLASH_OB_RDP_LEVEL_2
 */
__STATIC_INLINE uint32_t DDL_FLASH_OB_GetRDP(void)
{
    return ((READ_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_RPROT)) >> FLASH_OPTCTRL1_RPROT_Pos);
}

/**
 * @brief   Enable FLASH Data Sector Read Protect
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_EnableRDP_DS(void)
{
    CLEAR_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NDSRPROT);
}

/**
 * @brief   Disable FLASH Data Sector Read Protect
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_DisableRDP_DS(void)
{
    SET_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NDSRPROT);
}

/**
 * @brief   Enable FLASH Data Sector Write Protect
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_EnableWRP_DS(void)
{
    CLEAR_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NDSWPROT);
}

/**
 * @brief   Disable FLASH Data Sector Write Protect
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_DisableWRP_DS(void)
{
    SET_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_NDSWPROT);
}

/**
 * @brief   Set boot remapping for system info area
 * @param   sysinfo specifies the Option Bytes BOR Reset Level.
 *          This parameter can be one of the following values:
 *            @arg DDL_FLASH_OB_BOOTREMAP_SYSINFO_1
 *            @arg DDL_FLASH_OB_BOOTREMAP_SYSINFO_2
 * @retval  None
 */
__STATIC_INLINE void DDL_FLASH_OB_SetSysInfoBoot(uint32_t sysinfo)
{
    MODIFY_REG(FLASH->OPTCTRL1, FLASH_OPTCTRL1_SYS_BOOT_SEL, sysinfo);
}

/**
 * @brief   Get FLASH Read Protect
 * @retval  Returned value can be one of the following values:
 *            @arg DDL_FLASH_OB_BOOTREMAP_SYSINFO_1
 *            @arg DDL_FLASH_OB_BOOTREMAP_SYSINFO_2
 */
__STATIC_INLINE uint32_t DDL_FLASH_OB_GetSysInfoBoot(void)
{
    return (READ_BIT(FLASH->OPTCTRL1, FLASH_OPTCTRL1_SYS_BOOT_SEL));
}

/**
  * @brief  Enable the write protection of the desired bank n sectors
  *
  * @note   When the memory read protection level is selected (RDP level = 1),
  *         it is not possible to program or erase the flash sector i if CortexM4
  *         debug features are connected or boot code is executed in RAM, even if nWRPi = 1
  * @note   Active value of nWRPi bits is inverted when PCROP mode is active (SPRMOD =1).
  *
  * @param  WRPSector specifies the sector(s) to be write protected.
  *         The value of this parameter depend on device used within the same series.
  *         This parameter can be a value of @ref FLASH_DDL_EC_OB_WRP.
  *
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_OB_EnableWRP(uint32_t WRPSector)
{
    CLEAR_BIT(FLASH->OPTCTRL2, WRPSector);
}

/**
  * @brief  Disable the write protection of the desired bank n sectors
  *
  * @note   When the memory read protection level is selected (RDP level = 1),
  *         it is not possible to program or erase the flash sector i if CortexM4
  *         debug features are connected or boot code is executed in RAM, even if nWRPi = 1
  * @note   Active value of nWRPi bits is inverted when PCROP mode is active (SPRMOD =1).
  *
  * @param  WRPSector specifies the sector(s) to be write protected.
  *         The value of this parameter depend on device used within the same series.
  *         This parameter can be a value of @ref FLASH_DDL_EC_OB_WRP.
  *
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_OB_DisableWRP(uint32_t WRPSector)
{
    SET_BIT(FLASH->OPTCTRL2, WRPSector);
}

/**
  * @}
  */
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FLASH_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus DDL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data[2]);
ErrorStatus DDL_FLASH_Erase(DDL_FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
uint32_t DDL_FLASH_WaitForLastOperation(void);
void DDL_FLASH_FlushCaches(void);
uint32_t DDL_FLASH_SetErrorCode(void);
ErrorStatus DDL_FLASH_OBProgram(DDL_FLASH_OBProgramInitTypeDef *pOBInit);
ErrorStatus DDL_FLASH_OB_UserConfig(DDL_FLASH_OB_USERConfig *pUSERConfig);
  /**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */
/**
  * @}
  */
#endif /* defined (FLASH)*/

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32F463_DDL_FLASH_H */
