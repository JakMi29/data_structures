#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP

#include "Node.h"

template<typename T>
class SinglyLinkedList {
private:
    Node<T> *head;

public:
    bool empty();
    SinglyLinkedList(){head= nullptr;}
    std::size_t size();

    void addFront(const T &newElement);

    void removeFront();

    void print();

    void addBack(const T &newElement);

    void removeBack();

    const T &front() const;

    const T &back() const;

    void insert(const T &newElement, int index);

    void remove(const T &element);

    T &operator[](int index);
    
     ~ SinglyLinkedList(){
        if(this->head== nullptr)
            return;
        Node<int> *pom;
        while(this->head!= nullptr)
        {
            pom=this->head;
            this->head=this->head->next;
            delete pom;
        }
    }
};

template<typename T>
bool SinglyLinkedList<T>::empty() {
    return !head;
}

template<typename T>
std::size_t SinglyLinkedList<T>::size() {
    int counter = 0;
    if (this->head == nullptr) {
        return 0;
    }
    Node<T> *t = head;
    counter++;
    while (t->next != nullptr) {
        t = t->next;
        counter++;
    }

    return counter;
}

template<typename T>
void SinglyLinkedList<T>::addFront(const T &newElement) {
    auto *t = new Node<T>(newElement);
    if (this->head == nullptr) {
        this->head = t;
        return;
    }
    t->next=this->head;
    this->head = t;
}

template<typename T>
void SinglyLinkedList<T>::removeFront() {
    Node<T> *t = this->head->next;
    delete this->head;
    this->head = t;

}

template<typename T>
void SinglyLinkedList<T>::addBack(const T &newElement) {

    auto *newStructure = new Node<T>(newElement);
    if (head == nullptr) {
        this->head = newStructure;
    }
    else {
        Node<T> *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStructure;
    }
}
template<typename T>
void SinglyLinkedList<T>::removeBack() {
    if (this->head == nullptr) {
      return;
    }
    if(this->head->next==nullptr)
    {
        delete this->head;
        this->head=nullptr;
        return;
    }
    else {
        Node<T> *t = this->head;
        while (t->next->next != nullptr) {
            t = t->next;
        }
        delete t->next;
        t->next = nullptr;
    }
}

template<typename T>
const T &SinglyLinkedList<T>::front() const {

    static T t;
    t=head->value;
    return t;
}

template<typename T>
const T &SinglyLinkedList<T>::back() const {
    Node<T> *pom = this->head;
    while (pom->next != NULL) {
       pom =pom->next;
    }
    static T t;
    t=pom->value;
    return t;
}

template<typename T>
void SinglyLinkedList<T>::insert(const T &newElement, int index) {
    auto *pom2= new Node<T>(newElement);
    Node<T> *pom= this->head;
    if(index==0){
        pom2->next=this->head;
        return;
    }

    while (--index)
    {
        if(pom->next== nullptr)
        {
            pom->next= new Node<T>(newElement);
            return;
        }
        pom=pom->next;
    }
    pom2->next=pom->next;
    pom->next=pom2;
}

template<typename T>
void SinglyLinkedList<T>::remove(const T &element) {
    Node<T> *current;
    while(this->head!= nullptr&&this->head->value==element)
    {
        current=this->head;
        this->head=this->head->next;
        delete current;
    }
    current=this->head;
    Node<T> *next=this->head->next;
    Node<T> *pom;

    while(next!= nullptr){
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
template<typename T>
void SinglyLinkedList<T>::print() {
    Node<T> *t = this->head;
    if (this->head == nullptr) {
        std::cout << "List empty" << std::endl;
        return;
    }
    while (t != nullptr) {
        std::cout << t->value;
        std::cout << " ";
        t = t->next;
    }
    std::cout<<std::endl;
}

template<typename T>
T &SinglyLinkedList<T>::operator[](int index) {
    static T t;
    if(this->head==nullptr)
    {
        std::cout<<"List is empty";
        return t;
    }
    Node<T> *pom=this->head;
    while(index!=0)
    {
        pom=pom->next;
        index--;
    }
    t=pom->value;
    return t;
}

#endif // DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP
