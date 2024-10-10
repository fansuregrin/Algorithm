#include <algorithm>
#include "../common.h"

using namespace std;

template <typename T>
void counting_sort(vector<T> &arr) {
    if (arr.empty()) return;
    int len = arr.size(), min_ = arr[0], max_ = arr[0];
    for (int i=1; i<len; ++i) {
        min_ = min(min_, arr[i]);
        max_ = max(max_, arr[i]);
    }
    int k = max_ - min_ + 1;
    vector<T> cnt(k, 0);
    for (const auto &e : arr) {
        ++cnt[e - min_];
    }
    for (int i=1; i<k; ++i) {
        cnt[i] += cnt[i-1];
    }
    vector<int> tmp(len);
    for (int i=len-1; i>=0; --i) {
        tmp[--cnt[arr[i] - min_]] = arr[i];
    }
    arr.swap(tmp);
}

template <typename T, typename F>
void sort_wrapper(vector<T> &arr, F sort_func) {
    cout << "before sort: " << arr << endl;
    sort_func(arr);
    cout << "after  sort: " << arr << endl;
    cout << endl;
}

int main() {
    vector<int> a1{1, 3, 2, 8, 3, 0, 6, 1, 3, 5};
    sort_wrapper(a1, counting_sort<int>);
}