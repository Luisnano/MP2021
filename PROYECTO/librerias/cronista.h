#ifndef PROYECTO_CRONISTA_H
#define PROYECTO_CRONISTA_H


#include <string.h>
#include <stdlib.h>
#include "core.h"

//DECLARACION DE FUNCIONES


void menu_cronista(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                   usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                   jugadores_plantillas **estructura_jugadores_plantillas);
void valorar_futbolistas(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                     usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                     jugadores_plantillas **estructura_jugadores_plantillas);

#endif //PROYECTO_CRONISTA_H
