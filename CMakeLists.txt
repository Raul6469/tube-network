# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("TubeNetwork")

# Incluez les sous-projets.
add_subdirectory ("TubeNetwork")

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
