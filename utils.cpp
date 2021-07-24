#include <iostream>
#include <vector>
#include <algorithm>

void initArrayWithConstant(int array[][6], int value){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 6; j++){
            array[i][j] = value;
        }
    }
}

void initArrayWithConstant(char array[][3], char value){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            array[i][j] = value;
        }
    }
}

void printArray(int array[][6]){
    for (int i = 0; i < 2; i++){
        std::cout << std::endl;
        for (int j = 0; j < 6; j++){
            std::cout << array[i][j] << " ";
        }
    }
    std::cout << std::endl << std::endl;
}

void printArray(char array[][3]){
    for (int i = 0; i < 3; i++){
        std::cout << "|";
        for(int j = 0; j < 3; j++){
            std::cout << " " << array[i][j] << " |";
        }
        std::cout << std::endl;
    }
}

bool ticTacToeCheckVIctory(char palyerName, char field[][3]){
    bool res = false;
    for (int i = 0; i < 3; i++){
        if (
                (                           // check row
                field[i][0] == palyerName &&
                field[i][1] == palyerName &&
                field[i][2] == palyerName
                ) ||
                (                           // check column
                field[0][i] == palyerName &&
                field[1][i] == palyerName &&
                field[2][i] == palyerName
                )
                ){
            return true;
        }
    }
    return false;
}

void ticTacToeEnter(char playerName, char field[][3]){
    int row, col;
    std::cout << playerName << " player, your turn (enter row and col indices): " << std::endl;
    std::cin >> row >> col;
    bool correct = row <= 2 && col <= 2 && field[row][col] == ' ';
    while (!correct) {
        std::cout << "Invalid coordinates" << std::endl;
        std::cout << playerName << " player, your turn (enter row and col indices): " << std::endl;
        std::cin >> row >> col;
        correct = row <= 2 && col <= 2 && field[row][col] == ' ';
    }
    field[row][col] = playerName;
}

bool ticTacToeContinue(char field[][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (field[i][j] == ' ') return true;
        }
    }
    return false;
}

void enterMatrix(int matrix[][4]){
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << "Enter element " << i << ", " << j << std::endl;
            std::cin >> matrix[i][j];
        }
    }
}

void enterVector(float vector[4]){
    for(int i = 0; i < 4; i++){
            std::cout << "Enter element " << i << std::endl;
            std::cin >> vector[i];
    }
}

bool checkMatrixEquality(int a[][4], int b[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

void enterMatrix(float matrix[][4]){
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            std::cout << "Enter element " << i << ", " << j << std::endl;
            std::cin >> matrix[i][j];
        }
    }
}

void enterData(int & x, int low, int high, std::string name){
    do{
        std::cout << "Enter " << name << std::endl;
        std::cin >> x;
    }while (x > high || x < low);
}

bool bubblesAvailable(bool bubbles[][12], int rowStart, int colStart, int rowEnd, int colEnd){
    for (int i = rowStart; i < rowEnd; ++i){
        for (int j = colStart; j < colEnd; ++j){
            if (bubbles[i][j]) {
                return true;
            }
        }
    }
    return false;
}

void printBubbles(bool bubbles[][12]){
    for (int i = 0; i < 12; ++i){
        for (int j = 0; j < 12; ++j){
            if (bubbles[i][j]) {
                std::cout << "O ";
            } else{
                std::cout << "X ";
            }
        }
        std::cout << std::endl;
    }
}

void initBubbles(bool bubbles[][12]){
    for (int i = 0; i < 12; ++i){
        for (int j = 0; j < 12; ++j){
            bubbles[i][j] = true;
        }
    }
}

void enterBins(bool bins[][5][10]){
    int height = 0;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            std::cout << "row: " << i << std::endl << "col: " << j << std::endl;
            enterData(height, 0, 10, "block height");
            for (int k = 0; k < 10; ++k){
                bins[i][j][k] = k < height;
            }
        }
    }
}

