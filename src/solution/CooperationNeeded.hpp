#ifndef COOP
#define COOP

#include "../Candidate.hpp"
#include "Handler.hpp"
#include <memory>


class CooperationNeeded: public Handler
{
public:
    ~CooperationNeeded(){};
    CooperationNeeded(bool needed_)
    {
        needed = needed_;
    }
    virtual bool handle_request_and_validate(const Candidate& c) override
    {
        if(c.cooperative == needed)
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
    std::shared_ptr<Handler> next = nullptr;
    bool needed;
};

#endif