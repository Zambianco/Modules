cmake_minimum_required(VERSION 3.10)

project(ErrorHandler)

# Versão do C++ (C++17)
set(CMAKE_CXX_STANDARD 17)

# Suporte ao Qt6
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(ErrorHandler SHARED
    src/ErrorHandler.cpp
    src/ErrorDialog.cpp
)

# Incluir diretórios para Qt6 e nlohmann/json
target_include_directories(ErrorHandler PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Qt6Core_INCLUDE_DIRS}     # Para Qt6
    ${Qt6Widgets_INCLUDE_DIRS}  # Para Qt6
    ${CMAKE_CURRENT_SOURCE_DIR}/include/nlohmann  # Para nlohmann/json (se não usar find_package)
)

# Vincular as bibliotecas
target_link_libraries(ErrorHandler 
    Qt6::Core
    Qt6::Widgets
)

# Diretório de saída para a DLL
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/libs)

# Configuração para exportar funções no Windows (se necessário)
if(WIN32)
    target_compile_definitions(ErrorHandler PUBLIC BUILD_DLL)
endif()
