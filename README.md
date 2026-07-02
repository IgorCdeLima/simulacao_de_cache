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
   
    *linux:*: ./simula_cache

obs: pode ser necessário autorizar a execução do aplicativo para linux ou MacOs
<img width="838" height="614" alt="WhatsApp Image 2026-07-02 at 15 50 57" src="https://github.com/user-attachments/assets/cf85adde-ef86-4e52-b1b3-b2ec7d70d64e" />


4. Informações para a execução 


*comando*
´simula_cache 0 64 4096 2  4 LRU 60´

São necessário 7 informações para o aplicativo ser executado, sendo elas:

Política de escrita: 0 - write-through e 1 - write-back;
Tamanho da linha: deve ser potência de 2, em bytes;
Número de linhas: deve ser potência de 2;
Associatividade (número de linhas) por conjunto: deve ser potência de 2 (mínimo 1 e máximo igual ao número de linhas);
Tempo de acesso quando encontra (hit time): em nanossegundos;
Política de Substituição: LRU (Least Recently Used) ou Aleatória;
Tempos de leitura/escrita: em nanossegundos.






