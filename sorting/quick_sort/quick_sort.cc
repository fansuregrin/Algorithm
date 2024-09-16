#include <algorithm>
#include "../common.h"
#include "../ball.h"

using namespace std;

template <typename T>
void quick_sort(vector<T> &arr, int start, int end) {
    if (end - start <= 1) {
        return;
    }
    vector<T> low, high;
    T pivot = arr[start];
    high.push_back(pivot);
    for (int i=start+1; i<end; ++i) {
        arr[i] < pivot ? low.push_back(arr[i]) : high.push_back(arr[i]);
    }
    auto it = std::copy(low.begin(), low.end(), arr.begin()+start);
    std::copy(high.begin(), high.end(), it);
    quick_sort(arr, start, start + low.size());
    quick_sort(arr, start + low.size() + 1, end);
}

template <typename T>
void quick_sort_optim(vector<T> &arr, int start, int end) {
    if (end - start <= 1) {
        return;
    }
    T pivot = arr[end - 1];
    int t = start;
    for (int i=start; i<end; ++i) {
        if (arr[i] < pivot) {
            if (i != t) swap(arr[i], arr[t]);
            ++t;
        }
    }
    swap(arr[end-1], arr[t]);
    quick_sort_optim(arr, start, t);
    quick_sort_optim(arr, t + 1, end);
}

template <typename T, typename F>
void sort_wrapper(vector<T> &arr, F sort_func) {
    cout << "before sort: " << arr << endl;
    sort_func(arr, 0, arr.size());
    cout << "after  sort: " << arr << endl;
    cout << endl;
}

int main() {
    vector<int> a1{1, 3, 2, 0, 6, 4, 5};
    vector<int> a2 = a1;
    sort_wrapper(a1, quick_sort<int>);
    sort_wrapper(a2, quick_sort_optim<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    vector<int> b2 = b1;
    sort_wrapper(b1, quick_sort<int>);
    sort_wrapper(b2, quick_sort_optim<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    vector<int> c2 = c1;
    sort_wrapper(c1, quick_sort<int>);
    sort_wrapper(c2, quick_sort_optim<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {3, algo::RED}, {2, algo::GREEN},
        {5, algo::BLUE}, {0, algo::GREEN}, {3, algo::GREEN}, {0, algo::RED}
    };
    vector<algo::Ball> d2 = d1;
    sort_wrapper(d1, quick_sort<algo::Ball>);
    sort_wrapper(d2, quick_sort_optim<algo::Ball>);
}