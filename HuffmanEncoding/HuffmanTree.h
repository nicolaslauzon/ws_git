#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"

class HuffmanTree{

	HuffmanTree();

public:

	void HuffmanTraversal(HuffmanNode* node) {
		if (node->left){
			HuffmanTraversal(node->left);
		}
		if (node->right){
			HuffmanTraversal(node->right);
		}
	}
};
#endif
