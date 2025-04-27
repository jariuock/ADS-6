// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& _data) : data(_data), next(nullptr) {}
    };
    Node* head; 

public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(const T& elem) {
        Node* newNode = new Node(elem);
        if (!head || elem.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && current->next->data.prior >= elem.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    T pop() {
        if (!head)
            throw std::out_of_range("Queue is empty!");
        Node* temp = head;
        T result = head->data;
        head = head->next;
        delete temp;
        return result;
    }
    bool empty() const {
        return head == nullptr;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif // INCLUDE_TPQUEUE_H_
