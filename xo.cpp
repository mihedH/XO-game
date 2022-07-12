#include <iostream>
using namespace std;

class tictactoe 
{
	char mat[3][3];
	char p;
	int playerturn;
	public:
		tictactoe();
		void drawboard();
		void playing();
		int get_playerturn();
		bool win();
		bool end();
		char mark();
		bool casevide(char p);
};

tictactoe::tictactoe()
{
	char c='1';
	for (int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
	      mat[i][j]=c++;
	playerturn=0;
	
}

void tictactoe::drawboard()
{    
    system("cls");
	cout<<"  "<<mat[0][0]<<" "<<"||"<<" "<<mat[0][1]<<" "<<"||"<<" "<<mat[0][2]<<endl;
	cout<<" --------------- "<<endl;
	cout<<"  "<<mat[1][0]<<" "<<"||"<<" "<<mat[1][1]<<" "<<"||"<<" "<<mat[1][2]<<endl;
	cout<<" --------------- "<<endl;
	cout<<"  "<<mat[2][0]<<" "<<"||"<<" "<<mat[2][1]<<" "<<"||"<<" "<<mat[2][2]<<endl;
}

void tictactoe::playing()
{
  	
  	 	cout<<"player "<<playerturn<<" : "<<endl;
  	 	cin>>p;
  	 	 if (casevide(p)) {
  	 	 	switch(p) {
  	 		case '1': mat[0][0]=mark();
  	 		break;
  	 		case '2': mat[0][1]=mark();
  	 		break;
			case '3': mat[0][2]=mark();
			break;
			case '4': mat[1][0]=mark();
			break;
  	 		case '5': mat[1][1]=mark();
  	 		break;
			case '6': mat[1][2]=mark();
			break;
			case '7': mat[2][0]=mark();
			break;
  	 		case '8': mat[2][1]=mark();
  	 		break;
			case '9': mat[2][2]=mark();
			break;	
		              }
		   playerturn=!playerturn;
			}
			else cout<<"case pleine "<<endl;	
}

char tictactoe::mark(){
	if (playerturn==0)
	   return 'X';
	   else return 'O';
}

bool tictactoe::win(){
	if ((mat[0][0]==mat[0][1])&&(mat[0][1]==mat[0][2]))
	  return true ;
    else if ((mat[0][0]==mat[1][0])&&(mat[0][0]==mat[2][0]))
	  return true ;
	else if ((mat[0][0]==mat[1][1])&&(mat[0][0]==mat[2][2]))
	  return true ;
	  else if ((mat[2][0]==mat[2][1])&&(mat[2][0]==mat[2][2]))
	  return true ;
	  else if ((mat[0][2]==mat[1][2])&&(mat[0][2]==mat[2][2]))
	  return true ;
	  else if ((mat[0][2]==mat[1][1])&&(mat[0][2]==mat[2][0]))
	  return true ;
	  else if ((mat[0][1]==mat[1][1])&&(mat[0][1]==mat[2][1]))
	  return true ;
	  else if ((mat[1][0]==mat[1][1])&&(mat[1][0]==mat[1][2]))
	  return true ;
	  else return false;
}

bool tictactoe::casevide(char p){
	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	     if (mat[i][j]==p)
	     return true;
return false;
};

bool tictactoe::end(){
	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	    if ((mat[i][j]!='X')&&(mat[i][j]!='O'))
	    return false;
return true;
	    
	    
}

int main()
{
  tictactoe xo;
  xo.drawboard();
  while ((!xo.win())&&(!xo.end()))
  {
  	xo.playing();
  	xo.drawboard();
  }
  
  return 0;
	
}
