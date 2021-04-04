#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUCTURAS

typedef struct{

    int presupuesto_defecto;               //Presupuesto de plantilla por defecto (comienza en 100)
    int max_futbolistas_plantilla;         //Maximo de futbolistas por plantilla(comienza 11)
    int max_plantillas_participante;       //Maximo de plantillas por participante(comienza 3)
    int tam_equipos;                       //Tamaño actual de la estructura_equipos
    int tam_futbolistas;                   //Tamaño actual de la estructura_futbolistas
    int tam_jugadores_plantillas;          //Tamaño actual de la estructura_jugadores_plantillas
    int tam_plantillas;                    //Tamaño actual de la estructura_plantillas
    int tam_usuarios;                      //Tamaño actual de la estructura_usuarios

}configuracion;


typedef struct{

    int usuario_id;
    char nombre_usuario[21];
    char usuario_perfil[15];
    char usuario_nick[6];
    char usuario_password[9];

}usuarios;


typedef struct{

    int usuario_id;
    int plantilla_id;
    char nombre_plantilla[31];
    int presupuesto_disp;
    int puntuacion_acum;

}plantillas;


typedef struct{

    int jugador_platilla_id;
    int plantilla_id;

}jugadores_plantillas;


typedef struct{

    int futbolista_id;
    int equipo_id;
    char nombre_futbolista[21];
    int futbolista_precio;
    int valoracion;

}futbolistas;


typedef struct{

    int equipo_id;
    char nombre_equipo[21];

}equipos;

//DEFINICIONES_FUNCIONES


void volcar_configuracion(configuracion *estructura_config);
void escribir_configuracion(configuracion *estructura_config);
void mostrar_configuracion(configuracion *estructura_config);

void volcar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config);
void escribir_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config);
void mostrar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config);

void volcar_equipos(equipos **estructura_equipos, configuracion *estructura_config);
void escribir_equipos(equipos **estructura_equipos, configuracion *estructura_config);
void mostrar_equipos(equipos **estructura_equipos, configuracion *estructura_config);

void volcar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config);
void escribir_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config);
void mostrar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config);

void volcar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config);
void escribir_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config);
void mostrar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config);

void volcar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas, configuracion *estructura_config);
void escribir_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas, configuracion *estructura_config);
void mostrar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas, configuracion *estructura_config);

int salir_programa(configuracion *estructura_config,futbolistas **estructura_futbolistas,equipos **estructura_equipos,
                   usuarios **estructura_usuarios,plantillas **estructura_plantillas,
                   jugadores_plantillas **estructura_jugadores_plantillas);


//FUNCIONES

//Cabecera: void volcar_configuracion(configuracion *estructura_config);
//Precondición: La función recibe el vector dinamico de estructura_config
//Postcondición: Se volca toda la informacion del fichero configuracion.txt en estructura_config

void volcar_configuracion(configuracion *estructura_config){

    //Apertura del fichero

    char c[5];
    int i;

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");

    if(f_configuracion==NULL){
        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);}

    //Vuelcan datos del fichero, cada dato ocupa una linea del fichero, por lo tanto guardamos después de encontrar \n

   

    fclose(f_configuracion);
}
//Cabecera: void volcar_futbolistas(futbolistas *estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico de estructura_futbolistas y estructura_config
//Postcondición: Vuelca toda la información del fichero futbolistas.txt en estructura_futbolistas

void volcar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config){


    int i,tam = 1;   //Tam contará el numero de lineas del fichero futbolista, empieza en 1 porque empieza en una linea
    char c;

    //Apertura del fichero

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "r");

    if(f_futbolistas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    //Contamos el numero de lineas del fichero futbolistas

    do {

        c = fgetc(f_futbolistas);

        if(c == '\n'){

            tam ++;

        }
    } while(c!=EOF);

     estructura_config->tam_futbolistas = tam/5;

    //Dividimos entre 5 puesto que en el fichero futbolistas escribimos cada 1 de sus campos por linea
    //Es decir cada futbolista son 5 lineas del fichero futbolistas
    //Este resultado, que será el tamaño de estrura_futbolistas
    //Se guarda en su respectiva variable en estructura_config


    //Reservamos la memoria dinámica

    *estructura_futbolistas = (futbolistas*)calloc(estructura_config->tam_futbolistas,sizeof(int));
    if(estructura_futbolistas==NULL){printf("Fallo de reserva de memoria\n");}


    //Rellena estructura_futbolistas

    for (i = 0 ; i < estructura_config->tam_futbolistas ; i++){

        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->futbolista_id);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->equipo_id);
        fscanf(f_futbolistas, "%s", estructura_futbolistas[i]->nombre_futbolista);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->futbolista_precio);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->valoracion);
    }

    fclose(f_futbolistas);
}

