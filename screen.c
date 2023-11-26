int workplace(){
    int dot_count,line_count,ed_lx,y,x;
    line_count = dot_count = 0;
    getmaxyx(stdscr,y,x);
    ed_l = y - 2;
    int ed_lx1,ed_lx2;
    ed_lx = 3;
    while(line_count != ed_l){
        move(dot_count,0);
        printw(".");
        if(line_count < 10){
            move(line_count,ed_lx);
            printw("%d",line_count);
        }else if(line_count < 100){
            ed_lx1 = ed_lx - 1;
            move(line_count,ed_lx1);
            printw("%d",line_count);
        }else if(line_count < 1000){
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

int editor(mainwindow,winsz)
WINDOW* mainwindow;
winsize winsz;
{
    int x,y,r,t;
    r = 200;
    t = 60;
    char ch;
    char cmd[] = "Voom=> ";
    noecho();
    if(has_colors()){
        start_color();
        init_color(COLOR_RED,17,64,86);
        init_pair(1, COLOR_WHITE, COLOR_RED);
        //use_default_colors();
        attron(1);
    }
    while(ch != 10){
        wbkgd(mainwindow, COLOR_PAIR(1));
        //wattron(mainwindow,COLOR_PAIR(1));
         wrefresh(mainwindow);
        ch = getch();
        printw("%c",ch);
        refresh();
    }
    refresh();
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
    getch();
    //renderer(); 
return EXIT_SUCCESS;
}
struct winsize setupwin_param(){
winsize  winsz;
winsize *winsresize = &winsz;    
getmaxyx(stdscr,winsz.ws_row,winsz.ws_col);
return winsz;
}
WINDOW* setupwin(){
    WINDOW* mainwindow;
    if ( (mainwindow = initscr()) == NULL) {
        fprintf(stderr, "Could not initialize ncurses!\n");
        exit(EXIT_FAILURE);
    }
return(mainwindow);
}
WINDOW* voomWindow_setup(WINDOW* mainwindow){
    mainwindow = setupwin();
    winsize winsz;
    winsz = setupwin_param();
    return mainwindow;
}