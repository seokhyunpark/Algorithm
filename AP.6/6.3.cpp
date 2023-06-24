#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m, n;

void lcs(string X, string Y, vector<vector<int> > &C, vector<vector<int> > &B) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 1;
            }
            else {
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);
                if (C[i][j - 1] > C[i - 1][j])
                    B[i][j] = 2;
                else
                    B[i][j] = 3;
            }
        }
    }
}

void get_lcs(int i, int j, vector<vector<int> > &B, string X) {
    if (i == 0 || j == 0)
        return;
    else {
        if (B[i][j] == 1) {
            get_lcs(i - 1, j - 1, B, X);
            cout << X[i];
        }
        else if (B[i][j] == 2)
            get_lcs(i, j - 1, B, X);
        else if (B[i][j] == 3)
            get_lcs(i - 1, j, B, X);
    }
}

int main() {
    string U, V; cin >> U >> V;
    string X = " " + U, Y = " " + V;
    m = X.length(), n = Y.length();

    vector<vector<int> > C(m + 1, vector<int>(n + 1, 0));
    vector<vector<int> > B(m + 1, vector<int>(n + 1, 0));

    lcs(X, Y, C, B);
    cout << C[m - 1][n - 1] << endl;

    get_lcs(m - 1, n - 1, B, X);

    return 0;
}
