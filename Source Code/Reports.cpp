#include "../Header/Reports.h"

// Default constructor
Report::Report()
{
    date = "";
    productsSold = 0;
    productsCost = 0;
    salaryCost = 0;
    totalCost = 0;
    income = 0;
    profit = 0;
}
// Constructor
Report::Report(string date, int productsSold, float productsCost, float salaryCost, float totalCost, float income, float profit)
{
    this->date = date;
    this->productsSold = productsSold;
    this->productsCost = productsCost;
    this->salaryCost = salaryCost;
    this->totalCost = totalCost;
    this->income = income;
    this->profit = profit;
}

// Getters
string Report::getDate() const
{
    return date;
}

int Report::getProductsSold() const
{
    return productsSold;
}

float Report::getProductsCost() const
{
    return productsCost;
}

float Report::getSalaryCost() const
{
    return salaryCost;
}

float Report::getTotalCost() const
{
    return totalCost;
}

float Report::getIncome() const
{
    return income;
}

float Report::getProfit() const
{
    return profit;
}

// Setters
void Report::setDate(string date)
{
    this->date = date;
}

void Report::setProductsSold(int productsSold)
{
    this->productsSold = productsSold;
}

void Report::setProductsCost(float productsCost)
{
    this->productsCost = productsCost;
}

void Report::setSalaryCost(float salaryCost)
{
    this->salaryCost = salaryCost;
}

void Report::setTotalCost(float totalCost)
{
    this->totalCost = totalCost;
}

void Report::setIncome(float income)
{
    this->income = income;
}

void Report::setProfit(float profit)
{
    this->profit = profit;
}

// Methods

void Report::addReport(vector<Report>& reports, const string& reportPath)
{
    // Add report to vector
    reports.push_back(*this);

    // Add report to CSV file
    ReportExport<Report> reportExporter;
    reportExporter.addReport(reportPath, reports.back());
}

void Report::deleteReport(vector<Report>& reports, const string& reportPath, string date)
{
    // Find report by date
    auto it = find_if(reports.begin(), reports.end(), [&date](const Report& report) { return report.date == date; });

    // If report is found
    if (it != reports.end())
    {
        // Delete report from vector
        reports.erase(it);

        // Export updated vector to csv
        ReportExport<Report> reportExporter;
        reportExporter.export2CSV(reportPath, reports);
    }
    else
    {
        cerr << "Error: Report not found.\n";
    }
}

void Report::calculateProductsSold(vector<Report>& reports, const string& orderPath, string date)
{
    // Find the orders of the date
    vector<Order> orders;
    OrderCSV<Order> orderImporter;

    orderImporter.importCSV(orderPath, orders);

    int totalProductsSold = 0;

    for (const auto& order : orders)
    {
        if (order.getOrderDate() == date)
        {
            // Take the quantities of the quantity string and split them by ';'
            vector<string> orderQuantities;
            stringstream ss2(order.getQuantity());
            string token2;
            while (getline(ss2, token2, ';'))
            {
                totalProductsSold += stoi(token2);
            }
        }
    }

    // Set the total products sold
    setProductsSold(totalProductsSold);
}

float Report::calculateProductsCost(vector<Report>& reports, const string& orderPath, const string& productPath, string date)
{
    // Find the orders of the date
    vector<Order> orders;
    OrderCSV<Order> orderImporter;

    orderImporter.importCSV(orderPath, orders);

    float totalProductsCost = 0;

    for (const auto& order : orders)
    {
        if (order.getOrderDate() == date)
        {
            // Take the products of the order string and split them by ';'
            vector<string> orderProducts;
            stringstream ss(order.getOrder());
            string token;
            while (getline(ss, token, ';'))
            {
                orderProducts.push_back(token);
            }

            // Take the quantities of the quantity string and split them by ';'
            vector<string> orderQuantities;
            stringstream ss2(order.getQuantity());
            string token2;
            while (getline(ss2, token2, ';'))
            {
                orderQuantities.push_back(token2);
            }

            // Import products vector
            vector<Product> products;
            ProductCSV<Product> productImporter;

            productImporter.importCSV(productPath, products);

            for (const auto& orderProduct : orderProducts)
            {
                int i = 0;
                for (const auto& product : products)
                {
                    if (product.getName() == orderProduct)
                    {
                        // Take the i element of the product vector and multiply it with the i element of the quantity vector
                        totalProductsCost += product.getCost() * stoi(orderQuantities[i]);
                        i++;
                    }
                }
            }
        }
    }

    // Set the total products cost
    setProductsCost(totalProductsCost);

    return totalProductsCost;
}

