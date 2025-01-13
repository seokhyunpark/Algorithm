#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int N, pos;
string ori_s, s;
string prefix, suffix;

int main() {
    cin >> N;
    cin >> ori_s;

    pos = ori_s.find('*');
    prefix = ori_s.substr(0, pos);
    suffix = ori_s.substr(pos + 1);

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s.size() < prefix.size() + suffix.size()) {
            cout << "NE" << "\n";
        }
        else {
            if (s.substr(0, prefix.size()) == prefix && s.substr(s.size() - suffix.size()) == suffix) {
                cout << "DA" << "\n";
            }
            else {
                cout << "NE" << "\n";
            }
        }
    }

    return 0;
}