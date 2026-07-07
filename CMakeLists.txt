cmake_minimum_required(VERSION 3.23)

project(MDL) #nome do projeto

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #faz criar o compile_commands para o clang identificar 
                                      #as lib baixadas
include(FetchContent) #bota o FetchContent para baixar os trem 

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG 79524ddd08a4ec981b7fea76afd08ee05f83755d #v1.17.0
  FIND_PACKAGE_ARGS NAMES spdlog #checa no pc antes se tem o spdlog builded ja
)

FetchContent_MakeAvailable(spdlog)


add_executable(mdl main.cpp)

target_link_libraries(mdl PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>) #nao entendi pq esse trem feio mas tava no github dos cara
