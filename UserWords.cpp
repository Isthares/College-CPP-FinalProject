//
//  UserWords.cpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 23/04/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#include "UserWords.hpp"

//constructor
UserWords::UserWords() {
    startWord = "";
    endWord = "";
}

//get startWord value
string UserWords::getStartWord() const {
    return (startWord);
}

//get endWord value
string UserWords::getEndWord() const{
    return (endWord);
}

//set startWord value
void UserWords::setStartWord(const string start){
    startWord = start;
}

//set endWord value
void UserWords::setEndWord(const string end){
    endWord = end;
}
