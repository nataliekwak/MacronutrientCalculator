#include "ingredients.cpp"
#include <unordered_map>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Helper function to read the passed in csv file and return a populated hashmap 
unordered_map<Ingredient, int, HashFunction> populateHashMap (string file)
{
    unordered_map<Ingredient, int, HashFunction> hashMap;

    // Do file reading and map populating here

    return hashMap;
}

//helper function to sort with merge sort
void mergeSort(unordered_map<Ingredient, int, HashFunction> *hashMap, string sortBy){
    
}




int main ()
{
    // Make hashmap by calling populateHashMap("ingredients.csv")
    unordered_map<Ingredient, int, HashFunction> hashMap;
    hashMap = populateHashMap("Ingredients.csv");


    // Output

    // Take user input
    while (true){
        int choice;
        cout << "0. Exit\n" << "1. Print ingredients by protein\n" << "3. Check specifc ingredient\n";
        cin >> choice;

        if (choice == 0){
            return;
        }
        if (choice == 1){

        }

    }
    
    return 0;
}