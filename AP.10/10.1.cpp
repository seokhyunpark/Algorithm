#include <iostream>
#include <vector>
using namespace std;

vector<int> col;
string max_col;
int n, cnt = 0;

void compare() {
    string s = "";
    for (int i = 1; i <= n; i++) {
        s += to_string(col[i]);
    }
    if (s > max_col) {
        max_col = s;
    }
}

bool promising(int i) {
    int k = 1;
    bool flag = true;

    while (k < i && flag) {
        if ((col[i] == col[k] || abs(col[i] - col[k]) == i - k))
            flag = false;
        k++;
    }
    return flag;
}

void queens(int i) {
    int j;
    if (promising(i)) {
        if (i == n) {
            compare();
            cnt++;
        }
        else {
            for (j = 1; j <= n; j++) {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    col.resize(n + 1);
    queens(0);

    cout << cnt << endl << max_col;

    return 0;
}
