#ifndef HUFFMAHNODE_H
#define HUFFMANNODE_H


class HuffmanNode{
public:
	HuffmanNode* left, right;
	char character;
	HuffmanNode(char character, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr) {
		this->character = character;
		this->left = left;
		this->right = right;
	}
   HuffmanNode & operator=(HuffmanNode& node) {
      left = node.left;
      right = node.right;
      character = node.character;
      return *this;
   }
};
#endif
