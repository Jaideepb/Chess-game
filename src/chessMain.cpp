#include<iostream>
#include "board.cpp"

using namespace std;

int main() {
	string fmove,tmove;
	int result;
	Game *G1=new Game();
	G1->PrintBoard();	
	cin>>fmove>>tmove;
	result = G1->Move(fmove,tmove); 
	if(result==0)
		cout<<"Move succesfull"<<endl;
	else
		cout<<"Move Unsucessfull"<<endl;
	G1->PrintBoard();	
	return 0;
}
