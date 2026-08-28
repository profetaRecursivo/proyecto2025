#include <deque>
#include <functional>
#include <utility>
using namespace std;
struct MinDeque {
    deque<int> dq;
    deque<pair<int, int>> min_dq;
    function<bool(int, int)> comp;
    MinDeque(function<bool(int, int)> c = less<int>()) : comp(c) {}                             //puedes pasar greater<int>()
    void push_back(int x) {
        dq.push_back(x);
        int c = 0;
        while (!min_dq.empty() and comp(x, min_dq.back().first)) {
            c += min_dq.back().second + 1;
            min_dq.pop_back();
        }
        min_dq.push_back({x, c});
    }
    void push_front(int x) {
        dq.push_front(x);
        if (!min_dq.empty() and comp(x, min_dq.front().first)) {
            min_dq.push_front({x, 0});
        } else if (min_dq.empty()) {
            min_dq.push_front({x, 0});
        } else {
            min_dq.front().second++;
        }
    }
    void pop_back() {
        if (dq.empty()) return;
        dq.pop_back();
        if (min_dq.back().second > 0) min_dq.back().second--;
        else min_dq.pop_back();
    }
    void pop_front() {
        if (dq.empty()) return;
        dq.pop_front();
        if (min_dq.front().second > 0) min_dq.front().second--;
        else min_dq.pop_front();
    }
    int get() { return min_dq.front().first; }//min o max
    int front() { return dq.front(); }
    int back() { return dq.back(); }
    bool empty() { return dq.empty(); }
    int size() { return dq.size(); }
};