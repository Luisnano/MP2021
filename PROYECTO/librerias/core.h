#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//Inclusion de librerias

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Definicion de funciones y estructuras

typedef struct{

    int max_equipos;
    int presupuesto_defecto;
    int max_futbolistas_plantilla;
    int max_plantillas_participante;
    int max_futbolistas;

}configuracion;

configuracion estructura_config;

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



//Funciones_definiciones


void volcar_configuracion();
void escribir_configuracion();
void mostrar_configuracion();
void volcar_futbolistas();
void escribir_futbolistas(futbolistas *);
void mostrar_futbolistas(futbolistas *);
void volcar_equipos();
void escribir_equipos(equipos *);
void mostrar_equipos(equipos *);

//Funciones


void volcar_configuracion(){

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");
    assert(f_configuracion != NULL || puts("Fallo de apertura de fichero"));

    fscanf(f_configuracion,"%i",&estructura_config.max_equipos);
    fscanf(f_configuracion,"%i",&estructura_config.presupuesto_defecto);
    fscanf(f_configuracion,"%i",&estructura_config.max_futbolistas_plantilla);
    fscanf(f_configuracion,"%i",&estructura_config.max_plantillas_participante);
    fscanf(f_configuracion,"%i",&estructura_config.max_futbolistas);

    fclose(f_configuracion);
}

void volcar_futbolistas(){

    int i;

    futbolistas *estructura_futbolistas;
    estructura_futbolistas = (futbolistas*)malloc(estructura_config.max_futbolistas*sizeof(int));
    assert(estructura_futbolistas == NULL || puts("Fallo de asignacion de memoria"));

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "r");
    assert(f_futbolistas != NULL || puts("Fallo de apertura de fichero"));

    for (i=0; i<estructura_config.max_futbolistas; i++){
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].futbolista_id);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].equipo_id);
        fscanf(f_futbolistas, "%s", estructura_futbolistas[i].nombre_futbolista);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].futbolista_precio);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].valoracion);
    }
    fclose(f_futbolistas);

}

void volcar_equipos(){

    int i;

    equipos *estructura_equipos;
    estructura_equipos = (equipos*)malloc(estructura_config.max_equipos*sizeof(int));
    assert(estructura_equipos == NULL || puts("Fallo de asignacion de memoria"));

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt", "r");
    assert(f_equipos != NULL || puts("Fallo de apertura de fichero"));

    for (i=0; i<estructura_config.max_equipos; i++){
        fscanf(f_equipos, "%i", &estructura_equipos[i].equipo_id);
        fscanf(f_equipos, "%s", &estructura_equipos[i].nombre_equipo);
    }
    fclose(f_equipos);

}

void escribir_configuracion(){

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
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.max_futbolistas);

    fclose(f_configuracion);
}

void escribir_futbolistas(futbolistas *estruc_fut){

    int i = 1, j;
    char c;

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "r+");
    assert(f_futbolistas != NULL || printf("Error apertura fichero_futbolistas\n"));

    while(c != EOF){
        c = fgetc(f_futbolistas);
        if(c == '\n'){
            i++;
        }
    }

    for (j=0; j<i/5; j++){
        fprintf(f_futbolistas, "%i", estruc_fut[i].futbolista_id);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estruc_fut[i].equipo_id);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%s", estruc_fut[i].nombre_futbolista);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estruc_fut[i].futbolista_precio);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estruc_fut[i].valoracion);
        fprintf(f_futbolistas,"%s","\n");
    }

    fclose(f_futbolistas);

    free(estruc_fut);
}

void escribir_equipos(equipos *estruc_equ){

    int i = 1, j;
    char c;

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt","r+");
    assert(f_equipos != NULL || printf("Error apertura fichero_equipos\n"));

    while(c != EOF){
        c = fgetc(f_equipos);
        if(c == '\n'){
            i++;
        }
    }

    for (j=0; j<i/2; j++){
        fprintf(f_equipos, "%i", estruc_equ[i].equipo_id);
        fprintf(f_equipos, "%s", "\n");
        fprintf(f_equipos, "%s", estruc_equ[i].nombre_equipo);
        fprintf(f_equipos, "%s", "\n");
    }

    fclose(f_equipos);

    free(estruc_equ);
}
void mostrar_configuracion(){

    printf("El numero maximo de equipos es: %i \n",estructura_config.max_equipos);
    printf("El presupuesto por defecto es: %i \n",estructura_config.presupuesto_defecto);
    printf("El numero maximo de futbolistas por plantilla es: %i \n",estructura_config.max_futbolistas_plantilla);
    printf("El numero maximo de plantillas por participantes: %i \n",estructura_config.max_plantillas_participante);
    printf("El numero maximo de futbolistas es: %i \n",estructura_config.max_futbolistas);
}

void mostrar_futbolistas(futbolistas *estruc_fut){

    int i;
    for(i=0 ;i<=sizeof(*estruc_fut);i++){

        printf("%i,",estruc_fut[i].futbolista_id);
        printf("%i,",estruc_fut[i].equipo_id);
        printf("%s,",estruc_fut[i].nombre_futbolista);
        printf("%i,",estruc_fut[i].futbolista_precio);
        printf("%i\n",estruc_fut[i].valoracion);
    }
}

void mostrar_equipos(equipos *estruc_equ){

    int i;
    for(i=0 ; i<=sizeof(*estruc_equ);i++){

        printf("%i,",estruc_equ[i].equipo_id);
        printf("%s\n",estruc_equ[i].nombre_equipo);
    }
}

#endif //PROYECTO_CORE_H    // Si no hay + codigo abajo lo acaba

