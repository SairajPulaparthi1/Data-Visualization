#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

int main()
{
  /*Naming variables to use*/
    string title;
    string col_1_header;
    string col_2_header;
    string input = "";
    int comma_place;
    vector<string> vec1;
    vector<int> vec2;
    int title_width = 33;
    int col_1_width = 20;
    int col_2_width = 23;
/* ask the user inputs for further analysis*/
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, col_1_header);
    cout << "You entered: " << col_1_header << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, col_2_header);
    cout << "You entered: " << col_2_header << endl;

    cout << "Enter a data point (-1 to stop input):" << endl;
    getline(cin, input);
/* create the loop till the user presses -1*/
    while (input != "-1") {
        try {
            comma_place = input.find(',');

            if (comma_place == string::npos) {
                throw runtime_error("Error: No comma in string.");
            }


            if (input.find(',', comma_place + 1) != string::npos) {
                throw runtime_error("Error: Too many commas in input.");
            }

            string data_string = input.substr(0, comma_place);
            string data_int = input.substr(comma_place + 1);


            if (data_int.empty()) { /*stack overflow */
                throw runtime_error("Error: Comma not followed by an integer.");
            }

            int change_num = stoi(data_int);

            vec1.push_back(data_string);
            vec2.push_back(change_num);

            cout << "Data string: " << data_string << endl;
            cout << "Data integer: " << change_num << endl;
        } catch (runtime_error& msg) {
            cout << msg.what() << endl;
        } catch (invalid_argument&) {
            cout << "Error: Comma not followed by an integer." << endl;
        } catch (out_of_range&) {
            cout << "Error: Integer value out of range." << endl;
        }

        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, input);
    }

    cout << endl;
    cout << setw(title_width) << title << endl;
    cout << setw(col_1_width) << left << col_1_header <<"|"
         << setw(col_2_width) << right << col_2_header << endl;

    cout << string(col_1_width + col_2_width + 1, '-') << endl;

    for (int i = 0; i < vec1.size(); ++i) {
        cout << setw(col_1_width) << left << vec1[i] << "|"
             << setw(col_2_width) << right << vec2[i] << endl;
    }

    cout << endl;
    for (int i = 0; i < vec1.size(); ++i) {
        cout << setw(col_1_width) << right << vec1[i] << " ";
        cout << right << string(vec2[i], '*') << endl;
    }

    return 0;
}




   /* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2

   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces

   Print out data in table format

   Print out data in chart format
   */
// WRITE YOUR CODE HERE

