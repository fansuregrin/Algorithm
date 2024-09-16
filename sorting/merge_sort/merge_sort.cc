#include <algorithm>
#include "../common.h"
#include "../ball.h"

using namespace std;

template <typename T>
void merge_sort1(vector<T> &arr, int &cmp_cnt, int &move_cnt) {
    int len = arr.size();
    cmp_cnt = 0, move_cnt = 0;
    int step = 1;
    vector<T> tmp(len);
    while (step < len) {
        for (int i=0; i<len; i+=2*step) {
            int k = i;
            int p1 = i, end1 = min(i + step, len);
            int p2 = end1, end2 = min(end1 + step, len);
            while (p1 < end1 && p2 < end2) {
#ifdef STABLE
                // 稳定
                tmp[k++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
#else                
                // 不稳定
                tmp[k++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
#endif
                ++cmp_cnt;
                ++move_cnt;
            }
            while (p1 < end1) {
                tmp[k++] = arr[p1++];
                ++move_cnt;
            }
            while (p2 < end2) {
                tmp[k++] = arr[p2++];
                ++move_cnt;
            }
        }
        arr.swap(tmp);
        step <<= 1;
    }
}

template <typename T>
void merge(vector<T> &arr, int low, int mid, int high, int &cmp_cnt, int &move_cnt) {
    vector<T> tmp(high - low);
    int p1 = low, p2 = mid, k = 0;
    while (p1 < mid && p2 < high) {
#ifdef STABLE
        tmp[k++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
#else
        tmp[k++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
#endif
        ++cmp_cnt;
        ++move_cnt;
    }
    while (p1 < mid) {
        tmp[k++] = arr[p1++];
        ++move_cnt;
    }
    while (p2 < high) {
        tmp[k++] = arr[p2++];
        ++move_cnt;
    }
    std::copy(tmp.begin(), tmp.end(), arr.begin() + low);
}

template <typename T>
void __merge_sort2(vector<T> &arr, int low, int high, int &cmp_cnt, int &move_cnt) {
    if (low >= high - 1) {
        return;
    }
    int mid = low + (high - low)/2;
    __merge_sort2(arr, low, mid, cmp_cnt, move_cnt);
    __merge_sort2(arr, mid, high, cmp_cnt, move_cnt);
    merge(arr, low, mid, high, cmp_cnt, move_cnt);
}

template <typename T>
void merge_sort2(vector<T> &arr, int &cmp_cnt, int &move_cnt) {
    __merge_sort2(arr, 0, arr.size(), cmp_cnt, move_cnt);
}

template <typename T, typename F>
void sort_wrapper(vector<T> &arr, F sort_func) {
    cout << "before sort: " << arr << endl;
    int cmp_cnt = 0, move_cnt = 0;
    sort_func(arr, cmp_cnt, move_cnt);
    cout << "after  sort: " << arr << endl;
    cout << "array size: " << arr.size()
         << ", compare count: " << cmp_cnt
         << ", move count: " << move_cnt << '\n' << endl;
}

int main() {
    vector<int> a1{1, 3, 2, 0, 6, 4, 5};
    vector<int> a2 = a1;
    sort_wrapper(a1, merge_sort1<int>);
    sort_wrapper(a2, merge_sort2<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    vector<int> b2 = b1;
    sort_wrapper(b1, merge_sort1<int>);
    sort_wrapper(b2, merge_sort2<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    vector<int> c2 = c1;
    sort_wrapper(c1, merge_sort1<int>);
    sort_wrapper(c2, merge_sort2<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {2, algo::GREEN},
        {1, algo::GREEN}, {3, algo::GREEN}
    };
    vector<algo::Ball> d2 = d1;
    sort_wrapper(d1, merge_sort1<algo::Ball>);
    sort_wrapper(d2, merge_sort2<algo::Ball>);
}