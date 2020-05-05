#ifndef HUFFMANENCODING_H
#define HUFFMANENCODING_H

#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "HuffmanNode.h"

#include <string>
#include <iostream>
#include <list>
class HuffmanEncoding{
	string input_;
	PriorityQueue<HuffmanNode> queue_;

	HuffmanEncoding();
public:
	void Input();
	void FillQueue();
   void CreateTree();
};
#endif
