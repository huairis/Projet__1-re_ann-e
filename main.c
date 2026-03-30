#include "main.h"
#include "ir_send.h"

extern TIM_HandleTypeDef htim2;

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_TIM1_Init();
    MX_TIM2_Init();

    HAL_TIM_Base_Start(&htim2);

    while (1)
    {
        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==GPIO_PIN_RESET)
        {
            IR_SendCommand(0x01); // ON/OFF
            HAL_Delay(300);
        }

        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==GPIO_PIN_RESET)
        {
            IR_SendCommand(0x02); // Bright +
            HAL_Delay(200);
        }

        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)==GPIO_PIN_RESET)
        {
            IR_SendCommand(0x03); // Bright -
            HAL_Delay(200);
        }

        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)==GPIO_PIN_RESET)
        {
            IR_SendCommand(0x04); // Color
            HAL_Delay(300);
        }

        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==GPIO_PIN_RESET)
        {
            IR_SendCommand(0x05); // Mode
            HAL_Delay(300);
        }
    }
}

        }

        HAL_Delay(200);  // petite pause pour éviter les répétitions trop rapides
    }
}
