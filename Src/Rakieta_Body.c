/*
 * Rakieta_Body.c
 *
 *  Created on: 11 sie 2022
 *      Author: dawid
 */
#include "main.h"
#include "rakieta_model_do_autogeneracji_kodu.h"
#include "init_can.h"
#include "can_as.h"


#define PWM_OUTPUT_1(x)    TIM2->CCR3=x
#define PWM_OUTPUT_2(x)    TIM2->CCR4=x
#define PWM_OUTPUT_3(x)    TIM15->CCR1=x
#define PWM_OUTPUT_4(x)    TIM15->CCR2=x

uint8_t led=0;
volatile uint32_t _20ms;
volatile uint32_t _500ms;
volatile uint32_t input_update[2];

data_t data;
output_t serwa;
volatile int32_t pwm_input[2];
const ConstP rtConstP;

//rakieta_model_do_autogeneracji_kodu_initialize();

void PWM_OUT()
{
	if(input_update[0]==1)
		  {
			  input_update[0]=0;
			  // used for value serwa.pwm_input[0] coming from function MATLAB
			  serwa.pwm_output[0]=serwa.pwm_input[0]*5+1500;
			  serwa.pwm_output[1]=3000-(serwa.pwm_input[0]*5+1500);
			  //  used for value serwa.pwm_input[0] coming from remote device
			 // serwa.pwm_output[0]=serwa.pwm_input[0];
			 // serwa.pwm_output[1]=3000-serwa.pwm_input[0];
			  PWM_OUTPUT_1(serwa.pwm_output[0]);
			  PWM_OUTPUT_2(serwa.pwm_output[1]);
		  }

		  if(input_update[1]==1)
		  {
			  input_update[1]=0;
			  //used for value serwa.pwm_input[1] coming from function MATLAB
			  serwa.pwm_output[2]=serwa.pwm_input[1]*5+1500;
			  serwa.pwm_output[3]=3000-(serwa.pwm_input[1]*5+1500);
			  // used for value serwa.pwm_input[1] coming from remote device
			  //serwa.pwm_output[2]=serwa.pwm_input[1];
			  //serwa.pwm_output[3]=3000-serwa.pwm_input[1];
			  PWM_OUTPUT_3(serwa.pwm_output[2]);
			  PWM_OUTPUT_4(serwa.pwm_output[3]);
		  }
}

void MATLAB()
{
	if(_20ms==1)
		  {
			  _20ms=0;

			  // rewritting data to inputs function rakieta_model_do_autogeneracji_kodu_step
			  rtU.v = data.tas;
			  rtU.przechylenie = data.fi;
			  rtU.pochylenie = data.teta;

			  // starting the function rakieta_model_do_autogeneracji_kodu_step
			 rakieta_model_do_autogeneracji_kodu_step();

			 // rewritting the answer computed from function rakieta_model_do_autogeneracji_kodu_step to variables serwa.pwm_input
			  serwa.pwm_input[0] = rtY.kanal_przech;
			  serwa.pwm_input[1] = rtY.kanal_poch;

			  // sending data after matlab has computed the answer
			  input_update[0]=1;
			  input_update[1]=1;

			  can_transmit_proc(&serwa);
		  }
}

void DIODA_LED()
{
	if(_500ms == 1)
		  {
	 	      _500ms = 0;
	          if(led==0)
	          {
	        	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
	        	 led=1;
	          }
	          else
	          {
				 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
				 led=0;
	          }
		  }
}

void APARATURA_ODCZYT(uint16_t GPIO_Pin)
{
	//switch(GPIO_Pin)
		//{
		   	if(GPIO_Pin==GPIO_PIN_6)
			{
				  static int32_t start_time;
				  int32_t pulse_lenght = 0;
				  if(!(GPIOA->IDR & GPIO_IDR_6)) // PWM in low
				  {
					 pulse_lenght = TIM4->CNT - start_time;
					 if(pulse_lenght < 0) serwa.pwm_input[1] = pulse_lenght + 0xFFFF;
					 else serwa.pwm_input[1] = pulse_lenght;
					 input_update[1] = 1;
				  }
				  else // PWM in hight
				  {
					 start_time = TIM4->CNT;
				  }
			}//break;
		   	if(GPIO_Pin==GPIO_PIN_7)
			{
		   	      static int32_t start_time;
		   	      int32_t pulse_lenght = 0;
		   	      if(!(GPIOA->IDR & GPIO_IDR_7)) // PWM in low
		   	      {
		   	         pulse_lenght = TIM4->CNT - start_time;
		   	         if(pulse_lenght < 0) serwa.pwm_input[0] = pulse_lenght + 0xFFFF;
		   	         else serwa.pwm_input[0] = pulse_lenght;
		   	         input_update[0] = 1;
		   	      }
		   	      else // PWM in hight
		   	      {
		   	         start_time = TIM4->CNT;
		   	      }
			}//break;
		//}
}
