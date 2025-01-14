#ifndef CSV_EXPORTER_H
#define CSV_EXPORTER_H

// Include libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>


using namespace std;

/// Template
// Abstract class for CSV Exporter with a template
template <typename T>
class CSVExporter
{
    public:
        virtual void export2CSV(const string& filePath, vector<T>& vect) = 0;
        virtual ~CSVExporter<T>() = default;
};

/// Mostenire
// Derived classes from CSVExporter

// Workers
template <typename T>
class WorkerExport : public CSVExporter<T>
{
    public:
        void export2CSV(const string& filePath, vector<T>& vect) override
        {
            ofstream file(filePath);
            if (!file.is_open())
            {
                cerr << "WorkerExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << "Name,Role,Shift Start,Shift End,Salary\n";
            for (const auto& worker : vect)
            {
                file << worker.getName() << "," << worker.getRole() << "," << worker.getShiftStart() << "," << worker.getShiftEnd() << "," << worker.getSalary() << "\n";
            }

            file.close();
        }

        /// Metode

        // Method to add only one worker to the CSV file
        void addWorker(const string& filePath, T& worker)
        {
            ofstream file(filePath, ios::app);
            if (!file.is_open())
            {
                cerr << "WorkerExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << worker.getName() << "," << worker.getRole() << "," << worker.getShiftStart() << "," << worker.getShiftEnd() << "," << worker.getSalary() << "\n";

            file.close();
        }
};

// Products
template <typename T>
class ProductExport : public CSVExporter<T>
{
    public:
        void export2CSV(const string& filePath, vector<T>& vect) override
        {
            ofstream file(filePath);
            if (!file.is_open())
            {
                cerr << "ProductExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << "Name,Price,Cost,Stock\n";
            for (const auto& product : vect)
            {
                file << product.getName() << "," << product.getPrice() << "," << product.getCost() << "," << product.getStock() << "\n";
            }

            file.close();
        }

        /// Metode

        // Method to add only one product to the CSV file
        void addProduct(const string& filePath, T& product)
        {
            ofstream file(filePath, ios::app);
            if (!file.is_open())
            {
                cerr << "ProductExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << product.getName() << "," << product.getPrice() << "," << product.getCost() << "," << product.getStock() << "\n";

            file.close();
        }
};

// Reports
template <typename T>
class ReportExport : public CSVExporter<T>
{
    public:
        void export2CSV(const string& filePath, vector<T>& vect) override
        {
            ofstream file(filePath);
            if (!file.is_open())
            {
                cerr << "ReportExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << "Date,Products Sold,Products Cost,Salary Cost,Total Cost,Income,Profit\n";
            for (const auto& report : vect)
            {
                file << report.getDate() << "," << report.getProductsSold() << "," << report.getProductsCost() << "," << report.getSalaryCost() << "," << report.getTotalCost() << "," << report.getIncome() << "," << report.getProfit() << "\n";
            }

            file.close();
        }

        /// Metode

        // Method to add only one report to the CSV file
        void addReport(const string& filePath, T& report)
        {
            ofstream file(filePath, ios::app);
            if (!file.is_open())
            {
                cerr << "ReportExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << report.getDate() << "," << report.getProductsSold() << "," << report.getProductsCost() << "," << report.getSalaryCost() << "," << report.getTotalCost() << "," << report.getIncome() << "," << report.getProfit() << "\n";

            file.close();
        }
};

// Orders
template <typename T>
class OrderExport : public CSVExporter<T>
{
    public:
        void export2CSV(const string& filePath, vector<T>& vect) override
        {
            ofstream file(filePath);
            if (!file.is_open())
            {
                cerr << "OrderExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << "Client Name,Order Date,Order,Quantity,Total\n";
            for (const auto& order : vect)
            {
                file << order.getUserName() << "," << order.getOrderDate() << "," << order.getOrder() << "," << order.getQuantity() << "," << order.getTotal() << "\n";
            }

            file.close();
        }

        /// Metode

        // Method to add only one order to the CSV file
        void addOrder(const string& filePath, T& order)
        {
            ofstream file(filePath, ios::app);
            if (!file.is_open())
            {
                cerr << "OrderExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << order.getUsertName() << "," << order.getOrderDate() << "," << order.getOrder() << "," << order.getQuantity() << "," << order.getTotal() << "\n";

            file.close();
        }
};

// Special Events
template <typename T>
class SpecialEventExport : public CSVExporter<T>
{
    public:
        void export2CSV(const string& filePath, vector<T>& vect) override
        {
            ofstream file(filePath);
            if (!file.is_open())
            {
                cerr << "SpecialEventExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << "Event name,Date,Cost,Income,Profit\n";
            for (const auto& specialEvent : vect)
            {
                file << specialEvent.getEventName() << "," << specialEvent.getDate() << "," << specialEvent.getCost() << "," << specialEvent.getIncome() << "\n";
            }

            file.close();
        }

        /// Metode

        // Method to add only one special event to the CSV file
        void addSpecialEvent(const string& filePath, T& specialEvent)
        {
            ofstream file(filePath, ios::app);
            if (!file.is_open())
            {
                cerr << "SpecialEventExport: Error: Could not open the CSV file.\n";
                return;
            }

            file << specialEvent.getEventName() << "," << specialEvent.getDate() << "," << specialEvent.getCost() << "," << specialEvent.getIncome() << "\n";

            file.close();
        }
};

#endif // CSV_EXPORTER_H