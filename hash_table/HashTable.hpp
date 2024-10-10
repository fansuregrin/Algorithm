#include <vector>

template <typename Val>
struct HtNode {
    HtNode * next;
    Val val;

    HtNode(Val value) : val(value) {}
};


template <
    typename Val,
    typename Key,
    typename HashFcn,
    typename ExtractKey
> class HashTable {
public:
    using size_type = size_t;

    HashTable(size_type n, HashFcn hash, ExtractKey get_key)
    : m_buckets(n), m_hash(hash), m_get_key(get_key) {
        for (auto &i : m_buckets) {
            i = nullptr;
        }
        m_num_buckets = n;
    }

    bool find(const Key &key, Val &result) const {
        size_type idx = m_hash(key) % m_num_buckets;
        _HtNode *curr = m_buckets[idx];
        while (curr) {
            if (m_get_key(curr->val) == key) {
                result = curr->val;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void insert(const Val &value) {
        Key key = m_get_key(value);
        size_type idx = m_hash(key) % m_num_buckets;
        _HtNode *curr = m_buckets[idx];
        while (curr) {
            if (m_get_key(curr->val) == key) {
                curr->val = value;
                break;
            }
            curr = curr->next;
        }
        if (curr == nullptr) {
            _HtNode *nd = new _HtNode(value);
            nd->next = m_buckets[idx];
            m_buckets[idx] = nd;
        }
    }
private:
    using _HtNode = HtNode<Val>;
    std::vector<_HtNode *> m_buckets;
    HashFcn m_hash;
    ExtractKey m_get_key;
    size_type m_num_buckets;
};