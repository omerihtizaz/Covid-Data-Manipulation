#include<iostream>
struct p6
{
    std::string name;
    int val;
    int amount;
    bool const operator<(const p6& a)
    {
        if( val < a.val)
        return true;
        return false;
    }
    
};