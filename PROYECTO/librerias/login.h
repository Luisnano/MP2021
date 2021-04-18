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

//FUNCIONES

//Función que permitirá a los usuarios registrados acceder al sistema.

//Cabecera: int acceso_sistema(usuarios **estructura_usuarios, configuracion *estructura_config).
//Precondición: la función recibe los contenidos de la estructura usuarios y de la estructura configuración.
//Poscondición: el usuario accede al sistema. En caso de coincidir su usuario y su contraseña, la función devuelve el
//perfil que le corresponde. En caso de que no esté registrado, devuelve 1.

int acceso_sistema(usuarios **estructura_usuarios, configuracion *estructura_config){

    int i = 0, j = 0, aux;
    char u[6], p[9];                    //Mismos tamaños(6 y 9) que el campo nick_usuario/password_usuario en usuario.txt.

    fflush(stdin);
    printf("\nIntroduzca su nick: ");
    fgets(u,6,stdin);
    u[strcspn(u, "\n")] = 0;    //funcion que encuentra el primer '\n' o '\r', y esta la igualamos a 0
    fflush(stdin);                 //Evitamos el salto de linea implicito del fgets

    while(i < (*estructura_config).tam_usuarios ){       //Recorre el vector dinámico de usuarios
                                                        //para verificar si existe algun susuario con ese nick.
        if(strcmp(u, (*estructura_usuarios)[i].usuario_nick) == 0){       //Verifica si hay coincidencia.

            j = 1;                  //Para afirmar que se ha encontrado coincidencia,
            aux = i;                //guardo en aux el usuario para poder referirme a sus campos mas adelante.

        }
        i++;
    }

    if(j == 1){           //Si se ha encontrado el nick del usuario:

        printf("\nBienvenid@ %s, a continuacion introduzca su password: ", (*estructura_usuarios)[aux].nombre_usuario);
        fgets(p,9,stdin);
        p[strcspn(p, "\n")] = 0;
        fflush(stdin);

        if(strcmp(p, (*estructura_usuarios)[aux].usuario_password) == 0){

            printf("\nPassword correcta, puede acceder al sistema como %s\n", (*estructura_usuarios)[aux].usuario_perfil);

            return aux + 1;    //Devuelvo el perfil del usuario para saber que menú usa;
        }



            while(strcmp(p, (*estructura_usuarios)[aux].usuario_password) != 0 ){
                //Comprueba la coincidencia de la contraseña

                 printf("\nPassword incorrecta. Introduzcala de nuevo.");
                 fgets(p,9,stdin);
                 p[strcspn(p, "\n")] = 0;
                fflush(stdin);
             }
            
            return aux + 1;

    }

    printf("\nNo existe ningun usuario con tu nick. Registrate primero.");
    return 0;  //En caso de que no esté registrado el usuario, devuelve 1.
}

//Función para que los usuarios se puedan registrar.

//Cabecera: void registro(usuarios **estructura_usuarios, configuracion *estructura_config).
//Precondición: la función recibe los contenidos de la estructura usuarios y de la estructura configuración.
//Poscondición: se registra un usuario de tipo participante.

void registro(usuarios **estructura_usuarios, configuracion *estructura_config){


    int i, j;        //J y aux serán auxiliares que servirán para saber cuando el nick o la contraseña ya existen.
    char aux[6];    //Tamaño 6 pues el tamaño del campo nick en usuarios es 6.

    //Le asignamos un espacio más al vector dinámico usuarios.

    (*estructura_config).tam_usuarios++;

    *estructura_usuarios = (usuarios*)realloc
                                    ((*estructura_usuarios),((*estructura_config).tam_usuarios)*sizeof(usuarios));

    printf("\nA continuacion se le pediran sus datos necesarios para el registro\n");

    do {

        j = 1;

        //En aux guardamos el nick en un principio para verificar si es valido

        fflush(stdin);
        printf("\nIntroduce tu nick de usuario(no mayor a 5 caracteres): ");
        //Ya que el ultimo elemento del string está reservado.
        fgets(aux, 6, stdin);
        aux[strcspn(aux, "\n")] = 0;
        fflush(stdin);

        for(i = 0 ; i < (*estructura_config).tam_usuarios ; i++) {

            if ((*estructura_usuarios)[i].usuario_nick == aux) {

                printf("\nEse nick ya existe, prueba otro!");
                //j a 0 para repetir el proceso hasta que introduzca un nick valido
                j = 0;

            }
        }

    } while(j == 0);

    //Si el nick es valido, lo guardamos en su lugar adecuado

    strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios-1].usuario_nick , aux);

    printf("\nIntroduce tu password (no mayor a 8 caracteres): ");

    //Ya que el ultimo elemento del string está reservado(tamaño de password).

    fflush(stdin);
    fgets((*estructura_usuarios)[(*estructura_config).tam_usuarios-1].usuario_password, 9, stdin);
    (*estructura_usuarios)[(*estructura_config).tam_usuarios-1].usuario_password[strcspn((*estructura_usuarios)[(*estructura_config).tam_usuarios-1].usuario_password, "\n")] = 0;

    //El ID del usuario se asigna automáticamente al siguiente espacio disponible.
    (*estructura_usuarios)[(*estructura_config).tam_usuarios-1].usuario_id = (*estructura_config).tam_usuarios;

    fflush(stdin);
    printf("\nEscriba su nombre y primer apellido:");
    fgets((*estructura_usuarios)[(*estructura_config).tam_usuarios-1].nombre_usuario,21,stdin);
    (*estructura_usuarios)[(*estructura_config).tam_usuarios-1].nombre_usuario[strcspn((*estructura_usuarios)[(*estructura_config).tam_usuarios-1].nombre_usuario, "\n")] = 0;
    fflush(stdin);

    printf("\nEl rol que puedes ser es por defecto participante\n");
    strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios-1].usuario_perfil, "participante");

    printf("\n\nEl resgistro ha sido realizado con exito."
           "Se procede a acceder al sistema\n\n");

}

#endif //PROYECTO_LOGIN_H   //Si no hay + codigo abajo lo acaba
