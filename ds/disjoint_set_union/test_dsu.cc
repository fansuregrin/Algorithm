#include "DSU.hpp"
#include <cassert>

using namespace std;

int main() {
    // {0, 1}, {2, 3, 4}, {5, 6}
    DSU x(7);
    x.merge(0, 1);
    x.merge(2, 3);
    x.merge(3, 4);
    x.merge(5, 6);

    assert(x.find(0) == x.find(1));
    assert(x.find(2) == x.find(3));
    assert(x.find(2) == x.find(4));
    assert(x.find(3) == x.find(4));
    assert(x.find(5) == x.find(6));
    assert(x.find(0) != x.find(2));
    assert(x.find(0) != x.find(3));
    assert(x.find(0) != x.find(4));
    assert(x.find(0) != x.find(5));
    assert(x.find(0) != x.find(6));
}