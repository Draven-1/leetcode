#include<iostream>
#include<vector>
#include<string>
#include<array>
using namespace std;


int main()
{
#if 1
    // vector<string> str = {"flower","flow","flight"};
    // vector<string> str = {"dog","racecar","car"};
    // vector<string> str = {"abcdefg","abcdefgh","abcdefghi", "abcdefghil"};
    // vector<string> str = {"ab", "a"};
    // vector<string> str = {"abcd"};
    vector<string> str = {"a", "a", "a"};
    // vector<string> str = {};
    if(0 == str.size())
    {
        cout << "" << endl;
        return 0;
    }
    // 纵向遍历, 从第1列开始
    for(int j = 0; j < str[0].size(); ++j)
    {
        // 取第一排第j列的字符和第j列的第1-i行的数据依次比较
        char c = str[0][j];
        // 横向遍历, 从第2行开始
        for(int i = 1; i < str.size(); ++i)
        {
            // 如果第i行第j列字符与第0行第j列的字符不相等则退出，并返回第0行第j-1列的子串
            if(c != str[i][j])
            {
                cout << str[0].substr(0, j) << endl; // substr(0, j)左闭右开
                return 0;
            }
        }
    }
    
    cout << str[0] << endl;
    return 0;
#endif
}
