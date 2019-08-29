#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

//    cout << "Please enter a date in format xxxx-xx (year-month): ";
//    string date_string;
//    cin >> date_string;
//
//    double rate_outcome = find_rate(rate, date, date_string);
//    cout << "The corresponding rate on the entered date is "
//    << rate_outcome << endl;
//
//    cout << "The difference between the rate on the entered date and average rate is "
//    << rate_outcome - ave << endl;

    while (cin)
    {
        cout << "Please enter a date in format xxxx-xx (year-month) or enter ctrl-z to exit: ";
        string date_string;
        cin >> date_string;

        double rate_outcome = find_rate(rate, date, date_string);
        cout << "The corresponding rate on the entered date is "
        << rate_outcome << endl;

        cout << "The difference between the rate on the entered date and average rate is "
        << rate_outcome - ave << endl;

    }

// This code should allow the user to continue to input dates
// until the user inputs the EOF (End-of-file), namely control-d (in linux/mac) or control-z (in windows)
// This should not crash if a bad date is entered.

   return 0.0; // program end
}

