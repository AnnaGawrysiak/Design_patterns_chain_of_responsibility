#ifndef WAGE
#define WAGE

#include "../Candidate.hpp"
#include "Handler.hpp"
#include <memory>
#include <iostream>

class WageRequirements: public Handler
{
public:
    ~WageRequirements(){};
    WageRequirements(unsigned int maxPreferredWage_)
    {
        maxPreferredWage = maxPreferredWage_;
    }
    virtual bool handle_request_and_validate(const Candidate& c) override
    {
        if(c.preferredWage <= maxPreferredWage)
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
    unsigned int maxPreferredWage;
    std::shared_ptr<Handler> next = nullptr;
};

#endif 