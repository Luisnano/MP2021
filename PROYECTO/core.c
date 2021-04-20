#include "librerias/core.h"

//Cabecera: void volcar_configuracion(configuracion *estructura_config);
//Precondición: La función recibe el vector dinamico de estructura_config
//Postcondición: Se volca toda la informacion del fichero configuracion.txt en estructura_config

void volcar_configuracion(configuracion *estructura_config){

    char *token;        //El token que guardara los campos de las lineas
    char linea[40] = "";     //Donde guardamos la linea del fichero para dividirla en tokens

    //Apertura del fichero

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");

    if(f_configuracion==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);}

    do{

        fgets(linea,40,f_configuracion);        //Leemos la linea del fichero

        if (strcmp(linea,"\0")!=0){             //Si la linea no esta vacia:

            //Vamos guardando los campos de la linea de configuracion.txt en sus respectivos campos de estructura_config
            //Mediante el uso de tokens con el delimitador guión

            token = strtok(linea,"-");
            estructura_config->presupuesto_defecto = atoi(token);
            token = strtok(NULL,"-");
            estructura_config->max_futbolistas_plantilla = atoi(token);
            token = strtok(NULL,"-");
            estructura_config->max_plantillas_participante = atoi(token);
            token = strtok(NULL,"-");
            estructura_config->tam_equipos = atoi(token);
            token = strtok(NULL,"-");
            estructura_config->tam_futbolistas = atoi(token);
            token = strtok(NULL,"-");
            estructura_config->tam_jugadores_plantillas = atoi(token);
            token = strtok(NULL,"-");
            estructura_config->tam_plantillas = atoi(token);
            token = strtok(NULL,"\n");
            estructura_config->tam_usuarios = atoi(token);

        }

    } while(!feof(f_configuracion));

    fclose(f_configuracion);
}

//Cabecera: void volcar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico de estructura_futbolistas y estructura_config
//Postcondición: Vuelca toda la información del fichero futbolistas.txt en estructura_futbolistas

void volcar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config){

    //Apertura del fichero

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "r");

    if(f_futbolistas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    char *token;        //El token donde se guardan los campos de las lineas del fichero
    char linea[60] = "";     //Linea donde se guarda las lineas del fichero

    *estructura_futbolistas = NULL;     //Empieza en null ya que al hacer el realloc puede tener basura

    do{

        fgets(linea, 60, f_futbolistas);       //Guarda en linea las lineas del fichero

        if (strcmp(linea,"\0") != 0){          //Si la linea no es nula

            //Aumenta el tamaño para 1 futbolista mas

            *estructura_futbolistas = (futbolistas*)realloc((*estructura_futbolistas),
                                                            ((*estructura_config).tam_futbolistas + 1)*sizeof(futbolistas));

            //Repite el proceso de guardar los campos de futbolistas en tokens y guardarlos en sus respectivos campos
            //Con atoi para transformar aquellos datos que son enteros, y stcpy para los datos que son cadenas

            token = strtok(linea,"-");
            (*estructura_futbolistas)[(*estructura_config).tam_futbolistas].futbolista_id = atoi(token);

            token = strtok(NULL,"-");
            (*estructura_futbolistas)[(*estructura_config).tam_futbolistas].equipo_id = atoi(token);

            token = strtok(NULL,"-");
            strcpy((*estructura_futbolistas)[(*estructura_config).tam_futbolistas].nombre_futbolista, token);

            token = strtok(NULL,"-");
            (*estructura_futbolistas)[(*estructura_config).tam_futbolistas].futbolista_precio = atoi(token);

            token = strtok(NULL,"\n");
            (*estructura_futbolistas)[(*estructura_config).tam_futbolistas].valoracion = atoi(token);

            //Aumenta el tamaño en 1 ya que hemos añadido un futbolista

            (*estructura_config).tam_futbolistas ++;

        }


    } while (!feof(f_futbolistas));


    fclose(f_futbolistas);
}

