#include "ingredients.cpp"
#include <unordered_map>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Helper function to read the passed in csv file and return a populated hashmap 
unordered_map<string, Ingredient*> populateHashMap (string file)
{
    unordered_map<string, Ingredient*> hashMap;

    // Do file reading and map populating here
    ifstream inFile; 
    inFile.open(file); 
    
    if (inFile.is_open()) 
    {
         cout << "File has been opened" << endl;
    }
    else 
    {
         cout << "ERROR: FILE NOT FOUND" << endl;
    }

    // Take the header line out of the file
    string trash;
    getline(inFile, trash);

    // Read the data from the file as a string vector
    vector<string> row;
    string line, singleValue, temp;

    while (inFile >> temp)
    {
        row.clear();

        // Read a whole row and store it in line
        getline(inFile, line);

        // Break up the line to get each singular value
        stringstream s(line);

        // Read each column of the current row and push to row vector
        while (getline(s, singleValue, ','))
        {
            row.push_back(singleValue);
        }

        // Get necessary values from row and convert when needed
        string genericName = row[0];
        string specificName = row[1];
        float carb = stof(row[6]);
        float cholesterol = stof(row[7]);
        float protein = stof(row[13]);
        float sugar = stof(row[17]);

        // Create an Ingredient object with the data from the csv
        Ingredient* food = new Ingredient(genericName, specificName, carb, cholesterol, protein, sugar);

        // Add the Ingredient to the hashMap
        hashMap[specificName] = food;
    }

    return hashMap;
}

// Prints out each element in a passed in hashmap
void printHashMap (unordered_map<string, Ingredient*> map)
{
    int testCounter = 0;

    for (auto i = map.begin(); i != map.end(); i++)
    {
        

        testCounter++;
    }

    cout << "\nThere are " << testCounter << " ingredients in the hash map." << endl;
}

//helper function to sort with merge sort
void mergeSort(unordered_map<Ingredient, int, HashFunction> *hashMap, string sortBy){
    
}

int main ()
{
    // Make hashmap by calling populateHashMap("ingredients.csv")
    unordered_map<string, Ingredient*> hashMap;
    hashMap = populateHashMap("ingredients.csv");

    // printHashMap(hashMap);

    // // Take user input
    // bool exit = false;
    // while (!exit)
    // {
    //     int choice;
    //     cout << "0. Exit\n" << "1. Print ingredients by protein\n" << "3. Print ingredients by sugar\n" << "3. Check specifc ingredient\n";
    //     cin >> choice;

    //     if (choice == 0)
    //     {
    //         exit = true;
    //         break;
    //     }
    //     else if (choice == 1)
    //     {

    //     }
    // }
    
    return 0;
}