//Cabecera: void volcar_equipos(equipos *estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y estructura_config
//Postcondición: Se vuelca toda la información del fichero equipos.txt en estructura_equipos

void volcar_equipos(equipos **estructura_equipos, configuracion *estructura_config){

    int i,tam = 1;
    char c;

    //Apertura_fichero

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt", "r");

    if(f_equipos==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    //Contamos el numero de lineas del fichero equipos

    do {

        c = fgetc(f_equipos);

        if(c == '\n'){

            tam++;
        }

    } while(c!=EOF);

    estructura_config->tam_equipos = tam/2;

    //Dividimos entre 2 puesto que en el fichero equipos cada dato ocupa una linea
    //Es decir, 2 lineas por usuario
    //El resultado será el tamaño de estructura_usuarios
    // Que se guardará en su respectiva variable en estructura_config

    //Reserva memoria al vector dinamico

    *estructura_equipos = (equipos*)calloc(estructura_config->tam_equipos,sizeof(int));
    if(estructura_equipos==NULL){printf("Fallo de reserva de memoria\n");}


    //Rellena la estructura_equipos

    for (i=0; i<estructura_config->tam_equipos; i++){

        fscanf(f_equipos, "%i", &estructura_equipos[i]->equipo_id);
        fscanf(f_equipos, "%s", estructura_equipos[i]->nombre_equipo);
    }


    fclose(f_equipos);
}

void volcar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config){

    int i,tam = 1;
    char c;

    //Apertura del fichero

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "r");

    if(f_usuarios==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    //Contamos el numero de lineas del fichero usuarios

    do {

        c = fgetc(f_usuarios);

        if(c == '\n'){

            tam++;

        }
    }while(c!=EOF);

    estructura_config->tam_usuarios = tam/5;

    //Dividimos el numero de lineas entre 5 ya que en el fichero usuario cada dato ocupa una linea
    //Es decir, 5 lineas por usuario
    //El resultado será el tamaño de estructura_usuarios
    //El cual se guardará en su respectiva variable en estructura_config

    //Reserva memoria en el vector dinamico

    *estructura_usuarios =(usuarios*)calloc(estructura_config->tam_usuarios,sizeof(usuarios));
    if(estructura_usuarios==NULL){printf("Fallo de reserva de memoria\n");}

    //Rellena la estructura_usuarios

    for (i = 0 ; i < estructura_config->tam_usuarios ; i++){

        fscanf(f_usuarios,"%i",&estructura_usuarios[i]->usuario_id);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->nombre_usuario);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->usuario_perfil);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->usuario_nick);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->usuario_password);
    }
    fclose(f_usuarios);
}

//Cabecera: void volcar_plantillas(plantillas *estructura_plantillas, configuracion *estructura_config);
//Precondicion: La función recibe el vector dinámico de estructura_plantillas y estructura_config
//Postcondición: Es volcada la informacion del fichero plantillas.txt en estructura_plantillas