//Cabecera: void volcar_equipos(equipos **estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y estructura_config
//Postcondición: Se vuelca toda la información del fichero equipos.txt en estructura_equipos

void volcar_equipos(equipos **estructura_equipos, configuracion *estructura_config){


    //Apertura_fichero

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt", "r");

    if(f_equipos==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    char *token;        //El token donde se guardan los campos de las lineas del fichero
    char linea[24] = "";     //Linea donde se guarda las lineas del fichero

    *estructura_equipos = NULL;     //Empieza en null ya que al hacer el realloc puede tener basura

    do{

        fgets(linea, 24, f_equipos);       //Guarda en linea las lineas del fichero

        if (strcmp(linea,"\0") != 0){          //Si la linea no es nula

            //Aumenta el tamaño para 1 equipo mas

            *estructura_equipos = (equipos*)realloc((*estructura_equipos),
                                                    ((*estructura_config).tam_equipos + 1)*sizeof(equipos));

            //Repite el proceso de guardar los campos de equipos en tokens y guardarlos en sus respectivos campos
            //Con atoi para transformar aquellos datos que son enteros, y stcpy para los datos que son cadenas

            token = strtok(linea,"-");
            (*estructura_equipos)[(*estructura_config).tam_equipos].equipo_id = atoi(token);

            token = strtok(NULL,"\n");
            strcpy((*estructura_equipos)[(*estructura_config).tam_equipos].nombre_equipo, token);


            //Aumenta el tamaño en 1 ya que hemos añadido un equipo

            (*estructura_config).tam_equipos ++;

        }


    } while (!feof(f_equipos));


    fclose(f_equipos);
}

//Cabecera: void volcar_usuarios(equipos **estructura_usuarios, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_usuarios y estructura_config
//Postcondición: Se vuelca toda la información del fichero usuarios.txt en estructura_usuarios
void volcar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config){


    //Apertura del fichero

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "r");

    if(f_usuarios==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    char *token;        //El token donde se guardan los campos de las lineas del fichero
    char linea[65] = "";     //Linea donde se guarda las lineas del fichero

    *estructura_usuarios = NULL;     //Empieza en null ya que al hacer el realloc puede tener basura

    do{

        fgets(linea, 65, f_usuarios);       //Guarda en linea las lineas del fichero

        if (strcmp(linea,"\0") != 0){          //Si la linea no es nula

            //Aumenta el tamaño para 1 usuario mas

            *estructura_usuarios = (usuarios*)realloc((*estructura_usuarios),
                                                      ((*estructura_config).tam_usuarios + 1)*sizeof(usuarios));

            //Repite el proceso de guardar los campos de usuarios en tokens y guardarlos en sus respectivos campos
            //Con atoi para transformar aquellos datos que son enteros, y stcpy para los datos que son cadenas

            token = strtok(linea,"-");
            (*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_id = atoi(token);

            token = strtok(NULL,"-");
            strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].nombre_usuario, token);

            token = strtok(NULL,"-");
            strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_perfil, token);

            token = strtok(NULL,"-");
            strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_nick, token);

            token = strtok(NULL,"\n");
            strcpy((*estructura_usuarios)[(*estructura_config).tam_usuarios].usuario_password, token);

            //Aumenta el tamaño en 1 ya que hemos añadido un usuario

            (*estructura_config).tam_usuarios ++;

        }


    } while (!feof(f_usuarios));

    fclose(f_usuarios);
}

//Cabecera: void volcar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config);
//Precondicion: La función recibe el vector dinámico de estructura_plantillas y estructura_config
//Postcondición: Es volcada la informacion del fichero plantillas.txt en estructura_plantillas

