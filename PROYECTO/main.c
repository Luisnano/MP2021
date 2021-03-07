//LIBRERIAS

#include <stdio.h>
#include "librerias/core.h"
#include "librerias/login.h"


//DEFINICIONES_FUNCIONES

int acceso_sistema(usuarios *estruc_usu);

//MAIN PROGRAM

int main() {

    int seleccion,acceso;

    printf("¡¡Bienvenid@ a la liga fantastica!!\n\n");
    printf("1) Acceso al sistema (cuenta ya existente)\n");
    printf("2) Registrarse (cuenta no existente)\n\n");
    printf("Selecciona una de las opciones posibles: ");
    scanf("%i",&seleccion);

    if(seleccion==1){

        acceso = acceso_sistema()
    }

    return 0;
}
