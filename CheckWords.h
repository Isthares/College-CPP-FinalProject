//
//  CheckWords.h
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 12/05/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#ifndef CheckWords_h
#define CheckWords_h

#include "libraries.h"
#include "UserWords.hpp"
#include "Menu.hpp"
#include "File.hpp"

template <int WORD_LENGTH, int WORD_COUNT>
class CheckWords {
    public:
        //constructor
        CheckWords();
        //convert the content of a string to upper case
        string toUpperCase (const string inputWord);
        //validates that a given word is in the dictionary
        bool existInDict(const array<char, WORD_LENGTH>& startW,
                         const array<array<char, WORD_LENGTH>, WORD_COUNT>& dictionary);
        //check that the word entered is valid
        bool validateWord(string startW, array<char, WORD_LENGTH>& startWord,
                          array<array<char, WORD_LENGTH>, WORD_COUNT>& dict);
        //manage the chosen option
        void manageOption(array<array<char, WORD_LENGTH>, WORD_COUNT>& dictionary, array<char, WORD_LENGTH>& startW,
                          array<char, WORD_LENGTH>& endW, UserWords& UW, const string filename);
    
};

template <int WORD_LENGTH, int WORD_COUNT>
//constructor
CheckWords<WORD_LENGTH, WORD_COUNT>::CheckWords(){}

//convert the content of a string to upper case
template <int WORD_LENGTH, int WORD_COUNT>
string CheckWords<WORD_LENGTH, WORD_COUNT>::toUpperCase (const string inputWord) {
    string ret;
    transform(inputWord.begin(), inputWord.end(), ret.begin(), ::toupper);
    return (ret);
}

template <int WORD_LENGTH, int WORD_COUNT>
//validates that a given word is in the dictionary
bool CheckWords<WORD_LENGTH, WORD_COUNT>::existInDict(const array<char, WORD_LENGTH>& startW,
                                                      const array<array<char, WORD_LENGTH>, WORD_COUNT>& dictionary) {
    WorldLadder<WORD_LENGTH, WORD_COUNT> WL;
    int index = WL.getIndexWord(dictionary, startW, 0, int(dictionary.size()) - 1);
    if (index == -1) {
        return (false);
    }
    else {
        return (true);
    }
}

template <int WORD_LENGTH, int WORD_COUNT>
//check that the word entered is valid
bool CheckWords<WORD_LENGTH, WORD_COUNT>::validateWord(string startW, array<char, WORD_LENGTH>& startWord,
                                                 array<array<char, WORD_LENGTH>, WORD_COUNT>& dict) {
    
    //check if the string has a valid length
    if (WORD_LENGTH != startW.length()) {
        //cout << "validWord: size: " << length << ", " << inputWord.length() << endl;
        return (false);
    }
    else {
        //check that the string has only letters
        for (int i = 0; i < startW.length(); i++){
            //Converting inputWord[i] to upper case version of character
            int upperCaseChar = toupper(startW[i]);
            if ((upperCaseChar < 'A') || (upperCaseChar > 'Z')) { //If character is not A-Z
                return (false);
            }
        }
        
        //convert to uppercase
        startW = toUpperCase(startW);
        
        for (int i = 0; i < WORD_LENGTH; i++) {
            startWord[i] = startW[i];
        }
        
        //validate that it is in the dictionary
        //if (existInDictThree(startWord, dict)) {
        if (existInDict(startWord, dict)) {
            return (true);
        }
        else {
            return (false);
        }
    }
}

template <int WORD_LENGTH, int WORD_COUNT>
//manage the chosen option
void CheckWords<WORD_LENGTH, WORD_COUNT>::manageOption(array<array<char, WORD_LENGTH>, WORD_COUNT>& dictionary,
                                                 array<char, WORD_LENGTH>& startW, array<char, WORD_LENGTH>& endW,
                                                 UserWords& UW, const string filename) {
    File<WORD_LENGTH, WORD_COUNT> F;
    Menu M;
    //    cout << endl;
    //    cout << "---- Playing with " << option << " letters words ----" << endl;
    //charge the file to the dictionary
    F.insertFileIntoArray(filename, dictionary);
    //ask the user to enter a start-word
    string start = M.lettersMenuWord("start", 'F');
    //check that the word entered is valid
    while (!validateWord(start, startW, dictionary)){
        start = M.lettersMenuWord("start", 'E');
    }
    //ask the user to enter a end-word
    string end = M.lettersMenuWord("end", 'F');
    //check that the word entered is valid
    while (!validateWord(end, endW, dictionary)){
        end = M.lettersMenuWord("end", 'E');
    }
    
    //checks if both words are equal
    while (start.compare(end) == 0) {
        //ask the user to enter a start-word
        start = M.lettersMenuWord("start", 'S');
        //check that the word entered is valid
        while (!validateWord(start, startW, dictionary)){
            start = M.lettersMenuWord("start", 'E');
        }
        //ask the user to enter a end-word
        end = M.lettersMenuWord("end", 'S');
        //check that the word entered is valid
        while (!validateWord(end, endW, dictionary)){
            end = M.lettersMenuWord("end", 'E');
        }
    }
    
    for (int i = 0; i < WORD_LENGTH; i++) {
        start[i] = startW[i];
    }
    
    for (int i = 0; i < WORD_LENGTH; i++) {
        end[i] = endW[i];
    }
    
    UW.setEndWord(end);
    UW.setStartWord(start);
    
}

#endif /* CheckWords_h */
