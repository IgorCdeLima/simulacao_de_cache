#include <commandLine.h>
#include <stdio.h>

// commandLine::commandLine(/* args */){}

void commandLine::argumentsForClass(int argc, char *argv[]){
    int POSICAO_DE_ARGUMENTO = 0;
    printf("Total de argumentos: %d\n", argc);

    for(POSICAO_DE_ARGUMENTO; POSICAO_DE_ARGUMENTO < argc; POSICAO_DE_ARGUMENTO++ ){
        printf("Argumento %d: %s\n", POSICAO_DE_ARGUMENTO, argv[POSICAO_DE_ARGUMENTO] );
    }
}


commandLine::~commandLine()
{
}
