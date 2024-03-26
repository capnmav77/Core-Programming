#include<iostream>

using namespace std;

// Static variable with file scope
static int fileScopedVariable = 10;

void exampleFunction() {
    // Static variable with function scope
    static int functionScopedVariable = 20;

    functionScopedVariable ++ ;
    cout<<functionScopedVariable<<endl;
}

int* getStaticPointer() {
  static int staticVariable = 42;
  cout <<staticVariable<<endl;
  return &staticVariable;
}


int main(void)
{
  // union long_bytes
  // {
  //   char ind[4];
  //   long ll;
  // } u1;
  // long l1 = 0x10203040;
  // int i;
  // u1.ll = l1;
  // for (i = 0; i < sizeof(long); i++)
  //   printf("Byte %d is %x\n", i, u1.ind[i]);
  // printf("%d", sizeof(long));
  // return 0;

  // exampleFunction();
  // exampleFunction();

  int *ptr = getStaticPointer();

  *ptr =100;
  getStaticPointer();

}