namespace Q5
{
    /// <summary>
    /// Each card instance owns two readonly int properties, Suit and NumberIdx, to index into the arrays Card.sSuit and Card.sNumber, retreiving their suits and numbers as a string
    /// </summary>
    class Card
    {
        private readonly static string[] sSuit = {"Spade", "Club", "Diamond", "Heart"};
        private readonly static string[] sNumber = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        private int suitIdx;
        private int numberIdx;

        public string Suit => sSuit[this.suitIdx];

        public string Number => sNumber[this.numberIdx];

        /// <summary>
        /// Create an instance of a card.
        /// </summary>
        /// <param name="_suitIdx">The index to retrieve the suit of this card as a string from array Card.sSuit</param>
        /// <param name="_numberIdx">The index to retreve the number of this card as a string Card from array Card.sNumber.</param>
        public Card(int _suitIdx, int _numberIdx)
        {
            this.suitIdx = _suitIdx;
            this.numberIdx = _numberIdx;
        }

        public override string ToString()
        {
            return string.Format("{0,2}--{1,-9}", this.Number, this.Suit);
        }
    }
}