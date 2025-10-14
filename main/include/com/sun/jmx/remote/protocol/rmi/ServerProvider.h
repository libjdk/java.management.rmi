#ifndef _com_sun_jmx_remote_protocol_rmi_ServerProvider_h_
#define _com_sun_jmx_remote_protocol_rmi_ServerProvider_h_
//$ class com.sun.jmx.remote.protocol.rmi.ServerProvider
//$ extends javax.management.remote.JMXConnectorServerProvider

#include <javax/management/remote/JMXConnectorServerProvider.h>

namespace java {
	namespace util {
		class Map;
	}
}
namespace javax {
	namespace management {
		class MBeanServer;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			class JMXConnectorServer;
			class JMXServiceURL;
		}
	}
}

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace protocol {
					namespace rmi {

class $import ServerProvider : public ::javax::management::remote::JMXConnectorServerProvider {
	$class(ServerProvider, $NO_CLASS_INIT, ::javax::management::remote::JMXConnectorServerProvider)
public:
	ServerProvider();
	void init$();
	virtual ::javax::management::remote::JMXConnectorServer* newJMXConnectorServer(::javax::management::remote::JMXServiceURL* serviceURL, ::java::util::Map* environment, ::javax::management::MBeanServer* mbeanServer) override;
};

					} // rmi
				} // protocol
			} // remote
		} // jmx
	} // sun
} // com

#endif // _com_sun_jmx_remote_protocol_rmi_ServerProvider_h_