float Report::calculateSalaryCost(vector<Report>& reports, const string& workerPath)
{
    // Find the workers
    vector<Worker> workers;
    WorkerCSV<Worker> workerImporter;

    workerImporter.importCSV(workerPath, workers);

    float totalSalaryCost = 0;

    for (const auto& worker : workers)
    {
        totalSalaryCost += worker.getSalary()/30;
    }

    // Set the total salary cost
    setSalaryCost(totalSalaryCost);

    return totalSalaryCost;
}

float Report::calculateTotalCost(vector<Report>& reports, const string& orderPath, const string& workerPath, const string& productPath, string date)
{
    // Calculate the total products cost
    float totalProductsCost = calculateProductsCost(reports, orderPath, productPath, date);

    // Calculate the total salary cost
    float totalSalaryCost = calculateSalaryCost(reports, workerPath);

    // Calculate the total cost
    float totalCost = totalProductsCost + totalSalaryCost;

    // Set the total cost
    setTotalCost(totalCost);

    return totalCost;
}

float Report::calculateTotalIncome(vector<Report>& reports, const string& orderPath, string date)
{
    // Find the orders of the date
    vector<Order> orders;
    OrderCSV<Order> orderImporter;

    orderImporter.importCSV(orderPath, orders);

    float totalIncome = 0;

    for (const auto& order : orders)
    {
        if (order.getOrderDate() == date)
        {
            totalIncome += order.getTotal();
        }
    }

    // Set the total income
    setIncome(totalIncome);

    return totalIncome;
}

float Report::calculateProfit(vector<Report>& reports, const string& orderPath, const string& workerPath, const string& productPath,string date)
{
    // Calculate the total income
    float totalIncome = calculateTotalIncome(reports, orderPath, date);

    // Calculate the total cost
    float totalCost = calculateTotalCost(reports, orderPath, workerPath, productPath, date);

    // Calculate the profit
    float profit = totalIncome - totalCost;

    // Set the profit
    setProfit(profit);

    return profit;
}

// Facade
// Report Facade Default constructor
ReportFacade::ReportFacade()
{
    report = Report();
    reportPath = "";
    orderPath = "";
    workerPath = "";
    productPath = "";
}
// Pentru a crea reportul trebuie sa apelam doar metoda calculateProductSold si calculateProfit, deoarece calculateProfit apeleaza metodele ramase
void ReportFacade::createReport(vector<Report>& reports, string location, string date)
{
    // Find the paths by location
    PathFinder pathFinder;
    string reportPath = pathFinder.getPath("Reports", location);
    string orderPath = pathFinder.getPath("Orders", location);
    string workerPath = pathFinder.getPath("Workers", location);
    string productPath = pathFinder.getPath("Products", location);
    string retrocede = "../";
    
    // Update paths 
    reportPath = retrocede + reportPath;
    orderPath = retrocede + orderPath;
    workerPath = retrocede + workerPath;
    productPath = retrocede + productPath;

    // Create the report
    Report report(date, 0, 0, 0, 0, 0, 0);

    // Calculate the products sold
    report.calculateProductsSold(reports, orderPath, date);

    // Calculate the profit
    report.calculateProfit(reports, orderPath, workerPath, productPath, date);

    // Add the report
    report.addReport(reports, reportPath);

}