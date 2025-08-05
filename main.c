#include <stdio.h>
#include "funciones.h"

int main() {
    FILE* in_telemetry; //Punteros a los archivos
    unsigned size_file/*Tam. del archivo*/,line_size=4000;//Offset
    unsigned PCS=2354, CDH=100;//Offset de los subsistemas
    unsigned short raw;

    in_telemetry = fopen("HKTMST.bin", "rb"); //Abre el archivo
    if (!in_telemetry){
        printf("ERROR - No se pudo abrir el archivo");
        return 1;
    }
    fseek(in_telemetry,0, SEEK_END); //Posiciona el cursor al final
    size_file = ftell(in_telemetry);
    if(size_file%4000 != 0){ //Si no es divisible por 4000, arroja un error
        printf("ERROR - Tam. Invalido");
        return 1;
    }
    fseek(in_telemetry, 0, SEEK_SET); //Vuelve a posicionar el cursor al inicio

    for (unsigned i=0; i < size_file; i += line_size){ //El bucle acaba cuando 'i' supera el tamaño del archivo
        fseek(in_telemetry, i + PCS, SEEK_SET); // Se suma la posicion del siguiente bloque mas el offset del subsistema
        fread(&raw,sizeof(short), 1, in_telemetry);
        printf("%d", raw);
    }






    return 0;
}