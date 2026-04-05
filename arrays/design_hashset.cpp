#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class MyHashSet {
public:
    int M = 15000;
    vector<list<int>> vec;

    int getkey(int key) {
        return key % M;
    }

    MyHashSet() {
        vec.resize(M);
    }
    
    void add(int key) {
        int index = getkey(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);

        if (itr == vec[index].end()) {
            vec[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getkey(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);

        if (itr != vec[index].end()) {
            vec[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index = getkey(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);

        return itr != vec[index].end();
    }
};

/*
Problem: Design HashSet (LeetCode 705)

Approach:
Used hashing with separate chaining to handle collisions.

Data Structure:
- Vector of lists (buckets)
- Each index stores a list of elements with same hash

Hash Function:
index = key % M

Operations:
1. add(key):
   - Check if key already exists
   - If not, insert into bucket

2. remove(key):
   - Find key in bucket and erase it

3. contains(key):
   - Search key in bucket

Time Complexity:
- Average: O(1)
- Worst: O(n) (if many collisions)

Space Complexity:
O(M + n)

Key Insight:
Collision handling using chaining avoids overwriting elements.
*/
