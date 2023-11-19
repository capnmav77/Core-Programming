#include <iostream>
#include <vector>

class Matrix; // Forward declaration

class Vector {
private:
    std::vector<int> elements;

public:
    Vector(std::initializer_list<int> vals) : elements(vals) {}

    friend void prodVectorMatrix(const Vector& vector, const Matrix& matrix);
};

class Matrix {
private:
    std::vector<std::vector<int>> elements;

public:

/*
vals is an std::initializer_list<std::initializer_list<int>>, which represents the list of rows of the matrix. 

Each inner initializer_list<int> represents a row of the matrix.

The constructor of Matrix uses a range-based for loop to iterate over each row in vals.

Inside the loop, row represents a single row of the matrix, which is an std::initializer_list<int>.

The statement elements.emplace_back(row) adds a new row to the elements vector. The emplace_back function constructs 

a new row object in place at the end of the vector.

Since row is itself an std::initializer_list<int>, it can be directly passed as an argument to emplace_back

 which constructs the row by copying the elements of row into the newly added row of elements
*/

    Matrix(std::initializer_list<std::initializer_list<int>> vals) {
        for (const auto& row : vals) {
            elements.emplace_back(row);
        }
    }

    friend void prodVectorMatrix(const Vector& vector, const Matrix& matrix);
};

void prodVectorMatrix(const Vector& vector, const Matrix& matrix) {
    std::vector<int> result;

    for (const auto& row : matrix.elements) {
        int sum = 0;

        for (size_t i = 0; i < vector.elements.size(); ++i) {
            sum += vector.elements[i] * row[i];
        }

        result.push_back(sum);
    }

    // Display the result
    std::cout << "Vector-Matrix Product: ";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    Vector vector({ 1, 2, 3 });
    Matrix matrix({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });

    prodVectorMatrix(vector, matrix);

    return 0;
}
