#ifndef PROYECTO_PARTICIPANTES_H
#define PROYECTO_PARTICIPANTES_H

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

//CABECERAS DE FUNCIONES

void menu_participantes(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                        equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                        plantillas **estructura_plantillas);

void crear_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                      equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                      plantillas **estructura_plantillas);

void listar_jugadores_disponibles(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                                  equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                                  plantillas **estructura_plantillas);

void configurar_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                           equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                           plantillas **estructura_plantillas);

void eliminar_plantillas(int *id,plantillas **estructura_plantillas, jugadores_plantillas **estructura_jugadores_plantillas,
                         configuracion *estructura_config);

void ranking(plantillas **estructura_plantillas, configuracion *estructura_config);

void listar_jugadores_plantillas(int *plantilla, jugadores_plantillas **estructura_jugadores_plantillas,
                                 futbolistas **estructura_futbolistas, configuracion *estructura_config);

void eliminar_jugador_plantillas(int *plantilla,int *id, jugadores_plantillas **estructura_jugadores_plantillas,
                                futbolistas **estructura_futbolistas,plantillas **estructura_plantillas,
                                 configuracion *estructura_config,equipos **estructura_equipos,
                                 usuarios **estructura_usuarios);

void anadir_jugador_plantillas(int *id,int *plantilla, configuracion *estructura_config,
                               jugadores_plantillas **estructura_jugadores_plantillas,
                               equipos **estructura_equipos, usuarios **estructura_usuarios,
                               futbolistas **estructura_futbolistas,plantillas **estructura_plantillas);

//FUNCIONES


//Cabecera: void menu_participantes(int *id, configuracion *estructura_config,
//                                  jugadores_plantillas **estructura_jugadores_plantillas, equipos **estructura_equipos,
//                                  usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
//                                  plantillas **estructura_plantillas);
//Precondición: La función recibe la id del participante , junto con todos los vectores de estructuras
//Postcondición: La función muestra las distintas opciones del menu participante para poder acceder a ellas

void menu_participantes(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                        equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                        plantillas **estructura_plantillas){



    int opcion,i,cont;     // Opcion es donde guardamos la opción seleccionada

    printf("\n\n---------MENU PARTICIPANTE---------\n\n");

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
                    menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                   estructura_usuarios,estructura_futbolistas,estructura_plantillas);
            break;

            case 2: //Para poder configurar plantillas el participante, este debe tener al menos 1 plantilla

                    cont = 0;

                    for (i = 0 ; i < (*estructura_config).tam_plantillas ; i++){

                        if ((*estructura_plantillas)[i].usuario_id == *id){

                            cont++;     //Guarda el nº de plantillas q tiene empezando en 0
                        }

                    }
                    //Si no tiene plantillas vuelta al menú

                    if (cont == 0){

                        printf("\nNo puedes seleccionar esta opción si no tienes ni 1 plantillas, crea 1 primero\n");
                        menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                           estructura_usuarios,estructura_futbolistas,estructura_plantillas);

                    }
                    configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                                          estructura_usuarios, estructura_futbolistas,estructura_plantillas);
            break;

            case 3: mostrar_plantillas(estructura_plantillas,estructura_config);
                    menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                       estructura_usuarios,estructura_futbolistas,estructura_plantillas);
            break;

            case 4: //Para poder eliminar plantillas el participante, este debe tener al menos 1 plantilla

                    cont = 0;

                    for (i = 0 ; i < (*estructura_config).tam_plantillas ; i++){

                        if ((*estructura_plantillas)[i].usuario_id == *id){

                        cont++;     //Guarda el nº de plantillas q tiene empezando en 0
                        }

                    }
                    //Si no tiene plantillas vuelta al menú

                    if (cont == 0){

                    printf("\nNo puedes seleccionar esta opción si no tienes ni 1 plantillas, crea 1 primero\n");
                    menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                       estructura_usuarios,estructura_futbolistas,estructura_plantillas);

                    }

                    eliminar_plantillas(id,estructura_plantillas,estructura_jugadores_plantillas, estructura_config);

                    menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                   estructura_usuarios,estructura_futbolistas,estructura_plantillas);
            break;

            case 5: ranking(estructura_plantillas,estructura_config);

                    menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                   estructura_usuarios,estructura_futbolistas,estructura_plantillas);
            break;

            case 6: salir_programa(estructura_config,estructura_futbolistas,estructura_equipos,estructura_usuarios,
                                   estructura_plantillas,
                                   estructura_jugadores_plantillas);
            break;

            default: printf("\n\nSelecciona una opcion correcta por favor\n\n");

            break;

            }

        }while(opcion > 0 && opcion < 7);       //Mientras la opcion no sea correcta repite el menú

    }


