// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "main.h"

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
            throw indexExeptions("Index is out of range array or head is empty");
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
    if (!index)
        push_front(data);
    else
    {
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->pNext;
        temp->pNext = new Node<T>(data, temp->pNext);
        Size++;
    }
}

template <typename T>
void List<T>::removeAt(int index)
{
    try
    {
        if ((index > Size) || (index < 0))
            throw indexExeptions("Index is out of range");
    }
    catch (exeption &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    if (!index)
        pop_front();
    else
    {
        Node<T> *temp = head;
        Node<T> *tempT;
        for (int i = 0; i < index - 1; i++)
            temp = temp->pNext;
        tempT = temp->pNext;
        temp->pNext = temp->pNext->pNext;
        delete tempT;
        Size--;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List<int> test;

    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.insert(4, 1);
    test.removeAt(2);
    for (int i = 0; i < test.getSize(); i++)
    {
        std::cout << test[i] << std::endl;
    }
    test.clear();
}
