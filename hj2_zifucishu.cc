#include <cctype>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    string s1;
    char c;
    getline(cin, s1);
    cin.get(c);
    int count = 0;

    // 字符串和字符都转换为小写比较
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    c = tolower(c);
    
    // 用迭代器的方式遍历
    // string::iterator it = s1.begin();
    auto it = s1.begin();
    for(; it != s1.end(); ++it)
    {
        if(c == *it)
            ++count;
    }

    cout << count << endl;

    return 0;
}
