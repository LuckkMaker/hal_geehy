/**
  *
  * @file    g32f463_ddl_qspi.c
  * @brief   QSPI DDL module driver.
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
#include "g32f463_ddl_qspi.h"
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

#if defined (QSPI1) || defined (QSPI2)

/** @defgroup QSPI_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @addtogroup QSPI_DDL_Private_Constants QSPI Private Constants
  * @{
  */
/* QSPI registers Masks */
#define QSPI_TFTL_CLEAR_MASK            ((uint32_t)(QSPI_TFTL_TFTH | QSPI_TFTL_TFT))
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup QSPI_DDL_Private_Macros QSPI Private Macros
  * @{
  */
#define IS_DDL_QSPI_CLOCK_PRESCALER(__PRESCALER__)  (((__PRESCALER__) >= 2U) && ((__PRESCALER__) <= 65534U) && (((__PRESCALER__) & 0x1U) == 0U))

#define IS_DDL_QSPI_FRAME_FORMAT(__FORMAT__)     (((__FORMAT__) == DDL_QSPI_FRAME_FORMAT_STANDARD) || \
                                                 ((__FORMAT__) == DDL_QSPI_FRAME_FORMAT_DUAL)     || \
                                                 ((__FORMAT__) == DDL_QSPI_FRAME_FORMAT_QUAD))

#define IS_DDL_QSPI_DATA_FRAME_SIZE(__SIZE__)    (((__SIZE__) >= 3U) && ((__SIZE__) <= 31U))

#define IS_DDL_QSPI_CLOCK_STRETCH(__STRETCH__)   (((__STRETCH__) == ENABLE) || \
                                                 ((__STRETCH__) == DISABLE))

#define IS_DDL_QSPI_TX_FIFO_THRESHOLD(__THRESHOLD__)  (((__THRESHOLD__) <= 7U))

#define IS_DDL_QSPI_TX_FIFO_LEVEL(__LEVEL__)          (((__LEVEL__) <= 7U))

#define IS_DDL_QSPI_RX_FIFO_THRESHOLD(__THRESHOLD__)  (((__THRESHOLD__) <= 7U))

#define IS_DDL_QSPI_CHIP_SELECT_TOGGLE(__TOGGLE__)   (((__TOGGLE__) == DDL_QSPI_CS_TOGGLE_DISABLE) || \
                                                     ((__TOGGLE__) == DDL_QSPI_CS_TOGGLE_ENABLE))

#define IS_DDL_QSPI_TRANSFER_MODE(__MODE__)         (((__MODE__) == DDL_QSPI_TXMODE_TX_AND_RX)       || \
                                                    ((__MODE__) == DDL_QSPI_TXMODE_TX_ONLY)          || \
                                                    ((__MODE__) == DDL_QSPI_TXMODE_RX_ONLY)          || \
                                                    ((__MODE__) == DDL_QSPI_TXMODE_EEPROM_READ))

#define IS_DDL_QSPI_RXD_SAMPLE_EDGE(__EDGE__)       (((__EDGE__) == DDL_QSPI_RSE_RISING) || \
                                                    ((__EDGE__) == DDL_QSPI_RSE_FALLING))

#define IS_DDL_QSPI_INSTRUCTION_SIZE(__SIZE__)      (((__SIZE__) == DDL_QSPI_INST_LEN_0)  || \
                                                    ((__SIZE__) == DDL_QSPI_INST_LEN_4BIT) || \
                                                    ((__SIZE__) == DDL_QSPI_INST_LEN_8BIT) || \
                                                    ((__SIZE__) == DDL_QSPI_INST_LEN_16BIT))

#define IS_DDL_QSPI_INSTRUCTION_MODE(__MODE__)      (((__MODE__) == DDL_QSPI_IAT_STANDARD_INST_ADDR) || \
                                                    ((__MODE__) == DDL_QSPI_IAT_STANDARD_INST)      || \
                                                    ((__MODE__) == DDL_QSPI_IAT_FRF_INST_ADDR))

#define IS_DDL_QSPI_INSTRUCTION(__INSTRUCTION__)    ((__INSTRUCTION__) <= 0xFFU)

