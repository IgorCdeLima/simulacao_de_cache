#include "ReaderArquive.h"


ReaderArquive::ReaderArquive()
{
}

ReaderArquive::~ReaderArquive()
{
    MemSecundaria.clear();

}

void ReaderArquive::readArquive()
{

    try
    {

        openArquive();
        std::string linha;

        MemSecundaria.clear();
        arquive.clear();
        arquive.seekg(0);

        LineInArquive AddressAndOperation;
        

        while(std::getline(arquive, linha))
        {
            AddressAndOperation = tools.split(linha);
            MemSecundaria.push_back(AddressAndOperation);
        }
        SizeMemoriaSecundaria = MemSecundaria.size();
    }
    catch(const std::exception& e)
    {
        std::cerr 
        << e.what() 
        << '\n'
        << std::endl;
    }
    closeArquive();
}

void ReaderArquive::openArquive()
{
    arquive.open(nameArquive, std::ios::in);
    if(!arquive.is_open())
    {
        throw std::runtime_error("Error opening file");
    }
}

void ReaderArquive::closeArquive()
{
    if(!arquive.is_open()) return;
    arquive.close();
}

LineInArquive ReaderArquive::getMemSecundaria(int posLine)
{
    if(posLine >= MemSecundaria.size() || posLine < 0)
    {
        throw std::out_of_range("Position out of range");
    }

    return MemSecundaria[posLine];
}

void ReaderArquive::defineNameArquive(std::string name)
{
    nameArquive = name;
}