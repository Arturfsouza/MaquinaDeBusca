#include <iostream>
#include "indice.h"

int main(){
    std::cout<<"Digite a palavra que voce quer procurar"<<std::endl;
    std::string palavra;
    std::cin>>palavra;
    Indice indice;
    palavra = indice.NormalizarPalavra(palavra);
    std::vector<std::string> arquivos;
    for(int i=1; i<4;i++){
        std::string arquivo = "documentos_testes/d" + std::to_string(i) + ".txt";
        arquivos.push_back(arquivo);
    }
    indice.LerArquivos(arquivos, palavra);
    indice.MostrarResultados(palavra);
    return 0;
}

//funcao processar linha e ler arquivos esta recebendo o parametreo palavra, que eh a palavra a ser procurada, mas isso nao faz muito sentido ser parametro dessas funcoes
//nomes de variaveis estao pouco descritivas e um pouco confusas dentro das funcoes, alem de as vezes repetidas em diferentes parte do codigo de maneira confusa
//implementar funcao para mostrar os resultados atraves do que esta no map
//melhorar tratamentos para derrubar a funcao caso necesario