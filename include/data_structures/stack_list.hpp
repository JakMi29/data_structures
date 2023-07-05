#ifndef DATA_STRUCTURES_STACK_LIST_HPP
#define DATA_STRUCTURES_STACK_LIST_HPP
// TODO: zaimplementuj klasę StackList - stos z implementacją listową


template<typename T>
class StackList
{
private:
    DoublyLinkedList<T> *list;
public:
    StackList();

    void push(const T &newElement);

    T pop();

    bool empty();

    std::size_t size();

    const T &top();
    ~StackList();
};
template <typename T>
StackList<T>::~StackList()
{
    delete this->list;
}

template<typename T>
StackList<T>::StackList() {
    this->list=new DoublyLinkedList<T>;
}

template<typename T>
void StackList<T>::push(const T &newElement) {
    list->addFront(newElement);
}

template<typename T>
T StackList<T>::pop() {
    static T t;
    t=list->front();
    list->removeFront();
    return t;
}

template<typename T>
bool StackList<T>::empty() {
    return list->empty();
}

template<typename T>
std::size_t StackList<T>::size() {
    return list->size();
}

template<typename T>
const T &StackList<T>::top() {
    static T t;
    t=list->front();
    return t;
}

#endif // DATA_STRUCTURES_STACK_LIST_HPP
