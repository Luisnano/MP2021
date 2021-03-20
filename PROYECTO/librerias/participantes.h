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

void listar_jugadores_disponibles(futbolistas *estructura_futbolistas,jugadores_plantillas *estructura_jugadores_plantillas,
                                  configuracion *estructura_config);

void configurar_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                           equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                           plantillas *estructura_plantillas);

void eliminar_plantillas(int *id,plantillas *estructura_plantillas, jugadores_plantillas *estructura_jugadores_plantillas,
                         configuracion *estructura_config);

void ranking(plantillas *estructura_plantillas, configuracion *estructura_config);

void listar_jugadores_plantillas(int *plantilla, jugadores_plantillas *estructura_jugadores_plantillas,
                                 futbolistas *estructura_futbolistas, configuracion *estructura_config);

void eliminar_jugador_plantillas(int *plantilla, jugadores_plantillas *estructura_jugadores_plantillas,
                                futbolistas *estructura_futbolistas,plantillas *estructura_plantillas,
                                 configuracion *estructura_config);

void anadir_jugador_plantillas(int *id,int *plantilla, configuracion *estructura_config,
                               jugadores_plantillas *estructura_jugadores_plantillas,
                               equipos *estructura_equipos, usuarios *estructura_usuarios,
                               futbolistas *estructura_futbolistas,plantillas *estructura_plantillas);

//FUNCIONES

void menu_participantes(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                        equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                        plantillas *estructura_plantillas){

    int opcion;

    printf("---------MENU PARTICIPANTE---------\n\n");

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

            case 3: mostrar_plantillas(estructura_plantillas,estructura_config);
            break;

            case 4: eliminar_plantillas(id,estructura_plantillas,estructura_jugadores_plantillas, estructura_config);
            break;

            case 5: ranking(estructura_plantillas,estructura_config);
            break;

            case 6: salir_programa(estructura_config,estructura_futbolistas,estructura_equipos,estructura_usuarios,
                                   estructura_plantillas,
                                   estructura_jugadores_plantillas);
            break;

            default: printf("\n\nSelecciona una opcion correcta por favor\n\n");

            break;

            }
        }while(opcion > 0 && opcion < 7);

    }

void crear_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                      equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                      plantillas *estructura_plantillas){

    int i, num_plantillas = 0;

    for(i = 0 ; i <= estructura_config->tam_plantillas ; i++){

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

            estructura_plantillas = (plantillas *)realloc(estructura_plantillas,
                                                          (estructura_config->tam_plantillas+1)*sizeof(int));
            if(estructura_plantillas == NULL){

                printf("Fallo de reserva de memoria\n");

            }

            estructura_plantillas[estructura_config->tam_plantillas].usuario_id = *id;

            estructura_plantillas[estructura_config->tam_plantillas].plantilla_id = estructura_config->tam_plantillas;

            printf("\nIntroduce el nombre de la plantilla: ");
            fgets(estructura_plantillas[estructura_config->tam_plantillas].nombre_plantilla,31,stdin);
            fflush(stdin);

            estructura_plantillas[estructura_config->tam_plantillas].presupuesto_disp = estructura_config->presupuesto_defecto;

            estructura_plantillas[estructura_config->tam_plantillas].puntuacion_acum = 0;

        printf("\nLa plantilla se ha creado con exito.\n");
        menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,estructura_usuarios,
                           estructura_futbolistas,estructura_plantillas);
    }

}

