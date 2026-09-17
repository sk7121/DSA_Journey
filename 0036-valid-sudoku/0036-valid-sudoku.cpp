class Solution {
public:
    bool row_wise(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;

            for (int j = 0; j < 9; j++) {
                char value = board[i][j];

                if (value == '.')
                    continue;

                if (st.count(value))
                    return false;

                st.insert(value);
            }
        }

        return true;
    }

    bool column_wise(vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {
            unordered_set<char> st;

            for (int i = 0; i < 9; i++) {
                char value = board[i][j];

                if (value == '.')
                    continue;

                if (st.count(value))
                    return false;

                st.insert(value);
            }
        }

        return true;
    }

    bool box_wise(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> st;

                for (int i_idx = i; i_idx < i + 3; i_idx++) {
                    for (int j_idx = j; j_idx < j + 3; j_idx++) {
                        char value = board[i_idx][j_idx];

                        if (value == '.')
                            continue;

                        if (st.count(value))
                            return false;

                        st.insert(value);
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return row_wise(board) && column_wise(board) && box_wise(board);
    }
};