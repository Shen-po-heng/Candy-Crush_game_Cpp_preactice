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

void game();//�C������ 
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
	{  system("cls");//�M���e��
        
		if(site==1)
		{   cout<<setw(4)<<"*"<<setw(2)<<"�}�l�C��"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"�W�h����"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"���}�C��"<<endl;}
		if(site==2)
		{	cout<<setw(4)<<" "<<setw(2)<<"�}�l�C��"<<endl;
			cout<<setw(4)<<"*"<<setw(2)<<"�W�h����"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"���}�C��"<<endl;}
		if(site==3)
		{	cout<<setw(4)<<" "<<setw(2)<<"�}�l�C��"<<endl;
			cout<<setw(4)<<" "<<setw(2)<<"�W�h����"<<endl;
			cout<<setw(4)<<"*"<<setw(2)<<"���}�C��"<<endl;}//�C���}�l�e�� ���W�U��� �M�w*����m
		if(key=getch()==13)//13=Enter��
		{	
		    if(site==1)
		    game();
		
		    if(site==2)//�C���W�h
			{	system("cls");//�M���e��
				cout<<" �o�O�@��10x10�j�p���x�ο}�G�L�A���ʨ���洫���}�G�A��C�䬰���"<<endl<<endl;
				cout<<" �Q������۾F��ӿ}�G�y�ЧY�i�洫�}�G "<<endl<<endl;
				cout<<" ��T�ӿ}�G�۳s�A�}�G�|�����åѤW���U���"<<endl<<endl;
				cout<<" ����3�� �� �� �� �o�����F����3�� �� �� �� �o�Q��"<<endl<<endl;
				cout<<" �C���ʤ@���}�G�B�ƴ�֤@���A���ʨ�0���C���Y����"<<endl<<endl;
				cout<<" �п�JENTER�H��^�e��"<<endl<<endl;
				while(getch()!=13);//��Jenter��^
			}
			if(site==3)//���}�C��
			exit(0);
		 }
		else
		{ switch(key=getch())
			{
				case 'w': // Up��
				case 'W':
					site--;
					break;
				case 'S':
				case 's': // Down��
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


void game()//�C������ 
{
	
	char array2[10]={'A','B','C','D','E','F','G','H','I','J'};

	int O;
	int X=0,Y=0;
	srand( time(0) );
	
	cout<<"   ";
	for(int w = 0;w < 10; w++ )  //�^��r�� 
	{   setColor(3);
		cout << setw(2) << array2[w];  
	}
	
	cout << endl;
	
	for(int i = 0; i < 10; i++)

	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0;j < 10; j++) //�]�w�}�C���ܼ� 
		{    
			array[i][j] = rand() % 4;
		}
	}
	//�_�l�ϥ� 
		
		O=array[X][Y];
		//���s���w(���F�ϥ�) 
		if(array[X][Y]==0)
		array[X][Y]=4;
		
		else if(array[X][Y]==1)
		array[X][Y]=5;
		
		else if(array[X][Y]==2)
		array[X][Y]=6;
		
		else if(array[X][Y]==3)
		array[X][Y]=7;
			

	///////////////////////////
	
	for(int k = 0;k < 10 ;k++) //�}�G�C 
	{
		setColor(3);
		cout<<setw(2)<<k+1<<" ";
		 
		for(int q = 0;q < 10 ;q++) //�C��column 
		{
	    	if( array[k][q] == 0)
	    	{
	    		setColor(2);
	    		cout << setw(2) << "��";
			}
			else if(array[k][q] == 1)
			{
				setColor(4);
				cout << setw(2) << "��";
			}
			else if(array[k][q] == 2)
			{
				setColor(6);
				cout << setw(2) << "��";
			}
			else if(array[k][q] == 3)
			{
				setColor(8);
				cout << setw(2) << "��";
			}
			else if(array[k][q] >=4)
			{ 
			    setColor(1,7);
	          
			       if(array[k][q]==4)
		              cout << "��";		
		
		           else if(array[k][q]==5)
	                  cout << "��";
		
		           else if(array[k][q]==6)
		              cout << "��";
		
		           else if(array[k][q]==7)
		              cout  << "��";
			}
		
		}
		
		cout << endl;
	}
array[X][Y]=O;
/////////////////////���j�u///////////////////////////////////////////////////////////////////////////////////////////
int counter=15;//�p�� 




for(int U=0;U<30;U++)
Erase();

candy(); 
cout<<endl;

setColor(7);
cout << "����3�� �� �� �� �o����" << endl << "����3�� �� �� �� �o�Q��" << endl << endl; 
cout<<"�Ѿl�B�ơG"<< counter <<setw(10)<<"����:"<< score << endl<<endl;

while(counter > 0)
{
//�洫
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
		//���s���w(���F�ϥ�) 
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
cout << "����3�� �� �� �� �o����" << endl << "����3�� �� �� �� �o�Q��" << endl << endl; 
cout<<"�Ѿl�B�ơG"<< counter <<setw(10)<<"����:"<< score << endl<<endl;
	
	if(mid==0)
		array[X][Y]=O;
	else
	  mid=0;	 
		
	}
	
 X=0,Y=0;

 X1=0,Y1=0;

 X2=0,Y2=0;

 C1=-1,C2=-1;


//////////////////////////////////////////////////////////////////////////////////// �T�O���̸g���� 
for(int U=0;U<30;U++)
Erase(); 
candy();
//////////////////////���j�u///////////////////

	
///////////////////////////////////////////////////////////////////////////////////////////		
counter--;

cout<<endl;

setColor(7);
cout << "����3�� �� �� �� �o����" << endl << "����3�� �� �� �� �o�Q��" << endl << endl; 
cout<<"�Ѿl�B�ơG"<< counter <<setw(10)<<"����:"<< score << endl<<endl;


}
///////////���j�u///////////// 
system("cls");

char Ans;

setColor(7);
cout<<endl;
cout<<"�`�o���F"<<score; 
cout<<"�n�A���@���ܡH(Y or N)";
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

void candy()//�Lcandy
{  
   
	cout<<"   ";
	for(int w = 0;w < 10; w++ )  //�^��r�� 
	{   setColor(3);
		cout << setw(2) << array2[w];  
	}
	
	cout << endl;
	for(int k = 0;k < 10 ;k++) //�}�G�C 
	{
		setColor(3);
		cout<<setw(2)<<k+1<<" ";
		 
		for(int q = 0;q < 10 ;q++) //�C��column 
		{
	    	if( array[k][q] == 0)
	    	{
	    		setColor(2);
	    		cout << setw(2) << "��";
			}
			else if(array[k][q] == 1)
			{
				setColor(4);
				cout << setw(2) << "��";
			}
			else if(array[k][q] == 2)
			{
				setColor(6);
				cout << setw(2) << "��";
			}
			else if(array[k][q] == 3)
			{
				setColor(8);
				cout << setw(2) << "��";
			}
			else if(array[k][q] >=4)
			{ 
			    setColor(1,7);
	          
			       if(array[k][q]==4)
		              cout << "��";		
		
		           else if(array[k][q]==5)
	                  cout << "��";
		
		           else if(array[k][q]==6)
		              cout << "��";
		
		           else if(array[k][q]==7)
		              cout  << "��";
			}
		
		}
		
		cout << endl;
	}	
		
}

void Erase()//���}�G 
{
	for(int l=0;l<10;l++)//���}�G (�) 
{
	for(int m=1;m<10;m++)
	{
		if(array[l][m-1]==array[l][m] && array[l][m]==array[l][m+1])
	    {  
	       switch(array[l][m])//�����}�G�o�� 
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
 
 for(int n=0;n<10;n++)//���}�G (����) 
{
	for(int o=1;o<10;o++)
	{
		if(array[o-1][n]==array[o][n] && array[o][n]==array[o+1][n])
	    {
	         switch(array[o][n])//�����}�G�o��
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
			 
			      if(J>=5)//���T�ɤT
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
			    
			      else if(J==4) //���T�ɤG 
	                  {
	                  	
		                array[J-1][n]=array[J-4][n]; //3-0
		                array[J][n]=array[J-3][n]; //4-1
	                  	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  }
				 else if(J==3) //���T�ɤ@ 
	                  {
	                  	
		                array[J][n]=array[J-3][n]; //3-0 
	                  	
	                  	array[0][n]=rand() % 4;
			            array[1][n]=rand() % 4;
			            array[2][n]=rand() % 4;
					  } 
				else if(J==2) //���T�ɹs 
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

