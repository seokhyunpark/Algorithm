#include <iostream>
using namespace std;

int fib(int num, int& cnt) {
    cnt++;
    if (num == 0 || num == 1)
        return num;
    return (fib(num - 1, cnt) + fib(num - 2, cnt));
}

int main() {
    int n; cin >> n;
    int fun_call = 0;

    cout << fib(n, fun_call) % 1000000 << endl;
    cout << fun_call << endl;
}
