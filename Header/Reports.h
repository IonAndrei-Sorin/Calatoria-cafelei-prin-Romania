#ifndef CSV_REPORT_H
#define CSV_REPORT_H

#include <iostream>
#include <string>
#include <vector>
#include "CSV_Importer.h"
#include "CSV_Exporter.h"
#include "Orders.h"
#include "Worker.h"
#include "PathFinder.h"

using namespace std;

class Report
{
    private:
        string date;
        int productsSold;
        float productsCost;
        float salaryCost;
        float totalCost;
        float income;
        float profit;

    public:
        // Default constructor
        Report();
        // Constructor
        Report(string date, int productsSold, float productsCost, float salaryCost, float totalCost, float income, float profit);
        
        // Getters
        string getDate() const;
        int getProductsSold() const;
        float getProductsCost() const;
        float getSalaryCost() const;
        float getTotalCost() const;
        float getIncome() const;
        float getProfit() const;

        // Setters
        void setDate(string date);
        void setProductsSold(int productsSold);
        void setProductsCost(float productsCost);
        void setSalaryCost(float salaryCost);
        void setTotalCost(float totalCost);
        void setIncome(float income);
        void setProfit(float profit);

        // Methods

        // Add report
        void addReport(vector<Report>& reports, const string& reportPath);
        // Delete report
        void deleteReport(vector<Report>& reports, const string& reportPath, string date);
        // Calculate products sold
        void calculateProductsSold(vector<Report>& reports, const string& orderPath,string date);
        // Calculate products cost
        float calculateProductsCost(vector<Report>& reports, const string& orderPath, const string& productPath, string date);
        // Calculate salary cost
        float calculateSalaryCost(vector<Report>& reports, const string& workerPath);
        // Calculate total cost
        float calculateTotalCost(vector<Report>& reports, const string& orderPath, const string& workerPath, const string& productPath, string date);
        // Calculate total income
        float calculateTotalIncome(vector<Report>& reports,const string& orderPath, string date);
        // Calculate profit
        float calculateProfit(vector<Report>& reports, const string& orderPath, const string& workerPath, const string& productPath, string date);
};


class ReportFacade
{
    private:
        Report report;
        string reportPath;
        string orderPath;
        string workerPath;
        string productPath;

    public:
        // Constructor
        ReportFacade();
        void createReport(vector<Report>& reports, string location, string date);
};
#endif // CSV_REPORT_H