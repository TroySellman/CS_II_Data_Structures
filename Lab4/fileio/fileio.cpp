#include <iostream>
#include <fstream>

// Function Prototypes
void PrintWord();
void Sum2Num();

// Main
int main(){
    PrintWord();
    std::cout << "\n";
    Sum2Num();
    std::cout << "\n";
    return 0;
}

// Function Declarations
void PrintWord () {
    std::ifstream file("fileio-text.txt");
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
        return;
    }
    char c;
    while(!file.eof()){
        file.get(c);
        if(c == '\n') {
            std::cout << "\n";
            continue;
        }
        if(c != ' ')  std::cout << c;
        else std::cout << "\n";
        if(file.eof()) return;
    }
    file.close();
}

void Sum2Num() {
    std::ifstream file("fileio-data-1.txt");
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
        return;
    }
    int num1 = 0;
    int num2 = 0;
    int sum  = 0;
    char c;
    bool flag1 = false; // for first semicolon
    bool flag2 = false; // for second semicolon
    while (!file.eof()){
        file.get(c);
        if (c == '\n') continue;
        if (c == ';' && flag1) flag2 = true; // reached second semicolon
        if (c == ';')          flag1 = true; // reached first semicolon
        if (!flag1 && (c != ' ') && (c != ';'))          num1 = num1 * 10 + (c - '0'); 
        if (flag1 && !flag2 && (c != ' ') && (c != ';')) num2 = num2 * 10 + (c - '0');
        if (flag1 && flag2) {
            sum = num1 + num2;
            std::cout << sum << "\n";
            flag1 = false;
            flag2 = false;
            sum   = 0;
            num1  = 0;
            num2  = 0;
        }
        if (file.eof()) return;
    }
    file.close();
}
