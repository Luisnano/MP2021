#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUCTURAS

typedef struct{

    int presupuesto_defecto;
    int max_futbolistas_plantilla;
    int max_plantillas_participante;

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
void volcar_futbolistas(futbolistas *estructura_futbolistas);
void escribir_futbolistas(futbolistas *estructura_futbolistas);
void mostrar_futbolistas(futbolistas *estructura_futbolistas);
void volcar_equipos(equipos *estructura_equipos);
void escribir_equipos(equipos *estructura_equipos);
void mostrar_equipos(equipos *estructura_equipos);
void volcar_usuarios(usuarios *estructura_usuarios);
void escribir_usuarios(usuarios *estructura_usuarios);
void mostrar_usuarios(usuarios *estructura_usuarios);
void volcar_plantillas(plantillas *estructura_plantillas);
void escribir_plantillas(plantillas *estructura_plantillas);
void mostrar_plantillas(plantillas *estructura_plantillas);
void volcar_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas);
void escribir_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas);
void mostrar_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas);
int salir_programa(configuracion *estructura_config,futbolistas *estructura_futbolistas,equipos *estructura_equipos,
                   usuarios *estructura_usuarios,plantillas *estructura_plantillas,
                   jugadores_plantillas *estructura_jugadores_plantillas);


//FUNCIONES


void volcar_configuracion(configuracion *estructura_config){

    //Apertura del fichero

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");
    if(f_configuracion==NULL){printf("Fallo de apertura de fichero\n");}

    //Vuelcan datos del fichero

    fscanf(f_configuracion,"%i",&estructura_config->presupuesto_defecto);
    fscanf(f_configuracion,"%i",&estructura_config->max_futbolistas_plantilla);
    fscanf(f_configuracion,"%i",&estructura_config->max_plantillas_participante);

    fclose(f_configuracion);
}

void volcar_futbolistas(futbolistas *estructura_futbolistas,configuracion *estructura_config){

    //Usamos la estructura_config ya que necesitamos el parametro max_jugadores para saber el tamaño del vector dinamicos

    int i,tam = 1;    //Tam contará el numero de lineas del fichero futbolista, empieza en 1 porque empieza en una linea
    char c;

    //Apertura del fichero

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "r");

    if(f_futbolistas==NULL){printf("Fallo de apertura de fichero\n");}

    //Contamos el numero de lineas del fichero futbolistas

    while(c!=EOF){

        c = fgetc(f_futbolistas);

        if(c == '\n'){

            tam ++;

        }
    }

    tam = tam/5;                  //Dividimos entre 5 puesto que en el fichero futbolistas escribimos 1 campo por linea
                                  //Es decir cada futbolista son 5 lineas

    //Reservamos la memoria dinámica

    estructura_futbolistas = (futbolistas*)calloc(tam,sizeof(int));
    if(estructura_futbolistas==NULL){printf("Fallo de reserva de memoria\n");}


    //Rellena estructura_futbolistas

    for (i=0; i<tam; i++){
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->futbolista_id);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->equipo_id);
        fscanf(f_futbolistas, "%s", estructura_futbolistas[i]->nombre_futbolista);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->futbolista_precio);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i]->valoracion);
    }

    fclose(f_futbolistas);
}

void volcar_equipos(equipos *estructura_equipos,configuracion *estructura_config){

    int i,tam = 1;
    char c;

    //Apertura_fichero

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt", "r");

    if(f_equipos==NULL){printf("Fallo de apertura de fichero\n");}

    //Contamos el numero de lineas del fichero equipos

    while(c!=EOF){

        c = fgetc(f_equipos);

        if(c == '\n'){

            tam++;
        }
    }

    tam = tam/2         //Dividimos entre 2 puesto que en el fichero equipos cada dato ocupa una linea
                        //Es decir, 2 lineas por usuario

    //Reserva memoria al vector dinamico


    estructura_equipos = (equipos*)calloc(tam,sizeof(int));
    if(estructura_equipos==NULL){printf("Fallo de reserva de memoria\n");}



    //Rellena la estructura_equipos

    for (i=0; i<tam; i++){

        fscanf(f_equipos, "%i", &estructura_equipos[i]->equipo_id);
        fscanf(f_equipos, "%s", estructura_equipos[i]->nombre_equipo);
    }


    fclose(f_equipos);
}

