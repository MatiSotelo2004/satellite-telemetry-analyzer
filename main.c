#include <stdio.h>
#include "funciones.h"

int main() {
    FILE* in_telemetry, *out_telemetry; //Punteros a los archivos
    unsigned size_file/*Tam. del archivo*/,line_size=4000;//Offset
    unsigned PCS=2354, CDH=100/*Offset de los subsistemas*/, raw_CDH/*Valor crudo de CDH*/;
    unsigned short raw_PCS;
    float PCS_value;
    time_t CDH_value;

    //Abre los archivos
    in_telemetry = fopen("HKTMST.bin", "rb"); 
    out_telemetry = fopen("output.txt", "w");
    if (!in_telemetry || !out_telemetry) { //Si no se pudo abrir alguno de los archivos
        printf("ERROR - No se pudo abrir los archivos");
        fclose(in_telemetry);
        fclose(out_telemetry);
        return 1;
    }
    //Obtiene el tam. del archivo
    fseek(in_telemetry,0, SEEK_END); //Posiciona el cursor al final
    size_file = ftell(in_telemetry);
    if(size_file%4000 != 0){ //Si no es divisible por 4000, arroja un error
        printf("ERROR - Tam. Invalido");
        fclose(in_telemetry);
        fclose(out_telemetry);
        return 1;
    }
    fseek(in_telemetry, 0, SEEK_SET); //Vuelve a posicionar el cursor al inicio

    //Lee el archivo en bloques de 4000 bytes
    for (unsigned i=0; i < size_file; i += line_size){ //El bucle acaba cuando 'i' supera el tamaño del archivo
        
        fseek(in_telemetry, i + PCS, SEEK_SET); // Se suma la posicion del siguiente bloque mas el offset del subsistema
        fread(&raw_PCS,sizeof(short), 1, in_telemetry);
        PCS_value = obtener_PCS(raw_PCS); //Llama a la funcion para obtener el valor de PCS

        fseek(in_telemetry, i + CDH, SEEK_SET); // Se suma la posicion del siguiente bloque mas el offset del subsistema
        fread(&raw_CDH, sizeof(int), 1, in_telemetry);
        CDH_value = obtener_CDH(raw_CDH); //Llama a la funcion para obtener el valor de CDH
        
        fprintf(out_telemetry, "PCS: %f\t CDH: %s\n", PCS_value, ctime(&CDH_value)); //Escribe el valor de PCS y el de CDH en el archivo de salida
        
    }

    //Cierra los archivos
    fclose(in_telemetry);
    fclose(out_telemetry);


    return 0;
}