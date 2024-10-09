#include "BinaryTree.hpp"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    auto len = vec.size();
    for (decltype(len) i = 0; i<len; ++i) {
        if (i == 0) {
            os << vec[i];
        } else {
            os << ' ' << vec[i];
        }
    }
    return os;
}

vector<vector<string>> inputs = {
    {"1", "null", "2", "3"},
    {"1","2","3","4","5","null","8","null","null","6","7","9"},
    {},
    {"1"},
};
vector<vector<int>> pre_orders = {
    {1, 2, 3},
    {1, 2, 4, 5, 6, 7, 3, 8, 9},
    {},
    {1},
};
vector<vector<int>> in_orders = {
    {1, 3, 2},
    {4, 2, 6, 5, 7, 1, 3, 9, 8},
    {},
    {1},
};
vector<vector<int>> post_orders = {
    {3, 2, 1},
    {4, 6, 7, 5, 2, 9, 8, 3, 1},
    {},
    {1},
};

template <typename T>
void testPreOrderTraverse(const BinaryTree<T> &tree, const vector<T> &ans) {
    auto res = tree.preOrderTraverse();
    cout << "preOrder: " << res << endl;
    cout << "answer: " << ans << endl;
    assert(res == ans);
}

template <typename T>
void testInOrderTraverse(const BinaryTree<T> &tree, const vector<T> &ans) {
    auto res = tree.inOrderTraverse();
    cout << "inOrder: " << res << endl;
    cout << "answer: " << ans << endl;
    assert(res == ans);
}

template <typename T>
void testPostOrderTraverse(const BinaryTree<T> &tree, const vector<T> &ans) {
    auto res = tree.postOrderTraverse();
    cout << "postOrder: " << res << endl;
    cout << "answer: " << ans << endl;
    assert(res == ans);
}

int main() {
    auto n = inputs.size();
    for (decltype(n) i=0; i<n; ++i) {
        BinaryTree<int> t(inputs[i]);
        testPreOrderTraverse(t, pre_orders[i]);
        testInOrderTraverse(t, in_orders[i]);
        testPostOrderTraverse(t, post_orders[i]);
    }
}