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

#ifndef __INC_ECPP_FACTORY_HH__
#define __INC_ECPP_FACTORY_HH__

namespace ecpp
{

  template <class BaseType>
  struct Factory0 {
    virtual BaseType * operator()() = 0;

    template <class Type>
    static Factory0 *create();
  };

  template <class BaseType, class A0>
  struct Factory1 {
    virtual BaseType * operator()(A0 a0) = 0;

    template <class Type>
    static Factory1 *create();
  };

  template <class BaseType, class A0, class A1>
  struct Factory2 {
    virtual BaseType * operator()(A0 a0, A1 a1) = 0;

    template <class Type>
    static Factory2 *create();
  };

  template <class BaseType, class A0, class A1, class A2>
  struct Factory3 {
    virtual BaseType * operator()(A0 a0, A1 a1, A2 a2) = 0;

    template <class Type>
    static Factory3 *create();
  };

  template <class BaseType, class A0, class A1, class A2, class A3>
  struct Factory4 {
    virtual BaseType * operator()(A0 a0, A1 a1, A2 a2, A3 a3) = 0;

    template <class Type>
    static Factory4 *create();
  };


  template <class BaseType, class A0, class A1, class A2, class A3, class A4>
  struct Factory5 {
    virtual BaseType * operator()(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) = 0;

    template <class Type>
    static Factory5 *create();
  };


  template <class BaseType, class Type>
  struct FactoryType0 : public Factory0<BaseType>
  { virtual Type * operator()() { return new Type(); } };

  template <class BaseType, class Type, class A0>
  struct FactoryType1 : public Factory1<BaseType,A0>
  { virtual Type * operator()(A0 a0) { return new Type(a0); } };

  template <class BaseType, class Type, class A0, class A1>
  struct FactoryType2 : public Factory2<BaseType,A0,A1>
  { virtual Type * operator()(A0 a0, A1 a1) { return new Type(a0,a1); } };

  template <class BaseType, class Type, class A0, class A1, class A2>
  struct FactoryType3 : public Factory3<BaseType,A0,A1,A2>
  { virtual Type * operator()(A0 a0, A1 a1, A2 a2) { return new Type(a0,a1,a2); } };

  template <class BaseType, class Type, class A0, class A1, class A2, class A3>
  struct FactoryType4 : public Factory4<BaseType,A0,A1,A2,A3>
  { virtual Type * operator()(A0 a0, A1 a1, A2 a2, A3 a3) { return new Type(a0,a1,a2,a3); } };

  template <class BaseType, class Type, class A0, class A1, class A2, class A3, class A4>
  struct FactoryType5 : public Factory5<BaseType,A0,A1,A2,A3,A4>
  { virtual Type * operator()(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) { return new Type(a0,a1,a2,a3,a4); } };


  template <class BaseType>
  template <class Type>
  inline Factory0<BaseType> *Factory0<BaseType>::create()
  {
    return new FactoryType0<BaseType,Type>();
  }

  template <class BaseType, class A0>
  template <class Type>
  inline Factory1<BaseType,A0> *Factory1<BaseType,A0>::create()
  {
    return new FactoryType1<BaseType,Type,A0>();
  }

  template <class BaseType, class A0, class A1>
  template <class Type>
  inline Factory2<BaseType,A0,A1> *Factory2<BaseType,A0,A1>::create()
  {
    return new FactoryType2<BaseType,Type,A0,A1>();
  }

  template <class BaseType, class A0, class A1, class A2>
  template <class Type>
  inline Factory3<BaseType,A0,A1,A2> *Factory3<BaseType,A0,A1,A2>::create()
  {
    return new FactoryType3<BaseType,Type,A0,A1,A2>();
  }

  template <class BaseType, class A0, class A1, class A2, class A3>
  template <class Type>
  inline Factory4<BaseType,A0,A1,A2,A3> *Factory4<BaseType,A0,A1,A2,A3>::create()
  {
    return new FactoryType4<BaseType,Type,A0,A1,A2,A3>();
  }

  template <class BaseType, class A0, class A1, class A2, class A3, class A4>
  template <class Type>
  inline Factory5<BaseType,A0,A1,A2,A3,A4> *Factory5<BaseType,A0,A1,A2,A3,A4>::create()
  {
    return new FactoryType5<BaseType,Type,A0,A1,A2,A3,A4>();
  }

};

#endif // __INC_ECPP_FACTORY_HH__
