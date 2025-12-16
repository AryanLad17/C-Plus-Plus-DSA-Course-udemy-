#include <iostream>
#include <vector>

using namespace std;

#define N 4 // Size of the maze (N x N)

int m[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int sol[N][N]; // To store the path taken

// Function to print the solution matrix
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;
}

// Check if move is safe
bool isSafe(int i, int j) {
    return (i >= 0 && i < N && j >= 0 && j < N && m[i][j] == 1);
}

bool solveMaze(int i, int j) {
    // If destination reached
    if (i == N - 1 && j == N - 1) {
        sol[i][j] = 1;
        printSolution();
        return true; 
    }

    if (isSafe(i, j)) {
        // Mark current cell as part of the path
        sol[i][j] = 1;
        m[i][j] = 0; // Mark as visited to avoid infinite loops

        // Move Right
        if (solveMaze(i, j + 1)) return true;
        
        // Move Down
        if (solveMaze(i + 1, j)) return true;
        
        // Move Left
        if (solveMaze(i, j - 1)) return true;
        
        // Move Up
        if (solveMaze(i - 1, j)) return true;

        // BACKTRACK: Unmark this cell
        sol[i][j] = 0;
        m[i][j] = 1; 
        return false;
    }

    return false;
}

int main() {
    // Initialize solution matrix with 0
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            sol[i][j] = 0;

    cout << "Path found in the maze (1s represent the path):" << endl;
    if (!solveMaze(0, 0)) {
        cout << "No solution exists.";
    }

    return 0;
}