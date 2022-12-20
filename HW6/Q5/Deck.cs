using System;

namespace Q5
{
    class Deck
    {
        public Card[] AllCards = new Card[52];
        private bool shuffledFlag = false;
        private int lastGivenCardIdx = 0;
        /// <summary>
        /// Initialize a deck of 52 cards, assigning each  a number and suit in order and put it into the array this.AllCards
        /// </summary>
        public Deck()
        {
            for(int nNumber = 0; nNumber < 13; nNumber++){
                for(int nSuit = 0; nSuit < 4; nSuit++){
                    this.AllCards[nSuit + nNumber * 4] = new Card(nSuit, nNumber);
                }
            }
        }

        /// <summary>
        /// Shuffle the deck instance, swapping the positions of two random cards in the array this.AllCard for 52 times
        /// </summary>
        public void Shuffle()
        {
            this.shuffledFlag = true;
            Random rnd = new Random();
            for(int i = 0; i < 52; i++){
                int card1Idx = rnd.Next() % 52;
                int card2Idx = rnd.Next() % 52;
                Card tmp = this.AllCards[card1Idx];
                this.AllCards[card1Idx] = this.AllCards[card2Idx];
                this.AllCards[card2Idx] = tmp;
            }
        }

        /// <summary>
        /// Console outputs the content of the array this.AllCards, printing the number and the suit of each card into a 13x4 grid
        /// </summary>
        public void ShowDeck()
        {
            var sb = new System.Text.StringBuilder();
            for(int i = 0; i < 13; i++){
                for(int j = 0; j < 4; j++){
                    if(j == 3){
                        sb.Append($"{this.AllCards[j + i * 4].ToString()}\n");
                    }else{
                        sb.Append($"{this.AllCards[j + i * 4].ToString()}");
                    }
                }
            }
            Console.Write(sb.ToString());
        }
        /// <summary>
        /// Give cards to each player. Cards given to a player will not reapper in future deals for a single instance of deck. This function should be called after the deck has been shuffled
        /// </summary>
        /// <param name="_players">The array containing player instances</param>
        /// <param name="nCardsEachPerson">Number of cards each player should get each draw</param>
        public void Deal(ref Player[] _players, int nCardsEachPerson = 2)
        {
            Card[] cardsGivenToAPlayer = new Card[nCardsEachPerson];
            for (int i = 0; i < _players.GetLength(0); i++) {
                for (int j = 0; j < nCardsEachPerson; j++){
                    cardsGivenToAPlayer[j] = this.AllCards[this.lastGivenCardIdx];
                    this.lastGivenCardIdx++;
                }
                _players[i].ReceiveCards(cardsGivenToAPlayer);
            }
        }
    }
}