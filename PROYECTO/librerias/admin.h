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

#endif //PROYECTO_ADMIN_H
