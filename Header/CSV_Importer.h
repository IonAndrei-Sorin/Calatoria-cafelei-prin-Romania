#ifndef CSV_IMPORTER_H
#define CSV_IMPORTER_H

// Include libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/// Template
// Abstract class for CSV Importer with a template
template <typename T>
class CSVImporter 
{
    public:
        virtual void importCSV(const string& filePath, vector<T>& vect) = 0;
        virtual ~CSVImporter<T>() = default;
};

/// Mostenire 
// Derived classes from CSVImporter

// Workers
template <typename T>
class WorkerCSV : public CSVImporter<T>
{
    private:
        vector<string> parseCSVLine(const string& line)
        {
            vector<string> result;
            string field;
            bool insideQuotes = false;

            for (char c : line) 
            {
                if (c == '"') 
                {
                    insideQuotes = !insideQuotes;
                } 
                else if (c == ',' && !insideQuotes) 
                {
                    result.push_back(field);
                    field.clear();
                } 
                else 
                {
                    field += c;
                }
            }
            result.push_back(field); // Add the last field
            return result;
        }
    public:
        void importCSV(const string& filePath, vector<T>& vect) override
        {
            ifstream file(filePath);
            if (!file.is_open()) 
            {
                cerr << "WorkerCSV: Error: Could not open the CSV file.\n";
                return;
            }

            string line;
            getline(file, line); // Ignore the header

            while (getline(file, line)) 
            {
                vector<string> fields = parseCSVLine(line);

                if (fields.size() < 4) 
                { // Check if all necessary fields exist
                    cerr << "WorkerCSV: Invalid line: " << line << "\n";
                    continue;
                }

                try 
                {
                    string name = fields[0];
                    string role = fields[1];
                    string shiftStart = fields[2];
                    string shiftEnd = fields[3];
                    int salary = fields[4].empty() ? 0 : stoi(fields[4]);

                    // Crează un obiect Worker și adaugă-l în vector
                    vect.emplace_back(name, role, shiftStart, shiftEnd, salary);
                } 
                catch (const exception& e) 
                {
                    cerr << "WorkerCSV: Error parsing line: " << e.what() << "\n";
                }
            }

            file.close();
        }
};

// Products 
template <typename T>
class ProductCSV : public CSVImporter<T>
{
    private:
        vector<string> parseCSVLine(const string& line)
        {
            vector<string> result;
            string field;
            bool insideQuotes = false;

            for (char c : line) 
            {
                if (c == '"') 
                {
                    insideQuotes = !insideQuotes;
                } 
                else if (c == ',' && !insideQuotes) 
                {
                    result.push_back(field);
                    field.clear();
                } 
                else 
                {
                    field += c;
                }
            }
            result.push_back(field); // Add the last field
            return result;
        }
    public:
        void importCSV(const string& filePath, vector<T>& vect) override
        {
            ifstream file(filePath);
            if (!file.is_open()) 
            {
                cerr << "ProductCSV: Error: Could not open the CSV file.\n";
                return;
            }

            string line;
            getline(file, line); // Ignore the header

            while (getline(file, line)) 
            {
                vector<string> fields = parseCSVLine(line);

                if (fields.size() < 3) 
                { // Verifică dacă toate câmpurile necesare există
                    cerr << "ProductCSV: Invalid line: " << line << "\n";
                    continue;
                }

                try 
                {
                    string name = fields[0];
                    float price = fields[1].empty() ? 0 : stof(fields[1]);
                    float cost = fields[2].empty() ? 0 : stof(fields[2]);
                    int stock = fields[3].empty() ? 0 : stoi(fields[3]);

                    // Crează un obiect Product și adaugă-l în vector
                    vect.emplace_back(name, price, cost, stock);
                } 
                catch (const exception& e) 
                {
                    cerr << "ProductCSV: Error parsing line: " << e.what() << "\n";
                }
            }

            file.close();
        }
};

// Reports
template <typename T>
class ReportCSV : public CSVImporter<T>
{
    private:
        vector<string> parseCSVLine(const string& line)
        {
            vector<string> result;
            string field;
            bool insideQuotes = false;

            for (char c : line) 
            {
                if (c == '"') 
                {
                    insideQuotes = !insideQuotes;
                } 
                else if (c == ',' && !insideQuotes) 
                {
                    result.push_back(field);
                    field.clear();
                } 
                else 
                {
                    field += c;
                }
            }
            result.push_back(field); // Add the last field
            return result;
        }
    public:
        void importCSV(const string& filePath, vector<T>& vect) override
        {
            ifstream file(filePath);
            if (!file.is_open()) 
            {
                cerr << "ReportCSV: Error: Could not open the CSV file.\n";
                return;
            }

            string line;
            getline(file, line); // Ignore the header

            while (getline(file, line)) 
            {
                vector<string> fields = parseCSVLine(line);

                if (fields.size() < 7) 
                { // Verifică dacă toate câmpurile necesare există
                    cerr << "ReportCSV: Invalid line: " << line << "\n";
                    continue;
                }

                try 
                {
                    string date = fields[0];
                    int productsSold = fields[1].empty() ? 0 : stoi(fields[1]);
                    float productsCost = fields[2].empty() ? 0 : stof(fields[2]);
                    float salaryCost = fields[3].empty() ? 0 : stof(fields[3]);
                    float totalCost = fields[4].empty() ? 0 : stof(fields[4]);
                    float income = fields[5].empty() ? 0.0 : stof(fields[5]);
                    float profit = fields[6].empty() ? 0.0 : stof(fields[6]);

                    vect.emplace_back(date, productsSold, productsCost, salaryCost, totalCost, income, profit);
                } 
                catch (const exception& e) 
                {
                    cerr << "ReportCSV: Error parsing line: " << e.what() << "\n";
                }
            }

            file.close();
        }
};

