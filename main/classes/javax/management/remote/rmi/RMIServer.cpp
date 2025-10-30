#include <javax/management/remote/rmi/RMIServer.h>

#include <javax/management/remote/rmi/RMIConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$MethodInfo _RMIServer_MethodInfo_[] = {
	{"getVersion", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{"newClient", "(Ljava/lang/Object;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _RMIServer_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.management.remote.rmi.RMIServer",
	nullptr,
	"java.rmi.Remote",
	nullptr,
	_RMIServer_MethodInfo_
};

$Object* allocate$RMIServer($Class* clazz) {
	return $of($alloc(RMIServer));
}

$Class* RMIServer::load$($String* name, bool initialize) {
	$loadClass(RMIServer, name, initialize, &_RMIServer_ClassInfo_, allocate$RMIServer);
	return class$;
}

$Class* RMIServer::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax