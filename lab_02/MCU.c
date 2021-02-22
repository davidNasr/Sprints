#include "MCU.h"

void MCU_EnableException (MCU_ExceptionType exceptionType)
{
	if(exceptionType == MCU_Programmable)
	{
		asm("CPSIE i");
	}else if(exceptionType == MCU_Fault)
	{
		asm("CPSIE f");
	}
	
	/* Switch to user mode */
	asm("MOV R0, #0x01");
	asm("MSR CONTROL, R0");
}
void MCU_DisableException (MCU_ExceptionType exceptionType)
{
	if(exceptionType == MCU_Programmable)
	{
		asm("CPSDE i");
	}else if(exceptionType == MCU_Fault)
	{
		asm("CPSDE f");
	}
	
	/* Switch to user mode */
	asm("MOV R0, #0x01");
	asm("MSR CONTROL, R0");
}