//Cabecera: void crear_plantillas(int *id, configuracion *estructura_config,
//                                jugadores_plantillas **estructura_jugadores_plantillas,equipos **estructura_equipos,
//                                usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
//                                plantillas **estructura_plantillas);
//Precondición: Recibe la id del participante y todas  los demas vectores estructura
//Postcondición: Crea una nueva plantilla para el participante en caso de que sea posible

void crear_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                      equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                      plantillas **estructura_plantillas){

    //num_plantillas llevara la cuenta de las plantillas que posee el participante,
    // empezando en 0 para incrementar segun vayamos detectando

    int i = 0, num_plantillas = 0;

    // El siguiente bucle cuenta el nº de plantillas que tiene el participante

    for(i = 0 ; i < (*estructura_config).tam_plantillas ; i++){

        if((*estructura_plantillas)[i].usuario_id == *id){

            num_plantillas++;     //Si detecta plantilla del participante aumenta el contador
        }
    }

    //Si el participante ha alcanzado el nº máximo de plantillas permitido entonces no puede seguir y vuelta al menu

    if(num_plantillas == (*estructura_config).max_plantillas_participante){

        printf("Numero maximo de plantillas alcanzado.\n");
        menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,estructura_usuarios,
                           estructura_futbolistas,estructura_plantillas);
    }

    //Si se pueden crear plantillas:

    else{

        printf("Se procede a crear una plantilla: \n");

        //Aumentamos el tamaño del vector dinamico en 1 ya que creamos 1 plantilla

        (*estructura_config).tam_plantillas++;    //Aumentamos en 1 el tamaño de plantillas

        *estructura_plantillas = (plantillas *)realloc((*estructura_plantillas),
                                                          ((*estructura_config).tam_plantillas)*sizeof(plantillas));

        if(estructura_plantillas == NULL){

            printf("Fallo de reserva de memoria\n");
            exit(EXIT_FAILURE);

        }

        //Empezamos a darle datos a la nueva plantilla
        //Algunos de ellos ya lo sabemos y otros los pedimos por teclado
        //La id del dueño de la plantilla es la del participante:

        (*estructura_plantillas)[(*estructura_config).tam_plantillas-1].usuario_id = *id;

        //El ID de la plantilla será el tamaño maximo del vector,
        //Ya que este tamaño va parejo con la última plantilla existente

        (*estructura_plantillas)[(*estructura_config).tam_plantillas-1].plantilla_id =
                                                                                     (*estructura_config).tam_plantillas;

        printf("\nIntroduce el nombre de la plantilla: ");

        fflush(stdin);
        fgets((*estructura_plantillas)[(*estructura_config).tam_plantillas-1].nombre_plantilla,31,stdin);

        //Le quitamos el /n para que se escriba bien y no en la siguiente linea del fichero

        (*estructura_plantillas)[(*estructura_config).tam_plantillas-1].nombre_plantilla[strcspn
                    ((*estructura_plantillas)[(*estructura_config).tam_plantillas-1].nombre_plantilla, "\n")] = 0;
        fflush(stdin);

        //Le damos a esa plantilla el presupuesto por defecto definido en configuracion.txt

        (*estructura_plantillas)[(*estructura_config).tam_plantillas-1].presupuesto_disp =
                                                                            (*estructura_config).presupuesto_defecto;
        //La puntuación empieza en 0 en todas las plantillas creadas

        (*estructura_plantillas)[(*estructura_config).tam_plantillas-1].puntuacion_acum = 0;

        printf("\nLa plantilla se ha creado con exito.\n");

    }

}

//Cabecera: void configurar_plantillas(int *id, configuracion *estructura_config,
//                                     jugadores_plantillas **estructura_jugadores_plantillas,equipos **estructura_equipos
//                                     , usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
//                                     plantillas **estructura_plantillas);
//Precondicion: La función recibe el id del participante junto con todos los demas vectores de estructura
//Postcondición: La funcion muestra un menu para configurar mediante funciones una de las plantillas del participante

