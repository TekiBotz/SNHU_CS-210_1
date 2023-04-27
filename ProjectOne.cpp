/*
 * ProjectOne.cpp
 *
 *  Date: [Jan 27, 2023
 *  Author: [Jarrale Butts]
 */


#include <iostream>
#include <string>
using namespace std;

// This void function allows me to make random number of *'s  when called
void Stars(int spaces) {
   char star;
   star = cout.fill('*');
   cout.width(spaces);
   cout << "";
}

// This void function allows me to make random number of blank spaces  when called
void Blanks(int spaces) {
   string blank;
   blank = cout.fill(' ');
   cout.width(spaces);
   cout << "";
}

// This void function is a print function
void PrintStarLine() {
   char symb;
   symb = '*';
   int i;

   // This for loop will print a predetermined number of *'s
   for (i = 0; i < 27; ++i) {
      cout << symb;
   }
}

// This void function is a print function
void StarLineBreak() {
   int i;
   // This for loop will give the break between the first and second set of *'s
   for (i = 0; i < 3; ++i) {
      cout << " ";
   }
}

// This void function converts any number to a two digit number
void TwoDigits(unsigned int time) {
   if (time < 10) {
      cout << "0" << time;
   } else {
      cout << time;
   }
}

// This void function centers the menu's top and bottom star lines
void MenuStarLine() {
   Blanks(15);
   PrintStarLine();
   Blanks(15);
}

// This void function creates the menu and all the selections
void Menu() {
   MenuStarLine();
   cout << endl;

   Blanks(15);
   Stars(1);
   Blanks(1);
   cout << "1";
   Blanks(1);
   cout << "-";
   Blanks(1);
   cout << "Add One Hour";
   Blanks(8);
   Stars(1);

   cout << endl;

   Blanks(15);
   Stars(1);
   Blanks(1);
   cout << "2";
   Blanks(1);
   cout << "-";
   Blanks(1);
   cout << "Add One Minute";
   Blanks(6);
   Stars(1);

   cout << endl;

   Blanks(15);
   Stars(1);
   Blanks(1);
   cout << "3";
   Blanks(1);
   cout << "-";
   Blanks(1);
   cout << "Add One Secound";
   Blanks(5);
   Stars(1);

   cout << endl;

   Blanks(15);
   Stars(1);
   Blanks(1);
   cout << "4";
   Blanks(1);
   cout << "-";
   Blanks(1);
   cout << "Exit Program";
   Blanks(8);
   Stars(1);

   cout << endl;
   MenuStarLine();
   cout << endl;
   cout << endl;
}

// This void function calls the menu function, allows an output and an input
void MenuChoice() {
   Menu();
   int choose;
   cout << "Choose an option from the menu: ";
   cin >> choose;
}

// This void function takes the numbers passed from TimeConversion() and assigns the numbers for the hour, minute, and seconds for standard time and prints them
void StandardTime(unsigned int hour, unsigned int minute, unsigned int second) {

   if (hour > 12) {
      hour = hour - 12;    // This makes sure if military time is entered it is converted to standard time
      TwoDigits(hour);
      cout << ":";
      if (minute > 59) {
         cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
         exit(-1);
      } else {
         TwoDigits(minute);
      }
      cout << ":";
      if (second > 59) {
         cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
         exit(-1);
      } else {
         TwoDigits(second);
      }
      cout << " P M";
   } else {
      TwoDigits(hour);
      cout << ":";
      if (minute > 59) {
         cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
         exit(-1);
      } else {
         TwoDigits(minute);
      }
      cout << ":";
      if (second > 59) {
         cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
         exit(-1);
      } else {
         TwoDigits(second);
      }
      cout << " A M";
   }
   
}

// This void function takes the numbers passed from TimeConversion() and assigns the numbers for the hour, minute, and seconds for military time and prints them
void MilitaryTime(unsigned int hour, unsigned int minute, unsigned int second) {
   if (hour > 23) {
      cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
      exit(-1);
   } else {
      TwoDigits(hour);
   }
   cout << ":";
   if (minute > 59) {
      cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
      exit(-1);
   } else {
      TwoDigits(minute);
   }
   cout << ":";
   if (second > 59) {
      cout << "Error";     // If a number is entered outside the spectrum the program will exit on the next line
      exit(-1);
   } else {
      TwoDigits(second);
   }
}

// Print function
void StandardClock() {
   cout << "12-Hour Clock";
}

// Print function
void MilitaryClock() {
   cout << "24-Hour Clock";
}

/**
 * This void function initally receives the hour, minute, and second values
 * Sets up the shape of the program
 * And calls multiple functions
*/

void TimeConversion(unsigned int hour, unsigned int minute, unsigned int second) {
   int i;
   for (i = 1; i != 0; ++i) {    // I initally had this function in a for loop to increment it, unfortunally I didn't have enough time to figure it out

   PrintStarLine();
   StarLineBreak();
   PrintStarLine();
   cout << endl;
   Stars(1);
   Blanks(6);
   StandardClock();
   Blanks(6);
   Stars(1);
   Blanks(3);
   Stars(1);
   Blanks(6);
   MilitaryClock();
   Blanks(6);
   Stars(1);
   cout << endl;
   Stars(1);
   Blanks(6);
   StandardTime(hour,minute,second);
   Blanks(7);
   Stars(1);
   Blanks(3);
   Stars(1);
   Blanks(8);
   MilitaryTime(hour,minute,second);
   Blanks(9);
   Stars(1);
   cout << endl;
   PrintStarLine();
   StarLineBreak();
   PrintStarLine();
   cout << endl;
   cout << endl;
      break;      // This breaks out of the for loop so it doesn't run forever
   }
}

/**
 * Main function
 * Gathers information from the user
 * Calls the functions created
 */
int main() {
   int hr;
   int min;
   int sec;
   cout << "Enter Time" << endl;
   cin >> hr;
   cin >> min;
   cin >> sec;

   TimeConversion(hr,min,sec);
   MenuChoice();
   TimeConversion(hr,min,sec);

   return 0;
}