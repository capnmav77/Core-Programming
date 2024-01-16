#include<iostream>

using namespace std;

void EnvVar()
{
    char **ptr  = environ;
    while(ptr)
    {
        printf("%s\n",*ptr);
        ptr++;

    }
}


int main(int argc,char *argv[],char **env)
{
   
    for(int i=0;i<argc;i++)
    {
        // cout<<argv[i]<<endl;
        printf("%s\n",argv[i]);
    }

    // char **ptr  = env;
    // while(ptr)
    // {
    //     printf("%s\n",*ptr);
    //     ptr++;

    // }

    EnvVar();

    return 0;
}