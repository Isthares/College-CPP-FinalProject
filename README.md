# College CPP Final Project
## Description: *Word Ladder Game*

Initially, the user has to decide which mode is he/she going to play. There are four options:
* Play with three letter words
* Play with four letter words
* Play with five letter words
* Exit Game

Once the user has chosen the length of the word, he/she enters a start word and an end word. The program changes the start word into the end word progressively, creating an existing word at each step. Each step consists of a single letter substitution. In case that there is no possible path between the two words, a message is shown. 

For example, the following are some of the possible solutions between words "LOVE" and "HATE":
- LOVE  HOVE  HAVE  HATE 
- LOVE  LAVE  LATE  HATE 
- LOVE  COVE  CAVE  HAVE  HATE
- LOVE  COVE  CAVE  CAKE  HAKE  HATE 
