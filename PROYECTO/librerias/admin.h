#ifndef PROYECTO_ADMIN_H
#define PROYECTO_ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include <string.h>

void menuAdministrador(configuracion *, jugadores_plantillas **, equipos **, usuarios **, futbolistas **, plantillas **);
void modificarEquipos( equipos **, configuracion *);
void addEquipos(equipos **, configuracion *);
void eliminarEquipos(equipos **, configuracion *);
void modificarUsuarios(usuarios **, configuracion *);
void addUsuarios(usuarios **, configuracion *);
void eliminarUsuarios(usuarios **, configuracion *);
void modificarConfiguracion(configuracion *);

//cabecera: void menuAdministrador(configuracion *, jugadores_plantillas **, equipos **, usuarios **, futbolistas **, plantillas **);
//precondicion: metodo que recibe todas las estructuras inicializadas.
//postcondicion: realiza las diferentes funciones del menú administrador.

void menuAdministrador(configuracion *estructura_config, jugadores_plantillas **estructura_jugadores_plantillas,
                       equipos **estructura_equipos, usuarios **estructura_usuarios, futbolistas **estructura_futbolistas,
                       plantillas **estructura_plantillas) { //metodo general del menu administrador

    int op = 0, op1 = 0, op2 = 0;
    printf("MENU ADMINISTRADOR\n\n");
    printf("1.- Equipos\n");
    printf("2.- Usuarios\n");
    printf("3.- Configuracion\n");
    printf("4.- Salir del programa\n");
    scanf("%i", &op);
    do {
        switch (op) {       //redirecciona las diferentes opciones:
            case 1:         //redireccion al menu de equipos (mostrar,modificar,añadir,eliminar)
                do {
                    printf("Bienvenido al menú de equipos\n");
                    printf("1.- Mostrar equipos\n");
                    printf("2.- Modificar equipos\n");
                    printf("3.- Annadir equipos\n");
                    printf("4.- Eliminar equipos\n");
                    scanf("%i", &op1);
                    switch (op1) {
                        case 1:
                            mostrar_equipos(estructura_equipos, estructura_config); //mostrar_equipos declarado en core.h
                            break;
                        case 2:
                            modificarEquipos(estructura_equipos, estructura_config);
                            break;
                        case 3:
                            addEquipos(estructura_equipos, estructura_config);
                            break;
                        case 4:
                            eliminarEquipos(estructura_equipos, estructura_config);
                            break;
                        default:
                            exit(EXIT_FAILURE); //salir del programa
                    }
                } while (op1 < 1 || op1 > 4);
                break;
            case 2:     //redireccion al menu de usuarios(mostrar,modificar,añadir,eliminar)
                printf("Bienvenido al menú de usuarios\n");
                printf("1.- Mostrar usuarios\n");
                printf("2.- Modificar usuarios\n");
                printf("3.- Annadir usuarios\n");
                printf("4.- Eliminar usuarios\n");
                scanf("%d", &op2);
                switch (op2) {
                    case 1:
                        mostrar_usuarios(estructura_usuarios, estructura_config);
                        break;
                    case 2:
                        modificarUsuarios(estructura_usuarios, estructura_config);
                        break;
                    case 3:
                        addUsuarios(estructura_usuarios, estructura_config);
                        break;
                    case 4:
                        eliminarUsuarios(estructura_usuarios, estructura_config);
                        break;
                    default:
                        exit(EXIT_FAILURE);
                }

            case 3:     //redireccion al menu de configuracion(solo edicion de este)
                printf("Bienvenido al menú de configuracion\n");
                modificarConfiguracion(estructura_config);
                break;

            case 4:     //llamada a la funcion salir_programa
                salir_programa(estructura_config, estructura_futbolistas, estructura_equipos, estructura_usuarios,
                               estructura_plantillas, estructura_jugadores_plantillas);
            default:
                exit(EXIT_FAILURE); //termina ejecución del programa
        }
    } while (op < 1 || op > 4);
}

    //cabecera: void modificarEquipos( equipos **estructura_equipos, configuracion *estructura_config);
    //precondicion: metodo que recibe las estructuras de equipos y configuracion inicializadas.
    //postcondicion: Permite al usuario modificar los equipos (nombre).

    void modificarEquipos( equipos **estructura_equipos, configuracion *estructura_config){
    char c,temp[21],nombre[21];
    int aux1=0;
    do {
        printf("\nIntroduce el nombre del equipo a modificar: ");
        scanf("%s", temp);
        for (int i = 0;i < (*estructura_config).tam_equipos; i++) {      //bucle para recorrer toda la estructura de equipos
            if (strcmp(temp, (*estructura_equipos)[i].nombre_equipo) == 0) {  //si temp coincide con algún nombre, almaceno el iterador
                aux1 = i;
            }
        }
        if (aux1 ==0) {//si no se ha almacenado un nuevo valor del iterador, entonces el nombre introducido no está en la estructura
            printf("\nEl nombre introducido de equipo no existe, Desea probar con otro nombre? (S o s para confirmar)");
            scanf("%c", &c);
        }
        }while((c == 's' || c == 'S')&&aux1 == 0);   //mientras no diga si y se cumpla que el nombre exista
        printf("\nSe ha encontrado un equipo con ese nombre: \nId: %d.\nNombre: %s.",
               (*estructura_equipos)[aux1].equipo_id, (*estructura_equipos)[aux1].nombre_equipo);
    do {

        printf("\nIntroduzca ahora el nuevo nombre:");  //nuevo nombre para el equipo
        scanf("%s",nombre);

    }while(strlen(nombre) > strlen((*estructura_equipos)[aux1].nombre_equipo));  //regula que el nuevo nombre no sea mayor que el tamaño predefinido
    strcpy((*estructura_equipos)[aux1].nombre_equipo,nombre);
}

    //cabecera: void addEquipos(equipos **estructura_equipos, configuracion *estructura_config);
    //precondicion: metodo que recibe las estructuras de equipos y configuracion inicializadas.
    //postcondicion: Permite al usuario añadir equipos.

    void addEquipos(equipos **estructura_equipos, configuracion *estructura_config){
    char c,temp[21];
    int aux1;
    do {
        printf("\nIntroduce el nombre del nuevo equipo: ");
        scanf("%s", temp);
        for (int i = 0;i < (*estructura_config).tam_equipos; i++) {      //bucle para recorrer toda la estructura de equipos
            if (strcmp(temp, (*estructura_equipos)[i].nombre_equipo) == 0) {  //si temp coincide con algún nombre, aux1 valdrá 1
                aux1 = 1;
            }else aux1 = 0;
        }
        if (aux1 == 1) {        //si es 1, entonces ese nombre ya está en uso
            printf("\nEl nombre del equipo ya esta en uso, Desea probar con otro nombre? (S o s para confirmar)");
            scanf("%c", &c);
        }
    }while((c == 's' || c == 'S')&&aux1 == 1);   //mientras diga sí y el nombre esté en uso
    printf("\nEl nombre se ha guardado con exito.");
    equipos *estructura_equipos_temp = (equipos*)realloc((*estructura_equipos),
                                                         ((*estructura_config).tam_equipos + 1)*sizeof(equipos));
    if(estructura_equipos_temp == NULL){

        printf("\nError en la redimension del vector.");
        exit(EXIT_FAILURE);

    }else{
        *estructura_equipos = estructura_equipos_temp;
        strcpy((*estructura_equipos)[(*estructura_config).tam_equipos].nombre_equipo, temp);
        (*estructura_equipos)[(*estructura_config).tam_equipos].equipo_id = (*estructura_config).tam_equipos;
    }
}

    //cabecera: void eliminarEquipos(equipos **estructura_equipos, configuracion *estructura_config);
    //precondicion: metodo que recibe las estructuras de equipos y configuracion inicializadas.
    //postcondicion: Permite al usuario eliminar equipos.

    void eliminarEquipos(equipos **estructura_equipos, configuracion *estructura_config){
        char c,temp[21],nombre_temp[21];
        int aux1,aux2;
        do {
            printf("\nIntroduce el nombre del usuario a eliminar: ");
            scanf("%s", temp);
            for (int i = 0;i < (*estructura_config).tam_usuarios; i++) {      //bucle para recorrer toda la estructura de equipos
                if (strcmp(temp, (*estructura_equipos)[i].nombre_equipo) == 0) {  //si temp coincide con algún nombre, aux1 valdrá i
                    aux1 = i;
                }else aux1 = 1;
            }
            if (aux1 == 1) {        //si es 1, entonces ese nombre no está registrado
                printf("\nEl nombre del equipo no está registrado, Desea probar con otro nombre? (S o s para confirmar)");
                scanf("%c", &c);
            }
        }while((c == 's' || c == 'S')&&aux1 == 1);   //mientras diga sí y el nombre esté en uso
        printf("\nEl nombre se ha guardado con exito.");

        //cambio de valores del equipo a eliminar con el equipo con la última posicion, para eliminarlo reajustando el tamaño del vector
        aux2 = (*estructura_equipos)[aux1].equipo_id;
        strcpy(nombre_temp,(*estructura_equipos)[aux1].nombre_equipo);
        (*estructura_equipos)[aux1].equipo_id = (*estructura_equipos)[(*estructura_config).tam_equipos].equipo_id;
        strcpy((*estructura_equipos)[aux1].nombre_equipo,(*estructura_equipos)[(*estructura_config).tam_equipos].nombre_equipo);
        (*estructura_equipos)[(*estructura_config).tam_equipos].equipo_id = aux2;
        strcpy((*estructura_equipos)[(*estructura_config).tam_equipos].nombre_equipo,nombre_temp);

        (*estructura_config).tam_usuarios -= 1;
        equipos *estructura_equipos_temp = (equipos*)realloc((*estructura_equipos),
                                                             ((*estructura_config).tam_equipos)*sizeof(equipos));
        if(estructura_equipos_temp == NULL){

            printf("\nFallo en la redimension del vector.");
            exit(EXIT_FAILURE);

        }else {
            *estructura_equipos = estructura_equipos_temp;
        }
}

    //cabecera: void addUsuarios(usuarios **estructura_usuarios, configuracion *estructura_config);
    //precondicion: metodo que recibe las estructuras de usuarios y configuracion inicializadas.
    //postcondicion: Permite al usuario añador un usuario.

    void addUsuarios(usuarios **estructura_usuarios, configuracion *estructura_config){
        char c,temp[21],perfil_temp[15],nick_temp[6],password_temp[9];
        int aux1;
        do {
            printf("\nIntroduce el nombre del nuevo usuario: ");
            scanf("%s", temp);
            for (int i = 0;i < (*estructura_config).tam_usuarios; i++) {      //bucle para recorrer toda la estructura de usuarios
                if (strcmp(temp, (*estructura_usuarios)[i].nombre_usuario) == 0) {  //si temp coincide con algún nombre, aux1 valdrá 1
                    aux1 = 1;
                }else aux1 = 0;
            }
            if (aux1 == 1) {        //si es 1, entonces ese nombre ya está en uso
                printf("\nEl nombre del usuario ya esta en uso, Desea probar con otro nombre? (S o s para confirmar)");
                scanf("%c", &c);
            }
        }while((c == 's' || c == 'S')&&aux1 == 1);   //mientras diga sí y el nombre esté en uso
        printf("\nEl nombre se ha guardado con exito.");
        (*estructura_config).tam_usuarios += 1;
        usuarios *estructura_usuarios_temp = (usuarios*)realloc((*estructura_usuarios),
                                                                ((*estructura_config).tam_usuarios)*sizeof(usuarios));
        *estructura_usuarios = estructura_usuarios_temp;
        strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].nombre_usuario, temp);
        (*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_id = (*estructura_config).tam_equipos;

        do {
            printf("Introduzca un perfil de usuario: ");
            scanf("%s", perfil_temp);
        } while (strcmp(perfil_temp, "administrador") != 0 || strcmp(perfil_temp, "participante") != 0 ||
                 strcmp(perfil_temp, "cronista") != 0);

        do {
            printf("\nIntroduzca ahora el nick:");  //nuevo nombre para el nick
            scanf("%s", nick_temp);

        } while (strlen(nick_temp) > strlen((*estructura_usuarios)[aux1].usuario_nick));  //regula que el nick no sea mayor que el tamaño predefinido

        do {
            printf("\nIntroduzca ahora la password:");  //nuevo password
            scanf("%s", password_temp);

        } while (strlen(password_temp) > strlen((*estructura_usuarios)[aux1].usuario_password));  //regula que la password no sea mayor que el tamaño predefinido

        strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_perfil,perfil_temp);        //copio el perfil en la estructura
        strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_nick,nick_temp);            //copio el nick en la estructura
        strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_password,password_temp);    //copio la password en la estructura
    }

    //cabecera: void modificarUsuarios(usuarios **estructura_usuarios, configuracion *estructura_config);
    //precondicion: metodo que recibe las estructuras de usuarios y configuracion inicializadas.
    //postcondicion: Permite al usuario modificar los usuarios.

    void modificarUsuarios(usuarios **estructura_usuarios, configuracion *estructura_config){
        char temp[21], c, nombre_temp[21], perfil_temp[15], nick_temp[5], password_temp[9];
        int aux1 = 0;
        do {
            printf("\nIntroduce el nombre del usuario a modificar: ");
            scanf("%s", temp);
            for (int i = 0;
                 i < (*estructura_config).tam_usuarios; i++) {      //bucle para recorrer toda la estructura de equipos
                if (strcmp(temp, (*estructura_usuarios)[i].nombre_usuario) == 0) {  //si temp coincide con algún nombre, almaceno el iterador
                    aux1 = i;
                }
            }
            if (aux1 ==0) {//si no se ha almacenado un nuevo valor del iterador, entonces el nombre introducido no está en la estructura
                printf("\nEl nombre introducido de equipo no existe, Desea probar con otro nombre? (S o s para confirmar)");
                scanf("%c", &c);
            }
        } while ((c == 's' || c == 'S') && aux1 == 0);   //mientras no diga si y se cumpla que el nombre exista
        printf("Hemos encontrado un usuario con ese nombre: ");
        printf("\nId: %d.\nNombre: %s.\nPerfil: %s.\nNick: %s.\nPassword: %s.", (*estructura_usuarios)[aux1].usuario_id,
               (*estructura_usuarios)[aux1].nombre_usuario, (*estructura_usuarios)[aux1].usuario_perfil,
               (*estructura_usuarios)[aux1].usuario_nick, (*estructura_usuarios)[aux1].usuario_password);
        do {

            printf("\nIntroduzca ahora el nuevo nombre:");  //nuevo nombre para el usuario
            scanf("%s", nombre_temp);

        } while (strlen(nombre_temp) > strlen((*estructura_usuarios)[aux1].nombre_usuario));  //regula que el nuevo nombre no sea mayor que el tamaño predefinido

        do {
            printf("Introduzca un perfil de usuario: ");
            scanf("%s", perfil_temp);
        } while (strcmp(perfil_temp, "administrador") != 0 || strcmp(perfil_temp, "participante") != 0 ||
                 strcmp(perfil_temp, "cronista") != 0);

        do {
            printf("\nIntroduzca ahora el nuevo nick:");  //nuevo nombre para el nick
            scanf("%s", nick_temp);

        } while (strlen(nick_temp) > strlen((*estructura_usuarios)[aux1].usuario_nick));  //regula que el nuevo nick no sea mayor que el tamaño predefinido

        do {
            printf("\nIntroduzca ahora la nueva password:");  //nuevo password
            scanf("%s", password_temp);

        } while (strlen(password_temp) > strlen((*estructura_usuarios)[aux1].usuario_password));  //regula que el nuevo nick no sea mayor que el tamaño predefinido

    }

    //cabecera: void eliminarUsuarios(usuarios **estructura_usuarios, configuracion *estructura_config);
    //precondicion: metodo que recibe las estructuras de usuarios y configuracion inicializadas.
    //postcondicion: Permite al usuario eliminar un usuario.

