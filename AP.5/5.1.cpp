#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

int bin(int n, int k, vector<vector<int> > &DP) {
    cnt++;
    if (k == 0 || k == n)
        DP[n][k] = 1;
    else if (DP[n][k] == 0)
        DP[n][k] = (bin(n - 1, k, DP) + bin(n - 1, k - 1, DP)) % 10007;
    return DP[n][k];
}

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int> > DP(n + 1, vector<int>(k + 1));
    cout << bin(n, k, DP) << endl << cnt;
    
    return 0;
}
