
#include <xc.h>
#include "IO.h"
#include "PWM.h"

#define PWMPER 24.0

void InitPWM(void)
{
    PTCON2bits.PCLKDIV = 0b000; // Division par 1

    PTPER = 100 * PWMPER; // Période en pourcentage

    // Réglage PWM moteur 1 sur hacheur 1
    IOCON1bits.PMOD = 0b11; // Mode True Independent Output
    IOCON1bits.PENL = 1;
    IOCON1bits.PENH = 1;

    FCLCON1 = 0x0003; // Désactivation de la gestion des faults

    // Réglage PWM moteur 2 sur hacheur 2
    IOCON2bits.PMOD = 0b11; // Mode True Independent Output
    IOCON2bits.PENL = 1;
    IOCON2bits.PENH = 1;

    FCLCON2 = 0x0003; // Désactivation de la gestion des faults

    // Activation du module PWM
    PTCONbits.PTEN = 1;
}


double talon = 50;

void PWMSetSpeed(float vitesseEnPourcents, int moteur)
{if (moteur == 0){
    if (vitesseEnPourcents > 0)
    {
        PDC1 = vitesseEnPourcents * PWMPER + talon;
        SDC1 = talon;
    }
    else if (vitesseEnPourcents < 0)
    {
        SDC1 = -vitesseEnPourcents * PWMPER + talon;
        PDC1 = talon;
    }
    else
    {
        PDC1 = 0;
        SDC1 = 0;
    }
    
}else{
if (vitesseEnPourcents > 0)
    {
        PDC2 = vitesseEnPourcents * PWMPER + talon;
        SDC2 = talon;
    }
    else if (vitesseEnPourcents < 0)
    {
        SDC2 = -vitesseEnPourcents * PWMPER + talon;
        PDC2 = talon;
    }
    else
    {
        PDC2 = 0;
        SDC2 = 0;
    }
}
}

