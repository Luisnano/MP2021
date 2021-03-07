#ifndef PROYECTO_LOGIN_H    //Si no esta definido el modulo lo crea
#define PROYECTO_LOGIN_H    //Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "core.h"

//DEFINICIONES_FUNCIONES

void acceso_sistema(usuarios *);
void registro(usuarios *);


//FUNCIONES

void acceso_sistema(usuarios *estruc_usu) {

    int i = 0,j = 0,aux;
    char u[6],p[9];                    //Mismos tamaños que el campo nick/password_usuario en usuario.txt

    printf("Introduzca su usuario: ");
    fgets(u,6,stdin);
    fflush(stdin);

    while(i<=sizeof(estruc_usu)){

        if(strcmp(u,estruc_usu[i].usuario_nick)==0){

            j = 1;
            aux = i;                //Guardo en aux el usuario para poder referirme a sus campos mas adelante
        }

        i++;
    }

    if(j==1){

        printf("\nBienvenid@ %s, a continuacion introduzca su password: ",estruc_usu[aux].nombre_usuario);
        etiqueta1:
        fgets(p,9,stdin);
        fflush(stdin);

        if(strcmp(p,estruc_usu[aux].usuario_password)==1){

            printf("\nPassword correcta, puede acceder al sistema como %s",estruc_usu[aux].usuario_perfil);
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

void registro(usuarios *estruc_usu){

    estruc_usu = (usuarios*)realloc(estruc_usu,(sizeof(*estruc_usu)+1)*sizeof(int));    //Le damos un espacio mas al vector dinamico usuarios
    assert(estruc_usu == NULL || puts("Fallo de reserva de memoria"));

    printf("A continuacion se le pediran sus datos necesarios para el registro\n\n");


}

#endif //PROYECTO_LOGIN_H   //Si no hay + codigo abajo lo acaba
