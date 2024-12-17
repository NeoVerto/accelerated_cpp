#include "extract_fails.h"

#include <list>
/**
 * list 定义了 list 类型
 */
#include <vector>
#include "../04/Student_info.h"
#include "fgrade.h"

using std::list;
using std::vector;

// 一个相当慢的实现
/**
 * 顺序存取与随机存取
 */
vector<Student_info>
extract_fails_VectorByIndex(vector<Student_info>& students)
{
  vector<Student_info> fail;
  
  // 不变式: students 的索引在 [0, i) 中的元素所代表的成绩是及格的
  vector<Student_info>::size_type i = 0;
  /**
   * 容器
   * - 容器类型<T>::size_type: 用于保存容器可能存在的最大实例的长度
   * - 容器类型<T> c(c2): 用 c2 定义 c, c 是 c2 的副本; 若 c2 留空, 则 c 为空.
   * - 容器类型<T> c(n): 定义一个 n 个元素的容器 c. 若 T 是类类型, 则由类型控制
   * 元素的初始化方式; 若 T 为内部算术类型, 元素将被初始化为 0.
   * - 容器类型<T> c(n, t): 定义一个有 n 个元素的容器 c, c 的元素是 t 的副本.
   * - 容器类型<T> c(b, e): 创建一个容器, 保存位于区间 [b, e) 中的迭代器所指示元
   * 素的一个副本
   */

  /**
   * 容器操作
   * - c = c2: 用容器 c2 的一个副本来替换容器 c 的内容.
   * - c.size(): 返回 c 的元素个数, 类型为 size_type.
   * - c.empty(): 判断 c 中是否没有元素.
   * - c.insert(d, b, e): 复制由位于区间 [b, e) 中迭代器所指示的元素, 并将其插入
   * 到 c 中位于 d 之前的位置中.
   * - c.erase(it): 从容器 c 中删除由 it 指示的元素.
   * - c.erase(b, e): 从容器 c 中删除由 [b, e) 指示的元素.
   * - c.push_back(t): 在 c 的末尾添加一个元素, 其值为 t.
   */
  while (i != students.size())
  {
    if (fgrade(students[i]))
    {
      fail.push_back(students[i]);
      students.erase(students.begin() + i);
      /**
       * vector 类型的成员函数 erase()
       * - 语法: v.erase(迭代器);
       * - 从向量中删除一个元素.
       */

      /**
       * vector 类型的成员函数 reserve()
       * - 语法: v.reverse(n);
       * - 保留空间以保存 n 个元素.
       * - 不对元素初始化.
       * - 不改变容器大小, 仅影响向量为响应 insert 或 push_back 的重复调用而分配
       * 内存的频率.
       */

      /**
       * vector 类型的成员函数 resize()
       * - 语法: v.resize(n);
       * - 给 v 新长度, 长度等于 n.
       *   - n < v, 删除位置 n 之后的元素.
       *   - n > v, 添加新元素, 并按照 v 的元素类型初始化.
       */
      
      /**
       * 迭代器
       * - c.begin()  指向容器第一个元素
       * - c.end()    指向容器最后一个元素之后的那个位置
       * - c.rbegin() 指向容器最后一个元素
       * - c.rend()   指向容器第一个元素之前的那个位置
       * - c.rbegin(), c.rend() 只在允许以逆序访问其元素的容器中存在.
       * - 识别一个容器以及容器中的一个元素.
       * - 允许我们检查存储在这个元素中的值.
       * - 提供操作以移动在容器中的元素.
       * - 采用对应于容器所能够有效处理的方式对可用的操作进行约束.
       */

      /**
       * 迭代器类型
       * - 容器类型::const_iterator: 仅可读容器中的值.
       * - 容器类型::iterataor: 可修改容器中的值.
       * - 可将 iterator 转换为 const_iterator, 但不可逆.
       */

      /**
       * 迭代器操作
       * - b == e, b != e 可比较两个迭代器是否相等 (忽略 const).
       * - ++it, it++ 增量运算符 ++ 将迭代器推进到容器的下一个元素.
       * - (*iter).attr <=> iter->attr 间接引用运算符 * 可访问迭代器指向的元素.
       * - 对支持随机访问的容器, 可通过 iter+i, iter-i 得到指向迭代器指向元素后
       * (前) i 个元素的迭代器.
       *   - 对不支持随机访问的容器, 这样的写法是不合法的.
       */
    }
    else
      ++i;
  }

  return fail;
}

vector<Student_info>
extract_fails_VectorByIterator(vector<Student_info>& students)
{
  vector<Student_info> fail;

  vector<Student_info>::iterator iter = students.begin();
  while (iter != students.end())
  {
    if (fgrade(*iter))
    {
      fail.push_back(*iter);
      iter = students.erase(iter);
      /**
       * - 删除 iter 所指示元素的动作会使被删除位置之后的所有迭代器失效.
       * - erase 返回的迭代器指向紧集跟在刚删除的元素后的元素.
       */
    }
    else
      ++iter;
  }

  return fail;
}

list<Student_info>
/**
 * list<T> 类型
 * - 若要从容器中删除许多元素, 对大规模的输入, list 的速度快于 vector
 */
extract_fails_List(list<Student_info>& students)
{
  list<Student_info> fail;

  list<Student_info>::iterator iter = students.begin();
  while (iter != students.end())
  {
    if (fgrade(*iter))
    {
      fail.push_back(*iter);
      iter = students.erase(iter);
      /**
       * 与 vector 的差别
       * - list 的 push_back 与 erase 不会使其他元素的迭代器失效, 只有指向已被删
       * 除的元素的迭代器才会失效.
       * - 不能使用标准库的 sort 函数为存储在 list 中的值排序. 对此, list 类提供
       * 了自己的 sort 成员函数. 该函数同样可接收谓词作为排序依据.
       */
    }
    else
      ++iter;
  }

  return fail;
}