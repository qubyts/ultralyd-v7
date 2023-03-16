#include "BuzzerTask.h"
#include "main.h"
#include "stm32f4xx_hal_conf.h"
#include "Myapp.h"
#include "stdbool.h"
#include "cmsis_os.h"
#include "main.h"
#include "stdio.h"
#include "tim.h"
#include "print_server.h"
#include "usart.h"


/* Definitions for Buzzer_Task */
osThreadId_t Buzzer_TaskHandle;
const osThreadAttr_t Buzzer_Task_attributes = {
  .name = "Buzzer_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal7,
};


void Start_BuzzerTask(void *argument);



char txbuff1[50];
void Start_BuzzerTask(void *argument)
{
  /* USER CODE BEGIN StartBuzzer */
	  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	  TIM5->CCR1 = 1000;
	  int buzzer_toggle = 0;
	  int buzzer_toggle_cont = 0;
	  int buzzer_toggle_delay = 0;
	  int distance = 0;
	 ;

  /* Infinite loop */
  for(;;)
  {
	  distance = (captured_value1);

	  distance = (captured_value1/6.15)*0.0342;
	  printf("CCR1-2 is %i \n", captured_value1);
	  printf("distance is: %i cm \n \r", distance);
	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	  if((distance > 0)&&(distance <30))
		  {
			  buzzer_toggle_delay = 1000;
			  buzzer_toggle_cont = 1;
		  }
	  else if((distance >= 30)&&(distance <60))
		  {
			  buzzer_toggle_delay = 125;
			  buzzer_toggle_cont = 0;
		  }
	  else if((distance >= 60)&&(distance <90))
	  	  {
			  buzzer_toggle_delay = 142;
			  buzzer_toggle_cont = 0;
	  	  }
	  else if((distance >= 90)&&(distance <120))
	  	  {
			  buzzer_toggle_delay = 167;
			  buzzer_toggle_cont = 0;
	  	  }
	  else if((distance >= 120)&&(distance <150))
	  	  {
			  buzzer_toggle_delay = 200;
			  buzzer_toggle_cont = 0;
	  	  }
	  else if((distance >= 150)&&(distance <180))
	  	  {
			  buzzer_toggle_delay = 250;
			  buzzer_toggle_cont = 0;
	  	  }
	  else if((distance >= 180)&&(distance <210))
	  	  {
			  buzzer_toggle_delay = 333;
			  buzzer_toggle_cont = 0;
	  	  }
	  else if((distance >= 210)&&(distance <270))
	  	  {
			  buzzer_toggle_delay = 500;
			  buzzer_toggle_cont = 0;
	  	  }

	  else if((distance >= 270)&&(distance <=300))
	  	  {
			  buzzer_toggle_delay = 1000;
			  buzzer_toggle_cont = 0;
	  	  }

	  //sprintf(txbuff1,"distance: %d\n\r",distance);
	  //HAL_UART_Transmit(&huart2, &txbuff1, 20, 100);
	  if(buzzer_toggle == 1)
	  {
		  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
		  buzzer_toggle = 0;

	  }
	  else if((buzzer_toggle == 0)&&(buzzer_toggle_cont == 0))
	  {
		  HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_1);
		  buzzer_toggle = 1;
	  }
	  else
	  {
		  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
		  buzzer_toggle = 0;
	  }
	  if(distance < 1)
	  {
		  buzzer_toggle_delay = 2000;
		  HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_1);
	  }
	  if(distance >300)
	  {
		  buzzer_toggle_delay = 2000;
		  HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_1);
	  }

    osDelay(buzzer_toggle_delay);
  }

}
void buzzer_init(){
/* creation of Buzzer_Task */
Buzzer_TaskHandle = osThreadNew(Start_BuzzerTask, &captured_value1, &Buzzer_Task_attributes);
}
