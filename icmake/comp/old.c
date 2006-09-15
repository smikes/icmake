/*
                            O L D . C
*/

#include "iccomp.h"

ESTRUC_ *old (lval, rval)
    ESTRUC_
        *lval,
        *rval;
{
//    if (initialization)
//        
//    {
//        semantic(init_expr_not_const);
//        return nullframe(lval);
//    }

    if (test_binop(op_older, lval, rval))
        return (lval);                      /* test for correct types */

    etoc(lval);                             /* convert to code */
    etoc(rval);

    defcode(lval, rval, op_older);

    return (lval);                          /* return new expression */
}


