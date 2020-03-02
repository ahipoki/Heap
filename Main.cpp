#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int array[100];
  int len = sizeof(array)/sizeof(array[0]);
  cout<<len<<endl;
  ifstream inFile;
  int heap [100] = { 0 };
  inFile.open("myFile");
  for (int i = 0; i < 100; i++){
    inFile >> heap[i];
    //cout<<heap[i]<<endl;
  }
  inFile.close();
  cout<<"\n  5"<<endl;
  cout<<" / \\"<<endl;
  cout<<"5   5"<<endl;
}
