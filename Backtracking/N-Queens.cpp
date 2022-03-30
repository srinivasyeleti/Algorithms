//N-Queens using backtracking
#include<bits/stdc++.h>
using namespace std;

int board[8][8];

bool valid(int n, int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i][c])
            return false;
    }

    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return false;
    }
    return true;
}

void N_Queens (int n, int i) {
    if (i == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0)
                    cout << ". ";
                else
                    cout << "Q "; 
            }
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for (int j = 0; j < n; j++) {
        if (valid(n, i, j)) {
            board[i][j] = 1;
            N_Queens(n, i + 1);
        }
        board[i][j] = 0;
    }
    return;
}

int main() {
    int n ;
    cout << "Enter the size of the board : ";
    cin >> n;
    memset(board, 0, sizeof board);

    N_Queens(n, 0); 
    return 0;
}
