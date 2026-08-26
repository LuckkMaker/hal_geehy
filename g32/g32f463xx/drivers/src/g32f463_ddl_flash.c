/**
  *
  * @file    g32f463_ddl_flash.c
  * @brief   FLASH DDL module driver.
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
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32f463_ddl_flash.h"
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

#if defined (FLASH)

/** @defgroup FLASH_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup FLASH_DDL_Private_Macros FLASH Private Macros
  * @{
  */

/** @defgroup FLASH_DDL_ES_IS_FLASH_Definitions FLASH Private macros to check input parameters
  * @{
  */

#define DDL_IS_FLASH_TYPEPROGRAM(VALUE)(((VALUE) == DDL_FLASH_TYPEPROGRAM_BYTE)     || \
                                       ((VALUE) == DDL_FLASH_TYPEPROGRAM_HALFWORD) || \
                                       ((VALUE) == DDL_FLASH_TYPEPROGRAM_WORD)     || \
                                       ((VALUE) == DDL_FLASH_TYPEPROGRAM_DOUBLEWORD)|| \
                                       ((VALUE) == DDL_FLASH_TYPEPROGRAM_QUADWORD))

#define DDL_IS_FLASH_TYPEERASE(VALUE)(((VALUE) == DDL_FLASH_TYPEERASE_SECTORS) || \
                                     ((VALUE) == DDL_FLASH_TYPEERASE_MASSERASE) || \
                                     ((VALUE) == DDL_FLASH_TYPEERASE_BLOCKSERASE) || \
                                     ((VALUE) == DDL_FLASH_TYPEERASE_DATASECTORS))

#define DDL_IS_FLASH_NBBLOCKS(NBBLOCK) (((NBBLOCK) != 0) && ((NBBLOCK) <= DDL_FLASH_BLOCK_TOTAL))

#define DDL_IS_FLASH_NBSECTORS(NBSECTORS) ((NBSECTORS) <= DDL_FLASH_SECTOR_TOTAL)

#define DDL_IS_FLASH_NBDATASECTORS(NBDATASECTORS) (((NBDATASECTORS) != 0) && ((NBDATASECTORS) <= DDL_FLASH_DATASECTOR_TOTAL))

#define DDL_IS_OPTIONBYTE(VALUE) (((VALUE) == DDL_OPTIONBYTE_WRP) || \
                                    ((VALUE) == DDL_OPTIONBYTE_RDP) || \
                                    ((VALUE) == DDL_OPTIONBYTE_USER) || \
                                    ((VALUE) == DDL_OPTIONBYTE_BOR) || \
                                    ((VALUE) == DDL_OPTIONBYTE_DATA_WRP) || \
                                    ((VALUE) == DDL_OPTIONBYTE_DATA_RDP))

#define DDL_IS_WRPSTATE(VALUE) (((VALUE) == DDL_OB_WRPSTATE_DISABLE) || \
                                ((VALUE) == DDL_OB_WRPSTATE_ENABLE))

#define DDL_IS_OB_RDP_LEVEL(LEVEL) (((LEVEL) == DDL_FLASH_OB_RDP_LEVEL_0) ||\
                                    ((LEVEL) == DDL_FLASH_OB_RDP_LEVEL_1) ||\
                                    ((LEVEL) == DDL_FLASH_OB_RDP_LEVEL_2))

#define DDL_IS_OB_BOR_LEVEL(LEVEL) (((LEVEL) == DDL_FLASH_OB_BOR_LEVEL1) || ((LEVEL) == DDL_FLASH_OB_BOR_LEVEL2) ||\
                                    ((LEVEL) == DDL_FLASH_OB_BOR_LEVEL3) || ((LEVEL) == DDL_FLASH_OB_BOR_OFF))

#define DDL_IS_OB_IWDT_SOURCE(SOURCE) (((SOURCE) == DDL_FLASH_OB_IWDT_SW) || ((SOURCE) == DDL_FLASH_OB_IWDT_HW))

#define DDL_IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == ENABLE) || ((SOURCE) == DISABLE))

