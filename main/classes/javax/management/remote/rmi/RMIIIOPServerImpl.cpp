#include <javax/management/remote/rmi/RMIIIOPServerImpl.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/rmi/Remote.h>
#include <java/util/Map.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIServerImpl.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Remote = ::java::rmi::Remote;
using $Map = ::java::util::Map;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIServerImpl = ::javax::management::remote::rmi::RMIServerImpl;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$CompoundAttribute _RMIIIOPServerImpl_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$MethodInfo _RMIIIOPServerImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(RMIIIOPServerImpl::*)($Map*)>(&RMIIIOPServerImpl::init$)), "java.io.IOException"},
	{"closeClient", "(Ljavax/management/remote/rmi/RMIConnection;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"closeServer", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"doNewClient", "(Ljava/lang/Object;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, 0, nullptr, "java.io.IOException"},
	{"export", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"getProtocol", "()Ljava/lang/String;", nullptr, $PROTECTED},
	{"makeClient", "(Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"toStub", "()Ljava/rmi/Remote;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _RMIIIOPServerImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.management.remote.rmi.RMIIIOPServerImpl",
	"javax.management.remote.rmi.RMIServerImpl",
	nullptr,
	nullptr,
	_RMIIIOPServerImpl_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RMIIIOPServerImpl_Annotations_
};

$Object* allocate$RMIIIOPServerImpl($Class* clazz) {
	return $of($alloc(RMIIIOPServerImpl));
}

void RMIIIOPServerImpl::init$($Map* env) {
	$RMIServerImpl::init$(env);
	$throwNew($UnsupportedOperationException);
}

void RMIIIOPServerImpl::export$() {
	$throwNew($UnsupportedOperationException, "Method not supported. JMX RMI-IIOP is deprecated"_s);
}

$String* RMIIIOPServerImpl::getProtocol() {
	return "iiop"_s;
}

$Remote* RMIIIOPServerImpl::toStub() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$RMIConnection* RMIIIOPServerImpl::makeClient($String* connectionId, $Subject* subject) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void RMIIIOPServerImpl::closeClient($RMIConnection* client) {
	$throwNew($UnsupportedOperationException);
}

void RMIIIOPServerImpl::closeServer() {
	$throwNew($UnsupportedOperationException);
}

$RMIConnection* RMIIIOPServerImpl::doNewClient(Object$* credentials) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

RMIIIOPServerImpl::RMIIIOPServerImpl() {
}

$Class* RMIIIOPServerImpl::load$($String* name, bool initialize) {
	$loadClass(RMIIIOPServerImpl, name, initialize, &_RMIIIOPServerImpl_ClassInfo_, allocate$RMIIIOPServerImpl);
	return class$;
}

$Class* RMIIIOPServerImpl::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax