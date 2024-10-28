#include "indice.h"

Indice::Indice(){

}

void Indice::LerArquivos(const std::vector<std::string>& arquivos){
    for(const auto& arquivo : arquivos){
        std::ifstream inFile(arquivo);
        if(!inFile){
            std::cerr<<"Erro ao abrir arquivo: "<< arquivo<<std::endl;
        }
    }
}

void Indice::NormalizarPalavra(std::string palavra){
    for(auto it=palavra.begin(); it!=palavra.end(); it++){
        if(!isalpha(*it)){
            palavra.erase(it);
        }
        if(isupper(*it)){
            *it = tolower(*it);
        }
    }
}

Indice::~Indice(){

}