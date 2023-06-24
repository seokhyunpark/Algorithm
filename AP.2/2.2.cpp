#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n, long_t m, long_t p) {
    if (n == 1)
        return (n / 2 + 1) * (log2(2 * m) + 1) * (log2(4 * p) + 1);
    return (n / 2) * (log2(2 * m) + 1) * (log2(4 * p) + 1);
}

int main() {
    long_t n, m, p;
    scanf("%lld %lld %lld", &n, &m, &p);
    printf("%lld", fun(n, m, p));
}
