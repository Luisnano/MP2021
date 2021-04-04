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

    //String auxiliar para poder hacer los fgets

    char c[10];

    //Apertura del fichero

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");

    if(f_configuracion==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);}

    //Guardar los datos de cada linea del fichero en su respectivo campo
    //Ya que los datos en configuracion.txt están organizados de la manera que sea 1 dato por linea
    //Como todos los datos son valores enteros, los covertimos en del string c a entero mediante función atoi
    //El tamaño de los fgets depende del tamaño del entero + el /n y /0

        fgets(c,5,f_configuracion);
        estructura_config->presupuesto_defecto = atoi(c);
        fgets(c,4,f_configuracion);
        estructura_config->max_futbolistas_plantilla = atoi(c);
        fgets(c,3,f_configuracion);
        estructura_config->max_plantillas_participante = atoi(c);
        fgets(c,4,f_configuracion);
        estructura_config->tam_equipos = atoi(c);
        fgets(c,5,f_configuracion);
        estructura_config->tam_futbolistas = atoi(c);
        fgets(c,3,f_configuracion);
        estructura_config->tam_jugadores_plantillas = atoi(c);
        fgets(c,3,f_configuracion);
        estructura_config->tam_plantillas = atoi(c);
        fgets(c,3,f_configuracion);
        estructura_config->tam_usuarios = atoi(c);

    fclose(f_configuracion);
}
//Cabecera: void volcar_futbolistas(futbolistas *estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico de estructura_futbolistas y estructura_config
//Postcondición: Vuelca toda la información del fichero futbolistas.txt en estructura_futbolistas

void volcar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config){


    int i,j,N,tam = 1;   //Tam contará el numero de lineas del fichero futbolista, empieza en 1 porque empieza en una linea
    char c, aux[21];     //Aux tiene tamaño 21 ya que el tamaño máximo de los campos de futbolistas (nombre_futbolista)

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

    //Como cada futbolista ocupa una linea del fichero y tam guarda el número de lineas
    //Entonces el tamaño del vector dinámico de futbolistas es igual a tam

     estructura_config->tam_futbolistas = tam;

    //Reservamos la memoria dinámica

    *estructura_futbolistas = (futbolistas*)calloc(estructura_config->tam_futbolistas,sizeof(int));
    if(estructura_futbolistas==NULL){printf("Fallo de reserva de memoria\n");}


    //Rellena estructura_futbolistas, campo a campo, los cuales estan separados por comas

    //Este bucle será el bucle principal que acabará cuando se llegue al final del fichero, i simboliza el futbolista

    for (i = 0 ; !feof(f_futbolistas) ; i++ ){

        //Primero, el campo futbolista_id

        c = '0';

        //Guardamos en el string aux hasta la primera coma, es decir, hasta el final del primer campo, futbolista_id

        for(j = 0 ; c != ',' ; j++){

            c = fgetc(f_futbolistas);

            if (c != ','){

                aux[j] = c;
            }
        }

        //Transformamos lo recogido en un entero ya que futbolista_id es un dato entero

        estructura_futbolistas[i]->futbolista_id = atoi(aux);

        //Ahora el campo equipo_id

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0 ; tam < 21 ; tam++){

            aux[tam] = '\0';

        }

        //Guardamos en aux  hasta la segunda coma que es donde finaliza equipo_id

        for(j = 0 ; c != ',' ; j++){

            c = fgetc(f_futbolistas);

            if (c != ','){

                aux[j] = c;
            }
        }

        //Como equipo_id es un dato entero, transformamos lo recogido en aux en entero

        estructura_futbolistas[i]->equipo_id = atoi(aux);

        //Ahora el campo nombre_futbolista

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0 ; tam < 21 ; tam++){

            aux[tam] = '\0';

        }

        //Guardamos en aux  hasta la tercera coma que es donde finaliza nombre_futbolista

        for(j = 0 ; c != ',' ; j++){

            c = fgetc(f_futbolistas);

            if (c != ','){

                aux[j] = c;
            }
        }

        //Guardamos el nombre del futbolista que está en aux en su respectivo campo

        strcpy(estructura_futbolistas[i]->nombre_futbolista, aux);

        //Ahora el campo futbolista_precio

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0 ; tam < 21 ; tam++){

            aux[tam] = '\0';

        }

        //Guardamos en aux  hasta la cuarta coma que es donde finaliza futbolista_precio

        for(j = 0 ; c != ',' ; j++){

            c = fgetc(f_futbolistas);

            if (c != ','){

                aux[j] = c;
            }
        }

        //Como futbolista_precio es un dato entero, transformamos lo recogido en aux en entero

        estructura_futbolistas[i]->futbolista_precio = atoi(aux);

        //Ahora el campo valoracion

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0 ; tam < 21 ; tam++){

            aux[tam] = '\0';

        }

        //Guardamos en aux hasta el \n que es donde finaliza valoracion, ya que es el ultimo campo

        for(j = 0 ; c != '\n' ; j++){

            c = fgetc(f_futbolistas);

            if (c != '\n'){

                aux[j] = c;
            }
        }

        //Como valoración es un dato entero, transformamos lo recogido en aux en entero

        estructura_futbolistas[i]->valoracion = atoi(aux);
    }


    fclose(f_futbolistas);
}

//Cabecera: void volcar_equipos(equipos *estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y estructura_config
//Postcondición: Se vuelca toda la información del fichero equipos.txt en estructura_equipos