#define IS_DDL_QSPI_ADDRESS_SIZE(__SIZE__)          ((__SIZE__) <= DDL_QSPI_ADDR_LEN_60BIT)

#define IS_DDL_QSPI_XIP_INSTRUCTION(__INSTRUCTION__)  ((__INSTRUCTION__) <= 0xFFU)

#define IS_DDL_QSPI_XIP_WRAP_CODE(__WRAP_CODE__)  ((__WRAP_CODE__) <= 0xFFU)

#define IS_DDL_QSPI_XIP_ADDRESS_SIZE(__SIZE__)  ((__SIZE__) <= DDL_QSPI_XIP_ADDR_LEN_60BIT)

#define IS_DDL_QSPI_XIP_FRAME_FORMAT(__FORMAT__)  (((__FORMAT__) == DDL_QSPI_XIP_FRAME_FORMAT_DUAL) || \
                                               ((__FORMAT__) == DDL_QSPI_XIP_FRAME_FORMAT_QUAD))

#define IS_DDL_QSPI_XIP_INSTRUCTION_SIZE(__SIZE__)  (((__SIZE__) == DDL_QSPI_XIP_INST_LEN_0) || \
                                                 ((__SIZE__) == DDL_QSPI_XIP_INST_LEN_4BIT) || \
                                                 ((__SIZE__) == DDL_QSPI_XIP_INST_LEN_8BIT) || \
                                                 ((__SIZE__) == DDL_QSPI_XIP_INST_LEN_16BIT))

#define IS_DDL_QSPI_XIP_INSTRUCTION_MODE(__MODE__)  (((__MODE__) == DDL_QSPI_XIP_IAT_STANDARD_INST_ADDR) || \
                                                 ((__MODE__) == DDL_QSPI_XIP_IAT_STANDARD_INST) || \
                                                 ((__MODE__) == DDL_QSPI_XIP_IAT_FRF_INST_ADDR))

#define IS_DDL_QSPI_XIP_DUMMY_CYCLES(__CYCLES__)  ((__CYCLES__) <= 31U)

#define IS_DDL_QSPI_XIP_ENDIANNES(__ENDIANNESS__)  (((__ENDIANNESS__) == DDL_QSPI_XIP_MEM_ACCESS_BIG_ENDIAN) || \
                                                    ((__ENDIANNESS__) == DDL_QSPI_XIP_MEM_ACCESS_LITTLE_ENDIAN))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
static void DDL_QSPI_Config(QSPI_TypeDef *QSPIx, DDL_QSPI_CommandTypeDef *cmd);

/* Exported functions --------------------------------------------------------*/
/** @addtogroup QSPI_DDL_Exported_Functions
  * @{
  */

/** @addtogroup QSPI_DDL_EF_Init
  * @{
  */

/**
 * @brief  Initializes the QSPI according to the specified parameters
 *        in the DDL_QSPI_InitTypeDef.
 * @param  QSPIx: QSPI Instance
 * @param  QSPI_InitStruct: The specified parameters in the DDL_QSPI_InitTypeDef.
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
ErrorStatus DDL_QSPI_Init(QSPI_TypeDef *QSPIx, DDL_QSPI_InitTypeDef *QSPI_InitStruct)
{
    ErrorStatus status = SUCCESS;

    /* Check the parameters */
    ASSERT_PARAM(IS_QSPI_ALL_INSTANCE(QSPIx));
    ASSERT_PARAM(IS_DDL_QSPI_CLOCK_PRESCALER(QSPI_InitStruct->ClockPrescaler));
    ASSERT_PARAM(IS_DDL_QSPI_CLOCK_STRETCH(QSPI_InitStruct->ClockStretch));
    ASSERT_PARAM(IS_DDL_QSPI_TX_FIFO_THRESHOLD(QSPI_InitStruct->TxFifoThreshold));
    ASSERT_PARAM(IS_DDL_QSPI_TX_FIFO_LEVEL(QSPI_InitStruct->TxFifoLevel));
    ASSERT_PARAM(IS_DDL_QSPI_RX_FIFO_THRESHOLD(QSPI_InitStruct->RxFifoThreshold));
    ASSERT_PARAM(IS_DDL_QSPI_CHIP_SELECT_TOGGLE(QSPI_InitStruct->ChipSelectToggle));

    /* Configure QSPI FIFO Threshold */
    DDL_QSPI_SetTxFifoThreshold(QSPIx, QSPI_InitStruct->TxFifoThreshold);
    DDL_QSPI_SetTxFifoLevel(QSPIx, QSPI_InitStruct->TxFifoLevel);
    DDL_QSPI_SetRxFifoThreshold(QSPIx, QSPI_InitStruct->RxFifoThreshold);

    DDL_QSPI_SetChipSelectToggle(QSPIx, QSPI_InitStruct->ChipSelectToggle);
    /* Configure QSPI Clock Prescaler */
    DDL_QSPI_SetBaudRateDiv(QSPIx, QSPI_InitStruct->ClockPrescaler);
    /* Configure QSPI Clock Stretcher */
    if(QSPI_InitStruct->ClockStretch)
    {
        DDL_QSPI_EnableClockStretch(QSPIx);
    }
    else
    {
        DDL_QSPI_DisableClockStretch(QSPIx);
    }

    /* Return function status */
    return status;
}

