#include <iostream>
#include <vector>

using namespace std;

int n = 6;
vector<int> permutation;
bool chosen[10]; // Tracks visited elements

void search() {
    // Base Case: A complete permutation of length n has been formed
    if ((int)permutation.size() == n) {
        for (int x : permutation) cout << x << " ";
        cout << "\n";
        return;
    }
    
    // Try adding each unchosen element to the permutation
    for (int i = 0; i < n; i++) {
        if (chosen[i]) continue; // Skip if already placed
        
        chosen[i] = true;
        permutation.push_back(i);
        
        search(); // Recursive step
        
        // Backtrack
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main() {
    search();
    return 0;
}