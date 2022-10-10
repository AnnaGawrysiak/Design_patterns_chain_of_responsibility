#ifndef C
#define C

#include "../Candidate.hpp"
#include "Handler.hpp"
#include <memory>

class CRequirements: public Handler
{
public:
    ~CRequirements(){};
    CRequirements(unsigned int minCRequirements_)
    {
        minCRequirements = minCRequirements_;
    }
        virtual bool handle_request_and_validate(const Candidate& c) override
        {
            if(c.cFluency >= minCRequirements)
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
    unsigned int minCRequirements;
    std::shared_ptr<Handler> next = nullptr;
};

#endif