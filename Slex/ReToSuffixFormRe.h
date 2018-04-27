#pragma once

#include"predefine.h"

#include<stack>
#include<vector>

//============================== PHASE 3 ==============================

typedef std::pair<std::stack<OPERATOR>, std::stack<TERMINAL> > SuffixFormRe;

class ReToSuffixFormRe {
public:
    // You need to implement this method.
	int getPriority(int op, int flag);
	bool isOperator(int ch);
	std::vector<SYMBOL> toSuffix(std::vector<SYMBOL> processedRe);
    std::vector<SYMBOL> DoIt(std::vector<SYMBOL> processedRe);
	
private:

};