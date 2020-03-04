#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

void sort(int[], int);
void printTree(int[], int);

int main()
{
  ifstream inFile;
  int heap [100] = { 0 };
  int len = sizeof(heap)/sizeof(heap[0]);
  //Sort
  //Print tree
  inFile.open("myFile");
  for (int i = 0; i < len; i++){
    inFile >> heap[i];
    cout<<heap[i]<<" ";
  }
  cout<<endl;
  inFile.close();
  return 0;
}

void sort(int heap[], int len){
  
}

void printTree(int heap[], int len){
  
}
