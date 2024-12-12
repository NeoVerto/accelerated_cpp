// 非法操作
int* invalid_return_pointer()
{
  int x;
  return &x;
}

// 合法操作, 但存在问题.
int* valid_return_pointer()
{
  static int x;
  return &x;
}

/**
 * 当变量所占有的空间被释放后, 任何指向它的指针都将变得无效.
 */