#ifndef DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
#define DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
#include "Node2.h"
template <typename T>
class DoublyLinkedList
{
private:
    Node2<T> *head;
    Node2<T> *tail;
  public:
    bool empty();
    std::size_t size();
    void addFront(const T& newElement);
    void removeFront();
    void addBack(const T& newElement);
    void removeBack();
    DoublyLinkedList(){head=nullptr;}
    const T& front() const;
    const T& back() const;
    void insert(const T& newElement, int index);
    void remove(const T& element);
    void print();
    T& operator[](int index);
     ~ DoublyLinkedList();
};

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
        if(this->head==nullptr)
            return;
        Node2<int> *pom;
        while (this->head!= nullptr) {
            pom = this->head;
            this->head= this->head->next;
            delete pom;
        }
}

template <typename T>
bool DoublyLinkedList<T>::empty()
{
    return !head;
}

template <typename T>
std::size_t DoublyLinkedList<T>::size()
{
    int counter = 0;
    if (this->head== nullptr) {
        return 0;
    }
    Node2<T> *t = head;
    counter++;
    while (t->next != nullptr) {
        t = t->next;
        counter++;
    }
    return counter;
}
template <typename T>
void DoublyLinkedList<T>::addFront(const T& newElement)
{
    auto *pom=new Node2<T>(newElement);
    if(this->head==nullptr)
    {
        this->head=pom;
        this->tail=pom;
        return;
    }
    this->head->previous=pom;
    pom->next=this->head;
    this->head= pom;
}
template <typename T>
void DoublyLinkedList<T>::removeFront()
{
    if(this->head==nullptr)
    {
        std::cout<<"list is empty"<<"\n";
        return;
    }
    if(this->head==this->tail)
    {
        delete this->head;
        this->head=nullptr;
        this->tail=nullptr;
        return;
    }
    Node2<T>*pom;
    pom=this->head->next;
    delete this->head;
    this->head=pom;
    this->head->previous=nullptr;
}
template <typename T>
void DoublyLinkedList<T>::addBack(const T& newElement)
{
    auto *pom=new Node2<T>(newElement);
    if(this->head==nullptr)
    {
        this->head=pom;
        this->tail=pom;
        return;
    }
    this->tail->next=pom;
    pom->previous=this->tail;
    this->tail=pom;
}
template <typename T>
void DoublyLinkedList<T>::removeBack()
{
    if(this->head==nullptr)
    {
        std::cout<<"list is empty"<<"\n";
        return;
    }
    if(this->head==this->tail)
    {
        delete this->head;
        return;
    }
    Node2<T>*t=this->tail->previous;
    t->next=nullptr;
    delete this->tail;
    this->tail=t;
}
template <typename T>
const T& DoublyLinkedList<T>::front() const
{
    static T t;
    if(this->head==nullptr)
    {
        std::cout<<"list is empty"<<std::endl;
        return t;
    }
    t=this->head->value;
    return t;
}
template <typename T>
const T& DoublyLinkedList<T>::back() const
{
    static T t;
    if(this->head==nullptr)
    {
        std::cout<<"list is empty"<<std::endl;
        return t;
    }
    t=this->tail->value;
    return t;
}
template <typename T>
void DoublyLinkedList<T>::insert(const T& newElement, int index)
{
    auto pom= this->head;
    auto *pom2= new Node2<T>(newElement);
    if(index==0){
        pom2->next=this->head;
        return;
    }
    while (--index)
    {
        if(pom->next==nullptr)
        {
            pom->next= new Node2<T>(newElement);
            return;
        }
        pom=pom->next;
    }
    pom2->next=pom->next;
    pom->next=pom2;
}
template <typename T>
void DoublyLinkedList<T>::remove(const T& element)
{
    Node2<T> *current;
    while(this->head!=nullptr&&this->head->value==element)
    {
        current=this->head;
        this->head=this->head->next;
        delete current;
    }
    current=this->head;
    Node2<T> *next=this->head->next;
    Node2<T> *pom;

    while(next!=nullptr){
        if(next->value==element)
        {
            pom=next->next;
            delete next;
            next=pom;
            current->next=pom;
        }
        else
        {
            current=next;
            next=next->next;
        }
    }
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index)
{
    static T t;
    if(this->head==nullptr)
    {
        std::cout<<"List is empty";
        return t;
    }
    Node2<T> *pom=this->head;
    while(index!=0)
    {
        pom=pom->next;
        index--;
    }
    t=pom->value;
    return t;
}
template<typename T>
void DoublyLinkedList<T>::print() {
    Node2<T> *pom = this->head;
    if (this->head== nullptr) {
        std::cout << "List empty" << std::endl;
        return;
    }
    while (pom != nullptr) {
        std::cout << pom->value;
        std::cout << " ";
        pom = pom->next;
    }
}

#endif // DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