void volcar_usuarios(usuarios *estructura_usuarios, configuracion *estructura_config){

    int i,tam = 1;
    char c;

    //Apertura del fichero

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "r");

    if(f_usuarios==NULL){printf("Fallo de apertura de fichero\n");}

    //Contamos el numero de lineas del fichero usuarios

    while(c!=EOF){

        c = fgetc(f_usuarios);

        if(c == '\n'){

            tam++;

        }
    }

    tam = tam/5;        //Dividimos el numero de lineas entre 5 ya que en el fichero usuario cada dato ocupa una linea
                        //Es decir, 5 lineas por usuario

    //Reserva memoria en el vector dinamico


    estructura_usuarios =(usuarios*)calloc(tam,sizeof(int));  // El 3 es porque al principio hay solo 3 usuarios en el fichero
    if(estructura_usuarios==NULL){printf("Fallo de reserva de memoria\n");}

    //Rellena la estructura_usuarios

    for (i=0;i<tam;i++){

        fscanf(f_usuarios,"%i",&estructura_usuarios[i]->usuario_id);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->nombre_usuario);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->usuario_perfil);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->usuario_nick);
        fscanf(f_usuarios,"%s",estructura_usuarios[i]->usuario_password);
    }
    fclose(f_usuarios);
}

// Fichero plantillas empieza vacio , creamos unicamente la variable estructura

void volcar_plantillas(plantillas *estructura_plantillas, configuracion *estructura_config){


    // Le damos 1 espacio al vector dinamico, si se añaden plantillas se aumentara el tamano

    estructura_plantillas = (plantillas*)calloc(1,sizeof(int));
    if(estructura_plantillas==NULL){printf("Fallo de reserva de memoria\n");}


}

//Fichero jugadores_plantillas empieza vacio, creamos unicamente la variable estructura

void volcar_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas){



    //Le damos un espacio al vector dinamico, si se añaden futbolistas a las plantillas se aumentara el tamaño

    estructura_jugadores_plantillas = (jugadores_plantillas*)calloc(1,sizeof(int));
    if(estructura_jugadores_plantillas==NULL){printf("Fallo de reserva de memoria\n");}



}

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

    fclose(f_configuracion);
}

void escribir_futbolistas(futbolistas *estructura_futbolistas){

    int i ;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "w");

    if(f_futbolistas==NULL){printf("Fallo de apertura de fichero\n");}


    //Escribimos en el fichero futbolistas los datos de estructura_futbolistas

    for (i=0; i<=sizeof(estructura_futbolistas); i++){

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

    //Liberamos la memoria del vector dinamico

    free(estructura_futbolistas);
}

void escribir_equipos(equipos *estructura_equipos){

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt","w");

    if(f_equipos==NULL){printf("Fallo de apertura de fichero\n");}


    //Escribimos los datos de la estructura_equipos en el fichero equipos

    for (i=0; i<=sizeof(estructura_equipos); i++){

        fprintf(f_equipos, "%i", estructura_equipos[i]->equipo_id);
        fprintf(f_equipos, "%s", "\n");
        fprintf(f_equipos, "%s", estructura_equipos[i]->nombre_equipo);
        fprintf(f_equipos, "%s", "\n");
    }

    fclose(f_equipos);

    //Liberamos la memoria del vector dinamico

    free(estructura_equipos);
}

void escribir_usuarios(usuarios *estructura_usuarios){

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "w");

    if(f_usuarios==NULL){printf("Fallo de apertura de fichero\n");}


    //Escribimos en el fichero usuarios los datos de su respectiva estructura

    for(i=0 ; i<=sizeof(estructura_usuarios) ; i++){

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

    //Liberamos la memoria del vector dinámico

    free(estructura_usuarios);
}

void escribir_plantillas(plantillas *estructura_plantillas) {

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_plantillas;
    f_plantillas = fopen("files/plantillas.txt", "w");

    if(f_plantillas==NULL){printf("Fallo de apertura de fichero\n");}

    //Escribimos en el fichero plantillas el vector dinamico estructura_plantillas

    for(i=0 ; i<=sizeof(estructura_plantillas) ; i++){

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

        //Liberamos la memoria del vector

        free(estructura_plantillas);
    }


    void escribir_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas) {


        int i;

        //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

        FILE *f_jugadores_plantillas;
        f_jugadores_plantillas = fopen("files/jugadores_plantillas.txt", "w");

        if(f_jugadores_plantillas==NULL){printf("Fallo de apertura de fichero\n");}

        //Escribimos en el fichero jugadores_plantillas los datos del vector dinamico estrucutura_jugadores_plantillas

        for (i = 0; i <= sizeof(estructura_jugadores_plantillas); i++) {

            fprintf(f_jugadores_plantillas, "%i", estructura_jugadores_plantillas[i]->jugador_platilla_id);
            fprintf(f_jugadores_plantillas, "%s", "\n");
            fprintf(f_jugadores_plantillas, "%i", estructura_jugadores_plantillas[i]->plantilla_id);
            fprintf(f_jugadores_plantillas, "%s", "\n");
        }
        fclose(f_jugadores_plantillas);

        //Liberamos la memoria del vector

        free(estructura_jugadores_plantillas);

    }

