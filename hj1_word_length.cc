#include<iostream>
#include<string>
#include <cstdio>
using namespace std;
int main()
{
    // string s = "hello nowcoder";
    // string s = "hello";
    // string s("XSUWHQ");
    string s;
    getline(cin, s);  // c++ 输入一行字符串包含空格的写法
    int ret = s.rfind(" ");

    ret = s.size() - ret - 1;
    cout << ret << endl;
}
