// File Name: assign2_jlj147.cpp
//
// Author: Jayce Jones
// Date: 2/16/2016
// Assignment Number: 2
// CS 2308.251 Spring 2016
// Instruc1tor: Jill Seaman
//
// Allows a user to manage the inventory of a small store

#include <iostream>
#include <iomanip>

using namespace std;

//Structure containing 4 variables
struct ShopInventory
{
    string productName; //product Name
    string location;    //product location
    int quantity;       //product quantity
    double price;       //product price
};

//Function Prototypes
void addProduct(ShopInventory[], int);
void removeProduct(ShopInventory[], int&);
void adjustQuantity(ShopInventory[],int);
void productInfo(ShopInventory[],int);
void storeInventory(ShopInventory[],int);
int binarySearch(ShopInventory[],string, int);
void bubbleSort(ShopInventory[],int);


const int MAXCAPACITY = 100; //Maximum inventory constant

int main()
{
    int count = 0; //count variable initialized to zero
    int choice;   //menu choice chosen by user
    ShopInventory catalog[MAXCAPACITY]; //array of struct
    //holds info for 100 products

    do{
        //Display the Menu
        cout << "Manage Inventory Menu" << endl;
        cout << endl;
        cout << "1. Add a new product to the inventory" << endl;
        cout << "2. Remove a product from the inventory" << endl;
        cout << "3. Adjust quantity of a product" << endl;
        cout << "4. Display information for a product" << endl;
        cout << "5. Display inventory sorted by product name" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        while (choice < 1 || choice > 6)
        {
            cout << "Please enter a valid choice (1-6): ";
            cin >> choice;
        }

        //Add Product
        if (choice == 1)
        {
            addProduct(catalog,count);
            count++;
        }

        //Remove Product
        if (choice == 2)
        {
            removeProduct(catalog,count);
        }

        //Adjust Quantity
        if (choice == 3)
        {
            adjustQuantity(catalog,count);
        }

        //Display Product Info
        if (choice == 4)
        {
            bubbleSort(catalog,count);
            productInfo(catalog,count);
        }

        //Display Inventory
        if (choice == 5)
        {
            bubbleSort(catalog,count);
            storeInventory(catalog,count);
        }

        //Quit Program
    }while(choice != 6);

    cout << "Exiting the Program" << endl;

    return 0;
}

//*******************************************************************
// addProduct: Prompts user for product information and adds it to
//             the inventory
//
// catalog: Array of struct with 4 variables, max size 100
// c:count variable, containing array elements (product information)
//********************************************************************

