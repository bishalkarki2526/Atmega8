//#define F_CPU 1000000UL

#include <avr/io.h>
#include<util/delay.h>

void Motors (void);
void Ir_Sensor1(void);
void Led (void);
void Buzzer(void);

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0b0000000;
	DDRD = 0xFF;
	

	while (1)
	{
		
		//Led();
		//Ir_Sensor1();
		//Buzzer();
		Motors();
		
	}
}

void Led (void)
{
	PORTB = 0b00111100;
	_delay_ms(2000);
	PORTB = 0b00011100;
	_delay_ms(2000);
	PORTB = 0b00001100;
	_delay_ms(2000);
	PORTB = 0b00000100;
	_delay_ms(2000);
	PORTB = 0b00000000;
	_delay_ms(2000);
}


void Ir_Sensor1 (void)
{
	int Ir_Sensor11;
	int Ir_Sensor22;

	Ir_Sensor22 = PINC&0000001;
	Ir_Sensor11 = PINC&0000010;

	if (Ir_Sensor11 == 0000010  && Ir_Sensor22 == 0000001)
	{
		Led();
	}
	if (Ir_Sensor11 == 0000000 && Ir_Sensor22 == 0000001)
	{
		Led();
	}
	if (Ir_Sensor11 == 0000001  && Ir_Sensor22 == 0000000)
	{
		Led();
	}
	if (Ir_Sensor22 == 0000000 && Ir_Sensor22 == 0000000)
	{
		PORTB = 0b00000000;
	}
	
	
}


void Buzzer(void)
{
	DDRB=0XFF;
	DDRD=0xFF;
	PORTB = 0b00000011;
	//PORTD=0b00000011;
	_delay_ms(5000);
	PORTB = 0b00111100;
	_delay_ms(5000);
}



void Motors(void)
{
	int Left_Motor = 0;
	int Right_Motor = 0;
	
	Left_Motor = PINC&0b0000001;
	Right_Motor = PINC&0b0000010;
	if (Left_Motor == 0b0000001 && Right_Motor == 0b0000010)
	{
		
		PORTB = 0b00000000;
		_delay_ms(5000);
		Buzzer();
		
	}
	if(Left_Motor == 0b0000001 && Right_Motor == 0b0000000)
	{
		PORTB = 0b00001000;
	}
	if (Left_Motor == 0b0000000 && Right_Motor == 0b0000010)
	{
		PORTB=0b00100000;
	}
	if(Left_Motor == 0b00000000 && Right_Motor == 0b00000000)
	{
		PORTB=0b00101000;
	}
	
}
