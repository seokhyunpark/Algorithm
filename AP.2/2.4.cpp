#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    long_t temp = log(n) / log(4);
    return pow(8, temp + 1);
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}
