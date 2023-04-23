#Chris Manlove, Ayushmann Puri, Kyle Tran, Jenny Chen
#April 2023
#Makefile for Course Sprout

EXE = main
CXX = @g++
CXXFLAGS = -Wall -g -std=c++20 -O2
LINKERFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

$(EXE): $(OBJ) makefile 
				@rm -f $(EXE)
				$(CXX) src/*.cpp $(CXXFLAGS) $(LINKERFLAGS) -o $(EXE)
clean:
				@rm -f $(EXE)
run: $(EXE)
				@./$(EXE)
