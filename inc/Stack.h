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
        std::unique_ptr<Node> m_next;
    };

    std::unique_ptr<Node> m_top;
    int size;

public:
    Stack() { size = 0; }
    ~Stack() = default;

    // check if the stack contains any data
    bool empty() {
        return m_top == nullptr;
    }

    // add new data to the top of the stack
    void push(T data) {
        std::unique_ptr<Node> node = std::make_unique<Node>();
        node-> m_data = data;

        if (!empty()) {
            // new node is linked to the current top element
            node->m_next = std::move(m_top);
        }

        // new node goes to the top of the stack
        m_top = std::move(node);
        size++;
    }

    // returns the value of the top node on the stack after removing it
    T pop() {
        Node * temp = m_top.get();
        T temp_data = temp->m_data;

        // pop the current top node off the stack
        m_top = std::move(m_top->m_next);
        size--;

        return temp_data;
    }

    // get the data at the top of the stack
    T peek() {
        return m_top->m_data;
    }

    // get the number of nodes in the stack
    int get_size() {
        return size;
    }
};


#endif //ASSIGNMENT_2_STACK_H