#define DDL_IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == ENABLE) || ((SOURCE) == DISABLE))

/**
  * @}
  */



/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_DDL_Exported_Functions
  * @{
  */

/** @addtogroup FLASH_DDL_EF_Program_Erase
  * @{
  */

/**
 * @brief  Program byte, halfword, word, double word or quad word at a specified address
 * @param  TypeProgram  Indicate the way to program at a specified address.
 *         This parameter can be a value of @ref FLASH_DDL_EC_Type_Program:
 *         @arg @ref DDL_FLASH_TYPEPROGRAM_BYTE
 *         @arg @ref DDL_FLASH_TYPEPROGRAM_HALFWORD
 *         @arg @ref DDL_FLASH_TYPEPROGRAM_WORD
 *         @arg @ref DDL_FLASH_TYPEPROGRAM_DOUBLEWORD
 *         @arg @ref DDL_FLASH_TYPEPROGRAM_QUADWORD
 * @param  Address  specifies the address to be programmed.
 * @param  Data[2] specifies the data to be programmed
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS
 *          - ERROR
 */
ErrorStatus DDL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data[2])
{
    ErrorStatus status = SUCCESS;
    uint32_t errCode = DDL_FLASH_ERROR_NONE;

    /* Check the parameters */
    ASSERT_PARAM(DDL_IS_FLASH_TYPEPROGRAM(TypeProgram));

    /* Wait for last operation to be completed */
    errCode = DDL_FLASH_WaitForLastOperation();

    if(errCode == DDL_FLASH_ERROR_NONE)
    {
        if(TypeProgram == DDL_FLASH_TYPEPROGRAM_BYTE)
        {
           /*Program byte (8-bit) at a specified address.*/
           DDL_FLASH_SetProgramSize(DDL_FLASH_PSIZE_BYTE);
           DDL_FLASH_EnableProgram();
           *(__IO uint8_t*)Address = (uint8_t)Data[0];
        }
        else if(TypeProgram == DDL_FLASH_TYPEPROGRAM_HALFWORD)
        {
           /*Program halfword (16-bit) at a specified address.*/
           DDL_FLASH_SetProgramSize(DDL_FLASH_PSIZE_HALF_WORD);
           DDL_FLASH_EnableProgram();
           *(__IO uint16_t*)Address = (uint16_t)Data[0];
        }
        else if(TypeProgram == DDL_FLASH_TYPEPROGRAM_WORD)
        {
           /*Program word (32-bit) at a specified address.*/
           DDL_FLASH_SetProgramSize(DDL_FLASH_PSIZE_WORD);
           DDL_FLASH_EnableProgram();
           *(__IO uint32_t*)Address = (uint32_t)Data[0];
        }
        else if(TypeProgram == DDL_FLASH_TYPEPROGRAM_DOUBLEWORD)
        {
           /*Program double word (64-bit) at a specified address.*/
           DDL_FLASH_SetProgramSize(DDL_FLASH_PSIZE_DOUBLE_WORD);
           DDL_FLASH_EnableProgram();
           *(__IO uint32_t*)Address = (uint32_t)Data[0];

           /* Barrier to ensure programming is performed in 2 steps, in right order
            (independently of compiler optimization behavior) */
            __ISB();

            /* Program second word */
            *(__IO uint32_t*)(Address+4) = (uint32_t)(Data[0] >> 32);
        }
        else
        {
            /*Program quad word (128-bit) at a specified address.*/
           DDL_FLASH_SetProgramSize(DDL_FLASH_PSIZE_QUAD_WORD);
           DDL_FLASH_EnableProgram();
           *(__IO uint32_t*)Address = (uint32_t)Data[0];

            __ISB();

            /* Program second word */
            *(__IO uint32_t*)(Address+4) = (uint32_t)(Data[0] >> 32);

            __ISB();

            /* Program second word */
            *(__IO uint32_t*)(Address+8) = (uint32_t)(Data[1]);

            __ISB();

            /* Program second word */
            *(__IO uint32_t*)(Address+12) = (uint32_t)(Data[1] >> 32);
        }

        /* Wait for last operation to be completed */
        errCode = DDL_FLASH_WaitForLastOperation();
        if(errCode != DDL_FLASH_ERROR_NONE)
        {
            status = ERROR;
        }

        /* If the program operation is completed, disable the PG Bit */
        DDL_FLASH_DisableProgram();
    }
    else
    {
        status = ERROR;
    }

    /* Return function status */
    return status;
}

