// Copyright 2023
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "bst.h"

void extractNodes(BST<std::string>::Node* node,
                  std::vector<std::pair<std::string, int>>& vec) {
  if (node != nullptr) {
    extractNodes(node->left, vec);
    vec.push_back({node->value, node->count});
    extractNodes(node->right, vec);
  }
}

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return;
  }

  std::string current_word = "";

  while (!file.eof()) {
    int ch = file.get();
    if (ch == EOF) break;

    if (std::isalpha(static_cast<unsigned char>(ch))) {
      current_word += std::tolower(static_cast<unsigned char>(ch));
    } else {
      if (!current_word.empty()) {
        tree.insert(current_word);
        current_word = "";
      }
    }
  }

  if (!current_word.empty()) {
    tree.insert(current_word);
  }

  file.close();
}

void printFreq(BST<std::string>& tree) {
  std::vector<std::pair<std::string, int>> freqList;
  extractNodes(tree.getRoot(), freqList);

  std::sort(freqList.begin(), freqList.end(),
            [](const std::pair<std::string, int>& a,
               const std::pair<std::string, int>& b) {
              return a.second > b.second;
            });

  std::ofstream outFile("result/freq.txt");
  if (!outFile.is_open()) {
    std::cerr << "Error: Can't open result/freq.txt" << std::endl;
  }

  for (const auto& p : freqList) {
    std::cout << p.first << " " << p.second << "\n";
    if (outFile.is_open()) {
      outFile << p.first << " " << p.second << "\n";
    }
  }

  if (outFile.is_open()) {
    outFile.close();
  }
}
