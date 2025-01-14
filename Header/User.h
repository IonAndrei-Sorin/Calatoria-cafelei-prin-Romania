#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User
{
    private:
        string name;
        int ID;
    
    public:
        User(string name, int ID);

        // Getters
        string getName() const;
        int getID() const;

        // Setters
        void setName(string name);
        void setID(int ID);
};

#endif // USER_H