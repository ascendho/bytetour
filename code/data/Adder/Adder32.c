#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// @brief 32位加法器：支持有符号数、无符号数加减法
// @param x 加法输入比特串。注意，这不是数值！
// @param y 加法输入比特串。注意，这不是数值！  
// @param cf 进位指针。如果无符号数溢出，设为1
// @param sf 符号位指针。设为加减法结果的最高位比特
// @param of 有符号数溢出指针。如果溢出，设为1
// @return 有符号数、无符号数加减法比特串。不是数值！

uint32_t adder_32(uint32_t x, uint32_t y, uint32_t *cf, uint32_t *sf, uint32_t *of)
{
    uint32_t a = 0;     // 加法器结果比特串
    uint32_t cj = 0;    // cj即c[i+1], 输出的进位
    uint32_t ci = 0;    // c[i]，输入的进位。c[0]被定为0
    uint32_t xi = 0;    // x的第[i]位x[i]
    uint32_t yi = 0;    // y的第[i]位y[i]
    uint32_t ai = 0;    // a的第[i]位a[i]

    // 从最低位[0]到最高位[31], 按位相加
    for (uint32_t i = 0; i < 32; i++)
    {
        xi = ((x >> i) & 1);  // 得到x[i]
        yi = ((y >> i) & 1);  // 得到y[i]
        ci = cj;              // 得到c[i], 即上一组进位的结果

        // 根据真值表计算a[i], c[i+1]
        ai = (xi ^ yi ^ ci);
        cj = (xi & yi) | (ci & (xi ^ yi));

        // 将a[i]的结果写入a的比特串
        a = a | ((ai & 1) << i);
    }

    // 根据指针，将结果写入指针所指向的内存
    *cf = (cj & 1);
    *sf = (ai & 1);
    *of = ((ci ^ cj) & 1);
    return a;
}

int main(int argc, char *argv[])
{
    uint32_t cf, sf, of;
    // 将程序命令行参数转换为加法器的输入比特串
    uint32_t x = strtoul(argv[1], NULL, 10);
    uint32_t y = strtoul(argv[2], NULL, 10);
    // 调用加法器函数
    uint32_t a = adder_32(x, y, &cf, &sf, &of);
    // 打印计算结果：结果比特串、CF,SF,OF的数值
    printf("x, y, a, cf, sf, of)\n");
    printf("0x%x + 0x%x = 0x%x\nCF=%u,SF=%u,OF=%u\n", 
           x, y, a, cf, sf, of);
    return 0;
}