
/******************************************************************************
*******************************************************************************
*                           EECS 1580 - 001                                   *
*                        Project #3 Binary Tree                               *
*                                                                             *
*                      Written by: Logan Anteau                               *
*                          March 24, 2013                                     *
*******************************************************************************
*******************************************************************************
*/

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "BasketballTeam.h"
#include "Tree.h"

using namespace std;

bool readFromFile(string file);

Tree teamTree;

int main(int argc, char *argv[])
{
   
   string fileName;
   string searchString;
   string choice;
   
   cout << "Enter a file name to load team data from: ";
	cin >> fileName;
   
   if (!readFromFile(fileName))
		cout << "Error reading file!" << endl; 
	
   bool found;
   
   bool keepRunning = true;
   while (keepRunning)
   {
      cout << "\nWhat would you like to do?\n" << endl;
      cout << "\t1: Search for a team" << endl;
      cout << "\t2: Display teams with more than x amount of wins" << endl;
      cout << "\t3: Update a team's wins/losses" << endl;
      cout << "\t4: Add a team" << endl;
      cout << "\t5: Quit" << endl;
      cin >> choice;
      switch (*choice.begin()) // Notice this switch statement is switching on the ASCII value of the first character
      {
         case 49: // 49 = 1
            cout << "\nEnter the team you would like to search for: ";
            cin.ignore();                                                  // This ignores the \n character from the last entry
            getline(cin, searchString);                                    // std::getline is used so names can have spaces
            bstnode *result;
            result = teamTree.search(teamTree.getRoot(), searchString);
            if(result != NULL)
               cout << *(result->getKey()) << endl;
            else
               cout << "\nNo matching team found!" << endl;
            break;
         case 50: // 50 = 2
            cout << "Enter minimum number of wins: ";
            int wins;
            cin >> wins;
            teamTree.inoTreeWalk(teamTree.getRoot(), wins);
            break;
         case 51: // 51 = 3
            cout << "Which team would you like to update? (Enter team name or BACK to go back)" << endl << "\t";
            cin.ignore();                                                  // This ignores the \n character from the last entry
            getline(cin, searchString);                                    // std::getline is used so names can have spaces
            if (searchString == "BACK")
               break;
            bstnode *toBeUpdated;
            toBeUpdated = teamTree.search(teamTree.getRoot(), searchString);

            if(toBeUpdated != NULL)
            {
               cout << "\nCurrent team information: " << endl << endl;
               cout << *(toBeUpdated->getKey()) << endl << endl;
               cout << "\nWhat would you like to do?\n" << endl;
               cout << "\t1: Update wins" << endl;
               cout << "\t2: Update losses" << endl;
               cout << "\t3: Go back" << endl;
               cin >> choice;

               switch (*choice.begin())
               {
                  case 49: // 49 = 1
                     cout << "Enter new number of wins: ";
                     int wins;
                     cin >> wins;
                     toBeUpdated->getKey()->updateWins(wins);
                     cout << "Updated team info: " << endl;
                     cout << *(toBeUpdated->getKey());
                     break;
                  case 50: // 50 = 2
                     cout << "Enter new number of losses: ";
                     int losses;
                     cin >> losses;
                     toBeUpdated->getKey()->updateLosses(losses);
                     cout << "\nUpdated team info: " << endl;
                     cout << *(toBeUpdated->getKey());
                     break;
                  case 51: // 51 = 3
                     break;
               }

            }
            else
               cout << "\nTeam not found!" << endl;
            break;
         case 52: // 52 = 4
         {
            string school, name, conference;
            int newTeamWins, newTeamLosses;
            cout << "Enter team school: ";
            cin.ignore(); // This ignores the \n character from the last entry
            getline(cin, school);
            cout << "Enter team name: ";
            //cin.ignore(); // This ignores the \n character from the last entry
            getline(cin, name);
            cout << "Enter wins: ";
            cin >> newTeamWins;
            cout << "Enter losses: ";
            cin >> newTeamLosses;
            cout << "Enter team conference: ";
            cin.ignore(); // This ignores the \n character from the last entry
            getline(cin, conference);
            BasketballTeam* addedTeam = new BasketballTeam(school, name, newTeamWins, newTeamLosses, conference);
            bstnode* addedTeamNode = new bstnode(addedTeam);
            teamTree.insert(addedTeamNode);

            cout << "\nTeam entry added:" << endl;  // Display confirmation
            cout << *(addedTeamNode->getKey());

         }

            break;
         case 53: // 53 = 5
            keepRunning = false;
            break;
         default:
            cout <<  "\nInvalid choice!" << endl;
            break;
      }
   }
   return 0;
}

bool readFromFile(string file)
{
   ifstream inputFile;
   istream& stream = inputFile;
   string line, junk;
   
   int wins, losses;

   inputFile.open(file.c_str());

   if (!inputFile.good())
      return false;

   while (inputFile.good())
   {
      BasketballTeam* newTeam = new BasketballTeam();
      stream >> *newTeam;
      bstnode* team = new bstnode(newTeam);
      teamTree.insert(team);
   }

   return true;
}
