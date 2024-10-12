#include "LinkedList.hpp"

using namespace std;

int main() {
    SinglyList<int> lst;
    lst.push_front(3);
    lst.push_front(8);
    lst.push_front(2);
    cout << lst << endl;
    lst.pop_front();
    cout << lst << endl;
    cout << "front: " << lst.front() << endl;
}