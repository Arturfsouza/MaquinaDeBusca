#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


class Indice {
    public:
        Indice(){}

        void LerArquivos(const std::vector<std::string>& arquivos){

        }

        void AdicionarPalavra(std::string palavra, std::string nomeArquivo){
    
        }   

        ~Indice(){

        }

    private:

        void ProcessarLinha(const std::string& linha, const std::string& nomeArquivo){

        }

        std::map<std::string,std::map <std::string, int>> indice_;
        std::string NormalizarPalavra(std::string palavra){

        }

};