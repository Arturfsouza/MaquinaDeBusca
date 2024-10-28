#include <iostream>
#include <map>
#include <cctype>
#include <string>

class Indice {
    public:
        Indice(){}

        void LerArquivos(arquivo){

        }

        void NormalizarPalavra(std::string palavra){
            for(auto it=palavra.begin(); it!=palavra.end(); it++){
                if(!isalpha(*it)){
                    palavra.erase(it);
                }
                if(isupper(*it)){
                    *it = tolower(*it);
                }
            }
        }

        ~Indice(){

        }


    private:
        std::map<std::string,std::map <std::string, int>> indice_;



};