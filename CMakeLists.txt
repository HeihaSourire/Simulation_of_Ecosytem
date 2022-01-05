cmake_minimum_required(VERSION 3.20)
project(Simulation_ecosystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulation_ecosystem main.cpp Aquarium.cpp Milieu.cpp Bestiole.cpp Factory.cpp  Configuration.cpp
        Capteur/Capteur.cpp Capteur/Yeux.cpp Capteur/Oreilles.cpp
        Comportement/Comportement.cpp Comportement/Gregaire.cpp Comportement/Kamikaze.cpp Comportement/Peureuse.cpp Comportement/Prevoyante.cpp
        Accessoire/Accessoire.cpp Accessoire/Camouflage.cpp Accessoire/Carapace.cpp Accessoire/Nageoires.cpp)

find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})
target_link_libraries(Simulation_ecosystem ${X11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})