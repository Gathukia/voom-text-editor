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
EXTERN int setup_f INIT(= 0);
//windows parameters
typedef struct winsize
{
      unsigned short ws_row;
      unsigned short ws_col;
}winsize;
winsize winsz;
