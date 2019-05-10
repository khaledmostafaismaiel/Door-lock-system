/*
 * app.c
 *
 * Created: 4/13/2019 4:04:05 AM
 *  Author: Khaled's Lap
 */


#define F_CPU 8000000UL
#include "app.h"


void run(void)
{

	first_entry_validation();

	passkey_loading();

	close_door(); //to make sure the door is close

#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "CLOSE DOOR.");
#endif

	while (door_is_close == 0)
	{
		_delay_ms(10);		
		if (limit_switch_flag == 1)
		{
			close_limit_switch_checker();
			limit_switch_flag = 0;
		}
	}

#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "DOOR IS CLOSED.");
	_delay_ms(1000);
	LCD_Clear(LCD0);
#endif


distance_from_object = 0 ;

uint8_t i = 0 ;

set_int0_init();
while (i < SAMPLING_NUMBER){

_delay_ms(10);		

if (ultra_flag == 1)
{
	ultra_flag = 0;
	ultra_scan();

if ((distance_from_object > 0) && (distance_from_object <= DETECTION_DISTANCE))
{
	++i;
}else{
	i=0 ;
}


}
		
#if DEBUGE == 1
itoa(distance_from_object, buffer, 10);
LCD_Write_String(LCD0, buffer);
_delay_ms(100);
LCD_Clear(LCD0);
#endif		
		
		
}

reset_int0_init();

reset_ultra_timer1();

passkey_loading();

load_number_of_triles();

MainMassage();

counter = 0 ;
current = 0 ;
punish = 1	;
coreect_pass_key = 0 ;	
mission_done = 0 ;

while (coreect_pass_key == 0){
	
#if DEBUGE == 1
		DDRD |=  (1 << TEST_LED_PIN) ;
		PORTD ^=  (1 << TEST_LED_PIN);
		_delay_ms(100);		
#endif

if (punish == 1)
{
do_punish();
}


if ( (is_hash == 1) && (is_long_pressed == 1) && (current == 0) )
{
			
old_passkey_scanning();
reset_payload();
new_passkey_scanning();
reset_payload();

mission_done = 1 ;
				
}

_delay_ms(10);

if (mission_done == 0)
{

		passkey_scanning();
	
}



}
mission_done = 0 ;
reset_number_of_triles();
LCD_Clear(LCD0);	
open_door();

#if DEBUGE == 1
LCD_Write_String(LCD0, "OPEN DOOR.");
_delay_ms(2000);
#endif

	set_pwm_timer2_init();
	while (door_is_open != 1)
	{
		if (limit_switch_flag == 1)
		{
			limit_switch_flag = 0;
			open_limit_switch_checker();
		}

		if (potentiometer_flag == 1)
		{
			pwm_duty(adc_read());		
		}
		if (keypad_flag == 1)
		{
			keypad_flag = 0;
			new_pressed = get_pressed_key();
			if (new_pressed != NOT_PRESSED_LETTER)
			{
			LCD_Clear(LCD0);
			LCD_Write_String(LCD0,"DOOR MUST OPEN FIRST.");
			_delay_ms(500);
			LCD_Clear(LCD0);

			}


		}
	}
reset_pwm_timer2_init();


#if DEBUGE == 1
LCD_Clear(LCD0);
LCD_Write_String(LCD0, "DOOR IS OPENED.");
_delay_ms(2000);
LCD_Clear(LCD0);
#endif
coreect_pass_key = 0 ;

timer0_init();
while(timer1_wait_for < wait_for_10sec_timer0){

_delay_ms(10);
	if (keypad_flag == 1)  //i can add scanning for the keypad because if the user want to change the passkey in this time
	{
		keypad_flag = 0; 
	}
}


close_door();

#if DEBUGE == 1
LCD_Clear(LCD0);
LCD_Write_String(LCD0, "CLOSE DOOR.");
_delay_ms(2000);
#endif

while (door_is_close != 1)
{

_delay_ms(10);

	if (limit_switch_flag == 1)
	{
		limit_switch_flag = 0;
		close_limit_switch_checker();
	}
		

}


	LCD_Clear(LCD0);
	LCD_Write_String(LCD0,"GOODBYE.");
	_delay_ms(2000);
	LCD_Clear(LCD0);





}



void new_passkey_scanning(void){
		
		LCD_Clear(LCD0);
		LCD_Write_String(LCD0, "CHOOSE NEW PASSKEY.");
		_delay_ms(3000);
		LCD_Clear(LCD0);
			
		while (set_new_passkey == 0)
		{

			#if DEBUGE == 1
			DDRD |=  (1 << TEST_LED_PIN);
			PORTD ^=  (1 << TEST_LED_PIN);
			#endif

			_delay_ms(10);

			if (keypad_flag == 1)
			{
				keypad_flag = 0;
				new_pressed = get_pressed_key();
				if (new_pressed != NOT_PRESSED_LETTER)
				{

					switch (new_pressed)
					{
						case '#':
						if (counter == PASSKEY_LENGTH)
						{
							enter = 1;
						}
						break;

						default:
						if (new_pressed != '*')
						{
							payload[current] = new_pressed;
							++current;
						}
						else
						{
							if (current > 0)
							{
								--current;		
							}
						}
						lcd_format_display(new_pressed);
						break;
					}
				}

				if ((enter == 1) && (counter == PASSKEY_LENGTH))
				{
					set_new_passkey = 1 ;
					update_passkey(payload);
				}
				else
				{
					enter = 0;
				}
			}
		}	
		
		set_new_passkey = 0 ;
	
}


