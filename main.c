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
void sig_handler(int sig);
int editor();
int startVoom(){
    voomsetup_f = true;
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

struct buffer renderer(char* argv[]){
    FILE* fptr;
    char char_sz;
    int n = 40000;
    char count = 0;
    char ch;
    fptr = fopen(argv[1],"r+");
    char* buffer = (char*)malloc(n * sizeof(char));
    char* buffer3 = buffer;
    while(ch != EOF){
        ch = fgetc(fptr);
        if(ch == EOF)break;
        *buffer3 = ch;
        buffer3++;
        count++;
        //*buffer2++;
    }
fclose(fptr);
struct buffer mybuffer;
mybuffer.buffer = buffer;
mybuffer.buffer3 = buffer3;
return mybuffer;
}

int workplace_edit(){
    wrefresh(workplace_win);
    char cha;
    char count = 0;
    if(filep[1] != NULL){
    char *buffer,*buffer2,*buffer3;
    struct buffer workbuffer;
    workbuffer = renderer(filep);
    buffer = workbuffer.buffer;
    buffer3 = workbuffer.buffer3;
    buffer2 = buffer;
    int x,y;
    x = y = 0;
    while(buffer2 != buffer3){
        cha = *buffer2;
            mvwprintw(workplace_win,y,x,"%c",cha);
            x++;
            if(x == (workplace_w - 1 )){
                y++;
                x = 0;
            }
            buffer2++;
        }
    wrefresh(workplace_win);
    free(buffer);
    wrefresh(workplace_win);
}

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

int sidebar_edit(){
    int dot_count,line_count,ed_lx,y,x;
    line_count = dot_count = 0;
    y = LINES;
    x = COLS;
    ed_l = sidebar_h;
    int ed_lx1,ed_lx2;
    ed_lx1 = ed_lx2 = 0;
    ed_lx = (sidebar_w - 1);
    while(line_count != ed_l){
        wmove(sidebar_win,dot_count,0);
        wprintw(sidebar_win,"~");
        if(line_count < 10){
            wmove(sidebar_win,line_count,(ed_lx - 1));
            wprintw(sidebar_win,"%d",line_count);
        }else if((10 <= line_count) && (line_count < 100)){
            ed_lx1 = ed_lx - 2;
            wmove(sidebar_win,line_count,ed_lx1);
            wprintw(sidebar_win,"%d",line_count);
        }else if((10 <= line_count) && (line_count < 1000)){
            ed_lx2 = ed_lx - 3;
            wmove(sidebar_win,line_count,ed_lx2);
            wprintw(sidebar_win,"%d",line_count);
            }
        dot_count++;
        line_count++;
    }

wrefresh(sidebar_win);
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
int status_edit(){
    wrefresh(status_win);
    int r,t;
    r = 20;
    t = 60;
    char *cmd= "Voom=> ";
    cmd_p = (status_h - 1);
    vm_sy = (status_h - 2);
    vm_sx = 0;
    ln_ny = (status_h - 2);
    ln_nx = (COLS - 20);
    mvwprintw(status_win,cmd_p,0,"%s",cmd);
    mvwprintw(status_win,vm_sy,vm_sx,"normal");
    mvwprintw(status_win,ln_ny,ln_nx,"line %d, column %d",r,t);
    wrefresh(status_win);
return EXIT_SUCCESS;
}

// sets up voom window and the diffrent parameters required;

int voomWindow_setup(){
    wrefresh(stdscr);
    getmaxyx(stdscr,LINES,COLS);
    //editor();
    //workplace();
    return EXIT_SUCCESS;
}
int terminal_start(){
    if (initscr() == NULL){
        fprintf(stderr, "Could not initialize ncurses!\n");
        exit(EXIT_FAILURE);
    }
    clear();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    return EXIT_SUCCESS;
}
void terminal_stop(){
    endwin();
}

int setup_screen(){
    terminal_start();
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
int windows_setup(){
    status_h = 2;
    status_w = COLS;
    status_y = (LINES - status_h);
    status_x = 0;
    sidebar_h = status_y;
    sidebar_w = 5;
    sidebar_y = 0;
    sidebar_x = 0;
    workplace_h = status_y;
    workplace_w = (COLS) - sidebar_w;
    workplace_y = 0;
    workplace_x = sidebar_w;
    status_win = newwin(status_h,status_w,status_y,status_x);
    sidebar_win = newwin(sidebar_h,sidebar_w,sidebar_y,sidebar_x);
    workplace_win = newwin(workplace_h,workplace_w,workplace_y,workplace_x);
return EXIT_SUCCESS;
}

void reset_parameters(){
    wrefresh(stdscr);
    getmaxyx(stdscr,LINES,COLS);
    status_h = 2;
    status_w = COLS;
    status_y = (LINES - status_h);
    status_x = 0;
    sidebar_h = status_y;
    sidebar_w = 4;
    sidebar_y = 0;
    sidebar_x = 0;
    workplace_h = status_y;
    workplace_w = (COLS - 1) - sidebar_w;
    workplace_y = 0;
    workplace_x = sidebar_w;

}
int start_processes(){
    if(setup_f != true){
        windows_setup();
    }else if((setup_f == true) && (voomsetup_f == true)){
        windows_setup();
        voomWindow_setup();
    }else{
        reset_parameters();
    }
    sidebar_edit();
    status_edit();
    workplace_edit();
    setup_f = false;
    voomsetup_f = false;
    return EXIT_SUCCESS;
}
void sig_handler(int sig)
{
  if (SIGWINCH == sig) {
    setup_f = true;
    terminal_stop();
    setup_screen();
    voomWindow_setup();
    int y = LINES;
    int x = COLS;
    wresize(status_win,y,x);
    wclear(status_win);
    wresize(sidebar_win,y,x);
    wclear(sidebar_win);
    wresize(workplace_win,y,x);
    wclear(workplace_win);
    start_processes();
    //renderer(filep);
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
    //buffer = (char*)malloc(n * sizeof(char));
    if((argc > 1) && ((strcmp(v,help) == 0)||(strcmp(v,help2) == 0))){
        voomHelp();
    }else{
        setup_screen();
        if(argc == 1){
            startVoom();
            while(getch() == 10){
                start_processes();
            }
        }
    if(argc > 1){
        start_processes();
        //voomWindow_setup();
        //renderer(filep);
        delay(30000);
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
terminal_stop();
return 0;
}
