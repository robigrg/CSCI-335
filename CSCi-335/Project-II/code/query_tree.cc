// Robi Gurung
// query_tree.cc : parses two files and creates SequenceMaps,
// and adds them to the trees.


#include "avl_tree.h"
#include "bst_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace {

bool GetNextRecognitionSequence(string &line, string &seq) {
  seq = "";
  if (line[0] == '/')
  {
    return false;
  }
  while (line[0] != '/')
  {
    seq += line[0];
    line = line.substr(1);
    // line.erase(0,1);
  }
  line = line.substr(1);
  return true;
}

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  // Code for running Part2(a)
  // Parse input file @db_filename and feel tree @a_tree
  // Then prompt the user for exactly three strings (do a loop) and
  // provide the results of find() as described in the assignment.
  string db_line; 
  // Read the file line-by-line: 
  ifstream file(db_filename);
  if (!file.good())
  {
    cerr << "Error reading file" << endl;
    exit(1);
  }
  while (getline(file, db_line)) { 
    if (db_line[db_line.length() - 1] != '/')
    {
      continue;
    }
    // Get the first part of the line: 
    string an_enz_acro = db_line.substr(0, db_line.find("/"));
    db_line = db_line.substr(db_line.find("/") + 1);
    string a_reco_seq; 
    while (GetNextRecognitionSequence(db_line, a_reco_seq)) { 
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro); 
      a_tree.insert(new_sequence_map); 
    }  // End second while.  
  }  // End first while.
  file.close();

  string sequence;
  int temp_counter;
  for (int i = 0; i < 3; i++)
  {
    getline(cin, sequence);
    SequenceMap map{sequence, ""};
    if(a_tree.contains(map, temp_counter))
    {
      a_tree.print(map); 
    }
    else
    {
      std::cout << "Not Found\n";
    }
  }
}

}  // namespace

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string param_tree(argv[2]);
  cout << "Input filename is " << db_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    QueryTree(db_filename, a_tree);
  } 
  else if (param_tree == "AVL") {
    AvlTree<SequenceMap> a_tree;
    QueryTree(db_filename, a_tree);
  } 
  else {
    cout << "Unknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
