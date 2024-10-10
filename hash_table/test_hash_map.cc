#include <string>
#include <iostream>
#include "HashMap.hpp"

using namespace std;

int main() {
    HashMap<int, string> mp;
    string res;
    mp.insert(make_pair(1, "hello"));
    mp[2] = "two";
    mp[3] = "three";
    if (mp.find(1, res)) cout << "1: " << res << endl;
    if (mp.find(2, res)) cout << "2: " << res << endl;
    if (mp.find(10, res)) cout << "10: " << res << endl;
    cout << "3: " << mp[3] << endl;
    mp[3] = "san";
    cout << "3: " << mp[3] << endl;
}