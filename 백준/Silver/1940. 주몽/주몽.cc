#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[15000];
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] + a[j] == M) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}