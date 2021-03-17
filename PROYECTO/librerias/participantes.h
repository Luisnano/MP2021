#ifndef PROYECTO_PARTICIPANTES_H
#define PROYECTO_PARTICIPANTES_H

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

//DEFINICIÓN DE FUNCIONES

void menu_participantes(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                        equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                        plantillas *estructura_plantillas);
void crear_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                      equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                      plantillas *estructura_plantillas);
void listar_jugadores_disponibles(futbolistas *estructura_futbolistas,jugadores_plantillas *estructura_jugadores_plantillas);
void configurar_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                           equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                           plantillas *estructura_plantillas);
void eliminar_plantillas(plantillas *estructura_plantillas, jugadores_plantillas *estructura_jugadores_plantillas);
void ranking(plantillas *estructura_plantillas);


//FUNCIONES

void menu_participantes(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                        equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                        plantillas *estructura_plantillas){

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

            case 1: crear_plantillas(id, estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                     estructura_usuarios,estructura_futbolistas,estructura_plantillas);
            break;

            case 2: configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                                          estructura_usuarios, estructura_futbolistas,estructura_plantillas);
            break;

            case 3: mostrar_plantillas(estructura_plantillas);
            break;

            case 4: eliminar_plantillas(estructura_plantillas,estructura_jugadores_plantillas);
            break;

            case 5: ranking(estructura_plantillas);
            break;

            case 6: salir_programa(estructura_config,estructura_futbolistas,estructura_equipos,estructura_usuarios,
                                   estructura_plantillas,
                                   estructura_jugadores_plantillas);
            break;

            }
        }while(opcion > 0 && opcion < 7);

    }

void crear_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                      equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                      plantillas *estructura_plantillas){

    int i, num_plantillas = 0;

    for(i = 0; i <= sizeof(estructura_plantillas); i++){
        if(estructura_plantillas[i].usuario_id == *id){
            num_plantillas++;
        }
    }
    if(num_plantillas == 3){
        printf("Numero maximo de plantillas alcanzado.\n");
        menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,estructura_usuarios,
                           estructura_futbolistas,estructura_plantillas);
    }
    else{
        printf("Se procede a crear una plantilla: \n");

            estructura_plantillas = (plantillas *)realloc(estructura_plantillas, (sizeof(estructura_plantillas)+1)*sizeof(int));
            if(estructura_plantillas==NULL){
                printf("Fallo de reserva de memoria\n");
            }

            estructura_plantillas[sizeof(estructura_plantillas)].usuario_id = id;

            estructura_plantillas[sizeof(estructura_plantillas)].plantilla_id = sizeof(estructura_plantillas);

            printf("\nIntroduce el nombre de la plantilla: ");
            fgets(estructura_plantillas[sizeof(estructura_plantillas)].nombre_plantilla,31,stdin);
            fflush(stdin);

            estructura_plantillas[sizeof(estructura_plantillas)].presupuesto_disp = estructura_config->presupuesto_defecto;

            estructura_plantillas[sizeof(estructura_plantillas)].puntuacion_acum = 0;

        printf("\nLa plantilla se ha creado con exito.\n");
        menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,estructura_usuarios,
                           estructura_futbolistas,estructura_plantillas);
    }

}

void configurar_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                           equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                           plantillas *estructura_plantillas){

    int opcion, i;

    printf("A continuacion, mostraremos tus plantillas actuales. Selecciona una de ellas para configurarla.");

    for(i = 0; i <= sizeof(estructura_plantillas); i++){
        printf("%i, %s, presupuesto: %i, puntuacion: %i", estructura_plantillas[i].plantilla_id, estructura_plantillas[i].nombre_plantilla,
               estructura_plantillas[i].presupuesto_disp, estructura_plantillas[i].puntuacion_acum);
    }

    printf("MENU CONFIGURAR-PLANTILLA\n\n");

    printf("1.- Lista de jugadores en plantilla\n");
    printf("2.- Lista de jugadores disponibles\n");
    printf("3.- Añadir jugador a plantilla\n");
    printf("4.- Eliminar jugador de plantilla\n");
    printf("5.- Volver\n");

    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);

    do {
        switch(opcion){

            case 1:
                break;

            case 2:     listar_jugadores_disponibles(estructura_futbolistas,estructura_jugadores_plantillas);
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:     menu_participantes(&id,&estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                           estructura_usuarios,estructura_futbolistas,estructura_plantillas);
                break;

        }
    }while(opcion > 0 && opcion < 6);

}

void listar_jugadores_disponibles(futbolistas *estructura_futbolistas,jugadores_plantillas *estructura_jugadores_plantillas){

    int i,j,aux;

    for(i=0 ; i<=sizeof(estructura_futbolistas) ; i++){

        if(aux==1){

            printf("%i , %i , %s , %i , %i\n",estructura_futbolistas[i-1].futbolista_id,estructura_futbolistas[i-1].equipo_id,
                   estructura_futbolistas[i-1].nombre_futbolista,estructura_futbolistas[i-1].futbolista_precio,
                   estructura_futbolistas[i-1].valoracion);
        }

        aux = 1;

        for(j=0 ; j<=sizeof(estructura_jugadores_plantillas) && aux == 1 ; j++){

            if(estructura_futbolistas[i].futbolista_id == estructura_jugadores_plantillas[j].jugador_platilla_id){

                aux = 0;

            }
        }
    }

}



#endif //PROYECTO_PARTICIPANTES_H
