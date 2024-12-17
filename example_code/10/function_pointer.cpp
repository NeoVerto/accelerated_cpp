int next(int n)
{
  return n + 1;
}

template <class In, class Pred>
In find_if(In begin, In end, Pred f)
/**
 * 指向函数的指针经常被用作另一函数的参数, 如 Pred f.
 */
{
  while (begin != end && !f(*begin))
    ++begin;
  return begin;
}

int main()
{
  int (*fp)(int);
  /**
   * 函数指针 fp
   * - 语法: 返回类型 (*函数指针名)(参数列表)
   * - 调用它时以一个 int 类型的变量作为参数, 返回结果为 int 类型.
   */

  // 两个语句等价
  fp = &next;
  fp = next;
  /**
   * 程序对函数的操作
   * - 调用函数
   * - 获得函数地址
   */

  int i = 0;
  // 两个语句等价
  i = (*fp)(i);
  i = fp(i);
  /**
   * 通过函数指针调用函数
   * - 语法: (*函数指针名)(参数列表); 函数指针名(参数列表);
   */
  return 0;

  {
    // 返回函数指针的函数声明方法
    typedef double (*analysis_fp)(int); // typedef double (*)(int) analysis_fp;
    analysis_fp get_analysis_ptr();

    // 等价的另一种声明
    double (*get_analysis_ptr())(int);
  }
}