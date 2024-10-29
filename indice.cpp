#include "indice.h"
#include <sstream>
#include <fstream>
#include <cctype>


void Indice::AdicionarPalavra(std::string palavra, std::string nomeArquivo){
    indice_[palavra][nomeArquivo]++;
}


void Indice::LerArquivos(const std::vector<std::string>& arquivos, std::string palavra){
    for(const auto& arquivo : arquivos){
        std::ifstream inFile(arquivo);
        if(!inFile){
            std::cerr<<"Erro ao abrir arquivo: "<< arquivo<<std::endl;
        }
        std::string linha;
        while(std::getline(inFile, linha)){
            ProcessarLinha(linha, arquivo);
        }
        inFile.close();
    }
}

std::string Indice::NormalizarPalavra(std::string& palavra){
    auto it = palavra.begin();
    while(it != palavra.end()){
        if(!isalpha(*it)){
            palavra.erase(it);
        }
        else{
            if(isupper(*it)){
                *it = tolower(*it);}
            it++;
        }
    }
    return palavra;
}

void Indice::ProcessarLinha(const std::string& linha, const std::string& nomeArquivo, std::string palavra){
    std::istringstream stream(linha);
    std::string p;
    while(stream>>p){
        p = NormalizarPalavra(p);
        if(p == palavra){
            AdicionarPalavra(p, nomeArquivo);
        }
    }
}
