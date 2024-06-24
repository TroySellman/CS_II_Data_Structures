#include <iostream>

//use n = 10
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciTail(int n, int accumulator1, int accumulator2) {
    if (n == 0) return accumulator1;
    if (n == 1) return accumulator2;
    return fibonacciTail(n - 1, accumulator2, accumulator1 + accumulator2);
}

int main() {
    int n = 10;
    for (int i = 0; i < n; ++i) {
            std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
            std::cout << fibonacciTail(i, 0, 1) << " ";
    }
    std::cout << std::endl;
}
