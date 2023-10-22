//
// Created by Kaitlyn Archambault on 2023-10-03.
//

#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

/**
 * @brief A class to represent Stack data structure.
 *
 * Includes push, pop, peek, and size operations, and implements smart pointers.
 *
 * @tparam T The type of data stored in the stack.
 */
template<class T>
class Stack {
private:
    //stack nodes contain data and a smart pointer to the next node
    struct Node {
        T m_data;
        std::unique_ptr<Node> m_next;
    };

    std::unique_ptr<Node> m_top; // a smart pointer to the top of the stack
    int size; // the number of nodes in the stack

public:
    /**
     * @brief Default constructor to initialize an empty stack.
     */
    Stack() { size = 0; }

    /**
     * @brief Default destructor.
     */
    ~Stack() = default;

    /**
     * @brief check if the stack contains any data
     *
     * @return `true` if the stack is empty, `false` otherwise.
     */
    bool empty() {
        return m_top == nullptr;
    }

    /**
     * @brief Add new data to the top of the stack
     *
     * @param data The data to be added.
     */
    void push(T data) {
        std::unique_ptr<Node> node = std::make_unique<Node>();
        node->m_data = data;

        if (!empty()) {
            // new node is linked to the current top element
            node->m_next = std::move(m_top);
        }

        // new node goes to the top of the stack
        m_top = std::move(node);
        size++;
    }

    /**
     * @brief Pop and return the data of the top node on the stack.
     *
     * @return The data of the top node on the stack.
     */
    T pop() {
        Node *temp = m_top.get();
        T temp_data = temp->m_data;

        // pop the current top node off the stack
        m_top = std::move(m_top->m_next);
        size--;

        return temp_data;
    }

    /**
     * @brief Get the data at the top of the stack without removing it.
     *
     * @return The data of the top node on the stack.
     */
    T peek() {
        return m_top->m_data;
    }

    /**
     * @brief Get the number of nodes in the stack.
     *
     * @return The size of the stack.
     */
    int get_size() {
        return size;
    }
};


#endif //ASSIGNMENT_2_STACK_H