void configurar_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas *estructura_jugadores_plantillas,
                           equipos *estructura_equipos, usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                           plantillas *estructura_plantillas){

    int opcion, i, j = 0, plantilla;

    printf("A continuacion, mostraremos tus plantillas actuales.");

    for(i = 0 ; i < estructura_config->tam_plantillas ; i++){

        printf("%i, %s, presupuesto: %i, puntuacion: %i", estructura_plantillas[i].plantilla_id,
               estructura_plantillas[i].nombre_plantilla,estructura_plantillas[i].presupuesto_disp,
               estructura_plantillas[i].puntuacion_acum);
    }

    printf("Selecciona una de ellas para configurarla:");
    scanf("%i",&plantilla);

    printf("---------MENU CONFIGURAR-PLANTILLA---------\n\n");

    printf("1.- Lista de jugadores en plantilla\n");
    printf("2.- Lista de jugadores disponibles\n");
    printf("3.- Añadir jugador a plantilla\n");
    printf("4.- Eliminar jugador de plantilla\n");
    printf("5.- Volver\n");

    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);

    do {
        switch(opcion){

            case 1:     listar_jugadores_plantillas(&plantilla,estructura_jugadores_plantillas,estructura_futbolistas,
                                                    estructura_config);
                break;

            case 2:     listar_jugadores_disponibles(estructura_futbolistas,estructura_jugadores_plantillas,
                                                     estructura_config);
                break;

            case 3:     //Antes de llamar a la funcion comprobamos si la plantilla ya tiene 11 futbolistas
                        //En ese caso vuelve al menu otra vez

                        for(i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

                            if(plantilla == estructura_jugadores_plantillas[i].plantilla_id){

                                //Con j controlo el numero de futbolistas de esa plantilla

                                j++;

                            }
                        }

                        //Comparo si ya hay 11 futbolistas, si no, llamo funcion anadir_futbolista

                        if(j == estructura_config->max_futbolistas_plantilla){

                            printf("\nLa plantilla seleccionada ya tiene 11 futbolistas,"
                                   " si deseas anadir otro, primero elimina uno\n\n");

                            //Volvemos al menu configurar_plantillas

                            configurar_plantillas(id,estructura_config,
                                                  estructura_jugadores_plantillas,estructura_equipos,
                                                  estructura_usuarios,estructura_futbolistas,estructura_plantillas);

                        }

                        else{
                             anadir_jugador_plantillas( id,&plantilla,estructura_config,estructura_jugadores_plantillas,
                                    estructura_equipos,estructura_usuarios,estructura_futbolistas,estructura_plantillas);
                        }

                break;

            case 4:     eliminar_jugador_plantillas(&plantilla,estructura_jugadores_plantillas,estructura_futbolistas,
                                                    estructura_plantillas, estructura_config);
                break;

            case 5:     menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                           estructura_usuarios,estructura_futbolistas,estructura_plantillas);
                break;

            default:    printf("\n\nIntroduce una opcion valida por favor\n\n");

                break;
        }
    }while(opcion > 0 && opcion < 6);



}

void listar_jugadores_disponibles(futbolistas *estructura_futbolistas,jugadores_plantillas *estructura_jugadores_plantillas,
                                  configuracion *estructura_config){

    int i, j, aux;

    for(i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

        if(aux == 1){

            printf("%i , %i , %s , %i , %i\n",estructura_futbolistas[i-1].futbolista_id,estructura_futbolistas[i-1].equipo_id,
                   estructura_futbolistas[i-1].nombre_futbolista,estructura_futbolistas[i-1].futbolista_precio,
                   estructura_futbolistas[i-1].valoracion);
        }

        aux = 1;

        for(j = 0 ; j < estructura_config->tam_jugadores_plantillas && aux == 1 ; j++){

            if(estructura_futbolistas[i].futbolista_id == estructura_jugadores_plantillas[j].jugador_platilla_id){

                aux = 0;

            }
        }
    }

}


void ranking(plantillas *estructura_plantillas, configuracion *estructura_config) {

    int i, j, aux;

    int ranking[estructura_config->tam_plantillas];    //PASAMOS LA ESTRUCTURA A UN VECTOR RANKING PARA PODER ASI ORDENARLOS

    for (i = 0; i < estructura_config->tam_plantillas ; i++) {

        ranking[i] = estructura_plantillas[i].puntuacion_acum;
    }

    //AHORA HACEMOS UN ALGORITMO DE ORDENACION SIMPLE, CON AYUDA DE UN AUX COMPARAMOS SI EL ELEMENTO ACTUAL

    for (i = 0 ; i < estructura_config->tam_plantillas ; i++) {

        for (j = 0 ; j < estructura_config->tam_plantillas ; j++) {


            if (ranking[j] > ranking[j + 1]) {    //ES MAYOR QUE EL SIGUIENTE. SI LO ES, SE INTERCAMBIAN.

            aux = ranking[j + 1];

            ranking[j + 1] = ranking[j];

            ranking[j] = aux;

             }
         }
    }

    for(i = 0 ; i < estructura_config->tam_plantillas ; i++){

        printf("%i , %s => %i PUNTOS\n", estructura_plantillas[i].plantilla_id,
               estructura_plantillas[i].nombre_plantilla, ranking[i]);

    }
}

