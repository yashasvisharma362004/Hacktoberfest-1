#include <stdio.h>
#include <math.h>

/*

Given an integer n, we need to find the nth digit 
in the infinite sequence formed by concatenating 
all positive integers together:

*/

int findNthDigit(long long n) {
    long long length = 1;  
    long long count = 9;    
    long long start = 1;    


    while (n > length * count) {
        n -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }


    start += (n - 1) / length;

    long long num = start;
    int digitIndex = (int)((n - 1) % length);

    int digits[20], size = 0;
    while (num > 0) {
        digits[size++] = num % 10;
        num /= 10;
    }

    return digits[size - 1 - digitIndex];
}

int main() {
    long long n;
    printf("Enter n: ");
    scanf("%lld", &n);

    int result = findNthDigit(n);
    printf("The %lldth digit is: %d\n", n, result);

    return 0;
}
