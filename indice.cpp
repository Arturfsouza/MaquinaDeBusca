#include "indice.h"

Indice::Indice(){

}

void Indice::AdicionarPalavra(std::string palavra, std::string nomeArquivo){
    indice_[palavra][nomeArquivo]++;
}


void Indice::LerArquivos(const std::vector<std::string>& arquivos){
    for(const auto& arquivo : arquivos){
        std::ifstream inFile(arquivo);
        if(!inFile){
            std::cerr<<"Erro ao abrir arquivo: "<< arquivo<<std::endl;
        }
    }
}

std::string Indice::NormalizarPalavra(std::string palavra){
    for(auto it=palavra.begin(); it!=palavra.end(); it++){
        if(!isalpha(*it)){
            palavra.erase(it);
        }
        if(isupper(*it)){
            *it = tolower(*it);
        }
    }
    return palavra;
}

void Indice::ProcessarLinha(const std::string& linha, const std::string& nomeArquivo){
    std::istringstream stream(linha);
    std::string palavra;
    while(stream>>palavra){
        palavra = NormalizarPalavra(palavra);
        if(!palavra.empty()){
            AdicionarPalavra(palavra, nomeArquivo);
        }
    }
}

Indice::~Indice(){

}