/**
 * @brief  Perform a mass erase or erase the specified FLASH memory sectors
 * @param  pEraseInit  pointer to an FLASH_EraseInitTypeDef structure that
  *         contains the configuration information for the erasing.
 * @param  SectorError  SectorError pointer to variable  that
  *         contains the configuration information on faulty sector in case of error
  *         (0xFFFFFFFFU means that all the sectors have been correctly erased)
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS
 *          - ERROR
 */
ErrorStatus DDL_FLASH_Erase(DDL_FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError)
{
    uint32_t index = 0U;
    ErrorStatus status = SUCCESS;
    uint32_t errCode = DDL_FLASH_ERROR_NONE;

    /* Check the parameters */
    ASSERT_PARAM(DDL_IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

    /* Wait for last operation to be completed */
    errCode = DDL_FLASH_WaitForLastOperation();

    if(errCode == DDL_FLASH_ERROR_NONE)
    {

        DDL_FLASH_SetProgramSize(DDL_FLASH_PSIZE_BYTE);
        if(pEraseInit->TypeErase == DDL_FLASH_TYPEERASE_MASSERASE)
        {
            /*Mass erase to be done*/
            DDL_FLASH_EnableMassErase();
            DDL_FLASH_Start();

            /* Wait for last operation to be completed */
            errCode = DDL_FLASH_WaitForLastOperation();
            if(errCode != DDL_FLASH_ERROR_NONE)
            {
                status = ERROR;
            }

            /* if the erase operation is completed, disable the MER Bit */
            DDL_FLASH_DisableMassErase();
        }
        else if(pEraseInit->TypeErase == DDL_FLASH_TYPEERASE_SECTORS)
        {
            /* Check the parameters */
            ASSERT_PARAM(DDL_IS_FLASH_NBSECTORS(pEraseInit->NbSectors + pEraseInit->Sector));

            /* Erase by sectors to be done*/
            for (index = pEraseInit->Sector; index < (pEraseInit->NbSectors + pEraseInit->Sector); index++)
            {
                DDL_FLASH_EnableSectorErase();
                DDL_FLASH_SetSectorNumber(index);
                DDL_FLASH_Start();

                /* Wait for last operation to be completed */
                errCode = DDL_FLASH_WaitForLastOperation();
                if(errCode != DDL_FLASH_ERROR_NONE)
                {
                    status = ERROR;
                }

                /* If the erase operation is completed, disable the SERS Bits */
                DDL_FLASH_DisableSectorErase();

                if (status != SUCCESS)
                {
                  /* In case of error, stop erase procedure and return the faulty sector*/
                  *SectorError = index;
                  break;
                }
            }
        }
        else if(pEraseInit->TypeErase == DDL_FLASH_TYPEERASE_BLOCKSERASE)
        {
            /* Check the parameters */
            ASSERT_PARAM(DDL_IS_FLASH_NBBLOCKS(pEraseInit->NbBlocks + pEraseInit->Block));

            /* Erase by block to be done*/
            for (index = pEraseInit->Block; index < (pEraseInit->NbBlocks + pEraseInit->Block); index++)
            {
                DDL_FLASH_EnableBlockErase();
                DDL_FLASH_SetSectorNumber(index * 8U);
                DDL_FLASH_Start();

                /* Wait for last operation to be completed */
                errCode = DDL_FLASH_WaitForLastOperation();
                if(errCode != DDL_FLASH_ERROR_NONE)
                {
                    status = ERROR;
                }

                /* If the erase operation is completed, disable the BERS Bits */
                DDL_FLASH_DisableBlockErase();

                if (status != SUCCESS)
                {
                  /* In case of error, stop erase procedure and return the faulty sector*/
                  *SectorError = index;
                  break;
                }
            }
        }
        else
        {
            DDL_FLASH_EnableDataSectorErase();
            DDL_FLASH_Start();

            /* Wait for last operation to be completed */
            errCode = DDL_FLASH_WaitForLastOperation();
            if(errCode != DDL_FLASH_ERROR_NONE)
            {
                status = ERROR;
            }

            /* If the erase operation is completed, disable the DSERS Bits */
            DDL_FLASH_DisableDataSectorErase();

            if (status != SUCCESS)
            {
                /* In case of error, stop erase procedure and return the faulty sector*/
                *SectorError = index;
            }
        }

        /* Flush the caches to be sure of the data consistency */
        DDL_FLASH_FlushCaches();
    }
    else
    {
        status = ERROR;
    }

    /* Return function status */
    return status;
}

/**
  * @brief  Wait for a FLASH operation to complete.
  * @retval An error code, one of the following values, as well as their combinations:
  *          - DDL_FLASH_ERROR_NONE
  *          - DDL_FLASH_ERROR_RD
  *          - DDL_FLASH_ERROR_PGS
  *          - DDL_FLASH_ERROR_PGP
  *          - DDL_FLASH_ERROR_PGA
  *          - DDL_FLASH_ERROR_WRP
  *          - DDL_FLASH_ERROR_OPERATION
  *          - DDL_FLASH_ERROR_PGV
  *          - DDL_FLASH_ERROR_OPT
  */
uint32_t DDL_FLASH_WaitForLastOperation(void)
{
    uint32_t errCode = DDL_FLASH_ERROR_NONE;

    /* Wait for the FLASH operation to complete by polling on BUSY flag to be reset.
       Even if the FLASH operation fails, the BUSY flag will be reset and an error
       flag will be set */
    while(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_BSY));

    /* Check FLASH End of Operation flag  */
    if (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_EOP))
    {
        /* Clear FLASH End of Operation pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_EOP);
    }

    if((DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_OPERR) != RESET) | \
        (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGVERR) != RESET) |\
        (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_OPTERR) != RESET) |\
        (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_WRPERR) != RESET) |\
        (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGAERR) != RESET) |\
        (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGPERR) != RESET) |\
        (DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGSERR) != RESET)
        )
    {
        /*Save the error code*/
        errCode = DDL_FLASH_SetErrorCode();
    }

    /* If there is no error flag set */
    return errCode;
}

