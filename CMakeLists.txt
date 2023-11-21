cmake_minimum_required(VERSION 3.25)
project(Elaborato_Programazione_Lista_Spesa)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Test)

set(SOURCE_FILES Prodotto.h Prodotto.cpp ListaDellaSpesa.h ListaDellaSpesa.cpp ListaDellaSpesa.cpp Subject.h Observer.h Utente.h Utente.cpp)
add_executable(Elaborato_Programazione_Lista_Spesa main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Elaborato_Programazione_Lista_Spesa core)
