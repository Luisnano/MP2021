OBJS = main.o core.o admin.o login.o cronista.o participantes.o
EXES = main

main: main.o core.o admin.o login.o cronista.o participantes.o
	gcc $^ -o $@
	./main

main.o: main.c librerias/core.h librerias/admin.h librerias/login.h librerias/cronista.h librerias/participantes.h
	gcc $< -o $@

core.o : core.c librerias/core.h
	gcc $< -o $@

admin.o: admin.c librerias/admin.h librerias/core.h
	gcc $< -o $@

login.o : login.c librerias/login.h librerias/core.h
	gcc $< -o $@

cronista.o : cronista.c librerias/cronista.h librerias/core.h
	gcc $< -o $@

participantes.o : participantes.c librerias/participantes.h librerias/core.h
	gcc $< -o $@

clean:
	$(RM) $(OBJS) $(EXES)
