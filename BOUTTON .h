#ifndef BUTTONS_H
#define BUTTONS_H

#include "stm32l4xx_hal.h"   // bibliothèque HAL pour la STM32

/* Définition des broches des boutons */
#define BTN1_PIN GPIO_PIN_0
#define BTN2_PIN GPIO_PIN_1
#define BTN3_PIN GPIO_PIN_2
#define BTN4_PIN GPIO_PIN_3
#define BTN5_PIN GPIO_PIN_4

/* Tous les boutons sont connectés sur le port GPIOC */
#define BTN_PORT GPIOC

/* Fonctions disponibles pour le module boutons */
void Buttons_Init(void);     // initialise les boutons
uint8_t Buttons_Read(void);  // retourne le numéro du bouton appuyé

#endif
