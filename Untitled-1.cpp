#include <iostream>
#include <vector>

using namespace std;

int n = 3;
vector<int> subset;

void search(int k) {
    // Base Case: All choices made for elements 0 to n-1
    if (k == n) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
        return;
    }
    
    // Choice 1: Exclude k from subset
    search(k + 1);
    
    // Choice 2: Include k in subset
    subset.push_back(k);
    search(k + 1);
    subset.pop_back(); // Backtracking step
}

int main() {
    search(0);
    return 0;
}