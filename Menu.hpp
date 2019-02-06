//
//  Menu.hpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 07/05/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "File.hpp"
#include "WordLadder.hpp"
#include "UserWords.hpp"

class Menu {
    public:
        Menu();
        //display main menu
        string MainMenu();
        //check that the menu option chosen is valid
        char checkMenuOption (string inOption);
        //display letters menu
        string lettersMenuWord(const string inString, const char letter);
        //ask user to enter a new string until it is valid
        string getValidString (string inputWord, const int length);
        //exit treatment
        void exitOption();
        //ask how many solutions (path) to print out
        int getNumberPathsToPrint() const;
        //ask how deep can we search
        int getMaxDepthLevel() const; 
};

#endif /* Menu_hpp */
