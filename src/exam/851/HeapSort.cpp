#include <iostream>
#include <algorithm> // 包含 std::swap

typedef int ElemType;


// 堆调整函数
void HeadAdjust(ElemType A[], int k, int len) {
    ElemType temp = A[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1]) i++;  // 找到两个孩子中较大的那个
        if (temp >= A[i]) break;              // 如果父节点大于等于较大的孩子，跳出循环
        A[k] = A[i];                          // 否则，将较大的孩子上移
        k = i;                                // 继续向下调整
    }
    A[k] = temp;  // 将temp放到最终位置
}

// 堆排序函数
void HeapSort(ElemType A[], int len) {
    // 构建初始堆，只需要考虑
    for (int i = len / 2; i > 0; i--) {
        HeadAdjust(A, i, len);
    }

    // 进行堆排序
    for (int i = len; i > 1; i--) {
        std::swap(A[i], A[1]);     // 将堆顶元素和堆的最后一个元素交换
        HeadAdjust(A, 1, i - 1);   // 调整堆
    }
}

void Insert(ElemType A[], int& len, ElemType value) {
    len++;
    A[len] = value;

    // 上浮调整堆
    int k = len;
    while (k > 1 && A[k] > A[k / 2]) {
        std::swap(A[k], A[k / 2]);
        k /= 2;
    }
}

void DeleteTop(ElemType A[], int& len) {
    if (len < 1) return; // 空堆，无需删除

    // 交换堆顶元素和堆的最后一个元素
    std::swap(A[1], A[len]);

    // 减少堆的大小
    len--;

    // 下沉调整堆
    int k = 1;
    while (2 * k <= len) {
        int j = 2 * k; // 左子节点
        if (j < len && A[j] < A[j + 1]) j++; // 找到两个孩子中较大的那个
        if (A[k] >= A[j]) break; // 如果父节点大于等于较大的孩子，跳出循环
        std::swap(A[k], A[j]); // 否则，将较大的孩子上移
        k = j; // 继续向下调整
    }
}


int main() {
    ElemType A[] = {0, 7, 2, 6, 3, 8, 1};  // 0作为占位符，使数组从索引1开始
    int length = sizeof(A) / sizeof(ElemType) - 1; // 长度减去占位符0

    HeapSort(A, length);

    // 输出排序后的数组
    for (int i = 1; i <= length; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}



/**
 * 使用占位符替代 HeadAdjust 函数中的 temp 变量来进行堆调整是可行的，但通常会使代码变得不太直观。
 * 在堆排序的过程中，temp 变量用于存储当前节点的值，以便将子节点的值上移。
 * 直接使用占位符并不会改变算法的核心逻辑，但会稍微复杂化实现。
 */
