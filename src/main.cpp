// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;
  
  const char* filename = "src/war_peace.txt";

  makeTree(tree, filename);

  std::cout << "Tree depth: " << tree.depth() << std::endl;
  
  std::cout << "Frequency of 'war': " << tree.search("war") << std::endl;
  std::cout << "Frequency of 'peace': " << tree.search("peace") << std::endl;
  std::cout << "Frequency of 'tolstoy': " << tree.search("tolstoy") << "\n\n";

  std::cout << "Generating frequency list (console & file)..." << std::endl;
  
  printFreq(tree);

  std::cout << "Done! Results saved in result/freq.txt" << std::endl;

  return 0;
}
