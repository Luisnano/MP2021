#ifndef PROYECTO_LOGIN_H    //Si no esta definido el modulo lo crea
#define PROYECTO_LOGIN_H    //Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <core.h>

//DEFINICIONES_FUNCIONES

int acceso_sistema(usuarios *);


//FUNCIONES

int acceso_sistema(usuarios *estruc_usu) {

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
        fgets(p,9,stdin);
        fflush(stdin);

        if(strcmp(p,estruc_usu[aux].usuario_password)==1){

            printf("\nPassword correcta, puede acceder al sistema como %s",estruc_usu[aux].usuario_perfil);
            return j;
        }
        else{

            j=2;
            return j;
        }

    }
    else{

        return j;
    }
}

#endif //PROYECTO_LOGIN_H   //Si no hay + codigo abajo lo acaba
