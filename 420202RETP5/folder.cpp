#include "folder.h"

Folder::Folder(const std::string name)
{
    name_ = name;
}

bool Folder::isCompressed(int note)
{
    return notes_.at(note).IsCompressed() ? true : false;
}

bool Folder::FolderNameAlredyInUse(const std::string &name)
{
    for(size_t i = 0; i < folders_.size(); ++i) {
        if (name == folders_.at(i).Name()) {
            return true;
        }
        if (folders_.at(i).FolderNameAlredyInUse(name)) {
            return true;
        }
    }
    return false;
}

bool Folder::NoteNameAlredyInUse(const std::string &name)
{
    for(size_t i = 0; i < notes_.size(); ++i) {
        if (name == notes_.at(i).Name()) {
            return true;
        }
    }
    for(size_t i = 0; i < folders_.size(); ++i) {
        if (folders_.at(i).NoteNameAlredyInUse(name)) {
            return true;
        }
    }
    return false;
}
