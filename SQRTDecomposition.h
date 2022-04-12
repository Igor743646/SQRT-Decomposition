#pragma once
#include <vector>
#include <functional>
#include <cmath>

template<class T>
class SQRTDecomposition {

    std::vector<T> data;
    std::vector<T> blocks;
    size_t size;
    std::function<T(const T&, const T&)> func;

public:

    SQRTDecomposition(const std::vector<T>& v, std::function<T(const T&, const T&)> _func) {
        data = v;
        func = _func;
        size = (size_t)std::sqrt(v.size());
        size_t count_of_blocks = (v.size() % size == 0 ? v.size() / size : v.size() / size + 1);
        blocks.resize(count_of_blocks);

        for (size_t i = 0; i < count_of_blocks; i++) {
            blocks[i] = v[size * i];

            for (size_t j = 1; j < size and size * i + j < v.size(); j++) {
                blocks[i] = func(blocks[i], v[size * i + j]);
            }
        }
    }

    SQRTDecomposition(const std::vector<T>& v) : SQRTDecomposition(v, [](const T& a, const T& b) {return std::max(a, b); }) { }

    T Find(size_t i, size_t j) {
        T result = data[i];

        size_t t = i + 1;

        while (t <= j) {
            if (t % size == 0 and t + size - 1 <= j) {
                result = func(result, blocks[t / size]);
                t += size;
            }
            else {
                result = func(result, data[t]);
                t++;
            }
        }

        return result;
    }

};