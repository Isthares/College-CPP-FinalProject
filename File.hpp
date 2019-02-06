//
//  File.hpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 24/04/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include "libraries.h"

template <int WORD_LENGTH, int WORD_COUNT>
class File {
    public:
        File(); //Constructor
        //open the file, insert the content of the file into an array of arrays of chars, close the file
        void insertFileIntoArray(const string filename, array<array<char, WORD_LENGTH>, WORD_COUNT>& words);
};

template <int WORD_LENGTH, int WORD_COUNT>
File<WORD_LENGTH, WORD_COUNT>::File() {}

//open the file, insert the content of the file into an array of arrays of chars, close the file
template <int WORD_LENGTH, int WORD_COUNT>
void File<WORD_LENGTH, WORD_COUNT>::insertFileIntoArray(const string fileName,
                                                        array<array<char, WORD_LENGTH>, WORD_COUNT>& words){
    ifstream fin;
    string aLine; //word from the file
    int count = 0;
    
    fin.open(fileName); //open the file
    
    if (!fin) {
        cerr << "Unable to open " << fileName << ". " << endl;
        exit(1);   // call system to stop
    }
    
    int index = 0; //index of the array words
    while (!fin.eof()) {
        getline(fin,aLine);
        for (int i = 0; i < WORD_LENGTH; i++) {
            words[index][i] = aLine[i];
        }
        index++;
        count++;
    }
    fin.close(); //close the file
}


#endif /* File_hpp */
