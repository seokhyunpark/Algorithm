#include <iostream>
#include <vector>
using namespace std;

#define INF 0xffff

typedef vector<vector<int> > matrix_t;
typedef vector<pair<int, int> > set_of_edges;
vector<int> touch;

void print_touch(vector<int> touch) {
    int i;
    for (i = 2; i < touch.size() - 1; i++)
        cout << touch[i] << " ";
    cout << touch[i] << endl;
}

void dijkstra(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> length(n + 1);
    touch.resize(n + 1);

    F.clear();
    for (int i = 2; i <= n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }
    print_touch(touch);
    for (int t = 1; t <= n - 1; t++) {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }
        F.push_back(make_pair(touch[vnear], vnear));

        for (int i = 2; i <= n; i++)
            if (length[i] > length[vnear] + W[vnear][i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        print_touch(touch);
        length[vnear] = -1;
    }
}

vector<int> find_path(int u, int v, vector<int> touch) {
    if (u == v) {
        vector<int> path;
        path.insert(path.begin(), u);
        return path;
    }
    else {
        vector<int> path = find_path(u, touch[v], touch);
        path.insert(path.begin(), v);
        return path;
    }
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m-- > 0) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    set_of_edges F;
    dijkstra(n, W, F);
    for (auto e: F)
        cout << e.first << " " << e.second << " " << W[e.first][e.second] << endl;
    
    int t; cin >> t;
    while (t-- > 0) {
        int k; cin >> k;
        vector<int> path = find_path(1, k, touch);
        for (int i = path.size() - 1; i > 0; i--)
            cout << path[i] << " ";
        cout << path[0] << endl;
    }
}
