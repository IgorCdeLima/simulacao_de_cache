**SIMULA CACHE**

Aplicação em C++ para simular leituras e entradas de uma memória Cache

Foi utilizado o FrameWork do CMake para a compilação dos arquivos
Para tal é necessário instalar o CMake na máquina para compilar os dados 
o download pode ser encontrado em: https://cmake.org/   na aba de Downloads



Ao instalar o CMake devemos estar na pasta raiz do projeto, ao qual tem o arquivo CMakeLists.txt
rode os seguintes comandos

1. Cria  a pasta build ao qual tem os dados para a compilação
`
cmake -B build
`
2. Compile os arquivos 
`
cmake --build  build
`
3. O Arquivo compilado pode ser encontrado em:
    
    *windows*: .\simula_cache.exe
    *linux:*: .\simula_cache


