#ifndef CPP
#define CPP

#include "../Candidate.hpp"
#include "Handler.hpp"
#include <memory>

class CppRequirements: public Handler
{
public:
    ~CppRequirements(){};
    CppRequirements(unsigned int minCppRequirements_)
    {
        minCppRequirements = minCppRequirements_;
    }
    virtual bool handle_request_and_validate(const Candidate& c) override
    {
        if(c.cppFluency >= minCppRequirements)
        {
            if(next)
            {
                next->handle_request_and_validate(c);
            }
            else
                return true;
        }
        else
            return false;

    };

     void set_next(std::shared_ptr<Handler> handler) override
    {
         if (!next)
          next = handler;
    };
private:
    unsigned int minCppRequirements;
    std::shared_ptr<Handler> next = nullptr;
};

#endif
