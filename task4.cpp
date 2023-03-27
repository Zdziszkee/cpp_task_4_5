#include <iostream>
#include <vector>

unsigned long long fibonacciRecursive(unsigned long long n);

unsigned long long fibonacciIterative(unsigned long long n);

std::vector<unsigned long long> cache = {0, 1, 1};

int main() {
    int n = 9;
    fibonacciRecursive(n);
    for (int i = 0; i <= n; ++i) {
        std::cout << cache[i] << std::endl;
    }
    cache = {};
    std::cout << fibonacciIterative(9) << std::endl;
    return 0;
}

//0, 1, 1, 2, 3, 5, 8, 13, 21, 34
unsigned long long fibonacciRecursive(unsigned long long n) {
    unsigned long long result;
    if (n < cache.size()) {
        result = cache[n];
    } else {
        result = fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
        cache[n] = result;
    }
    return result;
}

unsigned long long fibonacciIterative(unsigned long long n) {
    unsigned long long result = 0;
    if (n < cache.size()) {
        result = cache[n];
    } else {
        int previous = 0;
        int current = 1;
        int next = 1;
        for (int i = 2; i <= n; ++i) {
            next = current + previous;
            previous = current;
            current = next;
        }
        result = next;
    }

    return result;
}