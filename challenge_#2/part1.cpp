#include <iostream>
#include <fstream>
#include <string>
int main(){
    std::string movement, sMovement, sMove;
    int horizontal = 0, depth = 0, nMove;
    std::ifstream inFile;
    inFile.open("input.txt");
    if(!inFile){
        std::cout << "error: unable to open input file";
        exit(1);            
    }
      
    while(inFile >> sMovement >> sMove){                      
        nMove = std::stoi(sMove);                
        if(sMovement == "forward")
            horizontal += nMove;
        else if(sMovement == "down")
            depth += nMove;
        else if(sMovement == "up")
            depth -= nMove;
    }
    std::cout << "depth: " << depth << std::endl;
    std::cout << "horizontal: " << horizontal << std::endl;
    std::cout << horizontal * depth;
}