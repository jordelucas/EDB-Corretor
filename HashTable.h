#ifndef HASH_TABLE_H
#define HASH_TABLE_h

#include <string>
#include "DoubleLinkedList.h"
#include "Pessoa.h"


class HashTable
{
    public:
        HashTable(unsigned int size);
        ~HashTable();
        unsigned int hash(std::string palavra);
        void insert(std::string palavra);
        void remove(std::string cpf);
        bool getByPalavra(std::string palavra);

    private:
        unsigned int size_;
        struct Node 
        {
            ~Node();
            Pessoa* info;
            Node* next;
        };

        Node** pessoas_;
        DoubleLinkedList<std::string> * data;
};

#endif