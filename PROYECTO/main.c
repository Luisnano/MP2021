//LIBRERIAS

#include <stdio.h>
#include <string.h>
#include "librerias/core.h"
#include "librerias/login.h"
#include "librerias/participantes.h"
#include "librerias/cronista.h"
#include "librerias/admin.h"

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
    volcar_usuarios(&estructura_usuarios,&estructura_config);
    volcar_futbolistas(&estructura_futbolistas,&estructura_config);
    volcar_equipos(&estructura_equipos,&estructura_config);
    volcar_plantillas(&estructura_plantillas,&estructura_config);
    volcar_jugadores_plantillas(&estructura_jugadores_plantillas,&estructura_config);

    //VARIABLES_LOCALES

    int i,id;
    char perfil[15];       //15 es el espacio max del campo usuario_perfil,
                           // ya que aquí guardare el perfil del usuario que accede al sistema

    //INICIO

    do {

    printf("Bienvenid@ a la liga fantastica!!\n\n");
    printf("1) Acceso al sistema (cuenta ya existente)\n");
    printf("2) Registrarse (cuenta no existente)\n");
    printf("3) Salir del sistema\n\n");
    printf("Selecciona una de las opciones posibles: ");

    scanf("%i",&i);

        if (i == 2) {

            registro(&estructura_usuarios,&estructura_config);
            id = acceso_sistema(&estructura_usuarios,&estructura_config);

            while (id == 1) {
                registro(&estructura_usuarios,&estructura_config);
                id = acceso_sistema(&estructura_usuarios,&estructura_config);
            }

            //Una vez se ha verificado que el usuario ha accedido al sistema hay que buscar su rol
            //Para enviarlo a su menu acorde a su rol

            for (i = 0; i < estructura_config.tam_usuarios; i++) {

                //Buscamos al usuario ay que id tendra su usuario_id

                if (estructura_usuarios[i].usuario_id == id) {

                    //Guardamos su rol para referirnos a el posteriormente

                    strcpy(perfil, estructura_usuarios[i].usuario_perfil);
                }
            }

            //Vemos si el usuario es participante

            if (strcmp(perfil, "participante") == 0) {

                menu_participantes(&id, &estructura_config, &estructura_jugadores_plantillas, &estructura_equipos,
                                   &estructura_usuarios, &estructura_futbolistas, &estructura_plantillas);

            }

            //Comprobamos si el usuario es cronista

            if (strcmp(perfil, "cronista") == 0) {

                menu_cronista(&estructura_config, &estructura_futbolistas, &estructura_equipos,
                              &estructura_usuarios, &estructura_plantillas,
                              &estructura_jugadores_plantillas);

            }

            //Chequeamos si el usuario es Administrador

            if(strcmp(perfil, "administrador") == 0) {

                menuAdministrador(&estructura_config , &estructura_jugadores_plantillas ,&estructura_equipos,
                                  &estructura_usuarios , &estructura_futbolistas , &estructura_plantillas);

            }

        }else if (i == 1) {

            id = acceso_sistema(&estructura_usuarios,&estructura_config);

            //Si acceso al sistema devuelve 1 significa que el usuario no está aun registrado

            while (id == 0) {
                registro(&estructura_usuarios,&estructura_config);
                id = acceso_sistema(&estructura_usuarios,&estructura_config);
            }

            //Una vez se ha verificado que el usuario ha accedido al sistema hay que buscar su rol
            //Para enviarlo a su menu acorde a su rol

            for (i = 0; i < estructura_config.tam_usuarios; i++) {

                //Buscamos al usuario ay que id tendra su usuario_id

                if (estructura_usuarios[i].usuario_id == id) {

                    //Guardamos su rol para referirnos a el posteriormente

                    strcpy(perfil, estructura_usuarios[i].usuario_perfil);
                }
            }

            //Vemos si el usuario es participante

            if (strcmp(perfil, "participante") == 0) {

                menu_participantes(&id, &estructura_config, &estructura_jugadores_plantillas, &estructura_equipos,
                                   &estructura_usuarios, &estructura_futbolistas, &estructura_plantillas);

            }

            //Comprobamos si el usuario es cronista

            if (strcmp(perfil, "cronista") == 0) {

                menu_cronista(&estructura_config, &estructura_futbolistas, &estructura_equipos,
                              &estructura_usuarios, &estructura_plantillas,
                              &estructura_jugadores_plantillas);

            }

            //Chequeamos si el usuario es Administrador

            if(strcmp(perfil, "administrador") == 0) {

                menuAdministrador(&estructura_config , &estructura_jugadores_plantillas ,&estructura_equipos,
                                  &estructura_usuarios , &estructura_futbolistas , &estructura_plantillas);

            }
        }else if(i == 3){
            salir_programa(&estructura_config, &estructura_futbolistas, &estructura_equipos, &estructura_usuarios,
                           &estructura_plantillas, &estructura_jugadores_plantillas);

        }

    //Si el usuario no introduce ni 1 (acceso al sistema) ni 2 (registro) se sigue repitiendo hasta que elija bien

    } while(i<1 || i>3);
}
