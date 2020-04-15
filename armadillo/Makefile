CPP = g++
CFLAGS = -Wall -O2 -larmadillo
TESTS = \
test1.cpp

.PHONY: all clean

all: $(TESTS:%.cpp=%)

.PRECIOUS: %

%: %.cpp
	-$(CPP) $(CFLAGS) $^ -o $@

clean:
	-rm -f $(TESTS:%.cpp=%)
