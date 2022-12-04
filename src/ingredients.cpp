#include <iostream>
using namespace std;

// Holds ingredient objects
struct Ingredient
{
    string genericName; // Index 0 of the csv
    string specificName; // Index 1
    float carbohydrate; // Index 6
    float cholesterol; // Index 7
    float protein; // Index 13 
    float sugar; // Index 17 

    // Add any other values we might have to store about each ingredient

    // Constructor
    Ingredient (string shortName, string longName, float carb, float chol; float p, float s)
    {
        genericName = shortName;
        specificName = longName;
        carbohydrate = carb;
        cholesterol = chol;
        protein = p;
        sugar = s;
    }

    // Equals to operator based on generic and specific name
    bool operator==(const Ingredient& i) const
    {
        return genericName == i.genericName && specificName == i.specificName;
    }
    string getGeneric(Ingredient *node){
        return node->genericName;
    }

    string getSpecific(Ingredient *node){
        return node->specificName;
    }

    float getCarb(Ingredient *node){
        return node->carbohydrate;
    }

    float getChol(Ingredient *node){
        return node->cholesterol;
    }

    float getProtein(Ingredient *node){
        return node->protein;
    }

    float getSugar(Ingredient *node){
        return node->sugar;
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