#ifndef DATA_STRUCTURES_QUEUE_LIST_HPP
#define DATA_STRUCTURES_QUEUE_LIST_HPP
#include "singly_linked_list.hpp"
// TODO: zaimplementuj klasę QueueList - kolejka z implementacją tablicową cykliczną
template <typename T>
class QueueList
{
private:
    DoublyLinkedList<T> *list;
  public:
    QueueList();
    void enqueue(const T& newElement);
    T dequeue();
    bool empty();
    std::size_t size();
    const T& front();
    void print();
    ~QueueList();
};
template <typename T>
QueueList<T>::~QueueList()
{
    delete this->list;
}

template<typename T>
void QueueList<T>::print() {
    list->print();
}

template <typename T>
QueueList<T>::QueueList()
{
    this->list=new DoublyLinkedList<T>;
}

template <typename T>
void QueueList<T>::enqueue(const T& newElement)
{
    list->addBack(newElement);
}

template <typename T>
T QueueList<T>::dequeue()
{
    static T t;
    t=list->front();
    list->removeFront();
    return t;
}

template <typename T>
bool QueueList<T>::empty()
{
    return list->empty();
}

template <typename T>
std::size_t QueueList<T>::size()
{
    return list->size();
}

template <typename T>
const T& QueueList<T>::front()
{
    static T t;
    t=list->front();
    return t;
}


#endif // DATA_STRUCTURES_QUEUE_LIST_HPP
