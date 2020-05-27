#ifndef HUFFMANENCODING_H
#define HUFFMANENCODING_H

#include "PriorityQueue.h"
#include "HuffmanNode.h"
#include "PQIterator.h"

#include <iostream>
#include <string>
#include <list>
#include <cmath>

class HuffmanEncoding{

    // Input string
    std::string input_;

    // Decoding key
    std::string key_;

    // PriorityQueue
    PriorityQueue<HuffmanNode*>* queue_;

    // Basic binary to decimal converter
    void BinaryToDecimal(std::list<int> &answer, std::list<unsigned char> total_solution);

    // Get to "to_find" in the tree from root "node".
    // Push_back a "0" when going left and "1" when going right in "binary_code"
    bool HuffmanTraversal(HuffmanNode* node, std::list<unsigned char> &binary_code, char to_find = 0);


    // 1rst step of the encoding: Fill "queue_"
    void FillQueue();

    // 2nd step of the encoding: initialise "key_" with "queue_"
    void CreateKey();

    // 3rd step of the encoding: create the huffmanNode tree from "queue_"
    HuffmanNode* CreateTree();

    // Last step of the encoding: get the encoded string from the tree
    const std::string GetBinaryCode(HuffmanNode* huffman_root);


public:

    // Main constructor
    HuffmanEncoding();

    // Encode
    bool Encode(const std::string &input);

    const std::string& BinaryCode() { return input_; }
    const std::string& Key() { return key_; }
};
#endif
