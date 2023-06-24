#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, median;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> S[i];
    sort(S.begin() + 1, S.end());
    median = (n + 1) / 2;
    cout << S[1] << " ";
    cout << S[median] << " ";
    cout << S[n];

    return 0;
}
