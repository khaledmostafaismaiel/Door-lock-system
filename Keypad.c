#define F_CPU 8000000UL

#include "keypad.h"

uint8_t Keypad_Aq[NUM_OF_ROWS][NUM_OF_COLOMS] =
	{
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'}};

uint8_t get_pressed_key(void)
{

	for (col = 0; col < NUM_OF_COLOMS; col++)
	{
		DDRC = (0b00010000 << col); // 0001 0000      0010 0000       0100 0000    1000 0000
		PORTC = ~(0b00010000 << col);

		for (row = 0; row < NUM_OF_ROWS; row++)
		{
			if (!(PINC & (1 << row))) // if pressed
			{
				set_counter_timer1A_init();
				while (!(PINC & (1 << row)))
					;
				if (timer1Aextra_time >= wait_for_3sec_timer1)
				{
					is_long_pressed = 1;
#if DEBUGE == 1
					LCD_Clear(LCD0);
					LCD_Write_String(LCD0, "LONG PRESSED.");
					_delay_ms(1000);
					LCD_Clear(LCD0);
#endif
				}
				else
				{
					is_long_pressed = 0;
#if DEBUGE == 1
					LCD_Clear(LCD0);
					LCD_Write_String(LCD0, "NOT LONG PRESSED.");
					_delay_ms(1000);
					LCD_Clear(LCD0);
#endif
				}
				reset_counter_timer1A_init();
				return what_key();
			}
		}
	}

	return NOT_PRESSED_LETTER;
}

uint8_t what_key()
{
	hash_checker = Keypad_Aq[row][col];
	if (hash_checker == '#')
	{
		is_hash = 1;
#if DEBUGE == 1
		LCD_Clear(LCD0);
		LCD_Write_String(LCD0, "IS HASH.");
		_delay_ms(1000);
		LCD_Clear(LCD0);
#endif
	}
	else
	{

		is_hash = 0;
#if DEBUGE == 1
		LCD_Clear(LCD0);
		LCD_Write_String(LCD0, "NOT HASH.");
		_delay_ms(1000);
		LCD_Clear(LCD0);
#endif
	}

	return Keypad_Aq[row][col];
}
