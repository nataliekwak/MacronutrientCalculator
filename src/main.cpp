#include "ingredients.cpp"
#include <unordered_map>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

// Helper function to read the passed in csv file and return a populated hashmap 
unordered_map<string, Ingredient*> populateHashMap (string file)
{
    unordered_map<string, Ingredient*> hashMap;

    // Do file reading and map populating here
    fstream inFile; 
    inFile.open(file, ios::in); 
    
    if (inFile.is_open()) 
    {
         cout << "File has been opened" << endl;
    }
    else 
    {
         cout << "ERROR: FILE NOT FOUND" << endl;
    }

    // Take the header line out of the file
    //string trash;
    //getline(inFile, trash);

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
        // UNCOMMENT BELOW PRINT EACH SPECIFIC NAME IN THE MAP 
        //cout << i.first << endl;

        testCounter++;
    }

    cout << "\nThere are " << testCounter << " ingredients in the hash map." << endl;
}

void swap(vector<float> &vect, int numOne, int numTwo)
{
    float temp = vect[numOne];
    vect[numOne] = vect[numTwo];
    vect[numTwo] = temp;
}

//helper function to sort with merge sort
int splitArray(vector<float> & vect, int low, int high)
{
    float pivot = vect[high];

    int temp = (low - 1);
    for(int i = low; i <= high - 1; i++)
    {
        if(vect[i] <= pivot)
        {
            temp++;
            swap(vect,temp,i);
        }
    }
    swap(vect,temp+1,high);
    return (temp+1);

}

void quickSort(vector<float> &vect, int low, int high)
{
    if(low < high)
    {
        int sort = splitArray(vect,low,high);

        quickSort(vect,low,sort - 1);
        quickSort(vect,sort + 1, high);
    }
}
//void mergeSort(unordered_map<string, Ingredient*> hashMap, string sortBy){
    
//}
void merge(vector<float>& vect, int low, int mid, int high)
{
    vector<float> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (vect[i] <= vect[j])
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

void mergeSort(vector<float>& vect, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(vect, low, mid);
        mergeSort(vect, mid+1, high);
        merge(vect, low, mid, high);
    }
}


int main ()
{
    // Make hashmap by calling populateHashMap("ingredients.csv")
    unordered_map<string, Ingredient*> hashMap;
    hashMap = populateHashMap("tester.csv");

    printHashMap(hashMap);

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