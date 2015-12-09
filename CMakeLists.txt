cmake_minimum_required (VERSION 2.6)
#nom du projet
project (Risk)

#ou mettre le output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_executable(Main src/Main.cpp src/Joueur.cpp src/Territoire.cpp src/Pion.cpp src/Frontiere.cpp src/Etat_jeu.cpp src/Moteur_jeu.cpp src/Ia.cpp src/IA_moyen.cpp src/Gestion_tour.cpp)
add_executable(Main2 src2/Action.cpp src2/Attaquer.cpp src2/Controleur_graphique src2/Deplacer.cpp src2/Etape.cpp src2/Etat.cpp src2/Graphique_etape.cpp src2/Graphique_pays.cpp src2/Main.cpp src2/Moteur.cpp src2/Pays.cpp src2/Plateau.cpp src2/Rendu.cpp  src2/Renforcer.cpp)
add_executable(Test divers/Test.cpp)
# SFML 
set(SFML_ROOT "/usr/lsa")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/share/SFML/cmake/Modules"
${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS graphics window system)
if(SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   target_link_libraries(Main ${SFML_LIBRARIES})
   target_link_libraries(Test ${SFML_LIBRARIES})
   target_link_libraries(Main2 ${SFML_LIBRARIES})
endif()

#mettre en c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-std=c++11")

#pour caque terminal, copier la ligne "export LD_LIBRARY_PATH="
