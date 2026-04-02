// LeetCode 49: Group Anagrams

// Approach:
// 1. Use a hashmap where key = sorted string
// 2. For each string in input:
//    - Sort the string → this becomes the key
//    - Store original string in map[key]
// 3. All anagrams will have same sorted key
// 4. Return all values of hashmap as result

// Time Complexity: O(n * k log k)
// n = number of strings, k = max length of string (sorting cost)
// Space Complexity: O(n * k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
