#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> P;

int dir[8][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};
int n, m, cnt;
bool path;

void hamiltonian(int d, int i) {
    P[i] = 1;
    if (d == n * m - 1) {
        if (path) {
            for (int k = 0; k < adj[i].size(); k++) {
                if (adj[i][k] == 0) {
                    cnt++;
                    break;
                }
            }
        }
        else
            cnt++;
    }
    else {
        for (int k = 0; k < adj[i].size(); k++) {
            if (P[adj[i][k]] == 0)
                hamiltonian(d + 1, adj[i][k]);
        }
    }
    P[i] = 0;
}

int main() {
    cin >> n >> m;
    adj.resize(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            adj[i * m + j] = vector<int>();
            for (int k = 0; k < 8; k++) {
                int n_i = i + dir[k][0];
                int n_j = j + dir[k][1];
                if (0 <= n_i && n_i < n && 0 <= n_j && n_j < m) {
                    adj[i * m + j].push_back(n_i * m + n_j);
                }
            }

        }
    }
    path = true;
    cnt = 0;
    P.resize(n * m);
    hamiltonian(0, 0);
    cout << cnt << endl;

    int T; cin >> T;
    path = false;
    for (int k = 0; k < T; k++) {
        int i, j; cin >> i >> j; cnt = 0;
        P.assign(n * m, 0);
        hamiltonian(0, i * m + j);
        cout << cnt << endl;
    }

    return 0;
}
