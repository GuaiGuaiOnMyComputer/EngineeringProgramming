using System.Collections.Generic;
using System.Text;
using System;

namespace Q5
{
    class Player
    {
        List<Card> CardsPocessed { get; }

        /// <summary>
        /// Instantiate a player instance by giving it an array of cards, which will be stored into this.CardsPocessed
        /// </summary>
        /// <param name="cardsGiven">The cards given to this player initially</param>
        public Player()
        {
            this.CardsPocessed = new List<Card>();
        }

        /// <summary>
        /// Removes all the cards a player has
        /// </summary>
        public void ClearCards()
        {
            this.CardsPocessed.Clear();
        }

        /// <summary>
        /// Append an array of cards into the player's pocession
        /// </summary>
        /// <param name="_givenCards">The array of cards the player should receive</param>
        public void ReceiveCards(Card[] _givenCards)
        {
            foreach(Card c in _givenCards){
                this.CardsPocessed.Add(c);
            }
        }
        
        /// <summary>
        /// Get a string of the cards the player has
        /// </summary>
        /// <returns>The cards a player has as a string</returns>
        public string ShowCards()
        {
            var _sb = new StringBuilder();
            foreach(Card c in this.CardsPocessed){
                _sb.Append(c.ToString());
            }
            _sb.Append("\n");
            return _sb.ToString();
        }
        /// <summary>
        /// Prints all the cards each player has into console
        /// </summary>
        /// <param name="_allPlayers">Array of players in the game</param>
        public static void AllPlayersShowCards(Player[] _allPlayers)
        {
            int nPlayers = _allPlayers.GetLength(0);
            for (int i = 0; i < nPlayers; i++){
                Console.Write("Player {0:d}|: {1:S}", i, _allPlayers[i].ShowCards());
            }
            Console.WriteLine("");
        }
    }
}