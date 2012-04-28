// Generated by Flexc++ V0.97.20 on Thu, 26 Apr 2012 19:57:43 +0200

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "scannerbase.h"

#include <unordered_map>
#include <string>
#include <sstream>
#include <stack>

#include <bobcat/stat>

#include "../file/file.h"

// $insert classHead
class Scanner: public ScannerBase
{
    bool d_includeFile;
    bool d_ppSpace;
    bool d_ppNewline;
    int d_token;
    size_t d_ignore;
    size_t d_number;
    std::istringstream d_defineStream;
    std::stack<size_t> d_ifdef;
    std::string const &d_matched;
    std::string d_ppIdent;
    std::unordered_map<std::string, std::string> d_defined;

    std::stringstream d_pp;
    void (Scanner::*d_ppOut)();
    void (Scanner::*d_ppBlank)();

    FBB::Stat d_stat;
    
    static std::unordered_map<std::string, std::pair<int, int>> s_token;
    static std::unordered_map<std::string, int>                 s_identifiers;

    public:
        enum Token
        {
            UNDEFINED_ = 256,
            EQUAL,
            UNEQUAL,
            SMALLER_EQUAL,
            GREATER_EQUAL,
            YOUNGER,
            OLDER,
            SHR,
            SHL,
            BNOT,
            GETCH,
            GETPID,
            GETS,
            ARG_HEAD,
            ARG_TAIL,
            ASCII,
            CMDTAIL,
            CMDHEAD,
            ECHO,
            EXISTS,
            GET_BASE,
            GETENV,
            GET_EXT,
            GET_PATH,
            PUTENV,
            SIZEOF,
            STRLEN,
            STRLWR,
            STRUPR,
            CHANGE_BASE,
            CHANGE_EXT,
            CHANGE_PATH,
            ELEMENT,
            FGETS,
            STRTOK,
            SUBSTR,
            CHDIR,
            STAT,
            SYSTEM,
            FPRINTF,
            EXEC,
            EXECUTE,
            MAKELIST,
            PRINTF,
            STRFIND,
        };

        Scanner(std::istream &in, bool preProcess);

        std::istream &pp();
        size_t ifdefStackSize() const;

        // $insert lexFunctionDecl
        int lex();

    private:
        int token() const;
        int parserToken();
        void blanks();
        void comment();
        void newline();
        int plain(int token);

        void beginFile();
        void changeFile();
        void changeImFile();

        void define(std::string const &value);
        void ifdef();
        void ifndef();
        void ppElse();
        std::string ppID();

        void endif();
        void undef();

        void replaceDefine();

        int identifier();
        int hexNumber();
        int number();
        int charToken();
        void dQuote();
        void str();
        void beginDefine();

        void ppOut();
        void ppBlank();
        void noPP();

        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

inline size_t Scanner::ifdefStackSize() const
{
    return d_ifdef.size();
}

inline std::istream &Scanner::pp()
{
    d_pp.seekg(0);
    return d_pp;
}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex__();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::print() 
{
    print__();
}

#endif // Scanner_H_INCLUDED_

