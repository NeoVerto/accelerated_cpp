#ifndef GUARD_pic_h
#define GUARD_pic_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Ptr.h"

class Pictrue;

class PicBase
{
  friend class StringPic;
  friend class FramePic;
  friend class VCatPic;
  friend class HCatPic;

  friend std::ostream& operator<<(std::ostream&, const Picture&);

private:
  typedef std::vector<std::string>::size_type height_size;
  typedef std::string::size_type width_size;

  virtual width_size width() const =0;
  virtual height_size height() const =0;
  virtual void display(std::ostream&, height_size, bool) const =0;
  /**
   * 纯虚函数
   * - 纯粹的接口, 无实现
   * - 包含纯虚函数的类, 称为抽象基类, 其没有相应的对象.
   * - 抽象基类无法被实例化
   */

protected:
  static void pad(std::ostream& os, width_size begin, width_size end)
  {
    while (begin != end)
    {
      os << " ";
      ++ begin;
    }
  }
  /**
   * 派生类成员所访问的是派生类对象的基类部分的保护成员, 而非基类对象的保护成员.
   */

public:
  virtual ~PicBase() {}
};

class StringPic : public PicBase
{
  friend class Picture;

private:
  std::vector<std::string> data;
  StringPic(const std::vector<std::string>& v): data(v) {}

  width_size width() const
  {
    width_size n = 0;
    for (height_size i = 0; i != data.size(); ++i)
      n = std::max(n, data[i].size());

    return n;
  }

  height_size height() const { return data.size(); }

  void display(std::ostream& os, height_size row, bool do_pad) const
  {
    width_size start = 0;
    if (row < height())
    {
      os << data[row];
      start = data[row].size();
    }

    if (do_pad)
      pad(os, start, width());
  }
};

class FramePic : public PicBase
{
  friend Picture frame(const Picture&);

private:
  Ptr<PicBase> p;
  FramePic(const Ptr<PicBase>& pic): p(pic) {}

  width_size width() const
  {
    return p->width() + 4;
  }

  height_size height() const
  {
    return p->height() + 4;
  }

  void display(std::ostream os, height_size row, bool do_pad) const
  {
    if (row >= height())
    {
      if (do_pad)
        pad(os, 0, width());
    }
    else
    {
      if (row == 0 || row == height() - 1)
        os << std::string(width(), '*');
      else if (row == 1 || row == height() - 2)
      {
        os << "*";
        pad(os, 1, width() - 1);
        os << "*";
      }
      else
      {
        os << "*";
        p->display(os, row - 2, true);
        os << "*";
      }
    }
  }
};

class HCatPic : public PicBase
{
  friend Picture hcat(const Picture&, const Picture&);

private:
  Ptr<PicBase> left, right;
  HCatPic(const Ptr<PicBase>& l, const Ptr<PicBase>& r): left(l), right(r) {}

  width_size width() const
  {
    return left->width() + right->width();
  }

  height_size height() const
  {
    return std::max(left->height(), right->height());
  }

  void display(std::ostream& os, height_size row, bool do_pad) const
  {
    left->display(os, row, do_pad || row < right->height());
    right->display(os, row, do_pad);
  }
};

class VCatPic : public PicBase
{
  friend Picture vcat(const Picture&, const Picture&);

private:
  Ptr<PicBase> top, bottom;
  VCatPic(const Ptr<PicBase>& t, const Ptr<PicBase>& b): top(t), bottom(b) {}

  width_size width() const
  {
    return std::max(top->width(), bottom->width());
  }

  height_size height() const
  {
    return top->height() + bottom->height();
  }

  void display(std::ostream& os, height_size row, bool do_pad) const
  {
    width_size w = 0;
    if (row < top->height())
    {
      top->display(os, row, do_pad);
      w = top->width();
    }
    else if (row < height())
    {
      bottom->display(os, row - top->height(), do_pad);
      w = bottom->width();
    }

    if (do_pad)
      pad(os, w, width());
  }
};

class Picture
{
  friend Picture frame(const Picture&);
  friend Picture hcat(const Picture&, const Picture&);
  friend Picture vcat(const Picture&, const Picture&);
  friend std::ostream& operator<<(std::ostream&, const Picture&);

public:
  Picture(const std::vector<std::string>& v = std::vector<std::string>())
    : p(new StringPic(v)) {}

private:
  Ptr<PicBase> p;
  Picture(PicBase* ptr): p(ptr) {}
};

Picture frame(const Picture& pic)
{
  return new FramePic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
  return new HCatPic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
  return new VCatPic(t.p, b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
  const PicBase::height_size height = picture.p->height();
  for (PicBase::height_size i = 0; i != height; ++i)
  {
    picture.p->display(os, i, false);
    os << std::endl;
  }
  return os;
}

#endif  // GUARD_pic_h