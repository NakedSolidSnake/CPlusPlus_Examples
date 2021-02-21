cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Examples VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(GuessGame ${CMAKE_CURRENT_LIST_DIR}/01-GuessGame/guess_game.cpp)
install(TARGETS GuessGame DESTINATION bin)

add_executable(Calculator ${CMAKE_CURRENT_LIST_DIR}/02-Calculator/main.cpp)
install(TARGETS Calculator DESTINATION bin)

add_executable(Exception ${CMAKE_CURRENT_LIST_DIR}/03-Exception/main.cpp)
install(TARGETS Exception DESTINATION bin)

add_executable(ClassPerson ${CMAKE_CURRENT_LIST_DIR}/04-ClassPerson/main.cpp)
install(TARGETS ClassPerson DESTINATION bin)

add_executable(BattleGame ${CMAKE_CURRENT_LIST_DIR}/05-BattleGame/main.cpp)
install(TARGETS BattleGame DESTINATION bin)


