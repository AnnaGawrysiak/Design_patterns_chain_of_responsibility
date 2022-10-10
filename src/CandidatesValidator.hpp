#ifndef VALIDATE
#define VALIDATE
#include <memory>

#include "Candidate.hpp"
#include "CooperationNeeded.hpp"
#include "CppRequirements.hpp"
#include "CRequirements.hpp"
#include "WageRequirements.hpp"


bool validate(const Candidate& candidate, bool coop_, unsigned int cpp_, unsigned int c_ , unsigned int wage_)
{
    std::shared_ptr<CooperationNeeded> coop = std::make_shared<CooperationNeeded>(coop_);
    std::shared_ptr<CppRequirements> cpp = std::make_shared<CppRequirements>(cpp_);
    std::shared_ptr<CRequirements> c = std::make_shared<CRequirements>(c_);
    std::shared_ptr<WageRequirements> wage = std::make_shared<WageRequirements>(wage_);

    coop->set_next(cpp);
    cpp->set_next(c);
    c->set_next(wage);

    return coop->handle_request_and_validate(candidate);
}

#endif