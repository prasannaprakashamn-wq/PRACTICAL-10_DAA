#include <iostream>
using namespace std;

int main() {
    int n = 4, m = 5;

    int e[5][3] = {
        {1, 2, 10},
        {1, 3, 6},
        {1, 4, 5},
        {2, 4, 15},
        {3, 4, 4}
    };

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (e[i][2] > e[j][2]) {
                for (int k = 0; k < 3; k++) {
                    int temp = e[i][k];
                    e[i][k] = e[j][k];
                    e[j][k] = temp;
                }
            }
        }
    }

    int parent[5] = {0, 1, 2, 3, 4};
    int total = 0, count = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < m && count < n - 1; i++) {
        int u = e[i][0];
        int v = e[i][1];

        int a = u, b = v;

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b) {
            cout << u << " - " << v
                 << " : " << e[i][2] << endl;

            parent[a] = b;
            total += e[i][2];
            count++;
        }
    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}

