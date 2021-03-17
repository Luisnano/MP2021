#ifndef PROYECTO_LOGIN_H    //Si no esta definido el modulo lo crea
#define PROYECTO_LOGIN_H    //Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

//DEFINICIONES_FUNCIONES

int acceso_sistema(usuarios *estructura_usuarios);
void registro(usuarios *estructura_usuarios);


//FUNCIONES

int acceso_sistema(usuarios *estructura_usuarios){ //Funcion que permitira a los usuarios registrados acceder al sistema

    int i = 0,j = 0,aux;
    char u[6],p[9];                    //Mismos tamaños(6 y 9) que el campo nick_usuario/password_usuario en usuario.txt

    printf("Introduzca su usuario: ");
    fgets(u,6,stdin);
    fflush(stdin);

    while(i<=sizeof(estructura_usuarios)){          //Recorre todo el vector dinamico de usuarios
                                                    // para verificar si existe algun susuario con ese nick

        if(strcmp(u,estructura_usuarios[i].usuario_nick)==0){   //Verifica si hay coincidencia

            j = 1;                  //Para afirmar que se ha encontrado coincidencia
            aux = i;                //Guardo en aux el usuario para poder referirme a sus campos mas adelante
        }

        i++;
    }

    if(j==1){           //Si se ha encontrado el nick del usuario:

        printf("\nBienvenid@ %s, a continuacion introduzca su password: ",estructura_usuarios[aux].nombre_usuario);
        etiqueta1:   //Esta etiqueta me servirá para volver a ella en caso de que posteriormente escriba mala contraseña,
                    // así podrá intentarlo de nuevo

        fgets(p,9,stdin);
        fflush(stdin);

        if(strcmp(p,estructura_usuarios[aux].usuario_password)==1){     //Comprueba la coincidencia de la contraseña

            printf("\nPassword correcta, puede acceder al sistema como %s",estructura_usuarios[aux].usuario_perfil);
            return estructura_usuarios[aux].usuario_id;    //Devuelvo el perfil del usuario para saber que menú usa
        }
        else{

            printf("\nPassword incorrecta,vuelve a introducirla: ");
            goto etiqueta1;                                //Va a la etiqueta para volver a introducir la contraseña
        }

    }
    else{
        printf("\nNo existe ningun usuario con tu nick, registrate primero");
        return 1;                   //En caso de que no esté registrado el usuario, devuelve 1
    }
}

void registro(usuarios *estructura_usuarios){       //Funcion para que los usuarios se puedan registrar

    //Le damos un espacio mas al vector dinamico usuarios
    estructura_usuarios = (usuarios*)realloc(estructura_usuarios,(sizeof(estructura_usuarios)+1)*sizeof(int));

    if(estructura_usuarios==NULL){printf("Fallo de reserva de memoria\n");}

    printf("A continuacion se le pediran sus datos necesarios para el registro\n\n");
    estructura_usuarios[sizeof(estructura_usuarios)].usuario_id = sizeof(estructura_usuarios);

    //El ID del usuario no lo elige él, le asignamos el siguiente numero disponible, es decir,
    // el del tamaño del vector ya q le hemos sumado uno a esa cantidad

    printf("\nDime tu nombre y primer apellido:");
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].nombre_usuario,21,stdin);
    fflush(stdin);
    printf("\nPor defecto serás usuario tipo participante");

    //Le asigno el perfil participante
    strcpy(estructura_usuarios[sizeof(estructura_usuarios)].usuario_perfil,"participante");
    fflush(stdin);

    printf("\nTu nombre de usuario(no mayor a 5 caracteres): ");   //Ya que el ultimo elemento del string está reservado
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].usuario_nick,6,stdin);
    fflush(stdin);
    printf("\nPor ultimo, tu contraseña(no mayor a 8 caracteres): "); //Ya que el ultimo elemento del string está reservado
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].usuario_password,9,stdin);
    fflush(stdin);

    printf("\n\nEl resgistro ha sido realizado con exito,"
           " ya puedes seleccionar la opcion de acceder al sistema del menu principal\n\n");

}

#endif //PROYECTO_LOGIN_H   //Si no hay + codigo abajo lo acaba
