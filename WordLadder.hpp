//
//  WordLadder.hpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 29/04/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#ifndef WordLadder_hpp
#define WordLadder_hpp

#include "File.hpp"
#include "UserWords.hpp"

template <int WORD_LENGTH, int WORD_COUNT>
class WorldLadder {
    public:
        //constructor
        WorldLadder();
        //given to words, returns true if both words differ from each other just for one letter
        bool checkIfDifferOnlyOneLetterFromWord (const array<char, WORD_LENGTH>& firstWord,
                                                 const array<char, WORD_LENGTH>& secondWord) const;
        bool isWordInPath(const int indexWord, const vector<int>& stack) const;
        //compares two char arrays: if equals return 0, if bigger returns 1, if smaller returns -1
        int compareCharArrays(const array<char, WORD_LENGTH>& word1,
                              const array<char, WORD_LENGTH>& word2) const;
        //returns a dictionary word index
        int getIndexWord(const array<array<char, WORD_LENGTH>, WORD_COUNT>& dict,
                         const array<char, WORD_LENGTH>& word, const int from, const int to);
        //display a valid path between start word and end word
        void displayPath(const vector<int> &stack,
                         const array<array<char, WORD_LENGTH>,WORD_COUNT>& dict) const;
        //display all possible valid paths
        void displayAllPaths(const vector<vector<int>>& allPaths, const array<char, WORD_LENGTH>& startW,
                             const array<char, WORD_LENGTH>& endW,
                             const array<array<char, WORD_LENGTH>,WORD_COUNT>& dict) const;
        //find a path between the start word and the end word
        void searchWordLadder(const array<array<char, WORD_LENGTH>,WORD_COUNT>& dict,
                              const int indexEndWord, const int depthLevel, const int maxDepthLevel, const int maxSolutions,
                              const vector<int> stack, vector<vector<int>>& solutions);
};

template <int WORD_LENGTH, int WORD_COUNT>
//constructor
WorldLadder<WORD_LENGTH, WORD_COUNT>::WorldLadder(){}

template <int WORD_LENGTH, int WORD_COUNT>
//given to words, returns true if both words differ from each other just for one letter
bool WorldLadder<WORD_LENGTH, WORD_COUNT>::checkIfDifferOnlyOneLetterFromWord (const array<char, WORD_LENGTH>& firstWord,
                                                                const array<char, WORD_LENGTH>& secondWord) const{
    int count = 0;
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (firstWord[i] != secondWord[i]) {
            count++;
            if (count > 1) {
                return (false);
            }
        }
    }
    return (count == 1);
}

template <int WORD_LENGTH, int WORD_COUNT>
//given a word (its index in the dictionary), checks if it already is in the path vector
bool WorldLadder<WORD_LENGTH, WORD_COUNT>::isWordInPath(const int indexWord, const vector<int>& stack) const{
    for (int i = 0; i < stack.size(); i++) {
        if (indexWord == stack[i]) {
            return (true);
        }
    }
    return (false);
}

//compares two char arrays: if equals return 0, if bigger returns 1, if smaller returns -1
template <int WORD_LENGTH, int WORD_COUNT>
int WorldLadder<WORD_LENGTH, WORD_COUNT>::compareCharArrays(const array<char, WORD_LENGTH>& word1,
                                                            const array<char, WORD_LENGTH>& word2) const {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (word1[i] < word2[i]) {
            return -1; //smaller
        } else if (word1[i] > word2[i]) {
            return 1; //bigger
        }
    }
    return (0); //equals
}

template <int WORD_LENGTH, int WORD_COUNT>
//returns a dictionary word index
int WorldLadder<WORD_LENGTH, WORD_COUNT>::getIndexWord(const array<array<char, WORD_LENGTH>, WORD_COUNT>& dict,
                                          const array<char, WORD_LENGTH>& word, const int from, const int to) {
    //Binary Search Algorithm
    if (from > to) {
        return (-1);
    }
    else {
        int mid = (from + to) / 2;
        
        int value = compareCharArrays(dict[mid], word);
        if (value == 0) {
            return (mid);
        }
        else if (value < 0) {
            return (getIndexWord(dict, word, mid + 1, to));
        }
        else {
            return (getIndexWord(dict, word, from, mid - 1));
        }
    }
}

