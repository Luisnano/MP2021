#ifndef PROYECTO_LOGIN_H    //Si no está definido el módulo lo crea.
#define PROYECTO_LOGIN_H    //Definicion del módulo.

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

//CABECERAS DE FUNCIONES

int acceso_sistema(usuarios **estructura_usuarios, configuracion *estructura_config);
void registro(usuarios **estructura_usuarios, configuracion *estructura_config);

#endif //PROYECTO_LOGIN_H
