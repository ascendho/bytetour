# 选择自己的编译器路径，建议使用 gcc-10
CC = gcc # 使用系统默认的编译器
# 编译器参数（调试信息、警告全开、错误视为警告、C99 标准）
CFLAGS = -g -Wall -Werror -std=c99

build:
	$(CC) $(CFLAGS) RISCVint.c Resource.c MMU.c LoadImage.c Fetch.c \
	Decode.c Execute.c MemAccess.c WriteBack.c ALUUnit.c Branch.c LoadStore.c \
	UpdatePC.c -o RISCVint

run:
	./RISCVint ./loadstore-binary

clean:
	rm -f RISCVencoder riscv-binary