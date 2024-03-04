/*ques: SPOJ WEBSITE: You will be given a 2-dimensional grid of letters. Find the length of the longest path of consecutive letters, starting at 'A'. 
Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).
For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':
ABC
One such path is:

path
Input
Each test case will start with a line contains two integers H, W the height and width of the grid respectively 1 <= H, W <= 50. 
Then H lines follow each of W uppercase letters only. Input terminates with H = 0 and W = 0.
Output
For each test case print “Case C: X” without quotes where C is the case number starting with 1 and X is the solution.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int H, W;
vector<vector<char>> grid;
int dfs(int i, int j, set<pair<int, int>>& visited) {
    int maxLen = 0;
    visited.insert({i, j});

    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) continue;
            int newI = i + di;
            int newJ = j + dj;
            if (newI >= 0 && newI < H && newJ >= 0 && newJ < W &&
                !visited.count({newI, newJ}) &&
                (grid[newI][newJ] == grid[i][j] + 1)) {
                maxLen = max(maxLen, 1 + dfs(newI, newJ, visited));
            }
        }
    }

    visited.erase({i, j});
    return maxLen;
}


int longestConsecutivePath() {
    int maxPath = 0;
    set<pair<int, int>> visited;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'A') {
                maxPath = max(maxPath, dfs(i, j, visited));
            }
        }
    }
    return maxPath;
}
int main() {
    int caseNum = 1;
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0)
            break;
        
        grid.assign(H, vector<char>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> grid[i][j];
            }
        }
        
        int longestPath = longestConsecutivePath();
        cout << "Case " << caseNum << ": " << longestPath+1 << endl;
        caseNum++;
    }
    return 0;
}
