#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45

using namespace std;
//		cout<<"?????????";

//class afaq{
//    public:
//    int data;
//    afaq *next;
//    afaq *prev;
//    afaq(int d){
//        data=d;
//        next=NULL;
//        prev=NULL;
//    }
//};
//void insert(afaq *&head,afaq *&tail,int d){
//    if(head==NULL){
//        head=tail=new afaq(d);
//    }
//    else{
//        afaq *n=new afaq(d);
//        tail->next=n;
//        n->prev=tail;
//        tail=n;
//    }
//}
//void print(afaq *head){
//    while(head!=NULL){
//        cout<<head->data<<" ";
//        head=head->next;
//    }
//    cout<<endl;
//}
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int pipePos[3];
int gapPos[3];
int pipeFlag[3];
int *pipePosPtr = pipePos;
int *gapPosPtr = gapPos;
int *pipeFlagPtr = pipeFlag;

char bird[2][6] = { '/','-','-','o','\\',' ',
					'|','_','_','_',' ','>' };
int birdPos = 6;
int score = 0;

class afaq{
    public:
    string data;
    afaq *next;
    afaq *prev;
    afaq(string d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};


void menu(){
	cout<<"\n\n\n\n\n\t\t\t\t\t--------------------------"<<endl;
	cout<<"\t\t\t\t\tPlease Register your Name: ";
	
}

void insert(afaq *&head,afaq *&tail,string d){
    if(head==NULL){
		menu();
        head=tail=new afaq(d);
    }
    else{
		menu();
        afaq *n=new afaq(d);
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}

void print(afaq *head){
	cout<<"\n\n\n\n\n\t\t\t\tPrevious Registered User\n"<<endl;
    while(head!=NULL){
        cout<<"\t\t\t\t*  "<<head->data<<endl;
        head=head->next;
    }
    cout<<endl;

}
void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) 
{
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void drawBorder(){ 
	
	for(int i=0; i<SCREEN_WIDTH; i++){
		gotoxy(i,0); cout<<"?";
		gotoxy(i,SCREEN_HEIGHT); cout<<"?";
	}
	
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(0,i); cout<<"?";
		gotoxy(SCREEN_WIDTH,i); cout<<"?";
	}
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(WIN_WIDTH,i); cout<<"?";
	}
}
void genPipe(int ind){


	gapPosPtr[ind] = 3 + rand()%14; 
}
void drawPipe(int ind){
	if( pipeFlagPtr[ind] == true ){
		for(int i=0; i<gapPosPtr[ind]; i++){ 
			gotoxy(WIN_WIDTH-pipePosPtr[ind],i+1); cout<<"***"; 
		}
		for(int i=gapPos[ind]+GAP_SIZE; i<SCREEN_HEIGHT-1; i++){ 
			gotoxy(WIN_WIDTH-pipePosPtr[ind],i+1); cout<<"***"; 
		}
	} 
}
void erasePipe(int ind){
	if( pipeFlag[ind] == true ){
		for(int i=0; i<gapPosPtr[ind]; i++){ 
			gotoxy(WIN_WIDTH-pipePosPtr[ind],i+1); cout<<"   "; 
		}
		for(int i=gapPos[ind]+GAP_SIZE; i<SCREEN_HEIGHT-1; i++){ 
			gotoxy(WIN_WIDTH-pipePosPtr[ind],i+1); cout<<"   "; 
		}
	}
}

void drawBird(){
	for(int i=0; i<2; i++){
		for(int j=0; j<6; j++){
			gotoxy(j+2,i+birdPos); cout<<bird[i][j];
		}
	}
}
void eraseBird(){
	for(int i=0; i<2; i++){
		for(int j=0; j<6; j++){
			gotoxy(j+2,i+birdPos); cout<<" ";
		}
	}
}

