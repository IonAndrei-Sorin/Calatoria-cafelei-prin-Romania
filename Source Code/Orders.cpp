#include "../Header/Orders.h"

// Default constructor
Order::Order()
{
    userName = "";
    orderDate = "";
    order = "";
    quantity = "";
    total = 0;
}
// Constructor without cost
Order::Order(string name, string date, string userOrder, string orderQuantity)
{
    userName = name;
    orderDate = date;
    order = userOrder;
    quantity = orderQuantity;
    total = 0;
}
// Constructor
Order::Order(string name, string date, string userOrder, string orderQuantity,float cost)
{
    userName = name;
    orderDate = date;
    order = userOrder;
    quantity = orderQuantity;
    total = cost;
}

// Getters
string Order::getUserName() const
{
    return userName;
}

string Order::getOrderDate() const
{
    return orderDate;
}

string Order::getOrder() const
{
    return order;
}

string Order::getQuantity() const
{
    return quantity;
}

float Order::getTotal() const
{
    return total;
}

// Setters
void Order::setUserName(string name)
{
    userName = name;
}

void Order::setOrderDate(string date)
{
    orderDate = date;
}

void Order::setOrder(string userOrder)
{
    order = userOrder;
}

void Order::setQuantity(string quantity)
{
    this->quantity = quantity;
}

void Order::setTotal(float cost)
{
    total = cost;
}

// Methods
// Is Loyal
int Order::isLoyal(const string& filePath, string name, int ID)
{
    vector<User> users;
    LoyalUsersCSV<User> userImporter;
    userImporter.importCSV(filePath, users);

    for (const auto& user : users)
    {
        if (user.getName() == name && user.getID() == ID)
        {
            return 1;
        }
    }

    return 0;
}

// Add order
void Order::addOrder(vector<Order>& orders, const string& filePath)
{
    // Add order to vector
    orders.push_back(*this);

    // Add order to csv
    OrderExport<Order> orderExporter;
    orderExporter.export2CSV(filePath, orders);
}

// Delete order
void Order::deleteOrder(vector<Order>& orders, const string& filePath, string name,string date)
{
    auto it = find_if(orders.begin(), orders.end(), [&name, &date](const Order& order) { return order.getUserName() == name && order.getOrderDate() == date; });

    // Delete order from vector
    if(it != orders.end())
    {
        orders.erase(it);

        // Delete order from csv
        OrderExport<Order> orderExporter;
        orderExporter.export2CSV(filePath, orders);
    }
}

// Calculate total cost
void Order::calculateTotalCost(vector<Order>& orders, const string& productPath, const string& orderPath, string userName, string date)
{
    // Find the order of the user
    for (auto it = orders.begin(); it != orders.end(); ++it)    
    {
        if (it->getUserName() == userName && it->getOrderDate() == date)
        {
            float totalCost = 0;
            int contor = 0;

            //Import products vector
            vector<Product> products;
            ProductCSV<Product> productImporter;

            productImporter.importCSV(productPath, products);

            // Take the products of the order string and split them by ';'   
            vector<string> orderProducts;         
            stringstream ss(it->getOrder());
            string token;
            while (getline(ss, token, ';'))
            {
                orderProducts.push_back(token);
            }

            // Take the quantities of the quantity string and split them by ';'
            vector<string> orderQuantities;
            stringstream ss2(it->getQuantity());
            string token2;
            while (getline(ss2, token2, ';'))
            {
                orderQuantities.push_back(token2);
            }

            for(const auto& orderProduct: orderProducts)
            {
                vector<Product> products;
                ProductCSV<Product> productImporter;
                productImporter.importCSV(productPath, products);

                for(auto& product: products)
                {
                    if(product.getName() == orderProduct)
                    {
                        // Take the i element of the product vector and multiply it with the i element of the quantity vector
                        totalCost += product.getPrice() * stoi(orderQuantities[contor]);
                        int currStock = product.getStock() - 1;
                        contor++;
                    }

                    //Update stock
                    product.updateStock(products, productPath, product.getName());
                }
            }


            it->setTotal(totalCost);
        }  

    }
}

// Calculate total quantity
int Order::calculateTotalQuantity(vector<Order>& orders, const string& orderPath, string userName)
{
    int totalQuantity = 0;

    for (const auto& order : orders)
    {
        if (order.getUserName() == userName)
        {
            vector<string> orderQuantities;
            stringstream ss(order.getQuantity());
            string token;
            while (getline(ss, token, ';'))
            {
                orderQuantities.push_back(token);
            }

            for (const auto& quantity : orderQuantities)
            {
                totalQuantity += stoi(quantity);
            }
        }
    }

    return totalQuantity;
}