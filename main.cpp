#include <iostream>
#include "first.h"
#include <string> // allows use of std::string



int main()
{
    /*----------------
    std::string
    -----------------*/

    //Just like normal variables, you can initialize or assign values to strings as you would expect:

    std::string empty {}; // empty string 
    std::string myName { "sloiczek" } ;
    myName = "Ania"; // assign variable myName the string literal "Ania"

    //Note that strings can hold numbers as well:

    std::string myID{ "77" }; // "77" is not the same as integer 77!

    /*----------------------
    String input and output
    -----------------------*/

    std::cout << "my name is: " << myName << '\n'; //Strings can be output as expected using std::cout.



    return 0;
}