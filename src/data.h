using namespace std;

#define NameCat(X) (string((color==BLACK)?"b_":"w_") + X) 
#define PRINT(X) cout<<X<<" "<<__FUNCTION__<<":"<<__LINE__<<endl

enum COLOR {
	BLACK =0,
	WHITE
};

enum Status {
	DEAD  =0,
	ALIVE 
};

enum ChessPieces {
	R1=0,N1,B1,Q,K,B2,N2,R2,
	p1,p2,p3,p4,p5,p6,p7,p8
};

typedef struct Position
{
	int X;
	int Y;
} Position;

