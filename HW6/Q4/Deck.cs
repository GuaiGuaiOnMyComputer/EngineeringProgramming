using System;

namespace Q4
{
    class Deck
    {
        public Card[] AllCards = new Card[52];
        public Deck()
        {
            // initialize a deck of 52 cards, assigning each  a number and suit in order
            for(int nNumber = 0; nNumber < 13; nNumber++){
                for(int nSuit = 0; nSuit < 4; nSuit++){
                    this.AllCards[nSuit + nNumber * 4] = new Card(nSuit, nNumber);
                }
            }
        }

        public void Shuffle()
        {
            Random rnd = new Random();
            for(int i = 0; i < 52; i++){
                int card1Idx = rnd.Next() % 52;
                int card2Idx = rnd.Next() % 52;
                Card tmp = this.AllCards[card1Idx];
                this.AllCards[card1Idx] = this.AllCards[card2Idx];
                this.AllCards[card2Idx] = tmp;
            }
        }

        public void ShowDeck()
        {
            var sb = new System.Text.StringBuilder();
            for(int i = 0; i < 13; i++){
                for(int j = 0; j < 4; j++){
                    if(j == 0){
                        sb.Append($"|{Card.sNumber[AllCards[i*4 + j].numberIdx], 2}--{Card.sSuit[AllCards[i*4 + j].SuitIdx], -9}");
                    }else if(j == 3){
                        sb.Append($"{Card.sNumber[AllCards[i*4 + j].numberIdx], 2}--{Card.sSuit[AllCards[i*4 + j].SuitIdx], -9}|\n");
                    }else{
                        sb.Append($"{Card.sNumber[AllCards[i*4 + j].numberIdx], 2}--{Card.sSuit[AllCards[i*4 + j].SuitIdx], -9}");
                    }
                }
            }
            Console.Write(sb.ToString());
        }
    }
}