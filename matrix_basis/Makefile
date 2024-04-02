CXXFLAGS = -std=c++17 -Wall

matrix: matrix.o
	g++ $(CXXFLAGS) -o $@ $^

matrix.o: matrix.cpp

.PHONY: clean test
clean:
	@echo "Removing"
	@-del  *.o
	@-del  matrix.exe
	@echo "Removed"

test:
	@echo $(shell powershell "Get-Content testmatrix.txt | ./matrix.exe")
