class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                string row=to_string(board[i][j])+"at row"+to_string(i);
                string col=to_string(board[i][j])+ "at col"+to_string(j);
                string box=to_string(board[i][j])+ "at box"+to_string(i/3)+to_string(j/3);
                if(st.find(row)!=st.end() ||st.find(col)!=st.end()||st.find(box)!=st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
                
            }
        }
        return true;
    }
};
/*
Problem: Valid Sudoku (LeetCode 36)

Approach:
Used hashing (unordered_set) to track duplicates in rows, columns, and 3x3 boxes.

Logic:
- Traverse each cell
- Skip '.'
- Create unique keys for:
  1. Row → "value row index"
  2. Column → "value col index"
  3. Box → "value box index"
- If any key already exists → invalid sudoku

Time Complexity:
O(1) → because grid size is fixed (9x9)

Space Complexity:
O(1) → set size is bounded (max ~243 entries)

Note:
If grid size is generalized to n×n:
- Time: O(n²)
- Space: O(n²)
*/