/**
 * @brief  De-Initializes the QSPI peripheral
 * @param  QSPIx: QSPI Instance
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
ErrorStatus DDL_QSPI_DeInit(QSPI_TypeDef *QSPIx)
{
    ErrorStatus result = SUCCESS;
    /* Check the parameters */
    ASSERT_PARAM(IS_QSPI_ALL_INSTANCE(QSPIx));

    if(QSPIx == QSPI1)
    {
        DDL_AHB2_GRP1_ForceReset(DDL_AHB2_GRP1_PERIPH_QSPI1);
        DDL_AHB2_GRP1_ReleaseReset(DDL_AHB2_GRP1_PERIPH_QSPI1);
    }
#if defined(QSPI2)
    else if(QSPIx == QSPI2)
    {
        DDL_AHB2_GRP1_ForceReset(DDL_AHB2_GRP1_PERIPH_QSPI2);
        DDL_AHB2_GRP1_ReleaseReset(DDL_AHB2_GRP1_PERIPH_QSPI2);
    }
#endif /* QSPI2 */
    else
    {
        result = ERROR;
    }
    /* Return function status */
    return result;
}

/**
  * @}
  */



/** @addtogroup QSPI_DDL_EF_Input_Output
  * @{
  */

/**
 * @brief  Set the command configuration.
 * @param  QSPIx: QSPI Instance
 * @param  cmd: structure that contains the command configuration information
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
ErrorStatus DDL_QSPI_Command(QSPI_TypeDef *QSPIx, DDL_QSPI_CommandTypeDef *cmd)
{
    ErrorStatus status = SUCCESS;

    /* Check the parameters */
    ASSERT_PARAM(IS_DDL_QSPI_INSTRUCTION_MODE(cmd->InstructionMode));
    ASSERT_PARAM(IS_DDL_QSPI_INSTRUCTION_SIZE(cmd->InstructionSize));
    ASSERT_PARAM(IS_DDL_QSPI_INSTRUCTION(cmd->Instruction));
    ASSERT_PARAM(IS_DDL_QSPI_ADDRESS_SIZE(cmd->AddressSize));
    ASSERT_PARAM(IS_DDL_QSPI_TRANSFER_MODE(cmd->TransferMode));
    ASSERT_PARAM(IS_DDL_QSPI_FRAME_FORMAT(cmd->FrameFormat));
    ASSERT_PARAM(IS_DDL_QSPI_DATA_FRAME_SIZE(cmd->DataFrameSize));

    while(DDL_QSPI_IsActiveFlag_Busy(QSPIx));

    /* Disable the QSPI peripheral */
    DDL_QSPI_Disable(QSPIx);

    /* Call the configuration function */
    DDL_QSPI_Config(QSPIx, cmd);

    /* Enable the Slave Select signal */
    DDL_QSPI_EnableSlave(QSPIx);

    /* Enable the QSPI peripheral */
    DDL_QSPI_Enable(QSPIx);

    while(!DDL_QSPI_IsActiveFlag_TFNF(QSPIx));
    /* Send the command */
    if (cmd->InstructionSize != DDL_QSPI_INST_LEN_0)
    {
        DDL_QSPI_WriteData(QSPIx, cmd->Instruction);
    }

    while(!DDL_QSPI_IsActiveFlag_TFNF(QSPIx));
    /* Send the address */
    if (cmd->AddressSize != DDL_QSPI_ADDR_LEN_0)
    {
        DDL_QSPI_WriteData(QSPIx, cmd->Address);
    }
    
    if (cmd->NbData == 0U)
    {
        while(DDL_QSPI_IsActiveFlag_Busy(QSPIx));
    }

    /* Return function status */
    return status;
}