void enterShip(int deckLength, std::vector<std::vector<int>> & shipCoords, int field[][10]) {
    bool inputSuccess;
    int row1, col1, row2, col2;
    do{
        enterData(row1, 0, 10, "ship start row");
        enterData(col1, 0, 10, "ship start col");
        enterData(row2, row1, 10, "ship end row");
        enterData(col2, col1, 10, "ship end col");
        inputSuccess = (row1 == row2 && col2 - col1 == deckLength - 1) || (col1 == col2 && row2 - row1 == deckLength -1);
        if (!inputSuccess) std::cout << "Invalid ship placement" << std::endl;
    }while(!inputSuccess);
    if (row1 == row2){
        // horizontal ship
        for (int i = col1; i <= col2; ++i){
            std::vector<int> coords = {row1, i};
            shipCoords.push_back(coords);
        }
    }
    else if (col1 == col2){
        // vertical ship
        for (int i = row1; i <= row2; ++i){
            shipCoords.push_back(std::vector<int>({i, col1}));
        }
    }
    else{
        std::cout << "Coords error" << std::endl;
    }
    for (std::vector<int> coordPair : shipCoords){
        if (field[coordPair[0]][coordPair[1]] != 0){
            std::cout << "Cannot place ship at cell " << coordPair[0] << " " << coordPair[1] << std::endl;
            shipCoords.clear();
            enterShip(deckLength, shipCoords, field);
        }
    }
}

void setupShips(int field[][10], int hits[10]) {

    for (int i = 1; i <= 4; i++) {
        std::vector<std::vector<int>> shipCoords;
        std::cout << "Enter " << 1 << " deck ship No: " << i << std::endl;
        enterShip(1, shipCoords, field);
        // place ship on the field
        for (std::vector<int> coordPair : shipCoords){
            field[coordPair[0]][coordPair[1]] = i;
        }
    }

    for (int i = 5; i <= 7; i++) {
        std::vector<std::vector<int>> shipCoords;
        std::cout << "Enter " << 2 << " deck ship No: " << i << std::endl;
        enterShip(2, shipCoords, field);
        // place ship on the field
        for (std::vector<int> coordPair : shipCoords){
            field[coordPair[0]][coordPair[1]] = i;
        }
    }

    for (int i = 8; i <= 9; i++) {
        std::vector<std::vector<int>> shipCoords;
        std::cout << "Enter " << 3 << " deck ship No: " << i << std::endl;
        enterShip(3, shipCoords, field);
        // place ship on the field
        for (std::vector<int> coordPair : shipCoords){
            field[coordPair[0]][coordPair[1]] = i;
        }
    }

    for (int i = 10; i <= 10; i++) {
        std::vector<std::vector<int>> shipCoords;
        std::cout << "Enter " << 4 << " deck ship No: " << i << std::endl;
        enterShip(4, shipCoords, field);
        // place ship on the field
        for (std::vector<int> coordPair : shipCoords){
            field[coordPair[0]][coordPair[1]] = i;
        }
    }
}

bool checkVictory(int hits[], int decks[]){
    for (int i = 0; i < 10; i++){
        if (hits[i] != decks[i]) return false;
    }
    return true;
}

void printField(int field[][10]){
    std::cout << "\t";
    for (int i = 0; i < 10; ++i){
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "\t";
    for (int i = 0; i < 10; ++i){
        std::cout << "-\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i){
        std::cout << i << " |\t";
        for (int j = 0; j < 10; ++j){
            if(field[i][j] >= 0){
                std::cout << "O";
            }
            else if (field[i][j] > -9000 && field[i][j] < 0) {
                std::cout << "X";
            }
            else if (field[i][j] == -9001){
                std::cout << "-";
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }
}

void printField(int field[][10], bool debug){
    std::cout << "\t";
    for (int i = 0; i < 10; ++i){
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "\t";
    for (int i = 0; i < 10; ++i){
        std::cout << "-\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i){
        std::cout << i << " |\t";
        for (int j = 0; j < 10; ++j){
            if(field[i][j] == 0){
                std::cout << "O";
            }
            else if (field[i][j] > -9000 && field[i][j] < 0) {
                std::cout << "X";
            }
            else if (field[i][j] == -9001){
                std::cout << "-";
            }
            if(field[i][j] > 0){
                std::cout << field[i][j];
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }
}

bool takeShot(int field[][10], int hits[], int decks[]){
    int row, col;
    enterData(row, 0, 10, "shot row");
    enterData(col, 0, 10, "shot col");
    if (field[row][col] > 0){
        hits[field[row][col] - 1]++;
        if (hits[field[row][col] - 1] == decks[field[row][col] - 1]){
            std::cout << "Destroyed " << decks[field[row][col] - 1] << " cell ship" << std::endl;
        }
        else{
            std::cout << "Wounded!" << std::endl;
        }
        field[row][col] *= -1;
        printField(field);
        return checkVictory(hits, decks);
    }
    else if (field[row][col] == 0){
        std::cout << "Miss!" << std::endl;
        field[row][col] = -9001;
        printField(field);
    }
    else if (field[row][col] < 0) {
        std::cout << "Illegal coordinates, already shot here" << std::endl;
        takeShot(field, hits, decks);
    }
    return false;
}