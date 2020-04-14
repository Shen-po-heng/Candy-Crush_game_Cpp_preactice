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

void game();//遊戲執行 
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
	{  system("cls");//清除畫面
        
		if(site==1)
		{   cout<<setw(4)<<"*"<<setw(2)<<"開始遊戲"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"規則說明"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"離開遊戲"<<endl;}
		if(site==2)
		{	cout<<setw(4)<<" "<<setw(2)<<"開始遊戲"<<endl;
			cout<<setw(4)<<"*"<<setw(2)<<"規則說明"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"離開遊戲"<<endl;}
		if(site==3)
		{	cout<<setw(4)<<" "<<setw(2)<<"開始遊戲"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"規則說明"<<endl;
			cout<<setw(4)<<"*"<<setw(2)<<"離開遊戲"<<endl;}//遊戲開始畫面 按上下鍵時 決定*的位置
		if(key=getch()==13)//13=Enter鍵
		{	
		    if(site==1)
		    game();
		
		    if(site==2)//遊戲規則
			{	system("cls");//清除畫面
				cout<<" 這是一個10x10大小的矩形糖果盤，移動到欲交換的糖果，按C鍵為選取"<<endl<<endl;
				cout<<" 被選取的相鄰兩個糖果座標即可交換糖果 "<<endl<<endl;
				cout<<" 當三個糖果相連，糖果會消除並由上往下填補"<<endl<<endl;
				cout<<" 消除3個 □ 或 ☆ 得五分；消除3個 ○ 或 ◇ 得十分"<<endl<<endl;
				cout<<" 每移動一次糖果步數減少一次，當移動到0次遊戲即結束"<<endl<<endl;
				cout<<" 請輸入ENTER以返回前頁"<<endl<<endl;
				while(getch()!=13);//輸入enter返回
			}
			if(site==3)//離開遊戲
			exit(0);
		 }
		else
		{ switch(key=getch())
			{
				case 'w': // Up鍵
				case 'W':
					site--;
					break;
				case 'S':
				case 's': // Down鍵
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


void game()//遊戲執行 
{
	
	char array2[10]={'A','B','C','D','E','F','G','H','I','J'};

	int O;
	int X=0,Y=0;
	srand( time(0) );
	
	cout<<"   ";
	for(int w = 0;w < 10; w++ )  //英文字母 
	{   setColor(3);
		cout << setw(2) << array2[w];  
	}
	
	cout << endl;
	
	for(int i = 0; i < 10; i++)

	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0;j < 10; j++) //設定陣列的變數 
		{    
			array[i][j] = rand() % 4;
		}
	}
	//起始反白 
		
		O=array[X][Y];
		//重新指定(為了反白) 
		if(array[X][Y]==0)
		array[X][Y]=4;
		
		else if(array[X][Y]==1)
		array[X][Y]=5;
		
		else if(array[X][Y]==2)
		array[X][Y]=6;
		
		else if(array[X][Y]==3)
		array[X][Y]=7;
			

	///////////////////////////
	
	for(int k = 0;k < 10 ;k++) //糖果列 
	{
		setColor(3);
		cout<<setw(2)<<k+1<<" ";
		 
		for(int q = 0;q < 10 ;q++) //列的column 
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
/////////////////////分隔線///////////////////////////////////////////////////////////////////////////////////////////
int counter=15;//計數 




for(int U=0;U<30;U++)
Erase();

candy(); 
cout<<endl;

setColor(7);
cout << "消除3個 □ 或 ☆ 得五分" << endl << "消除3個 ○ 或 ◇ 得十分" << endl << endl; 
cout<<"剩餘步數："<< counter <<setw(10)<<"分數:"<< score << endl<<endl;

while(counter > 0)
{
//交換
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
		//重新指定(為了反白) 
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
cout << "消除3個 □ 或 ☆ 得五分" << endl << "消除3個 ○ 或 ◇ 得十分" << endl << endl; 
cout<<"剩餘步數："<< counter <<setw(10)<<"分數:"<< score << endl<<endl;
	
	if(mid==0)
		array[X][Y]=O;
	else
	  mid=0;	 
		
	}
	
 X=0,Y=0;

 X1=0,Y1=0;

 X2=0,Y2=0;

 C1=-1,C2=-1;


//////////////////////////////////////////////////////////////////////////////////// 確保都依經消完 
for(int U=0;U<30;U++)
Erase(); 
candy();
//////////////////////分隔線///////////////////

	
///////////////////////////////////////////////////////////////////////////////////////////		
counter--;

cout<<endl;

setColor(7);
cout << "消除3個 □ 或 ☆ 得五分" << endl << "消除3個 ○ 或 ◇ 得十分" << endl << endl; 
cout<<"剩餘步數："<< counter <<setw(10)<<"分數:"<< score << endl<<endl;


}
///////////分隔線///////////// 
system("cls");

char Ans;

setColor(7);
cout<<endl;
cout<<"總得分；"<<score; 
cout<<"要再玩一次嗎？(Y or N)";
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

void candy()//印candy
{  
   
	cout<<"   ";
	for(int w = 0;w < 10; w++ )  //英文字母 
	{   setColor(3);
		cout << setw(2) << array2[w];  
	}
	
	cout << endl;
	for(int k = 0;k < 10 ;k++) //糖果列 
	{
		setColor(3);
		cout<<setw(2)<<k+1<<" ";
		 
		for(int q = 0;q < 10 ;q++) //列的column 
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

void Erase()//消糖果 
{
	for(int l=0;l<10;l++)//消糖果 (橫的) 
{
	for(int m=1;m<10;m++)
	{
		if(array[l][m-1]==array[l][m] && array[l][m]==array[l][m+1])
	    {  
	       switch(array[l][m])//消除糖果得分 
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
 
 for(int n=0;n<10;n++)//消糖果 (直的) 
{
	for(int o=1;o<10;o++)
	{
		if(array[o-1][n]==array[o][n] && array[o][n]==array[o+1][n])
	    {
	         switch(array[o][n])//消除糖果得分
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
			 
			      if(J>=5)//消三補三
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
			    
			      else if(J==4) //消三補二 
	                  {
	                  	
		                array[J-1][n]=array[J-4][n]; //3-0
		                array[J][n]=array[J-3][n]; //4-1
	                  	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  }
				 else if(J==3) //消三補一 
	                  {
	                  	
		                array[J][n]=array[J-3][n]; //3-0 
	                  	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  } 
				else if(J==2) //消三補零 
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

