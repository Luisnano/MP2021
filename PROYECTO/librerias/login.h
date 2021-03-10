#ifndef PROYECTO_LOGIN_H    //Si no esta definido el modulo lo crea
#define PROYECTO_LOGIN_H    //Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "core.h"

//DEFINICIONES_FUNCIONES

void acceso_sistema(usuarios *estructura_usuarios);
void registro(usuarios *estructura_usuarios);


//FUNCIONES

void acceso_sistema(usuarios *estructura_usuarios) {

    int i = 0,j = 0,aux;
    char u[6],p[9];                    //Mismos tamaños que el campo nick/password_usuario en usuario.txt

    printf("Introduzca su usuario: ");
    fgets(u,6,stdin);
    fflush(stdin);

    while(i<=sizeof(estructura_usuarios)){

        if(strcmp(u,estructura_usuarios[i].usuario_nick)==0){

            j = 1;
            aux = i;                //Guardo en aux el usuario para poder referirme a sus campos mas adelante
        }

        i++;
    }

    if(j==1){

        printf("\nBienvenid@ %s, a continuacion introduzca su password: ",estructura_usuarios[aux].nombre_usuario);
        etiqueta1:
        fgets(p,9,stdin);
        fflush(stdin);

        if(strcmp(p,estructura_usuarios[aux].usuario_password)==1){

            printf("\nPassword correcta, puede acceder al sistema como %s",estructura_usuarios[aux].usuario_perfil);
        }
        else{

            printf("\nPassword incorrecta,vuelve a introducirla: ");
            goto etiqueta1;
        }

    }
    else{
        printf("\nNo existe ningun usuario con tu nick, registrate primero");
    }
}

void registro(usuarios *estructura_usuarios){

    estructura_usuarios = (usuarios*)realloc(estructura_usuarios,(sizeof(estructura_usuarios)+1)*sizeof(int));    //Le damos un espacio mas al vector dinamico usuarios
    assert(estructura_usuarios != NULL || puts("Fallo de reserva de memoria"));

    printf("A continuacion se le pediran sus datos necesarios para el registro\n\n");
    scanf("%i",&estructura_usuarios[sizeof(estructura_usuarios)].usuario_id);
    printf("\nDime tu nombre y primer apellido:");
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].nombre_usuario,21,stdin);
    fflush(stdin);
    printf("\n¿Que tipo de usuario vas a ser? Puedes ser participante, cronista y participante: ");
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].usuario_perfil,15,stdin);
    fflush(stdin);
    printf("\nTu nombre de usuario(no mayor a 5 caracteres): ");
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].usuario_nick,6,stdin);
    fflush(stdin);
    printf("\nPor ultimo, tu contraseña(no mayor a 8 caracteres): ");
    fgets(estructura_usuarios[sizeof(estructura_usuarios)].usuario_password,9,stdin);
    fflush(stdin);

    printf("\n\nEl resgistro ha sido realizado con exito, ya puedes seleccionar la opcion de acceder al sistema del menu principal\n\n");

}

#endif //PROYECTO_LOGIN_H   //Si no hay + codigo abajo lo acaba
