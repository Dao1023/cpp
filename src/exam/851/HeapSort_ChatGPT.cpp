#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;
    int size;

    // 调整堆，使其满足最大堆性质 - O(log n)
    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest); // 递归调整子树
        }
    }

    // 向上调整堆以保持最大堆性质 - O(log n)
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        if (i && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent); // 递归调整父节点
        }
    }

public:
    Heap() : size(0) {}

    // 插入新元素 - O(log n)
    void insert(int key) {
        heap.push_back(key);
        size++;
        heapifyUp(size - 1);
    }

    // 删除堆顶元素（最大值） - O(log n)
    int deleteMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        heap.pop_back();
        size--;

        heapifyDown(0); // 调整堆

        return root;
    }

    // 堆排序 - O(n log n)
    void heapSort() {
        // 建堆 - O(n)
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }

        // 一一取出最大值（堆顶）并调整堆 - O(n log n)
        for (int i = size - 1; i >= 0; i--) {
            swap(heap[0], heap[i]); // 将当前最大值移到末尾
            size--;
            heapifyDown(0); // 调整剩余的堆
        }
    }

    void printHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    // 插入元素
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    cout << "Initial heap: ";
    h.printHeap(); // 输出初始堆

    // 删除堆顶元素
    cout << "Deleted max element: " << h.deleteMax() << endl;

    cout << "Heap after deletion: ";
    h.printHeap(); // 输出删除后的堆

    // 堆排序
    h.heapSort();

    cout << "Heap after heapSort: ";
    h.printHeap(); // 输出排序后的堆

    return 0;
}
