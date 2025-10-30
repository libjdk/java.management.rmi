#include <com/sun/jmx/remote/internal/rmi/ProxyRef.h>

#include <java/io/Externalizable.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <jcpp.h>

using $OperationArray = $Array<::java::rmi::server::Operation>;
using $Externalizable = ::java::io::Externalizable;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Method = ::java::lang::reflect::Method;
using $Remote = ::java::rmi::Remote;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					namespace rmi {

$CompoundAttribute _ProxyRef_MethodAnnotations_done1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _ProxyRef_MethodAnnotations_invoke3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _ProxyRef_MethodAnnotations_newCall5[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ProxyRef_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProxyRef, serialVersionUID)},
	{"ref", "Ljava/rmi/server/RemoteRef;", nullptr, $PROTECTED, $field(ProxyRef, ref)},
	{}
};

$MethodInfo _ProxyRef_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PUBLIC, $method(static_cast<void(ProxyRef::*)($RemoteRef*)>(&ProxyRef::init$))},
	{"done", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.rmi.RemoteException", nullptr, _ProxyRef_MethodAnnotations_done1},
	{"getRefClass", "(Ljava/io/ObjectOutput;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"invoke", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.lang.Exception", nullptr, _ProxyRef_MethodAnnotations_invoke3},
	{"invoke", "(Ljava/rmi/Remote;Ljava/lang/reflect/Method;[Ljava/lang/Object;J)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"newCall", "(Ljava/rmi/server/RemoteObject;[Ljava/rmi/server/Operation;IJ)Ljava/rmi/server/RemoteCall;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.rmi.RemoteException", nullptr, _ProxyRef_MethodAnnotations_newCall5},
	{"readExternal", "(Ljava/io/ObjectInput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remoteEquals", "(Ljava/rmi/server/RemoteRef;)Z", nullptr, $PUBLIC},
	{"remoteHashCode", "()I", nullptr, $PUBLIC},
	{"remoteToString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeExternal", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _ProxyRef_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.jmx.remote.internal.rmi.ProxyRef",
	"java.lang.Object",
	"java.rmi.server.RemoteRef",
	_ProxyRef_FieldInfo_,
	_ProxyRef_MethodInfo_
};

$Object* allocate$ProxyRef($Class* clazz) {
	return $of($alloc(ProxyRef));
}

void ProxyRef::init$($RemoteRef* ref) {
	$set(this, ref, ref);
}

void ProxyRef::readExternal($ObjectInput* in) {
	$nc(this->ref)->readExternal(in);
}

void ProxyRef::writeExternal($ObjectOutput* out) {
	$nc(this->ref)->writeExternal(out);
}

void ProxyRef::invoke($RemoteCall* call) {
	$nc(this->ref)->invoke(call);
}

$Object* ProxyRef::invoke($Remote* obj, $Method* method, $ObjectArray* params, int64_t opnum) {
	return $of($nc(this->ref)->invoke(obj, method, params, opnum));
}

void ProxyRef::done($RemoteCall* call) {
	$nc(this->ref)->done(call);
}

$String* ProxyRef::getRefClass($ObjectOutput* out) {
	return $nc(this->ref)->getRefClass(out);
}

$RemoteCall* ProxyRef::newCall($RemoteObject* obj, $OperationArray* op, int32_t opnum, int64_t hash) {
	return $nc(this->ref)->newCall(obj, op, opnum, hash);
}

bool ProxyRef::remoteEquals($RemoteRef* obj) {
	return $nc(this->ref)->remoteEquals(obj);
}

int32_t ProxyRef::remoteHashCode() {
	return $nc(this->ref)->remoteHashCode();
}

$String* ProxyRef::remoteToString() {
	return $nc(this->ref)->remoteToString();
}

ProxyRef::ProxyRef() {
}

$Class* ProxyRef::load$($String* name, bool initialize) {
	$loadClass(ProxyRef, name, initialize, &_ProxyRef_ClassInfo_, allocate$ProxyRef);
	return class$;
}

$Class* ProxyRef::class$ = nullptr;

					} // rmi
				} // internal
			} // remote
		} // jmx
	} // sun
} // com