void old_passkey_scanning(void){
	
			LCD_Clear(LCD0);
			LCD_Write_String(LCD0, "ENTER THE OLD PASSKEY.");
			_delay_ms(2000);
			LCD_Clear(LCD0);
while (coreect_pass_key == 0){

if (punish == 1)
{
	do_punish();
}

_delay_ms(10);

	if (keypad_flag == 1)
	{
		keypad_flag = 0;
				new_pressed = get_pressed_key();
				if (new_pressed != NOT_PRESSED_LETTER)
				{

					switch (new_pressed)
					{
						case '#':
						if (counter == PASSKEY_LENGTH)
						{
							enter = 1;
						}
						break;

						default:
						if (new_pressed != '*')
						{
							payload[current] = new_pressed;
							++current;
						}
						else
						{
							if (current > 0)
							{
								--current;
							}
						}
						lcd_format_display(new_pressed);
						break;
					}
				}

				if ((enter == 1) && (counter == PASSKEY_LENGTH))
				{
					if (pass_comparing(payload) == 1)
					{
						coreect_pass_key = 1 ;
						}else{
						LCD_Clear(LCD0);
						counter = 0 ;
						current = 0 ;
						++number_of_triels;
						set_number_of_triles();
						punish = 1 ;
					}
					
					}else{
					enter = 0;
				}		
	}
}

	
}




void passkey_scanning(void){

_delay_ms(10);
	
	if (keypad_flag == 1)
	{
		keypad_flag = 0;
			
			new_pressed = get_pressed_key();
			if (new_pressed != NOT_PRESSED_LETTER)
			{

				switch (new_pressed)
				{
					case '#':
					if (counter == PASSKEY_LENGTH)
					{
						enter = 1;
					}
					break;

					default:
					if (new_pressed != '*')
					{
						payload[current] = new_pressed;
						++current;
					}
					else
					{
							if (current > 0)
							{
								--current;
							}
					}
					lcd_format_display(new_pressed);
					break;
				}
			}

			if ((enter == 1) && (counter == PASSKEY_LENGTH))
			{
				if (pass_comparing(payload) == 1)
				{
					coreect_pass_key = 1 ;
					}else{
					LCD_Clear(LCD0);
					counter = 0 ;
					current = 0 ;
					++number_of_triels;
					set_number_of_triles();
					punish = 1 ;
				}
				
				}else{
				enter = 0;
			}
		
	
	}
	
}

void passkey_loading(void)
{
	uint8_t i;
	for (i = 0; i < PASSKEY_LENGTH; ++i)
	{
		correct_passkey[i] = EEPROM_read(passkey_address_array[i]);
	}
#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "PASSKEY LOADEAD.");
	_delay_ms(1000);
	LCD_Clear(LCD0);

	for (i = 0; i < PASSKEY_LENGTH; ++i)
	{
		LCD_Write_Char(LCD0, correct_passkey[i]);
		_delay_ms(300);
	}
	_delay_ms(3000);
	LCD_Clear(LCD0);
	_delay_ms(1000);
#endif
}



int pass_comparing(char string[])
{
	int i = 0;
	for (i; i < PASSKEY_LENGTH; ++i)
	{
		if (string[i] != correct_passkey[i])
		{
			LCD_Clear(LCD0);
			LCD_Write_String(LCD0, "TRY AGAIN.");
			_delay_ms(2000);
			LCD_Clear(LCD0);
			return 0;
		}
	}
	return 1;
}



#if DEBUGE == 1

void lcd_format_display(char letter)
{
	switch (letter)
	{
	case '*':
	if (counter > 0)
	{
		DeleteChar(LCD0);
		--counter;
	}

		break;

	case '1':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '2':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '3':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}

		break;

	case 'A':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '4':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '5':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '6':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case 'B':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '7':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '8':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '9':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case 'C':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case '0':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;

	case 'D':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, letter);
			++counter;
		}
		break;
	}
}

#endif


#if DEBUGE == 0

void lcd_format_display(char letter)
{
	switch (letter)
	{
		case '*':
	if (counter > 1)
	{
		DeleteChar(LCD0);
		--counter;
	}
		break;

		case '1':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '2':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '3':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}

		break;

		case 'A':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '4':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '5':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '6':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case 'B':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '7':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '8':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '9':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case 'C':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case '0':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;

		case 'D':
		if (counter < PASSKEY_LENGTH)
		{
			LCD_Write_Char(LCD0, '*');
			++counter;
		}
		break;
	}
}

