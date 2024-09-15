#ifndef ALGO_COMMON_H
#define ALGO_COMMON_H
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream& os, const std::vector<T> &arr) {
    int len = arr.size();
    for (int i=0; i<len; ++i) {
        if (i == 0) {
            os << arr[i];
        } else {
            os << ' ' << arr[i];
        }
    }
    return os;
}

#endif