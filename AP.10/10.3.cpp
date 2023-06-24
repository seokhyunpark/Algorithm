#include <iostream>
#include <vector>
using namespace std;

vector<int> vcolor;
vector<vector<int> > W;
int n, m, k, cnt;
bool found = false;

bool promising(int i) {
    int j = 1;
    bool flag = true;
    while (j < i && flag) {
        if (W[i][j] && vcolor[i] == vcolor[j])
            flag = false;
        j++;
    }
    return flag;
}

void m_coloring(int i) {
    int color;

    if (promising(i)) {
        if (i == n) {
            cnt++;
            if (!found)
                found = true;
        }
        else {
            for (color = 1; color <= m; color++) {
                vcolor[i + 1] = color;
                m_coloring(i + 1);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    W.resize(n + 1);
    vcolor.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        W[i].resize(n + 1);
    }
    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        W[u][v] = 1; W[v][u] = 1;
    }
    m_coloring(0);

    for (m = 1; m <= n; m++) {
        cnt = 0;
        m_coloring(0);
        if (found) {
            cout << m << endl << cnt << endl;
            break;
        }
    }

    return 0;
}
