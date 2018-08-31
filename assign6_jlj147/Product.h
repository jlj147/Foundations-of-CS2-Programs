// File Name: Product.h
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

#include <string>
using namespace std;

class Product
{
private:
    string productName;       // product description
    string locator;           // location of product in store
    int quantity;             // number of copies in inventory
    double price;             // selling price of the product
    
public:
    Product();
    Product(string,int,double,string);
    
    string getLocator();
    int getQuantity();
    double getPrice();
    string getProductName();
    
    void setLocator(string);
    void setQuantity(int);
    void setPrice(double);
    void setProductName(string);
    
    bool isEqual(Product);
    bool greaterThan(Product);
};
