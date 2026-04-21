#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

class FreqStack {
public:
    unordered_map<int,int> mp;
    priority_queue<tuple<int,int,int>> pq;
    int time = 0;

    FreqStack() {}

    void push(int val) {
        mp[val]++;
        pq.push({mp[val], time++, val});
    }

    int pop() {
        auto [freq, t, val] = pq.top();
        pq.pop();
        mp[val]--;
        return val;
    }
};

/*
Approach: Max Heap (Priority Queue)

Logic:
- Store (frequency, time, value)
- Heap ensures:
   → highest frequency first
   → if tie → most recent

Time Complexity:
Push: O(log n)
Pop: O(log n)

Key Insight:
Convert stack behavior into heap ordering
*/
