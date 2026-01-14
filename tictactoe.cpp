#include<iostream>
#include<string>
#include<string>
#include<array>
#include<vector>
#include<algorithm>



// 0 = emty 1 = X 2 = O
std::array<int,9> Board = {0,0,0,0,0,0,0,0,0};
int turn = 2;
std::array<std::string,9> CharBoard {"","","","","","","","",""};
int addy = 0;
std::array<std::string,3> possibleInt= {"0","1","2"};
std::vector<std::string> pastMoves = {};

void printBoard(){
 for(int i = 0; i < 9; i++){
  if(Board.at(i) == 1){CharBoard.at(i) = "X";}
  else if(Board.at(i) == 2){CharBoard.at(i) = "O";}
  else{CharBoard.at(i) = " ";}
  }
  std::cout<<"0   1   2\n  "<<CharBoard.at(0)<<"|"<<CharBoard.at(1)<<"|"<<CharBoard.at(2)<<"\n_________\n1 "<<CharBoard.at(3)<<"|"<<CharBoard.at(4)<<"|"<<CharBoard.at(5)<<"\n_________\n  "<<CharBoard.at(6)<<"|"<<CharBoard.at(7)<<"|"<<CharBoard.at(8)<<"\n2\n";
 }
 
int winCheckNormal(){
   for(int i = 0;i < 3; i++){
       //vert
   if((Board.at(0 + i ) == turn) && (Board.at(3 + i) == turn) && (Board.at(6 + i) == turn)){
    return 1;  
    }
   //horizontal
   if((Board.at(i * 3) == turn) && (Board.at(i * 3 + 1) == turn) && (Board.at(i * 3 + 2) == turn)){
    return 1;  
    }

   }
   //diagnol
   if(((Board.at(0) == turn ) && (Board.at(4) == turn) && (Board.at(8) == turn)) || ((Board.at(2) == turn) && (Board.at(4) == turn) && (Board.at(6) == turn))){
       return 1;
    }
    if(pastMoves.size() >= 9){  
    return 2;
   }
   return 0;
   
}

void modifyBoard(std::string Move){
 addy = 0;
//int x = std::stoi(Move.substr(Move.find("(") + 1,1))));
//int y = std::stoi(,Move.substr(Move.find(",") + 1,1)));
std::array<std::string,3> possibleInt= {"0","1","2"};
 int x = 0;
 int y = 0;
 //move checking

 
for(int Check = 0; Check == 0;){

  if((Move.find("(") == std::string::npos) || (Move.find(",") == std::string::npos) || (Move.find(")") == std::string::npos) || (Move.find(")") < Move.find(",")) || (Move.find(",") < Move.find("("))){
     std::cout<<"ERROR:Incorect format \"(x,y)\" try again:\n";
     std::getline(std::cin, Move);
     continue;
  }

  if(((std::find(std::begin(possibleInt),std::end(possibleInt) + 1,(Move.substr(Move.find("(") + 1,1)))) == (std::end(possibleInt) + 1)) || ((std::find(std::begin(possibleInt),std::end(possibleInt) + 1,Move.substr(Move.find(",") + 1,1))) == std::end(possibleInt) + 1)){
    std::cout<<"ERROR:Invalid carecter try again:\n";
     std::getline(std::cin, Move);
     continue;
  }
 
  if(std::find(pastMoves.begin(), pastMoves.end() + 4, Move) != pastMoves.end() + 4){
   std::cout<<"ERROR:Illegal move try again:\n";
   std::getline(std::cin, Move);
   continue;
  }
  Check++;
 }
 pastMoves.push_back(Move);
x = std::stoi(Move.substr(1,Move.find(",") - 1));
y = std::stoi(Move.substr(Move.find(",") + 1,Move.find(")") - 1));

 if(x == 0 && y == 0){addy = 0;}
 if(x == 1 && y == 0){addy = 1;}
 if(x == 2 && y == 0){addy = 2;}
 if(x == 0 && y == 1){addy = 3;}
 if(x == 1 && y == 1){addy = 4;}
 if(x == 2 && y == 1){addy = 5;}
 if(x == 0 && y == 2){addy = 6;}
 if(x == 1 && y == 2){addy = 7;}
 if(x == 2 && y == 2){addy = 8;}
 Board.at(addy) = turn;
}

int main(){
    std::string sTurn;
    std::string Move;
 while(winCheckNormal() == 0){
     turn = (turn == 1) ? 2 : 1;
     sTurn = (turn == 1) ? "X" : "O";
     std::cout<<"It is "<<sTurn<<"'s turn\n";
     printBoard();
     std::cout<<"\n\n please input move in (x,y) format: ";
     std::getline(std::cin, Move);
     modifyBoard(Move);
     
     
 }
 printBoard();
 if(winCheckNormal() == 1){
 std::cout<<"\n \n"<<sTurn<<" Won";
 }
 else{
  std::cout<<"\n \nCats Game";  
 }
 return 0;
}
