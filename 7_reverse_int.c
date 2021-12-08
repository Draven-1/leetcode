#include<stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

// 数学问题，理解官方的不等式推导过程

int main()
{
    // int num = 1234567;
    int num = -1234567;
    int re_int = 0;

    while(num != 0)
    {
        if(re_int < INT_MIN || re_int > INT_MAX)
            return 0;

        int digit = num % 10;
        num /= 10;
        re_int = re_int * 10 + digit;
    }

    printf("re_int: %d\n", re_int);

    return re_int;
}
