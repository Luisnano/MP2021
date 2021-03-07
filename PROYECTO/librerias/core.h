#ifndef PROYECTO_CORE_H     // Si no esta definido el modulo lo crea
#define PROYECTO_CORE_H     // Definicion del modulo

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ESTRUCTURAS

typedef struct{

    int max_equipos;
    int presupuesto_defecto;
    int max_futbolistas_plantilla;
    int max_plantillas_participante;
    int max_futbolistas;

}configuracion;

configuracion estructura_config;

typedef struct{

    int usuario_id;
    char nombre_usuario[21];
    char usuario_perfil[15];
    char usuario_nick[6];
    char usuario_password[9];

}usuarios;

usuarios *estructura_usuarios;

typedef struct{

    int usuario_id;
    int plantilla_id;
    char nombre_plantilla[31];
    int presupuesto_disp;
    int puntuacion_acum;

}plantillas;

plantillas *estructura_plantillas;

typedef struct{

    int jugador_platilla_id;
    int plantilla_id;

}jugadores_plantillas;

jugadores_plantillas *estructura_jugadores_plantillas;

typedef struct{

    int futbolista_id;
    int equipo_id;
    char nombre_futbolista[21];
    int futbolista_precio;
    int valoracion;

}futbolistas;

futbolistas *estructura_futbolistas;

typedef struct{

    int equipo_id;
    char nombre_equipo[21];

}equipos;

equipos *estructura_equipos;



//DEFINICIONES_FUNCIONES


void volcar_configuracion();
void escribir_configuracion();
void mostrar_configuracion();
void volcar_futbolistas();
void escribir_futbolistas();
void mostrar_futbolistas();
void volcar_equipos();
void escribir_equipos();
void mostrar_equipos();
void volcar_usuarios();
void escribir_usuarios();
void mostrar_usuarios();
void volcar_plantillas();
void escribir_plantillas();
void mostrar_plantillas();
void volcar_jugadores_plantillas();
void escribir_jugadores_plantillas();
void mostrar_jugadores_plantillas();

//FUNCIONES


void volcar_configuracion(){

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","r");
    assert(f_configuracion != NULL || printf("Fallo de apertura de fichero\n"));

    fscanf(f_configuracion,"%i",&estructura_config.max_equipos);
    fscanf(f_configuracion,"%i",&estructura_config.presupuesto_defecto);
    fscanf(f_configuracion,"%i",&estructura_config.max_futbolistas_plantilla);
    fscanf(f_configuracion,"%i",&estructura_config.max_plantillas_participante);
    fscanf(f_configuracion,"%i",&estructura_config.max_futbolistas);

    fclose(f_configuracion);
}

void volcar_futbolistas(){

    int i;

    estructura_futbolistas = (futbolistas*)malloc(estructura_config.max_futbolistas*sizeof(int));
    assert(estructura_futbolistas != NULL || printf("Fallo de reserva de memoria\n"));

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "r");
    assert(f_futbolistas != NULL || printf("Fallo de apertura de fichero\n"));

    for (i=0; i<1; i++){
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].futbolista_id);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].equipo_id);
        fscanf(f_futbolistas, "%s", &estructura_futbolistas[i].nombre_futbolista);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].futbolista_precio);
        fscanf(f_futbolistas, "%i", &estructura_futbolistas[i].valoracion);
    }
    fclose(f_futbolistas);

}

void volcar_equipos(){

    int i;

    estructura_equipos = (equipos*)malloc(estructura_config.max_equipos*sizeof(int));
    assert(estructura_equipos != NULL || printf("Fallo de reserva de memoria\n"));

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt", "r");
    assert(f_equipos != NULL || printf("Fallo de apertura de fichero\n"));

    for (i=0; i<estructura_config.max_equipos; i++){

        fscanf(f_equipos, "%i", &estructura_equipos[i].equipo_id);
        fscanf(f_equipos, "%s", &estructura_equipos[i].nombre_equipo);
    }
    fclose(f_equipos);
}

