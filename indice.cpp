#include "indice.h"
#include <sstream>
#include <fstream>
#include <cctype>
#include <algorithm>


void Indice::AdicionarPalavra(std::string palavra, std::string nomeArquivo){
    indice_[palavra][nomeArquivo]++;
}

void Indice::MostrarResultados(std::string palavra){
    if(indice_.find(palavra)==indice_.end()){
        std::cerr<<"Erro ao encontrar palavra: "<<palavra<<std::endl;
        return;
    }
    std::vector<std::pair<std::string, int>> docs(indice_[palavra].begin(),indice_[palavra].end());
    std::sort(docs.begin(), docs.end(), [](const auto& a, const auto& b){return a.second > b.second;});
    for(auto it=docs.begin(); it!=docs.end(); it++){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
}

void Indice::LerArquivos(const std::vector<std::string>& arquivos, std::string palavra){
    for(const auto& arquivo : arquivos){
        std::ifstream inFile(arquivo);
        if(!inFile){
            std::cerr<<"Erro ao abrir arquivo: "<< arquivo<<std::endl;
        }
        std::string linha;
        while(std::getline(inFile, linha)){
            ProcessarLinha(linha, arquivo, palavra);
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