void volcar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config){

    int  i , tam = 1;
    char c;

    FILE *f_plantillas;
    f_plantillas = fopen("files/usuarios.txt", "r");

    if(f_plantillas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    //Contamos el numero de lineas del fichero usuarios mediante tam

    do {

        c = fgetc(f_plantillas);

        if(c == '\n'){

            tam++;

        }
    }while(c!=EOF);

    estructura_config->tam_plantillas = tam / 5;

    //Dividimos el numero de lineas (tam) entre 5, ya que la estructura plantillas tiene 5 campos
    //Como el fichero está hecho de manera que cada campo ocupa una linea,
    //El resultado de la división será el número de plantillas

    *estructura_plantillas =(plantillas*)calloc(estructura_config->tam_plantillas,sizeof(int));
    if(estructura_plantillas==NULL){printf("Fallo de reserva de memoria\n");}

    //Volcamos los datos

    for (i = 0 ; i < estructura_config->tam_plantillas ; i++){

        fscanf(f_plantillas,"%i", &estructura_plantillas[i]->usuario_id);
        fscanf(f_plantillas,"%i", &estructura_plantillas[i]->plantilla_id);
        fscanf(f_plantillas,"%s", estructura_plantillas[i]->nombre_plantilla);
        fscanf(f_plantillas,"%i", &estructura_plantillas[i]->presupuesto_disp);
        fscanf(f_plantillas,"%i", &estructura_plantillas[i]->puntuacion_acum);
    }

    fclose(f_plantillas);

}

//Cabecera: void volcar_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas,
//                                           configuracion *estructura_config);
//Precondicion: La función recibe el vector dinámico de estructura_jugadores_plantillas y estructura_config
//Postcondición: La funcion vuelca toda la informacion del fichero jugadores_plantillas.txt en estructura_jugadores_plantillas

void volcar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas , configuracion *estructura_config){

    int  i , tam = 1;
    char c;

    FILE *f_jugadores_plantillas;
    f_jugadores_plantillas = fopen("files/usuarios.txt", "r");

    if(f_jugadores_plantillas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    //Contamos el numero de lineas del fichero usuarios con tam

   do {

        c = fgetc(f_jugadores_plantillas);

        if(c == '\n'){

            tam++;

        }
    } while(c!=EOF);

    estructura_config->tam_jugadores_plantillas = tam / 2;

    //Divido el número de lineas(tam) entre 2 ya que la estructura jugadores_plantillas tiene 2 campos
    //Y dado que en el fichero cada campo ocupa 1 linea, el resultado de la división será el número de jugadores_plantillas

   *estructura_jugadores_plantillas =(jugadores_plantillas *)calloc(estructura_config->tam_jugadores_plantillas,sizeof(int));
    if(estructura_jugadores_plantillas==NULL){printf("Fallo de reserva de memoria\n");}

    //Se vuelcan los datos

    for (i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++){

        fscanf(f_jugadores_plantillas,"%i", &estructura_jugadores_plantillas[i]->plantilla_id);
        fscanf(f_jugadores_plantillas,"%i", &estructura_jugadores_plantillas[i]->jugador_platilla_id);
    }

    fclose(f_jugadores_plantillas);

}

//Cabecera: void escribir_configuracion(configuracion *estructura_config);
//Precondición: La función recibe la variable estructura_configuracion
//Postcondición: Se escriben en el fichero configuración.txt los datos de estructura_configuracion

void escribir_configuracion(configuracion *estructura_config){

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","w");

    if(f_configuracion==NULL){printf("Fallo de apertura de fichero\n");}

    //Escribir datos del vector estructura_configuracion en el fichero configuracion

    fprintf(f_configuracion,"%i",estructura_config->presupuesto_defecto);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->max_futbolistas_plantilla);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->max_plantillas_participante);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->tam_equipos);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->tam_futbolistas);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->tam_jugadores_plantillas);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->tam_plantillas);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config->tam_usuarios);
    fprintf(f_configuracion,"%s","\n");


    fclose(f_configuracion);
}

//Cabecera: void escribir_futbolistas(futbolistas *estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe la variable dinámica estructura_fitbolistas y estructura_configuracion
//Postcondición: Se escriben en el fichero futbolistas.txt los datos de estructura_futbolistas

void escribir_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config){

    int i ;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "w");

    if(f_futbolistas==NULL){printf("Fallo de apertura de fichero\n");}

    //Escribimos en el fichero futbolistas los datos de estructura_futbolistas

    for (i=0 ; i < estructura_config->tam_futbolistas ; i++){

        fprintf(f_futbolistas, "%i", estructura_futbolistas[i]->futbolista_id);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i]->equipo_id);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%s", estructura_futbolistas[i]->nombre_futbolista);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i]->futbolista_precio);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i]->valoracion);
        fprintf(f_futbolistas,"%s","\n");
    }

    fclose(f_futbolistas);

}

//Cabecera: void escribir_equipos(equipos *estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y la estructura_configuracion
//Postcondición: Se escriben en el fichero equipos.txt los datos de estructura_equipos

