// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "main.h"

class exeption
{
public:
    exeption() {}
    virtual std::string what() { return "Something went wrong"; }

private:
    std::string exWhat;
};

class arrays : public exeption
{
public:
    arrays(std::string exWhat) : exWhat(exWhat) {}
    std::string what() override { return exWhat; }

private:
    std::string exWhat;
};

template <typename T>
List<T>::List()
{
    head = nullptr;
    Size = 0;
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
T &List<T>::operator[](const int element)
{
    try
    {
        if (head == nullptr || element > Size)
            throw arrays("\nIndex is out of range array or head is empty");
    }
    catch (exeption &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    Node<T> *temp = head;
    int countElements = 0;
    while ((temp->pNext != nullptr) && (countElements != element))
    {
        temp = temp->pNext;
        countElements++;
    }
    return temp->data;
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *temp = head;
        while (temp->pNext != nullptr)
        {
            temp = temp->pNext;
        }
        temp->pNext = new Node<T>(data);
    }
    Size++;
}

template <typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = temp->pNext;
    delete temp;
    Size--;
}

template <typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template <typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template <typename T>
void List<T>::insert(T data, int index)
{
    Node<T> *temp = head;
    if (!index)   
        push_front(data); 
    else 
    {
        for (int i = 0; i < index - 1; i++)
            temp = temp->pNext;
        temp->pNext = new Node<T>(data, temp->pNext);
        Size++;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List<int> test;

    test.push_back(45);
    test.push_back(46);
    test.insert(4, 1);
    for (int i = 0; i < test.getSize(); i++)
    {
        std::cout << test[i] << std::endl;
    }
    test.clear();
}
