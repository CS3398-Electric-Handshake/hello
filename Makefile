CPPUNIT_PREFIX = /usr

CXX = g++
FLAGS += -Wall
LIBS += -lcppunit -ldl
LDFLAGS += -L$(CPPUNIT_PREFIX)/lib
LDFLAGS += $(LIBS)

default: main

hello.o: main.cpp
	$(CXX) $(FLAGS) -c $^ -o $@

hello: main.o
	$(CXX) $(FLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f main
	rm -f main.o

.PHONY: clean
	
