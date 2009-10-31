/*
  This file is part of libecpp-module_name.
  libecpp-module_name is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  libecpp-mofule_name is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __INC_ECPP_FACTURY_HH__
#define __INC_ECPP_FACTURY_HH__

namespace ecpp
{

  template <class BaseType>
  struct Factury0 {
    virtual BaseType * operator()() = 0;

    template <class Type>
    static Factury0 *create();
  };

  template <class BaseType, class A0>
  struct Factury1 {
    virtual BaseType * operator()(A0 a0) = 0;

    template <class Type>
    static Factury1 *create();
  };

  template <class BaseType, class A0, class A1>
  struct Factury2 {
    virtual BaseType * operator()(A0 a0, A1 a1) = 0;

    template <class Type>
    static Factury2 *create();
  };

  template <class BaseType, class A0, class A1, class A2>
  struct Factury3 {
    virtual BaseType * operator()(A0 a0, A1 a1, A2 a2) = 0;

    template <class Type>
    static Factury3 *create();
  };

  template <class BaseType, class A0, class A1, class A2, class A3>
  struct Factury4 {
    virtual BaseType * operator()(A0 a0, A1 a1, A2 a2, A3 a3) = 0;

    template <class Type>
    static Factury4 *create();
  };


  template <class BaseType, class A0, class A1, class A2, class A3, class A4>
  struct Factury5 {
    virtual BaseType * operator()(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) = 0;

    template <class Type>
    static Factury5 *create();
  };


  template <class BaseType, class Type>
  struct FacturyType0 : public Factury0<BaseType>
  { virtual Type * operator()() { return new Type(); } };

  template <class BaseType, class Type, class A0>
  struct FacturyType1 : public Factury1<BaseType,A0>
  { virtual Type * operator()(A0 a0) { return new Type(a0); } };

  template <class BaseType, class Type, class A0, class A1>
  struct FacturyType2 : public Factury2<BaseType,A0,A1>
  { virtual Type * operator()(A0 a0, A1 a1) { return new Type(a0,a1); } };

  template <class BaseType, class Type, class A0, class A1, class A2>
  struct FacturyType3 : public Factury3<BaseType,A0,A1,A2>
  { virtual Type * operator()(A0 a0, A1 a1, A2 a2) { return new Type(a0,a1,a2); } };

  template <class BaseType, class Type, class A0, class A1, class A2, class A3>
  struct FacturyType4 : public Factury4<BaseType,A0,A1,A2,A3>
  { virtual Type * operator()(A0 a0, A1 a1, A2 a2, A3 a3) { return new Type(a0,a1,a2,a3); } };

  template <class BaseType, class Type, class A0, class A1, class A2, class A3, class A4>
  struct FacturyType5 : public Factury5<BaseType,A0,A1,A2,A3,A4>
  { virtual Type * operator()(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) { return new Type(a0,a1,a2,a3,a4); } };


  template <class BaseType>
  template <class Type>
  inline Factury0<BaseType> *Factury0<BaseType>::create()
  {
    return new FacturyType0<BaseType,Type>();
  }

  template <class BaseType, class A0>
  template <class Type>
  inline Factury1<BaseType,A0> *Factury1<BaseType,A0>::create()
  {
    return new FacturyType1<BaseType,Type,A0>();
  }

  template <class BaseType, class A0, class A1>
  template <class Type>
  inline Factury2<BaseType,A0,A1> *Factury2<BaseType,A0,A1>::create()
  {
    return new FacturyType2<BaseType,Type,A0,A1>();
  }

  template <class BaseType, class A0, class A1, class A2>
  template <class Type>
  inline Factury3<BaseType,A0,A1,A2> *Factury3<BaseType,A0,A1,A2>::create()
  {
    return new FacturyType3<BaseType,Type,A0,A1,A2>();
  }

  template <class BaseType, class A0, class A1, class A2, class A3>
  template <class Type>
  inline Factury4<BaseType,A0,A1,A2,A3> *Factury4<BaseType,A0,A1,A2,A3>::create()
  {
    return new FacturyType4<BaseType,Type,A0,A1,A2,A3>();
  }

  template <class BaseType, class A0, class A1, class A2, class A3, class A4>
  template <class Type>
  inline Factury5<BaseType,A0,A1,A2,A3,A4> *Factury5<BaseType,A0,A1,A2,A3,A4>::create()
  {
    return new FacturyType5<BaseType,Type,A0,A1,A2,A3,A4>();
  }

};

#endif // __INC_ECPP_FACTURY_HH__
