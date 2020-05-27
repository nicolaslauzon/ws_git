#include "directory.h"

Directory::Directory()
{
    parent = new Folder("/");
    path_.push(parent);
}

Folder *Directory::MainDirectory() const
{
    return parent;
}

Folder *Directory::CurrentFolder() const
{
    return path_.top();
}

void Directory::CdUp()
{
    path_.pop();
}

void Directory::Cd(Folder *folder)
{
    path_.push(folder);
}

/*std::string Directory::CurrentPathString() const
{
    Stack<Folder*> path = path_;
    std::string path_string = "";
    while (path.size() > 0) {
        for (std::string::const_iterator i = path.top()->Name().begin(); i != path.top()->Name().end(); ++i) {
            path_string.push_back(*i);
        }
        if (path_string != "/") {
            path_string.push_back('/');
        }
        path.pop();
    }
    return path_string;
}*/

int Directory::ItemCount() const
{
    return path_.top()->NoteCount() + path_.top()->FolderCount();
}

Directory::DirectoryItemType Directory::ItemType(int index) const
{
    if (path_.size() == 1) {
        if (index >= ItemCount()) {
            return kUndefined;
        }
        if (index < path_.top()->FolderCount()) {
            return kFolder;
        }
        return  kNote;
    }
    if (index == 0) {
        return kParentFolder;
    }
    if (index > ItemCount()) {
        return  kUndefined;
    }
    if (index <= path_.top()->FolderCount()) {
        return kFolder;
    }
    return  kNote;
}

Note *Directory::NoteAtIndex(int index) const
{
    if (ItemType(index) == kNote) {
        if (path_.size() > 1) {
            if (index - path_.top()->FolderCount() - 1 >= 0) {
                return path_.top()->ThisNote(index - path_.top()->FolderCount() - 1);
            }
            else {
                return nullptr;
            }
        }
        if (index - path_.top()->FolderCount() >= 0) {
            return path_.top()->ThisNote(index - path_.top()->FolderCount());
        }
    }
    return nullptr;
}

Folder *Directory::FolderAtIndex(int index) const
{
    if (ItemType(index) == kFolder) {
        if (path_.size() > 1) {
            if (index - 1 >= 0) {
                return path_.top()->ThisFolder(index - 1);
            }
            else {
                return nullptr;
            }
        }
        if (index >= 0) {
            return path_.top()->ThisFolder(index);
        }
    }
    return nullptr;
}
