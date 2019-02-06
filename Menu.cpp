//
//  Menu.cpp
//  CIS 252 _ Final Project
//
//  Created by Esther Heralta Espinosa on 07/05/2018.
//  Copyright © 2018 Esther Heralta Espinosa. All rights reserved.
//

#include "Menu.hpp"

//constructor
Menu::Menu(){}

//display main menu
string Menu::MainMenu () {
    string option;
    cout << endl << "------------- Let's Play! --------------" << endl;
    cout << "*  Play with 3 letter words   -- Press 3" << endl;
    cout << "*  Play with 4 letter words   -- Press 4" << endl;
    cout << "*  Play with 5 letter words   -- Press 5" << endl;
    cout << "*  Exit game                  -- Press 0" << endl << endl;
    
    cout << "Please, choose an option: ";
    cin >> option;
    return (option);
}

//check that the menu option chosen is valid
char Menu::checkMenuOption (string inOption) {
    int zero = int('0'); //ASCII value of 0
    int three = int('3'); //ASCII value of 3
    int four = int('4'); //ASCII value of 4
    int five = int ('5'); //ASCII value of 5

    while((inOption.length() != 1)){
        cout << endl << "The option entered is not valid." << endl;
        cout << "Please, choose a valid option: ";
        cin >> inOption;
    }
    int option = int(inOption[0]); //ASCII value of the option entered by the user
    while((option !=  zero) && (option != three) && (option != four) && (option != five)) {
        cout << endl << "The option entered is not valid." << endl;
        cout << "Please, choose a valid option: ";
        cin >> inOption;
        while((inOption.length() != 1)){
            cout << endl << "The option entered is not valid." << endl;
            cout << "Please, choose a valid option: ";
            cin >> inOption;
        }
        option = int(inOption[0]);
    }
    char opt = inOption[0];
    return(opt);
}

//display letters menu
string Menu::lettersMenuWord(const string inString, const char letter) {
    string word = "";
    if (letter == 'F') {
        cout << "* Enter a/an " << inString << " word: ";
    }
    else if (letter == 'S') {
        cout << endl << "Boths words are equal." << endl;
        cout << "Please, enter a new " << inString << " word: ";
    }
    else {
        cout << endl << "Invalid word." << endl;
        cout << "Please, enter a new " << inString << " word: ";
    }
    cin >> word;
    return (word);
}

//exit treatment
void Menu::exitOption() {
    cout << endl;
    cout << "--------------- Exit Game --------------" << endl;
    cout << "See you soon! Have a nice day!" << endl << endl;
}

//ask how many solutions (path) to print out
int Menu::getNumberPathsToPrint() const{
    int nPaths = 0;
    cout << endl;
    cout << "Maximum of paths that you want to print out: ";
    cin >> nPaths;
    while (nPaths <= 0) {
        cout << endl << "Invalid numbers of paths." << endl;
        cout << "Maximum of paths that you want to print out: ";
        cin >> nPaths;
    }
    return (nPaths);
}

//ask how deep can we search
int Menu::getMaxDepthLevel() const {
    int depth = 0;
    cout << endl;
    cout << "How deep do you want to search? ";
    cin >> depth;
    while (depth <= 0) {
        cout << endl << "Invalid number of depth." << endl;
        cout << "How deep do you want to search? ";
        cin >> depth;
    }
    return (depth);
}
