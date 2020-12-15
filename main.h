template <typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    void pop_front();
    void clear();
    void push_front(T data);
    void insert(T data, int index);
    int getSize() { return Size; }

    T &operator[](const int element);

private:
    template <typename T1>
    class Node
    {
    public:
        Node(T1 data = T1(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }

        Node *pNext;
        T1 data;
    };

    Node<T> *head;
    int Size;
};
