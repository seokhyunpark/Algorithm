#include <iostream>
#include <vector>
using namespace std;

void cal(int n, vector<vector<int> > &temp, vector<vector<int> > &x, vector<vector<int> > &y);

int main() {
    int n, b; cin >> n >> b;

    vector<vector<int> > S(n + 1, vector<int>(n + 1));
    vector<vector<int> > temp(n + 1, vector<int>(n + 1));
    vector<vector<int> > ans(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> S[i][j];
        ans[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 == 1)
            cal(n, temp, ans, S);
        cal(n, temp, S, S);
        b /= 2;
    }
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j < n; j++)
            cout << ans[i][j] << " ";
        cout << ans[i][j] << endl;
    }

    return 0;
} 

void cal(int n, vector<vector<int> > &temp, vector<vector<int> > &x, vector<vector<int> > &y) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = 0;
            for (int k = 1; k <= n; k++)
                temp[i][j] += x[i][k] * y[k][j];
            temp[i][j] %= 1000;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            x[i][j] = temp[i][j];
    }
}
