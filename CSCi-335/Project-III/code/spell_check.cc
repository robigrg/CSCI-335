// Robi Gurung
// Professor Ionnis Stamos
// CSCI 335
// 4 November 2021
// spell_check.cc: source file that checks spelling of the words by removing characters, 
// adding characters and swapping characters
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>

// You can change to quadratic probing if you
// haven't implemented double hashing.
#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"

using namespace std;

// You can add more functions here.

// Creates and fills double hashing hash table with all words from
// dictionary_file
HashTableDouble<string> MakeDictionary(const string &dictionary_file) {
  HashTableDouble<string> dictionary_hash;
  // Fill dictionary_hash.
  HashTableDouble<string> dictionary_hash;
  ifstream input_file;
  input_file.open(dictionary_file);

  if (input_file.fail()){cout << "File Not Found!\n";exit(1);}

  string line_3;
  while (getline(input_file, line_3))
  {
    dictionary_hash.Insert(line_3);
  }
  input_file.close();
  return dictionary_hash;
}


// For each word in the document_file, it checks the 3 cases for a word being
// misspelled and prints out possible corrections
void SpellChecker(const HashTableDouble<string>& dictionary,const string &document_file) {
  ifstream document;
  document.open(document_file);

  if (document.fail()){ cout << "File Not Found!\n"; exit(1);}

  string line;

  while(document >> line){
    for(size_t i = 0; i < line.length(); i++){ //reads each word
      line[i] = tolower(line[i]);
    size_t mark = line.length()-1;
    while (line[mark] < 'a' || line[mark] > 'z')
    {
      // break if we encounter an integer
      if (line[mark] >= '0' && line[mark] <= '9')
        break;
      line = line.substr(0, mark);
      mark = mark-1;
    }
    //if the word is found in the dictionary
    //output as the word is correct
    if(dictionary.Contains(word)){
      cout << line<< " is CORRECT\n";
    else{
      cout << line << " is INCORRECT\n"; 
      //Rule a) Adding one character in any possible position
      for(size_t i = 0; i< line.length()+1; i++){
        //iterates through ever alphabet letter
        for(size_t letter = 'a'; letter<= 'z'; letter++){
          //inserts into i position (1 letter)
          string word = line;
          string temp(1, (char)letter);
          line.insert(i, temp);
          if (dictionary.Contains(line))
            cout << "*** " << line << " -> " << word << " *** case A" << endl;
        }
      }

      // CASE B: one extra letter
      for (size_t i = 0; i < line.length(); i++)
      {
        string word = line;
        word.erase(i, 1);
        if (dictionary.Contains(word))
          cout << "*** " << line << " -> " << word << " *** case B" << endl;
      }
      // CASE C: swapping adjacent characters
      for (size_t i = 0; i < line.length() - 1; i++)
      {
        string word = line;
        char temp = word[i];
        word[i] = word[i + 1];
        word[i + 1] = temp;
        if (dictionary.Contains(word))
          cout << "*** " << line << " -> " << word << " *** case C" << endl;
      }
    }
  }
  document.close();
}

// @argument_count: same as argc in main
// @argument_list: save as argv in main.
// Implements
int testSpellingWrapper(int argument_count, char** argument_list) {
    const string document_filename(argument_list[1]);
    const string dictionary_filename(argument_list[2]);

    // Call functions implementing the assignment requirements.
    HashTableDouble<string> dictionary = MakeDictionary(dictionary_filename);
    SpellChecker(dictionary, document_filename);

    return 0;
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>"<< endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);
  
  return 0;
}
