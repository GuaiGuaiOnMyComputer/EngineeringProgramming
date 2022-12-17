namespace Q4
{
    class Card
    {
        public readonly static string[] sSuit = {"berry", "flower", "diamond", "heart"};
        public readonly static string[] sNumber = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        public readonly int SuitIdx;
        public readonly int numberIdx;
 
        public Card(int _suitIdx, int _numberIdx)
        {
            this.SuitIdx = _suitIdx;
            this.numberIdx = _numberIdx;
        }
    }
}

