#include<stdio.h>

#define EXIT_SUCCESS 0

int fcopy(FILE* tmp,FILE* Temp){
    char ch = 0;
    while(ch != EOF){
        ch = fgetc(tmp);
        fputc(ch,Temp);
    }
return 0;
}

int capitalToSmall(FILE* Temp,char** argv){
    char ch;
    int small = 32;
    fseek(Temp,0,SEEK_SET);
    FILE* tmp = tmpfile();
    while(ch != EOF){
        ch = fgetc(Temp);
        if(ch >= 65 && ch <= 90){
            ch += small;
            fputc(ch,tmp);
        }else fputc(ch,tmp);
    }
Temp = fopen(argv[2],"w+");
rewind(tmp);
fcopy(tmp,Temp);
return EXIT_SUCCESS;
}
/*int clear(FILE* Temp,FILE** Temp1){
while(Temp != Temp1){
        tem     
    }
}
}*/
FILE* cleanWords(FILE* Temp,char* argv[]){
    char ch = 0;
    fseek(Temp,0,SEEK_SET);
    FILE* tmp = tmpfile();
    while(ch != EOF){
        ch = fgetc(Temp);
        if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
            fputc(ch,tmp);
        }else if(ch == 32 || ch == '\n'){
            fputc(ch,tmp);
        }else goto finish;
    finish:
    }
rewind(tmp);
Temp = fopen(argv[2],"w+");
fcopy(tmp,Temp);
return EXIT_SUCCESS;
}


FILE *separateWords(FILE *ptr,FILE* xs/*char **argv*/){
    int count,count1;
    char ch; 
    FILE *tmp = tmpfile();
    if (tmp == NULL) 
    {
        puts("Unable to open temporary file"); 
    }
    while(ch != EOF){
        ch = fgetc(ptr);
        if(ch == 32 || ch == '\n'){
            if(ch == 32 && count == 0){
                fputc('\n',tmp);
                count++;
                goto after;
            }else if(ch == '\n' && count1 == 0){
                fputc(ch,tmp);
                count1++;
                goto after;
            }

        }else if(ch == '-'){
            fputc('\n',tmp);
        }else{
            fputc(ch,tmp);
            count = count1 = 0;
        }
    after:
}
    rewind(tmp);   /*fseek(tmp,0,SEEK_SET) */
    fcopy(tmp,xs);
    return 0;
}

int main(int argc,char **argv){
	FILE* ptr = fopen(argv[1],"r");
    FILE* Temp = fopen(argv[2],"w+");
    separateWords(ptr,Temp);
    cleanWords(Temp,argv);
    capitalToSmall(Temp,argv);
    fclose(ptr);
    fclose(Temp);
return 0;
}