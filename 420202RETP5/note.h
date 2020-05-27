#ifndef NOTE_H
#define NOTE_H

#include <string>

#include "HuffmanEncoding.h"

class Note
{
   std::string name_, content_;
   bool is_compressed_;
public:
    Note(const std::string& new_name);

    const std::string& Content() const { return content_; }
    const std::string& Name() const { return name_; }

    void SetName(const std::string& new_name) { name_ = new_name; }
    void SetContent(const std::string& new_content) { content_ = new_content; }
    const bool& IsCompressed() { return is_compressed_; }
    void EncodeThis();
};

#endif // NOTE_H
