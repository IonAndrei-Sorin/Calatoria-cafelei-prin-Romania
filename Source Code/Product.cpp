#include "../Header/Product.h"

// Default constructor
Product::Product()
{
    name = "";
    price = 0;
    cost = 0;
    stock = 0;
}
// Constructor
Product::Product(string name, float price, float cost, int stock)
{
    this->name = name;
    this->price = price;
    this->cost = cost;
    this->stock = stock;
}

// Getters
string Product::getName() const
{
    return name;
}

float Product::getPrice() const
{
    return price;
}

float Product::getCost() const
{
    return cost;
}

int Product::getStock() const
{
    return stock;
}

// Setters
void Product::setName(string name)
{
    this->name = name;
}

void Product::setPrice(float price)
{
    this->price = price;
}

void Product::setCost(float cost)
{
    this->cost = cost;
}

void Product::setStock(int stock)
{
    this->stock = stock;
}

// Methods
// Add product
void Product::addProduct(vector<Product>& products, const string& filePath)
{
    // Add product to vector
    products.push_back(*this);
    
    // Add product to csv
    ProductExport<Product> productExporter;
    productExporter.addProduct(filePath, *this);
}

// Delete product
void Product::deleteProduct(vector<Product>& products, string name, const string& filePath)
{
    // Find product by name
    auto it = find_if(products.begin(), products.end(), [&name](const Product& product) { return product.name == name; });

    if (it!=products.end())
    {
        products.erase(it);

        // Delete product from csv
        ProductExport<Product> productExporter;
        productExporter.export2CSV(filePath, products);
    }
    else
    {
        cerr << "Error: Product not found.\n";
    }
}

// Update product stock
void Product::updateStock(vector<Product>& products, const string& filePath, string name)
{
    // Update product stock in vector
    for (auto& product : products)
    {
        if (product.getName() == name)
        {
            int stockDiff = product.getStock() - 1;
            product.setStock(stockDiff);
            break;
        }
    }

    // Update product stock in csv
    ProductExport<Product> productExporter;
    productExporter.export2CSV(filePath, products);
}

