#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a cell in the grid
struct Cell {
    int row, col, time;
    Cell(int r, int c, int t) : row(r), col(c), time(t) {}
};

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0; // Empty grid
    int cols = grid[0].size();
    
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<Cell> q;
    int freshOranges = 0;
    
    // Initialize the queue with rotten oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push(Cell(i, j, 0));
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }
    
    int minTime = 0;
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        minTime = current.time;
        
        for (const vector<int>& dir : directions) {
            int newRow = current.row + dir[0];
            int newCol = current.col + dir[1];
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 2; // Make the fresh orange rotten
                q.push(Cell(newRow, newCol, current.time + 1));
                freshOranges--;
            }
        }
    }
    
    // If there are still fresh oranges, return -1 (impossible)
    return freshOranges == 0 ? minTime : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int minTime = orangesRotting(grid);
    if (minTime != -1) {
        cout << "Minimum time to rot all oranges: " << minTime << endl;
    } else {
        cout << "It is not possible to rot all oranges." << endl;
    }

    return 0;
}
