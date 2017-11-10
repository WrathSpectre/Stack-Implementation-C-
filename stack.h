#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {

private:
    struct Node {
        T _data;
        Node *next;
    };

    Node *head;
    unsigned _size;

public:
    Stack() {
        head = nullptr;
        _size = 0;
    }

    ~Stack() {
        Node *current = head, *next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }

    void push(const T data) {
        if (head == nullptr) {
            head = new Node;
            head->_data = data;
            head->next = nullptr;
        }

        else {
            Node *newNode = new Node;
            newNode->_data = data;
            newNode->next = head;
            head = newNode;
        }

        _size++;
    }

    T top() const {
        if (head == nullptr)
            throw std::runtime_error("error: empty stack");
            
        return head->_data;
    }

    void pop() {
        if (head == nullptr)
            throw std::runtime_error("error: empty stack");

        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }

        else {
            Node *newNode = head;
            head = head->next;
            delete newNode;
        }

        _size--;
    }

    const T &operator[](const unsigned index) const {
       if (head == nullptr)
            throw std::runtime_error("error: empty queue");

        else if (index >= _size)
            throw std::out_of_range("error: out of scope");

        else {
            Node *temp = head;

            for (unsigned itr = 0; itr < index; ++itr)
                temp = temp->next;

            return temp->_data;
            delete temp;
        }
    }

    unsigned size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size > 0 ? true : false;
    }
};

#endif
