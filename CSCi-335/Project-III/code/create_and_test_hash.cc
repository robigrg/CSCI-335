// Robi Gurung
// Professor Ionnis Stamos
// CSCI 335
// 4 November 2021
// create_and_test_hash.cc: This file contains the test functions for linear, 
// quadratic and double hashing. 
#include <fstream>
#include <iostream>
#include <string>

// Uncomment when you implemented linear probing & double hashing
#include "linear_probing.h"
#include "double_hashing.h"
#include "quadratic_probing.h"

using namespace std;


// You can add more functions here

// @hash_table: a hash table (can be linear, quadratic, or double)
// @words_filename: a filename of input words to construct the hash table
// @query_filename: a filename of input words to test the hash table
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table,const string &words_filename,const string &query_filename) {
    cout << "Test Functions For Hash Tables" << "\n";
    cout << "Words Filename: " << words_filename << "\n";
    cout << "Query Filename: " << query_filename << "\n";

    hash_table.MakeEmpty();
    //..Insert your own code
    ifstream wordsFile;
    wordsFile.open(words_filename);
    if(wordsFile.fail()){cout<<"File Not Found!\n";}
    string line_1;
    while (getline(wordsFile, line_1)){
        hash_table.Insert(line_1);
    }
    wordsFile.close();
    cout << "number_of_elements: " << hash_table.getSize() << "\n";
    cout << "size_of_table: " << hash_table.getTableSize() << "\n";
    cout << "load_factor: " << hash_table.getLoadFactor() << "\n";
    cout << "average_collisions: " << hash_table.getAverageCollisions() << "\n";
    cout << "total_collisions: " << hash_table.getCollisions() << "\n";
    cout << "\n";

    ifstream queryFile;
    queryFile.open(query_filename);
    if(queryFile.fail()){cout<<"File Not Found!\n";}
    string line_2;
    while (getline(queryFile, line_2)){
        hash_table.clearCollisions();
        if(hash_table.Contains(line_2)){
            cout << line << " Found " << hash_table.getCollisions() + 1 << endl;        
        else 
            cout << line << " Not_Found " << hash_table.getCollisions() + 1 << endl;
        }
    }
    queryFile.close();

}

// @argument_count: argc as provided in main
// @argument_list: argv as provided in imain
// Calls the specific testing function for hash table (linear, quadratic, or double).
int testHashingWrapper(int argument_count, char **argument_list) {
    const string words_filename(argument_list[1]);
    const string query_filename(argument_list[2]);
    const string param_flag(argument_list[3]);
    int R = 89;
    if (argument_count == 5) {
        const string rvalue(argument_list[4]);
        R = stoi(rvalue);
    }

    if (param_flag == "linear") {
        cout << "Linear: " << "\n"; 
        HashTableLinear<string>linear_probing_table;
        TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);
    } else if (param_flag == "quadratic") {
        cout << "Quadratic:" << "\n";
        HashTable<string>quadratic_probing_table;
	    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);
    } else if (param_flag == "double") {
        cout << "Double:" << "\n"<< "r_value: " << R << "\n";
        // Uncomment below when you have implemented double hashing.
        HashTableDouble<string> double_probing_table;
        TestFunctionForHashTable(double_probing_table, words_filename, query_filename);
    } else {
	cout << "Unknown tree type " << param_flag<< " (User should provide linear, quadratic, or double)" << endl;
    }
    return 0;
}

// Sample main for program create_and_test_hash. DO NOT CHANGE IT.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testHashingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char **argv) {
    if (argc != 4 and argc != 5) {
	cout << "Usage: " << argv[0]
         << " <wordsfilename> <queryfilename> <flag>" << endl;
	cout << "or Usage: " << argv[0]
         << " <wordsfilename> <queryfilename> <flag> <rvalue>" << endl;
	return 0;
    }

    testHashingWrapper(argc, argv);
    return 0;
}
