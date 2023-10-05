//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

template <class T>
class Stack {
private:
    struct Node {
        T m_data;
        struct Node * m_next;
    };

    Node* m_top;
    int size;

public:
    Stack() { m_top = nullptr, size = 0; }
    ~Stack() = default;

    bool empty() {
        return m_top == nullptr;
    }

    void push(T data) {
        Node* node = (Node*)malloc(sizeof(Node));
        node-> m_data = data;

        if (empty()) {
            // if stack is empty, node pointer is null
            node->m_next = nullptr;
        } else {
            //otherwise, new node is linked to the current top element
            node->m_next = m_top;
        }

        //new node goes to the top of the stack
        m_top = node;
        size ++;
    }

    T pop() {
        Node* temp = m_top;
        T temp_data = m_top->m_data;

        //pop the current top node off the stack
        m_top = m_top->m_next;
        size--;
        free(temp);

        return temp_data;
    }

    // get the data at the top of the stack
    T peek() {
        return m_top->m_data;
    }

    int get_size() {
        return size;
    }
};


#endif //ASSIGNMENT_2_STACK_H
