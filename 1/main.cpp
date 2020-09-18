// basic file operations
#include <iostream>
#include <fstream>
using namespace std;
int writeFile();
int main()
{
    writeFile();
}

int writeFile ()
{
string a;
cin >> a;
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << a;

  myfile.close();
  return 0;
}