void volcar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config){


    FILE *f_plantillas;

    f_plantillas = fopen("files/plantillas.txt", "r");

    if(f_plantillas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    char *token;        //El token donde se guardan los campos de las lineas del fichero
    char linea[50] = "";     //Linea donde se guarda las lineas del fichero

    *estructura_plantillas = NULL;     //Empieza en null ya que al hacer el realloc puede tener basura

    do{

        fgets(linea, 50, f_plantillas);       //Guarda en linea las lineas del fichero

        if (strcmp(linea,"\0") != 0){          //Si la linea no es nula

            //Aumenta el tamaño para 1 plantilla mas

            *estructura_plantillas = (plantillas*)realloc((*estructura_plantillas),
                                                          ((*estructura_config).tam_plantillas + 1)*sizeof(plantillas));

            //Repite el proceso de guardar los campos de plantillas en tokens y guardarlos en sus respectivos campos
            //Con atoi para transformar aquellos datos que son enteros, y stcpy para los datos que son cadenas

            token = strtok(linea,"-");
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].usuario_id = atoi(token);

            token = strtok(NULL,"-");
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].plantilla_id = atoi(token);

            token = strtok(NULL,"-");
            strcpy((*estructura_plantillas)[(*estructura_config).tam_plantillas].nombre_plantilla, token);

            token = strtok(NULL,"-");
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].presupuesto_disp = atoi(token);

            token = strtok(NULL,"\n");
            (*estructura_plantillas)[(*estructura_config).tam_plantillas].puntuacion_acum = atoi(token);

            //Aumenta el tamaño en 1 ya que hemos añadido una plantilla

            (*estructura_config).tam_plantillas ++;

        }


    } while (!feof(f_plantillas));

    fclose(f_plantillas);

}

//Cabecera: void volcar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas,
//                                           configuracion *estructura_config);
//Precondicion: La función recibe el vector dinámico de estructura_jugadores_plantillas y estructura_config
//Postcondición: La funcion vuelca toda la informacion del fichero jugadores_plantillas.txt en estructura_jugadores_plantillas

void volcar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas , configuracion *estructura_config){


    FILE *f_jugadores_plantillas;
    f_jugadores_plantillas = fopen("files/jugadores_plantillas.txt", "r");

    if(f_jugadores_plantillas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);

    }

    char *token;        //El token donde se guardan los campos de las lineas del fichero
    char linea[10] = "";     //Linea donde se guarda las lineas del fichero

    *estructura_jugadores_plantillas = NULL;     //Empieza en null ya que al hacer el realloc puede tener basura

    do{

        fgets(linea, 10, f_jugadores_plantillas);       //Guarda en linea las lineas del fichero

        if (strcmp(linea,"\0") != 0){          //Si la linea no es nula

            //Aumenta el tamaño para 1 equipo mas

            *estructura_jugadores_plantillas = (jugadores_plantillas*)realloc((*estructura_jugadores_plantillas),
                                                                              ((*estructura_config).tam_jugadores_plantillas + 1)*sizeof(jugadores_plantillas));

            //Repite el proceso de guardar los campos de jugadores_plantillas en tokens y guardarlos en sus respectivos campos
            //Con atoi para transformar aquellos datos que son enteros, y stcpy para los datos que son cadenas

            token = strtok(linea,"-");
            (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].jugador_platilla_id = atoi(token);

            token = strtok(NULL,"\n");
            (*estructura_jugadores_plantillas)[(*estructura_config).tam_jugadores_plantillas].plantilla_id = atoi(token);



            //Aumenta el tamaño en 1 ya que hemos añadido un futbolista a  una plantilla

            (*estructura_config).tam_jugadores_plantillas ++;

        }


    } while (!feof(f_jugadores_plantillas));

    fclose(f_jugadores_plantillas);

}

//Cabecera: void escribir_configuracion(configuracion *estructura_config);
//Precondición: La función recibe la variable estructura_configuracion
//Postcondición: Se escriben en el fichero configuración.txt los datos de estructura_configuracion

void escribir_configuracion(configuracion *estructura_config){

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","w");

    if(f_configuracion==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);
    }

    //Para cuando volvamos a volcar los datos no de error y empieze leyendo de cero
    //Inicializamos los tamaños a 0

    (*estructura_config).tam_futbolistas = 0;
    (*estructura_config).tam_equipos = 0;
    (*estructura_config).tam_usuarios = 0;
    (*estructura_config).tam_plantillas = 0;
    (*estructura_config).tam_jugadores_plantillas = 0;

    //Escribir datos del vector estructura_configuracion en el fichero configuracion

    fprintf(f_configuracion,"%i-%i-%i-%i-%i-%i-%i-%i",estructura_config->presupuesto_defecto,
            estructura_config->max_futbolistas_plantilla,estructura_config->max_plantillas_participante,
            estructura_config->tam_equipos,estructura_config->tam_futbolistas,estructura_config->tam_jugadores_plantillas,
            estructura_config->tam_plantillas,estructura_config->tam_usuarios);

    fclose(f_configuracion);
}

//Cabecera: void escribir_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe la variable dinámica estructura_fitbolistas y estructura_configuracion
//Postcondición: Se escriben en el fichero futbolistas.txt los datos de estructura_futbolistas

void escribir_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config){

    int i ;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "w");

    if(f_futbolistas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);
    }

    //Escribimos en el fichero futbolistas los datos de estructura_futbolistas

    for (i=0 ; i < (*estructura_config).tam_futbolistas ; i++){

        fprintf(f_futbolistas, "%i-%i-%s-%i-%i\n", (*estructura_futbolistas)[i].futbolista_id, (*estructura_futbolistas)[i].equipo_id,
                (*estructura_futbolistas)[i].nombre_futbolista,(*estructura_futbolistas)[i].futbolista_precio,
                (*estructura_futbolistas)[i].valoracion);
    }

    fclose(f_futbolistas);

}

//Cabecera: void escribir_equipos(equipos **estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y la estructura_configuracion
//Postcondición: Se escriben en el fichero equipos.txt los datos de estructura_equipos

void escribir_equipos(equipos **estructura_equipos, configuracion *estructura_config){

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt","w");

    if(f_equipos==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);
    }


    //Escribimos los datos de la estructura_equipos en el fichero equipos

    for (i=0; i < (*estructura_config).tam_equipos ; i++){

        fprintf(f_equipos, "%i-%s\n", (*estructura_equipos)[i].equipo_id,(*estructura_equipos)[i].nombre_equipo);
    }

    fclose(f_equipos);

}

//Cabecera: void escribir_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_usuarios y la estructura_configuracion
//Postcondición: Se escriben en el fichero usuarios.txt los datos de estructura_usuarios

void escribir_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config){

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "w");

    if(f_usuarios==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);
    }


    //Escribimos en el fichero usuarios los datos de su respectiva estructura

    for(i = 0 ; i < (*estructura_config).tam_usuarios ; i++){

        fprintf(f_usuarios,"%i-%s-%s-%s-%s\n",(*estructura_usuarios)[i].usuario_id,(*estructura_usuarios)[i].nombre_usuario,
                (*estructura_usuarios)[i].usuario_perfil,(*estructura_usuarios)[i].usuario_nick,
                (*estructura_usuarios)[i].usuario_password);
    }

    fclose(f_usuarios);

}

//Cabecera: void escribir_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_plantillas y la estructura_configuracion
//Postcondición: Se escriben en el fichero plantillas.txt los datos de estructura_plantillas

void escribir_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config) {

    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_plantillas;
    f_plantillas = fopen("files/plantillas.txt", "w");

    if(f_plantillas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);
    }

    //Escribimos en el fichero plantillas el vector dinamico estructura_plantillas

    for(i=0 ; i < (*estructura_config).tam_plantillas ; i++){

        fprintf(f_plantillas,"%i-%i-%s-%i-%i\n",(*estructura_plantillas)[i].usuario_id,(*estructura_plantillas)[i].plantilla_id,
                (*estructura_plantillas)[i].nombre_plantilla,(*estructura_plantillas)[i].presupuesto_disp,
                (*estructura_plantillas)[i].puntuacion_acum);
    }

    fclose(f_plantillas);

}

