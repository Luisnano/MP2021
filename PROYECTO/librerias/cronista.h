#ifndef PROYECTO_CRONISTA_H
#define PROYECTO_CRONISTA_H


#include <string.h>
#include <stdlib.h>
#include "core.h"

//DECLARACION DE FUNCIONES


void menu_cronista(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                   usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                   jugadores_plantillas **estructura_jugadores_plantillas);
void valorar_futbolistas(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                     usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                     jugadores_plantillas **estructura_jugadores_plantillas);

//FUNCIONES


//Cabecera: void menu_cronista(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
//                   usuarios **estructura_usuarios, plantillas **estructura_plantillas,
//                   jugadores_plantillas *estructura_jugadores_plantillas);
//Precondicion: Entran todas las estructuras existentes que hemos volcado con anterioridad de los ficheros.
//Postcondicion: Es una funcion MENU, es decir detalla todas las opciones que tiene el cronista, y dependiendo de la
//                  eleccion del usuario, llamara a una funcion diferente o se saldra del programa.

void menu_cronista(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                   usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                   jugadores_plantillas **estructura_jugadores_plantillas){

    int selec;

    printf("\n\n---------MENU CRONISTA----------\n");
    printf("                          \n");
    printf("      1.-Listar equipos    \n");
    printf("      2.-Valorar equipos   \n");
    printf("      3.-Salir del programa\n");
    printf("                          \n");
    printf(".....SELECCIONE UNA OPCION.....\n");
    printf("                           \n");
    printf(">");
    scanf("%i", &selec);

    do {
        switch (selec) {
            // 1.-Listar equipos
            case 1:
                //LLAMAMOS A LA FUNCION QUE ESCRIBE TODOS LOS EQUIPOS POR PANTALLA (DECLARADA EN CORE.H)
                mostrar_equipos(estructura_equipos, estructura_config);
                menu_cronista(estructura_config, estructura_futbolistas, estructura_equipos,
                              estructura_usuarios, estructura_plantillas,
                              estructura_jugadores_plantillas);
                break;

            //2.-Valorar futbolistas
            case 2:
                valorar_futbolistas(estructura_config, estructura_futbolistas, estructura_equipos,
                                estructura_usuarios, estructura_plantillas,
                                estructura_jugadores_plantillas);
                menu_cronista(estructura_config, estructura_futbolistas, estructura_equipos,
                              estructura_usuarios, estructura_plantillas,
                              estructura_jugadores_plantillas);
                break;

            //3.-Salir del programa
            case 3:
                //FUNCION SALIR DEL PROGRAMA (DECLARADA EN CORE.H)
                salir_programa(estructura_config, estructura_futbolistas, estructura_equipos, estructura_usuarios,
                               estructura_plantillas, estructura_jugadores_plantillas);
                break;

            //En caso de que el usuario no elija ninguna de las opciones.
            default:    printf("\n\nPor favor seleccione una opcion correcta\n\n");

                break;
        }

    } while (selec > 0 && selec < 4);
}

//Cabecera: void valorar_futbolistas(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
//                   usuarios **estructura_usuarios, plantillas **estructura_plantillas,
//                   jugadores_plantillas **estructura_jugadores_plantillas);
//Precondicion: Entran la estructura FUTBOLISTAS y la estructura CONFIGURACION
//Postcondicion: Permitirá al cronista actualizar las valoraciones de los futbolistas. Para ello,
//      el cronista seleccionará un identificador de un equipo y posteriormente le aparecerá la lista
//      de futbolistas de dicho equipo junto con su valoración actual. A continuación, el cronista irá
//      seleccionando futbolistas e introduciendo sus nuevas valoraciones (0-10).

void valorar_futbolistas(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                     usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                     jugadores_plantillas **estructura_jugadores_plantillas){

    int id_equipo;
    int id_futbolista;
    int i;
    int selec;
    int aux = 0;    //Aux ayuda a saber si no hay futbolistas de la ID de equipo que ha introducido el cronista

    //Dos bucles dowhile anidados, para el caso de que el usuario quiera volver atras, seguir valorando
    //  jugadores del equipo introducido o cambiar de equipo.
    do {

        printf(".....INTRODUZCA UN ID DE EQUIPO.....\n");
        printf("                           \n");
        printf(">");
        scanf("%i", &id_equipo);

        do {

            //VAMOS A ENSEñAR TODOS LOS FUTBOLISTAS QUE FORMAN PARTE DE ESE EQUIPO EN UN PEQUEñO MENU,
            // ENSEñANDO TODOS LOS CAMPOS DEL FUTBOLISTA

            for (i = 0 ; i < (*estructura_config).tam_futbolistas ; i++) {

                if (id_equipo == (*estructura_futbolistas)[i].equipo_id) {

                    aux = 1;

                    printf("-------------------------------\n");
                    printf("      ID: %d\n", (*estructura_futbolistas)[i].futbolista_id);
                    printf("      NOMBRE: %s\n", (*estructura_futbolistas)[i].nombre_futbolista);
                    printf("      PRECIO: %d MILLONES\n", (*estructura_futbolistas)[i].futbolista_precio);
                    printf("      VALORACION: %d\n", (*estructura_futbolistas)[i].valoracion);
                    printf("-------------------------------\n");
                }
            }

            //Si no hay ningun futbolista de ese equipo vuelta al menu

            if (aux == 0){

                printf("\nNo hay ningun futbolista de la ID que has introducido\n");
                menu_cronista(estructura_config, estructura_futbolistas, estructura_equipos,
                              estructura_usuarios, estructura_plantillas,
                              estructura_jugadores_plantillas);

            }

            printf(".....INTRODUZCA EL ID DEL FUTBOLISTA A VALORAR.....\n");
            scanf("%d", &id_futbolista);

            //LO PRINCIPAL: EL USUARIO INTRODUCIRA EL ID DEL JUGADOR DEL CUAL DESEA CAMBIAR LA VALORACION

            for (i = 0 ; i < (*estructura_config).tam_futbolistas ; i++) {

                if (id_futbolista == (*estructura_futbolistas)[i].futbolista_id) {

                    printf(".....INTRODUZCA LA NUEVA VALORACION DEL FUTBOLISTA.....\n");
                    printf("                           \n");
                    printf(">");
                    scanf("%d", &(*estructura_futbolistas)[i].valoracion); //SUSCEPTIBLE A CAMBIO

                }
            }

            printf(".....ELIJA UNA OPCION......\n");
            printf("                           \n");
            printf("       1.- SEGUIR VALORANDO\n");
            printf("       2.- CAMBIAR DE EQUIPO\n");
            printf("                           \n");
            printf(">");
            scanf("%d", &selec);

        }while(selec == 1); //Si elige 1, volvera a la linea 97, en la cual podra seguir valorando a mas jugadores del mismo equipo.

    }while (selec == 2); //Si elige 2, volvera a la linea 89, para asi introducir un nuevo id de equipo para poder valorarlo.
}

#endif //PROYECTO_CRONISTA_H