//Mostrar los parametros actuales de estructura_config

    void mostrar_configuracion(configuracion *estructura_config) {

        printf("El presupuesto por defecto es: %i \n", estructura_config->presupuesto_defecto);
        printf("El numero maximo de futbolistas por plantilla es: %i \n", estructura_config->max_futbolistas_plantilla);
        printf("El numero maximo de plantillas por participantes: %i \n",
               estructura_config->max_plantillas_participante);
    }

//Mostrar los datos de los futbolistas actuales de estructura_futbolistas

    void mostrar_futbolistas(futbolistas *estructura_futbolistas) {

        int i;
        for (i = 0; i <= sizeof(estructura_futbolistas); i++) {

            printf("%i,", estructura_futbolistas[i]->futbolista_id);
            printf("%i,", estructura_futbolistas[i]->equipo_id);
            printf("%s,", estructura_futbolistas[i]->nombre_futbolista);
            printf("%i,", estructura_futbolistas[i]->futbolista_precio);
            printf("%i\n", estructura_futbolistas[i]->valoracion);
        }
    }

//Mostrar los datos de los equipos actules de la estructura_equipos

    void mostrar_equipos(equipos *estructura_equipos) {

        int i;
        for (i = 0; i <= sizeof(estructura_equipos); i++) {

            printf("%i,", estructura_equipos[i]->equipo_id);
            printf("%s\n", estructura_equipos[i]->nombre_equipo);
        }
    }

//Mostrar los usuarios actuales de estructura_usuarios

    void mostrar_usuarios(usuarios *estructura_usuarios) {

        int i;

        for (i = 0; i <= sizeof(estructura_usuarios); i++) {

            printf("%i,", estructura_usuarios[i]->usuario_id);
            printf("%s,", estructura_usuarios[i]->nombre_usuario);
            printf("%s,", estructura_usuarios[i]->usuario_perfil);
            printf("%s,", estructura_usuarios[i]->usuario_nick);
            printf("%s \n", estructura_usuarios[i]->usuario_password);

        }

    }

//Mostrar las plantillas actuales de estructura_plantillas

    void mostrar_plantillas(plantillas *estructura_plantillas) {

        int i;

        for (i = 0; i <= sizeof(estructura_plantillas); i++) {

            printf("%i,", estructura_plantillas[i]->usuario_id);
            printf("%i,", estructura_plantillas[i]->plantilla_id);
            printf("%s,", estructura_plantillas[i]->nombre_plantilla);
            printf("%i,", estructura_plantillas[i]->presupuesto_disp);
            printf("%i \n", estructura_plantillas[i]->puntuacion_acum);

        }

    }

//Mostrar los jugadores actuales asignados a las plantillas en la estructura_jugadores_plantillas

    void mostrar_jugadores_plantillas(jugadores_plantillas *estructura_jugadores_plantillas) {

        int i;

        for (i = 0; i <= sizeof(estructura_jugadores_plantillas); i++) {

            printf("%i,", estructura_jugadores_plantillas[i]->jugador_platilla_id);
            printf("%i \n", estructura_jugadores_plantillas[i]->plantilla_id);
        }

    }

    int salir_programa(configuracion *estructura_config, futbolistas *estructura_futbolistas, equipos *estructura_equipos,
                   usuarios *estructura_usuarios, plantillas *estructura_plantillas,
                   jugadores_plantillas *estructura_jugadores_plantillas) {

        escribir_configuracion(estructura_config);
        escribir_futbolistas(estructura_futbolistas);
        escribir_equipos(estructura_equipos);
        escribir_usuarios(estructura_usuarios);
        escribir_plantillas(estructura_plantillas);
        escribir_jugadores_plantillas(estructura_jugadores_plantillas);

        return 0;

    }
}
#endif //PROYECTO_CORE_H    // Si no hay + codigo abajo lo acaba
