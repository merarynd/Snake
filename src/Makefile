CC=g++
CFLAGS=-Wall -Werror -Wextra -g -lstdc++ -std=c++17
OUTFLAG = -Wall -Werror -Wextra -o out
TEST=Snake_tests
TARGET=Snake
OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK_FLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit -lgtest
else
 CHECK_FLAGS = -lcheck -lm -lpthread -lgtest
endif

all: clean Snake.a

clean:
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info
	rm -rf *.dSYM
	rm -rf tests
	rm -rf test
	rm -rf *.a
	rm -rf *.out
	rm -rf *.o

Snake.a:
	$(CC) -g -c $(CFLAGS) *.cc
	ar rcs Snake.a *.o
	ranlib Snake.a

obj:
	$(CC) -g  $(OUTFLAG) $(TARGET).cc

test: clean $(TARGET).a
	$(CC) $(CFLAGS) $(TARGET).a $(TEST).cc -o test.out -lgtest	
	./test.out

style: 
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -n *.cc
	clang-format -n *.h
	rm -rf .clang-format

leaks: test
	CK_FORK=no leaks --atExit -- ./test.out

gcov_report:
	gcc $(CFLAGS) -fprofile-arcs -ftest-coverage Snake_tests.cc Snake.cc $(CHECK_FLAGS) -o test
	./test
	lcov -t "test" --ignore-errors mismatch -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html