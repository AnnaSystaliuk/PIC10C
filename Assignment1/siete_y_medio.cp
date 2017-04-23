#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)
double DealerGame(Player dealer);

// Non member functions declarations (if any)
double DealerGame(Player dealer)
{

    while(dealer.getHand()->getpoints() <= 5.5)
    {
        Card newCard;
        dealer.addCard(newCard);
        cout << "New Card: " << endl;
        cout << newCard.get_english_rank() << " of " << newCard.get_english_suit() << endl;
        cout << "Dealer's cards: " << endl;
        dealer.printCards();
        cout << "Dealer's score is " << dealer.getHand()->getpoints() << endl;
    }
    
    return dealer.getHand()->getpoints();
}

// Non member functions implementations (if any)


// Stub for main
int main(){
   /* --STATEMENTS-- */
    
    Player user(100);
    Player dealer(100);
    int betmoney;
    char answer;
    bool GAMEON = true;
 
    

    while (user.getMoney()>0)
    {
        user.newHand();
        cout << "Your score is " << user.getHand()->getpoints() << endl;
        cout << "You have " << user.getMoney() << " dollars. Enter bet: " << endl;
        cin >> betmoney;
        
        while (GAMEON)
        {

            Card newCard;
            user.addCard(newCard);
            cout << "New card is :" << endl;
            cout << newCard.get_english_rank() << " of " << newCard.get_english_suit() << endl;
            cout << "Your cards :" << endl;
            user.printCards();
            cout << "Your score is " << user.getHand()->getpoints() << endl;
            if (user.getHand()->getpoints() > 7.5)
            {
                cout << "You are busted! You lose!" << endl << endl << endl;
                user.lostMoney(betmoney);
                break;
            }
            cout << "Do you want another card? y/n" << endl;
            cin >> answer;
            if (answer == 'y')
            {
                continue;
            }
            else if (answer == 'n')
            {
                double DealerScore = DealerGame(dealer);
                if (DealerScore > 7.5)
                {
                    cout << "Dealer is busted! You win!" << endl;
                    user.wonMoney(betmoney);
                    break;
                }
                if ((7.5 - DealerScore) < (7.5 - user.getHand()->getpoints()))
                    user.lostMoney(betmoney);
                else if ((7.5 - DealerScore) > (7.5 - user.getHand()->getpoints()))
                user.wonMoney(betmoney);
                else if ((7.5 - DealerScore) == (7.5 - user.getHand()->getpoints()))
                cout << "It's a tie!" << endl << endl;
                break;
            }
        }
    }
    
    cout << "You have " << user.getMoney() << " dollars. " << endl;

   return 0;
}
