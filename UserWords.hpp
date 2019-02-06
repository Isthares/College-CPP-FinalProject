//
//  UserWords.hpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 23/04/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#ifndef UserWords_hpp
#define UserWords_hpp

#include "libraries.h"

class UserWords {
    private:
        string startWord;
        string endWord;
    public:
        UserWords(); //constructor
        string getStartWord() const; //get startWord value
        string getEndWord() const; //get endWord value
        void setStartWord(const string start); //set startWord value
        void setEndWord(const string end); //set endWord value
};

#endif /* UserWords_hpp */

