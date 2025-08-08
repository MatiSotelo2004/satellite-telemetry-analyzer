#include <stdio.h>
#include "funciones.h"

int es_little_endian() {
    unsigned int x = 1;
    // Si el primer byte es 1, es little-endian
    return *((unsigned char*)&x) == 1;
}

// Convierte un valor de 2 bytes de big-endian a little-endian
unsigned short invertir_2bytes(unsigned short val) {
    return (val >> 8) | (val << 8);
}

// Convierte un valor de 4 bytes de big-endian a little-endian
unsigned int invertir_4bytes(unsigned int val) {
    return ((val >> 24) & 0x000000FF) |
           ((val >> 8)  & 0x0000FF00) |
           ((val << 8)  & 0x00FF0000) |
           ((val << 24) & 0xFF000000);
}

float obtener_PCS(unsigned short raw){
    if (es_little_endian()) {
            raw = invertir_2bytes(raw);
        }
    return (float)(raw*0.01873128+(-38.682956)); // Formula para obtener PCS
}

time_t obtener_CDH(unsigned int raw) {
    unsigned int time_offset = 315975600; // Segundos desde epoch hasta el 6 de enero de 1980
    if (es_little_endian()) {
        raw = invertir_4bytes(raw);
    }
    // Asumiendo que el valor de raw es un timestamp en segundos desde epoch
    return (time_t)(raw+time_offset); // Convierte a time_t sumando el offset
}