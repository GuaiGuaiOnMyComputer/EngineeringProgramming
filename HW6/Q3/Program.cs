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
            int[] pointIdxFarthestApart = new int[2];
            foreach(int pt1Idx in extrimumIdxs){
                foreach(int pt2Idx in extrimumIdxs){
                    if(pt1Idx != pt2Idx){
                        double distance = Math.Sqrt(Math.Pow(mPoints[pt1Idx, 0] - mPoints[pt2Idx, 0], 2) + Math.Pow(mPoints[pt2Idx, 1] - mPoints[pt1Idx, 1], 2));
                        if(distance > maxDistance){
                            maxDistance = distance;
                            pointIdxFarthestApart[0] = pt1Idx;
                            pointIdxFarthestApart[1] = pt2Idx;
                        }
                    }
                }
            }
            mPrintResult(pointIdxFarthestApart[0], pointIdxFarthestApart[1], maxDistance);
            Console.ReadKey();
        }
        private static void mPrintResult(int idx1, int idx2, double distance)
        {
            Console.WriteLine("The two points fartest apart are ({0}, {1}) and ({2}, {3})", mPoints[idx1, 0], mPoints[idx1, 1], mPoints[idx2, 0], mPoints[idx2, 1]);
            Console.WriteLine("With distance {0:F3}", distance);
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