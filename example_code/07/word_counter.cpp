#include <iostream>
#include <map>
/**
 * map 定义了 map (映射表) 类型
 */
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::map;

int main()
{
  string s;
  map<string, int> counters;  // 存储每个单词和一个关联的计数器.
  /**
   * map 类型容器
   * - 定义语法: map<T-key, T-value> 容器名;
   * - 利用键访问值: 容器名[键];
   * - 若用未曾出现过的键当作 map 容器的索引, 则创建具有该键的新元素, 并对其初始
   * 化. 核心语言类型被默认初始化为 0.
   */

  // 读输入, 跟踪每个单词出现的次数
  while (cin >> s)
    ++counters[s];

  // 输出单词及相关数目
  for (map<string, int>::const_iterator it = counters.begin();
       it != counters.end();
       ++it)
      cout << it->first << "\t" << it->second << endl;
      /**
       * pair 类型
       * - 语法: pair<T-key, T-value> 容器名;
       * - 保存了两个元素, first 和 second.
       * - 对 map 容器而言, 其每个元素都是一个 pair, first 表示键, second 表示
       * 值.
       * - 若间接引用一个 map<T-key, T-value> 的 const_iterator, 就得到一个
       * pair<const T-key, T-value> 类型的对象.
       */

  return 0;
}