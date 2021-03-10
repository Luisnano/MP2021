//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include "librerias/core.h"
#include "librerias/login.h"

//MAIN PROGRAM

int main() {

    //Creamos las variables tipo estructuras
    configuracion estructura_config;
    usuarios *estructura_usuarios;
    plantillas *estructura_plantillas;
    jugadores_plantillas *estructura_jugadores_plantillas;
    futbolistas *estructura_futbolistas;
    equipos *estructura_equipos;

    //Volcamos todos los datos de los ficheros en sus respectivas variables estructuras anteriormente declaradas
    volcar_configuracion(&estructura_config);
    volcar_futbolistas(&estructura_futbolistas,&estructura_config);
    volcar_equipos(&estructura_equipos,&estructura_config);
    volcar_usuarios(&estructura_usuarios);
    volcar_plantillas(&estructura_plantillas);
    volcar_jugadores_plantillas(&estructura_jugadores_plantillas);


    printf("Bienvenid@ a la liga fantastica!!\n\n");
    printf("1) Acceso al sistema (cuenta ya existente)\n");
    printf("2) Registrarse (cuenta no existente)\n\n");
    printf("Selecciona una de las opciones posibles: ");

    return 0;
}
