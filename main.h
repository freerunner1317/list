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
        Iterator() : current(nullptr)
        {
        }
        Iterator(T* init) : current(init)
        {
        }

        Iterator operator+(const int n);
        T operator*();

    private:
        T* current;
    };

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