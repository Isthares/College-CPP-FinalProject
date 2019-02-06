//
//  main.cpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 23/04/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#include "Menu.hpp"
#include "WordLadder.hpp"
#include "CheckWords.h"


int main() {
    
    cout << endl << "  Welcome to the World Ladder Game!!!     " << endl << endl;

    //char option;
    string opt;
    bool exit = false;
    Menu M;

    while (!exit) {
        //display main menu
        opt = M.MainMenu();
        //checking that the option entered by the user is valid
        char option = M.checkMenuOption(opt);
        if (option == '0') {
            M.exitOption();
            exit = true;
        }
        else if (option == '3'){
            UserWords UW;
            WorldLadder<THREE, THREE_LETTER_SIZE_FILE> WL;
            CheckWords<THREE, THREE_LETTER_SIZE_FILE> CW;
            array<array<char, THREE>, THREE_LETTER_SIZE_FILE> words;
            array<char, THREE> startWord;
            array<char, THREE> endWord;
            cout << endl;
            cout << "---- Playing with " << THREE << " letters words ----" << endl;
            CW.manageOption(words, startWord, endWord, UW, THREE_LETTER_FILE);
            int maxSolutions = M.getNumberPathsToPrint();
            //cout << maxSolutions << endl;
            int maxDepthLevel = M.getMaxDepthLevel();
            //cout << maxDepthLevel << endl;
            //vector that contains the indexes of the words of the dictionary that are valid
            vector<int> path;
            //vector that contains all solutions found so far
            vector<vector<int>> allPaths;
            int indexInitialWord = WL.getIndexWord(words, startWord, 0, words.size() - 1);
            int indexFinalWord = WL.getIndexWord(words, endWord, 0, words.size() - 1);
            //store index of initial word into stack
            path.push_back(indexInitialWord);
            cout << endl << "---- Initializing path search ... ----" << endl;
            WL.searchWordLadder(words, indexFinalWord, 0, maxDepthLevel - 1, maxSolutions, path, allPaths);
            WL.displayAllPaths(allPaths, startWord, endWord, words);
        }
        else if (option == '4'){
            UserWords UW;
            WorldLadder<FOUR, FOUR_LETTER_SIZE_FILE> WL;
            CheckWords<FOUR, FOUR_LETTER_SIZE_FILE> CW;
            array<array<char, FOUR>, FOUR_LETTER_SIZE_FILE> words;
            array<char, FOUR> startWord;
            array<char, FOUR> endWord;
            cout << endl;
            cout << "---- Playing with " << FOUR << " letters words ----" << endl;
            CW.manageOption(words, startWord, endWord, UW, FOUR_LETTER_FILE);
            int maxSolutions = M.getNumberPathsToPrint();
            int maxDepthLevel = M.getMaxDepthLevel();
            //vector that contains the indexes of the words of the dictionary that are valid
            vector<int> path;
            //vector that contains all solutions found so far
            vector<vector<int>> allPaths;
            int indexInitialWord = WL.getIndexWord(words, startWord, 0, words.size() - 1);
            int indexFinalWord = WL.getIndexWord(words, endWord, 0, words.size() - 1);
            path.push_back(indexInitialWord);
            cout << endl << "...... Searching path(s) ......" << endl;
            WL.searchWordLadder(words, indexFinalWord, 0, maxDepthLevel - 1, maxSolutions, path, allPaths);
            WL.displayAllPaths(allPaths, startWord, endWord, words);
        }
        else if (option == '5'){
            UserWords UW;
            WorldLadder<FIVE, FIVE_LETTER_SIZE_FILE> WL;
            CheckWords<FIVE, FIVE_LETTER_SIZE_FILE> CW;
            array<array<char, FIVE>, FIVE_LETTER_SIZE_FILE> words;
            array<char, FIVE> startWord;
            array<char, FIVE> endWord;
            cout << endl;
            cout << "---- Playing with " << FIVE << " letters words ----" << endl;
            CW.manageOption(words, startWord, endWord, UW, FIVE_LETTER_FILE);
            int maxSolutions = M.getNumberPathsToPrint();
            int maxDepthLevel = M.getMaxDepthLevel();
            //vector that contains the indexes of the words of the dictionary that are valid
            vector<int> path;
            //vector that contains all solutions found so far
            vector<vector<int>> allPaths;
            int indexInitialWord = WL.getIndexWord(words, startWord, 0, words.size() - 1);
            int indexFinalWord = WL.getIndexWord(words, endWord, 0, words.size() - 1);
            path.push_back(indexInitialWord);
            cout << endl << "...... Searching path(s) ......" << endl;
            WL.searchWordLadder(words, indexFinalWord, 0, maxDepthLevel - 1, maxSolutions, path, allPaths);
            WL.displayAllPaths(allPaths, startWord, endWord, words);
        }
    }

    return (0);
}
