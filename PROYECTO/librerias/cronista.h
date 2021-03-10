#ifndef PROYECTO_CRONISTA_H
#define PROYECTO_CRONISTA_H

#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "core.h"

//DECLARACION DE FUNCIONES


void menu_cronista(equipos *estructura_equipos);
void valorar_equipos(equipos *estructura_equipos);

//FUNCIONES

void menu_cronista(equipos *estructura_equipos){
    int selec;
    etiqueta_vuelta:
    printf("           MENU CRONISTA  \n");
    printf("                          \n");
    printf("     1.-Listar equipos    \n");
    printf("     2.-Valorar equipos   \n");
    printf("     3.-Salir del programa\n");
    printf("                          \n");
    printf(".....SELECCIONE UNA OPCION.....\n");
    scanf("%d", &selec);
    switch (selec) {
        case 1: escribir_equipos(estructura_equipos); break;
        case 2: valorar_equipos(estructura_equipos); break;
        case 3: ; break; //SALIR DEL PROGRAMA
        default:
            goto etiqueta_vuelta;break ;//FINAL DE PROGRAMA

    }
}

void valorar_equipos(equipos *estructura_equipos){

}

#endif //PROYECTO_CRONISTA_H
