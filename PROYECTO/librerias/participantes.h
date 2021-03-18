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
    if(num_plantillas == estructura_config->max_plantillas_participante){
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

    int opcion, i,plantilla;

    printf("A continuacion, mostraremos tus plantillas actuales.");

    for(i = 0; i <= sizeof(estructura_plantillas); i++){

        printf("%i, %s, presupuesto: %i, puntuacion: %i", estructura_plantillas[i].plantilla_id,
               estructura_plantillas[i].nombre_plantilla,estructura_plantillas[i].presupuesto_disp,
               estructura_plantillas[i].puntuacion_acum);
    }

    printf("Selecciona una de ellas para configurarla:");
    scanf("%i",&plantilla);

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


void ranking(plantillas *estructura_plantillas) {

    int i, j, aux;

    int ranking[sizeof(estructura_plantillas)];    //PASAMOS LA ESTRUCTURA A UN VECTOR RANKING PARA PODER ASI ORDENARLOS

    for (i = 0; i <= sizeof(estructura_plantillas); i++) {

        ranking[i] = estructura_plantillas[i].puntuacion_acum;
    }

    //AHORA HACEMOS UN ALGORITMO DE ORDENACION SIMPLE, CON AYUDA DE UN AUX COMPARAMOS SI EL ELEMENTO ACTUAL

    for (i = 0; i <= sizeof(estructura_plantillas); i++) {

        for (j = i; j <= sizeof(estructura_plantillas); j++) {


            if (ranking[j] > ranking[j + 1]) {    //ES MAYOR QUE EL SIGUIENTE. SI LO ES, SE INTERCAMBIAN.

            aux = ranking[j + 1];

            ranking[j + 1] = ranking[j];

            ranking[j] = aux;

             }
         }
    }

    for(i=0; i <= sizeof(estructura_plantillas); i++){

        printf("%i , %s => %i PUNTOS\n", estructura_plantillas[i].plantilla_id, estructura_plantillas[i].nombre_plantilla, ranking[i]);

    }
}

void eliminar_plantillas(plantillas *estructura_plantillas, jugadores_plantillas *estructura_jugadores_plantillas){

    int i ,plantilla,v[3];
    char aux;

    printf("Seleccione el id de su plantilla que desea eliminar , las cuales son:");

    for(i = 0; i <= sizeof(estructura_plantillas); i++){        //Mostramos las plantillas

        printf("%i, %s, presupuesto: %i, puntuacion: %i", estructura_plantillas[i].plantilla_id,
               estructura_plantillas[i].nombre_plantilla,estructura_plantillas[i].presupuesto_disp,
               estructura_plantillas[i].puntuacion_acum);
    }

    printf("Id plantilla:");
    scanf("%i",&plantilla);

    //Para eliminar la plantilla seleccionada, creamos un vector auxiliar para los datos de formato entero de plantillas
    //y una variable auxiliar tipo string llamada aux para guardar el plantilla_nombre
    //Con estos auxiliares guardamos los datos de la plantilla para intercambair su posicion en estructura_plantillas
    //Con la ultima plantilla, así al hacer el realloc eliminamos la plantilla seleccionada

    for (i=0 ; i<=sizeof(estructura_plantillas) ; i++){

        if(plantilla == estructura_plantillas[i].plantilla_id){     //Para localizar la plantilla introducida

            v[0] = estructura_plantillas[i].usuario_id;
            v[1] = estructura_plantillas[i].plantilla_id;
            v[2] = estructura_plantillas[i].presupuesto_disp;
            v[3] = estructura_plantillas[i].puntuacion_acum;
            strcpy(aux,estructura_plantillas[i].nombre_plantilla);

            estructura_plantillas[i].usuario_id = estructura_plantillas[sizeof(estructura_plantillas)].usuario_id;
            estructura_plantillas[i].plantilla_id = estructura_plantillas[sizeof(estructura_plantillas)].plantilla_id;
            estructura_plantillas[i].presupuesto_disp = estructura_plantillas[sizeof(estructura_plantillas)].presupuesto_disp;
            estructura_plantillas[i].puntuacion_acum = estructura_plantillas[sizeof(estructura_plantillas)].puntuacion_acum;
            strcpy(estructura_plantillas[i].nombre_plantilla , estructura_plantillas[sizeof(estructura_plantillas)].nombre_plantilla);

            estructura_plantillas[sizeof(estructura_plantillas)].usuario_id = v[0];
            estructura_plantillas[sizeof(estructura_plantillas)].plantilla_id = v[1];
            estructura_plantillas[sizeof(estructura_plantillas)].presupuesto_disp = v[2];
            estructura_plantillas[sizeof(estructura_plantillas)].puntuacion_acum = v[3];
            strcpy(estructura_plantillas[sizeof(estructura_plantillas)].nombre_plantilla , aux);
        }
    }

    //Redimensionamos el vector estructura_plantillas, al eliminar una plantilla, le quitamos un elemento

    estructura_plantillas = (plantillas*)realloc(estructura_plantillas,(sizeof(estructura_plantillas)-1)*sizeof(int));
    if(estructura_plantillas==NULL){printf("Fallo de reserva de memoria");}

    //Ahora eliminamos todos los futbolistas de jugadores_plantillas con la id de la plantilla eliminada
    //El uso del do while se debe a que si cambio un futbolista de la plantilla seleccionada por el ultimo para
    //Hacer el realloc es posible que el ultimo futbolista tambien pertenezca a esa plantilla

    for(i=0 ; i<=sizeof(estructura_jugadores_plantillas) ; i++){

        do{

            v[0] = estructura_jugadores_plantillas[i].jugador_platilla_id;
            v[1] = estructura_jugadores_plantillas[i].plantilla_id;

            estructura_jugadores_plantillas[i].jugador_platilla_id =
                    estructura_jugadores_plantillas[sizeof(estructura_jugadores_plantillas)].jugador_platilla_id;
            estructura_jugadores_plantillas[i].plantilla_id =
                    estructura_jugadores_plantillas[sizeof(estructura_jugadores_plantillas)].plantilla_id;

            estructura_jugadores_plantillas[sizeof(estructura_jugadores_plantillas)].jugador_platilla_id = v[0];
            estructura_jugadores_plantillas[sizeof(estructura_jugadores_plantillas)].plantilla_id = v[1];

            estructura_jugadores_plantillas = (jugadores_plantillas *)
                    realloc(estructura_jugadores_plantillas,(sizeof(estructura_jugadores_plantillas)-1)*sizeof(int));

            if(estructura_plantillas==NULL){printf("Fallo de reserva de memoria");}

        } while(plantilla == estructura_jugadores_plantillas[i].plantilla_id);

    }

}




#endif //PROYECTO_PARTICIPANTES_H
