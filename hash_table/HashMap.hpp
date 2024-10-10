#include "HashTable.hpp"

template <typename Key, typename T, typename Hash = std::hash<Key>>
class HashMap {
public:
    using size_type = size_t;
    using value_type = std::pair<Key, T>;
    using key_type = Key;
    using mapped_type = T;

    HashMap(size_type bucket_count = 1024, const Hash &hash = Hash())
    : ht(bucket_count, hash, _GetKey()) {}

    bool find(const key_type &key, mapped_type &result) {
        value_type val;
        if (ht.find(key, val)) {
            result = val.second;
            return true;
        }
        return false;
    }

    void insert(const value_type &value) {
        ht.insert(value);
    }

    mapped_type &operator[](const key_type &key) {
        value_type &val = ht[key];
        val.first = key;
        return val.second;
    }
private:
    struct _GetKey {
        key_type operator()(const value_type &v) const {
            return v.first;
        }
    };

    HashTable<value_type, Key, Hash, _GetKey> ht;
};