// Orders
template <typename T>
class OrderCSV : public CSVImporter<T>
{
    private:
        vector<string> parseCSVLine(const string& line)
        {
            vector<string> result;
            string field;
            bool insideQuotes = false;

            for (char c : line) 
            {
                if (c == '"') 
                {
                    insideQuotes = !insideQuotes;
                } 
                else if (c == ',' && !insideQuotes) 
                {
                    result.push_back(field);
                    field.clear();
                } 
                else 
                {
                    field += c;
                }
            }
            result.push_back(field); // Add the last field
            return result;
        }
    public:
        void importCSV(const string& filePath, vector<T>& vect) override
        {
            ifstream file(filePath);
            if (!file.is_open()) 
            {
                cerr << "OrderCSV: Error: Could not open the CSV file.\n";
                return;
            }

            string line;
            getline(file, line); // Ignore the header

            while (getline(file, line)) 
            {
                vector<string> fields = parseCSVLine(line);

                if (fields.size() < 4) 
                { // Verifică dacă toate câmpurile necesare există
                    cerr << "OrderCSV: Invalid line: " << line << "\n";
                    continue;
                }

                try 
                {
                    string clientName = fields[0];
                    string orderDate = fields[1];
                    string order = fields[2];
                    string quantity = fields[3];
                    float total = fields[4].empty() ? 0 : stof(fields[4]);

                    vect.emplace_back(clientName, orderDate, order, quantity, total);
                } 
                catch (const exception& e) 
                {
                    cerr << "OrderCSV: Error parsing line: " << e.what() << "\n";
                }
            }

            file.close();
        }
};

// Special events
template <typename T>
class SpecialEventCSV : public CSVImporter<T>
{
    private:
        vector<string> parseCSVLine(const string& line)
        {
            vector<string> result;
            string field;
            bool insideQuotes = false;

            for (char c : line) 
            {
                if (c == '"') 
                {
                    insideQuotes = !insideQuotes;
                } 
                else if (c == ',' && !insideQuotes) 
                {
                    result.push_back(field);
                    field.clear();
                } 
                else 
                {
                    field += c;
                }
            }
            result.push_back(field); // Add the last field
            return result;
        }
    public:
        void importCSV(const string& filePath, vector<T>& vect) override
        {
            ifstream file(filePath);
            if (!file.is_open()) 
            {
                cerr << "SpecialEventCSV: Error: Could not open the CSV file.\n";
                return;
            }

            string line;
            getline(file, line); // Ignore the header

            while (getline(file, line)) 
            {
                vector<string> fields = parseCSVLine(line);

                if (fields.size() < 3) 
                { // Verifică dacă toate câmpurile necesare există
                    cerr << "SpecialEventCSV: Invalid line: " << line << "\n";
                    continue;
                }

                try 
                {
                    string eventName = fields[0];
                    string date = fields[1];
                    float cost = fields[2].empty() ? 0.0 : stof(fields[2]);
                    float income = fields[3].empty() ? 0.0 : stof(fields[3]);

                    vect.emplace_back(eventName, date, cost, income);
                } 
                catch (const exception& e) 
                {
                    cerr << "SpecialEventCSV: Error parsing line: " << e.what() << "\n";
                }
            }

            file.close();
        }
};

// Loyal Users
template <typename T>
class LoyalUsersCSV : public CSVImporter<T>
{
    private:
        vector<string> parseCSVLine(const string& line)
        {
            vector<string> result;
            string field;
            bool insideQuotes = false;

            for (char c : line) 
            {
                if (c == '"') 
                {
                    insideQuotes = !insideQuotes;
                } 
                else if (c == ',' && !insideQuotes) 
                {
                    result.push_back(field);
                    field.clear();
                } 
                else 
                {
                    field += c;
                }
            }
            result.push_back(field); // Add the last field
            return result;
        }
    public:
        void importCSV(const string& filePath, vector<T>& vect) override
        {
            ifstream file(filePath);
            if (!file.is_open()) 
            {
                cerr << "LoyalUsersCSV: Error: Could not open the CSV file.\n";
                return;
            }

            string line;
            getline(file, line); // Ignore the header

            while (getline(file, line)) 
            {
                vector<string> fields = parseCSVLine(line);

                if (fields.size() < 2) 
                { // Verifică dacă toate câmpurile necesare există
                    cerr << "LoyalUsersCSV: Invalid line: " << line << "\n";
                    continue;
                }

                try 
                {
                    string name = fields[0];
                    int ID = fields[1].empty() ? 0 : stoi(fields[1]);

                    vect.emplace_back(name, ID);
                } 
                catch (const exception& e) 
                {
                    cerr << "LoyalUsersCSV: Error parsing line: " << e.what() << "\n";
                }
            }

            file.close();
        }
};
#endif // CSV_IMPORTER_H
