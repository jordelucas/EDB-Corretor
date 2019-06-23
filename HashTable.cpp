#include "HashTable.h"
#include <iostream>
#include <cstring>

int valueVogais(std::string palavra){
    int pontos = 0;
    for(int i = 0; i < palavra.length(); i++){
        switch (palavra[i]){
        case 'a':
            pontos+=1;
            break;
        case 'e':
            pontos+=2;
            break;
        case 'i':
            pontos+=3;
            break;
        case 'o':
            pontos+=4;
            break;
        case 'u':
            pontos+=5;
            break;                                            
        default:
            break;
        }
    }
    if(pontos == 0){
        return 0;
    }else if (pontos >=1 && pontos <= 4) {
        return 1;
    }else if (pontos >=5 && pontos <= 8) {
        return 2;
    }else if (pontos >=9) {
        return 3;
    }
    return 0;
}

int sizePalavra(std::string palavra){
    int qtdAcentos = 0;
    for(int i = 0; i < palavra.length(); i++){
        if(palavra[i] == -61){
            qtdAcentos++;
        }
    }
    return palavra.size() - qtdAcentos;
}

HashTable::HashTable(unsigned int size)
    : size_(size)
{
    /*for (unsigned int i = 0; i < size; ++i) {
        pessoas_[i] = nullptr;
    }*/
    data = new DoubleLinkedList<std::string>[size];
}

HashTable::~HashTable()
{
/*    for (unsigned int i = 0; i < size_; ++i) {
        Node* current = pessoas_[i];
        while (current != nullptr) {
            Node* tmp = current;
            current   = current->next;
            delete tmp;
        }
    } */
    delete[] data;
}

void HashTable::insert(std::string palavra)
{

    if(palavra.front() == -61){
        data[size_-1].push_back(palavra);    
        return;
    }

    unsigned int h = hash(palavra);
    palavra[0] = tolower(palavra.front());
    data[h].push_back(palavra);
}

unsigned int HashTable::hash(std::string palavra)
{
    int valueAscii = tolower(palavra.front())-97;   /*Modifica a primeira letra para minúsculo e 
                                                    subtrai valor correspondente na tabela ascii, 
                                                    indo agora de 0 à 25*/
    int palavraSize = sizePalavra(palavra)-1;             /*Determina a quantidade de letras e em qual
                                                    lista para aquela inicial a palavra deve ficar */
    int pontosVogais = valueVogais(palavra);        /*Verifica quantas vogais tem a palavra e qual 
                                                    pontuacao ela recebe*/
    //std::cout << pontosVogais << "\n"; 
    int h = (palavraSize*4) + pontosVogais + (valueAscii * 80);        /*Garante 80 listas para cada inicial,
                                                                        sendo 20 divisões referente a quantidade
                                                                        de letras com 4 possibilidade cada de 
                                                                        pontuação recebida pelas vogais*/
    return h;
}

/*unsigned int h = hash(cpf);
void HashTable::remove(std::string cpf)
{
    h = h % size_;

    if (!pessoas_[h]) {
        return;
    }

    Node* current = pessoas_[h];

    //se for o elemento cabeça
    if (current->info->cpf == cpf) {
        Node* next = current->next;
        delete current;
        pessoas_[h] = next;
        return;
    }

    Node* prev = current;
    current    = current->next;

    while (current != nullptr && 
           current->info->cpf != cpf) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return;
    }

    prev->next = current->next;
    delete current;
} */

bool HashTable::getByPalavra(std::string palavra) {   
    if(palavra.front() == -61){
        if (!data[size_-1].search(palavra)) {
            return false;
        }
        return true;
    }

    unsigned int h = hash(palavra);

    if (!data[h].search(palavra)) {
        return false;
    }
    return true;
}

DoubleLinkedList<std::string> HashTable::getByList(std::string palavra) {   
    if(palavra.front() == -61){
        return data[size_-1];
    }

    unsigned int h = hash(palavra);
    std::cout << "!!!" << h << "\n";
    return data[h];
}

void HashTable::tamanho(){
    for (int i = 0; i < size_; i++){
        std::cout << data[i].size() << "\n";
    }
}