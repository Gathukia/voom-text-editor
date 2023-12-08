#ifndef EXTERN
# define EXTERN extern
# define INIT(x) x
#else
# ifndef INIT
# define INIT(x) x
# endif
#endif
//screen position parameters
EXTERN int cmd_p INIT(= 0);
EXTERN int vm_sy  INIT(= 0);
EXTERN int vm_sx INIT(= 0);
EXTERN int ln_ny INIT(= 0);
EXTERN int ln_nx INIT(= 0);
EXTERN int cl_ny INIT(= 0);
EXTERN int cl_nx INIT(= 0);
EXTERN int ed_l  INIT(= 0);
EXTERN int setup_f INIT(= false);
EXTERN int voomsetup_f INIT(= false);
//windows parameters
typedef struct winsize
{
      unsigned short ws_row;
      unsigned short ws_col;
}winsize;

char** filep;

extern int sidebar_y INIT(= 0);
extern int sidebar_x INIT(= 0);
extern int sidebar_h INIT(= 0);
extern int sidebar_w INIT(= 4);
extern int workplace_y INIT(= 0);
extern int workplace_x INIT(= 0);
extern int workplace_h INIT(= 0);
extern int workplace_w INIT(= 0);
extern int status_y INIT(= 0);
extern int status_x INIT(=0);
extern int status_h INIT(= 0);
extern int status_w INIT(=0);

WINDOW *status_win,*sidebar_win,*workplace_win;
struct buffer{
      char* buffer;
      char* buffer3;
};