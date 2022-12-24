namespace Q5
{
    /// <summary>
    /// Each card instance owns two readonly int properties, Suit and NumberIdx, to index into the arrays Card.sSuit and Card.sNumber, retreiving their suits and numbers as a string
    /// </summary>
    class Card
    {
        public readonly static string[] sSuit = {"Spade", "Club", "Diamond", "Heart"};
        public readonly static string[] sNumber = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        public readonly int SuitIdx;
        public readonly int NumberIdx;
 
        /// <summary>
        /// Create an instance of a card.
        /// </summary>
        /// <param name="_suitIdx">The index to retrieve the suit of this card as a string from array Card.sSuit</param>
        /// <param name="_numberIdx">The index to retreve the number of this card as a string Card from array Card.sNumber.</param>
        public Card(int _suitIdx, int _numberIdx)
        {
            this.SuitIdx = _suitIdx;
            this.NumberIdx = _numberIdx;
        }

        public override string ToString()
        {
            return $"{sNumber[this.NumberIdx], 2}--{sSuit[this.SuitIdx], -9}";
        }
    }
}