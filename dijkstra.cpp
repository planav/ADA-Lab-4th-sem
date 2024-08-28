#include <iostream>
#include <limits>
using namespace std;

#define infinity 999 

int main() {
    int n, v, i, u, count, w;
    int cost[10][10], dist[10], flag[10], min;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= n; w++) {
            cin >> cost[i][w];
            if (cost[i][w] == 0) {
                cost[i][w] = infinity;
            }
        }
    }

    cout << "Enter the source node: ";
    cin >> v;

    
    for (i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }
    
    count = 2;
    while (count <= n) {
        min = infinity;

       
        for (w = 1; w <= n; w++) {
            if (dist[w] < min && !flag[w]) {
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;
        count++;

        
        for (w = 1; w <= n; w++) {
            if (dist[u] + cost[u][w] < dist[w] && !flag[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }

    cout << "Shortest path distances from source node " << v << ":\n";
    for (i = 1; i <= n; i++) {
        if (i != v) {
            cout << "To node " << i << " cost = " << dist[i] << endl;
        }
    }

    return 0;
}

