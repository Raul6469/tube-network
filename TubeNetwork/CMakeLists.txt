# CMakeList.txt : projet CMake pour TubeNetwork, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/TubeNetwork/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/TubeNetwork/*.h)

add_executable (TubeNetwork ${SRC_FILES} ${HEADER_FILES})