#include "ir_tx.h"

/* Fonction qui initialise la LED infrarouge */
void IR_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0}; // structure de configuration

    __HAL_RCC_GPIOB_CLK_ENABLE(); // active l'horloge du port GPIOB

    /* Configuration de la broche comme sortie */
    GPIO_InitStruct.Pin = IR_PIN;

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // sortie push-pull

    GPIO_InitStruct.Pull = GPIO_NOPULL;           // pas de résistance interne

    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; // vitesse rapide pour le signal

    HAL_GPIO_Init(IR_PORT, &GPIO_InitStruct);     // applique la configuration
}


/* Fonction qui envoie un code infrarouge */
void IR_Send(uint8_t data)
{

    /* boucle pour envoyer les 8 bits du code */
    for(int i = 0; i < 8; i++)
    {

        /* vérifie si le bit est à 1 */
        if(data & (1 << i))
        {
            HAL_GPIO_WritePin(IR_PORT, IR_PIN, GPIO_PIN_SET); // allume la LED IR
        }
        else
        {
            HAL_GPIO_WritePin(IR_PORT, IR_PIN, GPIO_PIN_RESET); // éteint la LED IR
        }

        HAL_Delay(1); // petite temporisation
    }

    /* on éteint la LED à la fin */
    HAL_GPIO_WritePin(IR_PORT, IR_PIN, GPIO_PIN_RESET);
}
