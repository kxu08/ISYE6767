#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

double average(vector<double> v)
{
// code for calculating average of members of v
// and returning the average
    double ave;
    double sum = 0;
    for (int i=0; i != v.size(); i++){
        sum += v[i];
    }
    ave = sum / v.size();
    return ave;
}

double find_rate(vector<double> rate_vec, vector<string> date_vec, string date)
{
// code for finding the Baa rate for the
// given date (in yyyy-mm format)
// and returning the rate for that month
    for (int i=0; i != date_vec.size(); i++){
        if (date == date_vec[i])
            return rate_vec[i];

    }
}

int main()
{
    vector<double> rate;
    vector<string> date;
    ifstream infile("./hw1_H.15_Baa_Data.csv");

// code for loading rate and date vectors from the file hw1_H.15_Baa_Data.csv
// the headers should be handled properly. do not delete them manually
    string first_ele;
    string second_ele;

    while(infile.good()){
        getline(infile, first_ele, ',');
        getline(infile, second_ele);
        if (first_ele.find("-") != string::npos)
        {
            date.push_back(first_ele);
            rate.push_back(stod(second_ele));
        }
    }

   infile.close();

// code for prompting user for a date and returning the rate
// and the difference between the rate for that date and the
// average rate
//

    double ave = average(rate);
//    regex date_format("\\b\\d{4}[-]\\d{2}\\b");
//    regex date_format("^\\d{4}[-]([1-9]|0[1-9]|1[012])");

    // using regular expression to check whether the date format is acceptable
    // notice that xxxx-x is also acceptable here
    regex date_format("^(19|20)\\d{2}[-]([1-9]|0[1-9]|1[012])");


    while (true)
    {
        cout << "Please enter a date in format xxxx-xx (year-month) or enter ctrl+z to exit: ";
        string date_string;
        cin >> date_string;

        if (cin.eof())
            break;

        // if the entry format is xxxx-x, change it to xxxx-xx according to Dr. Deng's suggestion
        if ((regex_match(date_string, date_format)) && (date_string.size() == 6))
        {
            date_string = date_string.substr(0,5) + "0" + date_string.substr(5,1);
        }


        if (!regex_match(date_string, date_format))  // if the date entry is not valid, ask to enter it again
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "The date format is invalid, please enter again." << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << endl;
        }
        // check if the date entry is in the date set. If not, ask to enter it again
        else if (!(find(date.begin(), date.end(), date_string) != date.end()))
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "The date you entered is out of range, please enter again." << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << endl;
        }
        else
        {
            double rate_outcome = find_rate(rate, date, date_string);
            cout << "---------------------------------------------------------------" << endl;
            cout << "The average rate is " << ave << endl;
            cout << "The corresponding rate on the entered date is "
            << rate_outcome << endl;
            cout << "The difference between the rate on the entered date and average rate is "
            << rate_outcome - ave << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << endl;
        }

    }

// This code should allow the user to continue to input dates
// until the user inputs the EOF (End-of-file), namely control-d (in linux/mac) or control-z (in windows)
// This should not crash if a bad date is entered.

   return 0.0; // program end
}

