CC = gcc # 使用系统默认的编译器
CFLAGS = -g -Wall -Werror -std=c99  # 编译器参数
build:
	$(CC) $(CFLAGS) Adder32.c -o adder32
test: adder32
	./adder32 1 2
	./adder32 2147483648 1
	./adder32 4294967295 0
	./adder32 4294967295 1
	./adder32 2147483647 1
	./adder32 2147483647 0
	./adder32 2147483648 4294967295
	./adder32 2147483648 2147483648
clean:
	rm -f adder32