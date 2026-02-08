// LeetCode 127: Word Ladder
//
// Approach: Breadth First Search (BFS)
//
// Explanation:
// - Each word represents a node
// - An edge exists between two words if they differ by exactly one character
// - We need the shortest transformation sequence from beginWord to endWord
// - BFS is ideal because all edges have equal weight (1 transformation)
//
// Idea:
// - Store all words in a set for O(1) lookup
// - Start BFS from beginWord
// - At each step, change one character at a time (26 possibilities)
// - If the transformed word exists in the set, push it into the queue
// - Remove visited words from the set to avoid revisiting
//
// Level represents the length of the transformation sequence
//
// Time Complexity:
// - For each word, we try L positions and 26 characters
// - O(N * L * 26), where N = number of words, L = word length
//
// Space Complexity:
// - Queue + Hash Set
// - O(N)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Store all words in a set for fast lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present, transformation is impossible
        if (st.find(endWord) == st.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1; // Transformation sequence length

        // BFS traversal
        while (!q.empty()) {
            int n = q.size();

            // Process all words at the current level
            while (n--) {
                string element = q.front();
                q.pop();

                // If we reach the endWord
                if (element == endWord) {
                    return level;
                }

                // Try changing each character
                for (int i = 0; i < element.size(); i++) {
                    char original = element[i];

                    // Try all possible characters from 'a' to 'z'
                    for (int j = 0; j < 26; j++) {
                        element[i] = j + 'a';

                        // If the transformed word exists
                        if (st.find(element) != st.end()) {
                            q.push(element);
                            st.erase(element); // Mark as visited
                        }
                    }

                    // Restore original character
                    element[i] = original;
                }
            }

            // Increase level after finishing current layer
            level++;
        }

        // If transformation is not possible
        return 0;
    }
};
