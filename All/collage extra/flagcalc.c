#include <stdio.h>

int main() {
    long long n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);

    // Calculate the number of flagstones needed
    long long flagstonesLength = (n + a - 1) / a;
    long long flagstonesWidth = (m + a - 1) / a;

    long long totalFlagstones = flagstonesLength * flagstonesWidth;

    printf("%lld\n", totalFlagstones);

    return 0;
}
