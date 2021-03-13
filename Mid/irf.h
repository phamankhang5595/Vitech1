#ifndef __IRF_H__
#define __IRF_H__
/*******************************************************************************
 * Definition
 ******************************************************************************/
#define IRF_BUFF_MAX        5
#define IRF_QUEUE_MAX       5
#define IRF_HEADER          4

typedef struct irf_Command_t
{
    u8 command;
    u8 type;
    u8 senquence;
    u8 length;
    u8 buff[IRF_BUFF_MAX];
} irf_Command_t;
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief IRF_INIT
 *
 * @param 
 * @param 
 */
void IRF_Init();

/*!
 * @brief 
 *
 * @param 
 * @param 
 */
u8 IRF_GetCommand(irf_Command_t *irf_CommandBuff)
#endif  /* IRF_H */