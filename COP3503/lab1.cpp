#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
   cout << "Enter a title for the data:" << endl;
   string title, col1, col2;
   getline(cin, title);
   cout << "You entered: " << title << endl;
   cout << "Enter the column 1 header:" << endl;
   getline(cin, col1);
   cout << "You entered: " << col1 << endl;
   cout << "Enter the column 2 header:" << endl;
   getline(cin, col2);
   cout << "You entered: " << col2 << endl;
   vector<string> data1;
   vector<int> data2;
   string input = "";
   while (input != "-1")
   {
      cout << "Enter a data point (-1 to stop input):" << endl;
      getline(cin, input);
      if (input == "-1")
         break;
      //try: if input is not valid, throw an error.
      try
      {
               //catch: no comma in the string
         size_t commaPosition = input.find(',');
         if(commaPosition == string::npos)
         {
            throw ("Error: No comma in string.");
         }
         //catch: more than one comma in the string
         if(input.find(',', commaPosition + 1) != string::npos)
         {
            throw ("Error: Too many commas in input.");
         }
         //catch: second part is not an integer
         string part1 = input.substr(0, commaPosition);
         int part2 = stoi(input.substr(commaPosition + 1));
         data1.push_back(part1);
         data2.push_back(part2);
         cout << "Data string: " << part1 << endl;
         cout << "Data integer: " << part2 << endl;
      }
      catch (char const* error){
         cout << error << endl;
      }
      catch (invalid_argument& e){
         cout << "Error: Comma not followed by an integer." << endl;
      }
   }
   
 //print table
   cout << endl;
   cout << setw(33) << right << title << endl;
   cout << setw(20) << left << col1 << "|" << setw(23) << right << col2 << endl;
   cout << setfill('-') << setw(44) << "" << endl;
   for (size_t i = 0; i < data1.size(); i++){
      cout << left << setfill(' ') << setw(20) << data1[i] << "|" 
             << right << setw(23) << data2[i] << endl;
   }
//print histogram
   cout << endl;
   for (size_t i = 0; i < data1.size(); i++){
      cout << right << setfill(' ') << setw(20) << data1[i] << " ";
      for (int j = 0; j < data2[i]; j++){
         cout << "*";
      }
      cout << endl;
   }
   return 0;
}