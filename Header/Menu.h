#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include <iomanip>
#include "CSV_Importer.h"
#include "CSV_Exporter.h"
#include "Worker.h"
#include "Orders.h"
#include "Product.h"
#include "Reports.h"
#include "SpecialEvents.h"
#include "PathFinder.h"

using namespace std;

// Function prototypes
        /// Location menu
void LocationMenu();
        /// Start menu
void StartMenu(string location);
        /// Manager menu and submenus
void ManagerMenu(string location);

// Worker menu and submenus
void WorkerMenu(string location);
    // Worker submenus
void AddWorker(string location);
void SeeWorkers(string location);
void DeleteWorker(string location);
void ChangeShift(string location);

// Product menu and submenus
void ProductMenu(string location);
    // Product submenus
void AddProduct(string location);
void SeeProducts(string location);
void DeleteProduct(string location);

// Special Events menu and submenus
void SpecialEventMenu(string location);
    // Special Events submenus
void AddSpecialEvent(string location);
void SeeSpecialEvents(string location);
void DeleteSpecialEvent(string location);

// Report menu and submenus
void ReportMenu(string location);
    // Report submenus
void GenerateReport(string location);
void SeeReports(string location);
void DeleteReport(string location);


        /// User menu and submenus
void UserMenu(string location);
    // User submenus
string GetDate();
void SeeMenu(string location);
void AddElemntToOrder(string name, string date, string location);
void SeeOrder(string name, string date, string location);
void AddElementToOrder(string name, string date, string location);
void DeleteElementFromOrder(string name, string date, string location);
void FinishOrder(string name, string date, string location);

#endif // MENU_H