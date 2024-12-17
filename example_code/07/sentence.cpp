#include "sentence.h"

#include <cstdlib>
/**
 * cstdlib 定义了 rand 函数
 */
#include <stdexcept>
#include <string>
#include <vector>
#include "grammar.h"

using std::rand;

using std::domain_error;
using std::logic_error;
using std::string;
using std::vector;

bool bracketed(const std::string& word)
{
  return (word.size() > 2 && word.front() == '<' && word.back() == '>');
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
/**
 * const map 无 [] 重载
 */
{
  if (!bracketed(word))
    ret.push_back(word);
  else
  {
    // 为对应于 word 的规则定位
    Grammar::const_iterator it = g.find(word);
    /**
     * map 类型容器的成员函数 find
     * - 语法: m.find(key)
     * - 根据传入的键值查找元素.
     * - 若找到一个元素, 就返回指向该元素的迭代器.
     * - 若无这样的元素存在, 则返回 m.end().
     */
    if (it == g.end())
      throw logic_error("empty rule");

    // 获取可能的规则集合
    const Rule_collection& c = it->second;

    // 从规则集合中随机选择一条规则
    const Rule& r = c[nrand(c.size())];

    // 递归展开所选定的规则
    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
  }
}

int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    throw domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;
  do
    r = rand() / bucket_size;
    /**
     * rand() 函数
     * - 产生一个在 [0, RAND_MAX] 范围内的随机整数
     */
  while (r >= n);

  return r;
}

vector<string> gen_sentence(const Grammar& g)
{
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);

  return ret;
}