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


//MENU CRONISTA:
//      En caso de que el usuario sea cronista debe aparecer un menú:
//      MENU CRONISTA
//      1.- Listar Equipos
//      2.- Valorar Equipos
//      3.- Salir del programa
void menu_cronista(equipos *estructura_equipos){
    int selec;
    printf("---------MENU CRONISTA----------\n");
    printf("                          \n");
    printf("      1.-Listar equipos    \n");
    printf("      2.-Valorar equipos   \n");
    printf("      3.-Salir del programa\n");
    printf("                          \n");
    printf(".....SELECCIONE UNA OPCION.....\n");
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
    } while (selec != 1 || selec != 2 || selec != 3)
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
    etiqueta_seleccion_equipos:                               //ETIQUETA QUE UTILIZAREMOS MAS TARDE POR SI EL USUARIO QUIERE CAMBIAR DE EQUIPO
    printf(".....INTRODUZCA UN ID DE EQUIPO.....\n");
    scanf("%d", &id_equipo);

    etiqueta_vuelta_valoracion:                               //ETIQUETA QUE UTILIZAREMOS MAS TARDE POR SI EL USUARIO QUIERE CAMBIAR DE JUGADOR A VALORAR(DENTRO DEL MISMO EQUIPO)

    for (i=0; i<sizeof (estructura_futbolistas); i++) {       //VAMOS A ENSEñAR TODOS LOS FUTBOLISTAS QUE FORMAN PARTE DE ESE EQUIPO EN UN PEQUEñO MENU, ENSEñANDO TODOS LOS CAMPOS DEL FUTBOLISTA
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
    for (i=0; i<sizeof (estructura_futbolistas); i++){        //LO PRINCIPAL: EL USUARIO INTRODUCIRA EL ID DEL JUGADOR DEL CUAL DESEA CAMBIAR LA VALORACION
        if(id_futbolista == estructura_futbolistas[i].futbolista_id){
            printf(".....INTRODUZCA LA NUEVA VALORACION DEL FUTBOLISTA.....\n");
            scanf("%d", &estructura_futbolistas[i].valoracion);
        }
    }
    printf(".....ELIJA UNA OPCION......\n");
    printf("                           \n");
    printf("       1.- SEGUIR VALORANDO\n");
    printf("       2.- CAMBIAR DE EQUIPO\n");
    printf("       3.- SALIR DE VALORAR EQUIPOS\n");
    printf("                           \n");
    scanf("%d", &selec);
    do {
        switch (selec) {
            case 1:
                goto etiqueta_vuelta_valoracion;
                break;
            case 2:
                goto etiqueta_seleccion_equipos;
                break;
            case 3:
                goto etiqueta_final;
                break;
        }
    } while (selec != 1 || selec != 2 || selec != 3);
    etiqueta_final:                                         //ETIQUETA PARA TERMINAR YA ESTA FUNCION
}

#endif //PROYECTO_CRONISTA_H
