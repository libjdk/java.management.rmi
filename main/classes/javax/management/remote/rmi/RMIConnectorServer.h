#ifndef _javax_management_remote_rmi_RMIConnectorServer_h_
#define _javax_management_remote_rmi_RMIConnectorServer_h_
//$ class javax.management.remote.rmi.RMIConnectorServer
//$ extends javax.management.remote.JMXConnectorServer

#include <java/lang/Array.h>
#include <javax/management/remote/JMXConnectorServer.h>

#pragma push_macro("CREATED")
#undef CREATED
#pragma push_macro("CREDENTIALS_FILTER_PATTERN")
#undef CREDENTIALS_FILTER_PATTERN
#pragma push_macro("JNDI_REBIND_ATTRIBUTE")
#undef JNDI_REBIND_ATTRIBUTE
#pragma push_macro("RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE")
#undef RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE
#pragma push_macro("RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE")
#undef RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE
#pragma push_macro("SERIAL_FILTER_PATTERN")
#undef SERIAL_FILTER_PATTERN
#pragma push_macro("STARTED")
#undef STARTED
#pragma push_macro("STOPPED")
#undef STOPPED

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace util {
					class ClassLogger;
				}
			}
		}
	}
}
namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class ClassLoader;
		class Throwable;
	}
}
namespace java {
	namespace util {
		class Hashtable;
		class Map;
		class Set;
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
			class JMXConnector;
			class JMXServiceURL;
			class MBeanServerForwarder;
		}
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIServer;
				class RMIServerImpl;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class $export RMIConnectorServer : public ::javax::management::remote::JMXConnectorServer {
	$class(RMIConnectorServer, 0, ::javax::management::remote::JMXConnectorServer)
public:
	RMIConnectorServer();
	void init$(::javax::management::remote::JMXServiceURL* url, ::java::util::Map* environment);
	void init$(::javax::management::remote::JMXServiceURL* url, ::java::util::Map* environment, ::javax::management::MBeanServer* mbeanServer);
	void init$(::javax::management::remote::JMXServiceURL* url, ::java::util::Map* environment, ::javax::management::remote::rmi::RMIServerImpl* rmiServerImpl, ::javax::management::MBeanServer* mbeanServer);
	virtual void bind($String* jndiUrl, ::java::util::Hashtable* attributes, ::javax::management::remote::rmi::RMIServer* rmiServer, bool rebind);
	static $String* byteArrayToBase64($bytes* a);
	virtual void connectionClosed($String* connectionId, $String* message, Object$* userData) override;
	virtual void connectionFailed($String* connectionId, $String* message, Object$* userData) override;
	virtual void connectionOpened($String* connectionId, $String* message, Object$* userData) override;
	static $String* encodeJRMPStub(::javax::management::remote::rmi::RMIServer* rmiServer, ::java::util::Map* env);
	static $String* encodeStub(::javax::management::remote::rmi::RMIServer* rmiServer, ::java::util::Map* env);
	void encodeStubInAddress(::javax::management::remote::rmi::RMIServer* rmiServer, ::java::util::Map* attributes);
	virtual ::javax::management::remote::JMXServiceURL* getAddress() override;
	virtual ::java::util::Map* getAttributes() override;
	virtual bool isActive() override;
	static ::java::io::IOException* newIOException($String* message, $Throwable* cause);
	static ::javax::management::remote::rmi::RMIServerImpl* newJRMPServer(::java::util::Map* env, int32_t port);
	virtual ::javax::management::remote::rmi::RMIServerImpl* newServer();
	static ::javax::management::remote::rmi::RMIServer* objectToBind(::javax::management::remote::rmi::RMIServerImpl* rmiServer, ::java::util::Map* env);
	virtual void setMBeanServerForwarder(::javax::management::remote::MBeanServerForwarder* mbsf) override;
	virtual void start() override;
	virtual void stop() override;
	virtual ::javax::management::remote::JMXConnector* toJMXConnector(::java::util::Map* env) override;
	static $String* JNDI_REBIND_ATTRIBUTE;
	static $String* RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE;
	static $String* RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE;
	static $String* CREDENTIALS_FILTER_PATTERN;
	static $String* SERIAL_FILTER_PATTERN;
	static $chars* intToAlpha;
	static ::com::sun::jmx::remote::util::ClassLogger* logger;
	::javax::management::remote::JMXServiceURL* address = nullptr;
	::javax::management::remote::rmi::RMIServerImpl* rmiServerImpl = nullptr;
	::java::util::Map* attributes = nullptr;
	::java::lang::ClassLoader* defaultClassLoader = nullptr;
	$String* boundJndiUrl = nullptr;
	static const int32_t CREATED = 0;
	static const int32_t STARTED = 1;
	static const int32_t STOPPED = 2;
	int32_t state = 0;
	static ::java::util::Set* openedServers;
};

			} // rmi
		} // remote
	} // management
} // javax

#pragma pop_macro("CREATED")
#pragma pop_macro("CREDENTIALS_FILTER_PATTERN")
#pragma pop_macro("JNDI_REBIND_ATTRIBUTE")
#pragma pop_macro("RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE")
#pragma pop_macro("RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE")
#pragma pop_macro("SERIAL_FILTER_PATTERN")
#pragma pop_macro("STARTED")
#pragma pop_macro("STOPPED")

#endif // _javax_management_remote_rmi_RMIConnectorServer_h_