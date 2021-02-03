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
    void removeAt(int index);

    T &operator[](const int element);

    
    class Iterator
    {
    public:
        Iterator(List<T> initList) : current(initList.head)
        {}

        Iterator operator+(const int n);
        T operator*();

    private:
        typename List<T>::Node* current;
    };

private:
    class Node
    {
    public:
        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }

        Node *pNext;
        T data;
    };

    Node *head;
    int Size;
};

class exeption
{
public:
    exeption() {}
    virtual std::string what() { return "Something went wrong"; }

private:
    std::string exWhat;
};

class indexExeptions : public exeption
{
public:
    indexExeptions(std::string exWhat) : exWhat(exWhat) {}
    std::string what() override { return "\n" + exWhat; }

private:
    std::string exWhat;
};