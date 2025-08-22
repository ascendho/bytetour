CC = gcc # 使用系统默认的编译器
CFLAGS = -g -Wall -Werror -std=c99 # 编译器参数
build:
	$(CC) $(CFLAGS) String2Num.c -o strnum
test: strnum
	./strnum "1"
	./strnum "2147483647"
	./strnum "2147483648"
	./strnum "-1"
	./strnum "-1234"
	./strnum "-2147483648"
	./strnum "0xabcd"
	./strnum "  abcd1234 abcd"
	./strnum "  -0xabcd"
	./strnum "0xffffffff"
	./strnum "-0x80000000"
	./strnum "-0xffffffff"
	./strnum "    1234"
	./strnum "   1234abcd"
	./strnum "0x12344abcd"
	./strnum "0xabcdHellow World"
	./strnum "NOT a Number"
clean:
	rm -f strnum
