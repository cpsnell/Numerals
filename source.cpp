
// Roman Numerals

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <array>
#include <utility> // std::pair
using namespace std;

// Replace All
std::string ReplaceString(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}

int convertNumeral(std::string numeral)
{
    // Convert all 2 character values to unused 1 variable values
    std::vector <pair<std::string, std::string>> preprocessLUT
    {
        {std::string("IV"), std::string("N")},
        {std::string("IX"), std::string("O")},
        {std::string("XL"), std::string("P")},
        {std::string("XC"), std::string("Q")},
        {std::string("CD"), std::string("R")},
        {std::string("CM"), std::string("S")}
    };
    
    // Combination of chosen unused character variables and known roman numerals
    std::map <char, int> afterprocessMAP
    {{
        {'N', 4},
        {'O', 9},
        {'P', 40},
        {'Q', 90},
        {'R', 400},
        {'S', 900},
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    }
    };
    
    std::string newnumeral(numeral);
    //newnumeral = numeral;
    
    for(auto i : preprocessLUT)
    {
        newnumeral = ReplaceString(newnumeral, i.first, i.second);
    }

   int total = 0;
   for(char j : newnumeral)
   {
       total += afterprocessMAP.at(j);
   }

    return total;
}

int main(int argc, const char * argv[]) {
    try {
        int total = convertNumeral("XX");
        std::cout << total;
        return EXIT_SUCCESS;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
