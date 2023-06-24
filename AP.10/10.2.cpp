#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<bool> include;
vector<vector<int> > subsets;
int W, cnt = 0;

bool promising(int i, int weight, int total) {
    return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

void sum_of_subsets(int i, int weight, int total) {
    if (promising(i, weight, total)) {
        if (weight == W) {
            vector<int> subset;
            for (int j = 1; j <= i; j++) {
                if (include[j]) {
                    subset.push_back(w[j]);
                }
            }
            subsets.push_back(subset);
            cnt++;
        }
        else {
            include[i + 1] = true;
            sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
            include[i + 1] = false;
            sum_of_subsets(i + 1, weight, total - w[i + 1]);
        }
    }
}

int main() {
    int n, total = 0;
    cin >> n >> W;
    w.resize(n + 1);
    include.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        total += w[i];
    }
    sum_of_subsets(0, 0, total);

    cout << cnt << endl;
    if (cnt == 0) {
        cout << endl;
        return 0;
    }
    
    int i, j;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < subsets[i].size() - 1; j++)
            cout << subsets[i][j] << " ";
        cout << subsets[i][j] << endl;
    }


    return 0;
}
