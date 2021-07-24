#ifndef ASSIGNMENT_2D_ARRAYS_UTILS_H
#define ASSIGNMENT_2D_ARRAYS_UTILS_H
void initArrayWithConstant(int array[][6], int value);
void initArrayWithConstant(char array[][3], char value);
void printArray(int array[][6]);
void printArray(char array[][3]);
bool ticTacToeCheckVIctory(char palyerName, char field[][3]);
void ticTacToeEnter(char playerName, char field[][3]);
bool ticTacToeContinue(char field[][3]);
void enterMatrix(int matrix[][4]);
void enterMatrix(float matrix[][4]);
void enterVector(float vector[4]);
bool checkMatrixEquality(int a[][4], int b[][4]);
void enterData(int & x, int low, int high, std::string name);
bool bubblesAvailable(bool bubbles[][12], int rowStart, int colStart, int rowEnd, int colEnd);
void printBubbles(bool bubbles[][12]);
void initBubbles(bool bubbles[][12]);
void enterBins(bool bins[][5][10]);
void setupShips(int field[][10], int pInt[10]);
bool takeShot(int field[][10], int hits[], int decks[]);
void printField(int field[][10], bool debug);
#endif //ASSIGNMENT_2D_ARRAYS_UTILS_H
