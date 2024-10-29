#include <iostream>
#include "indice.h"

int main(){
    Indice indice;
    std::vector<std::string> arquivos;
    for(int i=1; i<4;i++){
        std::string arquivo = "d" + std::to_string(i) + ".txt";
        arquivos.push_back(arquivo);
    }
    indice.LerArquivos(arquivos);
}