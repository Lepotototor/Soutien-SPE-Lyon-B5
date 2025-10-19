CC=gcc
CFLAGS=-Wall -Wextra -Wvla -Werror

SRC=src/main.c src/array_even.c src/merge_blocks.c src/get_childs.c src/str_to_upper.c src/resize_tab.c
OBJ=main.o array_even.o merge_blocks.o get_childs.o str_to_upper.o resize_tab.o
BIN=dragons

TESTSUITE_SRC = tests/testsuite_merge_blocks.c tests/testsuite_get_childs.c tests/testsuite_array_even.c tests/testsuite_str_to_upper.c tests/testsuite_resize_tab.c tests/testsuite_sub_tab.c
TESTSUITE_OBJ = testsuite_merge_blocks.o testsuite_get_childs.o testsuite_array_even.o testsuite_str_to_upper.o testsuite_resize_tab.o testsuite_sub_tab.o
TESTSUITE_BIN = dragons_testsuite

all: CFLAGS +=  -g -fsanitize=address
all: LDFLAGS +=  -g -fsanitize=address
all: CPPFLAGS = -DMERGE_BLOCKS -DARRAY_EVEN -DGET_CHILDS -DSTR_TO_UPPER -DRESIZE_TAB
all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

$(OBJ): $(SRC)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^

merge_blocks: CPPFLAGS += -DMERGE_BLOCKS
merge_blocks: $(BIN)
	./$(BIN)

array_even: CPPFLAGS += -DARRAY_EVEN
array_even: $(BIN)
	./$(BIN)

get_childs: CPPFLAGS += -DGET_CHILDS
get_childs: $(BIN)
	./$(BIN)

str_to_upper: CPPFLAGS += -DSTR_TO_UPPER
str_to_upper: $(BIN)
	./$(BIN)

resize_tab: CPPFLAGS += -DRESIZE_TAB
resize_tab: $(BIN)
	./$(BIN)


intra: CPPFLAGS += -DDEBUG
intra: LDLIBS += -lcriterion
intra: $(TESTSUITE_BIN)
	./tests/intra.sh

check: CPPFLAGS += -DDEBUG
check: LDLIBS += -lcriterion
check: $(TESTSUITE_BIN)
	./$(TESTSUITE_BIN)

$(TESTSUITE_BIN): $(OBJ) $(TESTSUITE_OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(TESTSUITE_OBJ): $(TESTSUITE_SRC)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^

clean:
	$(RM) $(OBJ) $(BIN) $(TESTSUITE_OBJ) $(TESTSUITE_BIN) trace.xml
