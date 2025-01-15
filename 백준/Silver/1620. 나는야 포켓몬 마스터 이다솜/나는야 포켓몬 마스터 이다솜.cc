#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int N, M, temp;
map<string, int> mp;
string arr[100001];
string s;

int main() {
    FAST_IO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        mp[s] = i;
        arr[i] = s;
    }
    for (int i = 1; i <= M; i++) {
        cin >> s;
        temp = atoi(s.c_str());
        if (temp == 0) {
            cout << mp[s] << "\n";
        }
        else {
            cout << arr[temp] << "\n";
        }
    }

    return 0;
}