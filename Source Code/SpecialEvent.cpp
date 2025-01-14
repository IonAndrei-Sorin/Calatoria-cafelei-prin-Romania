#include "../Header/SpecialEvents.h"

// Default constructor
SpecialEvent::SpecialEvent()
{
    eventName = "";
    date = "";
    cost = 0;
    income = 0;
}
// Constructor
SpecialEvent::SpecialEvent(string eventName, string date, float cost, float income)
{
    this->eventName = eventName;
    this->date = date;
    this->cost = cost;
    this->income = income;
}

// Getters
string SpecialEvent::getEventName() const
{
    return eventName;
}

string SpecialEvent::getDate() const
{
    return date;
}

float SpecialEvent::getCost() const
{
    return cost;
}

float SpecialEvent::getIncome() const
{
    return income;
}

// Setters
void SpecialEvent::setEventName(string eventName)
{
    this->eventName = eventName;
}

void SpecialEvent::setDate(string date)
{
    this->date = date;
}

void SpecialEvent::setCost(float cost)
{
    this->cost = cost;
}

void SpecialEvent::setIncome(float income)
{
    this->income = income;
}

// Methods

// Add special event
void SpecialEvent::addSpecialEvent(vector<SpecialEvent>& specialEvents, const string& specialEventPath)
{
    // Add special event to vector
    specialEvents.push_back(*this);

    // Add special event to csv
    SpecialEventExport<SpecialEvent> specialEventExporter;
    specialEventExporter.addSpecialEvent(specialEventPath, *this);
}

// Delete special event
void SpecialEvent::deleteSpecialEvent(vector<SpecialEvent>& specialEvents, string eventName, const string& specialEventPath)
{
    // Find special event by name
    auto it = find_if(specialEvents.begin(), specialEvents.end(), [&eventName](const SpecialEvent& specialEvent) {return specialEvent.eventName == eventName; });

    // If special event was found
    if (it != specialEvents.end())
    {
        // Delete special event from vector
        specialEvents.erase(it);

        // Export updated vector to csv
        SpecialEventExport<SpecialEvent> specialEventExporter;
        specialEventExporter.export2CSV(specialEventPath, specialEvents);
    }
    else
    {
        cerr << "Error: Special event not found.\n";
    }
}

