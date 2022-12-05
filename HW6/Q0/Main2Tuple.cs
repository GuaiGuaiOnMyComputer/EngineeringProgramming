// File:Main2Tuple.cs     StuID:B10831020 Date: 2022-Dec-2
// TODO: Refeactoring ... (Main2Tuple.cs )
//
using System;
using System.Diagnostics;  // for Assert( )

class Program{
  public static void Main (string[] args) 
  {
    int[] userInput = new int[2];
    HelloWorldMsg(); // New added. TimeStamp is shown.
    GetUserInput(out userInput[0], out userInput[1]);
    Tuple<double, double> result = CalSumAndAvg(userInput);
    Console.WriteLine($"sum = {result.Item1}");
    Console.WriteLine($"avg = {result.Item2}");
    var sb = new System.Text.StringBuilder();
    // Get2Values((int)result.Item2); //casting is needed.
    // Get2Values((int)result.Item1, 11); //TODO - why ?
    Get2Values ((int)result.Item1, 3, ref sb); //Try this -uncomment it
      // result is a tuple holding 2 doubles, while the method Get2Falues is a function taking int as parameters
    Console.Write(sb.ToString());
    Console.ReadKey();
  }

  public static void GetUserInput(out int n1, out int n2)
  {
    Console.WriteLine("Please enter the first number");
    n1 = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Please enter the seconde number");
    n2 = Convert.ToInt32(Console.ReadLine());
  }

// Check out the defintion of ValueTuple in c# 7.0 spec.
  static Tuple<double, double> CalSumAndAvg(int[] numbers){

    double sum = 0;
    double avg;
    for (int i = 0; i < numbers.Length; i++)
    {
        sum += numbers[i];
    }
    avg =  sum / numbers.Length;
    return new Tuple<double, double>(sum, avg);
  }
// TODO: Added -- call this 
  public static void HelloWorldMsg()
  {
    string msg ="[觀-照-知-悟-證-行]::ME5015 工程領域的程式語言實務";
    string now1 = DateTime.Now +"\n"+msg+"\n"; 
    Console.WriteLine("Student ID: B10831020");
    Console.WriteLine($"{now1}");
  }	 
  
 //  GOAL:: GenerateRandomNumbers -- 
 //  TODO: make it complete as a new Method:
  public static void Get2Values(int ceiling, int cCount, ref System.Text.StringBuilder _sb){
    Random rnd = new Random();
    int inum1, inum2; 
    // Debug.Assert(cCount >=5);  // Microsoft - MSDOCS
    
    _sb.AppendLine($"\nLoop count {cCount}\n") ; //TODO 
    for (var idx =0; idx < cCount ;idx++) {
      inum1 = rnd.Next() % ceiling; 
      inum2 = rnd.Next() % ceiling *10; 
      _sb.AppendLine(String.Format("Loop= {2:G3}, {0:G4}, {1:G4}", inum1, inum2, idx ));
    }
  }
		// 
} // END of Class 