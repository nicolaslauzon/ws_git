#include "HuffmanEncoding.h"

HuffmanEncoding::HuffmanEncoding() {
	input = "";
}

void HuffmanEncoding::Input() {
	std::cout << "Entrez la chaine de caractere a encoder: " << std::endl;
	std::getline(std::cin, input_);
}

void HuffmanEncoding::FillQueue() {
	int count = 0;
	for(size_t i = 0; i < input_.size; ++i) {
		for(size_t j = i+1; j < input_.size; ++j) {
			if(input_.at(i) == input_.at(j)) {
				count += 1;
				input_.erase(j);
				j -= 1;
			}
		}
		queue_.push(HuffmanNode(input.at(i)), count);
		input.erase(i);
		i -= 1;
		count = 0;
	}
}

void HuffmanEncoding::CreateTree() {
   size_t priority = queue_.frontPriority();
   HuffmanNode* huffman_node1 = &queue_.front();
   queue_.pop;
   priority += queue_.frontPriority();
   HuffmanNode* huffman_node2 = &queue_.front();
   queue_.pop;
   queue_.push(HuffmanNode(' ', huffman_node1, huffman_node2), priority);
   if (queue_.size() > 1)
      CreateTree();
}
