#include<string>

using namespace std;

class Piece {
protected:
	string name;	// Name of Piece 
	int status; 	// Alive or Dead
	COLOR color;
//	Square *whichSqr;
public:
	Piece(){
		status=ALIVE;
	}	

	~Piece(){

	}
	string getName() {
		string beg_b="\033[2;83m";
		string beg_w="\033[1;3m";
		string end="\033[0m";

		string m=getname();
		if(color==WHITE)
			return beg_w+m+end;
		else
			return beg_b+m+end;
	}
	COLOR getColor(){
		return color;
	}
	virtual string getname() {};
};

class Pawn:public Piece {
public:
	Pawn(COLOR clr,int id){
		
		color = clr;
		name = NameCat("p_") + to_string(id);	
	}
	string getname(){
		return name;
	}
};

class Rook:public Piece {
public:
	Rook(COLOR clr,string id){
		color = clr;
		name  = NameCat("R_") + id;
	}
	string getname(){
		return name;
	}
};

class Knight:public Piece {
public:
	Knight(COLOR clr,string id){
		color = clr;
		name = NameCat("K_") + id;
	}
	string getname(){
		return name;
	}
};

class Bishop:public Piece {
public:
	Bishop(COLOR clr,string id){
		color = clr;
		name = NameCat("B_") + id;
	}
	string getname(){
		return name;
	}
};

class Queen:public Piece {
public:
	Queen(COLOR clr){
		color = clr;
		name = NameCat("Q");
	}
	string getname(){
		return name;
	}
};

class King:public Piece {
public:
	King(COLOR clr){
		color=clr;
		name = NameCat("K");
	}
	string getname(){
		return name;
	}
};


