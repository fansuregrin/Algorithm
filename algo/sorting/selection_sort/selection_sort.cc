#include "../ball.h"
#include "../common.h"

using namespace std;

template <typename T>
void selection_sort(vector<T> &arr, int &cmp_cnt, int &swap_cnt) {
    int len = arr.size();
    cmp_cnt = 0, swap_cnt = 0;
    for (int i=0; i<len-1; ++i) {
        for (int j=i+1; j<len; ++j) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
                ++swap_cnt;
            }
            ++cmp_cnt;
        }
    }
}

template <typename T>
void selection_sort_optim(vector<T> &arr, int &cmp_cnt, int &swap_cnt) {
    int len = arr.size();
    cmp_cnt = 0, swap_cnt = 0;
    int minIdx;
    for (int i=0; i<len-1; ++i) {
        minIdx = i;
        for (int j=i+1; j<len; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
            ++cmp_cnt;
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            ++swap_cnt;
        }
    }
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
    sort_wrapper(a1, selection_sort<int>);
    sort_wrapper(a2, selection_sort_optim<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    vector<int> b2 = b1;
    sort_wrapper(b1, selection_sort<int>);
    sort_wrapper(b2, selection_sort_optim<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    vector<int> c2 = c1;
    sort_wrapper(c1, selection_sort<int>);
    sort_wrapper(c2, selection_sort_optim<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {2, algo::GREEN},
        {1, algo::GREEN}, {3, algo::GREEN}
    };
    vector<algo::Ball> d2 = d1;
    sort_wrapper(d1, selection_sort<algo::Ball>);
    sort_wrapper(d2, selection_sort_optim<algo::Ball>);
}