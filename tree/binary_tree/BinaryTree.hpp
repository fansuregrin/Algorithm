#include <vector>
#include <string>
#include <queue>

template <typename T>
struct TreeNode {
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(const T &v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(const T &v, TreeNode *left, TreeNode *right)
        : val(v), left(left), right(right) {}
    T val;
    TreeNode *left, *right;
};

template <>
struct TreeNode<int> {
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(const int &v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(const int &v, TreeNode *left, TreeNode *right)
        : val(v), left(left), right(right) {}
    TreeNode(const std::string &s) : left(nullptr), right(nullptr) {
        val = std::stoi(s);
    }
    int val;
    TreeNode *left, *right;
};

template <typename T>
class BinaryTree {
public:
    BinaryTree() : m_root(nullptr) {}
    BinaryTree(TreeNode<T> *root) : m_root(root) {}
    BinaryTree(const std::vector<std::string> &arr) {
        m_root = create(arr);
    }
    ~BinaryTree() {
        destory(m_root);
    }

    std::vector<T> preOrderTraverse() const {
        std::vector<T> arr;
        preOrder(m_root, arr);
        return arr;
    }

    std::vector<T> inOrderTraverse() const {
        std::vector<T> arr;
        inOrder(m_root, arr);
        return arr;
    }

    std::vector<T> postOrderTraverse() const {
        std::vector<T> arr;
        postOrder(m_root, arr);
        return arr;
    }
private:
    static TreeNode<T> *create(const std::vector<std::string> &arr) {
        if (arr.empty()) return nullptr;
        std::queue<TreeNode<T> *>  q;
        auto it = arr.begin();
        auto root = new TreeNode<T>(*it++);
        q.push(root);
        while (!q.empty() && it != arr.end()) {
            int cnt = q.size() * 2;
            bool flag = false;
            while (cnt-- && it != arr.end()) {
                TreeNode<T> * nd = nullptr;
                const std::string &s = *it++;
                if (!flag) {
                    if (s != "null") {
                        nd = new TreeNode<T>(s);
                        q.front()->left = nd;
                        q.push(nd);
                    }
                    flag = true;
                } else {
                    if (s != "null") {
                        nd = new TreeNode<T>(s);
                        q.front()->right = nd;
                        q.push(nd);
                    }
                    q.pop();
                    flag = false;
                }
            }
        }
        return root;
    }

    static void destory(TreeNode<T> *root) {
        if (root == nullptr) return;
        if (root->left) {
            destory(root->left);
        }
        if (root->right) {
            destory(root->right);
        }
        delete root;
    }

    static void preOrder(TreeNode<T> *root, std::vector<T> &arr) {
        if (root == nullptr) return;
        arr.push_back(root->val);
        preOrder(root->left, arr);
        preOrder(root->right, arr);
    }

    static void inOrder(TreeNode<T> *root, std::vector<T> &arr) {
        if (root == nullptr) return;
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }

    static void postOrder(TreeNode<T> *root, std::vector<T> &arr) {
        if (root == nullptr) return;
        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.push_back(root->val);
    }

    TreeNode<T> *m_root;
};