/**
  * @brief  Flush the instruction and data caches
  * @retval None
  */
void DDL_FLASH_FlushCaches(void)
{
    /* Flush instruction cache  */
    if (READ_BIT(FLASH->ACCTRL, FLASH_ACCTRL_ICACHEEN) != RESET)
    {
        /* Disable instruction cache  */
        DDL_FLASH_DisableInstCache();
        /* Reset instruction cache */
        DDL_FLASH_EnableInstCacheReset();
        /* Enable instruction cache */
        DDL_FLASH_EnableInstCache();
    }

    if (READ_BIT(FLASH->ACCTRL, FLASH_ACCTRL_DCACHEEN) != RESET)
    {
        /* Disable data cache  */
        DDL_FLASH_DisableDataCache();
        /* Reset data cache */
        DDL_FLASH_EnableDataCacheReset();
        /* Enable data cache */
        DDL_FLASH_EnableDataCache();
    }
}

/**
  * @}
  */




/** @addtogroup FLASH_DDL_EF_State_Errors State and Errors functions
  * @{
  */


/**
  * @brief  Set the specific FLASH error flag.
  * @retval An error code, one of the following values, as well as their combinations:
  *          - DDL_FLASH_ERROR_NONE
  *          - DDL_FLASH_ERROR_PGS
  *          - DDL_FLASH_ERROR_PGP
  *          - DDL_FLASH_ERROR_PGA
  *          - DDL_FLASH_ERROR_WRP
  *          - DDL_FLASH_ERROR_OPERATION
  *          - DDL_FLASH_ERROR_PGV
  *          - DDL_FLASH_ERROR_OPT
  */
