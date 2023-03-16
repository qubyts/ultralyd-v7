#include "main.h"
#include "stm32f4xx_hal_conf.h"
#include "Myapp.h"
#include "stdbool.h"
#include "BuzzerTask.h"
#include "cmsis_os.h"
#include "main.h"
#include "stdio.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

osThreadId_t timerTaskHandle;
const osThreadAttr_t timerTask_attributes = {
  .name = "timerTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
void StarttimerTask(void *argument);

void StarttimerTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
	//HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
  /* Infinite loop */
  for(;;)
  {
if (hardwareDelayFlag == 0){
	  		TIM2->ARR = 22500;
	  		__HAL_TIM_ENABLE(&htim2);
	  		TIM1->CCR1 = 2250;

	  		HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	  		hardwareDelayFlag = 1;
	  		TIM4->DIER &= ~(1<<1);
	  		//TIM4->CCR1;
}

//	  	    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

void deftask_init(){
	/* creation of defaultTask */
	timerTaskHandle = osThreadNew(StarttimerTask, NULL, &timerTask_attributes);
}
