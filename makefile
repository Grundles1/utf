APP = toplevel

UTs=$(wildcard ut/*.c)

SRC=test_toplevel.c \
$(FW) \
$(UTs)
LIB=./fw/utf.a

LIBINC=-L ./fw
INC=-I ./ut \
-I ./fw

OBJ = $(SRC:.c=.o)

CFLAGS= $(LIBINC) $(INC) --verbose
CC=gcc

all: utf $(APP)
	./$(APP)

debug: $(APP)
	lldb ./$(APP)

utf:
	make -f fw/makefile

$(UTs):
	make -f ut/makefile

# profile: all
# 	gprof $(APP)

$(APP): $(OBJ)
	gcc $(CFLAGS) $(LIB) $^ -o $@ >> build.log

coverage: all
	gcov -b .

clean: 
	-@rm -rf $(APP) build.log 2>/dev/null
	-@find . -name *.o -delete 2>/dev/null
	-@find . -name *.a -delete 2>/dev/null



