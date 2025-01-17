#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (cin >> n) {
        ll i = 1;
        int ret = 1;
        while (true) {
            if (i % n == 0) {
                cout << ret << "\n";
                break;
            }
            i = (i * 10) + 1;
            i %= n;
            ret++;
        }
    }

    return 0;
}