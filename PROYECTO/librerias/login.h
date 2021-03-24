#ifndef PROYECTO_LOGIN_H    //Si no esta definido el modulo lo crea
#define PROYECTO_LOGIN_H    //Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

//CABECERAS DE FUNCIONES

int acceso_sistema(usuarios *estructura_usuarios, configuracion *estructura_config);
void registro(usuarios *estructura_usuarios, configuracion *estructura_config);


//FUNCIONES

//Función que permitirá a los usuarios registrados acceder al sistema.

//Cabecera: int acceso_sistema(usuarios *estructura_usuarios, configuracion *estructura_config).
//Precondición: la función recibe los contenidos de la estructura usuarios y de la estructura configuración.
//Poscondición: el usuario accede al sistema. En caso de coincidir su usuario y su contraseña, la función devuelve el
//perfil que le corresponde. En caso de que no esté registrado, devuelve 1.

int acceso_sistema(usuarios *estructura_usuarios, configuracion *estructura_config){

    int i = 0, j = 0, aux;
    char u[6], p[9];                    //Mismos tamaños(6 y 9) que el campo nick_usuario/password_usuario en usuario.txt

    printf("Introduzca su usuario: ");
    fgets(u,6,stdin);
    fflush(stdin);

    while(i < estructura_config->tam_usuarios){     //Recorre todo el vector dinamico de usuarios
                                                    //para verificar si existe algun susuario con ese nick.

        if(strcmp(u, estructura_usuarios[i].usuario_nick) == 0){       //Verifica si hay coincidencia.

            j = 1;                  //Para afirmar que se ha encontrado coincidencia,
            aux = i;                //guardo en aux el usuario para poder referirme a sus campos mas adelante.
        }

        i++;
    }

    if(j == 1){           //Si se ha encontrado el nick del usuario:

        printf("\nBienvenid@ %s, a continuacion introduzca su password: ", estructura_usuarios[aux].nombre_usuario);
        fgets(p,9,stdin);
        fflush(stdin);

        if(strcmp(p, estructura_usuarios[aux].usuario_password) == 0){

            printf("\nPassword correcta, puede acceder al sistema como %s", estructura_usuarios[aux].usuario_perfil);

            return estructura_usuarios[aux].usuario_id;    //Devuelvo el perfil del usuario para saber que menú usa.

        }

        else{

            while(strcmp(p, estructura_usuarios[aux].usuario_password) != 0 ){      //Comprueba la coincidencia de la contraseña

            printf("\nPassword incorrecta. Iintroduzcala de nuevo.");
            fgets(p,9,stdin);
            fflush(stdin);
             }
        }

    }

    else{

        printf("\nNo existe ningun usuario con tu nick. Registrate primero.");
        return 1;  //En caso de que no esté registrado el usuario, devuelve 1.
    }
}

//Funcion para que los usuarios se puedan registrar.

//Cabecera: void registro(usuarios *estructura_usuarios, configuracion *estructura_config).
//Precondición: la función recibe los contenidos de la estructura usuarios y de la estructura configuración.
//Poscondición: se registra un usuario de tipo participante.
void registro(usuarios *estructura_usuarios, configuracion *estructura_config){

    //Le asignamos un espacio más al vector dinámico usuarios.
    estructura_usuarios = (usuarios*)realloc(estructura_usuarios,(estructura_config->tam_usuarios+1)*sizeof(int));

    if(estructura_usuarios == NULL){printf("Fallo de reserva de memoria\n");}

    printf("A continuacion se le pediran sus datos necesarios para el registro\n\n");
    estructura_usuarios[estructura_config->tam_usuarios].usuario_id = estructura_config->tam_usuarios;

    //El ID del usuario se asigna automáticamente al siguiente espacio disponible. Esto es, el uso del espacio reservado
    //en pasos previos.

    printf("\nEscriba su nombre y primer apellido:");
    fgets(estructura_usuarios[estructura_config->tam_usuarios].nombre_usuario,21,stdin);
    fflush(stdin);
    printf("\nPor defecto, serás un usuario tipo participante");

    //Le asigno el perfil participante.
    strcpy(estructura_usuarios[estructura_config->tam_usuarios].usuario_perfil,"participante");
    fflush(stdin);

    printf("\nTu nombre de usuario(no mayor a 5 caracteres): ");   //Ya que el ultimo elemento del string está reservado.
    fgets(estructura_usuarios[estructura_config->tam_usuarios].usuario_nick,6,stdin);
    fflush(stdin);

    printf("\nPor ultimo, tu contraseña(no mayor a 8 caracteres): "); //Ya que el ultimo elemento del string está reservado.
    fgets(estructura_usuarios[estructura_config->tam_usuarios].usuario_password,9,stdin);
    fflush(stdin);

    printf("\n\nEl resgistro ha sido realizado con exito."
           "Puedes seleccionar la opcion de acceder al sistema del menu principal\n\n");

}

#endif //PROYECTO_LOGIN_H   //Si no hay + codigo abajo lo acaba
