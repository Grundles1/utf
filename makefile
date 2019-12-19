APP = utf

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
CFLAGS= -g -pg $(WARNFLAGS)

all: $(APP)
	./utf

debug: $(APP)
	lldb ./utf

# profile: all
# 	gprof $(APP)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c 2>&1 >> build.log

coverage: all
	gcov -b .

clean: 
	-@rm -rf $(APP) $(OBJ) build.log 2>/dev/null

$(APP): $(OBJ)
	gcc $(CFLAGS) $^ -o $@ >> build.log
	


