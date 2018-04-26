#include"Re.h"

#include"predefine.h"
#include"ReSymbolProcess.h"
#include"ReOperatorProcess.h"
#include"ReToSuffixFormRe.h"
#include"SuffixFormReToNfa.h"
#include"NfaToDfa.h"
#include"DfaToDriveTable.h"

#include<vector>

Re::Re(std::string original_re)
{
    ReSymbolProcess rsp;
    std::vector<SYMBOL> processed_re_1 = rsp.DoIt(original_re);
    ReOperatorProcess rop;
    std::vector<SYMBOL> processed_re_2 = rop.DoIt(processed_re_1);
    ReToSuffixFormRe rtsf;
    SuffixFormRe suffix_form_re = rtsf.DoIt(processed_re_2);
    NFA nfa(suffix_form_re);
    DFA dfa(nfa);
    dt = new DriveTable(dfa);
}

Re::~Re()
{
    delete dt;
}

int Re::Match(std::string input)
{
    return dt->Match(input);
}
