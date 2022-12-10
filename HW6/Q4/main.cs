using System;

namespace Q4
{
    class Program
    {
        static void Main(String[] args)
        {
            Console.WriteLine("Studnet ID: B10831020");
            Deck aDeckOfCards = new Deck();
            Console.WriteLine("");
            Console.WriteLine("Before shuffling");
            aDeckOfCards.ShowDeck();
            aDeckOfCards.Shuffle();
            Console.WriteLine("");
            Console.WriteLine("After shuffling");
            aDeckOfCards.ShowDeck();
            Console.ReadKey();
        }
    }
}