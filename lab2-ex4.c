#include "system.h"
//#include "led.h"
#include "pio.h"
#include "timer.h"
/* Include the pacer module from the previous lab.
   You must have completed this before starting this lab2-exercise.  */
#include "pacer.h"

int main (void)
{
    system_init ();
     //led_init ();

    pio_config_set(LEDMAT_COL1_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL2_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL3_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL4_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL5_PIO,PIO_OUTPUT_HIGH);

    pio_config_set(LEDMAT_ROW1_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW2_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW3_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW4_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW5_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW6_PIO,PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW7_PIO,PIO_OUTPUT_HIGH);
    pacer_init (500);
    /* TODO: Initialise the pins of the LED matrix.  */


    /* Set up pacer with a frequency of 50 Hz.  */

    while (1)
    {
        /* Pace the loop.  */
        pacer_wait ();
        pio_output_high(LEDMAT_COL1_PIO);
        pio_output_high(LEDMAT_ROW1_PIO);
        pio_output_high(LEDMAT_ROW7_PIO);
        pio_output_high(LEDMAT_COL5_PIO);

        pio_output_low(LEDMAT_COL1_PIO);
        pio_output_low(LEDMAT_ROW1_PIO);

        pio_output_high(LEDMAT_COL1_PIO);
        pio_output_high(LEDMAT_ROW1_PIO);

        pio_output_low(LEDMAT_COL5_PIO);
        pio_output_low(LEDMAT_ROW1_PIO);

        pio_output_high(LEDMAT_COL5_PIO);
        pio_output_high(LEDMAT_ROW1_PIO);

        pio_output_low(LEDMAT_COL5_PIO);
        pio_output_low(LEDMAT_ROW7_PIO);
        /* TODO: Drive the LED matrix using the pio functions,
           displaying only three corner LEDs.  */
    }
}
