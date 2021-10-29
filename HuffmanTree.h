/******************************************************************************
 *
 * Name: Madison Monroe	
 *
 * Date: 12/13/19	
 *
 * Assignment: Project 7 (Compression)
 *
 * Purpose:	
 *
 *****************************************************************************/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <cstddef>

class HuffmanTree {

 public:
  typedef unsigned char byte;

  // Purpose: Constructor
  // Pre: None
  // Post: A Huffman tree is created
  HuffmanTree(byte value, size_t freq, HuffmanTree* left = NULL,
              HuffmanTree* right = NULL);
  // Purpose: Comparison operator (<)
  // Pre: None
  // Post: If this tree's frequency is less than other's, return true,
  // otherwise return false.
  bool operator < (const HuffmanTree& other) const;

  // Purpose: Determines if it is a leaf
  // Pre: None.
  // Post: If the Huffman Tree pointer is a leaf, true is returned.
  //       Otherwise, false
  bool isLeaf();
  byte Value;
  size_t Frequency;
  HuffmanTree* Left;
  HuffmanTree* Right;
  ~HuffmanTree();
  void destroy();
};
  

#endif
