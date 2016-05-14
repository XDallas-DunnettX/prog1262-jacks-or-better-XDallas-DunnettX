//#include "mainwindow.h"
//#include <QApplication>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "hand.h"



int main()
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    int payout = 0;
    char input;
    Deck deck;
    Hand hand;


    do
    {
        switch(input)
        {

           case 'w':
           {
             hand.welcome();
             break;
           }
           case 'p':
           {
             hand.play();

             std::cout << "Would you like to play again? y/n" << std::endl;
             std::cin >> input;
             input = tolower(input);
             if(input == 'y')
             {
                 input == 'p';
             }
             else if(input == 'n')
             {
                 input == 'q';
             }
             break;
           }
           case 't':
           {
             hand.payTable();
             break;
           }
           case 'q':
           {
             break;
           }
           default:
           {
            std::cout << "please enter one four characters, W for welcome, P for play, T for pay table and Q to quit." << std::endl;
           }
        }
    }while(input != 'q');




    return 0;
}
