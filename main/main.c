#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../Drivers/gpio.h"

#define SW1 18
#define SW2 19
const int ENA = 15;
const int IN1 = 2;
const int IN2 = 4;
const int IN3 = 16;
const int IN4 = 17;
const int ENB = 21;
int c=0;

void forward();
void backwards();
void still();
void clockwise();
void anticlockwise();


void app_main(void)
{

	int c=0;
	MODO(SW1, ENTRADA);
	RESISTENCIAS(SW1, RES_PULLUP);
	RESISTENCIAS(SW2, RES_PULLUP);
	MODO(ENA, SALIDA);
	MODO(ENB, SALIDA);
	MODO(IN1, SALIDA);
	MODO(IN2, SALIDA);
	MODO(IN3, SALIDA);
	MODO(IN4, SALIDA);
	still();

    while (true) {

    	if(LEER(SW1) != 1){
    				c=1;
    				while(LEER(SW1) != 1){};
    	}
    	if(LEER(SW2) != 1){
    	    		c=2;
    	    		while(LEER(SW2) != 1){};
    	}
    	switch(c){
    	case 0:
    		still();
      		break;
    	case 1:
    		sleep(1);
    		forward();
    		sleep(2);
    		still();
    		sleep(2);
    		backwards();
    		sleep(2);
    		c=0;
    		break;
    	case 2:
    		sleep(1);
    		clockwise();
    		sleep(4);
    		still();
    		sleep(1);
    		anticlockwise();
    		sleep(4);
    		c=0;
    		break;

    	}
    }
}

void forward(){
	ESCRIBIR(IN1,ALTO);
	ESCRIBIR(IN2,BAJO);
	ESCRIBIR(IN3,ALTO);
	ESCRIBIR(IN4,BAJO);
	ESCRIBIR(ENA,ALTO);
	ESCRIBIR(ENB,ALTO);
}

void backwards(){
	ESCRIBIR(IN1,BAJO);
	ESCRIBIR(IN2,ALTO);
	ESCRIBIR(IN3,BAJO);
	ESCRIBIR(IN4,ALTO);
	ESCRIBIR(ENA,ALTO);
	ESCRIBIR(ENB,ALTO);
}

void still(){
	ESCRIBIR(IN1,BAJO);
	ESCRIBIR(IN2,BAJO);
  	ESCRIBIR(IN3,BAJO);
  	ESCRIBIR(IN4,BAJO);
  	ESCRIBIR(ENA,BAJO);
  	ESCRIBIR(ENB,BAJO);
}

void clockwise(){
	ESCRIBIR(IN1,ALTO);
	ESCRIBIR(IN2,BAJO);
	ESCRIBIR(IN3,BAJO);
	ESCRIBIR(IN4,ALTO);
	ESCRIBIR(ENA,ALTO);
	ESCRIBIR(ENB,ALTO);
}

void anticlockwise(){
	ESCRIBIR(IN1,BAJO);
	ESCRIBIR(IN2,ALTO);
	ESCRIBIR(IN3,ALTO);
	ESCRIBIR(IN4,BAJO);
	ESCRIBIR(ENA,ALTO);
	ESCRIBIR(ENB,ALTO);
}
