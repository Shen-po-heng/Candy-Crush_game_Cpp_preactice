#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include <stdio.h> 
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include"utility.h" 
using namespace std;

HANDLE hConsole;

void game();//game execution 
void candy();
void Erase();


int array[10][10];
char array2[10]={'A','B','C','D','E','F','G','H','I','J'};
int X=0,Y=0;

int X1=0,Y1=0;

int X2=0,Y2=0;

int C1=-1,C2=-1;
int mid=0;
int K;
int score = 0;	
int main()
{

    char key , site=1;

	while(1)
	{  system("cls");//clean screen
        
		if(site==1)
		{   cout<<setw(4)<<"*"<<setw(2)<<"start game"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"Rule"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"Exit"<<endl;}
		if(site==2)
		{   cout<<setw(4)<<""<<setw(2)<<"start game"<<endl;
			cout<<setw(4)<<"*"<<setw(2)<<"Rule"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"Exit"<<endl;}
		if(site==3)
		{   cout<<setw(4)<<""<<setw(2)<<"start game"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"Rule"<<endl;
			cout<<setw(4)<<"*"<<setw(2)<<"Exit"<<endl;}//use up and down to decide the position *
		if(key=getch()==13)//13=Enter鍵
		{	
		    if(site==1)
		    game();
		
		    if(site==2)//Rule
			{	system("cls");//Clean
				cout<<" This is a 10x10 rectangular candy tray. Move to the candy you want to exchange and press C to select"<<endl<<endl;
				cout<<" Two adjacent candy coordinates can be selected to exchange candy "<<endl<<endl;
				cout<<" When three candies are connected, the candies will be eliminated and filled from top to bottom"<<endl<<endl;
				cout<<" Eliminate 3 □ or ☆ to get 5 points; eliminate 3 ○ or ◇ to get 10"<<endl<<endl;
				cout<<" Each time you move the candy steps, the number of steps will decrease once, and the game will end when you move to 0 times"<<endl<<endl;
				cout<<" Please enter ENTER to return to the previous page"<<endl<<endl;
				while(getch()!=13);//input Enter to go back
			}
			if(site==3)//leave game
			exit(0);
		 }
		else
		{ switch(key=getch())
			{
				case 'w': // Up
				case 'W':
					site--;
					break;
				case 'S':
				case 's': // Down
					site++;
					break;}
			if(site>3)
			site=3;
			if(site<1)
			site=1;}
	  }
      return 0;   
	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//system("color F");
	
    
}


void game()//Game execution
{
	
	char array2[10]={'A','B','C','D','E','F','G','H','I','J'};

	int O;
	int X=0,Y=0;
	srand( time(0) );
	
	cout<<"   ";
	for(int w = 0;w < 10; w++ )  
	{   setColor(3);
		cout << setw(2) << array2[w];  
	}
	
	cout << endl;
	
	for(int i = 0; i < 10; i++)

	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0;j < 10; j++) 
		{    
			array[i][j] = rand() % 4;
		}
	}
	
		
		O=array[X][Y];
	
		if(array[X][Y]==0)
		array[X][Y]=4;
		
		else if(array[X][Y]==1)
		array[X][Y]=5;
		
		else if(array[X][Y]==2)
		array[X][Y]=6;
		
		else if(array[X][Y]==3)
		array[X][Y]=7;
			

	///////////////////////////
	
	for(int k = 0;k < 10 ;k++) //Candy row
	{
		setColor(3);
		cout<<setw(2)<<k+1<<" ";
		 
		for(int q = 0;q < 10 ;q++) //column 
		{
	    	if( array[k][q] == 0)
	    	{
	    		setColor(2);
	    		cout << setw(2) << "□";
			}
			else if(array[k][q] == 1)
			{
				setColor(4);
				cout << setw(2) << "○";
			}
			else if(array[k][q] == 2)
			{
				setColor(6);
				cout << setw(2) << "☆";
			}
			else if(array[k][q] == 3)
			{
				setColor(8);
				cout << setw(2) << "◇";
			}
			else if(array[k][q] >=4)
			{ 
			    setColor(1,7);
	          
			       if(array[k][q]==4)
		              cout << "□";		
		
		           else if(array[k][q]==5)
	                  cout << "○";
		
		           else if(array[k][q]==6)
		              cout << "☆";
		
		           else if(array[k][q]==7)
		              cout  << "◇";
			}
		
		}
		
		cout << endl;
	}
array[X][Y]=O;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int counter=15;// 




for(int U=0;U<30;U++)
Erase();

candy(); 
cout<<endl;

setColor(7);
cout << "Clear 3 □ or ☆ 5 points" << endl << "Eliminate 3 ○ or ◇ to get 10 points" << endl << endl; 
cout<<"Remaining steps:"<< counter <<setw(10)<<"Score:"<< score << endl<<endl;

