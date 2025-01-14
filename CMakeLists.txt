cmake_minimum_required(VERSION 3.10)

# Proiectul
project(CalatoriaCafelei)

# Standardul C++ utilizat
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adaugă toate fișierele sursă
file(GLOB SOURCES "Source Code/*.cpp")

# Include directoarele de header
include_directories(Header)

# Crează executabilul
add_executable(CalatoriaCafelei ${SOURCES})
# cmake_minimum_required(VERSION 3.10)

# # Proiect simplu
# project(TestProject)

# # Setează standardul C++
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Adaugă un fișier sursă principal (Main.cpp)
# add_executable(TestProject "Source Code/Main.cpp")
