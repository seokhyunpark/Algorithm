#include <iostream>
using namespace std;

int collatz(int num, int &len) {
    len++;
    if (num == 1)
        return --len;
    else if (num % 2 == 0)
        return collatz(num / 2, len);
    else
        return collatz(3 * num + 1, len);
}

int print_collatz(int num) {
    cout << num << " ";
    if (num == 1)
        return 0;
    else if (num % 2 == 0)
        return print_collatz(num / 2);
    else
        return print_collatz(3 * num + 1);
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    
    int index = 0, length = 0;
    for (int i = n; i <= m; i++) {
        int len = 0;
        len = collatz(i, len);
        if (len >= length) {
            index = i;
            length = len;
        }
    }
    cout << index << " " << length << endl;
    print_collatz(index);

    return 0;
}
