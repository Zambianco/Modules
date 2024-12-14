# Instruções para Compilação

Para compilar este projeto, siga os passos abaixo:

## Pré-requisitos

1. **MinGW**: Certifique-se de ter o MinGW instalado em sua máquina.
2. **CMake**: Baixe e instale o [CMake](https://cmake.org/download/).

Além disso, é necessário incluir a biblioteca `nlohmann/json` no diretório `include` do seu projeto.

## Passos para Compilação

1. Coloque o arquivo `json.hpp` da biblioteca `nlohmann/json` na pasta `include` do seu projeto. Você pode baixar o arquivo diretamente do [repositório oficial do GitHub](https://github.com/nlohmann/json).

2. Execute os seguintes comandos para gerar e compilar o projeto:

   Abra o terminal na raiz do projeto e execute:

   ```sh
   cmake -G "MinGW Makefiles" .
   cmake --build .
