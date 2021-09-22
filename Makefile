# Simple target
#
# The name of a target is the string before `:` and it's followed by its dependencies

CXX=gcc

CXXFLAGS ?=
CXXFLAGS += -Wall

SRCS = $(wildcard ./src/*.c)

all: test

# Build the executable test
test: $(SRCS)
	$(CXX) $^ -o $@

# Phony target to run test
run: test
	./test

# Phony target to clean the working folder
clean:
	rm -rf test
    
.PHONY: run clean

