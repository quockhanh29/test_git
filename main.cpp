     #include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
 
using namespace std;
 
void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,Cursor_an_Pos);
}
 
void layout(){
    gotoxy(0,0);
    for(int i=0;i<=5;i++) cout << "                   \n";
    gotoxy(0,0);
    cout << " ";
    for(char i='A';i<='Z';i++)
        cout << " " << i;
    gotoxy(0,20); cout << "_______________________________________________________";
}
 
int chardown(int s){
    srand(time(NULL));
    int col=rand()%26+1;
    int i=0;
    while(i<20&&!kbhit()){
        gotoxy(col*2,i);
        cout << " ";
        gotoxy(col*2,i+1);
        cout << char(64+col);
        Sleep(s);
        i++;
    }
    gotoxy(col*2,i); cout << " ";
    gotoxy(col*2,0); cout << char(64+col);
    if(i<20){
        char check=getch();
        if(check==char(96+col)||check==char(64+col))
        return 1;
        else return 0;
    } else {
        gotoxy(col*2,20);
        cout << "_";
        return 0;
    }
}
 
int main(){
    int lv;
    cout << "1: Level 1\n2: Level 2\n3: Level 3\n4: Level 4\n5: Level 5\n";
    cout << "Nhap level: "; cin >> lv;
    layout();
    int d1=0,d2=0,speed=500/lv;
    while(d1<20&&d2<20&&speed>0){
        if(chardown(speed)==1){
            d1++;
            gotoxy(0,22);
            cout << "Ban duoc " << d1 << " diem!\n";
        }else{
            d2++;
            gotoxy(0,23);
            cout << "May duoc " << d2 << " diem!\n";
        }
        speed-=3;
    }
    gotoxy(0,24);
    system("pause");
    return 0;
}

