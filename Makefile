CC=g++
C_FLAGS=-c -I.
SRC_DIR=./src
OBJ_DIR=./obj
BIN_DIR=./bin


main.o: $(SRC_DIR)/main.cpp
	$(CC) $(C_FLAGS) $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

graph.o: $(SRC_DIR)/graph.cpp
	$(CC) $(C_FLAGS) $(SRC_DIR)/graph.cpp -o $(OBJ_DIR)/graph.o

finite_automata.o: $(SRC_DIR)/finite_automata.cpp
	$(CC) $(C_FLAGS) $(SRC_DIR)/finite_automata.cpp -o $(OBJ_DIR)/finite_automata.o

main: main.o graph.o finite_automata.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/graph.o $(OBJ_DIR)/finite_automata.o -o $(BIN_DIR)/main

run: main
	@echo "Running the program..."
	@$(BIN_DIR)/main < $(FILE)

clean:
	rm $(OBJ_DIR)/*.o