uint32_t DDL_FLASH_SetErrorCode(void)
{
    uint32_t errCode = DDL_FLASH_ERROR_NONE;
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_WRPERR) != RESET)
    {
        errCode |= DDL_FLASH_ERROR_WRP;
        /* Clear FLASH write protection error pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_WRPERR);
    }

#if defined(DDL_FLASH_FLAG_PGAERR)
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGAERR) != RESET)
    {
        errCode |= DDL_FLASH_ERROR_PGA;
        /* Clear FLASH Programming alignment error pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_PGAERR);
    }
#endif /* DDL_FLASH_FLAG_PGAERR */

#if defined(DDL_FLASH_FLAG_PGPERR)
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGPERR) != RESET)
    {
        errCode |= DDL_FLASH_ERROR_PGP;
        /* Clear FLASH Programming parallelism error pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_PGPERR);
    }
#endif /* DDL_FLASH_FLAG_PGPERR */

#if defined(DDL_FLASH_FLAG_PGSERR)
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGSERR) != RESET)
    {
        errCode |= DDL_FLASH_ERROR_PGS;
        /* Clear FLASH Programming sequence error pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_PGSERR);
    }
#endif /* DDL_FLASH_FLAG_PGSERR */

#if defined(DDL_FLASH_FLAG_OPERR)
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_OPERR) != RESET)
    {
        errCode |= DDL_FLASH_ERROR_OPERATION;
        /* Clear FLASH Operation error pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_OPERR);
    }
#endif /* DDL_FLASH_FLAG_OPERR */

#if defined(DDL_FLASH_FLAG_PGVERR)
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_PGVERR) != RESET)
    {
        errCode |= DDL_FLASH_ERROR_PGV;
        /* Clear FLASH Operation error pending bit */
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_PGVERR);
    }
#endif /* DDL_FLASH_FLAG_PGVERR */

#if defined(DDL_FLASH_FLAG_OPTERR)
    if(DDL_FLASH_IsActiveFlag(DDL_FLASH_FLAG_OPTERR))
    {
        errCode |= DDL_FLASH_ERROR_OPT;
        DDL_FLASH_ClearFlag(DDL_FLASH_FLAG_OPTERR);
    }
#endif /* DDL_FLASH_FLAG_OPTERR */
    return errCode;
}


/**
  * @}
  */

/** @addtogroup FLASH_DDL_EF_OB Option Byte functions
  * @{
  */

/**
  * @brief  Program the FLASH User Option Byte: IWDT_SW / RST_STOP / RST_STDBY.
  * @param   pOBInit pointer to an DDL_FLASH_OBProgramInitTypeDef structure that
  *          contains the configuration information for the programming.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS
  *          - ERROR
  */
