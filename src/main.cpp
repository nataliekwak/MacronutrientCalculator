#include "ingredients.cpp"
#include <unordered_map>
//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Helper function to read the passed in csv file and return a populated hashmap 
unordered_map<string, Ingredient*> populateHashMap (string file)
{
    unordered_map<string, Ingredient*> hashMap;

    // Do file reading and map populating here
    fstream inFile; 
    inFile.open(file, ios::in); 
    
    // Read the data from the file as a string vector
    vector<string> row;
    string line, singleValue, temp;

    while (getline(inFile, line))
    {
        row.clear();

        // Read a whole row and store it in line
        //getline(inFile, line);

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

    for (auto i : map)
    {
        // Print each specific name in the map
        cout << i.first << endl;

        testCounter++;
    }

    cout << "\nThere are " << testCounter << " ingredients in the hash map." << endl;
}

// Helper function to sort with merge sort
void swap(vector<pair<string,float>> &vect, int numOne, int numTwo)
{
    pair<string, float> temp (vect[numOne].first, vect[numOne].second);

    vect[numOne].first = vect[numTwo].first;
    vect[numOne].second = vect[numTwo].second;

    vect[numTwo].first = temp.first;
    vect[numTwo].second = temp.second;

}

// Helper function to sort with merge sort
int splitArray(vector<pair<string,float>> & vect, int low, int high)
{
    float pivot = vect[high].second;

    int temp = (low - 1);
    for(int i = low; i <= high - 1; i++)
    {
        if(vect[i].second <= pivot)
        {
            temp++;
            swap(vect, temp, i);
        }
    }
    swap(vect, temp + 1, high);
    return(temp + 1);

}

// Function to implement quick sort
void quickSort(vector<pair<string,float>> &vect, int low, int high)
{
    if(low < high)
    {
        int sort = splitArray(vect, low, high);

        quickSort(vect, low, sort - 1);
        quickSort(vect, sort + 1, high);
    }
}

// Merge sort helper
void merge(vector<pair<string,float>>& vect, int low, int mid, int high)
{
    vector<pair<string,float>> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (vect[i].second <= vect[j].second)
        {
            temp.push_back(vect[i]);
            ++i;
        }
        else 
        {
            temp.push_back(vect[j]);
            ++j;
        }
    }

    while (i <= mid)
    {
        temp.push_back(vect[i]);
        ++i;
    }

    while (j <= high)
    {
        temp.push_back(vect[j]);
        ++j;
    }

    for (int i = low; i <= high; ++i)
    {
        vect[i] = temp[i - low];
    }
}

// Function to implement merge sort
void mergeSort(vector<pair<string,float>>& vect, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(vect, low, mid);
        mergeSort(vect, mid+1, high);
        merge(vect, low, mid, high);
    }
}

// Returns a vector of protein values from a hashmap
vector<pair<string,float>> populateVectorProtein(unordered_map<string, Ingredient*> map)
{
    vector<pair<string,float>> vect;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        pair<string, float> temp (it->first, it->second->protein);
        vect.push_back(temp);
    }
    return vect;
}

// Returns a vector of carb values from a hashmap
vector<pair<string,float>> populateVectorCarbohydrate(unordered_map<string, Ingredient*> map)
{
    vector<pair<string,float>> vect;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        pair<string, float> temp (it->first, it->second->carbohydrate);
        vect.push_back(temp);
    }
    return vect;
}

// Returns a vector of cholesterol values from a hashmap
vector<pair<string,float>> populateVectorCholesterol(unordered_map<string, Ingredient*> map)
{
    vector<pair<string,float>> vect;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        pair<string, float> temp (it->first, it->second->cholesterol);
        vect.push_back(temp);
    }
    return vect;
}

// Returns a vector of sugar values from a hashmap
vector<pair<string,float>> populateVectorSugar(unordered_map<string, Ingredient*> map)
{
    vector<pair<string,float>> vect;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        pair<string, float> temp (it->first, it->second->sugar);
        vect.push_back(temp);
    }
    return vect;
}


int main ()
{
    cout << "Welcome to the MacroNutrient Calculator!" << endl;

    // Make hashmap by calling populateHashMap("ingredients.csv")
    unordered_map<string, Ingredient*> hashMap;
    hashMap = populateHashMap("ingredients.csv");

    // Take user input
    bool exit = false;
    while (!exit)
    {
        int choice;
        cout << "\nPlease select an option:\n0. Exit\n" << "1. Sort ingredients by protein\n" << "2. Sort ingredients by sugar\n" << "3. Check Macros of a Specifc Ingredient\n";
        cin >> choice;

        // Exit
        if (choice == 0)
        {
            exit = true;
            break;
        }
        // Sort ingredients by protein
        else if (choice == 1)
        {
            int choice1;
            cout << "\nWhich sorting algorithm would you like to use?\n1. Merge Sort\n2. Quick Sort\n";
            cin >> choice1;

            vector<pair<string, float>> proteins = populateVectorProtein(hashMap);

            // Merge Sort
            if (choice1 == 1)
            {
                mergeSort(proteins, 0, proteins.size() - 1);
            }
            // Quick Sort
            else if (choice1 == 2)
            {
                quickSort(proteins, 0, proteins.size() - 1);
            }

            cout << "\nIngredients listed by amount of protein (from smallest to largest):" << endl;
            for (int i = 0; i < proteins.size(); i++)
            {
                cout << proteins[i].first << " - " << proteins[i].second << " g" << endl;
            }
        }
        // Sort Ingredients by Sugar
        else if (choice == 2)
        {
            int choice1;
            cout << "\nWhich sorting algorithm would you like to use?\n1. Merge Sort\n2. Quick Sort\n";
            cin >> choice1;

            vector<pair<string, float>> sugars = populateVectorSugar(hashMap);

            // Merge Sort
            if (choice1 == 1)
            {
                mergeSort(sugars, 0, sugars.size() - 1);
            }
            // Quick Sort
            else if (choice1 == 2)
            {
                quickSort(sugars, 0, sugars.size() - 1);
            }

            cout << "\nIngredients listed by amount of sugar (from smallest to largest):" << endl;
            for (int i = 0; i < sugars.size(); i++)
            {
                cout << sugars[i].first << " - " << sugars[i].second << " g" << endl;
            }
        }
        // Search for Ingredient
        else if (choice == 3)
        {
            cout << "\nThe following is a list of ingredient categories:" << endl;
            vector<string> categories;
            bool included = false;

            for (auto i : hashMap)
            {
                included = false;
                for (auto j : categories)
                {
                    if (i.second->genericName == j)
                    {
                        included = true;
                        break;
                    }
                }

                if (!included)
                {
                    categories.push_back(i.second->genericName);
                }
            }

            for (auto i : categories)
            {
                cout << i << endl;
            }

            string category;
            cout << "\nPlease type the category your ingredient is in exact from the above list: " << endl;
            getline(cin >> ws, category);

            cout << "\nThe following is a list of ingredients in the chosen category:" << endl;

            // Give the user options based on the category they picked
            for (auto i : hashMap)
            {
                if (i.second->genericName == category)
                {
                    cout << i.second->specificName << endl;
                }
            }

            string foodItem;
            cout << "\nPlease type the ingredient you want to search exactly from the above list: ";
            getline(cin >> ws, foodItem);

            unordered_map<string, Ingredient*>::iterator found;
            found = hashMap.find(foodItem);

            cout << "Food item: " << foodItem << endl;

            if (found != hashMap.end() )
            {
                found->second->printMacros();
            }
            else
            {
                cout << "Ingredient not found" << endl;
            }
        }
    }
    
    return 0;
}