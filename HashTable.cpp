#include "HashTable.h"
#include <iostream>
#include <cstring>

HashTable::HashTable(unsigned int size)
    : size_(size)
{
    pessoas_  = nullptr;
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
    std::cout << "opa\n";
    delete[] pessoas_;
    delete[] data;
}

void HashTable::insert(std::string palavra)
{
    unsigned int h = hash(palavra);
    data[h].push_back(palavra);
}

HashTable::Node::~Node()
{
    delete info;
}

unsigned int HashTable::hash(std::string palavra)
{
    return (palavra.size()-1) + ((tolower(palavra.front())-97) * 20);
}

void HashTable::remove(std::string cpf)
{
    unsigned int h = hash(cpf);
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
}

bool HashTable::getByPalavra(std::string palavra)
{   
    unsigned int h = hash(palavra);

    if (!data[h].search(palavra)) {
        return false;
    }

    return true;
}