#include <stack>
#include <iostream>
#include "../../ds/tree/binary_tree/BinaryTree.hpp"

using namespace std;

template <typename T>
bool isValidBST(const TreeNode<T>* root) {
    stack<TreeNode<T> *> st;
    TreeNode<T> *curr = const_cast<TreeNode<T>*>(root);
    int prev = 0;
    bool firstNode = true;
    while (curr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode<T> *nd = st.top();
            st.pop();
            if (!firstNode && nd->val <= prev) {
                return false;
            }
            firstNode = false;
            prev = nd->val;
            curr = nd->right;
        }
    }
    return true;
}

int main() {
    vector<string> input = {"5","1","4","null","null","3","6"};
    BinaryTree<int> tree(input);
    cout << boolalpha << isValidBST(tree.getRoot()) << endl;
}