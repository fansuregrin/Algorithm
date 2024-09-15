#include "../common.h"
#include "../ball.h"

using namespace std;

template <typename T>
void insertion_sort(vector<T> &arr, int &cmp_cnt, int &move_cnt) {
    int len = arr.size();
    cmp_cnt = 0, move_cnt = 0;
    for (int i=1; i<len; ++i) {
        int j = i-1;
        // 在有序部分中查找待插入的位置
        while (j>=0 && arr[j]>arr[i]) {
            --j;
            ++cmp_cnt;
        }
        if (j >= 0) ++cmp_cnt;
        T t = arr[i];
        // 将 arr[j+1] ~ arr[i-1] 向后移动一个位置
        for (int k=i; k>j+1; --k) {
            arr[k] = arr[k-1];
            ++move_cnt;
        }
        // 插入
        arr[j+1] = t;
    }
}

template <typename T, typename F>
void sort_wrapper(vector<T> &arr, F sort_func) {
    cout << "before sort: " << arr << endl;
    int cmp_cnt, move_cnt;
    sort_func(arr, cmp_cnt, move_cnt);
    cout << "after  sort: " << arr << endl;
    cout << "array size: " << arr.size()
         << ", compare count: " << cmp_cnt
         << ", move count: " << move_cnt << '\n' << endl;
}

int main() {
    vector<int> a1{1, 3, 2, 0, 6, 4, 5};
    sort_wrapper(a1, insertion_sort<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    sort_wrapper(b1, insertion_sort<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    sort_wrapper(c1, insertion_sort<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {2, algo::GREEN},
        {1, algo::GREEN}, {3, algo::GREEN}
    };
    sort_wrapper(d1, insertion_sort<algo::Ball>);
}