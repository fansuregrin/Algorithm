#include <vector>
#include <iostream>
#include "../ball.h"

using namespace std;

template <typename T>
void bubble_sort(vector<T> &arr, int &cmp_cnt, int &swap_cnt) {
    int len = arr.size();
    cmp_cnt = 0, swap_cnt = 0;
    for (int i=0; i<len-1; ++i) {
        for (int j=0; j<len-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                ++swap_cnt;
            }
            ++cmp_cnt;
        }
    }
}

template <typename T>
void bubble_sort_optim(vector<T> &arr, int &cmp_cnt, int &swap_cnt) {
    int len = arr.size();
    cmp_cnt = 0, swap_cnt = 0;
    bool ordered;
    for (int i=0; i<len-1; ++i) {
        ordered = true;
        for (int j=0; j<len-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                ordered = false;
                ++swap_cnt;
            }
            ++cmp_cnt;
        }
        if (ordered) break;
    }
}

template <typename T>
ostream &operator<<(ostream& os, const vector<T> &arr) {
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

template <typename T, typename F>
void sort_wrapper(vector<T> &arr, F sort_func) {
    cout << "before sort: " << arr << endl;
    int cmp_cnt, swap_cnt;
    sort_func(arr, cmp_cnt, swap_cnt);
    cout << "after  sort: " << arr << endl;
    cout << "array size: " << arr.size()
         << ", compare count: " << cmp_cnt
         << ", swap count: " << swap_cnt << '\n' << endl;
}

int main() {
    vector<int> a1{1, 3, 2, 0, 6, 4, 5};
    vector<int> a2 = a1;
    sort_wrapper(a1, bubble_sort<int>);
    sort_wrapper(a2, bubble_sort_optim<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    vector<int> b2 = b1;
    sort_wrapper(b1, bubble_sort<int>);
    sort_wrapper(b2, bubble_sort_optim<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    vector<int> c2 = c1;
    sort_wrapper(c1, bubble_sort<int>);
    sort_wrapper(c2, bubble_sort_optim<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {1, algo::RED},
        {1, algo::GREEN}, {3, algo::GREEN}
    };
    vector<algo::Ball> d2 = d1;
    sort_wrapper(d1, bubble_sort<algo::Ball>);
    sort_wrapper(d2, bubble_sort_optim<algo::Ball>);
}