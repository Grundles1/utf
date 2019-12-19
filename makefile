APP = toplevel

UTs=$(wildcard ut/*.c) 
FW=$(wildcard fw/*.c) 

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

$(UTs):
	make -f ut/makefile

# profile: all
# 	gprof $(APP)

$(APP): utf.a $(OBJ)
	gcc $(CFLAGS) $(LIB) $^ -o $@ >> build.log

coverage: all
	gcov -b .

clean: 
	-@rm -rf $(APP) 2>/dev/null
	-@find . -name build.log -delete 2>/dev/null
	-@find . -name *.o -delete 2>/dev/null
	-@find . -name *.a -delete 2>/dev/null



