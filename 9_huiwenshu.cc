#include<iostream>
using namespace std;

// 从个位开始将后面一半的数字反转与前面一半的数字比较 (官方给出的算法，个人认为不如数组方法直观、易读、高效)

int main()
{
    int num = 6789876; // 678876

    if(num < 0 || ((0 != num ) && (0 == num % 10)))
        return -1;

    int r_digit = 0;
    while(num > r_digit)
    {
        r_digit = r_digit * 10 + num % 10;
        num /= 10;
        // num = num / 10;
    }

    if((r_digit == num) || ((r_digit / 10) == num))
        return 0;

    return -1;
}

// int main()
// {
//     int num = 6789876; // 678876
//
//     if(num < 0)
//         return -1;
//
//     if(0 == num)
//         return 0;
//
//     if(0 == num % 10)
//         return -1;
//
//     int r_digit = 0;
//     while(num > r_digit)
//     {
//         r_digit = r_digit * 10 + num % 10;
//         num = num / 10;
//     }
//
//     if(r_digit == num)
//     {
//         #if 1
//         cout << "r_digit: " << r_digit << endl;
//         cout << "r_digit / 10: " << r_digit / 10 << endl;
//         cout << "num: " << num << endl;
//         #endif
//         return 0;
//     }
//
//     if((r_digit / 10) == num)
//     {
//         #if 1
//         cout << "r_digit: " << r_digit << endl;
//         cout << "r_digit / 10: " << r_digit / 10 << endl;
//         cout << "num: " << num << endl;
//         #endif
//         return 0;
//     }
//
//     #if 1
//     cout << "r_digit: " << r_digit << endl;
//     cout << "r_digit / 10: " << r_digit / 10 << endl;
//     cout << "num: " << num << endl;
//     #endif
//
//     return -1;
// }
