#ifndef PROYECTO_CRONISTA_H
#define PROYECTO_CRONISTA_H


#include <string.h>
#include <stdlib.h>
#include "core.h"

//DECLARACION DE FUNCIONES


void menu_cronista(configuracion *estructura_config, futbolistas *estructura_futbolistas, equipos *estructura_equipos,
                   usuarios *estructura_usuarios, plantillas *estructura_plantillas,
                   jugadores_plantillas *estructura_jugadores_plantillas);
void valorar_equipos(futbolistas *estructura_jugadores);

//FUNCIONES


//MENU CRONISTA:
//      En caso de que el usuario sea cronista debe aparecer un menú:
//      MENU CRONISTA
//      1.- Listar Equipos
//      2.- Valorar Equipos
//      3.- Salir del programa

void menu_cronista(configuracion *estructura_config, futbolistas *estructura_futbolistas, equipos *estructura_equipos,
                   usuarios *estructura_usuarios, plantillas *estructura_plantillas,
                   jugadores_plantillas *estructura_jugadores_plantillas){

    int selec;

    printf("---------MENU CRONISTA----------\n");
    printf("                          \n");
    printf("      1.-Listar equipos    \n");
    printf("      2.-Valorar equipos   \n");
    printf("      3.-Salir del programa\n");
    printf("                          \n");
    printf(".....SELECCIONE UNA OPCION.....\n");
    printf("                           \n");
    printf(">");
    scanf("%d", &selec);

    do {
        switch (selec) {
            case 1:
                escribir_equipos(estructura_equipos);
                break;   //LLAMAMOS A LA FUNCION QUE ESCRIBE TODOS LOS EQUIPOS POR PANTALLA (DECLARADA EN CORE.H)
            case 2:
                valorar_equipos(estructura_equipos);
                break;
            case 3:
                salir_programa(estructura_config, estructura_futbolistas, estructura_equipos, estructura_usuarios,
                               estructura_plantillas, estructura_jugadores_plantillas);
                break; //FUNCION SALIR DEL PROGRAMA (DECLARADA EN CORE.H)
        }
    } while (selec > 0 && selec < 4);
}

//FUNCION VALORAR EQUIPOS:
//      Permitirá al cronista actualizar las valoraciones de los futbolistas. Para ello,
//      el cronista seleccionará un identificador de un equipo y posteriormente le aparecerá la lista
//      de futbolistas de dicho equipo junto con su valoración actual. A continuación, el cronista irá
//      seleccionando futbolistas e introduciendo sus nuevas valoraciones (0-10).

void valorar_equipos(futbolistas *estructura_futbolistas){

    int valoracion;
    int id_equipo;
    int id_futbolista;
    int i;
    int selec;

    do {

        printf(".....INTRODUZCA UN ID DE EQUIPO.....\n");
        printf("                           \n");
        printf(">");
        scanf("%d", &id_equipo);

        do {
            
            for (i = 0; i <=
                        sizeof(estructura_futbolistas); i++) {       //VAMOS A ENSEñAR TODOS LOS FUTBOLISTAS QUE FORMAN PARTE DE ESE EQUIPO EN UN PEQUEñO MENU, ENSEñANDO TODOS LOS CAMPOS DEL FUTBOLISTA
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

            for (i = 0; i <=
                        sizeof(estructura_futbolistas); i++) {        //LO PRINCIPAL: EL USUARIO INTRODUCIRA EL ID DEL JUGADOR DEL CUAL DESEA CAMBIAR LA VALORACION
                if (id_futbolista == estructura_futbolistas[i].futbolista_id) {
                    printf(".....INTRODUZCA LA NUEVA VALORACION DEL FUTBOLISTA.....\n");
                    printf("                           \n");
                    printf(">");
                    scanf("%d", &estructura_futbolistas[i].valoracion);
                }
            }
            printf(".....ELIJA UNA OPCION......\n");
            printf("                           \n");
            printf("       1.- SEGUIR VALORANDO\n");
            printf("       2.- CAMBIAR DE EQUIPO\n");
            printf("                           \n");
            printf(">");
            scanf("%d", &selec);
        }while(selec == 1);
    }while (selec == 2);
}

#endif //PROYECTO_CRONISTA_H
