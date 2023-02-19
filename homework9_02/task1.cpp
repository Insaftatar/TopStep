#include <iostream>

class List {

    struct Node {
        int val;
        Node *next;
    };

    int size;
    int size_now = 0;

    Node *head = nullptr;

    public:

    List(int size) {
        this->size = size;
    }

    List() : List(10) {}

    void add_head(int val) {
        if (this->size_now <= this->size) {
            Node *new_node = new Node{val,head};
            this->head = new_node;
            this->size_now++;
        } else {
            size *= 2;
            this->add_head(val);
        }
    }

    void add_back(int d) {
        if (this->size_now <= this->size) {
            if (head == nullptr)
                head = new Node{d,nullptr};
            else
            {
                Node *tmp = head;
                while(tmp->next != nullptr)
                    tmp = tmp->next;
                tmp->next = new Node{d,nullptr};
            }

            this->size_now++;
        } else {
            size *= 2;
            this->add_head(d);
        }
    }

    void print() {
        for (Node *i = head; i != nullptr; i = i->next) {
            std::cout << i->val << " ";
        }
        std::cout << "\n";
    }
};

int main() {

    List list;
    list.add_head(5);
    list.add_back(4);
    list.print();

    return 0;
}