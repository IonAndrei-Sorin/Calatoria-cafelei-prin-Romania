#include "../Header/Menu.h"

void LocationMenu()
{
    int option;
    bool running = true;

    while (running)
    {
        cout << "\tLocations" << endl;
        cout << "1. Bucuresti" << endl;
        cout << "2. Brasov" << endl;
        cout << "3. Cluj-Napoca" << endl;
        cout << "4. Timisoara" << endl;
        cout << "5. Iasi" << endl;
        cout << "6. Exit" << endl;

        cout << "Choose a location: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            StartMenu("Bucuresti");
            break;
        case 2:
            system("cls");
            StartMenu("Brasov");
            break;
        case 3:
            system("cls");
            StartMenu("Cluj-Napoca");
            break;
        case 4:
            system("cls");
            StartMenu("Timisoara");
            break;
        case 5:
            system("cls");
            StartMenu("Iasi");
            break;
        case 6:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}

void StartMenu(string location)
{
    int option;
    bool running = true;

    while (running)
    {
        cout << "\t" << location << " Menu" << endl;
        cout << "1. Manager" << endl;
        cout << "2. User" << endl;
        cout << "3. Return to previous menu" << endl;
        cout << "4. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            ManagerMenu(location);
            break;
        case 2:
            system("cls");
            UserMenu(location);
            break;
        case 3:
            system("cls");
            return;
            break;
        case 4:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}


    /// Manager menu and submenus
// Manager menu
void ManagerMenu(string location)
{
    int option;
    bool running = true;

    while (running)
    {
        cout << "\tManager" << endl;
        cout << "1. Workers" << endl;
        cout << "2. Products" << endl;
        cout << "3. Special Events" << endl;
        cout << "4. Reports" << endl;
        cout << "5. Return to previous menu" << endl;
        cout << "6. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            WorkerMenu(location);
            break;
        case 2:
            system("cls");
            ProductMenu(location);
            break;
        case 3:
            system("cls");
            SpecialEventMenu(location);
            break;
        case 4:
            system("cls");
            ReportMenu(location);
            break;
        case 5:
            system("cls");
            return;
            break;
        case 6:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}
    // Worker submenus
// Add worker
void AddWorker(string location)
{
    // Find worker path
    PathFinder path;
    string workerPath = path.getPath("Workers", location);
    string initialPath = "../";
    workerPath = initialPath + workerPath;


    string name, role, shiftStart, shiftEnd;
    float salary;

    cout << "Enter worker name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter worker role: ";
    cin >> role;
    cout << "Enter worker shift start: ";
    cin >> shiftStart;
    cout << "Enter worker shift end: ";
    cin >> shiftEnd;
    cout << "Enter worker salary: ";
    cin >> salary;

    vector<Worker> workers;
    Worker worker(name, role, shiftStart, shiftEnd, salary);

    worker.addWorker(workers, workerPath);
}

// See workers
void SeeWorkers(string location)
{
    // Find worker path
    PathFinder path;
    string workerPath = path.getPath("Workers", location);
    string initialString = "../";
    workerPath = initialString + workerPath;

    vector<Worker> workers;
    WorkerCSV<Worker> workerImporter;
    workerImporter.importCSV(workerPath, workers);

    cout << "\tWorkers" << endl;
    cout << left << setw(20) << "Name" << setw(20) << "Role" << setw(20) << "Shift Start" << setw(20) << "Shift End" << setw(20) << "Salary" << endl;
    for (const auto& worker : workers)
    {
        cout << left << setw(20) << worker.getName() << setw(20) << worker.getRole() << setw(20) << worker.getShiftStart() << setw(20) << worker.getShiftEnd() << setw(20) << worker.getSalary() << endl;
    }
}

// Delete worker
void DeleteWorker(string location)
{
    // Find worker path
    PathFinder path;
    string workerPath = path.getPath("Workers", location);
    string initialPath = "../";
    workerPath = initialPath + workerPath;
    
    // See workers
    SeeWorkers(location);

    // Get the worker name
    string name;
    cout << "Enter the name of the worker you want to delete: ";
    cin.ignore();
    getline(cin, name);

    // Read workers from file
    vector<Worker> workers;
    WorkerCSV<Worker> workerImporter;
    workerImporter.importCSV(workerPath, workers);

    // Delete worker
    Worker worker;
    worker.deleteWorker(workers, name, workerPath);

    // Print task completed
    cout << "Worker deleted!" << endl;
}

// Change shift
void ChangeShift(string location)
{
    // Find worker path
    PathFinder path;
    string workerPath = path.getPath("Workers", location);
    string initialPath = "../";
    workerPath = initialPath + workerPath;

    // Read workers from file
    vector<Worker> workers;
    WorkerCSV<Worker> workerImporter;
    workerImporter.importCSV(workerPath, workers);

    // See workers
    SeeWorkers(location);

    // Get the worker name
    string name;

    cout << "Enter the name of the worker you want to change the shift: ";
    cin.ignore();
    getline(cin, name);

    // Get the shift changes
    string shiftStart, shiftEnd;
    cout << "Enter the new shift start: ";
    cin >> shiftStart;
    cout << "Enter the new shift end: ";
    cin >> shiftEnd;

    // Change shift
    Worker worker;
    worker.changeShift(workers, name, workerPath, shiftStart, shiftEnd);

    // Print task completed
    cout << "Shift changed!" << endl;
}
    // worker main menu
void WorkerMenu(string location)
{ 
    int option;
    bool running = true;

    while (running)
    {   
        cout << "\tWorkers" << endl;
        cout << "1. Add Worker" << endl;
        cout << "2. See Workers" << endl;
        cout << "3. Delete Worker" << endl;
        cout << "4. Change Shift" << endl;
        cout << "5. Return to previous menu" << endl;
        cout << "6. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            // Add worker
            AddWorker(location);

            break;
        case 2:
            system("cls");
            SeeWorkers(location);
            break;
        case 3:
            system("cls");
            DeleteWorker(location);
            break;
        case 4:
            system("cls");
            ChangeShift(location);
            break;
        case 5:
            system("cls");
            return;
            break;
        case 6:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}
    // Product submenus
void AddProduct(string location)
{   
    // Find product path
    PathFinder path;
    string productPath = path.getPath("Products", location);
    string initialPath = "../";
    productPath = initialPath + productPath;

    string name;
    float price, cost;
    int stock;

    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter product cost: ";
    cin >> cost;
    cout << "Enter product stock: ";
    cin >> stock;

    vector<Product> products;
    Product product(name, price, cost, stock);

    product.addProduct(products, productPath);
}

// See products
void SeeProducts(string location)
{
    // Find product path
    PathFinder path;
    string productPath = path.getPath("Products", location);
    string initialPath = "../";
    productPath = initialPath + productPath;

    vector<Product> products;
    ProductCSV<Product> productImporter;
    productImporter.importCSV(productPath, products);

    cout << "\tProducts" << endl;
    cout << left << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Cost" << setw(10) << "Stock" << endl;
    for (const auto& product : products)
    {
        cout << left << setw(20) << product.getName() << setw(10) << product.getPrice() << setw(10) << product.getCost() << setw(10) << product.getStock() << endl;
    }
}

// Delete product
void DeleteProduct(string location)
{
    // Find product path
    PathFinder path;
    string productPath = path.getPath("Products", location);
    string initialPath = "../";
    productPath = initialPath + productPath;

    // See products
    SeeProducts(location);

    // Get the product name
    string name;

    cout << "Enter the name of the product you want to delete: ";
    cin.ignore();
    getline(cin, name);

    // Read products from file
    vector<Product> products;
    ProductCSV<Product> productImporter;
    productImporter.importCSV(productPath, products);

    // Delete product
    Product product;
    product.deleteProduct(products, name, productPath);
}
    // Special Events submenus
    /// Produt main menu
void ProductMenu(string location)
{
    int option;
    bool running = true;

    while (running)
    {
        cout << "\tProducts" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. See Products" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Return to previous menu" << endl;
        cout << "5. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            // Add product
            AddProduct(location);
            break;
        case 2:
            system("cls");
            // See products
            SeeProducts(location);
            break;
        case 3:
            system("cls");
            // Delete product
            DeleteProduct(location);
            break;
        case 4:
            system("cls");
            return;
            break;
        case 5:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}

    // Special Events submenus
// Add special event
void AddSpecialEvent(string location)
{
    // Find special event path
    PathFinder path;
    string specialEventPath = path.getPath("Events", location);
    string initialPath = "../";
    specialEventPath = initialPath + specialEventPath;

    string name, date;
    float cost;

    cout << "Enter special event name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter special event date: ";
    cin >> date;
    cout << "Enter special event cost: ";
    cin >> cost;

        // Calculate event income
    float income = 0;
    // Find report path
    string reportPath = path.getPath("Reports", location);
    reportPath = initialPath + reportPath;

    // Find the report by date
    vector<Report> reports;
    ReportCSV<Report> reportImporter;
    reportImporter.importCSV(reportPath, reports);

    for (const auto& report : reports)
    {
        if (report.getDate() == date)
        {
            income = report.getIncome();
        }
    }
    

    vector<SpecialEvent> specialEvents;
    SpecialEvent specialEvent(name, date, cost, income);

    specialEvent.addSpecialEvent(specialEvents, specialEventPath);
}

// See special events
void SeeSpecialEvents(string location)
{
    // Find special event path
    PathFinder path;
    string specialEventPath = path.getPath("Events", location);
    string initialPath = "../";
    specialEventPath = initialPath + specialEventPath;

    vector<SpecialEvent> specialEvents;
    SpecialEventCSV<SpecialEvent> specialEventImporter;
    specialEventImporter.importCSV(specialEventPath, specialEvents);

    cout << "\tSpecial Events" << endl;
    cout << left << setw(30) << "Name" << setw(30) << "Date" << setw(20) << "Cost" << setw(10) << "Income" << endl;
    for (const auto& specialEvent : specialEvents)
    {
        cout << left << setw(30) << specialEvent.getEventName() << setw(30) << specialEvent.getDate() << setw(20) << specialEvent.getCost() << setw(10) << specialEvent.getIncome() << endl;
    }
}

// Delete special event
void DeleteSpecialEvent(string location)
{
    // Find special event path
    PathFinder path;
    string specialEventPath = path.getPath("Events", location);
    string initialPath = "../";
    specialEventPath = initialPath + specialEventPath;

    // See special events
    SeeSpecialEvents(location);

    // Get the special event name
    string name;
    cout << "Enter the name of the special event you want to delete: ";
    cin.ignore();
    getline(cin, name);

    // Read special events from file
    vector<SpecialEvent> specialEvents;
    SpecialEventCSV<SpecialEvent> specialEventImporter;
    specialEventImporter.importCSV(specialEventPath, specialEvents);

    // Delete special event
    SpecialEvent specialEvent;
    specialEvent.deleteSpecialEvent(specialEvents, name, specialEventPath);
}

    // Special Events main menu
void SpecialEventMenu(string location)
{
    int option;
    bool running = true;

    while (running)
    {
        cout << "\tSpecial Events" << endl;
        cout << "1. Add Special Event" << endl;
        cout << "2. See Special Events" << endl;
        cout << "3. Delete Special Event" << endl;
        cout << "4. Return to previous menu" << endl;
        cout << "5. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            // Add special event
            AddSpecialEvent(location);
            break;
        case 2:
            system("cls");
            // See special events
            SeeSpecialEvents(location);
            break;
        case 3:
            system("cls");
            // Delete special event
            DeleteSpecialEvent(location);
            break;
        case 4:
            system("cls");
            return;
            break;
        case 5:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}

    // Report submenus
// Generate report
void GenerateReport(string location)
{
    // Find report path
    PathFinder path;
    string reportPath = path.getPath("Reports", location);
    string initialPath = "../";
    reportPath = initialPath + reportPath;

    string date;

    cout << "Enter report date: ";
    cin >> date;

    vector<Report> reports;
    ReportFacade createReport;
    createReport.createReport(reports, location, date);
}

// See reports
void SeeReports(string location)
{
    // Find report path
    PathFinder path;
    string reportPath = path.getPath("Reports", location);
    string initialPath = "../";
    reportPath = initialPath + reportPath;

    vector<Report> reports;
    ReportCSV<Report> reportImporter;
    reportImporter.importCSV(reportPath, reports);

    cout << "\tReports" << endl;
    cout << left << setw(20) << "Date" << setw(20) << "Products Sold" << setw(20) << "Products Cost" << setw(20) << "Salary Cost" << setw(20) << "Total Cost" << setw(10) << "Income" << setw(10) << "Profit" << endl;
    for (const auto& report : reports)
    {
        cout << left << setw(20) << report.getDate() << setw(20) << report.getProductsSold() << setw(20) << report.getProductsCost() << setw(20) << report.getSalaryCost() << setw(20) << report.getTotalCost() << setw(10) << report.getIncome() << setw(10) << report.getProfit() << endl;
    }
}

// Delete report
void DeleteReport(string location)
{
    // Find report path
    PathFinder path;
    string reportPath = path.getPath("Reports", location);
    string initialPath = "../";
    reportPath = initialPath + reportPath;

    // See reports
    SeeReports(location);

    // Get the report date
    string date;
    cout << "Enter the date of the report you want to delete: ";
    cin >> date;

    // Read reports from file
    vector<Report> reports;
    ReportCSV<Report> reportImporter;
    reportImporter.importCSV(reportPath, reports);

    // Delete report
    Report report;
    report.deleteReport(reports, reportPath, date);
}

    // Report main menu 
void ReportMenu(string location)
{
    // Find report path
    PathFinder path;
    string reportPath = path.getPath("Reports", location);
    string initialPath = "../";
    reportPath = initialPath + reportPath;

    // Read reports from file
    vector<Report> reports;
    ReportCSV<Report> reportImporter;
    reportImporter.importCSV(reportPath, reports);

    int option;
    bool running = true;

    while (running)
    {
        cout << "\tReports" << endl;
        cout << "1. Generate Report" << endl;
        cout << "2. See Reports" << endl;
        cout << "3. Delete Report" << endl;
        cout << "5. Return to previous menu" << endl;
        cout << "4. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            // Generate report
            GenerateReport(location);
            break;
        case 2:
            system("cls");
            // See reports
            SeeReports(location);
            break;
        case 3:
            system("cls");
            // Delete report
            DeleteReport(location);
            break;
        case 4:
            system("cls");
            return;
            break;
        case 5:
            exit(0);
            break;
        default:
            system("cls");
            cout << "Invalid option!" << endl;
            break;
        }
    }
}

    /// User menus and submenus
// Get Date
string GetDate()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);

    string year = to_string(1900 + ltm->tm_year);
    string month = to_string(1 + ltm->tm_mon);
    string day = to_string(ltm->tm_mday);

    // test if the date have only 1 digit
    if (month.size() == 1)
    {
        month = "0" + month;
    }

    if (day.size() == 1)
    {
        day = "0" + day;
    }

    string date = year + "-" + month + "-" + day;

    return date;
}

// User menu    
void UserMenu(string location)
{
    int option;
    bool running = true;

    // Get the user name & the date
    string name, date;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    date = GetDate();

    system("cls");

    while (running)
    {
        cout << "\tUser" << endl;
        cout << "1. See Menu" << endl;
        cout << "2. Add to order" << endl;
        cout << "3. Delete from order" << endl;
        cout << "4. See order" << endl;
        cout << "5. Return to previous menu" << endl;
        cout << "6. Exit" << endl;

        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
            case 1:
                system("cls");
                // See menu
                SeeMenu(location);
                break;
            case 2:
                system("cls");
                // Add to order
                AddElementToOrder(name, date, location);
                break;
            case 3:
                system("cls");
                // Delete from order
                DeleteElementFromOrder(name, date, location);
                break;
            case 4:
                system("cls");
                // See order
                SeeOrder(name, date, location);
                FinishOrder(name, date, location);

                break;
            case 5:
                system("cls");
                return;
                break;
            case 6:
                exit(0);
                break;
        }
    }
}

// See menu
void SeeMenu(string location)
{
    // Find product path
    PathFinder path;
    string productPath = path.getPath("Products", location);
    string initialPath = "../";
    productPath = initialPath + productPath;

    vector<Product> products;
    ProductCSV<Product> productImporter;
    productImporter.importCSV(productPath, products);

    cout << "\tMenu" << endl;
    cout << left << setw(5) << "No." << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Stock" << endl;
    int contor = 1;
    for (const auto& product : products)
    {
        if(product.getStock() > 0)
        {
            cout << left << setw(5) << contor << setw(20) << product.getName() << setw(10) << product.getPrice() << setw(20) << "In stock" << endl;
        }
        else
        {
            cout << left << setw(5) << contor << setw(20) << product.getName() << setw(10) << product.getPrice() << setw(20) << "Out of stock" << endl;
        }
        contor++;
    }
}

// Add element to order
void AddElementToOrder(string name, string date, string location)
{
    // Find order path
    PathFinder path;
    string orderPath = path.getPath("Orders", location);
    string initialPath = "../";
    orderPath = initialPath + orderPath;

    // Find product path
    string productPath = path.getPath("Products", location);
    productPath = initialPath + productPath;

    int productNumber, quantity;

    SeeMenu(location);

    cout << "Enter the number of the product number: ";
    cin >> productNumber;
    cout << "Enter quantity: ";
    cin >> quantity;

        // Verify if the order already exists
    // Read orders from filed
    vector<Order> orders;
    OrderCSV<Order> orderImporter;
    orderImporter.importCSV(orderPath, orders);

    // Read products from file
    vector<Product> products;
    ProductCSV<Product> productImporter;
    productImporter.importCSV(productPath, products);

    int isFound = 0;

    // Add order
    for (auto order : orders)
    {
        if (order.getUserName() == name && order.getOrderDate() == date)
        {
            string newOrder = order.getOrder() + ";" + products[productNumber - 1].getName();
            string newQuantity = order.getQuantity() + ";" + to_string(quantity);

            Order order(name, date, newOrder, newQuantity);
            order.deleteOrder(orders, orderPath, name, date);
            order.addOrder(orders, orderPath);

            isFound = 1;

        }
    }    
    if(isFound == 0)
    {
        Order order(name, date, products[productNumber - 1].getName(), to_string(quantity));
        order.addOrder(orders, orderPath);
    }
}

// Delete element from order
void DeleteElementFromOrder(string name, string date, string location)
{
    // Find order path
    PathFinder path;
    string orderPath = path.getPath("Orders", location);
    string initialPath = "../";
    orderPath = initialPath + orderPath;

    // Find product path
    string productPath = path.getPath("Products", location);
    productPath = initialPath + productPath;

    int productNumber, quantity;

    // Print the order
    SeeOrder(name, date, location);

    cout << "Enter the number of the product name: ";
    cin >> productNumber;
    cout << "Enter how many elements you want to delete: ";
    cin >> quantity;

    // Read orders from filed
    vector<Order> orders;
    OrderCSV<Order> orderImporter;
    orderImporter.importCSV(orderPath, orders);

    // Read products from file
    vector<Product> products;
    ProductCSV<Product> productImporter;
    productImporter.importCSV(productPath, products);

    // Delete order
    for (auto order : orders)
    {
        if (order.getUserName() == name && order.getOrderDate() == date)
        {
            cout << "Order found!" << endl;
            // Find the string to delete
            
            string orderQuantity = to_string(quantity);
            cout << "Order quantity: " << orderQuantity << endl;

            // Take the products of the order string and split them by ';'
            vector<string> orderProducts;
            stringstream ss(order.getOrder());
            string token;
            while (getline(ss, token, ';'))
            {
                orderProducts.push_back(token);
            }
            string orderProduct = orderProducts[productNumber - 1];
            cout << "Order product: " << orderProduct << endl;

            // Take the quantities of the quantity string and split them by ';'
            vector<string> orderQuantities;
            stringstream ss2(order.getQuantity());
            string token2;
            while (getline(ss2, token2, ';'))
            {
                orderQuantities.push_back(token2);
            }

            string newOrder = "";
            string newQuantity = "";

            for (int i = 0; i < orderProducts.size(); i++)
            {
                if (orderProducts[i] != orderProduct)
                {
                    newOrder += orderProducts[i] + ";";
                    newQuantity += orderQuantities[i] + ";";
                }
                else
                {
                    int newQuantityInt = stoi(orderQuantities[i]) - quantity;

                    if (newQuantityInt > 0)
                    {
                        newOrder += orderProducts[i] + ";";
                        newQuantity += to_string(newQuantityInt) + ";";
                    }
                }
            }

                        // Elimină separatorul `;` de la final, dacă există
            if (!newOrder.empty() && newOrder.back() == ';')
                newOrder.pop_back();
            if (!newQuantity.empty() && newQuantity.back() == ';')
                newQuantity.pop_back();

            Order order(name, date, newOrder, newQuantity);
            order.deleteOrder(orders, orderPath, name, date);
            order.addOrder(orders, orderPath);
        }
    }
}

// See order
void SeeOrder(string name, string date, string location)
{
    // Find order path
    PathFinder path;
    string orderPath = path.getPath("Orders", location);
    string initialPath = "../";
    orderPath = initialPath + orderPath;

    // Find product path
    string productPath = path.getPath("Products", location);
    productPath = initialPath + productPath;

    // Read orders from filed
    vector<Order> orders;
    OrderCSV<Order> orderImporter;
    orderImporter.importCSV(orderPath, orders);

    // See order
    for (const auto order : orders)
    {
        if (order.getUserName() == name && order.getOrderDate() == date)
        {
            // Separete the order string
            vector<string> orderProducts;
            stringstream ss(order.getOrder());
            string token;
            while (getline(ss, token, ';'))
            {
                orderProducts.push_back(token);
            }
            // Separate the quantity string
            vector<string> orderQuantities;
            stringstream ss2(order.getQuantity());
            string token2;
            while (getline(ss2, token2, ';'))
            {
                orderQuantities.push_back(token2);
            }

            cout << "\tOrder" << endl;
            cout << left << setw(5) << "No." << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
            for (int i = 0; i < orderProducts.size(); i++)
            {
                // calculate price
                vector<Product> products;
                ProductCSV<Product> productImporter;
                productImporter.importCSV(productPath, products);

                for (const auto& product : products)
                {
                    if (product.getName() == orderProducts[i])
                    {
                        float productPrice = product.getPrice() * stoi(orderQuantities[i]);
                        cout << left << setw(5) << i + 1 << setw(20) << orderProducts[i] << setw(10) << orderQuantities[i] << setw(10) << productPrice << endl;
                    }
                }
            }
        }
    }
}

// Finish order
void FinishOrder(string name, string date, string location)
{
    // Find order path
    PathFinder path;
    string orderPath = path.getPath("Orders", location);
    string initialPath = "../";
    orderPath = initialPath + orderPath;

    // Find product path
    string productPath = path.getPath("Products", location);
    productPath = initialPath + productPath;

    // Read orders from filed
    vector<Order> orders;
    OrderCSV<Order> orderImporter;
    orderImporter.importCSV(orderPath, orders);

    // Read products from file
    vector<Product> products;
    ProductCSV<Product> productImporter;
    productImporter.importCSV(productPath, products);

    Order userOrder;
    
    // Print total cost
    for (const auto& order : orders)
    {
        if (order.getUserName() == name && order.getOrderDate() == date)
        {
            Order newOrder(name, date, order.getOrder(), order.getQuantity());

            // Calculate total cost
            newOrder.calculateTotalCost(orders, productPath, orderPath, name, date);
            float totalCost = order.getTotal();  
            
            cout << "Total cost: " << order.getTotal() << endl;

            // Atualize the csv file
            newOrder.deleteOrder(orders, orderPath, name, date);
            Order newOrder2(name, date, order.getOrder(), order.getQuantity(), totalCost);
            newOrder2.addOrder(orders, orderPath);
        }
    }

    // Print minimenu
    cout << "1. Pay" << endl;
    cout << "2. Cancel" << endl;
    cout << "3. Return to previous menu" << endl;

    int option;
    cout << "Choose an option: ";
    cin >> option;

    switch (option)
    {
        case 1:
            // Set the order elements
            for (auto& order : orders)
            {
                if (order.getUserName() == name && order.getOrderDate() == date)
                {
                    userOrder.setOrder(order.getOrder());
                    userOrder.setQuantity(order.getQuantity());
                }
            }

            userOrder.addOrder(orders, orderPath);

            cout << "Order finished! Thanks for choosing us!" << endl;
            // End program
            exit(0);
            break;

        case 2:
            // Delete the order
            userOrder.deleteOrder(orders, orderPath, name, date);
            cout << "Order canceled!" << endl;
            break;

        case 3:
            return;
            break;
        
        default:
            cout << "Invalid option!" << endl;
            break;
    }

}
