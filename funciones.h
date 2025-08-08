#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<time.h>

int es_little_endian();
unsigned short invertir_2bytes(unsigned short raw);
unsigned int invertir_4bytes(unsigned int raw);
float obtener_PCS(unsigned short raw);
time_t obtener_CDH(unsigned int raw);

#endif