void configurar_plantillas(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                           equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                           plantillas **estructura_plantillas){

    //Plantilla será la plantilla deseada a configurar y opcion la opcion elegida para decidir a que función llamar

    int opcion, i, j = 1 , plantilla;

    int v[3]; //Un vector donde guardaremos las id de las plantillas del participante
              //Tamaño 3 porque es el máximo de plantillas que puede tener un participante
              //Este dato está en fichero configuracion (max_futbolistas_plantilla)

    //Mostramos al participante sus plantillas para que pueda tener la información necesaria para elegir

    printf("\nA continuacion, mostraremos tus plantillas actuales.\n");

    for(i = 0 ; i < (*estructura_config).tam_plantillas ; i++){        //Mostramos las plantillas

        //Comprobamos que se impriman las plantillas del usuario (no uso funcion mostrar_plantillas) porque esa muestra
        //Todas las plantillas de todos los participantes

        if(*id == (*estructura_plantillas)[i].usuario_id){

            printf("\n%i, %s, presupuesto: %i, puntuacion: %i", (*estructura_plantillas)[i].plantilla_id,
                   (*estructura_plantillas)[i].nombre_plantilla,(*estructura_plantillas)[i].presupuesto_disp,
                   (*estructura_plantillas)[i].puntuacion_acum);

            v[i] = (*estructura_plantillas)[i].plantilla_id; //Guardamos las ids
        }
    }

    printf("\nSelecciona una de ellas para configurarla:\n\n");
    scanf("%i",&plantilla);

    //Verificamos si la id que ha metido el participante es de unas de sus plantillas
    // En el momento que se encuentre coincidencia ( j = 0) ya no hace falta que siga buscando mas
    //Por eso la condición del bucle tambien es mientras j == 1

    for(i = 0 ; i < (*estructura_config).tam_plantillas && j == 1 ; i++){

        if(v[i] == (*estructura_plantillas)[i].plantilla_id){

            // J empieza valiendo 1, si no se encuentra coincidencia seguirá valiendo 1 al final del bucle for

            j = 0;
        }
    }

    //Si no has introducido una id tuya vuelta al menú

    if ( j == 1){

        printf("\nNo has introducido una id de una de tus plantillas\n");
        menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,estructura_usuarios,
                           estructura_futbolistas,estructura_plantillas);

    }

    printf("\n\n---------MENU CONFIGURAR-PLANTILLA---------\n\n");

    printf("1.- Lista de jugadores en plantilla\n");
    printf("2.- Lista de jugadores disponibles\n");
    printf("3.- Añadir jugador a plantilla\n");
    printf("4.- Eliminar jugador de plantilla\n");
    printf("5.- Volver\n");

    printf("\nSeleccione una opcion: ");
    scanf("%i", &opcion);

    //Participante elige una de las opciones:

    do {
        switch(opcion){

            case 1:     listar_jugadores_plantillas(&plantilla,estructura_jugadores_plantillas,estructura_futbolistas,
                                                    estructura_config);
                        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                                      estructura_usuarios, estructura_futbolistas,estructura_plantillas);
                break;

            case 2:     listar_jugadores_disponibles(id,estructura_config,estructura_jugadores_plantillas,
                                                     estructura_equipos,estructura_usuarios,estructura_futbolistas,
                                                     estructura_plantillas);
                        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                                      estructura_usuarios, estructura_futbolistas,estructura_plantillas);
                break;

            case 3:     //Antes de llamar a la funcion añadir_futbolista ,comprobamos unos requisitos
                        //Vemos si la plantilla ya tiene 11 futbolistas
                        //En ese caso vuelve al menu otra vez

                        for(i = 0 ; i < (*estructura_config).tam_jugadores_plantillas ; i++){

                            if(plantilla == (*estructura_jugadores_plantillas)[i].plantilla_id){

                                //Con j controlo el numero de futbolistas de esa plantilla

                                j++;

                            }
                        }

                        //Comparo si ya hay 11 futbolistas, si no, llamo funcion anadir_futbolista

                        if(j == (*estructura_config).max_futbolistas_plantilla){

                            printf("\nLa plantilla seleccionada ya tiene 11 futbolistas,"
                                   " si deseas anadir otro, primero elimina uno\n\n");

                            //Volvemos al menu configurar_plantillas

                            configurar_plantillas(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                                  estructura_usuarios,estructura_futbolistas,estructura_plantillas);

                        }

                            //Si se cumplen los requisitos, llamamos a la función

                        else{

                             anadir_jugador_plantillas( id,&plantilla,estructura_config,estructura_jugadores_plantillas,
                                    estructura_equipos,estructura_usuarios,estructura_futbolistas,estructura_plantillas);

                            configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas,
                                                  estructura_equipos,estructura_usuarios, estructura_futbolistas,
                                                  estructura_plantillas);
                        }

                break;

            case 4:     eliminar_jugador_plantillas(&plantilla,&id,estructura_jugadores_plantillas,estructura_futbolistas,
                                                    estructura_plantillas, estructura_config,estructura_equipos,estructura_usuarios);

                        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                                      estructura_usuarios, estructura_futbolistas,estructura_plantillas);
                break;

            case 5:     menu_participantes(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                           estructura_usuarios,estructura_futbolistas,estructura_plantillas);
                break;

            default:    printf("\n\nIntroduce una opcion valida por favor\n\n");

                break;
        }
    }while(opcion > 0 && opcion < 6);       //Si la opcion no es valida sigue preguntando



}

