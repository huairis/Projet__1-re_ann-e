#ifndef IR_TX_H
#define IR_TX_H

#include "stm32l4xx_hal.h"

/* Définition de la broche utilisée pour la LED infrarouge */
#define IR_PIN GPIO_PIN_0
#define IR_PORT GPIOB

/* Fonctions du module infrarouge */
void IR_Init(void);          // initialise la sortie infrarouge
void IR_Send(uint8_t data);  // envoie un code infrarouge

#endif
