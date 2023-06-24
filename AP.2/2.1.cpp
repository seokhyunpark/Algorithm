#include <iostream>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    return 2 * n * n;
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}
