
int firstMissingPositive(int* nums, int numsSize) {

    int i = 0;
    while (i < numsSize) {

        if (nums[i] > 0 &&
            nums[i] <= numsSize &&
            nums[nums[i] - 1] != nums[i]) {

            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;

        } else {
            i++;
        }
    }
    for (int i = 0; i < numsSize; i++) {

        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return numsSize + 1;
}
