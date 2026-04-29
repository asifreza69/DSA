#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    int capacity;

    // key -> (iterator in DLL, value)
    unordered_map<int, pair<list<int>::iterator,int>> mp;

    // Doubly Linked List to maintain order
    list<int> dll;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Move key to front (most recently used)
    void makerecentuse(int key){
        dll.erase(mp[key].first);     // remove from current position
        dll.push_front(key);          // insert at front
        mp[key].first = dll.begin();  // update iterator
    }

    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        makerecentuse(key);           // mark as recently used
        return mp[key].second;        // return value
    }
    
    void put(int key, int value) {

        // If key already exists → update + move to front
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makerecentuse(key);
            return;
        }

        // Insert new key
        dll.push_front(key);
        mp[key] = {dll.begin(), value};

        // If capacity exceeded → remove LRU (back)
        if(mp.size() > capacity){
            int lru = dll.back();     // least recently used key
            dll.pop_back();           // remove from list
            mp.erase(lru);            // remove from map
        }
    }
};

/*
==========================
🔥 FULL EXPLANATION
==========================

DATA STRUCTURES USED:

1. Doubly Linked List (dll)
   - Stores keys
   - Front = Most Recently Used (MRU)
   - Back  = Least Recently Used (LRU)

2. HashMap (mp)
   - key → (iterator to DLL, value)
   - Gives O(1) access

--------------------------------

HOW OPERATIONS WORK:

GET(key):
- If key not present → return -1
- Else:
    → Move key to front (recent use)
    → Return value

PUT(key, value):
- If key exists:
    → Update value
    → Move to front

- Else:
    → Insert at front
    → If size > capacity:
        → Remove key from back (LRU)

--------------------------------

KEY INSIGHT:

We must support:
- O(1) access → HashMap
- O(1) removal & insertion → Doubly Linked List

--------------------------------

WHY DLL + MAP?

- DLL gives ordering
- Map gives direct access

--------------------------------

EXAMPLE:

capacity = 2

put(1,1)
List: [1]

put(2,2)
List: [2,1]

get(1)
List: [1,2]

put(3,3)
→ remove LRU (2)
List: [3,1]

--------------------------------

TIME COMPLEXITY:
get → O(1)
put → O(1)

SPACE:
O(capacity)

--------------------------------

INTERVIEW ONE LINER:

"Use hashmap + doubly linked list to maintain order and achieve O(1) operations"
*/
