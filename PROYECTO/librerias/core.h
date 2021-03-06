<<<<<<< HEAD
#ifndef PROYECTO_CORE_H
#define PROYECTO_CORE_H
=======
#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//Inclusion de librerias
>>>>>>> master

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

<<<<<<< HEAD
#endif //PROYECTO_CORE_H
=======
//Definicion de funciones y estructuras

void leer_configuracion();

typedef struct{

    int max_equipos;
    int presupuesto_defecto;
    int max_futbolistas_plantilla;
    int max_plantillas_participante;

}configuracion;

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
>>>>>>> master
