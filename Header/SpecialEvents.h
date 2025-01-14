#ifndef CSV_SPECIAL_EVENT_H
#define CSV_SPECIAL_EVENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "CSV_Importer.h"
#include "CSV_Exporter.h"

using namespace std;

class SpecialEvent
{
    private:
        string eventName;
        string date;
        string location;
        float cost;
        float income;
    
    public:
        // Default constructor
        SpecialEvent();
        // Constructor
        SpecialEvent(string eventName, string date, float cost, float income);

        // Getters
        string getEventName() const;
        string getDate() const;
        float getCost() const;
        float getIncome() const;

        // Setters
        void setEventName(string eventName);
        void setDate(string date);
        void setCost(float cost);
        void setIncome(float income);

        // Methods

        // Add special event
        void addSpecialEvent(vector<SpecialEvent>& specialEvents, const string& specialEventPath);
        // Delete special event
        void deleteSpecialEvent(vector<SpecialEvent>& specialEvents, string eventName, const string& specialEventPath);  
};

#endif // CSV_SPECIAL_EVENT_H