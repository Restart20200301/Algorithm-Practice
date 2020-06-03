/**
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

 typedef struct {
    int* nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* arr = malloc(sizeof(NumArray));
    arr->nums = nums;
    return arr;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    for (int pos = i; pos <= j; pos++)
        sum += (obj->nums)[pos];
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/

// 更加正规的写法。（还可以加入范围判断在其中）
typedef struct {
    int size;
    int data[0];
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* arr = malloc(sizeof(NumArray) + sizeof(int) * numsSize);
    memcpy(arr->data, nums, numsSize * sizeof(int));
    arr->size = numsSize;
    return arr;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    for (int pos = i; pos <= j; pos++)
        sum += (obj->data)[pos];
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/