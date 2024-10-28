#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>


class Indice {
    public:
        Indice(){}

        void LerArquivos(const std::vector<std::string>& arquivos){

        }

        ~Indice(){

        }

    private:

        std::map<std::string,std::map <std::string, int>> indice_;
        void NormalizarPalavra(std::string palavra){

        }

};