##include <iostream>
#include <sstream>
using namespace std;

void table (char xo[9]) {
  
  cout << "    1    2    3 \n" 
       << "   +---+---+---+ \n "
       << "a | " << xo[0] << " | " << xo[1] << " | " << xo[2] << " |\n"
       << "   +---+---+---+\n "
       << "b | " << xo[3] << " | " << xo[4] << " | " << xo[5] << " |\n"
       << "   +---+---+---+\n "
       << "c | " << xo[6] << " | " << xo[7] << " | " << xo[8] << " |\n"
       << "   +---+---+---+\n ";
       
}

bool wwin( char xo[9], char & winner, bool &f){
  
  if (((xo[0]==xo[1]) && (xo[1]==xo[2]) && (xo[0]== 'x')) ||
     ((xo[3]==xo[4]) && (xo[4]==xo[5]) && (xo[3]== 'x')) ||
     ((xo[6]==xo[7]) && (xo[7]==xo[8]) && (xo[8]== 'x')) ||
     ((xo[0]==xo[3]) && (xo[3]==xo[6]) && (xo[6]== 'x')) ||
     ((xo[1]==xo[4]) && (xo[4]==xo[7]) && (xo[7]== 'x')) ||
     ((xo[2]==xo[5]) && (xo[5]==xo[8]) && (xo[8]== 'x')) ||
     ((xo[0]==xo[4]) && (xo[4]==xo[8]) && (xo[0]== 'x')) ||
     ((xo[2]==xo[4]) && (xo[4]==xo[6]) && (xo[6]== 'x'))) {
     f = true;
     winner = 'x';
     } else 
     
     if (((xo[0]==xo[1]) && (xo[1]==xo[2]) && (xo[0]== '0')) ||
     ((xo[3]==xo[4]) && (xo[4]==xo[5]) && (xo[3]== '0')) ||
     ((xo[6]==xo[7]) && (xo[7]==xo[8]) && (xo[8]== '0')) ||
     ((xo[0]==xo[3]) && (xo[3]==xo[6]) && (xo[6]== '0')) ||
     ((xo[1]==xo[4]) && (xo[4]==xo[7]) && (xo[7]== '0')) ||
     ((xo[2]==xo[5]) && (xo[5]==xo[8]) && (xo[8]== '0')) ||
     ((xo[0]==xo[4]) && (xo[4]==xo[8]) && (xo[0]== '0')) ||
     ((xo[2]==xo[4]) && (xo[4]==xo[6]) && (xo[6]== '0'))) {
     f = true;
     winner = '0';
     } 
     return f;
     
}
bool draw (char xo[9], bool &drw)
{ 
  int n=0;
  for (int i=0 ; i<9; i++){
     if (xo[i] != ' ') n++;
  }
  if (n==9) drw = true; 
  return drw;
}



int main ()
{
  char xo[9],winner; bool hw= false, drw = false;
  
  string name[9],nam[9];
  name[0]= "a1"; name[1]= "a2"; name[2]= "a3";
  name[3]= "b1"; name[4]= "b2"; name[5]= "b3";
  name[6]= "c1"; name[7]= "c2"; name[8]= "c3";
  
  for (int i =0 ; i<9; i++)
   {
     xo[i]=' ';
     nam[i]= "";
     
   }
    table(xo);
  int k =1;
  do { 
    
    int  t = 1 , j = 0;
       for (int i=0 ; i<9; i++){
    
    if (xo[i]== ' ') {
      j++;
      cout << j << ".mark cell";
      t = i/3;
      switch (t){
      case 0: cout << " a";break;
      case 1: cout << " b";break;
      case 2: cout << " c";break;
    }
    t = i%3;
     switch (t){
      case 0: cout << "1 " << "as ";break;
      case 1: cout << "2 " << "as ";break;
      case 2: cout << "3 " << "as ";break;
    } 
    
    if (k== 1) cout << "x\n";
     else cout << "0\n";
    }
  }
  cout << j+1<< ".quit\n";
  j =0;
  int number;
  cin >> number;
  
  for (int i =0; i < 9 ; i++)
    {
      if (xo[i]==' ') {
      j++;
      if (number == j && k == 1) {xo[i]='x';k--;break;}
       else if (number == j && k == 0) {xo[i]='0';k++;break;}
        
      }}
      table(xo);
      hw = wwin( xo,winner,hw);
       if (hw) {
         cout << winner << " won"; }
         
         drw = draw(xo,drw);
         if (drw){ cout << "drawn";
       }}
    
   while (!hw);
    
    
   return 0;
}
