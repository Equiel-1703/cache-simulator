#pragma once

class SubsPolicy
{
protected:
    int assoc;

public:
    SubsPolicy(int assoc)
    {
        this->assoc = assoc;
    }
    
    virtual void registerAccess(int via, int tag) = 0;
    virtual int getViaToReplace() = 0;
};
