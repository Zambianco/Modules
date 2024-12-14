cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(ModuleError VERSION 1.0)

# Define o tipo de build como DLL
add_library(ModuleError SHARED
    moduleerror.cpp
)

# Inclui os diretórios necessários
target_include_directories(ModuleError PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}           # Diretório atual (onde o CMakeLists.txt está)
    ${CMAKE_CURRENT_SOURCE_DIR}/include   # Diretório 'include' para os headers, se houver
)

# Define as flags de compilação
target_compile_options(ModuleError PUBLIC
    -std=c++17
)

# Especifica o nome da DLL
set_target_properties(ModuleError PROPERTIES
    OUTPUT_NAME "moduleerror"   # Nome da DLL gerada
)

# Especifica propriedades da DLL (remover prefixo 'lib' em sistemas Unix)
set_target_properties(ModuleError PROPERTIES PREFIX "")

# Se você estiver usando o MinGW no Windows, você pode precisar garantir que o GCC esteja configurado corretamente.
# CMake geralmente detecta automaticamente, mas você pode configurar isso manualmente, se necessário:
if(MINGW)
    message(STATUS "Usando MinGW para compilação")
endif()