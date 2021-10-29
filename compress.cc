/******************************************************************************
 *
 * Name: Madison Monroe	
 *
 * Date: 12/13/19	
 *
 * Assignment: Project 7 (Compression)
 *
 * Purpose: To compress and uncompress files.	
 *
 *****************************************************************************/
#include <iostream>
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "BitOstream.h"
#include "BitIstream.h"
#include <string>
#include <fstream>
using namespace std;

bool matchSuffix(string input, string suffix) {
  return input.substr(input.length() - suffix.length()) == suffix;
  }

void computeFrequencies(size_t (&frequencies)[256], string file){
  for (size_t i = 0; i < file.length(); i++)
    frequencies[(int)file[i]]++;
}

HuffmanTree* createTree(HuffmanTree* tree) {
  unsigned char c;
  if (!tree)
    return nullptr;
  
   cin >> noskipws >> c;

   //Internal Node
  if (c == 'I') {
    tree->Left = createTree(new HuffmanTree ('#', 0));
    tree->Right = createTree(new HuffmanTree('#',0));
    tree->Value = tree->Right->Value;
    return tree;
  }

  //Leaf Node- (need to read in next char to find leaf node's value)
  cin >> noskipws >> c;
  return new HuffmanTree (c, 0);
}

HuffmanTree* freqToTree(size_t (&frequencies)[256]) {
  PriorityQueue p(256);
  for (size_t i = 0; i < 256; i++)
    //figure out why byte doesn't work but size_t does

    //Creating Huffman trees from frequenies
    if (frequencies[i] != 0)
      p.enqueue(new HuffmanTree(i, frequencies[i]));

  //combining Huffman Trees that are the two least frequent
  while (p.length() > 1) {
    HuffmanTree* left = p.front();
    p.dequeue();
    HuffmanTree* right = p.front();
    p.dequeue();
    HuffmanTree* tree = new HuffmanTree(right->Value,
                       left->Frequency + right->Frequency, left, right);
    p.enqueue(tree);
  }
  return p.front();
}

//builds a str representation of a Huffman Tree
void strRepresent(HuffmanTree* tree) {

   if (!tree)
    return;

   if (tree->isLeaf())
     cout << "L" <<tree->Value;

  else
    cout << "I";

  strRepresent(tree->Left);
  strRepresent(tree->Right);
  }

//encodes bit values based on tree shape and value. Returns the encoding
string encode(HuffmanTree* tree, size_t value, string encoding = "") {
  
  if (!tree)
    return "";
  
  if (tree->Value == value && !tree->Left && !tree->Right)
    return encoding;

  return (encode(tree->Right, value, encoding + "1") +
          encode(tree->Left, value, encoding + "0"));
}

//adds the encodings to the encodings array
void arrEncode(HuffmanTree* tree, string (&encodings)[256],
               size_t (&frequencies)[256]) {

   for (size_t i = 0; i < 256; i++)
    if (frequencies[i] != 0)
      encodings[i] = encode(tree, i);
      }

void readTree(HuffmanTree* tree, BitIstream& bis) {
  unsigned char c;
  if (!tree->Left && !tree->Right) {
    if (!cin.fail())
      cout << tree->Value;
    return;
      }

  bis >> c;
  if (c == '0')
    readTree(tree->Left, bis);

  else if (c == '1')
    readTree(tree->Right, bis);

}

int main(int argc, char* argv[]) {

  bool uncompress = matchSuffix(argv[0],"uncompress");
    
  if (!uncompress) {
  BitOstream bs;

  size_t frequencies[256];
  string encodings[256];

  for (size_t i = 0; i < 256; i++) {
    frequencies[i] = 0;
    encodings[i] = "";
  }

  ifstream fin(argv[1]);
  if (fin.is_open()) {
    unsigned char c;

    //keeps track of the number of times a char is read in
    while (fin >> noskipws >> c)
      frequencies[(int)c]++;

    //resets fin so that it can be gone through again
    fin.clear();
    fin.seekg(0);

    HuffmanTree* ntree = freqToTree(frequencies);
      if(ntree) {
        bs << ntree->Frequency;
        bs << ntree;
        arrEncode(ntree, encodings, frequencies);

        while (fin >> noskipws >> c)
          bs << encodings[(HuffmanTree::byte) c];

        delete ntree;
      }

      else
        cout << 0;
    
  }
  
  else
      cout << "0";
  }

  else {
    size_t size;
    cin >> noskipws >> size;
    if (!cin.fail()) {
      HuffmanTree* tree = createTree(new HuffmanTree('#', 0));
      BitIstream bis (size, tree);

      while (size > 0) {
        readTree(tree, bis);
        if (cin.fail())
          break;
        size--;
      }
    }
  }
}



