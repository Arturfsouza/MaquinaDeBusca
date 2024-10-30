#ifndef INDICE_H
#define INDICE_H


#include <iostream>
#include <map>
#include <string>
#include <vector>



class Indice {
    public:
        Indice(){}
        void LerArquivos(const std::vector<std::string>& arquivos, std::string palavra);
        void AdicionarPalavra(std::string palavra, std::string nomeArquivo);
        void MostrarResultados(std::string palavra);
        std::string NormalizarPalavra(std::string& palavra);
        ~Indice(){}

    private:

        void ProcessarLinha(const std::string& linha, const std::string& nomeArquivo, std::string palavra);
        std::map<std::string,std::map <std::string, int>> indice_;
};

#endif