#include <iostream>
#include <cstdlib>  // For abs()
using namespace std;

void nqueens(int);
int place(int[], int);
void printsolution(int, int[]);

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    nqueens(n);
    return 0;
}

void nqueens(int n) {
    int x[10], count = 0, k = 1;
    x[k] = 0;

    while (k != 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && (!place(x, k))) {
            x[k] = x[k] + 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                count++;
                cout << "Solution " << count << endl;
                printsolution(n, x);
            } else {
                k++;
                x[k] = 0;  // Initialize the next row
            }
        } else {
            k--;  // Backtrack
        }
    }
}

int place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)) {
            return 0;
        }
    }
    return 1;
}

void printsolution(int n, int x[]) {
    char c[10][10];
    
    // Initialize the board
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 'X';
        }
    }
    
    // Place queens on the board
    for (int i = 1; i <= n; i++) {
        c[i][x[i]] = 'Q';
    }

    // Print the board
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

