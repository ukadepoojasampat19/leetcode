#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string solve(int num, unordered_map<int, string>& belowTen, unordered_map<int, string>& belowTwenty, unordered_map<int, string>& belowHundred) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num];
        }
        if (num < 100) { // e.g., 89
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + belowTen[num % 10] : "");
        }
        if (num < 1000) { // e.g., 899
            return solve(num / 100, belowTen, belowTwenty, belowHundred) + " Hundred" + (num % 100 != 0 ? " " + solve(num % 100, belowTen, belowTwenty, belowHundred) : "");
        }
        if (num < 1000000) { // e.g., 899,999
            return solve(num / 1000, belowTen, belowTwenty, belowHundred) + " Thousand" + (num % 1000 != 0 ? " " + solve(num % 1000, belowTen, belowTwenty, belowHundred) : "");
        }
        if (num < 1000000000) { // e.g., 899,999,999
            return solve(num / 1000000, belowTen, belowTwenty, belowHundred) + " Million" + (num % 1000000 != 0 ? " " + solve(num % 1000000, belowTen, belowTwenty, belowHundred) : "");
        }
        return solve(num / 1000000000, belowTen, belowTwenty, belowHundred) + " Billion" + (num % 1000000000 != 0 ? " " + solve(num % 1000000000, belowTen, belowTwenty, belowHundred) : "");
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        // Mapping numbers to words
        unordered_map<int, string> belowTen = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
        unordered_map<int, string> belowTwenty = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
        unordered_map<int, string> belowHundred = {{2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};

        return solve(num, belowTen, belowTwenty, belowHundred);
    }
};