void escribir_equipos(equipos **estructura_equipos, configuracion *estructura_config){

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt","w");

    if(f_equipos==NULL){printf("Fallo de apertura de fichero\n");}


    //Escribimos los datos de la estructura_equipos en el fichero equipos

    for (i=0; i < estructura_config->tam_equipos ; i++){

        fprintf(f_equipos, "%i", estructura_equipos[i]->equipo_id);
        fprintf(f_equipos, "%s", "\n");
        fprintf(f_equipos, "%s", estructura_equipos[i]->nombre_equipo);
        fprintf(f_equipos, "%s", "\n");
    }

    fclose(f_equipos);

}

//Cabecera: void escribir_usuarios(usuarios *estructura_usuarios, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_usuarios y la estructura_configuracion
//Postcondición: Se escriben en el fichero usuarios.txt los datos de estructura_usuarios

void escribir_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config){

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "w");

    if(f_usuarios==NULL){printf("Fallo de apertura de fichero\n");}


    //Escribimos en el fichero usuarios los datos de su respectiva estructura

    for(i = 0 ; i < estructura_config->tam_usuarios ; i++){

        fprintf(f_usuarios,"%i",estructura_usuarios[i]->usuario_id);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i]->nombre_usuario);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i]->usuario_perfil);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i]->usuario_nick);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i]->usuario_password);
        fprintf(f_usuarios, "%s", "\n");

    }

    fclose(f_usuarios);

}

//Cabecera: void escribir_plantillas(plantillas *estructura_plantillas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_plantillas y la estructura_configuracion
//Postcondición: Se escriben en el fichero plantillas.txt los datos de estructura_plantillas

void escribir_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config) {

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_plantillas;
    f_plantillas = fopen("files/plantillas.txt", "w");

    if(f_plantillas==NULL){printf("Fallo de apertura de fichero\n");}

    //Escribimos en el fichero plantillas el vector dinamico estructura_plantillas

    for(i=0 ; i < estructura_config->tam_plantillas ; i++){

        fprintf(f_plantillas,"%i",estructura_plantillas[i]->usuario_id);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%i",estructura_plantillas[i]->plantilla_id);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%s",estructura_plantillas[i]->nombre_plantilla);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%i",estructura_plantillas[i]->presupuesto_disp);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%i",estructura_plantillas[i]->puntuacion_acum);
        fprintf(f_plantillas, "%s", "\n");
    }

        fclose(f_plantillas);

    }

//Cabecera: void escribir_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas,
//                                             configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_jugadores_plantillas y la estructura_configuracion
//Postcondición: Se escriben en el fichero jugadores_plantillas.txt los datos de estructura_jugadores_plantillas

    void escribir_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas,
                                       configuracion *estructura_config) {


        int i;

        //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

        FILE *f_jugadores_plantillas;
        f_jugadores_plantillas = fopen("files/jugadores_plantillas.txt", "w");

        if(f_jugadores_plantillas==NULL){printf("Fallo de apertura de fichero\n");}

        //Escribimos en el fichero jugadores_plantillas los datos del vector dinamico estrucutura_jugadores_plantillas

        for (i = 0; i < estructura_config->tam_jugadores_plantillas; i++) {

            fprintf(f_jugadores_plantillas, "%i", estructura_jugadores_plantillas[i]->jugador_platilla_id);
            fprintf(f_jugadores_plantillas, "%s", "\n");
            fprintf(f_jugadores_plantillas, "%i", estructura_jugadores_plantillas[i]->plantilla_id);
            fprintf(f_jugadores_plantillas, "%s", "\n");
        }
        fclose(f_jugadores_plantillas);

    }

//Cabecera: void mostrar_configuracion(configuracion *estructura_config);
//Precondición: La función recibe el vector estructura_config
//Postcondición: La función muestra los datos de estructura_config

    void mostrar_configuracion(configuracion *estructura_config) {

        printf("El presupuesto por defecto es: %i \n", estructura_config->presupuesto_defecto);
        printf("El numero maximo de futbolistas por plantilla es: %i \n", estructura_config->max_futbolistas_plantilla);
        printf("El numero maximo de plantillas por participantes: %i \n",
               estructura_config->max_plantillas_participante);
    }

