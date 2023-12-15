#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool valid(int x, int y, int boardSize) {
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize) {
        return true;
    }
    return false;
}

vector<vector<bool>> markPos(vector<vector<bool>>& visited, int boardSize, int x, int y, bool flag) {
    if (valid(x - 1, y - 2, boardSize)) {
        visited[x - 1][y - 2] = flag;
    }

    if (valid(x - 1, y + 2, boardSize)) {
        visited[x - 1][y + 2] = flag;
    }

    if (valid(x + 1, y - 2, boardSize)) {
        visited[x + 1][y - 2] = flag;
    }

    if (valid(x + 1, y + 2, boardSize)) {
        visited[x + 1][y + 2] = flag;
    }

    if (valid(x - 2, y - 1, boardSize)) {
        visited[x - 2][y - 1] = flag;
    }

    if (valid(x - 2, y + 1, boardSize)) {
        visited[x - 2][y + 1] = flag;
    }

    if (valid(x + 2, y - 1, boardSize)) {
        visited[x + 2][y - 1] = flag;
    }

    if (valid(x + 2, y + 2, boardSize)) {
        visited[x + 2][y + 2] = flag;
    }
    return visited;
}

long long placeKnight2(vector<vector<bool>>& visited, int boardSize) {
    long long numPoss = 0;
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            if (!visited[x][y]) {
                numPoss++;
            }
        }
    }    
    return numPoss;
}

long long countBackTrack(int boardSize) {
    long long numPoss = 0;
    vector<vector<bool>> visited(boardSize, vector<bool> (boardSize, false));
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            // Mark position of 1st knight
            visited[x][y] = true;

            // Mark affected positions in the board after placing the 1st knight.
            visited = markPos(visited, boardSize, x, y, true);

            // Count number of ways for placing the 2nd knight given 1st knight at (x, y)
            numPoss += placeKnight2(visited, boardSize);

            // Unmark position of 1st knight
            // visited[x][y] = false;
            vector<vector<bool>> visited(boardSize, vector<bool> (boardSize, false));

            // // Unmark affected positions in the board after taking out the 1st knight.
            // visited = markPos(visited, boardSize, x, y, false);
        }
    }

    // if (boardSize == 3) {
    //     cout << numPoss << endl;
    // }

    return numPoss*2;
}

int main() {
    int n;
    long long cntPoss = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 0 << endl;
        }
        else {
            cntPoss = countBackTrack(i);
            cout << cntPoss << endl;
        }
    }

    return 0;
}