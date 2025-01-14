#ifndef CSV_WORKER_H
#define CSV_WORKER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "CSV_Exporter.h"

using namespace std;

class Worker
{
    private:
        string name;
        string role;
        string shiftStart;
        string shiftEnd;
        float salary;
    
    public:
        // Default Constructor
        Worker();
        // Constructor
        Worker(string name, string role, string shiftStart, string shiftEnd, float salary);

        // Getters
         string getName() const;
         string getRole() const;
         string getShiftStart() const;
         string getShiftEnd() const;
         float getSalary() const;

        // Setters
         void setName(string name);
         void setRole(string role);
         void setShiftStart(string shiftStart);
         void setShiftEnd(string shiftEnd);
         void setSalary(float salary);

        // Methods

        // Add in system worker
         void addWorker(vector<Worker>& workers, const string& filePath);
        // Delete from system worker
         void deleteWorker(vector<Worker>& workers, string name, const string& filePath);
        // Change shift for worker
         void changeShift(vector<Worker>& workers, string name, const string& filePath, string shiftStart, string shiftEnd);
};

#endif // CSV_WORKER_H
