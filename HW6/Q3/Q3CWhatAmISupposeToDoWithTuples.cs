// using System;


// namespace Q3C
// {
//     class Program
//     {
//         static void Main(string[] args)
//         {
//             var grades =
//             (
//                 (90, 90, 80),
//                 (80, 80, 70), 
//                 (50, 60, 70), 
//                 (40, 80, 80),
//                 (60, 60, 70),
//                 (70, 80, 70),
//                 (90, 60, 50),
//                 (30, 80, 60),
//                 (60, 60, 50)
//             );
//             int nStudents = 9;
//             int nExams =  3;
//             float[] examAvg = new float[nExams];
//             float[] studentAvg = new float[nStudents];
//             CalculateExamAvg(grades, ref examAvg, nExams, nStudents);
//             CalculateStudentAvg(grades, ref studentAvg, nExams, nStudents);
//             Console.ReadKey();
//         }

//         static void ExportResult(float[] _examAvg, float[] _studentAvg, int _nStudents, int _nExams)
//         {
//             Console.WriteLine(String.Format("{0,10}{1,18}{2,6}{3,12}", "Student", "Grades", " ", "Stu Avg"));
//             Console.WriteLine(new String('-', 46));
//             for (int i = 0; i < _nStudents; i++){
//                 for (int j = 0; j < _nExams; j++){
//                     if(j == 0){ // printing the first score of each student to console, encluding the student's number
//                         Console.Write(String.Format("{0,10}{1,8}", i, sGrades[i, j]));
//                     }else if(j == _nExams -1){ // printing the last score of each studnet to console, encluding the student's average
//                         Console.Write(String.Format("{0,8}{1,12:F3}\n", sGrades[i, j], _studentAvg[i]));
//                     }else{
//                         Console.Write(String.Format("{0,8}", sGrades[i, j]));
//                     }
//                 }
//             }
//             Console.WriteLine(new String('-', 46));
//             Console.WriteLine(String.Format("{0,-10}{1,8:F3}{2,8:F3}{3,8:F3}", "Avg", _examAvg[0], _examAvg[1], _examAvg[2]));
//         }
//         static void CalculateExamAvg(ref float[] examAvg, int _nExam, int _nStudent)
//         {
//             for (int j = 0; j < _nExam; j++){
//                 examAvg[j] = 0;
//                 for (int i = 0; i < _nStudent; i++)
//                 {
//                     examAvg[j] += sGrades[i, j];
//                 }
//                 examAvg[j] /= _nStudent;
//             }
//         }

//         static void CalculateStudentAvg(ref float[] studentAvg, int _nExam, int _nStudent)
//         {
//             for (int i = 0; i < _nStudent; i++){
//                 studentAvg[i] = 0;
//                 for (int j = 0; j < _nExam; j++){
//                     studentAvg[i] += sGrades[i, j];
//                 }
//                 studentAvg[i] /= _nExam; // divide the sum of students' 3 exam scores by 3 to get his/her average
//             }
//         }

//     }
// }