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
#ifndef __BASKETBALLTEAM_H__
#define __BASKETBALLTEAM_H__

#include <cstdlib>
#include <string>
#include <iostream>

class BasketballTeam {

   friend std::istream& operator >>(std::istream& istr, BasketballTeam &team);
   friend std::ostream& operator <<(std::ostream& ostr, BasketballTeam &team);
   friend bool operator<=(BasketballTeam &lhs, BasketballTeam &rhs);
   friend bool operator<(BasketballTeam &lhs, BasketballTeam &rhs);
   friend bool operator>=(BasketballTeam &lhs, BasketballTeam &rhs);
   friend bool operator>(BasketballTeam &lhs, BasketballTeam &rhs);
   friend bool operator==(BasketballTeam &lhs, BasketballTeam &rhs);
   friend bool operator!=(BasketballTeam &lhs, BasketballTeam &rhs);

private:
   int m_wins;
   int m_losses;
   std::string m_school;
   std::string m_name;
   std::string m_conference;

public:
   BasketballTeam();
   BasketballTeam(std::string school, std::string name, int wins, int losses, std::string conference);
   std::string getSchool() const;
   std::string getName() const;
   std::string getRecord() const;
   std::string getConference() const;
   int getWins() const;
   int getLosses() const;
   void updateWins(int wins);
   void updateLosses(int losses);

};

#endif