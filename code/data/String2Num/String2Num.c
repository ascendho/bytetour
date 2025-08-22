#include <stdio.h>
/// @brief 将单个字符<c>转换为DFA的输入（转移表的列号）
/// @param c 输入字符
/// @return DFA的输入（状态转移表的列号）
int get_inputnum(char c)
{
    if (c == '0')               return 0;
    if ('1' <= c && c <= '9')   return 1;
    if (c == '-')               return 2;
    if (c == 'x' || c == 'X')   return 3;
    if ('a' <= c && c <= 'f')   return 4;
    if ('A' <= c && c <= 'F')   return 5;
    if (c == ' ')               return 6;
    return 7;
}

// DFA状态转移表：二维数组实现
int Transfer[6][8] = {
    // 0;1-9; -; xX;a-f;A-F;spc;oth         
    { 1,  2,  3, -1,  5,  5,  0,  -1 },     // DFA状态0
    { 2,  2,  6,  4,  6,  6,  6,   6 },     // DFA状态1
    { 2,  2,  6,  6,  5,  5,  6,   6 },     // DFA状态2
    { 1,  2, -1, -1, -1, -1, -1,  -1 },     // DFA状态3
    { 5,  5, -1, -1,  5,  5,  6,   6 },     // DFA状态4
    { 5,  5,  6,  6,  5,  5,  6,   6 },     // DFA状态5
};

/// @brief 将字符串<str>转换为32位有符号整数
/// @param str 输入字符串，可以含有Leadning Spaces
/// @param val 指向输出结果的指针
/// @return 转换成功，返回1；失败，返回0
int string2num(char *str, int *val)
{
    int state = 0, i = 0, neg = 0, _state = 0, hex = 0, dec = 0;
    char c;
    
    // 一遍扫描
    while (1)
    {
        c = str[i];
        // DFA状态转移
        _state = state;
        state = Transfer[_state][get_inputnum(c)];
        
        // 根据当前状态，判断是否进行数值计算
        switch (state)
        {
            case -1:
                // 转换失败
                return 0;
            case 2:
                // 十进制数字/十六进制数计算
                dec = dec * 10 + (c - '0');
                hex = hex * 16 + (c - '0');
                break;
            case 3:
                // 数值为负数
                neg = 1;
                break;
            case 5:
                // 十六进制数计算
                hex = hex * 16 +
                 (('0' <= c && c <= '9') ? (c - '0') : 0) +
                 (('a' <= c && c <= 'f') ? (c - 'a' + 10) : 0) +
                 (('A' <= c && c <= 'F') ? (c - 'A' + 10) : 0);
                break;
            case 6:
                // 转换成功，按照上一个状态确定十进制/十六进制
                if (_state == 5) *val = hex;
                else if (_state == 2) *val = dec;
                else return 0;
                // 处理正负号
                if (neg == 1) *val = (*val) * -1;
                return 1;
            default: break;
        }
        i += 1;
    }
    // 转换失败
    return 0;
}

// 程序入口 - Entry Point
int main(int argc, char *argv[])
{
    int a = 0, s = string2num(argv[1], &a);
    // 打印绿色的成功结果
    if (s == 1) printf("\e[1;32m[OK]‘%s’ => %d \e[0m\n", argv[1], a);
    // 打印红色的失败结果
    else       printf("\e[1;31m[FAILED]‘%s’\e[0m\n", argv[1]);
    return 0;
}