//Cabecera: void listar_jugadores_disponibles(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
//                                  equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
//                                  plantillas **estructura_plantillas);
//Precondición: La función recibe los vectores de estructuras para futbolistas, jugadores_plantillas, y configuracion
//Postcondición: La funcion muestra al participante los futbolistas que no están asignados a ninguna plantilla

void listar_jugadores_disponibles(int *id, configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                                  equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                                  plantillas **estructura_plantillas){

    //Aux1 será una variable que ayudará a saber si un futbolista pertenece o no a una plantilla
    //Aux2 ayudará pasa saber si no hay ningun futbolista disponible

    printf("\nLos futbolistas disponibles que puedes anadir a tus plantilla son:\n");

    int i, j, aux1,aux2 = 0;

    //Recorremos la estructura jugadores_plantilla ya que aquí están guardados todos los futbolistas
    //que están en una plantilla , los que estén disponibles se mostrarán por pantalla

    for(i = 0 ; i < (*estructura_config).tam_futbolistas ; i++){

        aux1 = 1;

        for(j = 0 ; j < (*estructura_config).tam_jugadores_plantillas && aux1 == 1 ; j++){

            if((*estructura_futbolistas)[i].futbolista_id == (*estructura_jugadores_plantillas)[j].jugador_platilla_id){

                aux1 = 0;
                aux2 = 1;       //Como encuentra un futbolista disponible ya es imposible que no hay ninguno disponible
                                //Por lo tanto no se cumplirá despues el bucle if para mostrar que no hay ningun futbolista
                                //disponible
            }
        }

        if(aux1 == 1){

            //Los mostramos por pantalla

            printf("%i , %i , %s , %i , %i\n",
                   (*estructura_futbolistas)[i-1].futbolista_id,(*estructura_futbolistas)[i-1].equipo_id,
                   (*estructura_futbolistas)[i-1].nombre_futbolista,(*estructura_futbolistas)[i-1].futbolista_precio,
                   (*estructura_futbolistas)[i-1].valoracion);
        }
    }

    //Si no hay futbolistas disponibles vuelve al menu configuración

    if(aux2 == 0){

        printf("\nNo hay futbolistas disponibles en este momento.\n");
        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                              estructura_usuarios, estructura_futbolistas,estructura_plantillas);

    }

}

//Cabecera: void ranking(plantillas **estructura_plantillas, configuracion *estructura_config);
//Precondición: La función recibe los vectores de estructura plantillas y configuración
//Postcondición: La función muestra al usuario una lista ordenada actual de las plantillas con mayor puntuación

void ranking(plantillas **estructura_plantillas, configuracion *estructura_config) {

    //Aux ayudará a llevar a cabo el algoritmo de la burbuja para reordenar el vector ranking

    int i, j, aux;

    int ranking[(*estructura_config).tam_plantillas];    //PASAMOS LA ESTRUCTURA A UN VECTOR RANKING PARA PODER ASI ORDENARLOS

    for (i = 0; i < (*estructura_config).tam_plantillas ; i++) {

        ranking[i] = (*estructura_plantillas)[i].puntuacion_acum;
    }

    //AHORA HACEMOS UN ALGORITMO DE ORDENACION SIMPLE, CON AYUDA DE UN AUX COMPARAMOS SI EL ELEMENTO ACTUAL

    for (i = 0 ; i < (*estructura_config).tam_plantillas ; i++) {

        for (j = 0 ; j < (*estructura_config).tam_plantillas ; j++) {


            if (ranking[j] > ranking[j + 1]) {    //ES MAYOR QUE EL SIGUIENTE. SI LO ES, SE INTERCAMBIAN.

            aux = ranking[j + 1];

            ranking[j + 1] = ranking[j];

            ranking[j] = aux;

             }
         }
    }

    //MUESTRA EL RANKING

    for(i = 0 ; i < (*estructura_config).tam_plantillas ; i++){

        printf("%i , %s => %i PUNTOS\n", (*estructura_plantillas)[i].plantilla_id,
               (*estructura_plantillas)[i].nombre_plantilla, ranking[i]);

    }
}

//Cabecera: void eliminar_plantillas(int *id,plantillas **estructura_plantillas,
//                                   jugadores_plantillas **estructura_jugadores_plantillas,
//                                   configuracion *estructura_config);
//Precondición: La función recibe el id del participante y los vectores de estructura de
//              plantillas, jugadores_plantillas y configuración
//Postcondición: La función pide una de las plantillas del participante a eliminar, la borra y
//               reordena el vector dinámico de estructura plantillas restandole un espacio


