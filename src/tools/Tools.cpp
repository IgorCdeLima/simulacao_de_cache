#include "Tools.h"




Tools::Tools(/* args */)
{
}

Tools::~Tools()
{
}

std::string Tools::toBinary(uint32_t value, int numberBits)
{
    return std::bitset<32>(value)
        .to_string()
        .substr(32 - numberBits);
}


void Tools::printLine(std::string mensagem, std::string variable)
{
    std::cout 
        << mensagem
        << variable
        << std::endl;
}

void Tools::printHexString(std::string mensagem, uint32_t variable)
{
    std::cout
    << mensagem
    <<"0x"
    << std::hex
    << std::setw(8)
    << std::setfill('0')
    << variable
    << "\n";

}

uint32_t Tools::offsetBitsInterpretation(uint32_t address, int offsetBits)
{
    uint32_t mask  = (1 << offsetBits) -1;
    return  address & mask;
}

uint32_t Tools::setBitsInterpretation(uint32_t address,int offsetBits, int setBits)
{
    uint32_t maskOffset = (address >>offsetBits);
    uint32_t maskSet = (1U << setBits)-1;
    return maskOffset & maskSet;
}

uint32_t Tools::tagBitsInterpretation(uint32_t address, int offsetBits, int setBits)
{
    uint32_t mask = address>>(offsetBits + setBits);
    return mask;
}

void Tools::cabecalho()
{
    std::cout<< "\n\n";
    std::cout
    << "Atualização: 23/06/2026"
    << std::endl;

    std::cout<< "\n\n";

    std::cout
    << "OPERATION"
    << "\t\t"
    << "TAG"
    << "\t\t\t"
    << "SET"
    << "\t\t"
    << "OFFSET"
    <<"\n";

}

void Tools::imprimir(MemoryAccess data,  int tagBits, int setBits, int offsetBits)
{

    std::cout
    << data.operation
    << "\t\t\t"
    << toBinary(data.address.tag, tagBits)
    << "\t"
    << toBinary(data.address.set, setBits)
    << "\t"
    << toBinary(data.address.offset, offsetBits)
    << "\n";


}


void Tools::printTable(simulationCache data)
{
    std::cout
    << "\n\tTABELA 1 - Parametros  da Simulacao\n"
    << "\n\tParâmetro \t\t\tValor"
    << "\n\tTamanho do bloco: \t\t" 
    << data.sizeBlock
    << " bytes"
    << "\n\tPolitica de Escrita: \t\t"
    << data.writePolicy
    << "\n\tAlgoritimo de Substituicao: \t"
    << data.substituitionPolicy
    << "\n\tAssociatividade: \t\t"
    << data.associability
    << " blocos"
    << std::endl;

    std::cout <<std::string(REPET, '-') << std::endl;


    std::cout
    << "\n\tTABELA 2 - Resultado da Simulacao\n"
    << "\n\tNumero de Blocos: \t\t"
    << data.numberOfBlocks
    << "\n\tTaxa de Acerto: \t\t"
    << data.hitRate
    << "%"
    << "\n\tTempo medio de Acesso (ns): \t"
    << data.averageAccessTime
    << "\n\tLeituras na MP: \t\t"
    << data.memoryRead
    << "\n\tEscritas na MP: \t\t"
    << data.memoryWrite
    << "\n\tLeituras na CACHE: \t\t"
    << data.leiturasCache
    << "\n\tEscritas na CACHE: \t\t"
    << data.escritasCache
    << std::endl;

    std::cout
    << std::string(REPET, '-')
    << "\n\tREAD OPERATION: "
    << data.readOperation
    << "\tWRITE OPERATION: "
    << data.writeOperation
    << "\tTOTAL OPERATION: "
    << data.totalOperation
    << std::endl;

}


void Tools::printInformationsInitials(informationsProgram info)
{

    std::cout
    << std::string(REPET, '-')
    << "\n\n\t<entry_policy>:\t\t\t"
    << info.politicaDeEscrita
    <<  ((info.politicaDeEscrita == 1) ? "\t(Write-back)" : "\t(Write-through)")
    << "\n\t<size_line>:\t\t\t"
    << info.tamanhoDoBloco
    << "\n\t<number_of_lines>:\t\t"
    << info.quantidadeDeblocos
    << "\n\t<associability>:\t\t"
    << info.associabilidade
    << "\n\t<access_time_per_hit>:\t\t"
    << info.tempoDeAcessoMedio
    << "\n\t<substituition_policy>:\t\t"
    << info.politicaDeSubstituicao
    << "\n\t<time_to_read_write>:\t\t"
    << info.tempoDeEscritaLeitura
    << "\n\n"
    <<  std::string(REPET, '-')
    << "\n\n\t[1] Number of Sets (quantidade de conjuntos):\t"
    << info.quantidadeDeConjuntos
    << "\n\t[2] Set offSet Bits (Bits da palavra):\t\t"
    << info.bitsPalavra
    << "\n\t[3] Set bits (bits do conjunto):\t\t"
    << info.bitsConjunto
    << "\n\t[4] Tag bits (Bits da Tag):\t\t\t"
    << info.bitsTag
    << "\n\t[5] Total Size to Cache Memory:\t\t\t"
    << info.tamanhoDaCacheString
    << "\n\n"
    << std::string(REPET, '-')
    << std::endl;

}