#endif


void MainMassage(void)
{
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "Welcome");
	
	uint8_t i;
	for (i = 0; i < 16; i++)
	{
		Shift_Right(LCD0);
		_delay_ms(500);
	}
	for (i = 0; i < 23; i++)
	{
		Shift_Left(LCD0);
		_delay_ms(500);
	}
	LCD_Clear(LCD0);

	LCD_Write_String(LCD0, "Enter PassKey.");
	_delay_ms(1000);
	LCD_Clear(LCD0);
	
}

void load_number_of_triles(void)
{
	number_of_triels = EEPROM_read(NUMBEROFTRILESADDRESS);
#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "NUM TRILES LOADEAD");
	_delay_ms(1000);
	LCD_Clear(LCD0);
#endif
}

void set_number_of_triles(void)
{

	EEPROM_write(NUMBEROFTRILESADDRESS, number_of_triels);

#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "NUM OF TRILES SETED.");
	_delay_ms(1000);
	LCD_Clear(LCD0);
	LCD_Write_Char(LCD0,EEPROM_read(NUMBEROFTRILESADDRESS));
	_delay_ms(2000);
	LCD_Clear(LCD0);
	#endif
}
void reset_number_of_triles(void)
{
	number_of_triels = '0' ;
	EEPROM_write(NUMBEROFTRILESADDRESS, number_of_triels);

	#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "RESET TRILES NUM.");
	_delay_ms(1000);
	LCD_Clear(LCD0);
	LCD_Write_Char(LCD0,EEPROM_read(NUMBEROFTRILESADDRESS));
	_delay_ms(2000);
	LCD_Clear(LCD0);
	#endif
}
void first_entry_validation(void)
{
	if (EEPROM_read(FIRST_ENTERY_VALIDATION_ADDRESS) != FIRST_ENTERY_VALIDATION_LETTER)
	{


		char message[20] = "FIRST CODE USAGE.";
		LCD_Clear(LCD0);
		LCD_Write_String(LCD0, message);
		_delay_ms(3000);
		LCD_Clear(LCD0);

		reset_number_of_triles();
		
		new_passkey_scanning();

		LCD_Clear(LCD0);
		update_passkey(payload);
		
#if DEBUGE == 1
		uint8_t i;
		for (i = 0; i < PASSKEY_LENGTH; ++i)
		{
			LCD_Write_Char(LCD0, payload[i]);
		}
		_delay_ms(2000);
		LCD_Clear(LCD0);
#endif

		EEPROM_write(FIRST_ENTERY_VALIDATION_ADDRESS, FIRST_ENTERY_VALIDATION_LETTER);

#if DEBUGE == 1
		LCD_Clear(LCD0);
		LCD_Write_String(LCD0, "ADRESSE CONFIRM LETTER.");
		_delay_ms(1000);
		LCD_Clear(LCD0);
		LCD_Write_Char(LCD0, EEPROM_read(FIRST_ENTERY_VALIDATION_ADDRESS));
		_delay_ms(2000);
		LCD_Clear(LCD0);
		_delay_ms(1000);		
#endif
	}
}





void update_passkey(char string[PASSKEY_LENGTH])
{
	uint8_t i;
	for (i = 0; i < PASSKEY_LENGTH; ++i)
	{
		EEPROM_write(passkey_address_array[i], string[i]);
		correct_passkey[i] = string[i];
	}

#if DEBUGE == 1

	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "NEW PASSKEY SETED");
	_delay_ms(2000);
	LCD_Clear(LCD0);

#endif
}



void do_punish(void){
	
subtract = number_of_triels - '0' ;

if (subtract > 1)
{

if (subtract % MAXNUMBEROFTRIELS == 0)
{
	divided = subtract / MAXNUMBEROFTRIELS ;
	int num_of_loops = power(divided); ;
	int i ;
	int number_on_second = num_of_loops * MIN_WAIT ;

	#if DEBUGE == 1
	LCD_Write_String(LCD0,"NUM OF LOOPS");
	itoa(num_of_loops,buffer,10);
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0,buffer);
	_delay_ms(1000);	
	#endif

	for (i=0;i<num_of_loops;++i)
	{
		LCD_Clear(LCD0);
		LCD_Write_String(LCD0,"WAIT ");	
		itoa(number_on_second,buffer,10);
		LCD_Write_String(LCD0,buffer);	
		_delay_ms(5000) ;
		number_on_second = number_on_second - MIN_WAIT ;
	}
LCD_Clear(LCD0);
punish = 0;
}

}

}


void reset_payload(void){
	
int i ;
for (i=0;i<PASSKEY_LENGTH;++i)
{
	payload[i] = '*' ;
}

counter = 0 ;
current = 0 ;
#if DEBUGE == 1
	LCD_Clear(LCD0);
	LCD_Write_String(LCD0, "PAYLOAD RESETED");
	_delay_ms(2000);
	LCD_Clear(LCD0);
#endif
}



int power(int num){

return	(1<<(num - 1));

}
