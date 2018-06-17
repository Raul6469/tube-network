# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("TubeNetwork")

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

# Ajoutez une source à l'exécutable de ce projet.
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/TubeNetwork/*.cpp ${PROJECT_SOURCE_DIR}/TubeNetwork/network/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/TubeNetwork/network/*.h)

add_executable (TubeNetwork ${SRC_FILES} ${HEADER_FILES})