/**
 * @brief  Transmit and Receive a byte in blocking mode.
 * @param  QSPIx:   QSPI Instance
 * @param  pTxdata: pointer of Tx buff data
 * @param  pRxdata: pointer of Rx buff data
 * @param  size:    size of Tx/Rx buff data
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
ErrorStatus DDL_QSPI_TransmitReceive(QSPI_TypeDef *QSPIx,
                                                uint8_t *pTxdata,
                                                uint8_t *pRxdata,
                                                uint32_t size)
{
    uint32_t txCount, rxCount;
    ErrorStatus status = SUCCESS;

    while(DDL_QSPI_IsActiveFlag_Busy(QSPIx));

    if ((pTxdata != 0) && (pRxdata != 0))
    {
        txCount = size;
        rxCount = size;
        /* Disable the QSPI peripheral */
        DDL_QSPI_Disable(QSPIx);

        /* Disable the Slave Select signal */
        DDL_QSPI_DisableSlave(QSPIx);

        DDL_QSPI_SetDataFrameSize(QSPIx, DDL_QSPI_DFS_BIT_08);
        DDL_QSPI_SetFrameFormat(QSPIx, DDL_QSPI_FRAME_FORMAT_STANDARD);
        DDL_QSPI_SetTansMode(QSPIx, DDL_QSPI_TXMODE_TX_AND_RX);

        /* Enable the Slave Select signal */
        DDL_QSPI_EnableSlave(QSPIx);

        /* Enable the QSPI peripheral */
        DDL_QSPI_Enable(QSPIx);

        while(txCount)
        {
            while(DDL_QSPI_IsActiveFlag_TFNF(QSPIx) == RESET);
            /* Send the byte */
            DDL_QSPI_WriteData(QSPIx, *(pTxdata++));
            txCount--;

            while(DDL_QSPI_IsActiveFlag_RFNE(QSPIx) == RESET || DDL_QSPI_IsActiveFlag_Busy(QSPIx));
            *(pRxdata++) = DDL_QSPI_ReadData(QSPIx);
            pRxdata++;
            rxCount--;
        }

    }
    /* Return function status */
    return status;
}

/**
 * @brief  Transmit an amount of data in blocking mode.
 * @param  QSPIx: QSPI Instance
 * @param  pTxData: pointer of Tx buff data
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
ErrorStatus DDL_QSPI_Transmit(QSPI_TypeDef *QSPIx, uint8_t *pTxData)
{
    uint32_t txCount;
    ErrorStatus status = SUCCESS;

    txCount = DDL_QSPI_GetFrameNum(QSPIx) + 1;

    while(txCount)
    {
        while(DDL_QSPI_IsActiveFlag_TFNF(QSPIx) == RESET);
        /* Send the byte */
        DDL_QSPI_WriteData(QSPIx, *(pTxData));
        pTxData++;
        txCount--;
    }
    while(DDL_QSPI_IsActiveFlag_Busy(QSPIx));
    /* Return function status */
    return status;
}

/**
 * @brief  Receive an amount of data in blocking mode.
 * @param  QSPIx: QSPI Instance
 * @param  pRxData: pointer of Rx buff data
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
ErrorStatus DDL_QSPI_Receive(QSPI_TypeDef *QSPIx, uint8_t *pRxData)
{
    uint32_t rxCount;
    ErrorStatus status = SUCCESS;

    rxCount = DDL_QSPI_GetFrameNum(QSPIx) + 1;

    while(rxCount)
    {
        while(DDL_QSPI_IsActiveFlag_RFNE(QSPIx) == RESET);
        /* Get the byte */
        *(pRxData) = DDL_QSPI_ReadData(QSPIx);
        pRxData++;
        rxCount--;
    }
    while(DDL_QSPI_IsActiveFlag_Busy(QSPIx));

    /* Return function status */
    return status;
}

