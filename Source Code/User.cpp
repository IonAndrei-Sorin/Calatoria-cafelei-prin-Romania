#include "../Header/User.h"

// Constructor
User::User(string name, int ID)
{
    this->name = name;
    this->ID = ID;
}

// Getters
string User::getName() const
{
    return name;
}

int User::getID() const
{
    return ID;
}

// Setters
void User::setName(string name)
{
    this->name = name;
}

void User::setID(int ID)
{
    this->ID = ID;
}