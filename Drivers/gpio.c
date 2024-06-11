#include <stdint.h>
#include "../Drivers/gpio_config.h"
#include "../Drivers/gpio_adresses.h"


/**************************************************************************
* Function: ENABLE_PIN_AS_INPUT
* Preconditions: NONE
* Overview: WRITES 1 AT THE 9TH BIT OF THE SPECIFIED REGISTER TO ENABLE IT AS INPUT.
* Input: PIN NUMBER.
* Output: NONE.
*
*****************************************************************************/

;static void ENABLE_PIN_AS_INPUT(uint8_t pin_num){
	(*(volatile uint32_t*)(IO_MUX_REGISTERS[pin_num])) |= INPUT_ENABLE;
}

/**************************************************************************
* Function: DISABLE_PIN_AS_INPUT
* Preconditions: NONE
* Overview: WRITES 0 AT THE 9TH BIT OF THE SPECIFIED REGISTER TO DISABLE IT AS INPUT.
* Input: PIN NUMBER.
* Output: NONE.
*
*****************************************************************************/
static void DISABLE_PIN_AS_INPUT(uint8_t pin_num){
	(*(volatile uint32_t*)(IO_MUX_REGISTERS[pin_num])) &= INPUT_DISABLE;
}

/**************************************************************************
* Function: ENABLE_PIN_AS_OUTPUT
* Preconditions: NONE
* Overview: WRITES 1 AT THE SPECIFIED BIT OF THE OUTPUT ENABLE REGISTER TO TURN THAT PIN INTO AN OUTPUT PIN
* Input: PIN NUMBER.
* Output: NONE.
*
*****************************************************************************/
static void ENABLE_PIN_AS_OUTPUT(uint8_t pin_num){
	if(pin_num < 32)
		OUTPUT_ENABLE_REG_0_31 |= (1 << pin_num);
	if(pin_num > 31)
		OUTPUT_ENABLE_REG_32_33 |= (1 << (pin_num - 32));
}

/**************************************************************************
* Function: DISABLE_PIN_AS_OUTPUT
* Preconditions: NONE
* Overview: WRITES 0 AT THE SPECIFIED BIT OF THE OUTPUT ENABLE REGISTER TO DISABLE THAT PIN AS AN OUTPUT PIN
* Input: PIN NUMBER.
* Output: NONE.
*
*****************************************************************************/
static void DISABLE_PIN_AS_OUTPUT(uint8_t pin_num){
	if(pin_num < 32)
		OUTPUT_ENABLE_REG_0_31 &= (~(1 << pin_num));
	if(pin_num > 31)
		OUTPUT_ENABLE_REG_32_33 &= (~(1 << (pin_num - 32)));
}

/**************************************************************************
* Function: MODO
*****************************************************************************/
void MODO(uint8_t pin_num, MODO_GPIO MODO){

	//DISPONIBLE PARA REGISTROS GPIO Y GPI
	if (MODO == ENTRADA){
		DISABLE_PIN_AS_OUTPUT(pin_num);
		ENABLE_PIN_AS_INPUT(pin_num);
	}
	//DISPONIBLE PARA REGISTROS GPIO
	if (MODO == SALIDA){
		DISABLE_PIN_AS_INPUT(pin_num);
		ENABLE_PIN_AS_OUTPUT(pin_num);
	}
}

/**************************************************************************
* Function: RESISTENCIAS
*****************************************************************************/
void RESISTENCIAS(uint8_t pin_num, MODO_RESISTENCIAS MODO){
	if (MODO == RES_PULLUP){
		(*(volatile uint32_t*)(IO_MUX_REGISTERS[pin_num])) &= PULLDOWN_DISABLE;
		(*(volatile uint32_t*)(IO_MUX_REGISTERS[pin_num])) |= PULLUP_ENABLE;
	}

	if (MODO == RES_PULLDOWN){
		(*(volatile uint32_t*)(IO_MUX_REGISTERS[pin_num])) &= PULLUP_DISABLE;
		(*(volatile uint32_t*)(IO_MUX_REGISTERS[pin_num])) |= PULLDOWN_ENABLE;
	}

}

/**************************************************************************
* Function: LEER
*****************************************************************************/
int LEER(uint8_t pin_num){
	int LECTURA;
	if(pin_num < 32){
		if(((INPUT_STATUS_REG_0_31 >> pin_num) & 0x1) == 1)
			LECTURA = 1;
		else
			LECTURA = 0;
	}
	if(pin_num > 31){
		if(((INPUT_STATUS_REG_32_39 >> (pin_num - 32)) & 0x1) == 1)
			LECTURA = 1;
		else
			LECTURA = 0;
	}
	return LECTURA;
}

/**************************************************************************
* Function: ESCRIBIR
*****************************************************************************/
void ESCRIBIR(uint8_t pin_num, ESTADO EDO){
	if(pin_num < 32){
		if(EDO == ALTO)
			SET_OUTPUT_PIN_REG_0_31 |= (1 << pin_num);
		if(EDO == BAJO)
			CLEAR_OUTPUT_PIN_REG_0_31 |= (1 << pin_num);
	}
	if(pin_num > 31){
		if(EDO == ALTO)
			SET_OUTPUT_PIN_REG_32_33 |= (1 << (pin_num - 32));
		if(EDO == BAJO)
			CLEAR_OUTPUT_PIN_REG_32_33 |= (1 << (pin_num - 32));
	}
}


