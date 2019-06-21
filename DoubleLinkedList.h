#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>

template<typename Item>
struct Node
{
    Node();
    Item info;
    
    Node<Item> *next;
    Node<Item> *prev;
};

template<typename Item>
class DoubleLinkedList
{
private:
    Node<Item>* head_;
    Node<Item>* last_;

public:
    DoubleLinkedList();
    void push_back(Item item);
    void push_front(Item item);
    bool empty();

    void pop_back();
    void pop_front();
    void clear();

    Item* front();
    Item* back();
    size_t size();
    Node<Item>* search(Item i);
    void invert();
    void traverse(void(*callback)(Item&));
    void traverseReverse(void (*callback)(Item&));

}; 

template<typename Item>
Node<Item>::Node() : next(nullptr), prev(nullptr) {}

template<typename Item>
DoubleLinkedList<Item>::DoubleLinkedList() : head_(nullptr), last_(nullptr) {
}

template<typename Item>
void DoubleLinkedList<Item>::push_back(Item item){
    Node<Item> *new_node      = new Node<Item>();
    new_node->info = item;

    if (head_==nullptr&&last_==nullptr){
        head_ = new_node;
        last_ = new_node;
        return;
    }
    
    last_->next    = new_node;
    new_node->prev = last_;
    last_ = new_node;

}

template<typename Item>
void DoubleLinkedList<Item>::push_front(Item item){
    Node<Item> *new_node = new Node<Item>();
    new_node->info = item;
    
    if (head_==nullptr&&last_==nullptr){
        head_ = new_node;
        last_ = new_node;
        return;
    }

    head_->prev    = new_node;
    new_node->next = head_;
    head_          = new_node;
    

}

template<typename Item>
bool DoubleLinkedList<Item>::empty(){
    return head_ == nullptr && last_ == nullptr;
}

template<typename Item>
void DoubleLinkedList<Item>::pop_back(){
    if (head_==nullptr&&last_==nullptr){
        return;
    }
    Node<Item> *tmp = last_;
    last_ = last_->prev;
    last_->next = nullptr;
    delete tmp;

}

template<typename Item>
void DoubleLinkedList<Item>::pop_front(){
    if (head_==nullptr&&last_==nullptr){
        return;
    }
    Node<Item> *tmp = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete tmp;

}

template<typename Item>
void DoubleLinkedList<Item>::clear(){
    if (head_==nullptr&&last_==nullptr){
        return;
    }
    while (head_->next!=nullptr)
    {
        pop_front();
    }

    delete head_;
    head_ = nullptr;
    last_ = nullptr;
}

template<typename Item>
Item* DoubleLinkedList<Item>::front(){
     if (head_==nullptr&&last_==nullptr){
        return nullptr;
        }
     return &head_->info;
}

template<typename Item>
Item* DoubleLinkedList<Item>::back(){
    if (head_==nullptr&&last_==nullptr){
        return nullptr;
    }
    return &last_->info;
}

template<typename Item>
size_t DoubleLinkedList<Item>::size(){
    Node<Item> *current = head_;
    size_t qtty = 0;

    while(current!=nullptr){
        Node<Item> *tmp = current->next;
        current = tmp;
        qtty++;
    }
    return qtty;
}

template<typename Item>
Node<Item>* DoubleLinkedList<Item>::search(Item i){
    Node<Item>* current = head_;
    while (current!=nullptr&&current->info!=i)
    {
        if (current==nullptr)
        {
            return nullptr;
        }
        
        Node<Item> *tmp    = current->next;
             current = tmp;
    }
    return current;
}

template<typename Item>
void DoubleLinkedList<Item>::invert(){
    Node<Item> *current = head_;
    Node<Item> *tmp = nullptr;
    while (current!=nullptr)
    {
        tmp           = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current       = current->prev;
    }
    
    tmp = last_;
    last_ = head_;
    head_ = tmp;
}

template<typename Item>
void DoubleLinkedList<Item>::traverse(void(*callback)(Item&)){
    Node<Item> *current = head_;

    while (current!=nullptr)
    {
        callback(current->info);
        current  = current->next;
    }
    
}

template<typename Item>
void DoubleLinkedList<Item>::traverseReverse(void (*callback)(Item&)){
    Node<Item> *current = last_;

    while (current!=nullptr)
    {
        callback(current->info);
        current  = current->prev;
    }
}
#endif  // !DOUBLE_LINKED_LIST_H