void eliminar_plantillas(int *id, plantillas *estructura_plantillas, jugadores_plantillas *estructura_jugadores_plantillas,
                         configuracion *estructura_config){

    int i, plantilla, v[4];
    char aux;

    printf("\nSeleccione el id de su plantilla que desea eliminar , las cuales son:");

    for(i = 0 ; i < estructura_config->tam_plantillas ; i++){        //Mostramos las plantillas

        //Comprobamos que se impriman las plantillas del usuario

        if(*id == estructura_plantillas[i].usuario_id){

        printf("\n%i, %s, presupuesto: %i, puntuacion: %i", estructura_plantillas[i].plantilla_id,
               estructura_plantillas[i].nombre_plantilla,estructura_plantillas[i].presupuesto_disp,
               estructura_plantillas[i].puntuacion_acum);
        }
    }

    printf("\nId plantilla:");
    scanf("%i",&plantilla);

    //Para eliminar la plantilla seleccionada, creamos un vector auxiliar para los datos de formato entero de plantillas
    //y una variable auxiliar tipo string llamada aux para guardar el plantilla_nombre
    //Con estos auxiliares guardamos los datos de la plantilla para intercambair su posicion en estructura_plantillas
    //Con la ultima plantilla, así al hacer el realloc eliminamos la plantilla seleccionada

    for (i = 0 ; i < estructura_config->tam_plantillas ; i++){

        if(plantilla == estructura_plantillas[i].plantilla_id){     //Para localizar la plantilla introducida

            v[0] = estructura_plantillas[i].usuario_id;
            v[1] = estructura_plantillas[i].plantilla_id;
            v[2] = estructura_plantillas[i].presupuesto_disp;
            v[3] = estructura_plantillas[i].puntuacion_acum;
            strcpy(&aux,estructura_plantillas[i].nombre_plantilla);

            estructura_plantillas[i].usuario_id = estructura_plantillas[estructura_config->tam_plantillas].usuario_id;
            estructura_plantillas[i].plantilla_id = estructura_plantillas[estructura_config->tam_plantillas].plantilla_id;
            estructura_plantillas[i].presupuesto_disp = estructura_plantillas[estructura_config->tam_plantillas].presupuesto_disp;
            estructura_plantillas[i].puntuacion_acum = estructura_plantillas[estructura_config->tam_plantillas].puntuacion_acum;
            strcpy(estructura_plantillas[i].nombre_plantilla, estructura_plantillas[estructura_config->tam_plantillas].nombre_plantilla);

            estructura_plantillas[estructura_config->tam_plantillas].usuario_id = v[0];
            estructura_plantillas[estructura_config->tam_plantillas].plantilla_id = v[1];
            estructura_plantillas[estructura_config->tam_plantillas].presupuesto_disp = v[2];
            estructura_plantillas[estructura_config->tam_plantillas].puntuacion_acum = v[3];
            strcpy(estructura_plantillas[estructura_config->tam_plantillas].nombre_plantilla , &aux);
        }
    }

    //Redimensionamos el vector estructura_plantillas, al eliminar una plantilla, le quitamos un elemento

    estructura_plantillas = (plantillas*)realloc(estructura_plantillas,(estructura_config->tam_plantillas-1)*sizeof(int));
    if(estructura_plantillas == NULL){printf("\nFallo de reserva de memoria");}

    //Ahora eliminamos todos los futbolistas de jugadores_plantillas con la id de la plantilla eliminada
    //El uso del do while se debe a que si cambio un futbolista de la plantilla seleccionada por el ultimo para
    //Hacer el realloc es posible que el ultimo futbolista tambien pertenezca a esa plantilla

    for(i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

        do{

            v[0] = estructura_jugadores_plantillas[i].jugador_platilla_id;
            v[1] = estructura_jugadores_plantillas[i].plantilla_id;

            estructura_jugadores_plantillas[i].jugador_platilla_id =
                    estructura_jugadores_plantillas[estructura_config->tam_jugadores_plantillas].jugador_platilla_id;
            estructura_jugadores_plantillas[i].plantilla_id =
                    estructura_jugadores_plantillas[estructura_config->tam_jugadores_plantillas].plantilla_id;

            estructura_jugadores_plantillas[estructura_config->tam_jugadores_plantillas].jugador_platilla_id = v[0];
            estructura_jugadores_plantillas[estructura_config->tam_jugadores_plantillas].plantilla_id = v[1];

            estructura_jugadores_plantillas = (jugadores_plantillas *)
                    realloc(estructura_jugadores_plantillas,(estructura_config->tam_jugadores_plantillas-1)*sizeof(int));

            if(estructura_jugadores_plantillas == NULL){printf("\nFallo de reserva de memoria");}

        } while(plantilla == estructura_jugadores_plantillas[i].plantilla_id);

    }

}