//Cabecera: void escribir_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas,
//                                             configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_jugadores_plantillas y la estructura_configuracion
//Postcondición: Se escriben en el fichero jugadores_plantillas.txt los datos de estructura_jugadores_plantillas

void escribir_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas,
                                   configuracion *estructura_config) {


    int i;

    //Abrimos el fichero en modo w para borrar los datos anteriores y escribir los actualizados desipues de salir del juego

    FILE *f_jugadores_plantillas;
    f_jugadores_plantillas = fopen("files/jugadores_plantillas.txt", "w");

    if(f_jugadores_plantillas==NULL){

        printf("Fallo de apertura de fichero\n");
        exit(EXIT_FAILURE);
    }

    //Escribimos en el fichero jugadores_plantillas los datos del vector dinamico estrucutura_jugadores_plantillas

    for (i = 0; i < (*estructura_config).tam_jugadores_plantillas; i++) {

        fprintf(f_jugadores_plantillas, "%i-%i\n", (*estructura_jugadores_plantillas)[i].jugador_platilla_id,
                (*estructura_jugadores_plantillas)[i].plantilla_id);
    }
    fclose(f_jugadores_plantillas);

}

//Cabecera: void mostrar_configuracion(configuracion *estructura_config);
//Precondición: La función recibe el vector estructura_config
//Postcondición: La función muestra los datos de estructura_config

void mostrar_configuracion(configuracion *estructura_config) {

    printf("El presupuesto por defecto es: %i \n", (*estructura_config).presupuesto_defecto);
    printf("El numero maximo de futbolistas por plantilla es: %i \n", (*estructura_config).max_futbolistas_plantilla);
    printf("El numero maximo de plantillas por participantes: %i \n",
           (*estructura_config).max_plantillas_participante);
    printf("El numero actual de equipos es: %i \n", (*estructura_config).tam_equipos);
    printf("El numero actual de futbolistas es: %i \n", (*estructura_config).tam_futbolistas);
    printf("El numero actual de jugadores por plantilla es: %i \n", (*estructura_config).tam_jugadores_plantillas);
    printf("El numero actual de plantillas es: %i \n", (*estructura_config).tam_plantillas);
    printf("El numero actual usuarios es: %i \n", (*estructura_config).tam_usuarios);
}

//Cabecera: void mostrar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_futbolistas y la estructura_config
//Postcondición: La función muestra los datos de estructura_futbolistas

void mostrar_futbolistas(futbolistas **estructura_futbolistas, configuracion *estructura_config) {

    int i;
    for (i = 0; i < (*estructura_config).tam_futbolistas ; i++) {

        printf("%i-", (*estructura_futbolistas)[i].futbolista_id);
        printf("%i-", (*estructura_futbolistas)[i].equipo_id);
        printf("%s-", (*estructura_futbolistas)[i].nombre_futbolista);
        printf("%i-", (*estructura_futbolistas)[i].futbolista_precio);
        printf("%i\n", (*estructura_futbolistas)[i].valoracion);
    }
}

//Cabecera: void mostrar_equipos(equipos **estructura_equipos, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_equipos y la estructura_config
//Postcondición: La función muestra los datos de estructura_equipos

void mostrar_equipos(equipos **estructura_equipos, configuracion *estructura_config) {

    int i;
    for (i = 0; i < (*estructura_config).tam_equipos ; i++) {

        printf("%i-", (*estructura_equipos)[i].equipo_id);
        printf("%s\n", (*estructura_equipos)[i].nombre_equipo);
    }
}

//Cabecera: void mostrar_usuarios(usuarios **estructura_usuarios , configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_usuarios y la estructura_config
//Postcondición: La función muestra los datos de estructura_usuarios

