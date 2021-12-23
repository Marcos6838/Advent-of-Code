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

    i = 0;
    while(i < 12 + 1){
        int j = 0;
        if(zerosCounter > onesCounter){
            i--;
            gammaRate[i] = 0;
            i++;
        }
        else if(onesCounter > zerosCounter){
            i--;
            gammaRate[i] = 1;
            i++;
        }
        zerosCounter = 0;
        onesCounter = 0;

        while(j < 1000){
            if(arrayOfBinary[j][i] == 1)
                onesCounter++;
            else if(arrayOfBinary[j][i] == 0)
                zerosCounter++;
            j++;
        }
        i++;
    }

    for(int i = 0; i < 12; i++){
        if(gammaRate[i] == 0)
            epsilonRate[i] = 1;
        else if(gammaRate[i] == 1)
            epsilonRate[i] = 0;
    }
    
    i = 0;
    while(i < 12){
        gamToDec =  gamToDec * 2 + gammaRate[i];
        i++;
    }

    std::cout << std::endl;

    i = 0;
    while(i < 12){
        epsToDec = epsToDec * 2 + epsilonRate[i];
        i++;
    }

    std::cout << epsToDec << " " << gamToDec << std::endl;
    long answer = epsToDec * gamToDec;
    std::cout << answer;
    
}