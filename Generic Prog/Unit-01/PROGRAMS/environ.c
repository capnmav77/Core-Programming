#include <stdlib.h>
#include <stdio.h>
void printenv() {
    char ** env;
#if defined(WIN) && (_MSC_VER >= 1900)
    env = *__p__environ();
#else
    extern char ** environ;
    env = environ;
#endif
    for (env; *env; ++env) {
        printf("%s\n", *env);
    }
}

void deff(){
    int i=0;
    #ifdef DEFINE
        printf("%d \n" , DEFINE);
    #else
         printf("%d \n" , 0);
    #endif
   
}

int main (){
    //printenv();
    deff();
    return 0;
}