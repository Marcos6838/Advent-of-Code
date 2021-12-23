#include <string>
#include <iostream>
#include <fstream>
int main()
{
    std::string line, sToInt;
    int digit, gamToDec = 0, epsToDec = 0, onesCounter = 0, zerosCounter = 0;
    int arrayOfBinary[1000][12] = {0};
    int gammaRate[12], epsilonRate[12];
    std::ifstream inFile;
    inFile.open("input.txt");
    if(!inFile){
        std::cout << "error: unable to open input file";
        exit(1);            
    }
    
    int i = 0;
    while(inFile >> line){                      
        for(int j = 0; j < 12; j++){
            sToInt = line.at(j);
            digit = std::stoi(sToInt);
            arrayOfBinary[i][j] = digit;
        }
        i++;
    } 

    
}