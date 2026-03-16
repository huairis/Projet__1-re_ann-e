#include "buttons.h"

/* Fonction qui initialise les 5 boutons */
void Buttons_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};  // structure utilisée pour configurer les GPIO

    __HAL_RCC_GPIOC_CLK_ENABLE();  // active l'horloge du port GPIOC

    /* Configuration des 5 broches comme entrées */
    GPIO_InitStruct.Pin = BTN1_PIN | BTN2_PIN | BTN3_PIN | BTN4_PIN | BTN5_PIN;

    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;  // mode entrée

    GPIO_InitStruct.Pull = GPIO_PULLDOWN;    // résistance pull-down interne
                                             // la pin reste à 0 si le bouton n'est pas pressé

    HAL_GPIO_Init(BTN_PORT, &GPIO_InitStruct); // applique la configuration
}


/* Fonction qui détecte quel bouton est appuyé */
uint8_t Buttons_Read(void)
{

    /* Lecture du bouton 1 */
    if(HAL_GPIO_ReadPin(BTN_PORT, BTN1_PIN) == GPIO_PIN_SET)
        return 1;

    /* Lecture du bouton 2 */
    if(HAL_GPIO_ReadPin(BTN_PORT, BTN2_PIN) == GPIO_PIN_SET)
        return 2;

    /* Lecture du bouton 3 */
    if(HAL_GPIO_ReadPin(BTN_PORT, BTN3_PIN) == GPIO_PIN_SET)
        return 3;

    /* Lecture du bouton 4 */
    if(HAL_GPIO_ReadPin(BTN_PORT, BTN4_PIN) == GPIO_PIN_SET)
        return 4;

    /* Lecture du bouton 5 */
    if(HAL_GPIO_ReadPin(BTN_PORT, BTN5_PIN) == GPIO_PIN_SET)
        return 5;

    /* Aucun bouton appuyé */
    return 0;
}
