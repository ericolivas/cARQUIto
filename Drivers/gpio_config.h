#include <stdint.h>


#ifndef DRIVERS_GPIO_CONFIG_H_
#define DRIVERS_GPIO_CONFIG_H_

#define PULLDOWN_ENABLE   (1UL<<7)
#define PULLDOWN_DISABLE  (~(1UL<<7))
#define PULLUP_ENABLE     (1UL<<8)
#define PULLUP_DISABLE    (~(1UL<<8))
#define INPUT_ENABLE      (1UL<<9)
#define INPUT_DISABLE     (~(1UL<<9))

typedef enum{
	BAJO = 1,
	ALTO = 2,
}ESTADO;

typedef enum {
	ENTRADA	= 1,
	SALIDA = 2,
}MODO_GPIO;

typedef enum {
	RES_PULLUP = 1,
	RES_PULLDOWN = 2,
}MODO_RESISTENCIAS;

#endif /* DRIVERS_GPIO_CONFIG_H_ */
