#include <stdio.h>
#include <windows.h>   // WinApi header

void strong()
{
    HANDLE  hConsole;
    int k = 2;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    printf("%s\n","Entered password provides Strong security.\n");
    //return 0;
}
void Medium()
{
  HANDLE  hConsole;
    int k = 6;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    printf("%s\n","Entered password provides Medium security.\n");
    //return 0;
}
void Week()
{
  HANDLE  hConsole;
    int k = 4;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    printf("%s\n","Entered password provides Week security.\n");
    //return 0;
}
void psort()
{
  HANDLE  hConsole;
    int k = 4;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    printf("%s\n","Password length is short.\n");
    //return 0;
}
void plong()
{
  HANDLE  hConsole;
    int k = 4;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
    printf("%s\n","Password length is long.\n");
    //return 0;
}