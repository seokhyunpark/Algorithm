#include <bits/stdc++.h>
using namespace std;

int A, B, C, t1, t2, price;
int cnt[100];

int main() {
    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++) {
        cin >> t1 >> t2;
        for (int i = t1; i < t2; i++) {
            cnt[i]++;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (cnt[i] == 1) {
            price += A;
        }
        else if (cnt[i] == 2) {
            price += B * 2;
        }
        else if (cnt[i] == 3) {
            price += C * 3;
        }
    }
    cout << price << "\n";

    return 0;
}