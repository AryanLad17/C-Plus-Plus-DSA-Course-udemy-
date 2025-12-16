#include <iostream>
#include <vector>

using namespace std;

// We define the size of the maze
const int n = 4; 
int m[n][n] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int sol[n][n]; // Matrix to store the path taken

void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool rim(int i, int j) {
    // 1. Success condition: Reached the bottom-right corner
    if (i == n - 1 && j == n - 1) {
        sol[i][j] = 1;
        return true;
    }

    // 2. Boundary and Obstacle check
    // Check if (i,j) is within bounds and the cell is a path (1)
    if (i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1) {
        
        // Mark current cell as part of solution path
        sol[i][j] = 1;
        
        // Mark as visited in the maze to prevent infinite recursion (cycles)
        m[i][j] = 0; 

        // Move Right
        if (rim(i, j + 1)) return true;
        
        // Move Down
        if (rim(i + 1, j)) return true;
        
        // Move Left
        if (rim(i, j - 1)) return true;
        
        // Move Up
        if (rim(i - 1, j)) return true;

        // 3. BACKTRACK: If none of the moves work, unmark this cell
        sol[i][j] = 0;
        m[i][j] = 1; 
        return false;
    }

    return false;
}

int main() {
    // Initialize solution matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }

    if (rim(0, 0)) {
        cout << "Path found (1s indicate the path):" << endl;
        printSolution();
    } else {
        cout << "No path exists to the destination." << endl;
    }

    return 0;
}