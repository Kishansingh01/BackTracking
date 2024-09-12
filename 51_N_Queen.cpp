//   Leetecode 51


class Solution {
public:
    bool inbound(int i, int j, int A) {
        return i >= 0 && j >= 0 && i < A && j < A;
    }

    bool issafe(int r, int c, vector<string>& temp, int A) {
        // Check row and column
        for (int k = 0; k < A; k++) {
            if (temp[k][c] == 'Q' || temp[r][k] == 'Q') return false;
        }

        // Check diagonals
        for (int l = 0; l < A; l++) {
            if (inbound(r - l, c - l, A) && temp[r - l][c - l] == 'Q') return false;
            if (inbound(r + l, c - l, A) && temp[r + l][c - l] == 'Q') return false;
            if (inbound(r + l, c + l, A) && temp[r + l][c + l] == 'Q') return false;
            if (inbound(r - l, c + l, A) && temp[r - l][c + l] == 'Q') return false;
        }
        return true;
    }

    void fnc(vector<vector<string>>& ans, vector<string>& temp, int A, int row) {
        if (row == A) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < A; i++) {
            if (issafe(row, i, temp, A)) {
                temp[row][i] = 'Q';
                fnc(ans, temp, A, row + 1);
                temp[row][i] = '.';  
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        fnc(ans, temp, n, 0);
        return ans;
    }
};
