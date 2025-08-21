CC = gcc # 使用系统默认的编译器
CFLAGS = -g -Wall -Werror -std=c99 # 编译器参数
build:
	$(CC) $(CFLAGS) Overflow.c -o overflow
test: overflow
	./overflow 1 2
	./overflow 1 ffffffff
	./overflow 1 7fffffff
	./overflow 80000000 80000000
clean:
	rm -f overflow
	