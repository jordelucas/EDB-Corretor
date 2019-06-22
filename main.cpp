
#include <iostream>
#include <fstream>
#include <string>         
#include <algorithm>     
#include <chrono>     

#include "HashTable.h"
#include "funcoesUteis.cpp"
#include "Queue.h"

//auto inicio = std::chrono::high_resolution_clock::now();

int main(int argc, char const *argv[]){

    HashTable tableDicionario(2080);
    std::ifstream arq_Dicionario("dicionario.txt");
    if (arq_Dicionario.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }
    std::string palavra;
    while(arq_Dicionario >> palavra){
        if(palavra.size() >= 3){
            //std::cout << palavra << " ";
            tableDicionario.insert(palavra);
        }
    }
    arq_Dicionario.close();

    Queue<std::string> filaTexto;
    std::ifstream arq_Texto("arquivos/ufrn.txt");
    if (arq_Texto.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }
    int qtdd = 0;
    while(arq_Texto >> palavra){
        if(acentoInicio(palavra) && palavra.size() == 3){
            continue;
        }
        if(tamanhoMinimo(palavra)){
            std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
            palavra = removeChar(palavra);
            if(tamanhoMinimo(palavra)){
                //std::cout << palavra << "\n";
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
    std::cout << qtdd << "\n";

    //auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    //long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

    //std::cout << microseconds;


    return 0;
}