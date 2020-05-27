#ifndef FOLDER_H
#define FOLDER_H

#include "note.h"

#include <string>
#include <vector>

class Folder
{
    std::string name_;
    std::vector<Note> notes_;
    std::vector<Folder> folders_;

public:
    Folder(const std::string name);

    const std::string& Name() const { return name_; }
    void SetName(const std::string& name) { name_ = name; }

    int NoteCount() const {return notes_.size(); }
    int FolderCount() const {return folders_.size(); }

    bool isCompressed(int note);

    Folder* ThisFolder(int i) { return &folders_.at(i); }
    Note* ThisNote(int i) { return &notes_.at(i); }

    const std::string& NoteContent(int note) { return notes_.at(note).Content(); }
    void SetContent(const std::string& new_content, int note) { notes_[note].SetContent(new_content); }

    void CreateFolder(const std::string& name) { folders_.push_back(Folder(name)); }
    void CreateNote(const std::string& name) { notes_.push_back(Note(name)); }

    const std::string& FolderName(const int& i) { return folders_.at(i).Name(); }
    const std::string& NoteName(const int& i) { return notes_.at(i).Name(); }

    bool FolderNameAlredyInUse(const std::string& name);
    bool NoteNameAlredyInUse(const std::string& name);
};

#endif // FOLDER_H
