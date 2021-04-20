#Makefile para la ejecucion del programa completo
#Requerimientos: #mingw32-make instalados
#FUNCIONAMIENTO
#Construcción del ejecutable: mingw32-make -f makefile main
#Limpiar .o y .exe: mingw32-make -f makefile clean

RM = del			#variable limpiar
CC = gcc			#compilador
CFLAGS = -Wall -g   #flags del compilador: WALL-> advertencias del compilador -G: genera información del debugger
EXE = main.exe      #ejecutable/s
OBJS = main.o core.o admin.o login.o cronista.o participantes.o	#objetos

main: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c librerias/core.h librerias/admin.h librerias/login.h librerias/cronista.h librerias/participantes.h
	$(CC) $(CFLAGS) -c $<

core.o : core.c librerias/core.h
	$(CC) $(CFLAGS) -c $<

admin.o: admin.c librerias/admin.h librerias/core.h
	$(CC) $(CFLAGS) -c $<

login.o : login.c librerias/login.h librerias/core.h
	$(CC) $(CFLAGS) -c $<

cronista.o : cronista.c librerias/cronista.h librerias/core.h
	$(CC) $(CFLAGS) -c $<

participantes.o : participantes.c librerias/participantes.h librerias/core.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(EXE) $(OBJS)
