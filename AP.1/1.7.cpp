#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a = 0, b = 1, next;

    for (int i = 1; i <= n; i++) {
        next = (a + b) % 1000000;
        a = b;
        b = next;
    }

    cout << a << endl;
}
