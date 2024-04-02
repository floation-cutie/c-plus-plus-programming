CXXFLAGS = -std=c++11 -Wall 
CXX = g++

matrix: main.o matrix.o
	$(CXX) $(CXXFLAGS) -o $@ $^

matrix.o: matrix.cpp matrix.hpp

.PHONY: clean
clean:
	@echo "Removing"
	@-del  *.o
	@-del  matrix.exe
	@echo "Removed"