void listar_jugadores_plantillas(int *plantilla, jugadores_plantillas *estructura_jugadores_plantillas,
                                futbolistas *estructura_futbolistas, configuracion *estructura_config){

    int i, j;

    printf("\n\nLos futbolistas que pertenecen a la plantilla %i son:",*plantilla);

    for(i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

        //Identifico a los futbolistas de esa plantilla ya que plantilla_id es el mismo dato en jugadores_plantillas
        //Y en plantillas

        if (*plantilla == estructura_jugadores_plantillas[i].plantilla_id){

            //Busco al futbolista mediante su campo futbolista_id para imprimir sus datos

            for(j = 0 ; j < estructura_config->tam_futbolistas ; j++){

                //Identifico al futbolista

                if(estructura_jugadores_plantillas[i].jugador_platilla_id == estructura_futbolistas[j].futbolista_id){

                    //Muestro sus datos

                    printf("\n%i , equipo:%i, %s, precio:%i, valoracion:%i\n",estructura_futbolistas[j].futbolista_id,
                           estructura_futbolistas[j].equipo_id,estructura_futbolistas[j].nombre_futbolista,
                           estructura_futbolistas[j].futbolista_precio,estructura_futbolistas[j].valoracion);

                }
            }
        }
    }
}

void eliminar_jugador_plantillas(int *plantilla, jugadores_plantillas *estructura_jugadores_plantillas,
                                futbolistas *estructura_futbolistas,plantillas *estructura_plantillas,
                                 configuracion *estructura_config) {

    int i, j, opcion, aux1, aux2;

    printf("\n\nLos futbolistas que pertenecen a la plantilla %i son:", *plantilla);

    for (i = 0; i < estructura_config->tam_jugadores_plantillas ; i++) {

        //Identifico a los futbolistas de esa plantilla ya que plantilla_id es el mismo dato en jugadores_plantillas
        //Y en plantillas

        if (*plantilla == estructura_jugadores_plantillas[i].plantilla_id) {

            //Muestro sus datos

            printf("\n%i , equipo:%i, %s, precio:%i, valoracion:%i\n", estructura_futbolistas[i].futbolista_id,
                   estructura_futbolistas[i].equipo_id, estructura_futbolistas[i].nombre_futbolista,
                   estructura_futbolistas[i].futbolista_precio, estructura_futbolistas[i].valoracion);

        }
    }

    printf("\n\nAhora elija un jugador a eliminar:");
    scanf("%i",&opcion);

    //Busco al futbolista para poder hacer la suma de presupuesto de la plantilla

    for(i = 0 ; i <estructura_config->tam_futbolistas ; i++){

        if(opcion == estructura_futbolistas[i].futbolista_id){

            //En j guardo el indicador de ese futbolista concreto en la estructura para poder referirme a el
            //Uso j pues no la voy a volver a usar en la funcion

            j = i;

        }
    }

    //Le sumo al presupuesto de la plantilla seleccinada el precio del futbolista eliminado

    estructura_plantillas[*plantilla].presupuesto_disp =
            estructura_plantillas[*plantilla].presupuesto_disp + estructura_futbolistas[j].futbolista_precio;

    //Para hacer el realoc restando 1 espacio a estructura_jugadores_plantillas , intercambio el futbolista sellecionado
    //Por el ultimo, así al hacer el realloc lo borro , aux1 y aux2 me ayudaran a hacer el cambio ya que
    //Jugadores_plantillas tiene 2 parametros

    for(i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

        if(opcion == estructura_jugadores_plantillas[i].jugador_platilla_id) {

            aux1 = estructura_jugadores_plantillas[opcion].jugador_platilla_id;
            aux2 = estructura_jugadores_plantillas[opcion].plantilla_id;

            estructura_jugadores_plantillas[opcion].jugador_platilla_id = estructura_jugadores_plantillas[i].jugador_platilla_id;
            estructura_jugadores_plantillas[opcion].plantilla_id = estructura_jugadores_plantillas[i].plantilla_id;

            estructura_jugadores_plantillas[i].jugador_platilla_id = aux1;
            estructura_jugadores_plantillas[i].plantilla_id = aux2;

            //Una vez cambiados los valores, procedo a hacer el realloc

            estructura_jugadores_plantillas = (jugadores_plantillas *)
                    realloc(estructura_jugadores_plantillas,(estructura_config->tam_jugadores_plantillas-1)*sizeof(int));

            if(estructura_jugadores_plantillas == NULL){printf("\nFallo de reserva de memoria");}

        }
    }

}

