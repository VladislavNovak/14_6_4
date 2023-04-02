#include <iostream>
#include <string>

using std::string;

void printResult(const float (&arr)[4]) {
    std::cout << "Result is array: [ ";
    for (float i : arr) std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void inputToVector(float (&vec)[4], const string &title = "") {
    std::cout << std::endl;
    std::cout << title << " of floating numbers." << std::endl;
    for (size_t i = 0; i < 4; ++i) {
        std::cout << "Enter " << (i + 1) << " item: ";
        std::cin >> vec[i];
    }

    printResult(vec);
}

int main() {
    float base[4] = {0};
    float matrix[4][4] = {0};
    float result[4] = {0};

    // Заполняем вектор:
    inputToVector(base, "Vector");

    // Заполняем матрицу:
    for (size_t i = 0; i < 4; ++i) {
        string title = "Matrix (line " + std::to_string(i + 1) + ")";
        inputToVector(matrix[i], title);
    }

    // Перемножаем по принципу (base[i] * matrix[i][j]) + accumulate
    for (size_t i = 0; i < 4; ++i) {
        float accumulate = 0;
        for (size_t j = 0; j < 4; ++j) {
            accumulate += (base[i] * matrix[i][j]);
        }

        result[i] = accumulate;
    }

    std::cout << "\nResult of multiplying a matrix by a vector. ";
    printResult(result);
}
