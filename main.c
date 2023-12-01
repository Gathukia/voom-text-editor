#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <stdbool.h>
#include<signal.h>
#include<ncurses.h>
#include<setjmp.h>
#include<ncursesw/ncurses.h>
#include "voom.c"
#include "param.h"
#define EXIT_SUCCESS 0
//#define help "-help"
WINDOW* mainwindow;
void sig_handler(int sig);
int editor();
int startVoom(){
    int x,y,a,b,c,d,e,f;
    c = 0; 
    char voom[][50] = {"_ _    _ _ _ __    _________      ___","\\  \\  /  //    \\  /    \\ |  \\    /   |"," \\  \\/  //  __  \\/  __  \\|   \\></    |","  \\    / \\ (__) /\\ (__) /|  *\\   *\\  |","   \\__/   \\_ __/  \\____/ |_/  \\_/  \\_|"} ;
    y = LINES;
    x = COLS;
    a = (x / 2) - 20;
    b = (y / 2);
    d = 2;
    attron(A_BOLD | COLOR_PAIR(2));
    while(c != 5){
        move(d,a);
        printw("%s",voom[c]);
        c++;
        d++;
    }
    attroff(A_BOLD | COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    printw("..Editor");
    attroff(COLOR_PAIR(3));
    d++;
    e = (x / 2)-6;
    move(d,e);
    printw("VOOM v0.0.1\n");
    d++;
    f = (x / 2)-27;
    move(d,f);
    printw("voom is a simple open source vim prototypic text editor.\n\n");
    d += 2;
    e = (x / 2) -13;
    move(d,e);
    attron(A_BOLD | COLOR_PAIR(2));
    printw("#)Author  :");
    attroff(A_BOLD | COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    printw(" Edwin_ignas   \n");
    attroff(COLOR_PAIR(4));
    d++;
    move(d,e);
    attron(A_BOLD | COLOR_PAIR(2));
    printw("#)Website :");
    attroff(A_BOLD | COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    printw(" Edwinignas.com\n");
    attroff(COLOR_PAIR(4));
    editor();
    move(0,3);
    printw("1");
    refresh();
    getch();
    return EXIT_SUCCESS;
}

int voomHelp(){
    printf("starting voom....\n\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
    char char_sz;
    char count = 0;
    int n = 10000;
    char ch,cha;
    fptr = fopen(argv[1],"r+");
    char* buffer = (char*)malloc(n * sizeof(char));
    char* buffer3 = buffer;
    char** buffer2 = &buffer;
    while(ch != EOF){
        ch = fgetc(fptr);
        if(ch == EOF)break;
        *buffer3 = ch;
        buffer3++;
        count++;
        //*buffer2++;
    }
int y = 0;
int x = 5;
fclose(fptr);

while(buffer != buffer3){
    cha = *buffer;
    move(y,x);
    printw("%c",cha);
    x++;
    if(x == (COLS - 1)){
        y++;
        x = 5;
    }
    buffer++;
}
refresh();
return EXIT_SUCCESS;
}

// int screenPrint_proc(){
//     if(ch == "\n"){
//         moveCursor(n);
//     }else if(ch == 08){
//         movecursor(-1);
//     }else if(ch = 27){
//         moveCursor(escape);
//     }else if(ch == 09){
//         moveCursor(tab);
//     }

// }

int workplace(){
    




    int dot_count,line_count,ed_lx,y,x;
    line_count = dot_count = 0;
    y = LINES;
    x = COLS;
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
int editor()
{
    int x,y,r,t;
    r = 200;
    t = 60;
    char ch;
    char *cmd= "Voom=> ";
    noecho();
    y = LINES;
    x = COLS;
    cmd_p = (y - 1);
    vm_sy = (y - 2);
    vm_sx = 1;
    ln_ny = (y - 2);
    ln_nx = (x - 20);
     
    move(cmd_p,0);
    addstr(cmd);
    move(vm_sy,vm_sx);
    printw("normal");
    move(ln_ny,ln_nx);
    printw("line %d, column %d",r,t);
    refresh(); 
return EXIT_SUCCESS;
}

// sets up voom window and the diffrent parameters required;

int voomWindow_setup(){
    if(setup_f == true){
        delwin(mainwindow);
        setup_f = false;
    }
    wrefresh(stdscr);
    getmaxyx(stdscr,LINES,COLS);
    editor();
    workplace();
    return EXIT_SUCCESS;
}
int setup_screen(){
    if (initscr() == NULL){
        fprintf(stderr, "Could not initialize ncurses!\n");
        exit(EXIT_FAILURE);
}
    if(has_colors()){
        start_color();
        init_color(COLOR_RED,17,64,86);
        init_color(COLOR_GREEN,12, 237, 19);
        init_color(COLOR_BLUE,237, 12, 203);
        init_color(COLOR_YELLOW,237, 237, 12);
        init_pair(1, COLOR_WHITE, COLOR_RED);
        init_pair(2,COLOR_GREEN,COLOR_RED);
        init_pair(3,COLOR_BLUE,COLOR_RED);
        init_pair(4,COLOR_YELLOW,COLOR_RED);
        //use_default_colors();
        attron(1);
        wbkgd(stdscr, COLOR_PAIR(1));
        wrefresh(stdscr);
    }
clear();
return EXIT_SUCCESS;
}
void sig_handler(int sig)
{
  if (SIGWINCH == sig) {
    setup_f = true;
    if(setup_f == true){
        endwin();
        setup_f = false;
    }
    endwin();
    setup_screen();
    voomWindow_setup();
    renderer(filep);
}
}
int main(int argc,char **argv){
    char *help = "-help";
    char *help2 = "-h";
    char* v = argv[1];
    int x = 0;
    filep = argv;
    //FILE* edit = fopen(argv[1],"w+");
    signal(SIGWINCH,sig_handler);
    
    if((argc > 1) && ((strcmp(v,help) == 0)||(strcmp(v,help2) == 0))){
        voomHelp();
    }else{
        setup_screen();
        if(argc == 1){
        while(x != 3){
            startVoom();
            delay(7000);
            printw("%d curse init",x);
            x++;
        }
        goto end;
        }
    if(argc > 1){
        voomWindow_setup();
        renderer(filep);
        delay(3000);
    }
    }
 /*if(argc == 1){
        initscr();
        while(x != 3){
            startVoom();
            delay(700);
            printw("%d curse init",x);
            x++;
        }
        endwin();

    }else if(argc > 1){
       if((strcmp(v,help)) == 0||(strcmp(v,help2)) == 0){
        voomHelp();
       }else{
        filep = argv;
        voomWindow_setup(filep);
        //renderer(argv);
        //getch();

       }
    }
while(getch() != 10){
    voomWindow_setup(filep);
    delay(700);
}*/
end:    
endwin();
return 0;
}
