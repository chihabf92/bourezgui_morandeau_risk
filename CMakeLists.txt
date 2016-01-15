cmake_minimum_required (VERSION 2.6)
#nom du projet
project (Risk)

#ou mettre le output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_executable(Main src/Main.cpp src/Joueur.cpp src/Territoire.cpp src/Pion.cpp src/Frontiere.cpp src/Etat_jeu.cpp src/Moteur_jeu.cpp src/Ia.cpp src/IA_moyen.cpp src/Gestion_tour.cpp)
add_executable(Main2 src2/Action.cpp  src2/Controleur_graphique  src2/Etape.cpp src2/Etat.cpp src2/Graphique_etape.cpp src2/Graphique_pays.cpp src2/Main.cpp src2/Moteur.cpp src2/Pays.cpp src2/Plateau.cpp src2/Rendu.cpp)
add_executable(MainServeur src2/Serveur/main.cpp src2/Serveur/AbstractService.cpp src2/Serveur/Commande.cpp src2/Serveur/CommandeDB.cpp src2/Serveur/CommandeService.cpp src2/Serveur/ServiceException.cpp src2/Serveur/ServicesManager.cpp src2/Serveur/VersionService.cpp)
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
   target_link_libraries(MainServeur ${SFML_LIBRARIES})
endif()

#mettre en c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

#pour chaque terminal, copier la ligne "export LD_LIBRARY_PATH="

# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# libmicrohttpd
include_directories ("${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/include")
target_link_libraries(MainServeur "${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/lib/libmicrohttpd.so")
target_link_libraries(Main2 "${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/lib/libmicrohttpd.so")
