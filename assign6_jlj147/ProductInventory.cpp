// File Name: ProductInventory.cpp
//
// Author: Jayce Jones
// Date: 04/08/2016
// Assignment Number: 6
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// Represents the inventory of a small store
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.

#include <iostream>
#include <cstddef>

#include "ProductInventory.h"

using namespace std;

//***********************************************************
// ProductInventory: Constructor that creats an empty list
//***********************************************************
ProductInventory::ProductInventory()
{
    productList = NULL; //sets the head pointer equal to NULL
}

//*********************************************************************
// ~ProdcutInventory: Destructor that deallocates all the node in the list
//*********************************************************************
ProductInventory::~ProductInventory()
{
    ProductNode *p = productList; //Create pointer and
                                 //set it equal to the head pointer
    ProductNode *n;              //Pointer to traverse the list
    while (p != NULL)
    {
        n = p -> next;  //Saves address of next node
        delete p;
        p = n;          //Point p to next node
    }
}

//*******************************************************************
// addProduct: Attempts to add a product to the inventory by the list.
//             Ensures that the product being added is unique by name and
//             location, and that price and quantity are valid. If the
//             error check is passed the product is added
// newProduct: Holds name, price, quantity, and location for the product to be
//             added returns true if the product is successfully
//             added to inventory, and false if it is not
//*******************************************************************
bool ProductInventory::addProduct(Product newProduct)
{
    ProductNode *n;     //Pointer created for error check
    n = productList;    //Pointer set equal to head pointer
    ProductNode *newNode;   //Pointer created to point to the product being
                            //passed in
    
    //Allocating the new node
    newNode = new ProductNode;
    newNode -> data = newProduct;
    newNode -> next = NULL;
    
    //Validation
    while (n)
    {
        if(newProduct.isEqual(n->data) == true || newProduct.getQuantity() < 0
           || newProduct.getPrice() < 0)
        {
            return false;
        }
        n = n-> next;
    }
    
    //If head pointer is NULL, create a node between them
    if (productList==NULL)
    {
        productList = newNode;
    }
    
    //Else add the node to the list
    else
    {
        ProductNode *p = productList;
        
        while(p->next != NULL)
        {
            p = p -> next;
        }
        p -> next = newNode;
    }
    return true;
}

//***************************************************************************
// removeProduct: Takes a product name and locator and if that product is
//                found in inventory, removes the entire product
// name:The name of the product to be removed, passed in from driver or sort
//      function
// location: The locator of the the product that is to be removed, passed in
//           from driver or sort function
// returns true if the product is successfully removed from inventory, and false
// if it is not
//***************************************************************************
bool ProductInventory::removeProduct(string name, string location)
{
    ProductNode *p = productList; //Create pointer to traverse the list and
                                 //set it equal to the head pointer
    ProductNode *n = nullptr; //Pointer to traverse the list
    
    //skip nodes that are not equal to name and location
    while (p != NULL && (p->data.getProductName() != name
                         || p->data.getLocator() != location))
    {
        n = p;
        p = p -> next;
    }
    
    //If the list is empty of the product is not in the list
    if (p==NULL)
    {
        return false;
    }
    
    //if p is not null: the product name and locator were found
    if (p != NULL)
    {
        if (p==productList) //p points to the first element
        {
            productList = p ->next;
            delete p;
        }
        else
        {
            n->next = p->next;
            delete p;
        }
    }
    return true;
}

//*******************************************************************
// showInventory: Displays the information for each product that has been
//                added to the inventory, one product per line
//*******************************************************************

void ProductInventory::showInventory()
{
    ProductNode *p;  //Pointer to traverse the list
    p = productList; //Set pointer equal to head pointer
    
    while (p) //While p is pointing to a node
    {
        cout << p->data.getLocator() << " ";
        cout << p->data.getQuantity() << " ";
        cout << p->data.getPrice() << " ";
        cout << p->data.getProductName() << " ";
        p = p->next;
        cout << endl;
    }
}

//***************************************************************************
// getTotalQuantity: Sums the total quantity of products in inventory
//
// returns the total number of units of all the products in the inventory
//***************************************************************************
int ProductInventory::getTotalQuantity()
{
    int total = 0; //accumulates quantities
    ProductNode *p; //pointer to traverse the list
    p=productList; //set pointer to head pointer
    while (p)
    {
        total += p -> data.getQuantity();
        p = p -> next;
    }
    return total;
}

//***************************************************************************
// sortInventory: Reorders the products in the list to be alphebetical, this is
//                using the findMinimum function and the removeProduct function
//***************************************************************************
void ProductInventory::sortInventory()
{
    Product min; //variable to hold the minimum product found
    ProductNode *newHead; //Creating a new pointer
    ProductNode *copyNode; //Creating another pointer
    ProductNode *p; //Pointer to traverse the list
    newHead = NULL;
    
    while(productList)
    {
        min = findMinimum(); //Call to find minimum
        
        //Allocating the new node
        copyNode = new ProductNode;
        copyNode -> data = min;
        copyNode -> next = NULL;
        
        //If pointer is pointing to an empty list or the final value, create
        //a new node and remove the data that was previously in it
        if (newHead == NULL)
        {
            newHead = copyNode;
            removeProduct(min.getProductName(),min.getLocator());
        }
        
        //Else traverse the list
        else
        {
            p = newHead;
            
            while (p->next)
            {
                p = p -> next;
            }
        
        p -> next = copyNode;
        removeProduct(min.getProductName(), min.getLocator());
        }
    }
    productList = newHead;
}

//***************************************************************************
// findMinimum: Returns the minimum product in the list, using the greater
//              greaterThan function to compare name and location
//  returns the minimum product found, that which comes first alphabetically
//***************************************************************************
Product ProductInventory::findMinimum()
{
    Product min; //variable to hold the minimum product found
    ProductNode *p;
    p = productList;
    min = productList->data; //Set min to read in lists
    
    //If min has read all nodes or finds no nodes, then return the min product
    if (productList == NULL)
    {
        return min;
    }
    
    //While p is pointing to something keep reading lists, and if a new minimum
    //is found assign it to the min variable
    while(p)
    {
        if(min.greaterThan(p->data))
        {
               min = p -> data;
        }
        p = p -> next;
    }
    return min;
}
