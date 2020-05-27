#include "HuffmanEncoding.h"

void HuffmanEncoding::BinaryToDecimal(std::list<int> &answer, std::list<unsigned char> total_solution)
{
    int int_equivalent = 0;
    for (std::list<unsigned char>::const_iterator i = total_solution.begin(); i != total_solution.end();) {
        for (int j = 7; j >= 0; --j) {
            if (*i) {
                int_equivalent += pow(2,j);
            }
            ++i;
        }
        answer.push_back(int_equivalent);
        int_equivalent = 0;
    }
}

bool HuffmanEncoding::HuffmanTraversal(HuffmanNode *node, std::list<unsigned char> &binary_code, char to_find)
{
    // If I find the char "to_find" return true
    if (node && node->character == to_find)
        return true;
    // If I can go left I do it
    if (node->left){
        binary_code.push_back(0);
        // If I find the char "to_find" return true
        if (HuffmanTraversal(node->left, binary_code,to_find)==true)
            return true;
        binary_code.pop_back();
    }
    // If I can go right I do it
    if (node->right){
        binary_code.push_back(1);
        // If I find the char "to_find" return true
        if (HuffmanTraversal(node->right, binary_code,to_find)==true)
            return true;
        binary_code.pop_back();
    }
    // If I don't find it return false
    return false;
}

HuffmanEncoding::HuffmanEncoding()
{
    input_ = key_ = "";
    queue_ = nullptr;
}

void HuffmanEncoding::FillQueue()
{
    queue_ = new PriorityQueue<HuffmanNode*>();
    int count = 1;
    std::string str = input_;
    while(str.size()) {
        // Detect the number of character that are equivalent and stock the result in "count".
        for(size_t i = 1; i < str.size();++i) {
            if(str.at(i) == str.at(0))
                ++count;
        }
        // Remove the character that are equivalent in the string "str".
        for(size_t i = 1; i < str.size();++i) {
            if(str.at(i) == str.at(0))
                str.erase(i--,1);
        }
        // Push the front character with the right count and then erase the character.
        queue_->push(new HuffmanNode(str.at(0)), count);
        str.erase(0,1);
        count = 1;
    }
}

void HuffmanEncoding::CreateKey()
{
    // Iterate on the "queue_" and create the "key_".
    PQIterator<HuffmanNode*>* i = queue_->begin();
    while ( i->End() ) {
        key_ += std::to_string(i->Priority()) + " '" + i->Data()->character + "' ";
        i->Iterate();
    } 
    key_.pop_back();
    delete i;
}

HuffmanNode* HuffmanEncoding::CreateTree()
{

    // Create the HuffmanNode tree.
    while (queue_->size() > 1) {
        // First node and his priority
        size_t priority = queue_->frontPriority();
        HuffmanNode* node1 = queue_->front();
        queue_->pop();

        // Second node and his priority
        priority += queue_->frontPriority();
        HuffmanNode* node2 = queue_->front();
        queue_->pop();

        // New node with "node1" and "node2" as his child
        queue_->push(new HuffmanNode(0, node1, node2), priority);
    }

    // Initialise the root of the tree and delete the "queue_"
    HuffmanNode* huffman_root;
    huffman_root = queue_->front();
    delete queue_;
    queue_ = nullptr;
    return huffman_root;
}

const std::string HuffmanEncoding::GetBinaryCode(HuffmanNode* huffman_root)
{

    struct HuffmanCode{
        char character;
        std::list<unsigned char> byte_equivalent;
    };
    // Contain the binary equivalent for each char in the "input_"
    std::list<HuffmanCode> binary_for_each_char;

    // Iterate on the "key_". This allow me to have each character in the string and pass them to "HuffmanTraversal"
    for (size_t i = 3; i < key_.size(); i+=6) {

        // Variable that contain the binary of the char at "i".
        std::list<unsigned char> binary_code;

        // If it find the char at "i" create a new HuffmanCode and push it in front of "binary_for_each_char"
        if (HuffmanTraversal(huffman_root, binary_code,key_.at(i))==true) {
            HuffmanCode new_value;
            new_value.character = key_.at(i);
            new_value.byte_equivalent = binary_code;
            binary_for_each_char.push_front(new_value);
        }
    }

    // Binary equivalent of the "input_"
    std::list<unsigned char> total_solution;


    // Initialise "total_solution"
    // iterate on "input_"
    for (size_t i = 0; i < input_.size(); ++i) {
        // iterate on "binary_for_each_char"
        for (std::list<HuffmanCode>::const_iterator j = binary_for_each_char.begin(); j != binary_for_each_char.end(); ++j) {

            if (input_.at(i) == j->character) {
                // Initialisation
                for (std::list<unsigned char>::const_iterator k = j->byte_equivalent.begin(); k != j->byte_equivalent.end(); ++k) {
                    total_solution.push_back(*k);
                }
            }
        }
    }

    // Push back some more bits if necessary
    while(total_solution.size() % 8) {
        total_solution.push_back(0);
    }

    // List containing the int equivalent of "binary_for_each_char"
    std::list<int> int_answer;

    // Initialisation of "int_answer"
    BinaryToDecimal(int_answer, total_solution);

    // String to print "int_answer"
    std::string answer;

    // Initialisation of "answer"
    for (std::list<int>::const_iterator i = int_answer.begin(); i != int_answer.end(); ++i) {
        answer += std::to_string(*i) + ' ';
    }
    delete huffman_root;
    return answer;
}

bool HuffmanEncoding::Encode(const std::string &input)
{
    input_ = input;
    FillQueue();
    CreateKey();
    input_ = GetBinaryCode(CreateTree());
    return true;
}
