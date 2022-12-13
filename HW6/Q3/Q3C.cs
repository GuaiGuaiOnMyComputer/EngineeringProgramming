using System;


namespace Q3C
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Student ID: B10831020\nRedoing Q3B with tuples");
            var (examAvg, studentAvg) = CalculateBothAvg();
            ExportResult(examAvg, studentAvg, sGrades.GetLength(0), sGrades.GetLength(1));
            Console.ReadKey();
        }

        static Tuple<float[], float[]> CalculateBothAvg()
        {
            return Tuple.Create(CalculateExamAvg(), CalculateStudentAvg());
        }

        static void ExportResult(float[] _examAvg, float[] _studentAvg, int _nStudents, int _nExams)
        {
            
            Console.WriteLine(String.Format("{0,10}{1,18}{2,6}{3,12}", "Student", "Grades", " ", "Stu Avg"));
            Console.WriteLine(new String('-', 46));
            for (int i = 0; i < _nStudents; i++){
                for (int j = 0; j < _nExams; j++){
                    if(j == 0){ // printing the first score of each student to console, encluding the student's number
                        Console.Write(String.Format("{0,10}{1,8}", i, sGrades[i, j]));
                    }else if(j == _nExams -1){ // printing the last score of each studnet to console, encluding the student's average
                        Console.Write(String.Format("{0,8}{1,12:F3}\n", sGrades[i, j], _studentAvg[i]));
                    }else{
                        Console.Write(String.Format("{0,8}", sGrades[i, j]));
                    }
                }
            }
            Console.WriteLine(new String('-', 46));
            Console.WriteLine(String.Format("{0,-10}{1,8:F3}{2,8:F3}{3,8:F3}", "Avg", _examAvg[0], _examAvg[1], _examAvg[2]));
        }
        static float[] CalculateExamAvg()
        {
            int nStudents = sGrades.GetLength(0);
            int nExams = sGrades.GetLength(1);
            float[] examAvg = new float[sGrades.GetLength(1)];
            for (int j = 0; j < nExams; j++){
                examAvg[j] = 0;
                for (int i = 0; i < nStudents; i++)
                {
                    examAvg[j] += sGrades[i, j];
                }
                examAvg[j] /= nStudents;
            }
            return examAvg;
        }

        static float[] CalculateStudentAvg()
        {
            int nStudents = sGrades.GetLength(0);
            int nExams = sGrades.GetLength(1);
            float[] studentAvg = new float[nStudents];
            for (int i = 0; i < nStudents; i++){
                studentAvg[i] = 0;
                for (int j = 0; j < nExams; j++){
                    studentAvg[i] += sGrades[i, j];
                }
                studentAvg[i] /= nExams; // divide the sum of students' 3 exam scores by 3 to get his/her average
            }
            return studentAvg;
        }
        private static readonly int[,] sGrades = 
        {
            {90, 90, 80},
            {80, 80, 70}, 
            {50, 60, 70}, 
            {40, 80, 80},
            {60, 60, 70},
            {70, 80, 70},
            {90, 60, 50},
            {30, 80, 60},
            {60, 60, 50}
        };

    }
}