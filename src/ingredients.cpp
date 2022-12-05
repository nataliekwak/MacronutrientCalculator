#include <iostream>
using namespace std;

// Holds ingredient objects
class Ingredient
{
        string genericName; // Index 0 of the csv
        string specificName; // Index 1
        float carbohydrate; // Index 6
        float cholesterol; // Index 7
        float protein; // Index 13 
        float sugar; // Index 17 

        // Constructor
        Ingredient () {};

        Ingredient (string shortName, string longName, float carb, float chol, float p, float s)
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
        
        // Setters
        void setGeneric (string name)
        {
            genericName = name;
        }

        void setSpecific (string name)
        {
            specificName = name;
        }

        void setCarbs (float c)
        {
            carbohydrate = c;
        }

        void setCholesterol (float c)
        {
            cholesterol = c;
        }

        void setProtein (float p)
        {
            protein = p;
        }

        void setSugar (float s)
        {
            sugar = s;
        }

        // Getters
        string getGeneric()
        {
            return genericName;
        }

        string getSpecific()
        {
            return specificName;
        }

        float getCarb()
        {
            return carbohydrate;
        }

        float getChol()
        {
            return cholesterol;
        }

        float getProtein()
        {
            return protein;
        }

        float getSugar()
        {
            return sugar;
        }

};

// Class for our hash function
class HashFunction
{
    public:
        size_t operator()(const Ingredient& i) const
        {
            return int(i.genericName[0]) + int(i.genericName.charAt[1]) + int(i.genericName.charAt[2]);
            // hash function that calulates the ascii values for the first 3 characters
        }
};