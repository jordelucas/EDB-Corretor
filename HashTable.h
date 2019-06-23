#ifndef HASH_TABLE_H
#define HASH_TABLE_h

#include <string>

#include "DoubleLinkedList.h"

class HashTable {
    public:
        HashTable(unsigned int size);
        ~HashTable();
        unsigned int hash(std::string palavra);
        void insert(std::string palavra);
        //void remove(std::string cpf);
        bool getByPalavra(std::string palavra);
        Node<std::string> * getByList(std::string palavra);
        void tamanho();
    private:
        unsigned int size_;
        DoubleLinkedList<std::string> * data;
};

#endif