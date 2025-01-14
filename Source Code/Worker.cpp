#include "../Header/Worker.h"

// Default Constructor
Worker::Worker() {}
// Constructor
Worker::Worker(string name, string role, string shiftStart, string shiftEnd, float salary) 
{
    this->name = name;
    this->role = role;
    this->shiftStart = shiftStart;
    this->shiftEnd = shiftEnd;
    this->salary = salary;
}

// Implementarea metodelor getter
string Worker::getName() const { 
    return name; 
}

string Worker::getRole() const { 
    return role; 
}

string Worker::getShiftStart() const { 
    return shiftStart; 
}

string Worker::getShiftEnd() const { 
    return shiftEnd; 
}

float Worker::getSalary() const { 
    return salary; 
}

// Implementarea metodelor setter
void Worker::setName(string name) { 
    this->name = name; 
}

void Worker::setRole(string role) { 
    this->role = role; 
}

void Worker::setShiftStart(string shiftStart) { 
    this->shiftStart = shiftStart; 
}

void Worker::setShiftEnd(string shiftEnd) { 
    this->shiftEnd = shiftEnd; 
}

void Worker::setSalary(float salary) { 
    this->salary = salary; 
}

// Metodele specifice
void Worker::addWorker(vector<Worker>& workers, const string& filePath) {
     // Add worker to vector
    workers.push_back(*this);

    // Add worker to csv
    WorkerExport<Worker> workerExporter;
    workerExporter.addWorker(filePath, *this);
    
}

void Worker::deleteWorker(vector<Worker>& workers, string name, const string& filePath) {
    // Find worker by name
    auto it = find_if(workers.begin(), workers.end(), [&name](const Worker& worker) { return worker.name == name; });

    // If worker was found
    if (it != workers.end())
    {
        // Delete worker from vector
        workers.erase(it);

        // Export updated vector to csv
        WorkerExport<Worker> workerExporter;
        workerExporter.export2CSV(filePath, workers);
    }
    else
    {
        cerr << "Error: Worker not found.\n";
    }
}


void Worker::changeShift(vector<Worker>& workers, string name, const string& filePath, string shiftStart, string shiftEnd) {
    // Find worker by name
    auto it = find_if(workers.begin(), workers.end(), [&name](const Worker& worker) { return worker.name == name; });

    // If worker was found
    if (it != workers.end())
        {
        // Change shift for worker
        it->shiftStart = shiftStart;
            it->shiftEnd = shiftEnd;

        // Export updated vector to csv
        WorkerExport<Worker> workerExporter;
        workerExporter.export2CSV(filePath, workers);
    }
    else
    {
        cerr << "Error: Worker not found.\n";
    }
}