void volcar_usuarios(){

    int i;

    estructura_usuarios =(usuarios*)malloc(3*sizeof(int));  // El 3 es porque al principio hay solo 3 usuarios en el fichero
    assert(estructura_usuarios != NULL || printf("Fallo de reserva de memoria\n"));

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "r");
    assert(f_usuarios != NULL || printf("Fallo de apertura de fichero\n"));

    for (i=0;i<3;i++){

        fscanf(f_usuarios,"%i",&estructura_usuarios[i].usuario_id);
        fscanf(f_usuarios,"%s",&estructura_usuarios[i].nombre_usuario);
        fscanf(f_usuarios,"%s",&estructura_usuarios[i].usuario_perfil);
        fscanf(f_usuarios,"%s",&estructura_usuarios[i].usuario_nick);
        fscanf(f_usuarios,"%s",&estructura_usuarios[i].usuario_password);
    }
    fclose(f_usuarios);
}

void volcar_plantillas(){       // Fichero plantillas empieza vacio , creamos unicamente la variable estructura

    estructura_plantillas = (plantillas*)malloc(1*sizeof(int));     // Le damos 1 espacio al vector dinamico, si se añaden plantillas se aumentara el tamano
    assert(estructura_plantillas != NULL || printf("Fallo de reserva de memoria\n"));
}

void volcar_jugadores_plantillas(){        //Fichero jugadores_plantillas empieza vacio, creamos unicamente la variable estructura

    estructura_jugadores_plantillas = (jugadores_plantillas*)malloc(1*sizeof(int));     //Le damos un espacio al vector dinamico, si se añaden futbolistas a las plantillas se aumentara el tamaño
    assert(estructura_jugadores_plantillas != NULL || printf("Fallo de reserva de memoria\n"));
}

void escribir_configuracion(){

    FILE *f_configuracion;
    f_configuracion = fopen("files/configuracion.txt","w");
    assert(f_configuracion != NULL || printf("Error apertura fichero_configuracion\n"));

    fprintf(f_configuracion,"%i",estructura_config.max_equipos);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.presupuesto_defecto);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.max_futbolistas_plantilla);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.max_plantillas_participante);
    fprintf(f_configuracion,"%s","\n");
    fprintf(f_configuracion,"%i",estructura_config.max_futbolistas);

    fclose(f_configuracion);
}

void escribir_futbolistas(){

    int i ;

    FILE *f_futbolistas;
    f_futbolistas = fopen("files/futbolistas.txt", "w");
    assert(f_futbolistas != NULL || printf("Error apertura fichero_futbolistas\n"));

    for (i=0; i<=sizeof(estructura_futbolistas); i++){
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i].futbolista_id);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i].equipo_id);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%s", estructura_futbolistas[i].nombre_futbolista);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i].futbolista_precio);
        fprintf(f_futbolistas,"%s","\n");
        fprintf(f_futbolistas, "%i", estructura_futbolistas[i].valoracion);
        fprintf(f_futbolistas,"%s","\n");
    }

    fclose(f_futbolistas);

    free(estructura_futbolistas);
}

void escribir_equipos(){

    int i;

    FILE *f_equipos;
    f_equipos = fopen("files/equipos.txt","w");
    assert(f_equipos != NULL || printf("Error apertura fichero_equipos\n"));

    for (i=0; i<=sizeof(estructura_equipos); i++){
        fprintf(f_equipos, "%i", estructura_equipos[i].equipo_id);
        fprintf(f_equipos, "%s", "\n");
        fprintf(f_equipos, "%s", estructura_equipos[i].nombre_equipo);
        fprintf(f_equipos, "%s", "\n");
    }

    fclose(f_equipos);

    free(estructura_equipos);
}

void escribir_usuarios(){

    int i;

    FILE *f_usuarios;
    f_usuarios = fopen("files/usuarios.txt", "w");
    assert(f_usuarios != NULL || printf("Error apertura fichero_equipos\n"));

    for(i=0 ; i<=sizeof(estructura_usuarios) ; i++){

        fprintf(f_usuarios,"%i",estructura_usuarios[i].usuario_id);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i].nombre_usuario);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i].usuario_perfil);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i].usuario_nick);
        fprintf(f_usuarios, "%s", "\n");
        fprintf(f_usuarios,"%s",estructura_usuarios[i].usuario_password);
        fprintf(f_usuarios, "%s", "\n");

    }
    fclose(f_usuarios);

    free(estructura_usuarios);
}

