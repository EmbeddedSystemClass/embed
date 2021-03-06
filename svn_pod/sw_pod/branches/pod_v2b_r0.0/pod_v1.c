/******************** (C) COPYRIGHT 2011 **************************************
* File Name          : pod_v1.c
* Hackeroos          : caw, deh
* Date First Issued  : 08/30/2011
* Board              : STM32F103VxT6_pod_mm (USART1)
* Description        : Main program for version implementation
*******************************************************************************/
/*
08-30-2011

Subroutine call references shown as "@n"--
@1 = svn_pod/sw_pod/trunk/pod_v1/p1_normal_run.c
@2 = svn_pod/sw_pod/trunk/pod_v1/p1_cold_run.c
@3 = svn_pod/sw_pod/trunk/pod_v1/p1_get_reset_mode.c
@4 = svn_pod/sw_pod/trunk/pod_v1/p1_initialization.c
@5 = svn_pod/sw_pod/trunk/RS232_ctl.c

*/
#include "pod_v1.h"
#include "p1_initialization.h"
#include "p1_normal_run.h"
#include "p1_common.h"
#include <string.h>



int main (void)
{
	/* Basic initialization required for all modes */
	p1_initialization_basic();	// Return with clocks, pins, some pwr switches setup. (@4)

/* ========== Temp for debugging ============= */
//MAX3232SW_on		// Turn on RS-232 level converter (if doesn't not on RS-232 chars are not seen) (@1)
//cRS232_skip_flag = 1;	// Set flag. Only do initialization once! (@5)
/* Initialize USART and setup control blocks and pointer */
//USART1_rxinttxint_initRTC(115200,96,2,48,4);	//  (@5)
/* Initialize UART4 (GPS) */
//UART4_rxinttxint_initRTC(4800,96,2,48,4);	//  (@5)
/* Announce who we are */
//USART1_txint_puts("\n\rpod_v1 11-21-2011\n\r"); USART1_txint_send();
/* =============== End temp ================== */

	p1_normal_run();	// Setup and do tension logging, etc.

	/* Never comes back here (unless a bug) */
	while (1==1);
	return 0;
}
