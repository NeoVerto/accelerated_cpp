#ifndef GUARD_sentence_h
#define GUARD_sentence_h

#include <string>
#include <vector>
#include "grammar.h"
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
int nrand(int);
std::vector<std::string> gen_sentence(const Grammar&);

#endif  // GUARD_sentence_h