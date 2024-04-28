#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> create_matrix(int rows, int cols) {
    return vector<vector<double>>(rows, vector<double>(cols, 0.0));
}

vector<vector<double>> calculate_matrix(const vector<double>& x, int n) {
    int m = x.size();
    auto matrix = create_matrix(n + 1, n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < m; ++k) {
                matrix[i][j] += pow(x[k], i + j);
            }
        }
    }
    return matrix;
}

vector<double> calculate_vector(const vector<double>& x, const vector<double>& y, int n) {
    int m = x.size();
    vector<double> vector(n + 1, 0.0);
    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k < m; ++k) {
            vector[i] += y[k] * pow(x[k], i);
        }
    }
    return vector;
}

// Gaussian elimination
vector<double> solve_linear_system(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        
        swap(A[maxRow], A[i]);
        swap(b[maxRow], b[i]);

        for (int k = i + 1; k < n; ++k) {
            double c = -A[k][i] / A[i][i];
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
            b[k] += c * b[i];
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; --k) {
            b[k] -= A[k][i] * x[i];
        }
    }
    return x;
}

// Testing
int main() {
    vector<double> X = {1, 2, 3, 4, 5, 6, 7};
    vector<double> Y = {45000, 50000, 60000, 80000, 110000, 150000, 200000};
    int n = 3; //we can select the degree of the polynomial

    vector<vector<double>> k = calculate_matrix(X, n);
    vector<double> l = calculate_vector(X, Y, n);
    vector<double> b_coeffs = solve_linear_system(k, l);

    cout << "Polynomial Coefficients:" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << "b" << i << ": " << b_coeffs[i] << endl;
    }

    return 0;
}
