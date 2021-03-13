#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "irf.h"
#include "uart.h"
#include "queue.h"
#include "xor.h"
/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Variable
 ******************************************************************************/
QUEUEx_t    irf_CommandQueue;
irf_Command_t irf_CommandBuff[IRF_QUEUE_MAX];
/*******************************************************************************
 * code
 ******************************************************************************/
static void IRFCallBackHandle();
/*!
 * @brief IRF_INIT
 *
 * @param 
 * @param 
 */
void IRF_Init()
{
    UART_Init(UART_BAUDRATE);
    UART_CallBackInit(IRF_CallBackHandle);
    QUEUE_Init(&irf_CommandQueue, (u8*)irf_CommandBuff,\
                IRF_QUEUE_MAX, sizeof(irf_Command_t));
    UART_Enable();
}
/*!
 * @brief IRF_CallBackHandle
 *
 * @param none
 */
static void IRF_CallBackHandle(void)
{
    static u8 revByte = 0;
    static u16 revByteCount = 0;
    static u8 revBuff[IRF_HEADER + IRF_BUFF_MAX + 1];

    revByte = UART_RevData();
    revBuff[revByteCount++] = revByte;
    if(revByteCount >= IRF_HEADER)
    {
        if(revByteCount == (IRF_HEADER + revBuff[3] + 1))
        {
            if(revBuff[IRF_HEADER + revBuff[3]] == XOR_Caculator(revBuff, 0, IRF_HEADER + revBuff[3]))
            {
                QUEUE_Push(&irf_CommandQueue, revBuff);
            }
            revByteCount = 0;
        }
    }
}

/*!
 * @brief 
 *
 * @param 
 * @param 
 */
u8 IRF_GetCommand(irf_Command_t *irf_CommandBuff)
{
    /* if queue not empty: get command */
    if(!QUEUE_Empty(&irf_CommandQueue))
    {
        QUEUE_Get(&irf_CommandQueue,(u8*)irf_CommandBuff);
        return 1;
    }
    return 0;
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