/**
  * @}
  */

/** @addtogroup QSPI_DDL_EF_XIP
  * @{
  */
/**
 * @brief  Configure the QSPI XIP memory mapped mode.
 * @param  QSPIx: QSPI Instance
 * @param  xipConfig: structure the contains the XIP configuration information.
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS
 *          - ERROR
 */
ErrorStatus DDL_QSPI_MemoryMapped(QSPI_TypeDef *QSPIx, DDL_QSPI_XIPTypeDef *xipConfig)
{
    ErrorStatus status = SUCCESS;

    /* Check the parameters */
    ASSERT_PARAM(IS_DDL_QSPI_XIP_INSTRUCTION(xipConfig->Instruction));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_WRAP_CODE(xipConfig->WrapCode));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_ADDRESS_SIZE(xipConfig->AddressSize));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_INSTRUCTION_MODE(xipConfig->InstructionMode));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_INSTRUCTION_SIZE(xipConfig->InstructionSize));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_FRAME_FORMAT(xipConfig->FrameFormat));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_DUMMY_CYCLES(xipConfig->DummyCycles));
    ASSERT_PARAM(IS_DDL_QSPI_XIP_ENDIANNES(xipConfig->Endianness));

    while(DDL_QSPI_IsActiveFlag_Busy(QSPIx));

    /* Disable the QSPI peripheral */
    DDL_QSPI_Disable(QSPIx);

    /* Call the configuration function */
    DDL_QSPI_XIP_SetExtMemAccessFormat(QSPIx, xipConfig->Endianness);

    /* Flash support instruction state */
    if (xipConfig->InstructionSize != DDL_QSPI_XIP_INST_LEN_0)
    {
        DDL_QSPI_XIP_SetOpcodeForINCR(QSPIx, xipConfig->Instruction);
        DDL_QSPI_XIP_SetOpcodeForWRAP(QSPIx, xipConfig->WrapCode);

        /* Enable XIP instruction state */
        DDL_QSPI_XIP_EnableInstruction(QSPIx);
    }
    else
    {
        /* Disable XIP instruction state */
        DDL_QSPI_XIP_DisableInstruction(QSPIx);
    }
    /* Configure XIP parameters */
    DDL_QSPI_XIP_SetInstAddrType(QSPIx, xipConfig->InstructionMode);
    DDL_QSPI_XIP_SetInstLen(QSPIx, xipConfig->InstructionSize);
    DDL_QSPI_XIP_SetAddrLen(QSPIx, xipConfig->AddressSize);
    DDL_QSPI_XIP_SetWaitCycle(QSPIx, xipConfig->DummyCycles);
    DDL_QSPI_XIP_SetFrameFormat(QSPIx, xipConfig->FrameFormat);
    
    if (xipConfig->ContinuousMode == ENABLE)
    {
        DDL_QSPI_XIP_EnableContinuous(QSPIx);
    }
    else
    {
        DDL_QSPI_XIP_DisableContinuous(QSPIx);
    }
    if (xipConfig->PrefetchMode == ENABLE)
    {
        DDL_QSPI_XIP_EnablePrefetch(QSPIx);
    }
    else
    {
        DDL_QSPI_XIP_DisablePrefetch(QSPIx);
    }

    /* Enable the Slave Select signal */
    DDL_QSPI_XIP_EnableSlave(QSPIx);

    /* Enable the QSPI peripheral */
    DDL_QSPI_Enable(QSPIx);
    
    /* Enable XIP */
    DDL_QSPI_XIP_Enable(QSPIx);
    
    /* Return function status */
    return status;
}
/**
  * @}
  */


/** @defgroup QSPI_Private_Functions QSPI Private Functions
  * @{
  */

/**
 * @brief  Configure the communication registers.
 * @param  QSPIx: QSPI Instance
 * @param  cmd: structure that contains the command configuration information
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: QSPI registers are de-initialized
 *          - ERROR: QSPI registers are not de-initialized
 */
