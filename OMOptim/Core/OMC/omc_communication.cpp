// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.

#include "omc_communication.h"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_1;



OmcCommunication_ptr OmcCommunication_Helper::_nil() {
  return ::OmcCommunication::_nil();
}

::CORBA::Boolean OmcCommunication_Helper::is_nil(::OmcCommunication_ptr p) {
  return ::CORBA::is_nil(p);

}

void OmcCommunication_Helper::release(::OmcCommunication_ptr p) {
  ::CORBA::release(p);
}

void OmcCommunication_Helper::marshalObjRef(::OmcCommunication_ptr obj, cdrStream& s) {
  ::OmcCommunication::_marshalObjRef(obj, s);
}

OmcCommunication_ptr OmcCommunication_Helper::unmarshalObjRef(cdrStream& s) {
  return ::OmcCommunication::_unmarshalObjRef(s);
}

void OmcCommunication_Helper::duplicate(::OmcCommunication_ptr obj) {
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
}

OmcCommunication_ptr
OmcCommunication::_duplicate(::OmcCommunication_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
  return obj;
}

OmcCommunication_ptr
OmcCommunication::_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


OmcCommunication_ptr
OmcCommunication::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

OmcCommunication_ptr
OmcCommunication::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_OmcCommunication _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_OmcCommunication* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
    if( !_the_nil_ptr ) {
      _the_nil_ptr = new _objref_OmcCommunication;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* OmcCommunication::_PD_repoId = "IDL:OmcCommunication:1.0";


_objref_OmcCommunication::~_objref_OmcCommunication() {
  
}


_objref_OmcCommunication::_objref_OmcCommunication(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::OmcCommunication::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
_objref_OmcCommunication::_ptrToObjRef(const char* id)
{
  if( id == ::OmcCommunication::_PD_repoId )
    return (::OmcCommunication_ptr) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (::CORBA::Object_ptr) this;

  if( omni::strMatch(id, ::OmcCommunication::_PD_repoId) )
    return (::OmcCommunication_ptr) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (::CORBA::Object_ptr) this;

  return 0;
}

// Proxy call descriptor class. Mangled signature:
//  _cstring_i_cstring
class _0RL_cd_54189747B6CAE889_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_54189747B6CAE889_00000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::String_var result;
};

void _0RL_cd_54189747B6CAE889_00000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_54189747B6CAE889_00000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

void _0RL_cd_54189747B6CAE889_00000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalString(result,0);

}

void _0RL_cd_54189747B6CAE889_00000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalString(0);

}

const char* const _0RL_cd_54189747B6CAE889_00000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_54189747B6CAE889_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_54189747B6CAE889_00000000* tcd = (_0RL_cd_54189747B6CAE889_00000000*)cd;
  _impl_OmcCommunication* impl = (_impl_OmcCommunication*) svnt->_ptrToInterface(OmcCommunication::_PD_repoId);
  tcd->result = impl->sendExpression(tcd->arg_0);


}

char* _objref_OmcCommunication::sendExpression(const char* expr)
{
  _0RL_cd_54189747B6CAE889_00000000 _call_desc(_0RL_lcfn_54189747B6CAE889_10000000, "sendExpression", 15);
  _call_desc.arg_0 = expr;

  _invoke(_call_desc);
  return _call_desc.result._retn();


}
// Local call call-back function.
static void
_0RL_lcfn_54189747B6CAE889_20000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_54189747B6CAE889_00000000* tcd = (_0RL_cd_54189747B6CAE889_00000000*)cd;
  _impl_OmcCommunication* impl = (_impl_OmcCommunication*) svnt->_ptrToInterface(OmcCommunication::_PD_repoId);
  tcd->result = impl->sendClass(tcd->arg_0);


}

char* _objref_OmcCommunication::sendClass(const char* model)
{
  _0RL_cd_54189747B6CAE889_00000000 _call_desc(_0RL_lcfn_54189747B6CAE889_20000000, "sendClass", 10);
  _call_desc.arg_0 = model;

  _invoke(_call_desc);
  return _call_desc.result._retn();


}
_pof_OmcCommunication::~_pof_OmcCommunication() {}


omniObjRef*
_pof_OmcCommunication::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::_objref_OmcCommunication(ior, id);
}


::CORBA::Boolean
_pof_OmcCommunication::is_a(const char* id) const
{
  if( omni::ptrStrMatch(id, ::OmcCommunication::_PD_repoId) )
    return 1;
  
  return 0;
}

const _pof_OmcCommunication _the_pof_OmcCommunication;

_impl_OmcCommunication::~_impl_OmcCommunication() {}


::CORBA::Boolean
_impl_OmcCommunication::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if( omni::strMatch(op, "sendExpression") ) {

    _0RL_cd_54189747B6CAE889_00000000 _call_desc(_0RL_lcfn_54189747B6CAE889_10000000, "sendExpression", 15, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "sendClass") ) {

    _0RL_cd_54189747B6CAE889_00000000 _call_desc(_0RL_lcfn_54189747B6CAE889_20000000, "sendClass", 10, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
_impl_OmcCommunication::_ptrToInterface(const char* id)
{
  if( id == ::OmcCommunication::_PD_repoId )
    return (::_impl_OmcCommunication*) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (void*) 1;

  if( omni::strMatch(id, ::OmcCommunication::_PD_repoId) )
    return (::_impl_OmcCommunication*) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (void*) 1;
  return 0;
}

const char*
_impl_OmcCommunication::_mostDerivedRepoId()
{
  return ::OmcCommunication::_PD_repoId;
}

POA_OmcCommunication::~POA_OmcCommunication() {}
