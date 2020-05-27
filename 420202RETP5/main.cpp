#include "BSTree.h"
#include "Stack.h"
#include "Window.hpp"
#include "directory.h"
#include "folder.h"

#include <iostream>

Window window;
Directory directory;
std::string title;
BSTree<int> selected;

int current_index;

int GetIndex(int x, int y) {
    x = (x - (x % 114) ) / 114;
    y = (y - (y % 128) ) / 128;
    if (!y) {
        return x;
    }
    int y_max_index = (window.getWidth() - window.getWidth() % 114) / 114;
    x += y_max_index * y - 1;
    return x;
}

void onInit() {
    title = directory.CurrentFolder()->Name();
}

void onClick(const SDL_Point& cursor, const bool& rightButton, const bool& ctrl) {

    // On left click and ctrl
    if (!rightButton && ctrl) {
        int index = GetIndex(cursor.x, cursor.y);
        if (index <= directory.ItemCount()) {
            if (selected.search(index)) {
                selected.remove(index);
            }
            else {
                selected.add(index);
            }
        }
        return;
    }

    current_index = GetIndex(cursor.x, cursor.y);
    Directory::DirectoryItemType clicking_on = directory.ItemType(current_index);

    // On left click
    if (!rightButton && !ctrl) {
        switch (clicking_on) {
        case Directory::kParentFolder:
            directory.CdUp();
            while (title.back() != '/') {
                title.pop_back();
            }
            if (title != "/") {
                title.pop_back();
            }
            break;
        case Directory::kFolder:
            directory.Cd(directory.FolderAtIndex(current_index));
            if (directory.PathSize() > 2) {
                title += "/" + directory.CurrentFolder()->Name();
            }
            else {
                title += directory.CurrentFolder()->Name();
            }
            break;
        case Directory::kNote:{
            std::string new_content = window.showTextBox(directory.NoteAtIndex(current_index)->Content());
            if (new_content != "") {
                directory.NoteAtIndex(current_index)->SetContent(new_content);
            }
            break;
        }
        case Directory::kEncodedNote:
            break;
        case Directory::kUndefined:
            selected.removeAll();
            break;
        }
        return;
    }

    // On right click
    if (rightButton && !ctrl) {
        int options = 0;

        switch (clicking_on) {
            case Directory::kUndefined:
                options = NEW_FOLDER | NEW_NOTE | SELECT_ALL;
                break;
            case Directory::kFolder:
                options = RENAME | DELETE | SELECT_ALL;
                selected.add(current_index);
                break;
            case Directory::kNote:
                options = RENAME | DELETE | ENCODE | SELECT_ALL;
                selected.add(current_index);
                break;
            case Directory::kEncodedNote:
                options = RENAME | DELETE | DECODE | SELECT_ALL;
                selected.add(current_index);
                break;
            case Directory::kParentFolder:
                return;
        }
        window.openContextMenu(cursor, options);
    }
}

void onMenuClick(const unsigned long& item) {
    switch (item) {
    case NEW_FOLDER: {
        std::string new_folder_name = window.showTextField("");
        if (new_folder_name == "") {
            return;
        }
        if (!directory.MainDirectory()->FolderNameAlredyInUse(new_folder_name)) {
            directory.CurrentFolder()->CreateFolder(new_folder_name);
        }
        break;
    }

    case NEW_NOTE: {
        std::string new_note_name = window.showTextField("");
        if (new_note_name == "") {
            return;
        }
        if (!directory.MainDirectory()->NoteNameAlredyInUse(new_note_name)) {
            directory.CurrentFolder()->CreateNote(new_note_name);
        }
    }
        break;
    case RENAME:
        if (selected.size() == 1) {
            if (selected.search(current_index)) {
                std::string new_name;
                if (directory.FolderAtIndex(current_index)) {
                    new_name = window.showTextField(directory.FolderAtIndex(current_index)->Name());
                    if (new_name != "") {
                        if (!directory.MainDirectory()->FolderNameAlredyInUse(new_name)) {
                            directory.FolderAtIndex(current_index)->SetName(new_name);
                        }
                    }
                }
                else {
                    new_name = window.showTextField(directory.NoteAtIndex(current_index - directory.CurrentFolder()->FolderCount())->Name());
                    if (new_name != "") {
                        if (!directory.MainDirectory()->NoteNameAlredyInUse(new_name)) {
                            directory.NoteAtIndex(current_index)->SetName(new_name);
                        }
                    }
                }
            }
            selected.remove(current_index);
        }
        break;
    case DELETE:
        break;
    case ENCODE:
        break;
    case DECODE:
        break;
    case SELECT_ALL:
        break;
    }
}

