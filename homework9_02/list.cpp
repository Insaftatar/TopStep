#include <iostream>

template<typename T>
class List
{
    struct Node {
        T val;
        Node *next;
    };

    Node *head = nullptr;
    int size;

public:
    List() {}

    List(int size, T val) {
        this->size = 0;
        int tmp = size;
        while (tmp != 0) {
            AddToTail(val);
            --tmp;
        }
    }

    void AddToTail(const T &val) {
        if (head == nullptr) {
            head = new Node {val, nullptr};
        } else {
            Node *i = head;
            while (i->next != nullptr) {
                i = i->next;
            }
            i->next = new Node {val, nullptr};
        }
        this->size += 1;
    }

    void AddToHead(T el) {
        Node *tmp = new Node{el,head};
        this->head = tmp;
    }

    void DeleteFromHead() {
        this->head = this->head->next;
    }

    void DeleteAll() {
        this->head = nullptr;
    }

    void DeleteTail() {
        Node *last = this->head;

        while (last->next->next != nullptr) {
            last = last->next;
        }

        last->next = nullptr;
    }

    void show() {
        for (Node *i = head; i != nullptr; i = i->next) {
            std::cout << i->val << " ";
        }
        std::cout << "\n";
    }
};

int main()
{
    List<int> list(7,4);

    list.show();
    list.AddToHead(5);
    list.AddToTail(9);
    list.show();
    list.DeleteFromHead();
    list.DeleteTail();
    list.show();
    list.DeleteAll();
    list.show();

    return 0;
}
