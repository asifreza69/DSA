class Solution {
public:

    int m, n;

    // 4 directions
    vector<vector<int>> dir = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };

    bool find(int i,
              int j,
              vector<vector<char>>& board,
              string word,
              int idx) {

        // Current character mismatch
        if(board[i][j] != word[idx]) {
            return false;
        }

        // Entire word matched
        if(idx == word.size() - 1) {
            return true;
        }

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '$';

        for(auto &it : dir) {

            int x = i + it[0];
            int y = j + it[1];

            if(x >= 0 && x < m &&
               y >= 0 && y < n &&
               board[x][y] != '$' &&
               find(x, y, board, word, idx + 1)) {

                board[i][j] = temp;
                return true;
            }
        }

        // Backtrack
        board[i][j] = temp;
        return false;
    }

    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words) {

        m = board.size();
        n = board[0].size();

        set<string> ans;

        // Check every word
        for(auto &word : words) {

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {

                    if(board[i][j] == word[0] &&
                       find(i, j, board, word, 0)) {

                        ans.insert(word);
                    }
                }
            }
        }

        return vector<string>(
            ans.begin(), ans.end()
        );
    }
};

/*
==========================
🔥 WORD BOGGLE
==========================

Goal:
Find all dictionary words that
can be formed in the board.

--------------------------------

🧠 Core Idea:

For every word:
- Start DFS from matching cells.
- Try to match next characters.
- Mark visited cells temporarily.
- Restore them during backtracking.

--------------------------------

Rules:
- Adjacent cells can be used.
- Same cell cannot be reused
  in one word.

--------------------------------

Algorithm:

1. For each word:
2. Traverse every cell.
3. If first character matches:
      run DFS.
4. If word found:
      insert into answer set.

--------------------------------

Backtracking:

Mark current cell as visited.
Explore neighbours.
Restore original character.

--------------------------------

⏱️ Time Complexity:
O(W * m * n * 4^L)

W = number of words
L = average word length

--------------------------------

🧠 Space Complexity:
O(L)

Recursion stack depth.

--------------------------------

🧩 Pattern:
Backtracking + DFS

--------------------------------

🎯 Category:
Graph → Grid DFS

--------------------------------

🧠 Interview One-Liner:

For each word, run DFS with
backtracking from every matching
starting cell.

*/
