#include "main.h"
#include "buttons.h"
#include "ir_tx.h"

int main(void)
{

    HAL_Init();              // initialise la bibliothèque HAL
    SystemClock_Config();    // configure l'horloge du microcontrôleur

    Buttons_Init();          // initialise les boutons
    IR_Init();               // initialise l'émetteur infrarouge

    uint8_t button;          // variable qui stocke le bouton appuyé


    while (1)                // boucle infinie du programme
    {

        button = Buttons_Read();  // lecture des boutons


        switch(button)
        {

            case 1:
                IR_Send(0x01);  // envoie code 1
                break;

            case 2:
                IR_Send(0x02);  // envoie code 2
                break;

            case 3:
                IR_Send(0x03);  // envoie code 3
                break;

            case 4:
                IR_Send(0x04);  // envoie code 4
                break;

            case 5:
                IR_Send(0x05);  // envoie code 5
                break;

        }

        HAL_Delay(200);  // petite pause pour éviter les répétitions trop rapides
    }
}
