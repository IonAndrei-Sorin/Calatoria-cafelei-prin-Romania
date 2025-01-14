#ifndef CSV_ORDER_H
#define CSV_ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "CSV_Importer.h"
#include "CSV_Exporter.h"
#include "Product.h"
#include "User.h"

using namespace std;

class Order
{
    private:
        string userName;
        string orderDate;
        string order;
        string quantity;
        float total;

    public:
        // Default constructor
        Order();
        // Constructor without cost
        Order(string name, string date, string userOrder, string orderQuantity);
        // Constructor
        Order(string name, string date, string userOrder, string orderQuantity, float cost);

        // Getters
        string getUserName() const;
        string getOrderDate() const;
        string getOrder() const;
        string getQuantity() const;
        float getTotal() const;

        // Setters
        void setUserName(string name);
        void setOrderDate(string date);
        void setOrder(string userOrder);
        void setQuantity(string quantity);
        void setTotal(float cost);

        // Methods
        // Is Loyal
        int isLoyal(const string& filePath, string name, int ID);  
        // Add order
        void addOrder(vector<Order>& orders, const string& filePath);
        // Delete order
        void deleteOrder(vector<Order>& orders, const string& filePath, string name, string date); // Use the date to delete the orders of said date
        // Calculate total cost
        void calculateTotalCost(vector<Order>& orders, const string& productPath,const string& orderPath, string userName, string date);
        // Calculate total quantity
        int calculateTotalQuantity(vector<Order>& orders, const string& orderPath, string userName);
};

#endif // CSV_ORDER_H