ErrorStatus DDL_FLASH_OBProgram(DDL_FLASH_OBProgramInitTypeDef *pOBInit)
{
    ErrorStatus status = SUCCESS;

    /* Check the parameters */
    ASSERT_PARAM(DDL_IS_OPTIONBYTE(pOBInit->OptionType));

    /* Write protection configuration */
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_WRP) == DDL_OPTIONBYTE_WRP)
    {
        ASSERT_PARAM(DDL_IS_WRPSTATE(pOBInit->WRPState));
        if (pOBInit->WRPState == DDL_OB_WRPSTATE_ENABLE)
        {
            /*Enable of Write protection on the selected Sector*/
            DDL_FLASH_OB_EnableWRP(pOBInit->WRPSector);
        }
        else
        {
            /*Disable of Write protection on the selected Sector*/
            DDL_FLASH_OB_DisableWRP(pOBInit->WRPSector);
        }
    }

    /*Read protection configuration*/
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_RDP) == DDL_OPTIONBYTE_RDP)
    {
        DDL_FLASH_OB_RDP_LevelConfig(pOBInit->RDPLevel);
    }

    /*USER configuration*/
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_USER) == DDL_OPTIONBYTE_USER)
    {
        status = DDL_FLASH_OB_UserConfig(&pOBInit->USERConfig);
    }

    /*BOR Level configuration*/
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_BOR) == DDL_OPTIONBYTE_BOR)
    {
        DDL_FLASH_OB_BOR_LevelConfig(pOBInit->BORLevel);
    }

    /*Data sector write protection configuration*/
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_DATA_WRP) == DDL_OPTIONBYTE_DATA_WRP)
    {
        if (pOBInit->DataWRPState == ENABLE)
        {
            /*Enable of Write protection on the selected Sector*/
            DDL_FLASH_OB_EnableWRP_DS();
        }
        else
        {
            /*Disable of Write protection on the selected Sector*/
            DDL_FLASH_OB_DisableWRP_DS();
        }
    }

    /*Data sector read protection configuration*/
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_DATA_RDP) == DDL_OPTIONBYTE_DATA_RDP)
    {
        if (pOBInit->DataRDPState == ENABLE)
        {
            /*Enable of Write protection on the selected Sector*/
            DDL_FLASH_OB_EnableRDP_DS();
        }
        else
        {
            /*Disable of Write protection on the selected Sector*/
            DDL_FLASH_OB_DisableRDP_DS();
        }
    }

    /*System Info Boot configuration*/
    if ((pOBInit->OptionType & DDL_OPTIONBYTE_SYSINFO_BOOT) == DDL_OPTIONBYTE_SYSINFO_BOOT)
    {
        DDL_FLASH_OB_SetSysInfoBoot(pOBInit->SysInfoBootSel);
    }

    DDL_FLASH_OB_Launch();

    return status;
}

/**
  * @brief  Program the FLASH User Option Byte: IWDT_SW / RST_STOP / RST_STDBY.
  * @param  pUSERConfig pointer to an DDL_FLASH_OB_USERConfig structure that
  *             contains the configuration information for the programming.
  *          -Iwdt Selects the IWDT mode
  *             This parameter can be one of the following values:
  *             @arg DDL_FLASH_OB_IWDT_SW: Software IWDT selected
  *             @arg DDL_FLASH_OB_IWDT_HW: Hardware IWDT selected
  *          -StopEn Enable/Disable reset event when entering STOP mode.
  *             This parameter  can be one of the following values:
  *             @arg ENABLE
  *             @arg DISABLE
  *          -StdbyEn Enable/Disable reset event when entering Standby mode.
  *             This parameter  can be one of the following values:
  *             @arg ENABLE
  *             @arg DISABLE
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS
 *          - ERROR
  */
ErrorStatus DDL_FLASH_OB_UserConfig(DDL_FLASH_OB_USERConfig *pUSERConfig)
{
    ErrorStatus status = SUCCESS;
    uint32_t errCode = DDL_FLASH_ERROR_NONE;

    /* Check the parameters */
    ASSERT_PARAM(DDL_IS_OB_IWDT_SOURCE(pUSERConfig->Iwdt));
    ASSERT_PARAM(DDL_IS_OB_STOP_SOURCE(pUSERConfig->StopEn));
    ASSERT_PARAM(DDL_IS_OB_STDBY_SOURCE(pUSERConfig->StdbyEn));

    /* Wait for last operation to be completed */
    errCode = DDL_FLASH_WaitForLastOperation();

    if (errCode == DDL_FLASH_ERROR_NONE)
    {
        DDL_FLASH_OB_SetWDTSelect(pUSERConfig->Iwdt);
        if(pUSERConfig->StopEn)
        {
            DDL_FLASH_OB_EnableStopRST();
        }
        else
        {
            DDL_FLASH_OB_DisableStopRST();
        }

        if(pUSERConfig->StdbyEn)
        {
            DDL_FLASH_OB_EnableStandbyRST();
        }
        else
        {
            DDL_FLASH_OB_DisableStandbyRST();
        }
    }
    else
    {
        status = ERROR;
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

#endif /* defined (FLASH) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
