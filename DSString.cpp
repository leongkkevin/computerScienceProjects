//
// Created by Kevin Leong on 9/16/20.
//

#include "DSString.h"

DSString::DSString() {

    this->size = 0;
    this->capacity = this->size+1;
    this-> data = new char[this->capacity];
    data[capacity - 1] = '\0';
}

DSString::DSString(const char *newData) {
    this->size = strlen(newData);
    this->capacity = this->size + 1;
    this->data = new char[this->capacity];

    if(this->size != 0){
        strcpy(this->data, newData);
        data[capacity - 1] = '\0';
    }
}

DSString::DSString(const DSString &copyString) {
    this->size = copyString.size;
    this->capacity = copyString.capacity;
    this->data = new char[this->capacity];
    strcpy(this->data, copyString.data);
    data[capacity - 1] = '\0';
}

DSString::~DSString() {
    delete[] data;
}

//Overloaded Operators

DSString &DSString::operator=(const char *newData) {
    int wordLength = createLength(newData);

    //resize if necessary
    if(wordLength >= this->capacity){
        resize(wordLength);
    }

    //set new size
    this->size = wordLength;

    //recreate data
    if(this->capacity !=0){
        delete[] this->data;
    }
    this-> data = new char[this->capacity];

    //copy data into this data
    strcpy(this->data, newData);
    this->data[capacity - 1] = '\0';

    return *this;
}

DSString &DSString::operator=(const DSString &sourceString) {

    //set new size
    this->size = sourceString.size;
    //set capacity
    this->capacity = this->size + 1;

    //recreate data
    if(this->capacity !=0){
        delete[] this->data;
    }
    this->data = new char[capacity];

    //copy data into this data
    strcpy(this->data, sourceString.data);
    //this->data[capacity - 1] = '\0';

    return *this;
}

DSString DSString::operator+(const DSString &addString) {
    DSString copy = *this;
    copy.size = this->getLength();
    copy.capacity = this->getCap();

    //resize if necessary
    if(addString.size + copy.getLength() >= copy.getCap()){
        copy.resize(addString.size + copy.getLength());
    }

    //copy data in data's data
    int j = 0;
    for(int i = copy.getLength(); i < copy.getCap(); ++i) {
        copy.data[i] = addString.data[j];
        copy.size++;
        ++j;
    }
    copy.data[copy.getCap() - 1] = '\0';

    //get rid of null terminator count
    copy.size--;
    return copy;
}

std::ostream &operator<<(std::ostream &out, const DSString &outString) {
    for(int i = 0; i < outString.getLength(); ++i){
        out << outString.data[i];
    }
    return out;
}

bool DSString::operator==(const char *compString) const {
    bool returnBool = false;
    if(strcmp(this->data, compString) < 0 || strcmp(this->data, compString) > 0){
        returnBool = false;
    } else if (strcmp(this->data, compString) == 0){
        returnBool = true;
    }
    return returnBool;
}

bool DSString::operator==(const DSString &compString) const{
    bool returnBool = false;
    if(strcmp(this->data, compString.data) < 0 || strcmp(this->data, compString.data) > 0){
        returnBool = false;
    } else if (strcmp(this->data, compString.data) == 0){
        returnBool = true;
    }

    return returnBool;
}

bool DSString::operator>(const DSString &compString) const{
    return strcmp(this->data, compString.data) > 0;
}

bool DSString::operator<(const DSString &compString) const{
    if(isdigit(compString.getData()[0])){
        int thisNum = atoi(this->data);
        int compNum = atoi(compString.getData());
        return thisNum < compNum;
    }else {
        return strcmp(this->data, compString.data) < 0;
    }
}

char &DSString::operator[](const int location) {

    return this->data[location];
}


//Assorted Functions

void DSString::resize(int newLength){
    //copy the data from initial data
    char temp[capacity];
    for(int i = 0; i < capacity; i++){
        temp[i] = data[i];
    }

//    delete old data
    if(this->size != 0) {
        delete[] this->data;
    }

    //new data with new capacity;
    this->data = new char[newLength + 1];

    //set the new data with temp copy
    for(int i = 0; i < this->size; i++){
        this->data[i] = temp[i];
    }

    //set a new capacity
    this->capacity = newLength + 1;

    //new null terminator
    this->data[capacity - 1] = '\0';
}

int DSString::createLength(const char *newData){
    return strlen(newData);
}

int DSString::getLength() const {
    return this->size;
}
int DSString::getCap() {
    return this->capacity;
}

char * DSString::getData() const {
    return this->data;
}

void DSString::append(char addData){

    resize(this->size + 1);

    this->data[this->size] = addData;
    this->data[this->capacity - 1] = '\0';

    //change size
    this->size = this->capacity - 1;
}

//returns a part of the DSString (from start and numChars characters down)
DSString DSString::substring(int start, int numChars) {

    char *subChars = new char[numChars + 1];

    int j = 0;
    for(int i = start; i < numChars; ++i){
         subChars[j] = this->getData()[i];
        j++;
    }

    subChars[numChars] = '\0';

    DSString sub(subChars);

    delete[] subChars;

    return sub;
}

char *DSString::c_str() {
    return this->data;
}

int DSString::hasAt(char checkChar, int start) {
    int index = -1;
    for(int i = start; i < this->getLength(); ++i){
        if(this->getData()[i] == checkChar){
            index = i;
            break;
        }
    }

    return index;
}




