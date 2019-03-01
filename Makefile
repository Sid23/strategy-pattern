IDIR=include
CC=g++
STD=-std=c++11
CFLAGS=$(STD) -I $(IDIR) -Wall
OBJS=main.o src/Animal.o
DEPS = $(patsubst %,$(IDIR)/%,Animal.h) $(patsubst %,$(IDIR)/%,interfaces.h)

TEST_DEPS = libgtest.a gtest-all.o

all: main gTest

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.a: gtest-all.o
	ar -rv $@ $<

gtest-all.o:
	$(CC) $(STD) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc

gTest: test/gTestMain.cpp main.cpp $(DEPS) $(TEST_DEPS)
	$(CC) $(CFLAGS) -Iinclude -stdlib=libc++ -lgtest -pthread $< -o gTest
	#g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	#ar -rv libgtest.a gtest-all.o
.PHONY: clean

clean:
	rm -f main gTest *.o *a src/*.o *~ core $(INCDIR)/*~ 