void volcar_equipos(equipos **estructura_equipos, configuracion *estructura_config){

    int i,j,tam = 1;    //Tam empieza valiendo 1 pues va a contar el número de lineas, y empieza ya contando una
    char c,aux[21];     //Aux tiene valor 21 ya que es el mayor tamaño de los campos de equipos (nombre_equipo)

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

    estructura_config->tam_equipos = tam;

    //Como cada equipo en el fichero ocupa 1 linea, entonces tam que ha guardado el numero de estas
    //Será el tamaño del vector dinamico de equipos
    //Reserva memoria al vector dinamico

    *estructura_equipos = (equipos*)calloc(estructura_config->tam_equipos,sizeof(int));
    if(estructura_equipos==NULL){printf("Fallo de reserva de memoria\n");}


    //Rellena la estructura_equipos

    //Rellena estructura_equipos, campo a campo, los cuales estan separados por comas

    //Este bucle será el bucle principal que acabará cuando se llegue al final del fichero, i simboliza el equipo

    for (i = 0 ; !feof(f_equipos) ; i++ ) {

        //Primero, el campo equipo_id

        c = '0';

        //Guardamos en el string aux hasta la primera coma, es decir, hasta el final del primer campo, equipo_id

        for (j = 0; c != ','; j++) {

            c = fgetc(f_equipos);

            if (c != ',') {

                aux[j] = c;
            }
        }

        //Transformamos lo recogido en un entero ya que equipo_id es un dato entero

        estructura_equipos[i]->equipo_id = atoi(aux);

        //Ahora el campo nombre_equipo

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0; tam < 21; tam++) {

            aux[tam] = '\0';

        }

        //Guardamos en aux  hasta el final de linea, ya que nombre_equipo es el último campo

        for (j = 0; c != '\n'; j++) {

            c = fgetc(f_equipos);

            if (c != '\n') {

                aux[j] = c;
            }
        }

        //Guardamos el nombre del equipo que está en aux en su respectivo campo

        strcpy(estructura_equipos[i]->nombre_equipo, aux);
    }


        fclose(f_equipos);
}

void volcar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config){

    int i,j,tam = 1;    //Tam comienza en 1 ya que contará el nº de lineas y ya se empieza contando una
    char c,aux[21];     //Aux tiene tamaño 21 ya que es el tamaño maximo de los campos de usuarios(nombre_usuario)

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

    estructura_config->tam_usuarios = tam;

    //Cada usuario ocupa 1 linea del fichero, lo cual está contabilizado en tam
    //Por lo tanto tam es el tamaño del vector dinámico de usuarios
    //Reserva memoria en el vector dinamico

    *estructura_usuarios =(usuarios*)calloc(estructura_config->tam_usuarios,sizeof(usuarios));
    if(estructura_usuarios==NULL){printf("Fallo de reserva de memoria\n");}

    //Rellena la estructura_equipos

    //Rellena estructura_usuarios, campo a campo, los cuales estan separados por comas

    //Este bucle será el bucle principal que acabará cuando se llegue al final del fichero, i simboliza al usuario

    for (i = 0 ; !feof(f_usuarios) ; i++ ) {

        //Primero, el campo usuario_id

        c = '0';

        //Guardamos en el string aux hasta la primera coma, es decir, hasta el final del primer campo, usuario_id

        for (j = 0; c != ','; j++) {

            c = fgetc(f_usuarios);

            if (c != ',') {

                aux[j] = c;
            }
        }

        //Transformamos lo recogido en un entero ya que usuario_id es un dato entero

        estructura_usuarios[i]->usuario_id = atoi(aux);

        //Ahora el campo nombre_usuario

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0; tam < 21; tam++) {

            aux[tam] = '\0';

        }

        //Guardamos en aux  hasta el final de la segunda coma, ya que nombre_usuario abarca hasta ahí

        for (j = 0; c != ','; j++) {

            c = fgetc(f_usuarios);

            if (c != ',') {

                aux[j] = c;
            }
        }

        //Guardamos el nombre del usuario que está en aux en su respectivo campo

        strcpy(estructura_usuarios[i]->nombre_usuario, aux);

        //Ahora el campo usuario_perfil

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0; tam < 21; tam++) {

            aux[tam] = '\0';

        }

        //Guardamos en aux hasta la tercera coma, ya que usuario_perfil abarca hasta ahí

        for (j = 0; c != ','; j++) {

            c = fgetc(f_usuarios);

            if (c != ',') {

                aux[j] = c;
            }
        }

        //Guardamos el perfil del ususario que está en aux en su respectivo campo

        strcpy(estructura_usuarios[i]->usuario_perfil, aux);

        //Ahora el campo usuario_nick

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0; tam < 21; tam++) {

            aux[tam] = '\0';

        }

        //Guardamos en aux hasta la cuarta coma ya que usuario_nick es el último campo

        for (j = 0; c != '\n'; j++) {

            c = fgetc(f_equipos);

            if (c != '\n') {

                aux[j] = c;
            }
        }

        //Guardamos el nombre del equipo que está en aux en su respectivo campo

        strcpy(estructura_equipos[i]->nombre_equipo, aux);

        //Ahora el campo nombre_equipo

        //Vaciamos auxiliar para usarlo de nuevo

        for (tam = 0; tam < 21; tam++) {

            aux[tam] = '\0';

        }

        //Guardamos en aux  hasta el final de linea, ya que nombre_equipo es el último campo

        for (j = 0; c != '\n'; j++) {

            c = fgetc(f_equipos);

            if (c != '\n') {

                aux[j] = c;
            }
        }

        //Guardamos el nombre del equipo que está en aux en su respectivo campo

        strcpy(estructura_equipos[i]->nombre_equipo, aux);
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
