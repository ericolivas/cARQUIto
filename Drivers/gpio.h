#include <stdint.h>
#include "../Drivers/gpio.c"
#include "../Drivers/gpio_config.h"
#include "../Drivers/gpio_adresses.h"


#ifndef DRIVERS_GPIO_H_
#define DRIVERS_GPIO_H_

//FUNCIONES A UTILIZAR
extern int LEER(uint8_t pin_num);	//LEER PIN: SOLO PIDE EL PIN DEL CUAL SE TOMA LA LECTURA
extern void ESCRIBIR(uint8_t pin_num, ESTADO EDO);	//ESCRIBIR A PIN: PIDE EL PIN Y EL ESTADO A ESCRIBIR
extern void MODO (uint8_t pin_num, MODO_GPIO MODO);	//MODO DEL PIN: PIDE EL PIN Y SI VA A SER ENTRADA O SALIDA
extern void RESISTENCIAS(uint8_t pin_num, MODO_RESISTENCIAS MODO);	//HABILITAR RESISTENCIAS: PIDE EL PIN Y SI VA A SER PULLUP O PULLDOWN



#endif /* DRIVERS_GPIO_H_ */
