#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class PathFinder
{
    private:
        const string pathCSV = "../CSV/General/Paths.csv";
    public:
        // Get Path
        string getPath(string fileName, string location);
};

#endif // PATH_FINDER_H