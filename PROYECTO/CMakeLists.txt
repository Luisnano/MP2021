cmake_minimum_required(VERSION 3.17)
project(PROYECTO C)

set(CMAKE_C_STANDARD 99)

add_executable(PROYECTO main.c librerias/admin.h librerias/core.h librerias/participantes.h librerias/cronista.h librerias/login.h)

