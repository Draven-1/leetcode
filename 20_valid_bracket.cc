#include <cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

// 遍历字符：
// 1. 左括号入栈。
// 2. 遇到右括号：
//    A. 判断栈是否为空，为空则返回false (TODO 容易出错点，容易忘记)
//    B. 不为空，则用栈顶元素与当前字符比较是否配对(分四种情况，最好的写法是switch case)
//       不配对则返回false, 配对则出栈，进行下一轮循环。
// 3. 遍历完字符判断栈是否为空：
//    不为空返回false, 为空返回True

// if , else if , else 写法
#if 0
int  main( )
{
    // string str = "(({})}}{[()]}())";
    // string str = "(({})]]{[()]}())";
    // string str = "(({})s]{[()]}())";
    string str = "(({}){[()]}())";
    // string str = "()({";
    // string str = "()";
    // string str = "))";
    // string str = "()))";
    stack<char> ch_st;
    cout << str.size() << endl;
    // 元素个数时单数,返回false, 此次逻辑和最后重复,不过此处可做为其优化
    if(str.size() <= 0 || 1 == str.size() % 2)
    {
        cout << "字符串个数为奇数，或者小于等于0" << endl;
        return -1;
    }

    for(int index = 0 ; index < (int)str.size(); ++index)
    {
        // 左括号 入栈
        if('(' == str[index] || '[' == str[index] || '{' == str[index])
        {
            ch_st.push(str[index]);
            continue; // 优化循环语句
        }
        // 右括号
        else if (')' == str[index] || ']' == str[index] || '}' == str[index])
        {
            // 第一个字符如果是右括号，则栈为空。如果循环没有结束到这里，则说明右括号多于左括号
            if(ch_st.empty())
            {
                cout << "第一个字符是右括号或者右括号多于左括号" << endl;
                return -1;
            }
            // 与栈顶元素做匹配, 可以用siwthc case语句
            if(')' == str[index])
            {
                if('(' != ch_st.top())
                {
                    cout << "()不匹配" << endl;
                    return -1;
                }

                ch_st.pop();
                // continue; // 优化循环语句 (如果用的是if,else if,else 或者 sitch case 则无用, 用if if if 则可以起到优化作用)
            }
            else if(']' == str[index])
            {
                if('[' != ch_st.top())
                {
                    cout << "[]不匹配" << endl;
                    return -1;
                }

                ch_st.pop();
                // continue; // 优化循环语句
            }
            else
            {
                if('{' != ch_st.top())
                {
                    cout << "{}不匹配" << endl;
                    return -1;
                }

                ch_st.pop();
                // continue; // 优化循环语句
            }
        }
        // 字符串中含有其他的字符(若允许其他字符，这个里则为continue)
        else
        {
            cout << "字符串中含有其他字符" << endl;
            return -1;
        }
    } //end for

    // 栈不为空，怎左括号多于右括号
    if(!ch_st.empty())
    {
        cout << "左括号多余右括号" << endl;
        return -1;
    }

    cout << "匹配成功" << endl;
    return 0;
}
#endif


// // switch case 的写法
#if 0
int  main()
{
    // string str = "(({})}}{[()]}())";
    // string str = "(({})]]{[()]}())";
    // string str = "(({})s]{[()]}())";
    string str = "(({}){[()]}())";
    // string str = "()({";
    // string str = "()";
    // string str = "))";
    // string str = "()))";
    stack<char> ch_st;
    // for 循环C++11写法
    for(auto ch : str)
    {
        if('(' == ch || '[' == ch || '{' == ch)
        {
            ch_st.push(ch);
            continue;
        }

        if(ch_st.empty())
        {
            cout << "右括号多于左括号" << endl;
            return -1;
        }

        switch(ch)
        {
        case ')':
            if('(' == ch_st.top())
                ch_st.pop();
            else
            {
                cout << "() 不匹配" << endl;
                return -1;
            }
            break;
        case ']':
            if('[' == ch_st.top())
                ch_st.pop();
            else
            {
                cout << "[] 不匹配" << endl;
                return -1;
            }
            break;
        case '}':
            if('{' == ch_st.top())
                ch_st.pop();
            else
            {
                cout << "{} 不匹配" << endl;
                return -1;
            }
            break;
        default:
            cout << "含有其他字符" << endl;
            return -1;
            // break;
        }
    }

    if(!ch_st.empty())
    {
        cout << "左括号多于右括号" << endl;
        return -1;
    }

    cout << "匹配成功" << endl;
    return 0;
}
#endif


// 力扣官方写法
#if 1
int main()
{
    // string str = "(({})}}{[()]}())";
    // string str = "(({})]]{[()]}())";
    // string str = "(({})s]{[()]}())";
    string str = "(({}){[()]}())";
    // string str = "()({";
    // string str = "()";
    // string str = "(s)";
    // string str = "s()";
    // string str = "()s";
    // string str = "))";
    // string str = "()))";
#if 1
    int s_size = str.size();
    if (s_size % 2 == 1) {
        // return false;
        cout << "不匹配_0" << endl;
        return -1;
    }
    
    stack<char> ch_st;
    unordered_map<char, char> un_map ={
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for(char ch : str)
    {
        // 当前元素为右括号
        if(un_map.count(ch))
        {
            // 当前栈为空 或者 当前的元素于栈顶元素不匹配
            if(ch_st.empty() || ch_st.top() != un_map[ch])
            {
                cout << "不匹配_1" << endl;
                return -1;
            }

            ch_st.pop();
        }
        else
            ch_st.push(ch);
    }

    if(!ch_st.empty())
    {
        cout << "不匹配_2" << endl;
        return -1;
    }

    cout << "匹配" << endl;
    return 0;
#endif

#if 0
    string s = str;
    int n = s.size();
    if (n % 2 == 1) {
        // return false;
        cout << "不匹配_1" << endl;
        return -1;
    }
    
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    stack<char> stk;
    for (char ch: s) {
        if (pairs.count(ch)) {
            if (stk.empty() || stk.top() != pairs[ch]) {
                cout << "不匹配_2" << endl;
                return -1;
                // return false;
            }
            stk.pop();
        }
        else {
            stk.push(ch);
        }
    }

    // return stk.empty();
#endif

}
#endif