void eliminar_plantillas(int *id, plantillas **estructura_plantillas, jugadores_plantillas **estructura_jugadores_plantillas,
                         configuracion *estructura_config){

    //Plantilla

    int i, plantilla, v[4];
    char aux;

    printf("\nSeleccione el id de su plantilla que desea eliminar , las cuales son:");

    for(i = 0 ; i < (*estructura_config).tam_plantillas ; i++){        //Mostramos las plantillas

        //Comprobamos que se impriman las plantillas del usuario (no uso funcion mostrar_plantillas) porque esa muestra
        //Todas las plantillas pero el participante solo puede borrar las suyas

        if(*id == (*estructura_plantillas)[i].usuario_id){

        printf("\n%i, %s, presupuesto: %i, puntuacion: %i", (*estructura_plantillas)[i].plantilla_id,
               (*estructura_plantillas)[i].nombre_plantilla,(*estructura_plantillas)[i].presupuesto_disp,
               (*estructura_plantillas)[i].puntuacion_acum);
        }
    }

    printf("\nId plantilla a eliminar:");
    scanf("%i",&plantilla);

    //Para eliminar la plantilla seleccionada, creamos un vector auxiliar para los datos de formato entero de plantillas
    //y una variable auxiliar tipo string llamada aux para guardar el plantilla_nombre
    //Con estos auxiliares guardamos los datos de la plantilla para intercambair su posicion en estructura_plantillas
    //con la ultima plantilla, así al hacer el realloc eliminamos la plantilla seleccionada

    for (i = 0 ; i < (*estructura_config).tam_plantillas ; i++){

        if(plantilla == (*estructura_plantillas)[i].plantilla_id){     //Para localizar la plantilla introducida

            v[0] = (*estructura_plantillas)[i].usuario_id;
            v[1] = (*estructura_plantillas)[i].plantilla_id;
            v[2] = (*estructura_plantillas)[i].presupuesto_disp;
            v[3] = (*estructura_plantillas)[i].puntuacion_acum;
            strcpy(&aux,(*estructura_plantillas)[i].nombre_plantilla);

            (*estructura_plantillas)[i].usuario_id = (*estructura_plantillas)[(*estructura_config).tam_plantillas].usuario_id;
            (*estructura_plantillas)[i].plantilla_id = (*estructura_plantillas)[(*estructura_config).tam_plantillas].plantilla_id;
            (*estructura_plantillas)[i].presupuesto_disp = (*estructura_plantillas)[(*estructura_config).tam_plantillas].presupuesto_disp;
            (*estructura_plantillas)[i].puntuacion_acum = (*estructura_plantillas)[(*estructura_config).tam_plantillas].puntuacion_acum;
            strcpy((*estructura_plantillas)[i].nombre_plantilla, (*estructura_plantillas)[(*estructura_config).tam_plantillas].nombre_plantilla);

            (*estructura_plantillas)[(*estructura_config).tam_plantillas].usuario_id = v[0];
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].plantilla_id = v[1];
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].presupuesto_disp = v[2];
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].puntuacion_acum = v[3];
            strcpy((*estructura_plantillas)[(*estructura_config).tam_plantillas].nombre_plantilla , &aux);
        }
    }

    //Redimensionamos el vector estructura_plantillas, al eliminar una plantilla, le quitamos un elemento

    (*estructura_config).tam_plantillas --;

    //Si la estructura_plantillas no tiene ninguna plantilla no le hacemos el realloc para guardarle tamaño 0
    //A si que la definimos como nula, si el tamaño no es 0 al restarle 1 entonces si hacemos realloc

    if ((*estructura_config).tam_plantillas == 0){

        *estructura_plantillas = NULL;

    }

    else {

        *estructura_plantillas = (plantillas *) realloc((*estructura_plantillas),
                                                        ((*estructura_config).tam_plantillas) * sizeof(plantillas));
        if (estructura_plantillas == NULL) {

            printf("\nFallo de reserva de memoria");
            exit(EXIT_FAILURE);
        }
    }

    //Ahora eliminamos todos los futbolistas de jugadores_plantillas con la id de la plantilla eliminada
    //El uso del do while se debe a que
    //si cambio un futbolista de la plantilla seleccionada por el ultimo futbolista de jugadores_plantillas para
    //hacer el realloc es posible que el ultimo futbolista tambien pertenezca a esa plantilla

    for(i = 0 ; i < (*estructura_config).tam_jugadores_plantillas ; i++){

        //Para encontar a aquellos futbolistas que pertenecen a la plantilla eliminada

        if(plantilla == (*estructura_jugadores_plantillas)[i].plantilla_id) {

            do {
                //Algoritmo de la burbuja, haciendo así el cambio usando las variables auxiliares creadas

                v[0] = (*estructura_jugadores_plantillas)[i].jugador_platilla_id;
                v[1] = (*estructura_jugadores_plantillas)[i].plantilla_id;

                (*estructura_jugadores_plantillas)[i].jugador_platilla_id =
                        (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id;
                (*estructura_jugadores_plantillas)[i].plantilla_id =
                        (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].plantilla_id;

                (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id = v[0];
                (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].plantilla_id = v[1];

                (*estructura_config).tam_jugadores_plantillas--; // El tamaño de jugadores plantillas se reduce en 1

                //Si la estructura_jugadores_plantillas no tiene ningun jugador no hacemos realloc para guardar tamaño 0
                //A si que la definimos como nula, si el tamaño no es 0 al restarle 1 entonces si hacemos realloc

                if ((*estructura_config).tam_jugadores_plantillas == 0){

                    *estructura_jugadores_plantillas = NULL;

                }
                else {

                    *estructura_jugadores_plantillas = (jugadores_plantillas *)
                            realloc((*estructura_jugadores_plantillas),((*estructura_config).tam_jugadores_plantillas)
                            * sizeof(jugadores_plantillas));

                    if (estructura_jugadores_plantillas == NULL) {

                        printf("\nFallo de reserva de memoria");
                        exit(EXIT_FAILURE);
                    }
                }

            } while (plantilla == (*estructura_jugadores_plantillas)[i].plantilla_id);
        }
    }
}

//Cabecera: void listar_jugadores_plantillas(int *plantilla, jugadores_plantillas **estructura_jugadores_plantillas,
//                                           futbolistas **estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe la plantilla a listar sus jugadores junto a los vectores dinamicos de estructura
//                jugadores_plantillas , futbolistas y configuración
//Postcondición: La funcion muestra los futbolistas de la plantilla que recibe la función

void listar_jugadores_plantillas(int *plantilla, jugadores_plantillas **estructura_jugadores_plantillas,
                                futbolistas **estructura_futbolistas, configuracion *estructura_config){

    int i, j, aux = 0;      //Aux me servirá para controlar si no ha encontrado ningun jugador

    printf("\n\nLos futbolistas que pertenecen a la plantilla %i son:",*plantilla);

    for(i = 0 ; i < (*estructura_config).tam_jugadores_plantillas ; i++){

        //Identifico a los futbolistas de esa plantilla ya que plantilla_id es el mismo dato en jugadores_plantillas
        //Y en plantillas

        if (*plantilla == (*estructura_jugadores_plantillas)[i].plantilla_id){

            aux = 1;    //Si encuentra a un jugador al menos toma valor 1 y no imprime que no se ha encontrado futbolistas

            //Busco al futbolista mediante su campo futbolista_id para imprimir sus datos

            for(j = 0 ; j < (*estructura_config).tam_futbolistas ; j++){

                //Identifico al futbolista

                if((*estructura_jugadores_plantillas)[i].jugador_platilla_id == (*estructura_futbolistas)[j].futbolista_id){

                    //Muestro sus datos

                    printf("\n%i , equipo:%i, %s, precio:%i, valoracion:%i\n",(*estructura_futbolistas)[j].futbolista_id,
                           (*estructura_futbolistas)[j].equipo_id,(*estructura_futbolistas)[j].nombre_futbolista,
                           (*estructura_futbolistas)[j].futbolista_precio,(*estructura_futbolistas)[j].valoracion);

                }
            }
        }
    }

    if (aux == 0){

        printf("\nNo hay futbolistas en esa plantilla\n");

    }
}

//Cabecera: void eliminar_jugador_plantillas(int *plantilla,*int id jugadores_plantillas **estructura_jugadores_plantillas,
//                                           futbolistas **estructura_futbolistas,plantillas **estructura_plantillas,
//                                           configuracion *estructura_config,equipos **estructura_equipos,
//                                           usuarios **estructura_usuarios);
//Precondición: La función recibe la plantilla a configurar, junto con los vectores dinámicos de estructura
//                jugadores_plantillas, futbolistas, plantillas y configuracion
//Postcondición: La funcion muestra los futbolistas de la plantilla que recibe,
// y posteriomente borra el futbolista seleccionado por el participante


void eliminar_jugador_plantillas(int *plantilla,int *id, jugadores_plantillas **estructura_jugadores_plantillas,
                                futbolistas **estructura_futbolistas,plantillas **estructura_plantillas,
                                 configuracion *estructura_config,equipos **estructura_equipos,
                                 usuarios **estructura_usuarios) {

    int i, j = -1 , opcion, aux,aux1, aux2;

    //Tenemos que mostrar los futbolistas de la plantilla para que pueda elegir el ID del futbolista que quiere borrar

    for(i = 0 ; i < (*estructura_config).tam_jugadores_plantillas ; i++){

        //Identifico a los futbolistas de esa plantilla ya que plantilla_id es el mismo dato en jugadores_plantillas
        //Y en plantillas

        if (*plantilla == (*estructura_jugadores_plantillas)[i].plantilla_id){

            aux = 1;    //Si encuentra a un jugador al menos toma valor 1 y no imprime que no se ha encontrado futbolistas

            //Busco al futbolista mediante su campo futbolista_id para imprimir sus datos

            for(j = 0 ; j < (*estructura_config).tam_futbolistas ; j++){

                //Identifico al futbolista

                if((*estructura_jugadores_plantillas)[i].jugador_platilla_id == (*estructura_futbolistas)[j].futbolista_id){

                    //Muestro sus datos

                    printf("\n%i , equipo:%i, %s, precio:%i, valoracion:%i\n",(*estructura_futbolistas)[j].futbolista_id,
                           (*estructura_futbolistas)[j].equipo_id,(*estructura_futbolistas)[j].nombre_futbolista,
                           (*estructura_futbolistas)[j].futbolista_precio,(*estructura_futbolistas)[j].valoracion);

                }
            }
        }
    }
    //Si no hay futbolistas en la plantilla vuelve al menú configuració

    if (aux == 0) {

        printf("\nNo hay futbolistas en esa plantilla\n");

        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas, estructura_equipos,
                              estructura_usuarios, estructura_futbolistas,estructura_plantillas);

    }

    printf("\n\nAhora elija la ID del jugador a eliminar:");
    scanf("%i",&opcion);

    //Busco al futbolista para poder hacer la suma de presupuesto de la plantilla

    for(i = 0 ; i < (*estructura_config).tam_futbolistas && j == -1 ; i++){

        if(opcion == (*estructura_futbolistas)[i].futbolista_id){

            //En j guardo la ID de ese futbolista concreto en la estructura para poder referirme a el
            //Uso j pues no la voy a volver a usar en la funcion

            j = i;

        }
    }

    //Le sumo al presupuesto de la plantilla seleccinada el precio del futbolista eliminado

    (*estructura_plantillas)[*plantilla].presupuesto_disp =
            (*estructura_plantillas)[*plantilla].presupuesto_disp + (*estructura_futbolistas)[j].futbolista_precio;

    //Para hacer el realloc restando 1 espacio a estructura_jugadores_plantillas , intercambio el futbolista sellecionado
    //Por el ultimo, así al hacer el realloc lo borro , aux1 y aux2 me ayudaran a hacer el cambio ya que
    //Jugadores_plantillas tiene 2 parametros

    //Comprobamos si el futbolista a borrar es el ultimo de jugadores_futbolistas, para ahorrar el proceso comentado
    //anteriormente, si no, se realiza el algoritmo de la burbuja

    if (opcion == (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id){

        //Reducimos en 1 el tamaño de jugadores plantilla
        (*estructura_config).tam_jugadores_plantillas--;

        //Si solo habia 1 futbolista en jugadores_plantillas entonces al haber ahora 0 al restarle 1
        //No haríamos en ese caso realloc para tamaño 0, declaramos estrcutura_jugadores_plantillas como nula

        if ((*estructura_config).tam_jugadores_plantillas == 0){

            *estructura_jugadores_plantillas = NULL;

        }

        //Si no se da el caso especial comentado entonces se hace el realloc como siempre

        else {

            *estructura_jugadores_plantillas = (jugadores_plantillas *)
                    realloc((*estructura_jugadores_plantillas),
                            ((*estructura_config).tam_jugadores_plantillas) * sizeof(jugadores_plantillas));

            if (estructura_jugadores_plantillas == NULL) {

                printf("\nFallo de reserva de memoria");
                exit(EXIT_FAILURE);
            }
        }
    }

    else {

        for (i = 0; i < (*estructura_config).tam_jugadores_plantillas; i++) {

            if (opcion == (*estructura_jugadores_plantillas)[i].jugador_platilla_id) {

                //Los auxiliares toman el valor de los datos del futbolista a borrar

                aux1 = (*estructura_jugadores_plantillas)[opcion].jugador_platilla_id;
                aux2 = (*estructura_jugadores_plantillas)[opcion].plantilla_id;

                //Los datos de la posición del futbolista a borrar son cambiados por los del ultimo

                (*estructura_jugadores_plantillas)[opcion].jugador_platilla_id =
                        (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id;
                (*estructura_jugadores_plantillas)[opcion].plantilla_id =
                        (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].plantilla_id;

                //Los datos del ultimo futbolistas son cambiados por los guardados en aux1 y aux2

                (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id = aux1;
                (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].plantilla_id = aux2;

                //Una vez cambiados los valores, procedo a hacer el realloc

                //Reducimos en 1 el tamaño de jugadores plantilla
                (*estructura_config).tam_jugadores_plantillas--;

                //Si solo habia 1 futbolista en jugadores_plantillas entonces al haber ahora 0 al restarle 1
                //No haríamos en ese caso realloc para tamaño 0, declaramos estrcutura_jugadores_plantillas como nula

                if ((*estructura_config).tam_jugadores_plantillas == 0){

                    *estructura_jugadores_plantillas = NULL;

                }

                    //Si no se da el caso especial comentado entonces se hace el realloc como siempre

                else {

                    *estructura_jugadores_plantillas = (jugadores_plantillas *)
                            realloc((*estructura_jugadores_plantillas),
                                    ((*estructura_config).tam_jugadores_plantillas) * sizeof(jugadores_plantillas));

                    if (estructura_jugadores_plantillas == NULL) {

                        printf("\nFallo de reserva de memoria");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }
}

//Cabecera: void anadir_jugador_plantillas(int *id,int *plantilla, configuracion *estructura_config,
//                                         jugadores_plantillas **estructura_jugadores_plantillas,
//                                         equipos **estructura_equipos, usuarios **estructura_usuarios,
//                                         futbolistas **estructura_futbolistas,plantillas **estructura_plantillas);
//Precondición: La funcion recibe la id del participante, la plantilla a la cual añadir futbolistas, y todos
//              los vectores dinámicos de estructuras.
//Postcondición: La funcion lista los futbolista que no tienen plantilla , de los cuales el participante elige uno
//               que será añadido a su plantilla seleccionada que recibe la función

void anadir_jugador_plantillas(int *id,int *plantilla, configuracion *estructura_config,
                               jugadores_plantillas **estructura_jugadores_plantillas,equipos **estructura_equipos,
                               usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                                plantillas **estructura_plantillas){

    int i,j, aux1 = -1, aux2,futbolista;

    //Llamo a la funcion que lista los jugadores disponibles sin plantilla anteriormente asignada

    listar_jugadores_disponibles(id,estructura_config,estructura_jugadores_plantillas,estructura_equipos,
                                 estructura_usuarios,estructura_futbolistas,estructura_plantillas);

    printf("\nIntroduce el ID del futbolista que quiera anadir a la plantilla:");
    scanf("%i",&futbolista);

    //Identifico al futbolista

    for(i = 0 ; i < (*estructura_config).tam_futbolistas ; i++){

        if(futbolista == (*estructura_futbolistas)[i].futbolista_id){

            for (j = 0 ; j < (*estructura_config).tam_jugadores_plantillas ; j++){

                if((*estructura_futbolistas)[i].futbolista_id == (*estructura_jugadores_plantillas)[j].jugador_platilla_id){

                   //Si el futbolista introducido ya está en una plantilla

                   aux1 = -1;

                }
                else{

                    //Aux1 toma el indicador del futbolista para poder referirme a el mas adelante

                    aux1 = i;
                }

            }
        }
    }

    if( aux1 == -1){

        printf("\nHas introducido una id de futbolista no valida");
        anadir_jugador_plantillas( id,&plantilla,estructura_config,estructura_jugadores_plantillas,
                                   estructura_equipos,estructura_usuarios,estructura_futbolistas,estructura_plantillas);

    }

    for(i = 0 ; i < (*estructura_config).tam_plantillas ; i++){

        if((*estructura_plantillas)[i].plantilla_id == *plantilla){

            //Aux2 toma el indicador de la plantilla para poder referirme a el mas adelante

            aux2 = i;
        }

    }
    //Comprobamos si la plantilla dispone de suficiente presupuesto para comprar al jugador

    if((*estructura_futbolistas)[aux1].futbolista_precio > (*estructura_plantillas)[aux2].presupuesto_disp){

        printf("\nEl precio del futbolista que has seleccionado es superior al presupuesto de tu plantilla\n\n");

        configurar_plantillas(id, estructura_config, estructura_jugadores_plantillas,
                 estructura_equipos, estructura_usuarios, estructura_futbolistas, estructura_plantillas);

    }

    else{

        printf("\nEl futbolista seleccionado es valido\n");

        //Incrementamos en 1 el tamaño de jugadores_plantillas

        (*estructura_config).tam_jugadores_plantillas++;

        //Con realloc aumentamos en 1 el tamaño de estructura_jugadores_plantillas

        *estructura_jugadores_plantillas = (jugadores_plantillas *)
                realloc((*estructura_jugadores_plantillas),((*estructura_config).tam_jugadores_plantillas)*sizeof(jugadores_plantillas));

        if(estructura_jugadores_plantillas==NULL){

            printf("\nFallo de reserva de memoria");
            exit(EXIT_FAILURE);
        }

        //Relleno los datos del nuevo espacio reservado con los datos del futbolista seleccionado
        //Los cuales estan guardados en aux1 y aux2

        (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id = aux1+1;
        (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].plantilla_id = aux2+1;
    }

}



#endif //PROYECTO_PARTICIPANTES_H
