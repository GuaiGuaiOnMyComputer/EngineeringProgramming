using System;

namespace Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Student ID: B10831020");
            // find the two points farthest apart:
            // Step1: find the index of the 4 points with max x, max y, min x , min y coordinates. Maximun distance must occur between these 4 points
            // Step2: calculate the distances between these 4 points
            // Step3: sort the distances in acsending order
            int[] extrimumIdxs = {FindMin(mPoints, 0), FindMin(mPoints, 1), FindMax(mPoints, 0), FindMax(mPoints, 1)};
            double maxDistance = 0;
            foreach(int pt1Idx in extrimumIdxs){
                foreach(int pt2Idx in extrimumIdxs){
                    double distance = Math.Sqrt(Math.Pow())
                    if(pt1Idx != pt2Idx){
                        
                    }
                }
            }

        }
        private static int FindMax(double[,] arr, int axis)
        {
            int currentExtreme = 0;
            for(int i = 0; i < arr.GetLength(axis); i++){
                currentExtreme = arr[i, axis] > arr[currentExtreme, axis] ? i : currentExtreme;
            }
            return currentExtreme;
        }
        private static int FindMin(double[,] arr, int axis)
        {
            int currentExtreme = 0;
            for(int i = 0; i < arr.GetLength(axis); i++){
                currentExtreme = arr[i, axis] < arr[currentExtreme, axis] ? i : currentExtreme;
            }
            return currentExtreme;
        }
        private readonly static double [,] mPoints = {
            {0, 0}, 
            {2.2, -2.3},
            {3.4, -8.5},
            {-9.5, -2.1},
            {10.3, -2.1}, 
            {7.5, 4.4},
            {2.1, 4.4}
        };
    }    
}