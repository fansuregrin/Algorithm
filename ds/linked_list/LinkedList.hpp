#ifndef ALGO_LINKED_LIST_HPP
#define ALGO_LINKED_LIST_HPP
#include <cstddef>
#include <iostream>

template <typename T>
struct SinglyListNode {
    SinglyListNode * next;
    T val;
    SinglyListNode() : val(), next(nullptr) {}
    SinglyListNode(const T &val_) : val(val_), next(nullptr) {}
    SinglyListNode(const T &val_, SinglyListNode *next_) : val(val_), next(next_) {}
};

template <typename T>
class SinglyList {
public:
    using size_type = size_t;
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;

    template <typename U> friend
    std::ostream &operator<<(std::ostream &os, const SinglyList<U> &list);

    SinglyList() : m_head(new node_type()), m_len(0) {}

    ~SinglyList() {
        while (m_head) {
            node_type *tmp = m_head;
            m_head = m_head->next;
            delete tmp;
            --m_len;
        }
    }

    reference front() {
        return m_head->next->val;
    }

    const_reference front() const {
        return m_head->next->val;        
    }

    void push_front(const T& value) {
        m_head->val = value;
        node_type *nd = new node_type();
        nd->next = m_head;
        m_head = nd;
        ++m_len;
    }

    void pop_front() {
        if (m_head->next) {
            node_type *nd = m_head->next;
            m_head->next = m_head->next->next;
            delete nd;
            --m_len;
        }
    }
private:
    using node_type = SinglyListNode<T>;
    node_type *m_head;
    size_type m_len;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const SinglyList<T> &list) {
    typename SinglyList<T>::node_type *curr = list.m_head->next;
    typename SinglyList<T>::size_type i = 0;
    while (curr) {
        os << (i++ > 0 ? " -> " : "") << curr->val;
        curr = curr->next;
    }
    return os;
}

#endif // ALGO_LINKED_LIST_HPP