void mostrar_usuarios(usuarios **estructura_usuarios, configuracion *estructura_config) {

    int i;

    for (i = 0 ; i < (*estructura_config).tam_usuarios ; i++) {

        printf("%i-", (*estructura_usuarios)[i].usuario_id);
        printf("%s-", (*estructura_usuarios)[i].nombre_usuario);
        printf("%s-", (*estructura_usuarios)[i].usuario_perfil);
        printf("%s-", (*estructura_usuarios)[i].usuario_nick);
        printf("%s\n", (*estructura_usuarios)[i].usuario_password);
    }

}

//Cabecera: void mostrar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_plantillas y la estructura_config
//Postcondición: La función muestra los datos de estructura_plantillas

void mostrar_plantillas(plantillas **estructura_plantillas, configuracion *estructura_config) {

    int i;

    for (i = 0 ; i < (*estructura_config).tam_plantillas ; i++) {

        printf("%i,", (*estructura_plantillas)[i].usuario_id);
        printf("%i,", (*estructura_plantillas)[i].plantilla_id);
        printf("%s,", (*estructura_plantillas)[i].nombre_plantilla);
        printf("%i,", (*estructura_plantillas)[i].presupuesto_disp);
        printf("%i \n", (*estructura_plantillas)[i].puntuacion_acum);

    }

}

//Cabecera: void mostrar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas, configuracion *estructura_config);
//Precondición: La función recibe el vector dinámico estructura_jugadores_plantillas y la estructura_config
//Postcondición: La función muestra los datos de estructura_jugadores_plantillas

void mostrar_jugadores_plantillas(jugadores_plantillas **estructura_jugadores_plantillas,configuracion *estructura_config) {

    int i;

    for (i = 0 ; i < (*estructura_config).tam_jugadores_plantillas ; i++) {

        printf("%i,", (*estructura_jugadores_plantillas)[i].jugador_platilla_id);
        printf("%i \n", (*estructura_jugadores_plantillas)[i].plantilla_id);
    }

}

//Cabecera: void salir_programa(configuracion *estructura_config, futbolistas **estructura_futbolistas,
//                             equipos **estructura_equipos,usuarios **estructura_usuarios,
//                             plantillas **estructura_plantillas,jugadores_plantillas **estructura_jugadores_plantillas);
//Precondición: La funcion recibe todos los vectores dinamicos de estructura y estructura_config
//Postcondición: La función llama a todas las funciones para que escriban los datos modificados y añadidos durante el programa
//              , y acaba saliendo del programa

void salir_programa(configuracion *estructura_config, futbolistas **estructura_futbolistas, equipos **estructura_equipos,
                    usuarios **estructura_usuarios, plantillas **estructura_plantillas,
                    jugadores_plantillas **estructura_jugadores_plantillas) {

    //Para que se lean bien los ficheros para la siguiente vez que se ejecute el salir_programa
    //Inicializamos todos los tamaos actuales


    escribir_futbolistas(estructura_futbolistas,estructura_config);
    escribir_equipos(estructura_equipos,estructura_config);
    escribir_usuarios(estructura_usuarios,estructura_config);
    escribir_plantillas(estructura_plantillas,estructura_config);
    escribir_jugadores_plantillas(estructura_jugadores_plantillas,estructura_config);

    //El último es escribir_configuracion ya que contiene el tamaño de los ficheros que escribiremos como ceros
    //Y como necesitamos esos tamaños para escribir esos ficheros, lo dejamos para el final una vez
    //Los demas han sido escritos

    escribir_configuracion(estructura_config);

    //Liberamos la memoria dinamica

    free(*estructura_futbolistas);
    free(*estructura_equipos);
    free(*estructura_usuarios);
    free(*estructura_plantillas);
    free(*estructura_jugadores_plantillas);

    exit(1);



}

