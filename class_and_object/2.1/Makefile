CXXFLAGS = -std=c++17 -Wall

circle: circle.o
	g++ $(CXXFLAGS) -o $@ $^

circle.o: circle.hpp

.PHONY: clean test
clean:
	@echo "Removing"
	@-del  *.o
	@-del  circle.exe
	@echo "Removed"

# test:
# 	@echo $(shell powershell "Get-Content testmatrix.txt | ./matrix.exe")
