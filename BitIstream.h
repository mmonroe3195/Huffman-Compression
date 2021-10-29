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

#ifndef BITISTREAM_H
#define BITISTREAM_H
#include "HuffmanTree.h"
#include <string>

class BitIstream {

 public:
  BitIstream(size_t& size, HuffmanTree*& tree);
  HuffmanTree* readTree();
  BitIstream& operator >> (unsigned char& bit);
  ~BitIstream();

 private:
  size_t Size;
  HuffmanTree* Tree;
  std::string Bits;
  
};

std::string getBits();
#endif
