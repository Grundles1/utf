EXE = utf

SRC = utf.c \
ut.c \
test_toplevel.c
OBJ = $(SRC:.c=.o)
CC=gcc
WARNFLAGS= \
-Weverything \
-Werror \
-Wno-shadow \
-Wno-infinite-recursion \
-Wno-padded  
CFLAGS= -g $(WARNFLAGS)

all: $(EXE)
	./utf

debug: $(EXE)
	lldb ./utf

# profile: all
# 	gprof $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c 2>&1 >> build.log

coverage: all
	gcov -b .

clean: 
	rm -rf $(EXE) build.log *.o *.dSYM

$(EXE): $(OBJ)
	gcc $(CFLAGS) $^ -o $@ >> build.log
	


