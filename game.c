#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "pio.h"

#define PACER_RATE 200
#define MESSAGE_RATE 10

/** Define PIO pins driving LED matrix rows.  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO,
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};


/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};




static void display_column (uint8_t row_pattern, uint8_t current_column)
{

     static uint8_t previous_column = 0;
    pio_output_high (cols[previous_column]);
    uint8_t current_row = 0;

    for (current_row = 0; current_row <= 6; current_row++) {
        if ((row_pattern >> current_row & 1)) {
            pio_output_low (rows[current_row]);
        } else {
            pio_output_high (rows[current_row]);
        }
    }

    pio_output_low (cols[current_column]);
    previous_column = current_column;




}

void welcome (void)
{

    tinygl_text("start!");
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
}

void display_board1(void)
{
     uint8_t current_column = 0;
       static const uint8_t bitmap[] =
{
    //0x7e, 0x48, 0x48, 0x48, 0x7e //siscor
    //0x3e, 0x22, 0x22, 0x22, 0x3e // paper
    0x1c, 0x22, 0x22, 0x22, 0x1c //rock


};
     while (1)
    {
        pacer_wait ();

        display_column (bitmap[current_column], current_column);

        current_column++;

        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }
    }
}

void display_board2(void)
{
     uint8_t current_column = 0;
       static const uint8_t bitmap[] =
{
    //0x7e, 0x48, 0x48, 0x48, 0x7e //siscor
    0x3e, 0x22, 0x22, 0x22, 0x3e // paper
    //0x1c, 0x22, 0x22, 0x22, 0x1c //rock


};
     while (1)
    {
        pacer_wait ();

        display_column (bitmap[current_column], current_column);

        current_column++;

        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }
    }
}

void display_board3(void)
{
     uint8_t current_column = 0;
       static const uint8_t bitmap[] =
{
    0x7e, 0x48, 0x48, 0x48, 0x7e //siscor
    //0x3e, 0x22, 0x22, 0x22, 0x3e // paper
    //0x1c, 0x22, 0x22, 0x22, 0x1c //rock


};
     while (1)
    {
        pacer_wait ();

        display_column (bitmap[current_column], current_column);

        current_column++;

        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }
    }
}




void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

int main (void)
{
    system_init ();
    ir_uart_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();

    /* TODO: Initialise IR driver.  */
    //tinygl_text("START!\0");
    welcome();
    uint8_t current_column = 0;

    system_init ();
    pacer_init (500);
    pio_config_set (LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_COL2_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_COL3_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_COL4_PIO, PIO_OUTPUT_HIGH);
        pio_config_set (LEDMAT_COL5_PIO, PIO_OUTPUT_HIGH);



    while (1)
    {
        pacer_wait ();
        tinygl_update ();
        navswitch_update();
        /* TODO: Call the navswitch update function.  */
        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            display_board1();
            ir_uart_putc('R');

            if (ir_uart_read_ready_p()) {
                if (ir_uart_getc() == 'R') {
                    display_character('0');
                } else if (ir_uart_getc() == 'S') {
                    display_character('W');
                } else if (ir_uart_getc() == 'P') {
                    display_character('L');
                }
            }
        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
            display_board2();
            ir_uart_putc('P');

            if (ir_uart_read_ready_p()) {
                if (ir_uart_getc() == 'P') {
                    display_character('0');
                } else if (ir_uart_getc() == 'S') {
                    display_character('L');
                } else if (ir_uart_getc() == 'R') {
                    display_character('W');
                }
            }
        } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            display_board3();
            ir_uart_putc('S');

            if (ir_uart_read_ready_p()) {
                if (ir_uart_getc() == 'S') {
                    display_character('0');
                } else if (ir_uart_getc() == 'P') {
                    display_character('W');
                } else if (ir_uart_getc() == 'R') {
                    display_character('L');
                    }
                    }
                    }
                }
        return 0;
}
