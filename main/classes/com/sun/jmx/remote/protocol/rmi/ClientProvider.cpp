#include <com/sun/jmx/remote/protocol/rmi/ClientProvider.h>

#include <java/net/MalformedURLException.h>
#include <java/util/Map.h>
#include <javax/management/remote/JMXConnector.h>
#include <javax/management/remote/JMXServiceURL.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MalformedURLException = ::java::net::MalformedURLException;
using $Map = ::java::util::Map;
using $JMXConnector = ::javax::management::remote::JMXConnector;
using $JMXConnectorProvider = ::javax::management::remote::JMXConnectorProvider;
using $JMXServiceURL = ::javax::management::remote::JMXServiceURL;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace protocol {
					namespace rmi {

$MethodInfo _ClientProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ClientProvider::*)()>(&ClientProvider::init$))},
	{"newJMXConnector", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map;)Ljavax/management/remote/JMXConnector;", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map<Ljava/lang/String;*>;)Ljavax/management/remote/JMXConnector;", $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _ClientProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.jmx.remote.protocol.rmi.ClientProvider",
	"java.lang.Object",
	"javax.management.remote.JMXConnectorProvider",
	nullptr,
	_ClientProvider_MethodInfo_
};

$Object* allocate$ClientProvider($Class* clazz) {
	return $of($alloc(ClientProvider));
}

void ClientProvider::init$() {
}

$JMXConnector* ClientProvider::newJMXConnector($JMXServiceURL* serviceURL, $Map* environment) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($($nc(serviceURL)->getProtocol()))->equals("rmi"_s)) {
		$throwNew($MalformedURLException, $$str({"Protocol not rmi: "_s, $(serviceURL->getProtocol())}));
	}
	return $new($RMIConnector, serviceURL, environment);
}

ClientProvider::ClientProvider() {
}

$Class* ClientProvider::load$($String* name, bool initialize) {
	$loadClass(ClientProvider, name, initialize, &_ClientProvider_ClassInfo_, allocate$ClientProvider);
	return class$;
}

$Class* ClientProvider::class$ = nullptr;

					} // rmi
				} // protocol
			} // remote
		} // jmx
	} // sun
} // com