int collision(){
	if( pipePos[0] >= 61  ){
		if( birdPos<gapPosPtr[0] || birdPos >gapPosPtr[0]+GAP_SIZE ){
//			cout<< " HIT ";
//			getch();
			return 1;
		}
	}
	return 0;
}
void debug(){
//	gotoxy(SCREEN_WIDTH + 3, 4); cout<<"Pipe Pos: "<<pipePos[0];
	
}
void gameover(){
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\tThank you For Playing our game" <<endl;
	cout<<"\n\n\n\n\n\t\t\t\t--------------------------"<<endl;
	cout<<"\t\t\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t\t\t--------------------------"<<endl<<endl;
	cout<<"\t\t\t\t----------Score: "<<score<<"--------\n\n\n\n"<<endl;
	cout<<"\t\t\t\tPress any key to go back to menu.";
	getch();
}
void updateScore(){

	gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;
}

void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Press spacebar to make bird fly";

	cout<<"\n\nPress any key to go back to menu";
	getch();
}

void play(){
	int l;
	birdPos = 6;
	score=0;
	pipeFlagPtr[0] = 1; 
	pipeFlagPtr[1] = 0;
	pipePosPtr[0] = pipePosPtr[1] = 4;
	
	system("cls"); 
	
	drawBorder();
	genPipe(0);
	updateScore();
	
	gotoxy(WIN_WIDTH + 5, 2);cout<<"FLAPPY BIRD";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" Spacebar = jump";
	
	gotoxy(10, 5);cout<<"Press any key to start";
	getch();
	gotoxy(10, 5);cout<<"                      ";
	
	while(1){
		 
		if(kbhit()){ // if key is pressed
			char ch = getch();
			if(ch==32){
				if( birdPos > 3 )
					birdPos-=3;
			} 
			if(ch==27){
				break;
			}
		}
		
		drawBird();
		drawPipe(0);
		drawPipe(1);
		debug();
		if( collision() == 1 ){
			gameover();
			return;
		}
		Sleep(100);
		eraseBird();
		erasePipe(0);
		erasePipe(1);
		birdPos += 1;
		
		if( birdPos > SCREEN_HEIGHT - 2 ){
			gameover();
			return;
		}
		
		if( pipeFlagPtr[0] == 1 )
			pipePosPtr[0] += 2;
		
		if( pipeFlagPtr[1] == 1 )
			pipePosPtr[1] += 2;
		
		if( pipePosPtr[0] >= 40 && pipePosPtr[0] < 42 ){
			pipeFlagPtr[1] = 1;
			pipePosPtr[1] = 4;
			genPipe(1);
		}
		if( pipePos[0] > 68 ){
			score++;
			
			updateScore();
			pipeFlagPtr[1] = 0;
			pipePosPtr[0] = pipePosPtr[1];
			gapPosPtr[0] = gapPosPtr[1];
		}
		
	}
	 
}

int main()
{afaq *tail=NULL;
afaq *head=NULL;
 int a;
string c;
	setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	A:
	system("cls");
	 cout<<"\n\n\n\n\n\t\t\t\t -------------------------- "<<endl; 
     cout<<"\t\t\t\t |      Flappy Bird       | "<<endl; 
	 cout<<"\t\t\t\t --------------------------"<<endl;
	 cout<<"\t\t\t\t1. Register your User Name"<<endl;
	 cout<<"\t\t\t\t2. Start Game"<<endl;	 
	 cout<<"\t\t\t\t3. Instructions"<<endl;
	 cout<<"\t\t\t\t4. Registered Users"<<endl;
	 cout<<"\t\t\t\t5. Exit"<<endl;
	 cout<<"\t\t\t\tSelect option: ";
	 cin>>a;
	switch(a){
		case 1:
			system("cls");
			menu();
		 	cin>>c;
			insert(head,tail,c);
			goto A;
			break;
		case 2: 
			system("cls");
		 	play()	;
			goto A;
			break;
	    case 3:
			system("cls");
			instructions();
			goto A;
			break;
		case 4:
			system("cls");
			print (head);
			// goto A;
			break;
		case 5 :
			exit(0);
			break;
					
	}																						
	return 0;
}
