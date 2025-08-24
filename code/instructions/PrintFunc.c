// 手动定义基本数据类型，避免包含stdint.h
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

// 手动声明printf函数，避免包含stdio.h
int printf(const char *format, ...);

/// @brief 打印函数指令的函数
/// @param func 待打印函数的函数指针
void print_func(void *func) 
{
    uint32_t a = *(uint32_t *)func; 
    uint8_t *b = (uint8_t *)&a; 
    // 直到遇到 ret 指令为止
    // 仅用于函数以 ret 指令返回的情况
    while (1) 
    {
        printf("%p: %02x %02x %02x %02x\n", func, b[0], b[1], b[2], b[3]); 
        if (a == 0x00008067) 
            break;
        // 更新函数指针的位置：下一条指令
        func += 4; 
        a = *(uint32_t *)func; 
        b = (uint8_t *)&a; 
    }
}

// 主函数
void main() 
{
    // 打印 main 自身
    print_func(&main);
}