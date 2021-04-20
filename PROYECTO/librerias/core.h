#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//LLIBRERIAS

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

void salir_programa(configuracion *estructura_config,futbolistas **estructura_futbolistas,equipos **estructura_equipos,
                   usuarios **estructura_usuarios,plantillas **estructura_plantillas,
                   jugadores_plantillas **estructura_jugadores_plantillas);

#endif //PROYECTO_CORE_H    // Si no hay + codigo abajo lo acaba
