// LeetCode 953: Verifying an Alien Dictionary
// Approach: Map alien character order and compare adjacent words
// Time Complexity: O(N * L)
// Space Complexity: O(1)

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;

        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];

            int mini = min(w1.size(), w2.size());
            bool flag = false;

            for(int j = 0; j < mini; j++){
                if(w1[j] != w2[j]){
                    if(mp[w1[j]] > mp[w2[j]]){
                        return false;
                    }
                    flag = true;
                    break;
                }
            }

            // Prefix case
            if(!flag && w1.size() > w2.size()){
                return false;
            }
        }
        return true;
    }
};
