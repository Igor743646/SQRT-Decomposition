#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>

#include "Utils.h"
#include "SQRTDecomposition.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    const size_t size = 42;

    vector<int> v(size);

    for (size_t i = 0; i < size; i++) {
        v[i] = rand() % 99999999;
    }

    SQRTDecomposition<int> sqrt(v, [](int a, int b) {return std::min(a, b); });

    print(v);
    print(sqrt.Find(0, 41));

    /*for (size_t size = 1000; size < 500000; size += 1000) {
        vector<int> v(size);

        for (size_t i = 0; i < size; i++) {
            v[i] = rand() % 99999999;
        }

        SQRTDecomposition<int> sqrt(v);

        chrono::time_point<chrono::system_clock>  start1 = chrono::system_clock::now();
        for (size_t i = 0; i < 800; i++) {
            sqrt.Find(0, size - 1);
        }
        chrono::time_point<chrono::system_clock>  end1 = chrono::system_clock::now();
        chrono::time_point<chrono::system_clock>  start2 = chrono::system_clock::now();
        for (size_t i = 0; i < 800; i++) {
            size_t a = rand() % size, b = rand() % size;
            if (a > b) std::swap(a, b);
            sqrt.Find(a, b);
        }
        chrono::time_point<chrono::system_clock>  end2 = chrono::system_clock::now();
        cout << size << " " << chrono::duration<double>(end1 - start1).count() + (chrono::duration<double>(end2 - start2).count() / 800) << "\n";
    }*/
}