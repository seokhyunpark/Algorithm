#include <iostream>
using namespace std;

int k, cnt = 0, cnt_hanoi = 0;

void hanoi(int n, char src, char via, char dst) {
    cnt_hanoi++;
    if (n == 1) {
        cnt++;
        if (cnt == k)
            printf("%c -> %c\n", src, dst);
    }
    else {
        hanoi(n-1, src, dst, via);
        hanoi(1, src, via, dst);
        hanoi(n-1, via, src, dst);
    }
}

int main() {
    int n;
    cin >> n;
    cin >> k;
    hanoi(n, 'A', 'B', 'C');
    cout << cnt_hanoi;
}
