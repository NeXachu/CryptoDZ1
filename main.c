#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LineWidth 80
#define FilenameWidth 100
int pseudorand(char* line, int *n, int* seed){
    int result=*seed;
    for (;*line!=0;++line){
        result=(result* 257  + *line  )%1301077;
    }
    return abs(result%*n)+1;
}

int main(int argc,char* argv[]){
    int opt=0;
    char* filename=(char*)malloc(FilenameWidth);
    int n;
    int seed=1;
    while ((opt=getopt(argc,argv,"f:n:s::"))!=-1){
        switch (opt)
        {
        case 'f':
            strcpy(filename,optarg); 
            break;
        case 'n':
            if (optarg==NULL) return 0;
            n=atoi(optarg);
            break;     
        case 's':
            if (optarg==NULL) return 0;
            seed=atoi(optarg);
            break;
        case '?': printf("Err found!\n");break;
        };
    };
    FILE *f=fopen(filename,"r");
    if (f==NULL){ fprintf(stderr,"Can't open file!"); return 0;}
    char* line=(char*) malloc(LineWidth);
    while (!feof(f)){
        fgets(line,LineWidth,f);
        if (line[strlen(line)-1]=='\n') line[strlen(line)-1]=0;
        fprintf(stdout,"%s: %i \n",line, pseudorand(line,&n,&seed));
    }
    fclose(f);
    return 0;
};