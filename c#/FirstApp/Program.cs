using System;

namespace HelloWorld
{
  class Program
  {
    static void Main(string[] args)
    {
            TestClass test = new TestClass
            {
                A = 5
            };
            Console.WriteLine(test.A);
    }
  }
}