#ifndef HANDLER
#define HANDLER

#include "Candidate.hpp"
#include <memory>

class Handler
{
public:
    virtual ~ Handler() {};
    virtual void set_next(std::shared_ptr<Handler> handler)=0;
    virtual bool handle_request_and_validate(const Candidate& c)=0;
};

#endif