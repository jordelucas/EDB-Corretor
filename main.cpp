
#include <iostream>
#include <fstream>
#include <string>         
#include <algorithm>     
#include <chrono>     

#include "HashTable.h"
#include "funcoesUteis.cpp"
#include "Queue.h"
#include "levenshtein.h"

//auto inicio = std::chrono::high_resolution_clock::now();

int main(int argc, char const *argv[]){

    HashTable tableDicionario(2080);
    std::ifstream arq_Dicionario("arquivos/dicionario.txt");
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

    Node<std::string> *str1 = tableDicionario.getByList(*filaTexto.peek());
    int diference = 0;
    int qtd = 0; 

    std::string * str2;
    while(true){
        str2 = filaTexto.peek();
        do{
            diference = levenshtein(*str2, str1->info);
            if(str1->next == nullptr){
                break;
            }
            str1 = str1->next;
            //std::cout << *list.front() <<  "\n";
        }while(diference != 1);
        std::cout << "\n";
        std::cout << str1->info << " - " << *str2 << ": " << diference << "\n";
        if(filaTexto.size() == 1){
            break;
        }
        filaTexto.pop_front();
        str1 = tableDicionario.getByList(*filaTexto.peek());
        qtd++;
    }
 
    //tableDicionario.tamanho();
    std::cout << qtdd << "\n";

    //auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    //long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(resultado).count();

    //std::cout << microseconds;

    return 0;
}