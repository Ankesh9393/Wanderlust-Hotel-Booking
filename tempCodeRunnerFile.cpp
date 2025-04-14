#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // 1-based indexing for convenience
        vector<vector<int>> G(n + 1, vector<int>(n + 1));
        vector<int> p(2 * n + 1); // p[1] to p[2n]

        // Read the grid
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> G[i][j];

        // For each k = i + j, set p[k] using any G[i][j]
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int k = i + j;
                if (p[k] == 0)
                    p[k] = G[i][j];
            }
        }

        // Output p[2] to p[2n]
        for (int i = 2; i <= 2 * n; ++i)
            cout << p[i] << " ";
        cout << "\n";
    }
    return 0;
}
