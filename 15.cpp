#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<double> A; // Non-zero values
    std::vector<int> JA;  // Column indices
    std::vector<int> IA;  // Row pointers
    int numRows, numCols;

public:
    SparseMatrix(int rows, int cols) : numRows(rows), numCols(cols) {
        // Initialize the IA array with zeros
        IA.push_back(0);
    }

    void addValue(int row, int col, double value) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            std::cerr << "Invalid row or column index." << std::endl;
            return;
        }
        A.push_back(value);
        JA.push_back(col);
        IA[row + 1]++; // Increment the row pointer for the next row
    }

    void build() {
        // Build the IA array by cumulatively summing its elements
        for (int i = 1; i <= numRows; i++) {
            IA[i] += IA[i - 1];
        }
    }

    // Matrix-vector multiplication (Ax = y)
    void multiply(const std::vector<double>& x, std::vector<double>& y) const {
        if (x.size() != numCols || y.size() != numRows) {
            std::cerr << "Invalid input vector sizes." << std::endl;
            return;
        }

        for (int i = 0; i < numRows; i++) {
            y[i] = 0;
            for (int j = IA[i]; j < IA[i + 1]; j++) {
                y[i] += A[j] * x[JA[j]];
            }
        }
    }
};

int main() {
    SparseMatrix matrix(3, 3);

    // Populate the sparse matrix
    matrix.addValue(0, 0, 2.0);
    matrix.addValue(0, 1, 1.0);
    matrix.addValue(1, 1, 3.0);
    matrix.addValue(2, 0, 1.0);
    matrix.addValue(2, 2, 4.0);
    matrix.build();

    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<double> y(3, 0);

    matrix.multiply(x, y);

    std::cout << "Result of Ax = y:" << std::endl;
    for (double val : y) {
        std::cout << val << " ";
    }

    return 0;
}
