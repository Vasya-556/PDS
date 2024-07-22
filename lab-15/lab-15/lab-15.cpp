#include <iostream>
#include <vector>

using namespace std;

void placeQueens(vector<vector<int>>& result, vector<int>& board, int row, int n);
vector<vector<int>> nQueens(int n);

int main() {
    int n;
    cout << "Enter n: "; cin >> n;
    vector<vector<int>> solutions = nQueens(n);
    for (auto& s : solutions) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Number of solutions: " << solutions.size();
}

void placeQueens(vector<vector<int>>& result, vector<int>& board, int row, int n) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        bool isSafe = true;
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(board[i] - col) == row - i) {
                isSafe = false;
                break;
            }
        }
        if (isSafe) {
            board[row] = col;
            placeQueens(result, board, row + 1, n);
            board[row] = -1;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> result;
    vector<int> board(n, -1);
    placeQueens(result, board, 0, n);
    return result;
}
