#include <stdio.h>

#define N 3

typedef struct {
    double *data;
    int rows;
    int cols;
} Matrix;

void matrix_multiply(Matrix a, Matrix w, Matrix result) {
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = 0;
        for (int j = 0; j < a.cols; j++) {
            result.data[i] += a.data[j] * w.data[i * w.cols + j];
        }
    }
}

// MSE
double loss_function(double y_true[], double y_pred[], int n) {
	double mse = 0.0;
	for (int i = 0; i < n; i++) {
		double diff = y_true[i] - y_pred[i];
		mse += diff * diff;
	}
	return mse / n;
}


int main() {
    double a_data[] = {1, 2, 3};
    Matrix a = {a_data, 1, N};
    
    double y_data[] = {0, 1, 0};
    Matrix y = {y_data, 1, N};
	
	double w1_data[] = {1, 2, 3, 4, 5, 6};
    Matrix w1 = {w1_data, 2, N};
    
    double w2_data[] = {2, 2, 3, 5, 5, 6};
    Matrix w2 = {w2_data, 2, N};
	
	
	double result_data[2];
	Matrix result = {result_data, 2, 1};

    matrix_multiply(a, w1, result);
    matrix_multiply(a, w2, result);
    
    double loss = loss_function(y.data, a.data, N);
    printf("%f\n", loss);

    for (int i = 0; i < result.rows; i++) {
        printf("%f\n", result.data[i]);
    }

    return 0;
}
