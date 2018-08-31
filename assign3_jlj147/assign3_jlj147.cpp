//File Name: assign3_jlj147.cpp
//
//Author: Jayce Jones
//Date: 2/21/2016
//Assignment Number: 3
//CS 2308.251 Spring 2016
//Instructor: Jill Seaman
//
//Implements and tests five functions, using pointers
//and dynamic memory allocation

#include <iostream>

using namespace std;

//Function Prototypes
double median(int *,int);
double pizza(int,int,int);
int *resize(int *, int);
int *shiftX(int *,int,int);
int *subArray(int *,int,int);
int *duplicateArray(int *,int);

int main()
{
    const int SIZE = 10; //Changing size of the array
    int values[SIZE]={1,2,3,4,5,6,7,8,9,0}; //Array of integers
    double middle=0;    //Numeric value to store the median score
    int *resizeArray;   //For dynamically allocated array from resize
    int *shiftXArr;     //For dynamically allocated array from shiftX
    int *resultArr;     //For dynamically allocated array from subArray
    int shiftValue = 4; //Numeric value to shift array
    int people = 25;    //Number of people for pizza, to compute price
    int slices = 3;     //Slices of pizza per person, to compute price
    int pizzas = 9;     //Number of pizzas, to compute price
    double price = 0.00;//Numeric value for price
    int *ptr1;          //Points to pizzas
    int *ptr2;          //Points to slices
    int start = 5;      //Numeric value for start index
    int length = 4;     //Numeric value for a string of numbers

    //Median
    cout << "Testing median: " << endl;
    cout << "Test data: 1 2 3 4 5 6 7 8 9 " << endl;
    cout << "Expected median: 4.5" << endl;

    //Call to median function
    middle = median(values,SIZE);
    cout << "Actual median: " << middle << endl;
    cout << endl;

    //Pizza
    cout << "Testing pizza for 25 people: " << endl;
    
    ptr1=&pizzas;     //ptr1 points to pizzas
    ptr2=&slices;     //ptr2 points to slices

    cout << "Expected result: 112.8 p:9 s:3" << endl;

    //Call to pizza
    price = pizza(people,*ptr1,*ptr2);

    cout << "Actual result: ";
    cout << price << " p:" << *ptr1 << " s:" << *ptr2 << endl;
    cout << endl;

    //Resize
    cout << "Testing resize: " << endl;
    cout << "Test data :1 2 3 4 5 6 7 8 9 0" << endl;
    cout << "Expected result: 1 2 3 4 5 6 7 8 9 0 " <<
            "-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 " << endl;

    //Call to resize function
    resizeArray=resize(values,SIZE);

    cout <<"Actual result: ";
    for (int i=0; i<SIZE*2;i++)
    {
        cout << *(resizeArray+i) << " ";
    }
    cout << endl << endl;

    delete [] resizeArray;


    //ShiftX
    cout << "Testing shiftX: " << endl;
    cout << "Test data: 1 2 3 4 5 6 7 8 9 0 " << endl;
    cout << "Expected result: -1 -1 -1 -1 1 2 3 4 5 6 7 8 9 0" << endl;

    //Call to shiftX
    shiftXArr = shiftX(values,SIZE,shiftValue);

    cout << "Actual results: ";
    for (int i=0;i<SIZE+shiftValue;i++)
    {
        cout << *(shiftXArr+i) << " ";
    }
    cout << endl << endl;
    
    delete [] shiftXArr;

    //SubArray
    cout << "Testing subArray: " << endl;
    cout << "Test data: 1 2 3 4 5 6 7 8 9 0" << endl;
    cout << "Start: " << start << " Length: " << length << endl;
    cout << "Expected output: 6 7 8 9" << endl;

    resultArr=subArray(values,start,length);
    
    cout << "Actual results: ";
    for (int i=0;i<length; i++)
    {
        cout << *(resultArr+i) << " ";
    }
    cout << endl << endl;
    
    delete [] resultArr;


    return 0;
}

//*******************************************************************
// median: Finds the medain value of an array
//
// *numbers: The array passed in the form of a pointer variable
// size: The size of the array
// returns: The median value of the array
//********************************************************************

double median (int *numbers, int size)
{
    double sum=0;   //Numeric counter to sum up all the array elements

    for(int i=0; i < size; i++)
    {
       sum += *(numbers+i);
    }

    return sum/size;
}

//*************************************************************************
// pizza: Finds the total price of pizza given 3 paramaters
//
// people: The number of people eating
// ptrP: pointer paramater that represnts the number of pizzas order
// ptrS: pointer paramater that represents the number of slices per person
// returns: The total price of pizza
//**************************************************************************
double pizza(int people, int ptrP , int ptrS)
{
    int totalSlices = people*3; //Numeric value for total slices of pizza
                                //to be used in calculation
    ptrP = totalSlices/8;
    ptrS = totalSlices%8;
    return ptrP*11.95 + ptrS*1.75;
}

//*************************************************************************
// resize: Creates a new array that is twice the size of the argument array
//         and outputs -1 in unused elements of the new array
//
// *numbers: Values array passed as a pointer from main
// size: The original size of values array in main
// returns: A dynamically allocated array as a pointer, with the new values
//**************************************************************************
int *resize(int *numbers, int size)
{
    int *resizeArray;       //Dynamically allocated array created
    int NEW_SIZE = size*2;  //Numeric value for twice the original size
    resizeArray = new int[NEW_SIZE]; //Allocate the new array

    for (int i=0;i<size;i++)
    {
        *(resizeArray+i) = *(numbers+i);
    }

    for (int i=size;i < NEW_SIZE;i++)
    {
        *(resizeArray+i)=-1;
    }
    return resizeArray;
}
//*************************************************************************
// shiftX: Creates a new array x elements larger than the array being passed
//         ,shifts the old elemetns, and sets the new elements equal to -1
//
// *numbers: Values array passed as a pointer from main
// size: The original size of values array in main
// returns: A dynamically allocated array as a pointer, with the new values
//**************************************************************************

int *shiftX(int *numbers, int size, int x)
{

    int *shiftArray;    //Dynamically allocated array created

    shiftArray = new int[size+x]; //Allocate the new array

    for (int i=0;i<size;i++)
    {
        *(shiftArray+i)=*(numbers+i);
    }

    for (int i=0; i < x; i++)
    {
        *(shiftArray+i)=-1;
    }

    for (int i=0; i < size; i++)
    {
        *(shiftArray+i+x)=*(numbers+i);
    }
    
    return shiftArray;

}

//*************************************************************************
// subArray:creates a new array that is a copy of the elements from the
//          original array starting at the start index, and has length
//          equal to the length argument.
//
// *array: Values array passed as a pointer from main
// start: Desired starting index
// length: Desired array length to be outputted
// returns: A dynamically allocated array as a pointer, with the new values
//**************************************************************************

int *subArray(int *array, int start, int length)
{
    //Call to duplicateArray
    int *result = duplicateArray(array+start,length);
    return result;
}

//*************************************************************************
// duplicateArray:Creates a new dynamically allocated array copied from
//                the array that was passed
//
//
// *array: Values array passed as a pointer from main
// size: Desired array length to be outputted
// returns: A dynamically allocated array as a pointer, with the new values
//**************************************************************************

int *duplicateArray(int *arr,int size)
{
    int *newArray; //Dynamically allocated array created
    if(size <= 0)
      return NULL;
    
    newArray = new int[size];   //allocate new array

    for (int i=0; i < size; i++)
    {
        newArray[i] = arr[i];   //copy to new array
    }
    
    return newArray;
}

