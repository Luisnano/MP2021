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
    printf("---------MENU CRONISTA----------\n");
    printf("                          \n");
    printf("      1.-Listar equipos    \n");
    printf("      2.-Valorar equipos   \n");
    printf("      3.-Salir del programa\n");
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

void valorar_equipos(futbolistas *estructura_futbolistas){
    int valoracion;
    int id_equipo;
    int id_futbolista;
    int i;
    int selec;
    etiqueta_seleccion_equipos:
    printf(".....INTRODUZCA UN ID DE EQUIPO.....\n");
    scanf("%d", &id_equipo);

    etiqueta_vuelta_valoracion:

    for (i=0; i<sizeof (estructura_futbolistas); i++) {
        if (id_equipo == estructura_futbolistas[i].equipo_id) {
            printf("-------------------------------\n");
            printf("      ID: %d\n", estructura_futbolistas[i].futbolista_id);
            printf("      NOMBRE: %s\n", estructura_futbolistas[i].nombre_futbolista);
            printf("      PRECIO: %d MILLONES\n", estructura_futbolistas[i].futbolista_precio);
            printf("      VALORACION: %d\n", estructura_futbolistas[i].valoracion);
            printf("-------------------------------\n");
        }
    }
    printf(".....INTRODUZCA EL ID DEL FUTBOLISTA A VALORAR.....\n");
    scanf("%d", &id_futbolista);
    for (i=0; i<sizeof (estructura_futbolistas); i++){
        if(id_futbolista == estructura_futbolistas[i].futbolista_id){
            printf(".....INTRODUZCA LA NUEVA VALORACION DEL FUTBOLISTA.....\n");
            scanf("%d", &estructura_futbolistas[i].valoracion);
        }
    }
    etiqueta_seleccion_final:
    printf(".....ELIJA UNA OPCION......\n");
    printf("                           \n");
    printf("       1.- SEGUIR VALORANDO\n");
    printf("       2.- CAMBIAR DE EQUIPO\n");
    printf("       3.- SALIR DE VALORAR EQUIPOS\n");
    printf("                           \n");
    scanf("%d", &selec);
    switch (selec) {
        case 1: goto etiqueta_vuelta_valoracion; break;
        case 2: goto etiqueta_seleccion_equipos; break;
        case 3: goto etiqueta_final; break;
        default: goto etiqueta_seleccion_final; break;
    }
    etiqueta_final:
}

#endif //PROYECTO_CRONISTA_H
