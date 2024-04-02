CXXFLAGS = -std=c++11 -Wall 
CXX = g++

point: point.cpp point.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^
.PHONY: clean
clean:
	@echo "Removing"
	@-del  point.exe
	@echo "Removed"
