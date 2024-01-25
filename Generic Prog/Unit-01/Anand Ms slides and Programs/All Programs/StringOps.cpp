// Program to illustrate the use of the abstract data type string
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string content, prevStr;
  string line;
  cout << "Please introduce a text. Enter an empty line to finish:\n";
  do
  {
    getline(cin,line);
    if (line == prevStr) // just checking whether the same string has been keyed in again
        cout << "Previous and the current string are the same" << endl;
    prevStr = line;
    cout << "Size of this string is " << line.size() << endl;
    content += line + '\n';
  } while (!line.empty());
  cout << "The text you introduced was:\n" << content;
  return 0;
}
