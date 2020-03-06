#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void strupper(char* str);
void sort(int[], int);
void printTree(int[], int, int, int);
void heapify(int[], int);
void heapDown(int[], int, int);

int main()
{
  char input[80];
  //File or input
  char line[100];
  //File name or array of numbers
  bool type = false;
  //Bool
  while (type == false){//While they didn't enter the file name or numbers correctly
    cout<<"Do you want to use input or a file?"<<endl;
    //Ask if they want to use input or a file
    cin.getline(input, 80);
    //Get their input
    strupper(input);
    //Make it uppercase
    if (strcmp(input, "INPUT")==0){//If they said input
      type = true;
      //Set bool to true
      cout<<"Please enter a list of integers separated by spaces"<<endl;
      //Ask them for a list of ints separated by spaces
      cin.get(line, 100);
      //Get their input
      cin.clear();
      cin.ignore(999, '\n');
    }
    else if (strcmp(input, "FILE")==0){//Else if they said file
      char fileName[100];
      //File name
      cout<<"Enter a file name"<<endl;
      //Ask for a file name
      cin.getline(fileName, sizeof(fileName));
      //Get their input
      ifstream fileStream;
      //File setup
      fileStream.open(fileName);
      //Open the file they inputted
      if (fileStream){//If they were able to open it
        fileStream.getline(line, sizeof(line));
	//Get the numbers from the file
      }
      else{//If it couldn't be found
        cout<<"Couldn't find that file"<<endl;
	//Tell them that isn't a file
        return 0;
	//Return
      }
      fileStream.close();
      //Close the file
      type = true;
      //Set bool to true
    }
    else{//Anything else
      cout<<"That's an invalid option"<<endl;
      //Tell them that's an invalid option
    }
  }
  char* list = strtok(line, " ");
  //Separate the input into tokens split by spaces
  int heap[100];
  //Heap
  int len = 0;
  //Length
  while (list){//While list
    heap[len] = atoi(list);
    //Convert it to ints
    heapify(heap, len);
    //Call heapify
    list = strtok(NULL, " ");
    len++;
    //Add 1 to len
  }
  cout<<"Visual Representation"<<endl;
  //Visual representation
  printTree(heap, len, 0, 0);
  //Print tree function
  cout<<"Max to min:"<<endl;
  //Max to min
  sort(heap, len);
  //Sort numbers
  cout<<endl;
  return 0;
  //Return 0
}

void strupper(char* str){//Set to uppercase
  int len = strlen(str);
  //Length of char* str
  for (int i = 0; i < len; i++){//For length of char* str
    str[i] = toupper(str[i]);
    //Make it uppercase
  }
}

void sort(int heap[], int len){//Sort function
  int originLen = len;
  //Original length
  for (int i = 0; i < originLen; ++i){//For the length
    cout<<heap[0]<<" ";
    //Print heap[0] and a space
    int last = heap[len-1];
    //Last is heap[len-1]
    heap[0] = last;
    //Heap[0] is last
    len--;
    //Subtract 1 from length
    heapDown(heap, len, 0);
    //Call heapDown
  }
}

void printTree(int heap[], int len, int depth, int ind){//Print tree function
  if (ind*2+1 < len){
    printTree(heap, len, depth+1, ind*2+1);
    //Recursively call print tree function
  }
  for (int i = 0; i < depth; i++){
    cout<<"      ";
    //Print spaces
    //Print heap value
  }
  cout<<heap[ind]<<endl;
  if (ind*2+2 < len){
    printTree(heap, len, depth+1, ind*2+2);
    //Recursively call print tree function
  }
}

void heapDown(int heap[], int len, int in){//Heap down function
  int largest = in;
  //Largest
  int l = 2*in+1;
  //Left
  int r = 2*in+2;
  //Right
  if (l < len && heap[l] > heap[largest]){//If left is < length and heap[left] > largest in heap
    largest = l;
    //Largest is now left
  }
  if (r < len && heap[r] > heap[largest]){//If right < length and heap[right] > largest in heap
    largest = r;
    //Largest is now right
  }
  if (largest != in){//If largest is not in
    swap(heap[in], heap[largest]);
    //Swap in and largest
    heapDown(heap, len, largest);
    //Recursively call heap down function
  }
}

void heapify(int heap[], int len){//Heapify
  int parent = len/2;
  //Parent is length divided by 2
  if (heap[len] > heap[parent] && len > 0){//If length of heap > heap[parent] and length > 0
    swap(heap[len], heap[parent]);
    //Swap length of heap and parent
    heapify(heap, parent);
    //Recursively call heapify
  }
}
