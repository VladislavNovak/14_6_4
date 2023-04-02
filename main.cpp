#include <iostream>
#include <typeinfo> // для typeid().name()

int main() {
    float vec[4] = {3, 6, 2, 9};
    float matrix[4][4] = {
            {3, 2.1, 8, 5},
            {5,  1,   8,  6},
            {6, 2,  8, 2},
            {4, 4,  1, 5},
    };
    float result[4] = {0};

    for (size_t i = 0; i < 4; ++i) {
        float accumulate = 0;
        for (size_t j = 0; j < 4; ++j) {
            accumulate += (vec[i] * matrix[i][j]);
        }

        result[i] = accumulate;
    }

    for (auto item: result) {
        std::cout << item << " " << typeid(item).name() << " ";
    }
}
