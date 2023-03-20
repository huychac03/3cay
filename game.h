#pragma once
#include <iostream>
#include "Card.h"

using namespace std;

class Game
{
private:
    class Hand {
    public:

        Card cardInHand[3];
        Hand() {
            //srand(time(NULL));
            for (int i = 0; i < 3; i++) {
                cardInHand[i] = Card();
            }
        }
        void display() {
            for (int i = 0; i < 3; i++) {
                cardInHand[i].display();
            }            
        }

        int sumValue() {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += cardInHand[i].getValue();
            }
            return sum%10;
        }

        int highestFeatureOfAPlayer() {
            int high = cardInHand[0].getFeature();
            for (int i = 0; i < 3; i++) {
                if (cardInHand[i].getFeature() > high) {
                    high = cardInHand[i].getFeature();
                }
            }
            return high;
        }

        Card cardWithHighestFeature() {
            int high = highestFeatureOfAPlayer();

            Card highestCard = cardInHand[0];
            for (int i = 1; i < 3; i++) {
                if (cardInHand[i].getFeature() == high) {
                    highestCard = cardInHand[i];                  
                }
            }

            for (int i = 1; i < 3; i++) {
                if (cardInHand[i].getValue() > highestCard.getValue() && cardInHand[i].getFeature() == highestCard.getFeature()) {
                    highestCard = cardInHand[i];
                }
            }       
            return highestCard;
        }
    };

    Hand player[4];

public:
    Game()
    {
        srand(time(NULL));
        for (int i = 0; i < 4; i++)
        {
            player[i] = Hand();           
        }
    }


    void Winner() {
        int maxSumValue = 0;
        int winnerIndex = -1;

        // Find the player with the highest sumValue
        for (int i = 0; i < 4; i++) {
            int sumValue = player[i].sumValue();
            if (sumValue > maxSumValue) {
                maxSumValue = sumValue;
                winnerIndex = i;
            }
        }

        // Check if there is a tie
        for (int i = 0; i < 4; i++) {
            if (i != winnerIndex && player[i].sumValue() == maxSumValue) {
                // There is a tie, compare the feature of the highest cards
                Card winnerCard = player[winnerIndex].cardWithHighestFeature();
                Card currentCard = player[i].cardWithHighestFeature();

                if (currentCard.getFeature() > winnerCard.getFeature() ||
                    (currentCard.getFeature() == winnerCard.getFeature() &&
                        currentCard.getValue() > winnerCard.getValue())) {
                    // The current player has a higher feature or a higher value card, so they become the new winner
                    winnerIndex = i;
                }
            }
        }

        // Display the winner
        cout << "The winner is Player " << winnerIndex + 1 << endl;
    }




    void displayPlayerHand()
    {
        for (int i = 0; i <4; i++)
        {
           cout << "Player hand " << i + 1 << ": " << endl;
           player[i].display();    
           cout << "Sum of player " << i + 1 << " is: " << player[i].sumValue() << endl;
           //cout << "The highest feature of player " << i + 1 << " is: " << player[i].highestFeatureOfAPlayer() << endl;
           cout << "Test: "; player[i].cardWithHighestFeature().display();
           cout << endl;
        }

        Winner();
    }



};
