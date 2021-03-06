// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6a ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:645

#ifndef _TAO_IDL_MESSAGES_T_H_
#define _TAO_IDL_MESSAGES_T_H_



// TAO_IDL - Generated from
// be/be_visitor_interface/tie_sh.cpp:87

// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class  POA_MessageReceiver_tie : public POA_MessageReceiver
{
public:
  /// the T& ctor
  POA_MessageReceiver_tie (T &t);
  /// ctor taking a POA
  POA_MessageReceiver_tie (T &t, PortableServer::POA_ptr poa);
  /// ctor taking pointer and an ownership flag
  POA_MessageReceiver_tie (T *tp, ::CORBA::Boolean release = true);
  /// ctor with T*, ownership flag and a POA
  POA_MessageReceiver_tie (
      T *tp,
      PortableServer::POA_ptr poa,
      ::CORBA::Boolean release = true
    );
  /// dtor
  
  ~POA_MessageReceiver_tie (void);
  // TIE specific functions
  /// return the underlying object
  T *_tied_object (void);
  /// set the underlying object
  void _tied_object (T &obj);
  /// set the underlying object and the ownership flag
  void _tied_object (T *obj, ::CORBA::Boolean release = true);
  /// do we own it
  ::CORBA::Boolean _is_owner (void);
  /// set the ownership
  
  void _is_owner ( ::CORBA::Boolean b);
  // overridden ServantBase operations
  PortableServer::POA_ptr _default_POA (void);
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/tie_sh.cpp:60
  
  void sendMessage (
      const ::Message &);

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  ::CORBA::Boolean rel_;
  
  // copy and assignment are not allowed
  POA_MessageReceiver_tie (const POA_MessageReceiver_tie &);
  void operator= (const POA_MessageReceiver_tie &);
};

// TAO_IDL - Generated from 
// be/be_codegen.cpp:1391


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "MessageS_T.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("MessageS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#endif /* ifndef */

