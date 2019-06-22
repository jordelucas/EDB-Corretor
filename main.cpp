#include <iostream>
#include <fstream>
#include <string>         
#include <algorithm>     

#include "HashTable.h"
#include "Queue.h"
#include "Pessoa.h"

std::string removeChar(std::string palavra);
bool tamanhoMinimo(std::string palavra);
bool palavraAcentuada(std::string palavra);

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

std::string removeChar(std::string palavra) {
    while((palavra.front() < 97 && palavraAcentuada(palavra) == false) || palavra.front() > 122 || palavra.back() < 97 || palavra.back() > 122){
        if(tamanhoMinimo(palavra)){
            if((palavra.front() < 97 && palavraAcentuada(palavra) == false) || palavra.front() > 122) {
                palavra.erase(palavra.begin());
            }
            if(palavra.back() < 97 || palavra.back() > 122) {
                palavra.pop_back();
            }
        }else{
            return palavra;
        }
    }
    return palavra;
}

bool tamanhoMinimo(std::string palavra){
    return palavra.size() >= 3;
}

bool palavraAcentuada(std::string palavra){
    return palavra.front() == -61;
}