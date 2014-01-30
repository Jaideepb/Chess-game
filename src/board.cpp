/* 
 * Desc: This file contains all the classes required for chess program.
 */

#include<string>
#include<string.h>
#include<map>
#include "data.h"
#include "Pieces.cpp"

using namespace std;

class Square {
protected:
	Piece *myPiece;
	Position *pos;
	COLOR color;
public:		
	Square(Position ,COLOR );
	~Square();
	Piece* getMyPiece();
	void SetMyPiece(Piece *pie);
	Piece* GetMyPiece(); 

};

class Player;

class Board {
protected:
	Square *sqr[64];
public:
	Board();
	~Board();
	void SetSquares(Player& ply);
	Square* GetSquare(int id);
	void PrintMe();
};

class Player {
protected:
	map<int, Piece*> mPieces;
	COLOR mycolor;	
public:
	Player(COLOR);
	~Player();
	friend void Board::SetSquares(Player& ply); 
};

class Game {
protected:
	Board  *board;
	Player *white;
	Player *black;
public:
	Game();
	void InitiateBoard(Player& ply);
	void PrintBoard();
	int Move(string,string);
	int giveSquareId(string );
	Piece* GetSqrPiece(int);
};

// #Game 

Game::Game()
{
	board = new Board();
	white = new Player(WHITE);
	black = new Player(BLACK);
	InitiateBoard(*white);
	InitiateBoard(*black);
}

void Game::InitiateBoard(Player &ply){
	board->SetSquares(ply);
}

void Game::PrintBoard(){
	board->PrintMe();
}

Piece* Game::GetSqrPiece(int sqrNum){
	return board->GetSquare(sqrNum)->GetMyPiece();
}

int Game::Move(string mvFrom,string mvTo){
	int fid=giveSquareId(mvFrom);
	if(fid==-1)
		return -1;
	Piece *fpie = GetSqrPiece(fid);
	if(fpie!=NULL)
		cout<<"From := "<<fpie->getName()<<endl;
	else
		cout<<"NULL"<<endl;

	int tid=giveSquareId(mvTo);
	if(tid==-1)
		return -1;
	fpie = GetSqrPiece(tid);

	if(fpie!=NULL)
		cout<<"To := "<<fpie->getName()<<endl;
	else
		cout<<"NULL"<<endl;
	return 0;
}

int Game::giveSquareId(string mv){
	if(mv.length()!=2)
		return -1;
	else
	{
		int i=mv[0]-'a';	
		if(i>7)
			return -1;
		int j=mv[1]-'0';
		return j*10+i-1;
	}
}

// #Board

Board::Board()
{
	Position tempPos={0,0};
	COLOR color;
	for(int i=0;i<8;i++)
	{	
		for(int j=0;j<8;j++)
		{
			tempPos = {i,j};
			if( (i+j)%2 == 0)
				color = BLACK;
			else
				color = WHITE;

			sqr[8*i+j] = new Square(tempPos,color);
		}
	}	
}

Board::~Board()
{
	for(int i=0;i<64;i++)
		delete sqr[i];
}

void Board::SetSquares(Player& ply) {
	int j;
	for(int i=0;i<=1;i++)
	{
//		PRINT(" here "<<ply.mycolor);
		if(ply.mycolor==BLACK)	
			j=i;
		else
			j=7-i;	
		for(int pie=R1;pie<=R2;pie++)
		{
//			PRINT(ply.mPieces[i*8+pie]->getName());
			sqr[j*8+(pie%8)]->SetMyPiece(ply.mPieces[i*8+pie]);	
		}	
	}
}

Square* Board::GetSquare(int id){
	return sqr[id];	
}

void Board::PrintMe() {
	char a='a';
	cout<<"\t";
	for(int i=0;i<8;i++)
		cout<<"   "<<a++<<"\t";
	cout<<endl;
	cout<<"\t";
	for(int k=0;k<8;k++)
		cout<<"________";
	cout<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<"\t";
		for(int j=0;j<8;j++)
		{
			cout<<"|";
			Piece *pi = this->sqr[i*8+j]->GetMyPiece();
			if(pi !=NULL)
			{
				cout<<" "<<pi->getName()<<"\t";
			}
			else
				cout<<"\t";
		}
		cout<<"|";
		cout<<endl;
		cout<<i+1<<"\t";
		for(int k=0;k<8;k++)
			cout<<"|\t";
		cout<<"|";
		cout<<endl;
		cout<<"\t";
		for(int k=0;k<8;k++)
			cout<<"________";
	cout<<endl;
	}
}

// #Square

Square::Square(Position loc,COLOR clr){
	this->myPiece=NULL;
	this->pos = new Position{loc.X,loc.Y};
	color = clr;
}

Square::~Square(){
	delete pos;
}

void Square::SetMyPiece(Piece *pie) {
	myPiece = pie;
}

Piece* Square::GetMyPiece() {
	return myPiece;
}

// #Player
 
Player::Player(COLOR clr){
	mycolor=clr;
	mPieces[K]  = new King(clr);
	mPieces[Q]  = new Queen(clr);
	mPieces[R1] = new Rook(clr,"1");
	mPieces[R2] = new Rook(clr,"2");
	mPieces[N1] = new Knight(clr,"1");
	mPieces[N2] = new Knight(clr,"2");
	mPieces[B1] = new Bishop(clr,"1");
	mPieces[B2] = new Bishop(clr,"2");
	for(int i=p1;i<=p8;i++)
		mPieces[i] = new Pawn(clr,i-p1);
}

Player::~Player(){
	for(int i=R1;i<=p8;i++)
		delete mPieces[i];
}
