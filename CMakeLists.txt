cmake_minimum_required(VERSION 3.24)
project(PPIL)

set(CMAKE_CXX_STANDARD 14)

include_directories(Include)

add_executable(PPIL
        Include/Cercle.h
        Include/Expert.h
        Include/ExpertCor.h
        Include/ExpertCorCercle.h
        Include/ExpertCorPoly.h
        Include/ExpertCorSeg.h
        Include/GroupForm.h
        Include/Polygone.h
        Include/Segment.h
        Include/Shape.h
        Include/Tranforme.h
        Include/Vecteur2D.h
        Include/VisitorSave.h
        Include/VisitorSaveText.h
        src/Cercle.cpp
        src/GroupForm.cpp
        src/main.cpp
        src/Polygone.cpp
        src/Segment.cpp
        src/VisitorSaveText.cpp)
