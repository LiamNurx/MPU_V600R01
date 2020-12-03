/******************************************************************************
*Copyright(C)2017, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC
* components. This software is licensed by HDSC to be adapted only
* for use in systems utilizing HDSC components. HDSC shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. HDSC is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/** \file lpm.c
 **
 ** Common API of lpm.
 ** @link LpmGroup Some description @endlink
 **
 **   - 2017-06-06
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "lpm.h"
/**
 *******************************************************************************
 ** \addtogroup LpmGroup
 ******************************************************************************/
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/                                     

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/*
*******************************************************************************************************************
Cortex-M0/Cortex-M0+ 低功耗特性说明:
	1.两个架构相关的休眠模式:
		-- Normal sleep.		//	普通休眠
		-- Deep sleep.			//	深度休眠
	2.两个指令都可用于进入普通休眠模式和深度休眠模式:	
		-- WFI					
		-- WFE
	3.进入普通休眠模式还是深度休眠模式由系统控制块(SCB)中系统控制寄存器(SCB->SCR)的 SLEEPDEEP 位控制:
		-- 0		//	进入休眠后，普通休眠模式会被选中;
		-- 1 	//	进入休眠后，深度休眠模式会被选中;
	4.当退出异常处理并返回程序线程时，处理器是否立即进入休眠模式(WFI)，由 SCB->SCR 的 SLEEPONEXIT 位决定:
		-- 0		//	使能
		-- 1		//	禁止

Note:
	1.系统控制块 SCB 相关内容可参考: <<Cortex-M0/Cortex-M0+ 权威指南>>;
*******************************************************************************************************************
*/




/**
 *****************************************************************************
 ** \brief 进入深度休眠模式
 **
 ** \input bOnExit - TRUE: 	当退出异常处理后，再次自动进入休眠模式;
 **                  FALSE:	唤醒后不再自动进入休眠;
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void Lpm_GotoDeepSleep(boolean_t bOnExit)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    SCB->SCR |= 1u<<bOnExit;
    __WFI();
}

/**
 *****************************************************************************
 ** \brief 进入普通休眠模式
 **
 ** \input bOnExit - TRUE:	当退出异常处理后，再次自动进入休眠模式;
 **                  FALSE:	唤醒后不再自动进入休眠;
 ** 
 ** \retval NULL                                     
 *****************************************************************************/
void Lpm_GotoSleep(boolean_t bOnExit)
{
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    SCB->SCR |= 1u<<bOnExit;
    __WFI();
}
                        
//@} // LpmGroup                                                                           

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
