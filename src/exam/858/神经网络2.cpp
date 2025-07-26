#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 定义激活函数（Sigmoid）
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// 定义激活函数的导数
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

// 初始化随机权重
void initialize_weights(double *weights, int n) {
    for (int i = 0; i < n; i++) {
        weights[i] = ((double)rand() / RAND_MAX) * 2 - 1; // 随机值在 [-1, 1]
    }
}

// 前向传播
void forward_propagation(double input[2], double hidden[2], double *output, double w1[2][2], double w2[2]) {
    // 计算隐藏层输出
    for (int i = 0; i < 2; i++) {
        hidden[i] = 0;
        for (int j = 0; j < 2; j++) {
            hidden[i] += input[j] * w1[j][i];
        }
        hidden[i] = sigmoid(hidden[i]);
    }

    // 计算输出层输出
    *output = 0;
    for (int i = 0; i < 2; i++) {
        *output += hidden[i] * w2[i];
    }
    *output = sigmoid(*output);
}

// 计算损失（均方误差）
double calculate_loss(double output, double target) {
    return 0.5 * pow(target - output, 2);
}

// 反向传播
void back_propagation(double input[2], double hidden[2], double output, double target, double w1[2][2], double w2[2], double learning_rate) {
    // 计算输出层误差
    double output_error = target - output;
    double output_delta = output_error * sigmoid_derivative(output);

    // 更新输出层权重
    for (int i = 0; i < 2; i++) {
        w2[i] += hidden[i] * output_delta * learning_rate;
    }

    // 计算隐藏层误差
    double hidden_error[2];
    for (int i = 0; i < 2; i++) {
        hidden_error[i] = output_delta * w2[i];
        double hidden_delta = hidden_error[i] * sigmoid_derivative(hidden[i]);

        // 更新隐藏层权重
        for (int j = 0; j < 2; j++) {
            w1[j][i] += input[j] * hidden_delta * learning_rate;
        }
    }
}

int main() {
    srand(time(NULL)); // 初始化随机种子

    // 定义输入和目标输出（XOR 问题）
    double inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    double targets[4] = {0, 1, 1, 0};

    // 定义权重
    double w1[2][2]; // 输入层到隐藏层的权重
    double w2[2];    // 隐藏层到输出层的权重

    // 初始化权重
    initialize_weights(&w1[0][0], 4);
    initialize_weights(w2, 2);

    // 训练参数
    int epochs = 10000;
    double learning_rate = 0.1;

    // 训练神经网络
    for (int epoch = 0; epoch < epochs; epoch++) {
        double total_loss = 0.0;

        for (int i = 0; i < 4; i++) {
            double hidden[2];
            double output;

            // 前向传播
            forward_propagation(inputs[i], hidden, &output, w1, w2);

            // 计算损失
            double loss = calculate_loss(output, targets[i]);
            total_loss += loss;

            // 反向传播
            back_propagation(inputs[i], hidden, output, targets[i], w1, w2, learning_rate);
        }

        // 打印每一轮的平均损失
        if (epoch % 100 == 0) {
            printf("Epoch %d, Loss: %f\n", epoch, total_loss / 4);
        }
    }

    // 测试神经网络
    printf("Testing the trained network:\n");
    for (int i = 0; i < 4; i++) {
        double hidden[2];
        double output;

        forward_propagation(inputs[i], hidden, &output, w1, w2);
        printf("Input: [%f, %f] -> Output: %f (Expected: %f)\n", inputs[i][0], inputs[i][1], output, targets[i]);
    }

    return 0;
}
