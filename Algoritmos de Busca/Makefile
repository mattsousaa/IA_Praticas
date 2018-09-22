all: folder app

GCC = g++ -std=c++11
BIN = bin
OBJ = obj
INC = -Iinc/

app: main dfs bfs ucs state action node graph inputcmd
	@echo "Linking..."
	+@$(GCC) -o $(BIN)/app $(OBJ)/main.o $(OBJ)/dfs.o $(OBJ)/bfs.o $(OBJ)/ucs.o $(OBJ)/state.o $(OBJ)/action.o $(OBJ)/node.o $(OBJ)/graph.o $(OBJ)/inputcmd.o
	@echo "Binary are ready in $(BIN)/app"

main:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

dfs:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

bfs:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

ucs:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

state:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

action:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

node:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

graph:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

inputcmd:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

folder:
	@mkdir -p $(OBJ) $(BIN)

clean:
	@rm -rf $(OBJ)/* $(BIN)/* $(OBJ) $(BIN)

###############################################################################