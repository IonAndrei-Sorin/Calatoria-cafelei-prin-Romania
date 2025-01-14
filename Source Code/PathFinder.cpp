#include "../Header/PathFinder.h"

// Get Path
string PathFinder:: getPath(string fileName, string location)
{
    ifstream file(pathCSV);
    if (!file.is_open())
    {
        cerr << "Error: Could not open the CSV file.\n";
        return "";
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string csvFileName, csvLocation, csvPath;

        // Citește cele 3 coloane
        getline(ss, csvFileName, ',');
        getline(ss, csvLocation, ',');
        getline(ss, csvPath, ',');

        // Verifică dacă `fileName` și `location` coincid
        if (csvFileName == fileName && csvLocation == location)
        {
            return csvPath; // Returnează path-ul găsit

        }
    }

    file.close();
    return "Nu exista path-ul dorit"; // Nu s-a găsit un path corespunzător
}