void escribir_plantillas(){

    int i;

    FILE *f_plantillas;
    f_plantillas = fopen("files/plantillas.txt", "w");
    assert(f_plantillas != NULL || printf("Error apertura de fichero\n"));


    for(i=0 ; i<=sizeof(estructura_plantillas) ; i++){

        fprintf(f_plantillas,"%i",estructura_plantillas[i].usuario_id);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%i",estructura_plantillas[i].plantilla_id);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%s",estructura_plantillas[i].nombre_plantilla);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%i",estructura_plantillas[i].presupuesto_disp);
        fprintf(f_plantillas, "%s", "\n");
        fprintf(f_plantillas,"%i",estructura_plantillas[i].puntuacion_acum);
        fprintf(f_plantillas, "%s", "\n");
    }

    fclose(f_plantillas);

    free(estructura_plantillas);
}

void escribir_jugadores_plantillas(){

    int i;

    FILE *f_jugadores_plantillas;
    f_jugadores_plantillas = fopen("files/jugadores_plantillas.txt", "w");
    assert(f_jugadores_plantillas != NULL || printf("Error apertura fichero_jugadores_plantillas\n"));

    for(i=0 ; i<=sizeof(estructura_jugadores_plantillas) ; i++){

        fprintf(f_jugadores_plantillas,"%i",estructura_jugadores_plantillas[i].jugador_platilla_id);
        fprintf(f_jugadores_plantillas, "%s", "\n");
        fprintf(f_jugadores_plantillas,"%i",estructura_jugadores_plantillas[i].plantilla_id);
        fprintf(f_jugadores_plantillas, "%s", "\n");
    }
    fclose(f_jugadores_plantillas);

    free(estructura_jugadores_plantillas);

}

void mostrar_configuracion(){

    printf("El numero maximo de equipos es: %i \n",estructura_config.max_equipos);
    printf("El presupuesto por defecto es: %i \n",estructura_config.presupuesto_defecto);
    printf("El numero maximo de futbolistas por plantilla es: %i \n",estructura_config.max_futbolistas_plantilla);
    printf("El numero maximo de plantillas por participantes: %i \n",estructura_config.max_plantillas_participante);
    printf("El numero maximo de futbolistas es: %i \n",estructura_config.max_futbolistas);
}

void mostrar_futbolistas(){

    int i;
    for(i=0 ;i<=sizeof(estructura_futbolistas);i++){

        printf("%i,",estructura_futbolistas[i].futbolista_id);
        printf("%i,",estructura_futbolistas[i].equipo_id);
        printf("%s,",estructura_futbolistas[i].nombre_futbolista);
        printf("%i,",estructura_futbolistas[i].futbolista_precio);
        printf("%i\n",estructura_futbolistas[i].valoracion);
    }
}

void mostrar_equipos(){

    int i;
    for(i=0 ; i<=sizeof(estructura_equipos);i++){

        printf("%i,",estructura_equipos[i].equipo_id);
        printf("%s\n",estructura_equipos[i].nombre_equipo);
    }
}

void mostrar_usuarios(){

    int i;

    for(i=0 ; i<=sizeof(estructura_usuarios) ; i++){

        printf("%i,",estructura_usuarios[i].usuario_id);
        printf("%s,",estructura_usuarios[i].nombre_usuario);
        printf("%s,",estructura_usuarios[i].usuario_perfil);
        printf("%s,",estructura_usuarios[i].usuario_nick);
        printf("%s \n",estructura_usuarios[i].usuario_password);

    }

}

void mostrar_plantillas(){

    int i;

    for(i=0 ; i<=sizeof(estructura_plantillas) ; i++){

        printf("%i,",estructura_plantillas[i].usuario_id);
        printf("%i,",estructura_plantillas[i].plantilla_id);
        printf("%s,",estructura_plantillas[i].nombre_plantilla);
        printf("%i,",estructura_plantillas[i].presupuesto_disp);
        printf("%i \n",estructura_plantillas[i].puntuacion_acum);

    }

}

void mostrar_jugadores_plantillas(){

    int i ;

    for(i=0 ; i<sizeof(estructura_jugadores_plantillas) ; i++ ){

        printf("%i,",estructura_jugadores_plantillas[i].jugador_platilla_id);
        printf("%i \n",estructura_jugadores_plantillas[i].plantilla_id);
    }

}

#endif //PROYECTO_CORE_H    // Si no hay + codigo abajo lo acaba

