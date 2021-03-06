/* own header files */
#include "XdkAppInfo.h"

#undef BCDS_MODULE_ID  /* Module ID define before including Basics package*/
#define BCDS_MODULE_ID XDK_APP_MODULE_ID_MAIN

/* system header files */
#include <stdio.h>
#include "BCDS_Basics.h"

/* additional interface header files */
#include "XdkSystemStartup.h"
#include "BCDS_Assert.h"
#include "AppController.h"
#include "BCDS_CmdProcessor.h"
#include "FreeRTOS.h"
#include "task.h"

/* global variables ********************************************************* */
static CmdProcessor_T MainCmdProcessor;

/* functions */

int main(void)
{
    /* Mapping Default Error Handling function */
    Retcode_T retcode = Retcode_Initialize(DefaultErrorHandlingFunc);
    if (RETCODE_OK == retcode)
    {
        retcode = systemStartup();
    }
    if (RETCODE_OK == retcode)
    {
        retcode = CmdProcessor_Initialize(&MainCmdProcessor, (char *) "MainCmdProcessor", TASK_PRIO_MAIN_CMD_PROCESSOR, TASK_STACK_SIZE_MAIN_CMD_PROCESSOR, TASK_Q_LEN_MAIN_CMD_PROCESSOR);
    }
    if (RETCODE_OK == retcode)
    {

        retcode = CmdProcessor_Enqueue(&MainCmdProcessor, AppController_Init, &MainCmdProcessor, UINT32_C(0));
    }
    if (RETCODE_OK == retcode)
    {
        /* start scheduler */
        vTaskStartScheduler();
        /* Code must not reach here since the OS must take control. If not, we will assert. */
    }
    else
    {
        Retcode_RaiseError(retcode);
        printf("main : XDK System Startup failed.\r\n");
    }
    assert(false);
}
