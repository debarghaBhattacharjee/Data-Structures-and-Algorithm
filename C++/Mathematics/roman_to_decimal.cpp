// PROBLEM STATEMENT: print the decimal equivalent of a roman numeral string.
// EXAMPLE: VIII = 8, XVIII = 18

#include <iostream>
#include <string>
using namespace std;

// Function to get base decimal equivalent of some 
// basic roman numerals.
int get_base_decimal(const string &roman) {
    if(roman == "I")
        return 1;
    else if(roman == "II")
        return 2;
    else if(roman == "III")
        return 3;
    else if(roman == "IV")
        return 4;
    else if(roman == "V")
        return 5;
    else if(roman == "VI")
        return 6;
    else if(roman == "VII")
        return 7;
    else if(roman == "VIII")
        return 8;
    else if(roman == "IX")
        return 9;
    else if(roman == "X")
        return 10;
    else if(roman == "L")
        return 50;
    else if(roman == "C")
        return 100;
    else if(roman == "D")
        return 500;
    else if(roman == "M")
        return 1000;
    else
        return -1;
    return -1;
}

// Function to convert a roman string to its equivalent
// decimal integer.
int roman_to_decimal(const string &roman) {
    int decimal = 0;
    int n = roman.length();
    int i = 0;
    while (i < n) {
        // Here, 
        //    s1 = decimal equivalent of current roman literal
        //    s2 = decimal equivalent of next literal
        int s1 = get_base_decimal(string(1, roman[i]));\
        if (i + 1 < n) {
            // If there is a roman literal next, simply update 
            // decimal as: decimal = decimal + s1
            int s2 = get_base_decimal(string(1, roman[i+1]));
            if (s1 >= s2) {
                // If s1 >= s2, then update decimal as: 
                // decimal = decimal - s1
                decimal = decimal + s1;
                i = i + 1;
            } else {
                // If s2 > s1, then update decimal as: 
                // decimal = decimal + s2 - s1
                decimal = decimal + s2 - s1;
                i = i + 2;
            }
        } else {
            // If there is no next roman literal, simply update 
            // decimal as: decimal = decimal + s1
            decimal = decimal +  s1;
            i = i + 1;
        }
    }
    return decimal;
}

// Driver program
int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // Your code goes here.
    string roman;
    cin >> roman;
    // cout << roman << endl;
    int decimal = roman_to_decimal(roman);
    cout << decimal << endl;
    
    return 0;
}