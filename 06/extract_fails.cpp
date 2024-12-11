#include "extract_fails.h"

#include <algorithm>
/**
 * algorithm 定义了 remove_copy_if
 * algorithm 定义了 remove_if
 */
#include <iterator>
#include <vector>
#include "../04/Student_info.h"
#include "../05/fgrade.h"

using std::back_inserter;
using std::remove_copy_if;
using std::stable_partition;
using std::vector;

bool pgrade(const Student_info& s)
{
  return !fgrade(s);
}

vector<Student_info> extract_fails_DualPassing(vector<Student_info>& students)
{
  vector<Student_info> fail;
  remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
  /**
   * remove_copy_if 函数
   * - 语法: remove_copy_if(b, e, d, f)
   * - 将 [b, e) 中不满足 f 的元素复制到 d 处.
   */
  students.erase(remove_if(students.begin(), students.end(), fgrade),
                 /**
                  * remove_if 函数
                  * - 语法: remove_if(b, e, f)
                  * - "删除" [b, e) 中满足 f 的元素.
                  * - 将不满足谓词条件的元素复制到容器的前面, 并返回一个指向新逻
                  * 辑末尾的迭代器.
                  */
                 
                 /**
                  * remove()
                  * - 语法: remove(b, e, t);
                  * - "删除" [b, e) 中等于 t 的元素.
                  */
                 students.end());
  /**
   * vector 类型对象的 erase 函数
   * - 语法: v.erase(b, e)
   * - 移除 [b, e) 的全部元素.
   */
}

vector<Student_info> extract_fails_MonoPassing(vector<Student_info>& students)
{
  vector<Student_info>::iterator iter =
    stable_partition(students.begin(), students.end(), pgrade);
    /**
     * stable_partition 函数
     * - 语法: stable_partition(b, e, f);
     * - 将 [b, e) 中的元素调整顺序, 使得满足 f 的元素排在不满足 f 的元素前.
     * - 返回一个迭代器, 指向第一个不满足 f 的元素处.
     */

    /**
     * partition 函数
     * - 语法: partition(b, e, f);
     * - 同 stable_partition, 但排序无稳定性.
    */
  vector<Student_info> fail(iter, students.end());
  students.erase(iter, students.end());

  return fail;
}
/**
 * 算法, 容器与迭代器
 * - 算法作用于容器的元素, 而非容器本身
 * - 成员函数直接作用于容器上, 给出或改变容器的状态.
 * - 修改操作 (无论是算法还是成员函数) 都可能使得迭代器失效.
 */