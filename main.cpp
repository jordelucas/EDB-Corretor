#include <iostream>
#include <fstream>
#include <string>         
#include <algorithm>     

#include "funcoesUteis.h"
#include "HashTable.h"
#include "Queue.h"
#include "Pessoa.h"

int main(int argc, char const *argv[]){

    HashTable tableDicionario(520);
    std::ifstream arq_Dicionario("dicionario.txt");
    if (arq_Dicionario.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }
    std::string palavra;
    while(arq_Dicionario >> palavra){
        if(tamanhoMinimo(palavra)){
            tableDicionario.insert(palavra);
        }
    }
    arq_Dicionario.close();

    Queue<std::string> filaTexto;
    std::ifstream arq_Texto("arquivos/imd.txt");
    if (arq_Texto.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }
    int qtdd = 0;
    while(arq_Texto >> palavra){

        if(palavraAcentuada(palavra) && palavra.size() == 3){
            continue;
        }

        if(tamanhoMinimo(palavra)){      
            std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
            palavra = removeChar(palavra);
            if(tamanhoMinimo(palavra)){
                if(tableDicionario.getByPalavra(palavra) == false){
                    qtdd++;
                    std::cout << palavra << "\n";
                    filaTexto.push_back(palavra);
                }
            }
        }
    }
    arq_Texto.close();

    //tableDicionario.tamanho();
    //std::cout << qtdd << "\n";

    return 0;
}