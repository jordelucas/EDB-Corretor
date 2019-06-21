#include <iostream>
#include <fstream>
#include <string>         
#include <algorithm>     

#include "HashTable.h"
#include "Pessoa.h"

int main(int argc, char const *argv[])
{
    HashTable tableDicionario(520);

    std::ifstream arq_Dicionario("dicionario.txt");
    if (arq_Dicionario.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }

    std::string palavra;
    while(arq_Dicionario >> palavra){
        if(palavra.size() >= 3){
            tableDicionario.insert(palavra);
        }
    }
    arq_Dicionario.close();

    //tableDicionario.getByPalavra("instituto");

    HashTable tableTexto(100);

    std::ifstream arq_Texto("imd.txt");
    if (arq_Texto.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }
    
    std::cout << "vai comecar a percorrer o texto\n";
    while(arq_Texto >> palavra){
        if(palavra.size() >= 3){
            std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
            if(tableDicionario.getByPalavra(palavra) == false){
                tableTexto.insert(palavra);
            }
        }else{
            std::cout << "nao considera\n";
        }
    }
    arq_Texto.close();
  
    /*Pessoa * pessoaPtr = table.getByCpf(
        "01923839282"
    );

    if (pessoaPtr) {
        std::cout << pessoaPtr->nome << std::endl;
    } */

    
    return 0;
}