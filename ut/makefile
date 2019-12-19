SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
WARNFLAGS= \
-Weverything \
-Werror \
-Wno-shadow \
-Wno-infinite-recursion \
-Wno-padded  
INC=-I ../fw
CFLAGS= -g $(WARNFLAGS) $(INC)
CC=gcc

all: $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c 2>&1 >> build.log

# coverage: all
# 	gcov -b .

clean: 
	-@rm -rf $(APP) build.log 2>/dev/null
	-@find . -name *.o -delete 2>/dev/null
	-@find . -name *.a -delete 2>/dev/null



