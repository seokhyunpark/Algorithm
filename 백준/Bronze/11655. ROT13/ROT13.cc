#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

string s, result;

int main() {
    FAST_IO

    getline(cin, s);
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            if (c + 13 > 'z') {
                result += (c + 13 - 26);
            }
            else {
                result += (c + 13);
            }
        }
        else if (c >= 'A' && c <= 'Z') {
            if (c + 13 > 'Z') {
                result += (c + 13 - 26);
            }
            else {
                result += (c + 13);
            }
        }
        else {
            result += c;
        }
    }
    cout << result << "\n";

    return 0;
}