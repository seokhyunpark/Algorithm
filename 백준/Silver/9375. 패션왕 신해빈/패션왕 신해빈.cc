#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_base(false); cin.tie(NULL); cout.tie(NULL);

int m, n;
long long result;
map<string, int> mp;
string a, b;

int main() {
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> n;

        mp.clear();
        for (int j = 0; j < n; j++) {
            cin >> a >> b;
            mp[b]++;
        }

        result = 1;
        for (const auto& pair : mp) {
            result *= ((long long)pair.second + 1);
        }
        result--;
        cout << result << "\n";
    }

    return 0;
}