#include <vector>
#include <list>
using namespace std;

class MyHashMap {
public:
    vector<list<pair<int,int>>> bucket;
    int size = 10000;

    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        int index = key % size;
        auto &chain = bucket[index];

        for (auto &it : chain) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }

        chain.push_back({key, value});
    }
    
    int get(int key) {
        int index = key % size;
        auto &chain = bucket[index];

        for (auto &it : chain) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % size;
        auto &chain = bucket[index];

        for (auto it = chain.begin(); it != chain.end(); it++) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }
};

/*
Problem: Design HashMap (LeetCode 706)

Approach:
Used hashing with separate chaining (list of key-value pairs).

Data Structure:
- Vector of lists (buckets)
- Each bucket stores (key, value) pairs

Hash Function:
index = key % size

Operations:
1. put(key, value):
   - If key exists → update value
   - Else → insert new pair

2. get(key):
   - Search in bucket and return value
   - If not found → return -1

3. remove(key):
   - Find key and erase from list

Time Complexity:
- Average: O(1)
- Worst: O(n)

Space Complexity:
O(n)

Key Insight:
Proper deletion is important → erase node instead of marking.
*/
