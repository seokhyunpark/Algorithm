#include <iostream>
#include <vector>
using namespace std;

vector<int> vindex;
vector<vector<int> > W;
int n, m, cnt = 0;

bool promising(int i) {
    int j;
    bool flag;
    if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
        flag = false;
    else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
        flag = false;
    else {
        flag = true;
        j = 1;
        while (j < i && flag) {
            if (vindex[i] == vindex[j])
                flag = false;
            j++;
        }
    }
    return flag;
}

void hamiltonian(int i) {
    int j;
    if (promising(i)) {
        if (i == n - 1)
            cnt++;
        else {
            for (j = 2; j <= n; j++) {
                vindex[i + 1] = j;
                hamiltonian(i + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vindex.resize(n + 1);
    W.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        W[i].resize(n + 1);
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        W[u][v] = 1; W[v][u] = 1;
    }
    vindex[0] = 1;
    hamiltonian(0);
    cout << cnt << endl;

    return 0;
}
