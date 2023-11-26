#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <stdbool.h>
#include<signal.h>
#include<ncurses.h>
#include<ncursesw/ncurses.h>
#include "voom.c"
#include "param.h"
#define EXIT_SUCCESS 0
//#define help "-help"
WINDOW* mainwindow;
void sig_handler(int sig);
int startVoom(){
    char ch;
    int x,y,z,j,i,k,l,m,v,h;
    z = j = i = v = 0;
    h = 2;
    char car[][85] = {"                  _..-------++._",
    "              _.-'/ |      _||  \"--._",
    "        __.--'`._/_\j_____/_||___\    `----.",
    "    _.--'_____    |          \     _____    /",
    " _j    /,---.\   |        =o |   /,---.\   |_             (( -o-))",
    "[__]==// .-. \\==`===========/==// .-. \\=[__]        ( (  VOOOM!! ))",
    ", - `._|\ `-' /|___\_________/___|\ `-' /|_.'  _____---(____--   --__==  )",
    "        `---'                     `---'"};
    printf("starting voom .....");
    initscr();
    getmaxyx(stdscr,y,x);
    k = x - 1;
    l = (x-1)/2;
    m = l-37;
    while(j != x){
        move(z,j);
        printw("*");
        j++;
    }
    while(z != 10){
        move(z,i);
        printw("*");
        move(z,k);
        printw("*");
        z++;
    }

    while(v != 8){
        move(h,m);
        printw("%s",car[v]);
        h++;
        v++;
    }
     refresh();
    getch();
    endwin();
    return EXIT_SUCCESS;
}
int voomHelp(){
    printf("starting voom................\n\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++=\n");
    printf("                     VOOM EDITOR                         \n");
    printf("                                     version 0.1         \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    FILE* vhelp = fopen("voomh.txt","r");
    printcmd(vhelp);
    fclose(vhelp);
    return EXIT_SUCCESS;
}
int renderer(char* argv[]){
    FILE* fptr;
    printw("function called");
    char char_sz;
    char count = 0;
    int n = 10000;
    char ch,cha;
    fptr = fopen(argv[1],"r+");
    char* buffer = (char*)malloc(n * sizeof(char));
    char* buffer3 = buffer;
    char** buffer2 = &buffer;
    printw("%ld",sizeof(count));
    printw("%ld",sizeof(buffer));
    while(ch != EOF){
        ch = fgetc(fptr);
        if(ch == EOF)break;
        *buffer3 = ch;
        buffer3++;
        count++;
        //*buffer2++;
    }
int v,h;
v = buffer;
h = buffer3;
printw("were here now");
printw("%d\n",v);
printw("%d",h);
int y = 0;
int x = 5;

while(buffer != buffer3){
    cha = *buffer;
    move(y,x);
    printw("%c",cha);
    x++;
    if(x == (winsz.ws_col - 1)){
        y++;
        x = 5;
    }
    buffer++;
}
refresh();
return EXIT_SUCCESS;
}

int workplace(){
    int dot_count,line_count,ed_lx,y,x;
    line_count = dot_count = 0;
    y = winsz.ws_row;
    x = winsz.ws_col;
    ed_l = y - 2;
    int ed_lx1,ed_lx2;
    ed_lx = 3;
    while(line_count != ed_l){
        move(dot_count,0);
        printw(".");
        if(line_count < 10){
            move(line_count,ed_lx);
            printw("%d",line_count);
        }else if((10 <= line_count) && (line_count < 100)){
            ed_lx1 = ed_lx - 1;
            move(line_count,ed_lx1);
            printw("%d",line_count);
        }else if((10 <= line_count) && (line_count < 1000)){
            ed_lx2 = ed_lx - 1;
            move(line_count,ed_lx2);
            printw("%d",line_count);
            }
        dot_count++;
        line_count++;
    }

refresh();
return EXIT_SUCCESS;
}

WINDOW* editor(mainwindow)
WINDOW* mainwindow;
{
    int x,y,r,t;
    r = 200;
    t = 60;
    char ch;
    char *cmd= "Voom=> ";
    noecho();
    if(has_colors()){
        start_color();
        init_color(COLOR_RED,17,64,86);
        init_pair(1, COLOR_WHITE, COLOR_RED);
        //use_default_colors();
        attron(1);
        wbkgd(mainwindow, COLOR_PAIR(1));
        wrefresh(mainwindow);
    }
    /*while(ch != 10){
        wbkgd(mainwindow, COLOR_PAIR(1));
        //wattron(mainwindow,COLOR_PAIR(1));
         wrefresh(mainwindow);
        ch = getch();
        printw("%c",ch);
        refresh();
    }*/
    cmd_p = (winsz.ws_row- 1);
    vm_sy = (winsz.ws_row - 2);
    vm_sx = 1;
    ln_ny = (winsz.ws_row - 2);
    ln_nx = (winsz.ws_col - 20);
    move(cmd_p,0);
    printw("%s",cmd);
    move(vm_sy,vm_sx);
    printw("normal");
    move(ln_ny,ln_nx);
    printw("line %d, column %d",r,t);
    refresh();
    workplace();
    //getch();
    //renderer(); 
return mainwindow;
}
int setupwin_param(WINDOW* mainwindow){    
getmaxyx(mainwindow,winsz.ws_row,winsz.ws_col);
//winsize *winsz2 = &winsz;
return EXIT_SUCCESS;
}
WINDOW* setupwin(){
    WINDOW* mainwindow;
    if (initscr() == NULL){
        fprintf(stderr, "Could not initialize ncurses!\n");
        exit(EXIT_FAILURE);
    }
    mainwindow = stdscr;
return mainwindow;
}

// sets up voom window and the diffrent parameters required;

WINDOW* voomWindow_setup(char* argv[]){
    if(setup_f == true){
        delwin(mainwindow);
        setup_f = false;
    }
    WINDOW* mainwindow;
    mainwindow = setupwin();
    printf("reached here\n");
    setupwin_param(mainwindow);
    mainwindow = editor(mainwindow);
    renderer(argv);
    getch();
    return mainwindow;
}
void sig_handler(int sig)
{
  if (SIGWINCH == sig) {
    endwin();
    setup_f = true;
    static WINDOW* mainwindow2;
    printf("terminal window resized\n");
    signal(SIGWINCH,sig_handler);
    mainwindow2 = voomWindow_setup(argv);
    //editor(mainwindow,winsz);

}
}
int main(int argc,char **argv){
    char *help = "-help";
    char *help2 = "-h";
    char* v = argv[1];
    //FILE* edit = fopen(argv[1],"w+");
    signal(SIGWINCH,sig_handler);
    if(argc == 1){
        startVoom();
    }else if(argc > 1){
       if((strcmp(v,help)) == 0||(strcmp(v,help2)) == 0){
        voomHelp();
       }else{
        mainwindow = voomWindow_setup(argv);
        //renderer(argv);
        //getch();

       }
    }
delwin(mainwindow);
endwin();
return 0;
}
