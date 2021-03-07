//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include "librerias/core.h"
#include "librerias/login.h"


//DEFINICIONES_FUNCIONES


//MAIN PROGRAM

int main() {

    volcar_configuracion();
    volcar_futbolistas();
    volcar_equipos();
    volcar_usuarios();
    volcar_plantillas();
    volcar_jugadores_plantillas();

    printf("¡¡Bienvenid@ a la liga fantastica!!\n\n");
    printf("1) Acceso al sistema (cuenta ya existente)\n");
    printf("2) Registrarse (cuenta no existente)\n\n");
    printf("Selecciona una de las opciones posibles: ");


    return 0;
}
