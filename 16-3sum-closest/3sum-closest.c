
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x > y) - (x < y);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {

        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }
            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                return sum;
            }
        }
    }

    return closest;
}
