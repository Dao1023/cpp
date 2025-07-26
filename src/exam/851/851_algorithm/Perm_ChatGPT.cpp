#include <iostream>
#include <vector>
#include <algorithm> // 为了使用 std::swap

// 递归函数，用于生成全排列
void permute(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    // 如果递归到了最后一个位置，保存当前排列
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    // 递归生成从 start 开始的所有排列
    for (int i = start; i < nums.size(); ++i) {
        std::swap(nums[start], nums[i]);  // 交换当前元素到起始位置
        permute(nums, start + 1, result); // 递归生成剩余元素的排列
        std::swap(nums[start], nums[i]);  // 还原数组到初始状态
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3}; // 要排列的元素
    std::vector<std::vector<int>> result;

    permute(nums, 0, result);

    // 输出结果
    for (const auto& permutation : result) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}