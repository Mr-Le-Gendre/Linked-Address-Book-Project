#ifndef H_LinkedListType
#define H_LinkedListType
#include <iostream>
#include <cassert>
using namespace std;

// Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* link;

    // Default constructor to initialize link to nullptr
    nodeType() : link(nullptr) {}
};

template <class Type>
class linkedListIterator
{
public:
    linkedListIterator();
    linkedListIterator(nodeType<Type>* ptr);
    Type operator*();
    linkedListIterator<Type> operator++();
    bool operator==(const linkedListIterator<Type>& right) const;
    bool operator!=(const linkedListIterator<Type>& right) const;

private:
    nodeType<Type>* current;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}

// ***************** class linkedListType ****************
template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    void reversePrint() const;
    void reversePrint(nodeType<Type>* current) const;
    int length() const;
    void destroyList();
    Type front() const;
    Type back() const;
    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();
    linkedListType();
    linkedListType(const linkedListType<Type>& otherList);
    ~linkedListType();

protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;

private:
    void copyList(const linkedListType<Type>& otherList);
};

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type>* temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type>* current = first;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
void linkedListType<Type>::reversePrint() const
{
    reversePrint(first);
}

template <class Type>
void linkedListType<Type>::reversePrint(nodeType<Type>* current) const
{
    if (current != nullptr)
    {
        reversePrint(current->link);
        cout << current->info << " ";
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != nullptr);
    return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != nullptr);
    return last->info;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr);
    return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type>* newNode;
    nodeType<Type>* current;

    if (first != nullptr)
        destroyList();

    if (otherList.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first;
        count = otherList.count;

        first = new nodeType<Type>;
        first->info = current->info;
        first->link = nullptr;
        last = first;
        current = current->link;

        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
    if (this != &otherList)
    {
        copyList(otherList);
    }
    return *this;
}

#endif
