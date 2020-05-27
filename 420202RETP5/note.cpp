#include "note.h"

Note::Note(const std::string& new_name)
{
    name_ = new_name;
    content_ = "";
    is_compressed_ = false;
}

void Note::EncodeThis()
{
    HuffmanEncoding encoding_technique;
    encoding_technique.Encode(content_);
    content_ = "<K>";
    content_ += encoding_technique.Key();
    content_ += "</K>\n";
    content_ += encoding_technique.BinaryCode();
    is_compressed_ = true;
}
