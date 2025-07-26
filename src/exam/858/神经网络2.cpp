#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ���弤�����Sigmoid��
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// ���弤����ĵ���
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

// ��ʼ�����Ȩ��
void initialize_weights(double *weights, int n) {
    for (int i = 0; i < n; i++) {
        weights[i] = ((double)rand() / RAND_MAX) * 2 - 1; // ���ֵ�� [-1, 1]
    }
}

// ǰ�򴫲�
void forward_propagation(double input[2], double hidden[2], double *output, double w1[2][2], double w2[2]) {
    // �������ز����
    for (int i = 0; i < 2; i++) {
        hidden[i] = 0;
        for (int j = 0; j < 2; j++) {
            hidden[i] += input[j] * w1[j][i];
        }
        hidden[i] = sigmoid(hidden[i]);
    }

    // ������������
    *output = 0;
    for (int i = 0; i < 2; i++) {
        *output += hidden[i] * w2[i];
    }
    *output = sigmoid(*output);
}

// ������ʧ��������
double calculate_loss(double output, double target) {
    return 0.5 * pow(target - output, 2);
}

// ���򴫲�
void back_propagation(double input[2], double hidden[2], double output, double target, double w1[2][2], double w2[2], double learning_rate) {
    // ������������
    double output_error = target - output;
    double output_delta = output_error * sigmoid_derivative(output);

    // ���������Ȩ��
    for (int i = 0; i < 2; i++) {
        w2[i] += hidden[i] * output_delta * learning_rate;
    }

    // �������ز����
    double hidden_error[2];
    for (int i = 0; i < 2; i++) {
        hidden_error[i] = output_delta * w2[i];
        double hidden_delta = hidden_error[i] * sigmoid_derivative(hidden[i]);

        // �������ز�Ȩ��
        for (int j = 0; j < 2; j++) {
            w1[j][i] += input[j] * hidden_delta * learning_rate;
        }
    }
}

int main() {
    srand(time(NULL)); // ��ʼ���������

    // ���������Ŀ�������XOR ���⣩
    double inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    double targets[4] = {0, 1, 1, 0};

    // ����Ȩ��
    double w1[2][2]; // ����㵽���ز��Ȩ��
    double w2[2];    // ���ز㵽������Ȩ��

    // ��ʼ��Ȩ��
    initialize_weights(&w1[0][0], 4);
    initialize_weights(w2, 2);

    // ѵ������
    int epochs = 10000;
    double learning_rate = 0.1;

    // ѵ��������
    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_loss = 0.0;

        for (int i = 0; i < 4; i++) {
            double hidden[2];
            double output;

            // ǰ�򴫲�
            forward_propagation(inputs[i], hidden, &output, w1, w2);

            // ������ʧ
            double loss = calculate_loss(output, targets[i]);
            total_loss += loss;

            // ���򴫲�
            back_propagation(inputs[i], hidden, output, targets[i], w1, w2, learning_rate);
        }

        // ��ӡÿһ�ֵ�ƽ����ʧ
        if (epoch % 100 == 0) {
            printf("Epoch %d, Loss: %f\n", epoch, total_loss / 4);
        }
    }

    // ����������
    printf("Testing the trained network:\n");
    for (int i = 0; i < 4; i++) {
        double hidden[2];
        double output;

        forward_propagation(inputs[i], hidden, &output, w1, w2);
        printf("Input: [%f, %f] -> Output: %f (Expected: %f)\n", inputs[i][0], inputs[i][1], output, targets[i]);
    }

    return 0;
}
