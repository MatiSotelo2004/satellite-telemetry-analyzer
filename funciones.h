#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<time.h>

typedef struct{
    float PCS_value;
    time_t CDH_value;
}satelite_struct;

int es_little_endian();
unsigned short invertir_2bytes(unsigned short raw);
unsigned int invertir_4bytes(unsigned int raw);
float obtener_PCS(unsigned short raw);
time_t obtener_CDH(unsigned int raw);
int comparar_registros(const void *a, const void*b);

#endif