#include <iostream>

using namespace std;

int n = 4;
int count_solutions = 0;
// Arrays to track occupied paths in O(1) time
bool column[20], diag1[40], diag2[40];

void search(int y) {
    // Base Case: All rows successfully assigned
    if (y == n) {
        count_solutions++;
        return;
    }
    
    for (int x = 0; x < n; x++) {
        // Prune path if column or diagonals are under attack
        if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        
        // Place Queen (Lock column and diagonals)
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
        
        search(y + 1); // Move to next row
        
        // Backtrack (Unlock column and diagonals)
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
    }
}

int main() {
    search(0);
    cout << "Valid configurations: " << count_solutions << "\n";
    return 0;
}