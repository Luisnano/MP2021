//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librerias/core.h"
#include "librerias/login.h"
#include "librerias/participantes.h"

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

    volcar_futbolistas(estructura_futbolistas,&estructura_config);
    volcar_equipos(estructura_equipos,&estructura_config);
    volcar_usuarios(estructura_usuarios);
    volcar_plantillas(estructura_plantillas);
    volcar_jugadores_plantillas(estructura_jugadores_plantillas);

    //VARIABLES_LOCALES

    int i,id;
    char perfil[15];            //15 es el espacio max del campo usuario_perfil, ya que aquí guardare el perfil del usuario que accede al sistema

    //INICIO

    etiqueta1:


    volcar_futbolistas(estructura_futbolistas,&estructura_config);
    /*
    volcar_equipos(&estructura_equipos,&estructura_config);
    volcar_usuarios(&estructura_usuarios, &estructura_config);
    volcar_plantillas(&estructura_plantillas, &estructura_config);
    volcar_jugadores_plantillas(&estructura_jugadores_plantillas);
*/
    //mostrar_configuracion(&estructura_config);
    //escribir_configuracion(&estructura_config);
    //mostrar_futbolistas(&estructura_futbolistas, estructura_config);
    /*

    printf("Bienvenid@ a la liga fantastica!!\n\n");
    printf("1) Acceso al sistema (cuenta ya existente)\n");
    printf("2) Registrarse (cuenta no existente)\n\n");
    printf("Selecciona una de las opciones posibles: ");

    scanf("%i",&i);

    if(i==1){

        id = acceso_sistema(estructura_usuarios);

        if (id ==1){

            goto etiqueta1;
        }

        for(i=0 ; i<=sizeof(estructura_usuarios) ; i++){

            if(estructura_usuarios[i].usuario_id == id){
                strcpy(perfil,estructura_usuarios[i].usuario_perfil);
            }
        }
        if (strcmp(perfil,"participante")==0){

            menu_participantes(&id,&estructura_config,estructura_jugadores_plantillas,estructura_equipos,estructura_usuarios,estructura_futbolistas,estructura_plantillas);

        }
        if (strcmp(perfil,"cronista")==0){

            menu_cronista(estructura_equipos);

        }

    }
    
    else{

        if(i==2){

            registro(estructura_usuarios);
            goto etiqueta1;

        }
        else{
            goto etiqueta1;
        }
    }



*/

    return 0;
}
