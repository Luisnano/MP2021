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

#endif //PROYECTO_PARTICIPANTES_H
