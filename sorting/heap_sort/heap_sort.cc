#include "../common.h"
#include "../ball.h"

using namespace std;

template <typename T>
class MinHeap {
public:
    MinHeap() {}

    void push(const T &e) {
        int hole = m_arr.size(), pa;
        m_arr.push_back(e);
        while (hole > 0) {
            pa = (hole - 1) / 2;
            if (m_arr[hole] < m_arr[pa]) {
                swap(m_arr[hole], m_arr[pa]);
                hole = pa;
            } else {
                break;
            }
        }
    }

    void pop(T &e) {
        if (m_arr.empty()) return;
        e = m_arr[0];
        m_arr[0] = *m_arr.rbegin();
        m_arr.pop_back();
        int idx = 0, sz = m_arr.size();
        int child = 2 * idx + 1;
        while (child < sz) {
            if (child + 1 < sz && m_arr[child+1] < m_arr[child]) {
                ++child;
            }
            if (m_arr[child] < m_arr[idx]) {
                swap(m_arr[child], m_arr[idx]);
                idx = child;
            } else {
                break;
            }
        }
    }

private:
    vector<T> m_arr;
};

template <typename T>
void heap_sort(vector<T> &arr) {
    MinHeap<T> hp;
    for (const auto &e : arr) {
        hp.push(e);
    }
    for (auto &e : arr) {
        hp.pop(e);
    }
}

template <typename T, typename F>
void sort_wrapper(vector<T> &arr, F sort_func) {
    cout << "before sort: " << arr << endl;
    sort_func(arr);
    cout << "after  sort: " << arr << endl;
    cout << endl;
}

int main() {
    vector<int> a1{1, 3, 2, 0, 6, 4, 5};
    sort_wrapper(a1, heap_sort<int>);
    
    vector<int> b1{0, 1, 2, 3, 4, 5, 6};
    sort_wrapper(b1, heap_sort<int>);

    vector<int> c1{6, 5, 4, 3, 2, 1, 0};
    sort_wrapper(c1, heap_sort<int>);

    vector<algo::Ball> d1{
        {2, algo::RED}, {0, algo::BLUE}, {3, algo::RED}, {2, algo::GREEN},
        {5, algo::BLUE}, {0, algo::GREEN}, {3, algo::GREEN}, {0, algo::RED}
    };
    sort_wrapper(d1, heap_sort<algo::Ball>);
}