//Cabecera: void mostrar_futbolistas(futbolistas *estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_futbolistas y la estructura_config
//Postcondición: La función muestra los datos de estructura_futbolistas

    void mostrar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config) {

        int i;
        for (i = 0; i < estructura_config->tam_futbolistas ; i++) {

            printf("%i,", estructura_futbolistas[i]->futbolista_id);
            printf("%i,", estructura_futbolistas[i]->equipo_id);
            printf("%s,", estructura_futbolistas[i]->nombre_futbolista);
            printf("%i,", estructura_futbolistas[i]->futbolista_precio);
            printf("%i\n", estructura_futbolistas[i]->valoracion);
        }
    }

//Cabecera: void mostrar_equipos(equipos *estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y la estructura_config
//Postcondición: La función muestra los datos de estructura_equipos

    void mostrar_equipos(equipos **estructura_equipos, configuracion *estructura_config) {

        int i;
        for (i = 0; i < estructura_config->tam_equipos ; i++) {

            printf("%i,", estructura_equipos[i]->equipo_id);
            printf("%s\n", estructura_equipos[i]->nombre_equipo);
        }
    }

//Cabecera: void mostrar_usuarios(usuarios *estructura_usuarios , configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_usuarios y la estructura_config
//Postcondición: La función muestra los datos de estructura_usuarios

    void mostrar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config) {

        int i;

        for (i = 0 ; i < estructura_config->tam_usuarios ; i++) {

            printf("%i,", estructura_usuarios[i]->usuario_id);
            printf("%s,", estructura_usuarios[i]->nombre_usuario);
            printf("%s,", estructura_usuarios[i]->usuario_perfil);
            printf("%s,", estructura_usuarios[i]->usuario_nick);
            printf("%s \n", estructura_usuarios[i]->usuario_password);

        }

    }

//Cabecera: void mostrar_plantillas(plantillas *estructura_plantillas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_plantillas y la estructura_config
//Postcondición: La función muestra los datos de estructura_plantillas

    void mostrar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config) {

        int i;

        for (i = 0 ; i < estructura_config->tam_plantillas ; i++) {

            printf("%i,", estructura_plantillas[i]->usuario_id);
            printf("%i,", estructura_plantillas[i]->plantilla_id);
            printf("%s,", estructura_plantillas[i]->nombre_plantilla);
            printf("%i,", estructura_plantillas[i]->presupuesto_disp);
            printf("%i \n", estructura_plantillas[i]->puntuacion_acum);

        }

    }

//Cabecera: void mostrar_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_jugadores_plantillas y la estructura_config
//Postcondición: La función muestra los datos de estructura_jugadores_plantillas

    void mostrar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas,configuracion *estructura_config) {

        int i;

        for (i = 0 ; i < estructura_config->tam_jugadores_plantillas ; i++) {

            printf("%i,", estructura_jugadores_plantillas[i]->jugador_platilla_id);
            printf("%i \n", estructura_jugadores_plantillas[i]->plantilla_id);
        }

    }

//Cabecera: int salir_programa(configuracion *estructura_config, futbolistas *estructura_futbolistas,
//                             equipos *estructura_equipos,usuarios *estructura_usuarios,
//                             plantillas *estructura_plantillas,jugadores_plantillas *estructura_jugadores_plantillas);
//Precondición: La funcion recibe todos los vectores dinamicos de estructura y estructura_config
//Postcondición: La función llama a todas las funciones para que escriban los datos modificados y añadidos durante el programa
//              , y acaba saliendo del programa

    int salir_programa(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                   usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                   jugadores_plantillas **estructura_jugadores_plantillas) {

        escribir_configuracion(estructura_config);
        escribir_futbolistas(estructura_futbolistas,estructura_config);
        escribir_equipos(estructura_equipos,estructura_config);
        escribir_usuarios(estructura_usuarios,estructura_config);
        escribir_plantillas(estructura_plantillas,estructura_config);
        escribir_jugadores_plantillas(estructura_jugadores_plantillas,estructura_config);

        //Liberamos la memoria dinamica

        free(estructura_futbolistas);
        free(estructura_equipos);
        free(estructura_usuarios);
        free(estructura_plantillas);
        free(estructura_jugadores_plantillas);

        return 0;

    }

#endif //PROYECTO_CORE_H    // Si no hay + codigo abajo lo acaba
