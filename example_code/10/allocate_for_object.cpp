int *pointer_to_dynamic()
{
  return new int(0);  // 为一个 int 类型的对象动态分配内存.
}

int main()
{
  int *p = new int;
  int *p_42 = new int(42);
  /**
   * new 关键字
   * - 语法: 类型 *指针名 = new 类型
   * - 为一个 T 类型的对象分配内存, 该对象由构造函数对其初始化, 并产生一个指向该
   *   对象的指针.
   * 
   * - 语法: 类型 *指针名 = new 类型(值)
   * - 将用给定值初始化该对象.
   * 
   * - 两者的区别在于, 前者为默认初始化, 后者为值初始化
   */

  delete p;
  /**
   * delete 关键字
   * - 语法: delete 指针名
   * - 将指针所指对象的内存空间释放出来, 该指针随即无效.
   */
}