template <int WORD_LENGTH, int WORD_COUNT>
//display a valid path between start word and end word
void WorldLadder<WORD_LENGTH, WORD_COUNT>::displayPath(const vector<int> &stack,
                                                       const array<array<char, WORD_LENGTH>,WORD_COUNT>& dict) const {
    cout << endl << "Path: " << endl;
    for (int i = 0; i < stack.size(); i++) {
        int index = stack[i];
        for (int j = 0; j < WORD_LENGTH; j++){
            if (j == (WORD_LENGTH - 1)) {
                cout << dict[index][j] << "  ";
            }
            else {
                cout << dict[index][j];
            }
        }
    }
    cout << endl;
}

template <int WORD_LENGTH, int WORD_COUNT>
//display all possible valid paths
void WorldLadder<WORD_LENGTH, WORD_COUNT>::displayAllPaths(const vector<vector<int>>& allPaths,
                                                           const array<char, WORD_LENGTH>& startW,
                                                           const array<char, WORD_LENGTH>& endW,
                                                           const array<array<char, WORD_LENGTH>,WORD_COUNT>& dict) const {
    //checks if it is empty (none path found)
    if (allPaths.size() == 0){
        cout << endl << "It has been not possible to find a path ";
        cout << "from ";
        for (int i = 0; i < startW.size(); i++) {
            cout << startW[i];
        }
        cout << " to ";
        for (int i = 0; i < endW.size(); i++) {
            cout << endW[i];
        }
        cout << "." << endl << endl;
    }
    else {
        cout << endl << "Path(s) from ";
        for (int i = 0; i < startW.size(); i++) {
            cout << startW[i];
        }
        cout << " to ";
        for (int i = 0; i < endW.size(); i++) {
            cout << endW[i];
        }
        cout << ":" << endl;
        for (int i = 0; i < allPaths.size(); i++) {
            cout << "* ";
            for (int j = 0; j < allPaths[i].size(); j++) {
                int index = allPaths[i][j];
                string output(WORD_LENGTH,'E');
                //cout << output << endl;
                //cout << string({dict[index][0], dict[index][1], dict[index][2]}) << "  ";
                for (int j = 0; j < WORD_LENGTH; j++){
                    output[j] = dict[index][j];
                }
                cout << output << "  ";
            }
            cout << endl;
        }
    }
}

template <int WORD_LENGTH, int WORD_COUNT>
//find a path between the start word and the end word
void WorldLadder<WORD_LENGTH, WORD_COUNT>::searchWordLadder(const array<array<char, WORD_LENGTH>,WORD_COUNT>& dict,
                                                            const int indexEndWord, const int depthLevel,
                                                            const int maxDepthLevel, const int maxSolutions,
                                                            const vector<int> stack, vector<vector<int>>& solutions) {
    if (solutions.size() >= maxSolutions) {
        return;
    }
    
    int count = (int)dict.size();
    for (int i = 0; i < count; i++) {
        
        int currentIndexWord = i;
        int lastIndexStackWord = stack[stack.size() - 1];
        
        bool onlyOneLetter = checkIfDifferOnlyOneLetterFromWord(dict[currentIndexWord], dict[lastIndexStackWord]);
        
        //if thre is more than one letter different, then go to the next word
        if (!onlyOneLetter) {
            continue;
        }
        
        bool wordInPath = isWordInPath(i, stack);
        
        //if the word is already in the path (stack), then go to the next word
        if (wordInPath) {
            continue;
        }
        
        //we have found a word that differs only one letter from the given word
        //and that it is not in the path (stack)
        vector<int> copyStack = stack;
        copyStack.push_back(i); //store index of the word  in the path (stack)
        
        //if found word is equals to the end word
        if (i == indexEndWord) { //base case
            //store the path in the vectors that contains all valid paths so far
            solutions.push_back(copyStack);
            //display the path found
            //displayPath(copyStack, dict);
            break;
        }
        else { //recursive case
            //early exit: control how deep can search
            if (depthLevel >= maxDepthLevel) {
                return;
            }
            
            searchWordLadder(dict, indexEndWord, depthLevel + 1, maxDepthLevel, maxSolutions, copyStack, solutions);
            
            if (solutions.size() >= maxSolutions) {
                return;
            }
        }
    }
}

#endif /* WordLadder_hpp */