while(counter > 0)
{
//swap
	while(C1==-1 || C2==-1)
	{
		char presskey=getch(); 
		
		
		switch(presskey)
		{
			case'W':
			case'w':
				X-=1;
				break;
			case'S':
			case's':
				X+=1;
				break;
			case'A':
			case'a':
				Y-=1;
				break;
			case'D':
			case'd':
				Y+=1;
				break;
			case'c':
			case'C':			
				if(C1==-1)
				{
				C1=array[X][Y];
				X1=X;
				Y1=Y;
			    }
				else
				{
				C2=array[X][Y];
				X2=X;
				Y2=Y;				
			    }
				break; 
		}
		
		system("cls");
		
		O=array[X][Y];
		
		if(array[X][Y]==0)
		array[X][Y]=4;
		
		else if(array[X][Y]==1)
		array[X][Y]=5;
		
		else if(array[X][Y]==2)
		array[X][Y]=6;
		
		else if(array[X][Y]==3)
		array[X][Y]=7;
	
	if(C1!=-1&&C2!=-1)
	    {
	    mid=C1;	
	    array[X1][Y1]=C2;
	    array[X2][Y2]=mid;
		
		}
	
	
		candy();

cout<<endl;

setColor(7);
cout << "Clear 3 □ or ☆ 5 points" << endl << "Eliminate 3 ○ or ◇ to get 10 points" << endl << endl; 
cout<<"Remaining steps:"<< counter <<setw(10)<<"Score:"<< score << endl<<endl;
	
	if(mid==0)
		array[X][Y]=O;
	else
	  mid=0;	 
		
	}
	
 X=0,Y=0;

 X1=0,Y1=0;

 X2=0,Y2=0;

 C1=-1,C2=-1;


//////////////////////////////////////////////////////////////////////////////////// 
for(int U=0;U<30;U++)
Erase(); 
candy();
//////////////////////分隔線///////////////////

	
///////////////////////////////////////////////////////////////////////////////////////////		
counter--;

cout<<endl;

setColor(7);
cout << "Clear 3 □ or ☆ 5 points" << endl << "Eliminate 3 ○ or ◇ to get 10 points" << endl << endl; 
cout<<"Remaining steps:"<< counter <<setw(10)<<"Score:"<< score << endl<<endl;


}
///////////分隔線///////////// 
system("cls");

char Ans;

setColor(7);
cout<<endl;
cout<<"Total Score"<<score; 
cout<<"Play it again?(y or n)";
cout<<endl;
cin>>Ans;
switch(Ans)
{
	case 'Y':
	case 'y':
	  system("cls");
	  score=0;
	   game();
	
	case 'N':
	case 'n':
	  break;
}
}

void candy()//print game
{  
   
	cout<<"   ";
	for(int w = 0;w < 10; w++ )  
	{   setColor(3);
		cout << setw(2) << array2[w];  
	}
	
	cout << endl;
	for(int k = 0;k < 10 ;k++) 
	{
		setColor(3);
		cout<<setw(2)<<k+1<<" ";
		 
		for(int q = 0;q < 10 ;q++) 
		{
	    	if( array[k][q] == 0)
	    	{
	    		setColor(2);
	    		cout << setw(2) << "□";
			}
			else if(array[k][q] == 1)
			{
				setColor(4);
				cout << setw(2) << "○";
			}
			else if(array[k][q] == 2)
			{
				setColor(6);
				cout << setw(2) << "☆";
			}
			else if(array[k][q] == 3)
			{
				setColor(8);
				cout << setw(2) << "◇";
			}
			else if(array[k][q] >=4)
			{ 
			    setColor(1,7);
	          
			       if(array[k][q]==4)
		              cout << "□";		
		
		           else if(array[k][q]==5)
	                  cout << "○";
		
		           else if(array[k][q]==6)
		              cout << "☆";
		
		           else if(array[k][q]==7)
		              cout  << "◇";
			}
		
		}
		
		cout << endl;
	}	
		
}

void Erase()//Erase Candy 
{
	for(int l=0;l<10;l++)
{
	for(int m=1;m<10;m++)
	{
		if(array[l][m-1]==array[l][m] && array[l][m]==array[l][m+1])
	    {  
	       switch(array[l][m])
			{
				case 0:
					score += 5;
					break;
				case 1:
					score +=10;
					break;
				case 2:
					score += 5;
					break;
				case 3: 
				    score += 10;
				    break;
				default:
					break;
			 }	
	    K=l;
	             while(K>0)
		            {
		
		                 array[K][m-1]=array[K-1][m-1];
		                 array[K][m]=array[K-1][m];
		                 array[K][m+1]=array[K-1][m+1];
		            K--;
	                }   
			array[0][m-1]=rand() % 4;
			array[0][m]=rand() % 4;
			array[0][m+1]=rand() % 4;	
			
			
	    }
    }
    
	
 } 
 int J=0;
 
 for(int n=0;n<10;n++)
{
	for(int o=1;o<10;o++)
	{
		if(array[o-1][n]==array[o][n] && array[o][n]==array[o+1][n])
	    {
	         switch(array[o][n])
			{
				case 0:
					score += 5;
					break;
				case 1:
					score +=10;
					break;
				case 2:
					score += 5;
					break;
				case 3: 
				    score += 10;
				    break;
				default:
					break;
			 }	     
			 
			 J=o+1;
			 
			      if(J>=5)
			         {
			  
				        while(J>4 && J<10) 
		                   {
				
		                    array[J-2][n]=array[J-5][n];
		                    array[J-1][n]=array[J-4][n];
		                    array[J][n]=array[J-3][n];
	                          J--;
			               }
		                array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
			        }
			    
			      else if(J==4) 
	                  {
	                  	
		                array[J-1][n]=array[J-4][n]; //3-0
		                array[J][n]=array[J-3][n]; //4-1
	                  	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  }
				 else if(J==3) 
	                  {
	                  	
		                array[J][n]=array[J-3][n]; //3-0 
	                  	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  } 
				else if(J==2)
	                  {
	                  	
		                             	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  } 
					  
		    
	    }
    }
    
	
 } 

system("cls");
}

