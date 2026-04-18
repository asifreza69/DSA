#include <queue>
using namespace std;

/*
====================================================
Approach 1: Two Queues
====================================================
Push: O(1)
Pop: O(n)
Top: O(n)
*/

class MyStack_TwoQueues {
public:
    queue<int> q1, q2;

    MyStack_TwoQueues() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int t = q1.front();
        q1.pop();

        swap(q1, q2);
        return t;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int t = q1.front();
        q2.push(t);
        q1.pop();

        swap(q1, q2);
        return t;
    }

    bool empty() {
        return q1.empty();
    }
};


/*
====================================================
Approach 2: Single Queue (Optimized)
====================================================
Push: O(n)
Pop: O(1)
Top: O(1)
*/

class MyStack_OneQueue {
public:
    queue<int> q;

    MyStack_OneQueue() {}

    void push(int x) {
        q.push(x);

        // Rotate queue to bring new element to front
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/*
====================================================
Key Insight:
====================================================
- Stack = LIFO
- Queue = FIFO

We simulate LIFO using queue operations:
- Two queues → transfer elements
- One queue → rotate elements

====================================================
*/
