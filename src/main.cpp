#include "commandLine.h"

commandLine& lineOfCommandTratament = commandLine::getInstance();

int main(int argc, char *argv[]){
    lineOfCommandTratament.argumentsForClass(argc, argv);
    return 0;
}