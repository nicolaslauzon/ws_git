#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Stack.h"
#include "folder.h"



class Directory
{
public:
    enum DirectoryItemType
    {
        kParentFolder=0,
        kFolder=1,
        kNote=2,
        kEncodedNote=3,
        kUndefined=4
    };

    Directory();

    Folder *MainDirectory() const;
    Folder *CurrentFolder() const;

    void CdUp();
    void Cd(Folder *folder);

    int ItemCount() const;
    DirectoryItemType ItemType(int index) const;

    Note *NoteAtIndex(int index) const;
    Folder *FolderAtIndex(int index) const;

    size_t PathSize() const { return path_.size(); }
private:
    Folder* parent;
    Stack<Folder*> path_;

};

#endif // DIRECTORY_H
