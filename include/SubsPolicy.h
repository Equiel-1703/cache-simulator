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
    
    virtual void registerAccess(int via) = 0;
    virtual int getViaToReplace() = 0;
    virtual SubsPolicy *clone() = 0;
};
