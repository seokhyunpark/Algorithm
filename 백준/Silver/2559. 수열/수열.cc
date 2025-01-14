#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int N, K;
int psum[100001];
int temp, result = -100 * 100000;

int main() {
    FAST_IO;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    for (int i = K; i <= N; i++) {
        result = max(psum[i] - psum[i - K], result);
    }
    cout << result << "\n";

    return 0;
}