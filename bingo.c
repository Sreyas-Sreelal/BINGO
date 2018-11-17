#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//ROw yum colavum
#define ROW 5
#define COLUMN 5
char bingoName[5]={'B','I','N','G','O'},bingoName_Com[5]={'B','I','N','G','O'};
int bingoCard[ROW][COLUMN],bingoCard_Com[ROW][COLUMN],called[25];
int g=0;


//ROBIN
void display_card_player()
{
	int i=0,j;
	printf("\n");
	while(i<5)
	{
		printf("%c\t",bingoName[i]);
		i++;
	}
	printf("\n");
	for(i=0;i<ROW;++i,printf("\n"))
		for(j=0;j<COLUMN;++j)
			printf("%d \t",bingoCard[i][j]);
}
void display_card_Com()
{
	int i=0,j;
	printf("\nCOM CARD\n");
	while(i<5)
	{
		printf("%c\t",bingoName_Com[i]);
		i++;
	}
	printf("\n");
	for(i=0;i<ROW;++i,printf("\n"))
		for(j=0;j<COLUMN;++j)
			printf("%d \t",bingoCard_Com[i][j]);
}

//Creates bingo card to the passed array (remember arrays are always passed by reference so changes in Card array in this function affects in bingoCard array in main)
void CreateBingoCard(int Card[ROW][COLUMN])
{
	int i,j,k,randomIndex;
	//An array consisting of numbers 1 to 25
	//Idhu eduth nammal angotum ingotum itt shufflum

	static int RandomNumbers[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	for(i=0;i<25;++i){
		//rand()%25 0 thott 24 vare numbers inte rangil random number ondakum
		randomIndex = rand()%25;
		//Ini ondakiya random numberine index aaki upayogich random positionsile elements swap cheyum
		RandomNumbers[i] = RandomNumbers[i] + RandomNumbers[randomIndex] - (RandomNumbers[randomIndex] = RandomNumbers[i]);
	}//loop kazhinj randomnumber oru mathri angotum ingortuum eduth erinja avasthayavum adhayath shuffle aayinn

	k = -1;
	//shuffle aaya array ile oru elementum orderil eduth cardil idunnu
	for(i=0;i<ROW;++i)
		for(j=0;j<COLUMN;++j)
			Card[i][j] = RandomNumbers[++k];

}
int bingoName_pos=0;
void check_player()
{
	int count=0,s,r;
	for(s=0;s<5;s++)
		for(r=0;r<5;r++)
			if(bingoCard[s][r]==0)
			{
				count++;
				if(count==5)
				{
					bingoName[bingoName_pos]='*';
					bingoName_pos++;
					if(bingoName_pos==4)
						printf("\nU WON!!!!!!!\n");
				}
			}
	for(r=0;r<5;r++)
		for(s=0;s<5;s++)
			if(bingoCard[s][r]==0)
			{
				count++;
				if(count==5)
				{
					bingoName[bingoName_pos]='*';
					bingoName_pos++;
					if(bingoName_pos==4)
						printf("\nU WON!!!!!!!\n");
				}
			}
}

int bingoName_Com_pos=0;
void check_Com()
{
	int count_Com=0,s,r,j;
	for(s=0;s<5;s++)
		for(j=0;j<5;j++)
			if(bingoCard_Com[s][r]==0)
			{
				count_Com++;
				if(count_Com==5)
				{
					bingoName_Com[bingoName_Com_pos]='*';
					bingoName_Com_pos++;
					if(bingoName_Com_pos==4)
						printf("\nU WON!!!!!!!\n");
				}
			}
	for(r=0;r<5;r++)
		for(s=0;s<5;s++)
			if(bingoCard_Com[s][r]==0)
			{
				count_Com++;
				if(count_Com==5)
				{
					bingoName_Com[bingoName_Com_pos]='*';
					bingoName_Com_pos++;
					if(bingoName_Com_pos==4)
						printf("\nU WON!!!!!!!\n");
				}
			}
}
void call_Com()
{
	int call,z,i,j;
	static int RandomNumbers[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	call=rand()%25;
	z=RandomNumbers[call];
	for(int h=0;h<25;h++)
		if(called[h]==z)
			call_Com();
		else
		{
			called[g]=z;
			g++;
		}
	printf("\n%d\n",z);
	while(z==0)
		call_Com();
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(bingoCard_Com[i][j]==z)
				bingoCard_Com[i][j]=0;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(bingoCard[i][j]==z)
				bingoCard[i][j]=0;
display_card_player();
display_card_Com();
}

void call_player()
{
	int call,i,j,flag=1;
	printf("Call a Number b/w 1 and 25:");
	scanf("%d",&call);
	for(int h=0;h<25;h++)
		if(called[h]==call)
			call_player();
		else
		{
			called[g]=call;
			g++;
		}
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(bingoCard[i][j]==call)
			{
				bingoCard[i][j]=0;
				flag=0;
			}
	if(flag!=0)
		printf("Invalid Entry");
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(bingoCard_Com[i][j]==call)
				bingoCard_Com[i][j]=0;
	display_card_player();
	display_card_Com();
}
void main()
{
	//oro random number sequenceinum oru starting point ond adhu default aayi 1 aanu
	//pakshe eppazhum 1 aanel ore sequence randome ondavvu for example
	//adhyam program run cheyumbol 3 4 5 6 enna pattern adhyam rand() function call cheythapol ondayengil adutha thavan program
	//run cheyumbol adhyam kittunna sequence um 3 4 5 6 arikkum
	//Nammal srand upayogich ee starting point mattum adhu uniqum avande adhinu eppalum unique ayikondirikunna time vech thanne starting point aakum
	//time() function ente value oro millli second um marikondirikum adhu unique um arikum (unix operating system ondayappol mothal kedan adikunna clock allel increment cheyunna varaible polle enn chindhikku)
	srand ( time(NULL) );
	CreateBingoCard(bingoCard);
	display_card_player();
	CreateBingoCard(bingoCard_Com);
	display_card_Com();
	do
	{
		call_player();
		check_player();
		call_Com();
	}while(bingoName_pos!=4 || bingoName_Com_pos!=4);

}
