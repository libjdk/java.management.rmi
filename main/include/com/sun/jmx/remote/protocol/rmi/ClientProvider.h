#ifndef _com_sun_jmx_remote_protocol_rmi_ClientProvider_h_
#define _com_sun_jmx_remote_protocol_rmi_ClientProvider_h_
//$ class com.sun.jmx.remote.protocol.rmi.ClientProvider
//$ extends javax.management.remote.JMXConnectorProvider

#include <javax/management/remote/JMXConnectorProvider.h>

namespace java {
	namespace util {
		class Map;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			class JMXConnector;
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

class $import ClientProvider : public ::javax::management::remote::JMXConnectorProvider {
	$class(ClientProvider, $NO_CLASS_INIT, ::javax::management::remote::JMXConnectorProvider)
public:
	ClientProvider();
	void init$();
	virtual ::javax::management::remote::JMXConnector* newJMXConnector(::javax::management::remote::JMXServiceURL* serviceURL, ::java::util::Map* environment) override;
};

					} // rmi
				} // protocol
			} // remote
		} // jmx
	} // sun
} // com

#endif // _com_sun_jmx_remote_protocol_rmi_ClientProvider_h_