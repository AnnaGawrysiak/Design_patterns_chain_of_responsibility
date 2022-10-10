#include <vector>
#include <iostream>

#include "Application.hpp"
#include "Candidate.hpp"
#include "CooperationNeeded.hpp"
#include "CppRequirements.hpp"
#include "CRequirements.hpp"
#include "WageRequirements.hpp"
#include "CandidatesValidator.hpp"

int main()
{
    std::vector<Candidate> candidates{
        {"Adelajda", 15, 87, 0, 12000},
        {"Brunhilda", 85, 42, 1, 11000},
        {"Ciechosław", 97, 92, 1, 25000},
        {"Domażyr", 91, 45, 0, 10000}};


    //cppFluency(cpp), cFluency(c), cooperative(coop), preferredWage(wage)

    bool coop = true;
    unsigned int  cpp = 20;
    unsigned int c = 0;
    unsigned int  wage = 15000;

    for(const auto& candidate: candidates)
    {
        if (validate(candidate, coop, cpp, c , wage))
            std::cout << "Candidate " << candidate.name << " seems to fit" << std::endl;
        else
            std::cout << "Candidate " << candidate.name << " does not seem to fit" << std::endl;
    }

    return 0;
}
