#include <iostream>
#include <fstream>
#include <string>
int main(){
    std::ifstream inFile;
    int counter = 0, trash = 0, num, tempNum;
    int inputArray[2000];
    std::string line;

    inFile.open("input.txt");
    if(!inFile){
        std::cout << "error: unable to open input file";
        exit(1);            
    }

    int i = 0;          
    while(inFile >> line){                      //*
        num = std::stoi(line);                  //*     while loop to asign input file to array
        inputArray[i] = num;                    //*
        i++;
    }

    num = 0;         
    i = 0;
    while(i < (sizeof(inputArray) / sizeof(inputArray[0]))){
        num = inputArray[i];
        if(trash == 0)
            trash++;
        else if(num > tempNum)
            counter++;
        tempNum = num;
        i++;
    }
    std::cout << "\n" << counter << std::endl;
}