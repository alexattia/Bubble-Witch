CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
FILE(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
IF(NOT EXISTS "${d}")
    MESSAGE(FATAL_ERROR "Error: environment variable IMAGINEPP_ROOT=" "${d}")
ENDIF(NOT EXISTS "${d}")
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
FIND_PACKAGE(Imagine)

PROJECT(Bubble)
add_executable(Bubble
        Balle.cpp
	Balle.h
        Jeu.cpp
        Tir.cpp
	Tir.h
        Vector.cpp
	Vector.h
	Affichage.cpp
	Affichage.h)
ImagineUseModules(Bubble Graphics)
