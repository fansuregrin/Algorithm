#include <forward_list>
#include <iostream>

using namespace std;

int main() {
    forward_list<int> lst;
    auto v = lst.front();
    cout << v << endl;
}