// File:Main2Tuple.cs     StuID:B10831020 Date: 2022-Dec-2
// TODO: Refeactoring ... (Main2Tuple.cs )
//
using System;
using System.Diagnostics;  // for Assert( )

class Program {
  public static void Main (string[] args) {
    string msg ="[觀-照-知-悟-證-行]::ME5015 工程領域的程式語言實務";
    int[] userInput = new int[2];
    Console.WriteLine (msg + " StuID = B10831020");
    Console.WriteLine("[TUPLE DEMO] Two Numbers:111 220 is assumed");
    HelloWorldMsg(msg); // New added. TimeStamp is shown.
    Console.WriteLine("Please enter the first number");
    userInput[0] = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Please enter the seconde number");
    userInput[1] = Convert.ToInt32(Console.ReadLine());

    Tuple<double, double> result = CalSumAndAvg(userInput);
    Console.WriteLine($"sum = {result.Item1}");
    Console.WriteLine($"avg = {result.Item2}");
    // wait for your key to stop its exectution
    Get2Values ((int)result.Item2); //casting is needed.
    Get2Values ((int)result.Item1, 11); //TODO - why ?
  //  Get2Values ((int)result.Item1, 3); //Try this -uncomment it
    Console.ReadKey();
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
  public static void HelloWorldMsg (string msg){
     string now1 = DateTime.Now +"\n"+msg+"\n"; 
     Console.WriteLine($"{now1}");
  }	 
  
 //  GOAL:: GenerateRandomNumbers -- 
 //  TODO: make it complete as a new Method:
  public static void Get2Values(int ceiling, int cCount=5 ){
    Random rnd = new Random();
    int inum1, inum2; 
    Debug.Assert(cCount >=5);  // Microsoft - MSDOCS
    
    Console.WriteLine($"\nLoop count {cCount}\n") ; //TODO 
    for (var idx =0; idx < cCount ;idx++) {
      inum1 =  rnd.Next() % ceiling; 
      inum2  = rnd.Next() % ceiling *10; 
      Console.WriteLine("Loop= {2:G3}, {0:G4}, {1:G4}", inum1, inum2, idx );
    }
  }
		// 
} // END of Class 