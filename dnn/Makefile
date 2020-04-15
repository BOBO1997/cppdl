PROG = program
SRCS = main.cpp mylib.cpp variable.cpp
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)
CPP = g++
CFLAGS = -Wall -O3 -std=c++17

.PHONY: all clean
.PRECIOUS: %

all: $(PROG)

-include $(DEPS)

$(PROG): $(OBJS)
	-$(CPP) $(CFLAGS) -o $@ $^

%.o: %.c
	-$(CPP) -c -MMD -MP $<

clean:
	-rm -f $(PROG) $(OBJS) $(DEPS)

#https://www.wagavulin.jp/entry/20120405/1333629926
#https://tex2e.github.io/blog/makefile/automatic-variables
#https://marycore.jp/prog/xcode/undefined-symbols-for-architecture-x86-64/#%E3%83%98%E3%83%83%E3%83%80%E3%83%BC%E3%83%95%E3%82%A1%E3%82%A4%E3%83%AB%E3%81%8C%E3%82%A4%E3%83%B3%E3%82%AF%E3%83%AB%E3%83%BC%E3%83%89%E3%81%95%E3%82%8C%E3%81%A6%E3%81%84%E3%81%AA%E3%81%84
