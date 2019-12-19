APP = toplevel

UTs=$(wildcard ut/*.c)

SRC=test_toplevel.c \
$(FW) \
$(UTs)
LIB=utf.a

LIBINC=-L fw
INC=-I ./ut \
-I ./fw

OBJ = $(LIB) \
$(SRC:.c=.o)

CFLAGS= $(INC)
CC=gcc

all: $(APP)
	./$(APP)

debug: $(APP)
	lldb ./$(APP)

utf.a:
	make -f fw/makefile

$(UTs):
	make -f ut/makefile

# profile: all
# 	gprof $(APP)

$(APP): utf.a $(OBJ)
	gcc $(CFLAGS) $(LIB) $^ -o $@ >> build.log

coverage: all
	gcov -b .

clean: 
	-@rm -rf $(APP) build.log 2>/dev/null
	-@find . -name *.o -delete 2>/dev/null
	-@find . -name *.a -delete 2>/dev/null



