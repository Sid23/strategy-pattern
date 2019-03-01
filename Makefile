IDIR=include
CC=g++
STD=-std=c++11
CFLAGS=$(STD) -I $(IDIR) -Wall
OBJS=main.o src/Animal.o
DEPS = $(patsubst %,$(IDIR)/%,Animal.h) $(patsubst %,$(IDIR)/%,interfaces.h)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

gTest: test/gTestMain.cpp main.cpp $(DEPS)
	$(CC) $(STD) -Iinclude -stdlib=libc++ -Iinclude -lgtest -pthread $< -o gTest
	#g++ -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	#ar -rv libgtest.a gtest-all.o
.PHONY: clean

clean:
	rm -f main gTest *.o *a src/*.o *~ core $(INCDIR)/*~ 