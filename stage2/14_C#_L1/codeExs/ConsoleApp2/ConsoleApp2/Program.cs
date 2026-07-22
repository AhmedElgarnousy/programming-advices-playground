using System;
using System.IO.MemoryMappedFiles;


public class MathLib
{
    public static int Add(int n1, int n2) { return n1 + n2; }
}
internal class Program
{
    //public static int Add(int n1, int n2) { return n1 + n2; }
    
    private static void Main(string[] args)
    {
        Console.WriteLine(MathLib.Add(2,3));
    }

}