/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/


#ifndef IRF_H

#define IRF_H


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

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



/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void IRF_Init(void);

void IRF_Proc(void);

void IRF_Send(u8* buff, u8 length);

void IRF_QueueClear();
#endif	/* IRF_H_ */