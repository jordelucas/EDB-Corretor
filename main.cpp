#include <iostream>
#include <fstream>

#include "HashTable.h"
#include "Pessoa.h"

int main(int argc, char const *argv[])
{
    HashTable table(520);

    std::ifstream arq_in("dicionario.txt");
    if (arq_in.fail()) {
        std::cout << "Problemas na abertura do arquivo\n";
        return 0;
    }

    std::string palavra;
    while(arq_in >> palavra){
        table.insert(palavra);
    }
    arq_in.close();

    std::string palavrinha = "viciáveis";

    std::string palavraEncontrada = table.getByPalavra(palavrinha);

    std::cout << palavraEncontrada;

    /*Pessoa * pessoaPtr = table.getByCpf(
        "01923839282"
    );

    if (pessoaPtr) {
        std::cout << pessoaPtr->nome << std::endl;
    } */

    
    return 0;
}
