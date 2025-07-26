#include <iostream>
//#include <climits>

using namespace std;

struct MinMax {
    int min;
    int max;
};

// �ݹ麯������ A[i...j] ����Сֵ�����ֵ
MinMax findMinMax(int A[], int i, int j) {
    if (i == j) {
        return {A[i], A[i]};  // ֻʣһ��Ԫ��ʱ����Сֵ�����ֵ��Ϊ��Ԫ��
    } else {
        int mid = (i + j) / 2;
        MinMax left = findMinMax(A, i, mid);
        MinMax right = findMinMax(A, mid + 1, j);
        
        return {min(left.min, right.min), max(left.max, right.max)};
    }
}

int main() {
    int A[] = {3, 1, 7, 9, 2, 5, 4};
    int n = sizeof(A) / sizeof(A[0]);

    MinMax result = findMinMax(A, 0, n - 1);

    cout << "Min: " << result.min << ", Max: " << result.max << endl;

    return 0;
}

