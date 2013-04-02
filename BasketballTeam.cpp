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

#include "BasketballTeam.h"
#include <sstream>

using namespace std;

BasketballTeam::BasketballTeam()
{
   m_school = " ";
   m_name = "";
   m_wins = 0;
   m_losses = 0;
   m_conference = "";
}

BasketballTeam::BasketballTeam(string school, string name, int wins, int losses, string conference)
{
   m_school = school;
   m_name = name;
   m_wins = wins;
   m_losses = losses;
   m_conference = conference;
}

string BasketballTeam::getSchool() const { return m_school; }
string BasketballTeam::getName() const { return m_name; }
string BasketballTeam::getRecord() const
{
   // We still want our nice looking wins and losses string, this method assembles it
   stringstream ss;
   ss << m_wins << " wins " << m_losses << " losses";
   return ss.str();
}
string BasketballTeam::getConference() const { return m_conference; }   

int BasketballTeam::getWins() const { return m_wins; }
int BasketballTeam::getLosses() const { return m_losses; }

void BasketballTeam::updateWins(int wins) { m_wins = wins; }
void BasketballTeam::updateLosses(int losses){ m_losses = losses; }

istream& operator >>(istream& istr, BasketballTeam &team)
{
   getline(istr, team.m_school);
   getline(istr, team.m_name);
   string junk;
   istr >> team.m_wins >> junk >> team.m_losses; // Junk takes out the "wins" and "losses" and lets us get the numbers
   getline(istr, junk);
   getline(istr, team.m_conference);
   return istr;
}

ostream& operator <<(ostream& ostr, BasketballTeam &team)
{
   cout << endl << "\t" << team.getSchool() << endl << "\t" << team.getName() << endl << "\t" << team.getRecord() 
      << endl << "\t" << team.getConference() << endl;
   return ostr;
}

bool operator <=(BasketballTeam &lhs, BasketballTeam &rhs) { return lhs.getName() <= rhs.getName(); }
bool operator<(BasketballTeam &lhs, BasketballTeam &rhs) { return lhs.getName() < rhs.getName(); }
bool operator>=(BasketballTeam &lhs, BasketballTeam &rhs) { return lhs.getName() >= rhs.getName(); }
bool operator>(BasketballTeam &lhs, BasketballTeam &rhs) { return lhs.getName() > rhs.getName(); }
bool operator==(BasketballTeam &lhs, BasketballTeam &rhs) { return lhs.getName() == rhs.getName(); }
bool operator!=(BasketballTeam &lhs, BasketballTeam &rhs) { return !(lhs == rhs); }