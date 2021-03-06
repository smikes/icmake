/*
\funcref{fun\_shl}{void fun\_shl ()}
    {}
    {}
    {pop(), push(), error()}
    {}
    {funshl.c}
    {
        This function pops two variables and pushes the shift-left result of 
        the {\em vu.intval} fields of these variables.  The resulting pushed 
        variable is of type {\em e\_int}.  

        It is assumed that the left argument of the expression was pushed 
        first; therefore, the right argument is popped first. 
        
    } 
*/ 

#include "opcodefun.ih"

void fun_shl ()
{
    int rvalue = intValue(top());

    pop();
    intSetValue(top(), intValue(top()) << rvalue);
}


