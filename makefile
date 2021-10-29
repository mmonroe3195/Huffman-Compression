compress: compress.o HuffmanTree.o BitOstream.o PriorityQueue.o BitIstream.o
	c++ -o compress compress.o HuffmanTree.o BitOstream.o PriorityQueue.o BitIstream.o

compress.o: compress.cc
	c++ -c compress.cc

HuffmanTree.o: HuffmanTree.cc HuffmanTree.h
	c++ -c HuffmanTree.cc

BitOstream.o: BitOstream.cc BitOstream.h
	c++ -c BitOstream.cc

PriorityQueue.o: PriorityQueue.cc PriorityQueue.h
	c++ -c PriorityQueue.cc

BitIstream.o: BitIstream.cc BitIstream.h
	c++ -c BitIstream.cc