static void DDL_QSPI_Config(QSPI_TypeDef *QSPIx, DDL_QSPI_CommandTypeDef *cmd)
{
    if (cmd->FrameFormat == DDL_QSPI_FRAME_FORMAT_STANDARD)
    {
        /* Configure CTRL1 */
        DDL_QSPI_SetFrameFormat(QSPIx, cmd->FrameFormat);
        DDL_QSPI_SetTansMode(QSPIx, cmd->TransferMode);

        if (cmd->TransferMode == DDL_QSPI_TXMODE_EEPROM_READ)
        {
            /* Configure CTRL2 */
            DDL_QSPI_SetFrameNum(QSPIx, cmd->NbData);
        }
        else
        {
            if(cmd->NbData != 0)
            {
                /* Configure CTRL2 */
                DDL_QSPI_SetFrameNum(QSPIx, (cmd->NbData - 1));
            }
        }
    }
    else if (cmd->FrameFormat == DDL_QSPI_FRAME_FORMAT_DUAL)
    {
        if ((cmd->TransferMode == DDL_QSPI_TXMODE_TX_ONLY) || (cmd->TransferMode == DDL_QSPI_TXMODE_RX_ONLY))
        {
            /* Configure CTRL1 */
            DDL_QSPI_SetFrameFormat(QSPIx, cmd->FrameFormat);
            DDL_QSPI_SetTansMode(QSPIx, cmd->TransferMode);

            /* Configure CTRL2 */
            if (cmd->NbData != 0)
            {
                DDL_QSPI_SetFrameNum(QSPIx, (cmd->NbData - 1));
            }
            else
            {
                DDL_QSPI_SetFrameNum(QSPIx, 0);
            }

            if (cmd->TransferMode == DDL_QSPI_TXMODE_TX_ONLY)
            {
                /* Configure CTRL3 */
                DDL_QSPI_SetInstAddrType(QSPIx, cmd->InstructionMode);
                DDL_QSPI_SetAddrLen(QSPIx, cmd->AddressSize);
                DDL_QSPI_SetInstLen(QSPIx, cmd->InstructionSize);
            }
            else
            {
                /* Configure CTRL3 */
                DDL_QSPI_SetInstAddrType(QSPIx, cmd->InstructionMode);
                DDL_QSPI_SetAddrLen(QSPIx, cmd->AddressSize);
                DDL_QSPI_SetInstLen(QSPIx, cmd->InstructionSize);
                DDL_QSPI_SetWaitCycle(QSPIx, cmd->DummyCycles);
            }
        }
    }
    else if (cmd->FrameFormat == DDL_QSPI_FRAME_FORMAT_QUAD)
    {
        if ((cmd->TransferMode == DDL_QSPI_TXMODE_TX_ONLY) || (cmd->TransferMode == DDL_QSPI_TXMODE_RX_ONLY))
        {
            /* Configure CTRL1 */
            DDL_QSPI_SetFrameFormat(QSPIx, cmd->FrameFormat);
            DDL_QSPI_SetTansMode(QSPIx, cmd->TransferMode);

            /* Configure CTRL2 */
            if (cmd->NbData != 0)
            {
                DDL_QSPI_SetFrameNum(QSPIx, (cmd->NbData - 1));
            }
            else
            {
                DDL_QSPI_SetFrameNum(QSPIx, 0);
            }

            if (cmd->TransferMode == DDL_QSPI_TXMODE_TX_ONLY)
            {
                /* Configure CTRL3 */
                DDL_QSPI_SetInstAddrType(QSPIx, cmd->InstructionMode);
                DDL_QSPI_SetAddrLen(QSPIx, cmd->AddressSize);
                DDL_QSPI_SetInstLen(QSPIx, cmd->InstructionSize);
            }
            else
            {
                /* Configure CTRL3 */
                DDL_QSPI_SetInstAddrType(QSPIx, cmd->InstructionMode);
                DDL_QSPI_SetAddrLen(QSPIx, cmd->AddressSize);
                DDL_QSPI_SetInstLen(QSPIx, cmd->InstructionSize);
                DDL_QSPI_SetWaitCycle(QSPIx, cmd->DummyCycles);
            }
        }
    }
    else
    {
        /* Nothing to do */
    }
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

#endif /* defined (QSPI1) || defined (QSPI2) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

