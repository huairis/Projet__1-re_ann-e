#include "main.h"

// Fonction principale
int main(void)
{
    // Initialisation HAL et horloge
    HAL_Init();
    SystemClock_Config();

    // Initialisation GPIO
    MX_GPIO_Init();

    // Boucle principale
    while (1)
    {
        // Si bouton B1 appuyé (PC13 = 0)
        if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // Allume IR + LED verte
        }
        else
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // Éteint IR + LED verte
        }
    }
}
