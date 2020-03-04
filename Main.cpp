#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

void strupper(char* str);
void sort(int[], int);
void printTree(int[], int);
void buildHeap(int[], int);
void heap(int[], int);

int main()
{
  char input[80];
  cout<<"Do you want to use input or a file?"<<endl;
  cin.getline(input, 80);
  strupper(input);
  if (strcmp(input, "INPUT")==0){
    cout<<"Input"<<endl;
  }
  else if (strcmp(input, "FILE")==0){
    cout<<"File"<<endl;
  }
  ifstream inFile;
  //int heap [100] = { 0 };
  int heap[] = { 1, 4, 5, 2, 3};
  int len = sizeof(heap)/sizeof(heap[0]);
  sort(heap, len);
  printTree(heap, len);
  inFile.open("myFile");
  for (int i = 0; i < len; i++){
    inFile >> heap[i];
    cout<<heap[i]<<" ";
  }
  cout<<endl;
  inFile.close();
  return 0;
}

void strupper(char* str){
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    str[i] = toupper(str[i]);
  }
}

void sort(int heap[], int len){
  buildHeap(heap, len);
  //for (int i = 0; i < len-1; i++){
  for (int i = len-1; i >= 0; i--){
    swap(heap[0], heap[i]);
    cout<<heap[i]<<endl;
  }
}

void printTree(int heap[], int len){
  cout<<"Placeholder"<<endl;
}

void buildHeap(int heap[], int len){
  for (int i = len/2-1; i >= 0; i--){
    cout<<"testing"<<endl;
  }
  cout<<"Heap"<<endl;
}
