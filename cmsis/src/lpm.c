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
Cortex-M0/Cortex-M0+ �͹�������˵��:
	1.�����ܹ���ص�����ģʽ:
		-- Normal sleep.		//	��ͨ����
		-- Deep sleep.			//	�������
	2.����ָ������ڽ�����ͨ����ģʽ���������ģʽ:	
		-- WFI					
		-- WFE
	3.������ͨ����ģʽ�����������ģʽ��ϵͳ���ƿ�(SCB)��ϵͳ���ƼĴ���(SCB->SCR)�� SLEEPDEEP λ����:
		-- 0		//	�������ߺ���ͨ����ģʽ�ᱻѡ��;
		-- 1 	//	�������ߺ��������ģʽ�ᱻѡ��;
	4.���˳��쳣���������س����߳�ʱ���������Ƿ�������������ģʽ(WFI)���� SCB->SCR �� SLEEPONEXIT λ����:
		-- 0		//	ʹ��
		-- 1		//	��ֹ

Note:
	1.ϵͳ���ƿ� SCB ������ݿɲο�: <<Cortex-M0/Cortex-M0+ Ȩ��ָ��>>;
*******************************************************************************************************************
*/




/**
 *****************************************************************************
 ** \brief �����������ģʽ
 **
 ** \input bOnExit - TRUE: 	���˳��쳣�������ٴ��Զ���������ģʽ;
 **                  FALSE:	���Ѻ����Զ���������;
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
 ** \brief ������ͨ����ģʽ
 **
 ** \input bOnExit - TRUE:	���˳��쳣�������ٴ��Զ���������ģʽ;
 **                  FALSE:	���Ѻ����Զ���������;
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