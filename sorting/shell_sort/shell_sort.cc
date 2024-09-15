#include "../common.h"
#include "../ball.h"

using namespace std;

// 初始步长为数组长度的一半，步长每次减半直到 1
template <typename T>
void shell_sort1(vector<T> &arr, int &cmp_cnt, int &swap_cnt) {
    int len = arr.size();
    cmp_cnt = 0, swap_cnt = 0;
    int step = len / 2;
    while (step >= 1) {
        for (int i=step; i<len; ++i) {
            int j = i;
            for (; j>=step && arr[j]<arr[j-step]; j-=step) {
                swap(arr[j], arr[j-step]);
                ++cmp_cnt;
                ++swap_cnt;
            }
            if (j >= step) {
                ++cmp_cnt;
            }
        }
        step /= 2;
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
    sort_wrapper(a1, shell_sort1<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    sort_wrapper(b1, shell_sort1<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    sort_wrapper(c1, shell_sort1<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {3, algo::RED}, {2, algo::GREEN},
        {5, algo::BLUE}, {0, algo::GREEN}, {3, algo::GREEN}, {0, algo::RED}
    };
    sort_wrapper(d1, shell_sort1<algo::Ball>);
}