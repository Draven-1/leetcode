#include<stdio.h>

// 将每个位的数字存放到一个定长(12)的整数数组中，前后一起遍历数组中的元素是否相等。
// 空间复杂度 O(1), 时间复杂度O(n)

int main()
{
    int arr[12];
    int count = 0;
    int num = 6789876;

    if(num < 0)
        return -1;

    while(num)
    {
        int digit = num % 10;
        num = num / 10;
        arr[count++] = digit;
    }

    // printf("count: %d\n", count);

    for(int i =0; i < count; i ++)
    {
        printf("digit: %d\n", arr[i]);
    }

    int begin = 0;
    int end = count - 1;
    while(begin < end)
    {
        if(arr[begin++] != arr[end--])
            return -1;
    }

    return 0;
}
