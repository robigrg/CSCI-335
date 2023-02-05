// Robi Gurung
// test_tree_mod.cc : modified version of test_tree.cc file

#include "avl_tree.h"
#include "bst_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
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
  }
  line = line.substr(1);
  return true;
}

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Part 1
  string db_line; 
  // Read the file line-by-line: 
  ifstream db_file(db_filename);
  if (!db_file.good())
  {
    cerr << "Error reading file" << endl;
    exit(1);
  }
  while (getline(db_file, db_line)) { 
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
  db_file.close();

  // Part 2
  int total_nodes = a_tree.totalNodes();
  cout << "2: " << total_nodes << endl;
  
  // Part 3a
  float average_depth = float(a_tree.depth(0)) / float(total_nodes);
  cout << "3a: " << average_depth << endl;
  
  // Part 3b
  float ratio = average_depth / log2(total_nodes);
  cout << "3b: " << ratio << endl;
  
  // Part 4a
  string word;
  int temp_counter = 0;
  ifstream seq_file(seq_filename);
  int successful_queries = 0;
  while(seq_file >> word) 
  {
    SequenceMap map(word, "");  
    bool success = a_tree.contains(map, temp_counter);
    if (success)
    {
      successful_queries++;
    }
  }
  seq_file.close();
  cout << "4a: " << successful_queries << endl;

  // Part 4b
  seq_file.open(seq_filename);
  int recursion_counter = 0;
  while(seq_file >> word) 
  {
    SequenceMap map(word, ""); 
    a_tree.contains(map, recursion_counter);
  }
  seq_file.close();
  cout << "4b: " << float(recursion_counter) / successful_queries << endl;
  
  // Part 5a
  seq_file.open(seq_filename);
  int state = 0;
  int delete_counter = 0;
  while(getline(seq_file, word)) {
    if(state % 2 == 0) {
      SequenceMap map(word, "");
      if (a_tree.contains(map, temp_counter))
      {
        a_tree.remove(map, delete_counter);
      }
    }
    state++;
  }
  seq_file.close();
  cout << "5a: " << (total_nodes - a_tree.totalNodes()) << endl;
  
  // Part 5b
  cout << "5b: " << float(delete_counter) / (total_nodes - a_tree.totalNodes()) << endl;

  // Part 6a
  total_nodes = a_tree.totalNodes();
  cout << "6a: " << total_nodes << endl;

  // Part 6b
  average_depth = float(a_tree.depth(0)) / total_nodes;
  cout << "6b: " << average_depth << endl;
  
  // Part 6c
  ratio = average_depth / log2(total_nodes);
  cout << "6c: " << ratio << endl; 

}

}  // namespace

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  const string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  cout << "Type of tree is " << param_tree << endl;
  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else if (param_tree == "AVL") {
    AvlTree<SequenceMap> a_tree;
    TestTree(db_filename, seq_filename, a_tree);
  } else {
    cout << "Unknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
