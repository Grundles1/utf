APP = utf
LIB = $(CURR_DIR)/utf.a
CURR_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

SRC =$(CURR_DIR)/utf.c
OBJ = $(SRC:.c=.o)
CC=gcc
WARNFLAGS= \
-Weverything \
-Werror \
-Wno-shadow \
-Wno-infinite-recursion \
-Wno-padded  
CFLAGS= -g $(WARNFLAGS)

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^ >> build.log

clean: 
	-@rm -rf $(APP) build.log 2>/dev/null
	-@find . -name *.o -delete 2>/dev/null



