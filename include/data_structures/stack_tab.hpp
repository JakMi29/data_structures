#ifndef DATA_STRUCTURES_STACK_TAB_HPP
#define DATA_STRUCTURES_STACK_TAB_HPP
// 22123213
//  TODO: zaimplementuj klasę StackTab - stos z implementacją tablicową
template <typename T>
class StackTab
{
  public:
    T* tab;
    int lastIndex{};
    int currentSize{};

  public:
    StackTab();

    explicit StackTab(std::size_t initialCapacity);

    void push(const T& newElement);

    T pop();

    bool empty();

    std::size_t size();

    const T& top();
    void addPlace();
    void print();
    ~StackTab();
};
template <typename T>
StackTab<T>::~StackTab()
{
    delete[] this->tab;
}

template <typename T>
void StackTab<T>::print()
{
    for(int i = 0; i <= this->lastIndex; i++)
    {
        std::cout << this->tab[i];
    }
    std::cout << std::endl;
}

template <typename T>
void StackTab<T>::addPlace()
{
    T* t = new T[this->currentSize*2];
    for(int i = 0; i < this->currentSize; i++)
    {
        t[i] = this->tab[i];
    }
    this->currentSize *= 2;
    delete[] this->tab;
    this->tab = t;
}

template <typename T>
StackTab<T>::StackTab()
{
    this->currentSize = 2;
    this->tab = new T[this->currentSize];
    this->lastIndex = -1;
}

template <typename T>
StackTab<T>::StackTab(std::size_t initialCapacity)
{
    this->currentSize = initialCapacity;
    this->tab = new T[this->currentSize];
    this->lastIndex = -1;
}

template <typename T>
void StackTab<T>::push(const T& newElement)
{
    if(this->lastIndex >= this->currentSize - 1)
        this->addPlace();
    this->lastIndex+=1;
    this->tab[this->lastIndex] = newElement;
}

template <typename T>
T StackTab<T>::pop()
{
    T value = this->tab[this->lastIndex];
    this->lastIndex--;
    return value;
}

template <typename T>
bool StackTab<T>::empty()
{
    if(this->lastIndex == -1)
        return true;
    return false;
}

template <typename T>
std::size_t StackTab<T>::size()
{
    return this->lastIndex + 1;
}

template <typename T>
const T& StackTab<T>::top()
{
    static T t;
    t = this->tab[lastIndex];
    return t;
}

#endif /* DATA_STRUCTURES_STACK_TAB_HPP */
