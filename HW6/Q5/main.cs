using System;

namespace Q5
{
    class Program
    {
        static void Main(String[] args)
        {
            Console.WriteLine("Studnet ID: B10831020");
            Player[] players; // initalized in method PlayersEnter
            if(args.Length == 1){
                Console.WriteLine($"{args[0]} players will join the game");
                PlayersEnter(out players, Convert.ToInt32(args[0]));
            }else{
                Console.WriteLine("The default number of player is 5, you can specify number of players as command line argument");
                PlayersEnter(out players);
            }
            Deck aDeckOfCards = new Deck();
            aDeckOfCards.Shuffle();
            Console.WriteLine("");
            Console.WriteLine("The entire deck after shuffling");
            aDeckOfCards.ShowDeck();
            DrawAndShowCards(players, aDeckOfCards);
            Console.ReadKey();
        }
        /// <summary>
        /// Draw and reveal all the cards each player has for desired number of times. The card drawn from the deck will not reappear in future draw-reveal cycles
        /// </summary>
        /// <param name="_allPlayers">The array of players in the game</param>
        /// <param name="_aDeckOfCards">The Deck instance currently using</param>
        static void DrawAndShowCards(Player[] _allPlayers, Deck _aDeckOfCards, int times = 4)
        {
            for (int i = 0; i < times; i++){
                Console.WriteLine($"Deal #{i+1}");
                foreach(Player p in _allPlayers){
                    p.ClearCards();
                }
                _aDeckOfCards.Deal(ref _allPlayers);
                Player.AllPlayersShowCards(_allPlayers);
            }
        }
        /// <summary>
        /// Initializes an array of player instances passed in as an output argument
        /// </summary>
        /// <param name="_allPlayers">The array where the player instances will be stored</param>
        /// <param name="_nPlayers">Number of players in a game</param>
        static void PlayersEnter(out Player[] _allPlayers, int _nPlayers = 5)
        {
            _allPlayers = new Player[_nPlayers];
            for (int i = 0; i < _nPlayers; i++){
                _allPlayers[i] = new Player();
            }
        }
    }
}