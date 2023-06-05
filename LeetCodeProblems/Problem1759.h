#pragma once
#include <string>
using namespace std;

//1759. Count Number of Homogenous Substrings

class Problem1759 {

public:
    int countHomogenous(string s) {
        long long homogenousNumber = 1;
        long long counter = 1;
        for (int i = 1;i < s.length();i++) {

            if (s[i] == s[i - 1]) {
                counter++;
            }
            else {
                counter = 1;
            }
            homogenousNumber = homogenousNumber + counter % 1000000007;
            //z 1 
            //zz = 3
            //zzz = 6
            //zzzz = 10
            //zzzzz = 15
            //zzzzzz = 21

        }

        return homogenousNumber;
    }

    void StartTest() {
        string val;
        while (cin >> val && val != "") {
            int countHomogenousNumber = countHomogenous(val);
            //countHomogenousNumber =  (countHomogenousNumber % 10 + 10) % 10;
            std::cout << countHomogenousNumber << endl;
        }
    }

};

