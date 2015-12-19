#include "Tape.h"
#include <iostream>
#include <vector>
#include <assert.h>

Tape::Tape(){
    cursor = CONTENT_OFFSET;
    for (int i = 0; i < CONTENT_OFFSET; i++) {
        content.push_back(' ');
    }
    content.push_back(' ');
    for (int i = 0; i < CONTENT_ENDING; i++) {
        content.push_back(' ');
    }
}

Tape::Tape(vector<char> cont){
    cursor = CONTENT_OFFSET;
	// add a blank at the beginning
    for (int i = 0; i < CONTENT_OFFSET; i++) {
        content.push_back(' ');
    }
    // deep copy content
    for (char c : cont) {
        content.push_back(c);
    }
	// add a blank at the end
    for (int i = 0; i < CONTENT_ENDING; i++) {
        content.push_back(' ');
    }
}

void Tape::setChar(char c){
    content[cursor] = c;
}

char Tape::getChar() const{
    return content[cursor];
}

/* Move the cursor
 * i=r : right
 * i=l : left
 */
void Tape::move(const char mov){
	assert(mov == 'l' || mov == 'r');
	if (mov == 'l')
		cursor--;
	else
		cursor++;
}

int Tape::getCursor() const{
    return cursor;
}

vector<char> Tape::getContent() const{
    return content;
}
