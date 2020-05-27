#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class HuffmanNode{
public:
    HuffmanNode* left,* right;
    char character;

    HuffmanNode() {
        character = 0;
        left = right = nullptr;
    }

    HuffmanNode(char character, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr) {
        this->character = character;
        this->left = left;
        this->right = right;
    }

    HuffmanNode(const HuffmanNode& node) {
        character = node.character;
        left = node.left;
        right = node.right;
    }

    HuffmanNode & operator=(HuffmanNode& node) {
        left = node.left;
        right = node.right;
        character = node.character;
        return *this;
    }
    ~HuffmanNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};
#endif
