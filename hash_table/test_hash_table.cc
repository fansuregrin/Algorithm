#include "HashTable.hpp"
#include <iostream>

using namespace std;

template <typename T>
struct Identity {
    T operator()(T x) const { return x; }
};

int main() {
    HashTable<int, int, std::hash<int>, Identity<int>> ht1(1024,
        std::hash<int>(), Identity<int>());
    int res = 0;
    ht1.insert(1);
    ht1.insert(2);
    ht1.insert(4);
    if (ht1.find(2, res)) cout << res << endl;
    if (ht1.find(5, res)) cout << res << endl;
}