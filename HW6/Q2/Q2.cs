using System.Linq;
using System;

namespace Q2;

class Program
{
    static void Main(string[] args)
    {
        var myTup = (2, 0, 4, 6, 1, 6);
        // Console.WriteLine(myTup[0]);
    }

    static (int min, int max) FindMinMax()
    {
        int[] arr = new int[]{ 1, 2, 4, 5, 21, 22 };
        return (arr.Min(), arr.Max());
    }
}