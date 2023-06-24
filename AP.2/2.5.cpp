#include <iostream>
using namespace std;

int collatz(int num) {
    cout << num << " ";
    if (num == 1)
        return 0;
    else if (num % 2 == 0)
        return collatz(num / 2);
    else
        return collatz(3 * num + 1);
}

int main() {
    int n; cin >> n;
    collatz(n);

    return 0;
}
