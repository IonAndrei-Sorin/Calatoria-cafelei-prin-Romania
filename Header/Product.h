#ifndef CSV_PRODUCT_H
#define CSV_PRODUCT_H

#include "CSV_Exporter.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Product
{
    public:
        string name;
        float price;
        float cost;
        int stock;
    
    public:
        // Default constructor
        Product();
        // Constructor
        Product(string name, float price, float cost, int stock);

        // Getters
        string getName() const;
        float getPrice() const;
        float getCost() const;
        int getStock() const;

        // Setters
        void setName(string name);
        void setPrice(float price);
        void setCost(float cost);
        void setStock(int stock);

        // Methods

        // Add product
        void addProduct(vector<Product>& products, const string& filePath);
        // Delete product
        void deleteProduct(vector<Product>& products, string name, const string& filePath);
        // Update product stock
        void updateStock(vector<Product>& products, const string& filePath, string name);
};

#endif // CSV_PRODUCT_H