void onDraw() {

    // Set title
    window.setTitle(title.c_str());

    int drawing_width, drawing_height, string_height_offset;
    string_height_offset = 100;
    drawing_width = drawing_height = 0;

    // Draw the parent folder
    if (directory.PathSize() > 1) {
        if (window.getWidth() >= ICON_WIDTH && window.getHeight() >= ICON_HEIGHT) {
            window.drawIcon(drawing_width, drawing_height, FOLDER);
            int string_width_offset = (ICON_WIDTH - window.getStringWidth("..")) / 2;
            window.drawString(drawing_width + string_width_offset, drawing_height + string_height_offset, "..");
            drawing_width += ICON_WIDTH;
        }
    }

    // Draw all the folders
    for (int i = 0; i < directory.CurrentFolder()->FolderCount(); ++i) {
        if (drawing_width + ICON_WIDTH > window.getWidth()){
             drawing_height += ICON_HEIGHT;
             drawing_width = 0;
        }
        if (window.getWidth() >= ICON_WIDTH + drawing_width && window.getHeight() >= ICON_HEIGHT + drawing_height) {
            window.drawIcon(drawing_width, drawing_height, FOLDER, selected.search(GetIndex(drawing_width,drawing_height)));
            if (window.getStringWidth(directory.CurrentFolder()->FolderName(i).c_str()) < ICON_WIDTH) {
                int string_width_offset = (ICON_WIDTH - window.getStringWidth(directory.CurrentFolder()->FolderName(i).c_str())) / 2;
                window.drawString(drawing_width + string_width_offset, drawing_height + string_height_offset, directory.CurrentFolder()->FolderName(i).c_str());
            }
            else {
                std::string name = directory.CurrentFolder()->FolderName(i);
                while (window.getStringWidth((name + " ...").c_str()) > ICON_WIDTH) {
                    name.pop_back();
                }
                int string_width_offset = (ICON_WIDTH - window.getStringWidth((name + " ...").c_str())) / 2;
                window.drawString(drawing_width + string_width_offset, drawing_height + string_height_offset, (name + " ...").c_str());
            }
        }
        if (drawing_width + ICON_WIDTH <= window.getWidth()) {
            drawing_width += ICON_WIDTH;
        }
    }
    // Draw all the notes
    for (int i = 0; i < directory.CurrentFolder()->NoteCount(); ++i) {
        if (drawing_width + ICON_WIDTH > window.getWidth()){
             drawing_height += ICON_HEIGHT;
             drawing_width = 0;
        }
        if (window.getWidth() >= ICON_WIDTH + drawing_width && window.getHeight() >= ICON_HEIGHT + drawing_height) {
            if (directory.CurrentFolder()->isCompressed(i)) {
                 window.drawIcon(drawing_width, drawing_height, ENCODED, selected.search(GetIndex(drawing_width,drawing_height)));
            }
            else {
                window.drawIcon(drawing_width, drawing_height, NOTE, selected.search(GetIndex(drawing_width,drawing_height)));
            }
            if (window.getStringWidth(directory.CurrentFolder()->NoteName(i).c_str()) < ICON_WIDTH) {
                int string_width_offset = (ICON_WIDTH - window.getStringWidth(directory.CurrentFolder()->NoteName(i).c_str())) / 2;
                window.drawString(drawing_width + string_width_offset, drawing_height + string_height_offset, directory.CurrentFolder()->NoteName(i).c_str());
            }
            else {
                std::string name = directory.CurrentFolder()->NoteName(i).c_str();
                while (window.getStringWidth((name + " ...").c_str()) > ICON_WIDTH) {
                    name.pop_back();
                }
                int string_width_offset = (ICON_WIDTH - window.getStringWidth((name + " ...").c_str())) / 2;
                window.drawString(drawing_width + string_width_offset, drawing_height + string_height_offset, (name + " ...").c_str());
            }
        }
        if (drawing_width + ICON_WIDTH <= window.getWidth()) {
            drawing_width += ICON_WIDTH;
        }
    }
}

void onClose() {
}

int main(int argc, char* argv[]) {
  window.open(onInit, onClick, onMenuClick, onDraw, onClose);
  return 0;
}
