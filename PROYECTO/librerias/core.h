#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//Inclusion de librerias

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Definicion de funciones y estructuras

void leer_configuracion();

typedef struct{

    int max_equipos;
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

}jugadores_platillas;

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

void leer_configuracion(){

    configuracion estructura_config;
    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");
    assert(f_configuracion != NULL || printf("Error apertura fichero_configuracion\n"));

    fscanf(f_configuracion,"%i",&estructura_config.max_equipos);
    fscanf(f_configuracion,"%i",&estructura_config.presupuesto_defecto);
    fscanf(f_configuracion,"%i",&estructura_config.max_futbolistas_plantilla);
    fscanf(f_configuracion,"%i",&estructura_config.max_plantillas_participante);

    fclose(f_configuracion);
}

void escribir_configuracion(){

    configuracion estructura_config;
    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r+");
    assert(f_configuracion != NULL || printf("Error apertura fichero_configuracion\n"));

    fprintf(f_configuracion,"%i",estructura_config.max_equipos);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.presupuesto_defecto);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.max_futbolistas_plantilla);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.max_plantillas_participante);

    fclose(f_configuracion);
}
#endif //PROYECTO_CORE_H    // Si no hay + cosigo abajo lo acaba
