#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "robot.h"


int main (void){
    /************************************************************************************************/
    //Initialisation oscillateur
    /***********************************************************************************************/
    InitOscillator();
    InitIO();
    
    // Initialisation timer
    InitTimer1();
    InitTimer23();
    
    /************************************************************************************************/
    //Initialisation pwm robot
    /***********************************************************************************************/
    InitPWM();
    // Initialisation des vitesses
    robotState.vitesseGaucheConsigne = 20;
    robotState.vitesseDroiteConsigne = 20;

    robotState.vitesseGaucheCommandeCourante = 0;
    robotState.vitesseDroiteCommandeCourante = 0;


  
    
    /***********************************************************************************************/
    // Configuration des input et output (IO)
    /***********************************************************************************************/
    LED_BLANCHE_1 = 1;
    LED_BLEUE_1 = 1;
    LED_ORANGE_1 = 1;
    LED_ROUGE_1 = 1;
    LED_VERTE_1 = 1;
    
    LED_BLANCHE_2 = 1;
    LED_BLEUE_2 = 1;
    LED_ORANGE_2 = 1;
    LED_ROUGE_2 = 1;
    LED_VERTE_2 = 1;

    /***********************************************************************************************/
    // Boucle Principale
    /***********************************************************************************************/
    while(1)
    {
//        LED_BLANCHE_1 = !LED_BLANCHE_1;
//        LED_BLEUE_1 = !LED_BLEUE_1;
        
    } // fin main
    
    
}
