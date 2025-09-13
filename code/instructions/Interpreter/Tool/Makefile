CC = gcc # 使用系统默认的编译器
CFLAGS = -g -Wall -Werror -std=c99  # 编译器参数（调试、警告全开、C99 标准）

build:
	$(CC) $(CFLAGS) CreateBin.c -o bin  # 编译生成可执行工具 bin

clean:
	rm -f bin  # 清理生成的可执行文件