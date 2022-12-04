#include <iostream>
using namespace std;

// Holds ingredient objects
struct Ingredient
{
    string genericName; // Index 0 of the csv
    string specificName; // Index 1
    float protein; // Index 13 
    float sugar; // Index 17 

    // Add any other values we might have to store about each ingredient

    // Constructor
    Ingredient (string shortName, string longName, float p, float s)
    {
        genericName = shortName;
        specificName = longName;
        protein = p;
        sugar = s;
    }

    // Equals to operator based on generic and specific name
    bool operator==(const Ingredient& i) const
    {
        return genericName == i.genericName && specificName == i.specificName;
    }
};

// Class for our hash function
class HashFunction
{
    public:
        size_t operator()(const Ingredient& i) const
        {
            // Return result of hash function here
        }
};