#include<iostream>
#include<string>
#include<cmath>
#include<string>
#include<array>

// 0 = emty 1 = X 2 = O
std::array<int,9> Board = {};
int turn = 0;
std::array<std::string,9> CharBoard {""};

void printBoard(){
 for(int i = 0; i < 9; i++){
  if(Board.at(i) == 1){CharBoard.at(i) = "X";}
  else if(Board.at(i) == 1){CharBoard.at(i) = "Y";}
  else{CharBoard.at(i) = " ";}
  std::cout<<CharBoard.at(0)<<"|"<<CharBoard.at(1)<<"|"<<CharBoard.at(2)<<"\n"<<
