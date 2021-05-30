all: folder app

GCC = g++ -std=c++11
BIN = bin
OBJ = obj
DATA = data
INC = -Iinc/

app: main cnf
	@echo "Linking..."
	+@$(GCC) -o $(BIN)/app $(OBJ)/main.o $(OBJ)/cnf.o
	@echo "Binary are ready in $(BIN)/app"

main:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

cnf:
	+@echo "Compile: $@"
	@$(GCC) src/$@.cpp $(INC) -c -o $(OBJ)/$@.o

folder:
	@mkdir -p $(DATA) $(OBJ) $(BIN)

clean:
	@rm -rf $(OBJ)/* $(BIN)/* $(DATA)/* $(DATA) $(OBJ) $(BIN)

###############################################################################
