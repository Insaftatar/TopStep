#include <iostream>
#include <memory>

template <typename T>
class Array
{
    std::unique_ptr<T[]> array;
    int size;

public:
    Array() : Array(3, 3) {}
    Array(const Array &other) {}
    Array(int size, T val) : array(new T[size])
    {
        this->size = size;

        this->cap = size;

        for (int i = 0; i < size; ++i)
        {
            this->array.get()[i] = val;
        }
    } // как пример конструктор от размера и знчения (необязтельно)

    void add_begin(T val) {
        for (int i = size; i > 0; --i)
        {
            this->array.get()[i] = this->array.get()[i - 1];
        }
        size += 1;
        this->array.get()[0] = val;
    } // добавить в начало

    void add_end(T val)
    {
        this->array.get()[size] = val;
        size += 1;
    } // добавить в конец

    void del_begin() {
        for (int i = 0; i < size; ++i)
        {
            this->array.get()[i] = this->array.get()[i + 1];
        }
        size -= 1;
    } // удалить из начала
    void del_end() {
        size -= 1;
    }   // удалить из конца

    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << array.get()[i] << " ";
        }
        std::cout << "\n";
    } // вывести массив

    ~Array() {}
};

int main()
{
    Array<int> arr(5, 5);

    arr.print();

    arr.add_end(4);

    arr.print();

    arr.add_begin(4);
    
    arr.print();

    arr.del_begin();

    arr.print();

    arr.del_end();

    arr.print();

    return 0;
}
