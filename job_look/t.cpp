#include<chrono>
#include<iostream>

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    int n=0;
    for (int i = 1; i <= 100000; i++) {
        std::cout<<i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}
