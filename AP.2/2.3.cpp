#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    return pow(4, log2(2 * n));
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}
