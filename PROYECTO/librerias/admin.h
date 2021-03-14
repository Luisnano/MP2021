#ifndef PROYECTO_ADMIN_H
#define PROYECTO_ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include "core.h"

void listarEquipos(equipos *, configuracion *);
void modificarEquipos( equipos *, configuracion *);
void addEquipos(equipos *, configuracion *);
void eliminarEquipos(equipos *, configuracion *);
void listarusuarios(futbolistas *, configuracion *);
void modificarusuarios(futbolistas *, configuracion *);
void addusuarios(futbolistas *, configuracion *);
void eliminarusuarios(futbolistas *, configuracion *);
void modificarConfiguracion(configuracion *);
int op;

printf("MENU ADMINISTRADOR\n\n");

printf("1.- Equipos\n");
printf("2.- Usuarios\n");
printf("3.- Configuracion\n");
printf("4.- Salir del programa\n");
    scanf("%d",&op);
do{
    switch(op){
        case 1:
            int op1;
            do{
                printf("Bienvenido al menú de equipos\n");
                printf("1.- Listar equipos\n");
                printf("2.- Modificar equipos\n");
                printf("3.- Annadir equipos\n");
                printf("4.- Eliminar equipos\n");
                    scanf("%d",&op1);
                    switch(op1){
                        case 1:
                            listarEquipos(&estructura_equipos,&estructura_config);break;
                        case 2:
                            modificarEquipos(&estructura_equipos,&estructura_config);break;
                        case 3:
                            addEquipos(&estructura_equipos,&estructura_config);break;
                        case 4:
                            eliminarEquipos(&estructura_equipos,&estructura_config);break;
                    }

                }
            break;
        case 2:
            int op2;
                printf("Bienvenido al menú de usuarios\n");
                printf("1.- Listar usuarios\n");
                printf("2.- Modificar usuarios\n");
                printf("3.- Annadir usuarios\n");
                printf("4.- Eliminar usuarios\n");
                    scanf("%d",&op2);break;

        case 3:
                printf("Bienvenido al menú de configuracion\n");
                modificarConfiguracion(&estructura_config);break;

        case 4:
            //funcion salirPrograma();
        default:
            exit(1);
    }
}while(op < 1 || op > 4);

void listarEquipos(equipos *estructura_equipos, configuracion *estructura_config){
    for(int i = 0;i<estructura_config->max_equipos;i++){
        printf("Equipo %d:\n",i+1);
        printf("Id del equipo: %d.\n",estructura_equipos[i].equipo_id);
        printf("Nombre del equipo: %s.\n",estructura_equipos[i].nombre_equipo);
        puts("");
    }
}

void modificarEquipos( equipos *estructura_equipos, configuracion *estructura_config) {
    int a, b, error = 0;
    char nombre[21];
    do {
        printf("Introduce un id para modificar el equipo: ");
        scanf("%d", &a);
        for (int i = 0; i < estructura_config->max_equipos; i++) {
            if (a == estructura_equipos[i].equipo_id) {
                printf("Seleccione un numero id para el equipo: ");
                scanf("%d", &b);
                for (int j = 0; j < estructura_config->max_equipos; j++) {
                    if (b != estructura[j].equipo_id){
                        estructura_equipos[i].equipo_id = b;
                    }else error = 1;
                }
                printf("Ahora seleccione un nuevo nombre para el equipo [max 20 caracteres]: ");
                scanf("%s",nombre);
                for (int j = 0; j < estructura_config->max_equipos; j++) {
                    if strcmp((nombre,estructura[j].nombre_equipo) != 0){
                        estructura_equipos[i].equipo_id = nombre;
                    }else error = 1;
                }
            }
        }
    } while(error != 1);
}

void addEquipos(equipos *estructura_equipos, configuracion *estructura_config){
    int new_id, error = 0;
    char new_nombre[21];
    do {
        printf("Introduce un numero id de equipo: ");
        scanf("%d", &new_id);

        for (int i = 0; i < estructura_config->max_equipos; i++) {
            if (new_id == estructura_equipos[i].equipo_id) {
                printf("El id ya existe.\n");
                error = 1;
            } else estructura_equipos[i].equipo_id = new_id;
            printf("Introduce el nombre del equipo: ");
            scanf("%s",new_nombre);
            if(strcmp(new_nombre, estructura_equipos[i].nombre_equipo) != 0){
                estructura_equipos[i].nombre_equipo = new_nombre;
            }else printf("El nombre del equipo ya existe");error = 1;
        }
    }while(error != 1);
}

void eliminarEquipos(equipos *estructura_equipos, configuracion *estructura_config){
    int a, error = 0;
    do {
        printf("Introduzca el id del equipo a eliminar: ");
        scanf("%d", &a);
        for(int i = 0;i<estructura_config->max_equipos;i++){
            if(a == estructura_equipos[i].equipo_id){
                estructura_equipos[i].equipo_id = 0;
                estructura_equipos[i].nombre_equipo = "";
            }else printf("El equipo seleccionado no existe");error = 1;
        }
    }while(error != 1);
}

void modificarConfiguracion(configuracion * estructura_config){
    int a;
    do {
        printf("Seleccione que desea cambiar de la configuracion: ");
        printf("1.-\nNumero maximo de equipos.\n");
        printf("2.-Presupuesto por defecto.\n");
        printf("3.-Numero maximo de jugadores por equipo.\n");
        printf("4.-Numero maximo de plantillas por participante.\n");
        printf("5.-Numero maximo de jugadores.\n");
        printf("6.-Numero de usuarios.\n");

        scanf("%d", &a);
        switch (a) {
            case 1:
                    do {
                        printf("Seleccione el nuevo valor para el numero maximo de equipos");
                        scanf("%d",&estructura_config.max_equipos);
                    }while(estructura_config.max_equipos < 1 || estructura_config.max_equipos > 20);break;
            case 2:
                do {
                    printf("Seleccione el nuevo valor para el presupuesto por defecto");
                    scanf("%d",&estructura_config.presupuesto_defecto);
                }while(estructura_config.max_equipos < 1 || estructura_config.max_equipos > 300);break;

            case 3:
                do {
                    printf("Seleccione el nuevo valor para el numero maximo de jugadores por equipo");
                    scanf("%d",&estructura_config.max_futbolistas_plantilla);
                }while(estructura_config.max_futbolistas_plantilla < 1 || estructura_config.max_futbolistas_plantilla > 11);
            case 4:
                do {
                    printf("Seleccione el nuevo valor para el numero maximo plantillas por usuario");
                    scanf("%d",&estructura_config.max_plantillas_participante);
                }while(estructura_config.max_plantillas_participante < 1 || estructura_config.max_plantillas_participante > 4);
            case 5:
                do {
                    printf("Seleccione el nuevo valor para el numero maximo futbolistas");
                    scanf("%d",&estructura_config.max_futbolistas);
                }while(estructura_config.max_futbolistas < 1 || estructura_config.max_futbolistas > 100);
            case 6:
                do {
                    printf("Seleccione el nuevo valor para el numero maximo de usuarios");
                    scanf("%d",&estructura_config.max_usuarios);
                }while(estructura_config.max_usuarios < 1 || estructura_config.max_usuarios > 6);
            default:
                exit(1);

        }
    }while();
}
#endif //PROYECTO_ADMIN_H