void eliminarUsuarios(usuarios **estructura_usuarios, configuracion *estructura_config){
    char c,temp[21],nombre_temp[21];
    int aux1,aux2;
    do {
        printf("\nIntroduce el nombre del usuario a eliminar: ");
        scanf("%s", temp);
        for (int i = 0;i < (*estructura_config).tam_usuarios; i++) {      //bucle para recorrer toda la estructura de usuarios
            if (strcmp(temp, (*estructura_usuarios)[i].nombre_usuario) == 0) {  //si temp coincide con algún nombre, aux1 valdrá i
                aux1 = i;
            }else aux1 = 1;
        }
        if (aux1 == 1) {        //si es 1, entonces ese nombre no está registrado
            printf("\nEl nombre del usuario no está registrado, Desea probar con otro nombre? (S o s para confirmar)");
            scanf("%c", &c);
        }
    }while((c == 's' || c == 'S')&&aux1 == 1);   //mientras diga sí y el nombre esté en uso
    printf("\nEl nombre se ha guardado con exito.");

    //cambio de valores del usuario a eliminar con el usuario con la última posicion, para eliminarlo reajustando el tamaño del vector
    aux2 = (*estructura_usuarios)[aux1].usuario_id;
    strcpy(nombre_temp,(*estructura_usuarios)[aux1].nombre_usuario);
    (*estructura_usuarios)[aux1].usuario_id = (*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_id;
    strcpy((*estructura_usuarios)[aux1].nombre_usuario,(*estructura_usuarios)[(*estructura_config).tam_equipos].nombre_usuario);
    (*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_id = aux2;
    strcpy((*estructura_usuarios)[(*estructura_config).tam_equipos].nombre_usuario,nombre_temp);

    (*estructura_config).tam_usuarios -= 1;
    usuarios *estructura_usuarios_temp = (usuarios*)realloc((*estructura_usuarios),
                                                            ((*estructura_config).tam_usuarios)*sizeof(usuarios));
    if(estructura_usuarios_temp == NULL){

        printf("\nFallo en la redimension del vector.");
        exit(EXIT_FAILURE);

    }else {
        *estructura_usuarios = estructura_usuarios_temp;
    }
}

    //cabecera: void modificarConfiguracion(configuracion *estructura_config);
    //precondicion: metodo que recibe la estructura de configuracion inicializada.
    //postcondicion: Permite al usuario administrador modificar la configuración.

    void modificarConfiguracion(configuracion *estructura_config) {
    int a=0, presupuestoTemp=0, maxPlanParTemp=0, maxFutPlan=0; //variables temporales para almacenar los valores
    char c;
    do{
        mostrar_configuracion(estructura_config);   //seleccion de las diferentes opciones
        printf("\nQue desea modificar?");
        printf("\n1. Presupuesto por defecto.");
        printf("\n2. Maximo de futbolistas por plantilla.");
        printf("\n3. Maximo de plantillas por jugador.");
        scanf("%i",&a);
        switch(a){
            case 1:
                do{
                    printf("\nIntroduce un nuevo valor para el presupuesto por defecto: ");
                    scanf("%i",&presupuestoTemp);
                    }while(presupuestoTemp < 0 || presupuestoTemp > 999999);    //mientras no salga de ese rango
                    printf("\nValor actualizado.");
                    (*estructura_config).presupuesto_defecto = presupuestoTemp;break;   //almaceno valor en la estructura
                    case 2:
                        do {
                            printf("\nIntroduce un nuevo valor para el maximo de futbolistas por plantilla: ");
                            scanf("%i", &maxFutPlan);
                        }while(maxFutPlan < 0 || maxFutPlan > 15);  //mientras no salga del rango
                            printf("\nValor actualizado.");
                            (*estructura_config).max_futbolistas_plantilla = maxFutPlan;break;    //almaceno valor en la estructura
                case 3:
                        do {
                            printf("\nIntroduce un nuevo valor para el maximo de plantillas por participante: ");
                            scanf("%i", &maxPlanParTemp);
                        }while(maxFutPlan < 0 || maxFutPlan > 6);   //mientras no salga de rango
                        printf("\nValor actualizado.");
                        (*estructura_config).max_plantillas_participante = maxPlanParTemp;break;  //almaceno valor en estructura

                default: exit(EXIT_FAILURE);
            }
            printf("Desea seguir modificando la configuracion? (Pulse 's' o 'S' para continuar)");
            scanf("%c",&c);
        }while (c == 's' || c == 'S');  //mientras sea 's' o 'S', se repite el bucle
        }
#endif //PROYECTO_ADMIN_H
