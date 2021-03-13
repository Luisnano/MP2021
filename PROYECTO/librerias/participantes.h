#ifndef PROYECTO_PARTICIPANTES_H
#define PROYECTO_PARTICIPANTES_H

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

//DEFINICIÓN DE FUNCIONES

void menu_participantes(int *id, jugadores_plantillas *estructura_jugadores_plantillas, futbolistas *estructura_futbolistas, plantillas *estructura_plantillas);
void crear_plantillas(plantillas *estructura_plantillas);
void configurar_plantillas(jugadores_plantillas *estructura_jugadores_plantillas, futbolistas *estructura_futbolistas, plantillas *estructura_plantillas);
void eliminar_plantillas(plantillas *estructura_plantillas, jugadores_plantillas *estructura_jugadores_plantillas);
void ranking(plantillas *estructura_plantillas);

//FUNCIONES

void menu_participantes(jugadores_plantillas *estructura_jugadores_plantillas, futbolistas *estructura_futbolistas, plantillas *estructura_plantillas){

    int opcion;

    printf("MENU PARTICIPANTE\n\n");

    printf("1.- Crear Plantilla\n");
    printf("2.- Configurar Plantilla\n");
    printf("3.- Listar Plantillas\n");
    printf("4.- Eliminar Plantilla\n");
    printf("5.- Ranking\n");
    printf("6.- Salir del programa\n\n");

    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);

    do {
        switch(opcion){

            case 1: crear_plantillas(estructura_plantillas); break;
            case 2: configurar_plantillas(estructura_jugadores_plantillas,estructura_futbolistas,estructura_plantillas); break;
            case 3: mostrar_plantillas(estructura_plantillas); break;
            case 4: eliminar_plantillas(estructura_plantillas,estructura_jugadores_plantillas); break;
            case 5: ranking(estructura_plantillas); break;
            case 6: salir_programa(estructura_config,estructura_futbolistas,estructura_equipos,estructura_usuarios,estructura_plantillas,estructura_jugadores_plantillas); break;

            }
        }while(opcion > 0 || opcion < 7);

    }

}

void crear_plantillas(plantillas *estructura_plantillas){

    int i, num_plantillas = 0;

    for(i = 0; i <= sizeof(estructura_plantillas); i++){
        if(estructura_plantillas[i].usuario_id == )
    }

}






#endif //PROYECTO_PARTICIPANTES_H
