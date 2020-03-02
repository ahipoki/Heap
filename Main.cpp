#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream inFile;
  int heap [100];
  inFile.open("myFile.exe");
  inFile >> heap[1] >> heap[2] >> heap[3] >> heap[4];
  inFile.close();
  cout<<"\n  5"<<endl;
  cout<<" / \\"<<endl;
  cout<<"5   5"<<endl;
}