void anadir_jugador_plantillas(int *id,int *plantilla, configuracion *estructura_config,
                               jugadores_plantillas *estructura_jugadores_plantillas,equipos *estructura_equipos,
                               usuarios *estructura_usuarios, futbolistas *estructura_futbolistas,
                                plantillas *estructura_plantillas){

    int i, aux1, aux2,futbolista;

    //Llamo a la funcion mostrar futbolista anteriormente declarada

    mostrar_futbolistas(estructura_futbolistas,estructura_config);

    printf("\nIntroduce el ID del futbolista que quiera anadir a la plantilla:");
    scanf("%i",&futbolista);

    //Identifico al futbolista

    for(i = 0 ; i < estructura_config->tam_futbolistas ; i++){

        if(futbolista == estructura_futbolistas[i].futbolista_id){

            //Aux1 toma el indicador del futbolista para poder referirme a el mas adelante

            aux1 = i;
        }
    }

    for(i = 0 ; i < estructura_config->tam_plantillas ; i++){

        if(estructura_plantillas[i].plantilla_id == *plantilla){

            //Aux2 toma el indicador de la plantilla para poder referirme a el mas adelante

            aux2 = i;
        }

    }
    //Comprobamos si la plantilla dispone de suficiente presupuesto para comprar al jugador

    if(estructura_futbolistas[aux1].futbolista_precio > estructura_plantillas[aux2].presupuesto_disp){

        printf("\nEl precio del futbolista que has seleccionado es superior al presupuesto de tu plantilla\n\n");

        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas,
                 estructura_equipos, estructura_usuarios, estructura_futbolistas, estructura_plantillas);

    }

    else{

        //Comprobamos si el futbolista ya esta en la plantilla o en otra, en ese caso no esta disponible

        for(i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

            //Comprobar coincidencia del futbolista_id y su plantilla_id

            if(estructura_jugadores_plantillas[i].jugador_platilla_id == aux1+1 ||
            estructura_jugadores_plantillas[i].plantilla_id == aux2+1 ){

                printf("\nEl futbolista seleccionado no esta disponible\n\n");

                configurar_plantillas(id,  estructura_config,  estructura_jugadores_plantillas,
                                      estructura_equipos,  estructura_usuarios,  estructura_futbolistas,
                                      estructura_plantillas);
            }
        }

        printf("\nEl futbolista seleccionado es valido\n");

        //Con realloc aumentamos en 1 el tamaño de estructura_jugadores_plantillas

        estructura_jugadores_plantillas = (jugadores_plantillas *)
                realloc(estructura_jugadores_plantillas,(estructura_config->tam_jugadores_plantillas+1)*sizeof(int));

        if(estructura_jugadores_plantillas==NULL){printf("\nFallo de reserva de memoria");}

        //Relleno los datos del nuevo espacio reservado con los datos del futbolista seleccionado
        //Los cuales estan guardados en aux1 y aux2

        estructura_jugadores_plantillas[estructura_config->tam_jugadores_plantillas].jugador_platilla_id = aux1+1;
        estructura_jugadores_plantillas[estructura_config->tam_jugadores_plantillas].plantilla_id = aux2+1;
    }

}



#endif //PROYECTO_PARTICIPANTES_H
