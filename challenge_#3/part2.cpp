#include <string>
#include <iostream>
#include <fstream>
int main()
{
    std::string line, sToInt;
    int digit, gamToDec = 0, epsToDec = 0, onesCounter = 0, zerosCounter = 0;
    int arrayOfBinary[1000][12] = {0};
    int tempArray[1000][12];
    int gammaRate[12], epsilonRate[12];
    std::ifstream inFile;
    inFile.open("input.txt");
    if(!inFile){
        std::cout << "error: unable to open input file";
        exit(1);            
    }
    
    int i = 0;
    while(inFile >> line){                      
        for(int j = 0; j < 5; j++){
            sToInt = line.at(j);
            digit = std::stoi(sToInt);
            arrayOfBinary[i][j] = digit;
        }
        i++;
    } 

    i = 0;
    int index = 0;
    while(i < 1){
        int j = 0;
        while(j < 12){
            if(arrayOfBinary[j][i] == 1){
                int k = 0;
                while(k < 5){
                    tempArray[index][k] = arrayOfBinary[j][k];
                    index++;
                    k++;
                }
            }
            j++;
        }
        i++;
    }

    i = 0;
    while(i < 12){
        int j = 0;
        std::cout << std::endl;
        while(j < 5){
            std::cout << tempArray[i][j];
            j++;
        }
        i++;
    }
    
}