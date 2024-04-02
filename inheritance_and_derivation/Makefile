CXXFLAGS = -std=c++17 -Wall 
CXX = g++


shape: shape.cpp shape.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^
.PHONY: clean
clean:
	@echo "Removing"
	@-del  shape.exe
	@echo "Removed"
