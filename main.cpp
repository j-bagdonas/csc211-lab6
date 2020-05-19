#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class textLines{

public:
     explicit textLines(int); //constructor to set size of an empty list
     explicit textLines(const string&);//constructor to fill up array
     textLines(const textLines&);// copy constructor
     int getLength();
     string returnAndDeleteLast();
     void addNewLineAndExpand(string);
     void empty();
     int numLines();
     textLines combine(const textLines&);
     ~textLines();
     string* arr;
     int size;

private:
    int length;
};
//constructor to set empty list
textLines::textLines(int capacity){
    size = capacity;
    arr = new string [size];
    length = 0;
}
//constructor to fill array
textLines::textLines(const string& name) {
    size = 10;
    arr = new string[size];
    ifstream inFile;
    length = 0;
    inFile.open(name);
    string line;
    while(!inFile.eof()){

        getline(inFile, line);
        arr[length] = line;
        length++;
    }
    inFile.close();
    cout << "New object created with data from  \'" << name << "\'. here is the list:" << endl;
    for (int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
    cout << "------------------------" << endl;
}

//copy constructor
textLines::textLines(const textLines&x) {
  size = 10;
  arr = new string [size];

  for(int i = 0; i < x.length; i++){
      arr[i] = x.arr[i];
  }
  length = x.length;
}

//gets length
int textLines::getLength(){
    return length;
}

//removes and returns last element in list
string textLines::returnAndDeleteLast() {

    string last = arr[length-1];
    arr[length - 1] = "";
    length--;

    return last;
}
//adds new string to the end and expands the array.
void textLines::addNewLineAndExpand(string line) {
    if (length + 1 > size){
        size = size *2;
        cout << "*List capacity doubled*" << endl;
        }
        arr[length] = line;
        cout << "\'" << arr[length] << "\'" << " has been added to the list" << endl;
    cout << "------------------------" << endl;

}

//empties the list
void textLines::empty(){
    for(int i = 0; i < length; i ++){
        arr[i] = "";
    }
}

//return number of lines still on the list
int textLines::numLines(){
    int count = 0;
    for (int i = 0; i < length; i++){
        if(arr[i] != ""){
            count ++;
        }
    }
    return count;
}

//combine current obj list with another
textLines textLines::combine(const textLines&obj){

    int mergeSize = size + obj.size;
    textLines temp(mergeSize);

    for(int i = 0; i < length; i++){
        temp.arr[i] = arr[i];
    }
    for (int j = 0; j < obj.length; j++){
        temp.arr[length + j] = obj.arr[j];
    }

    temp.length = length + obj.length;

    cout << "two lists combined: " << endl;

    return temp;
}
//destructor
textLines::~textLines(){
    delete [] arr;
}

int main() {

    //two instances of the class
    textLines x1("file1.txt");
    textLines x2("file2.txt");


    //add new line to the end of the list.
    x1.addNewLineAndExpand("here is a new line");

    //combine two lists
    textLines x3 = x1.combine(x2);
    for (int i = 0; i < x3.getLength(); i++){
        cout << x3.arr[i] << endl;
    }
    cout << "------------------------" << endl;

    //remove and return last
    cout << "the last line from x1 is: " << endl;
    cout << "\'"  << x1.returnAndDeleteLast() << "\'" << endl;
    cout << "------------------------" << endl;

    //number of lines
    cout << "the number if lines still in x1 is now: ";
    cout << x1.numLines() << endl;
    cout << "------------------------" << endl;

    //empty x2
    x2.empty();
    cout << x2.arr[2] << endl; //for example nothing should show up

    //copy constructor
    textLines x4(x1);
    cout << "New object created. copied list from x1: " << endl;
    for (int i = 0; i < x4.getLength(); i++){
        cout << x4.arr[i] << endl;
    }

    return 0;
}