void addProduct(ShopInventory catalog[], int c)
{

    int position;   //Position of product in the array
    string name;   //Name from user used to find product

    if (c < MAXCAPACITY-1)
    {
        cout << "Enter the new product name: ";
        cin >> ws;
        getline (cin, catalog[c].productName);
        name = catalog[c].productName;
        position = binarySearch(catalog,name,c);
        if (position == -1)
        {
            cout << "Enter the location (No Spaces): ";
            cin >> catalog[c].location;

            do{
                cout << "Enter the quantity (0 or more): ";
                cin >> catalog[c].quantity;
            }while(catalog[c].quantity < 0);

            do{
                cout << "Enter the price (Greater than 0): ";
                cin >> catalog[c].price;
            }while(catalog[c].price <= 0.01);
            cout << endl;
        }
        else
        {
            cout << "The product name must be unique" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "The inventory is full" << endl;
        cout << endl;
    }
}

//*******************************************************************
// removeProduct: Prompts user for product information and removes the
//                product from the inventory
//
// catalog: Array of struct with 4 variables, max size 100
// &c:count variable, passed by reference, containing array elements
//********************************************************************

void removeProduct(ShopInventory catalog[], int &c)
{
    string name;    //Name from user used to find product
    int position;   //Position of product in the array

    cout << "What item would you like to remove from the inventory? ";
    cin >> ws;
    getline (cin,name);

    position=binarySearch(catalog,name,c);
    if (position == -1)
    {
        cout << "This item is not in the inventory" << endl;
        cout << endl;
    }
    else
    {
        for (int i=position;i < c-1;i++)
        {
            catalog[i]=catalog[i+1];
        }
        c--;
        cout << "Removed product with name: "<< catalog[position].productName
        << endl;
        cout << endl;
    }

    bubbleSort(catalog,c);
}

//*******************************************************************
// adjustQuantity: Asks user for the name of a product whose quantity
//                 needs to be adjusted, and does so
//
// catalog: Array of struct with 4 variables, max size 100
// c:count variable, containing array elements (product info)
//********************************************************************

void adjustQuantity(ShopInventory catalog[],int c)
{
    int position;   //Position of product in the array
    string name;   //Name from user used to find product
    int change;    //Desired change to quantity

    cout << "What is the product name?: ";
    cin >> ws;
    getline (cin,name);

    position = binarySearch(catalog,name,c);
    if (position == -1)
    {
        cout << "The product has not been found" << endl;
        cout << endl;
    }

    else
    {
        cout << "Enter desired change to quantity(use negative value to"
        "decrease quantity):";
        cin >> change;
        cout << endl;
        //Equation to decrease and increase quantity
        catalog[position].quantity = catalog[position].quantity+change;
    }
}

//*******************************************************************
// productInfo: Displays the location, quantity, and price of a product
//              given the name
//
// catalog: Array of struct with 4 variables, max size 100
// c:count variable,containing array elements (product info)
//********************************************************************

void productInfo(ShopInventory catalog[],int c)
{
    int position; //Position of product in the array
    string name;  //Name from user used to find product

    cout << "Enter product name of product to find: ";
    cin >> ws;
    getline (cin,name);
    cout << endl;

    position = binarySearch(catalog,name,c);
    if (position == -1)
    {
        cout << "The product has not been found" << endl;
        cout << endl;
    }
    else
    {
        cout << "Product Name:" << catalog[position].productName << endl;
        cout << "Location:" << catalog[position].location << endl;
        cout << "Quantity:" << catalog[position].quantity << endl;
        cout << "Price:$" << setprecision(2) << catalog[position].price
        << endl;
        cout << endl;
    }
}

//************************************************************************
// storeInventory: Displays the information for each product in inventory
//                 on a seperat line
//
// catalog: Array of struct with 4 variables, max size 100
// c:count variable,containing array elements (product info)
//************************************************************************

void storeInventory(ShopInventory catalog[], int c)
{
    for (int i=0; i < c; i++)
    {
        cout << left << setw(8) << fixed << catalog[i].location
        << setw(8) << fixed << catalog[i].quantity
        << setprecision(2) << setw(10) << catalog[i].price
        << setw(30) << catalog[i].productName << endl;
    }
    cout << endl;
}

//************************************************************************
// bubbleSort: Bubble Sort code that compares product information in the
//             array with products being inputted, and sorts each product
//             alphebetically by name, this sort enables the user
//             to perform the binary search
//
// catalog: Array of struct with 4 variables, max size 100
// c:count variable,containing array elements (product info)
//************************************************************************

void bubbleSort(ShopInventory catalog[], int c)
{
    bool swap;
    ShopInventory temp;

    do
    {
        swap=false;
        for (int i = 0; i < (c-1); i++)
        {
            if (catalog[i].productName > catalog[i+1].productName)
            {
                temp = catalog[i];
                catalog[i] = catalog[i+1];
                catalog[i+1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

//************************************************************************
// binarySearch: Binary Search code that searches through an already
//               sorted inventory for a products full information after
//               being given the name by a user
//
// catalog: Array of struct with 4 variables, size 100
// n: A product name passed from multiple functions, used to find all of
//    a products information
// c:count variable, containing array elements (product info)
// returns: The position of the data,for an item, in the array
//************************************************************************

int binarySearch (ShopInventory catalog[], string n, int c)
{
 int first = 0;      //index of beginning of searchlist

    int last = c-1;     //index of end of search list

    int middle;         //index of midpoint of search list

    int position = -1;  //position of target value

    bool found = false; //flag



    while (!found && first <= last )

    {

        middle = (first + last)/2;      //calculuate midpoint



        if (catalog[middle].productName == n)

        {

            found = true;

            position = middle;

        }



        else if (catalog[middle].productName > n)

            last = middle-1;            //search list = lower half

        else

            first = middle + 1;         //search list = upper half

    }

    return (position);

}

