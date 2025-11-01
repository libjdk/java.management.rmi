#ifndef _javax_management_remote_rmi_RMIServerImpl_h_
#define _javax_management_remote_rmi_RMIServerImpl_h_
//$ class javax.management.remote.rmi.RMIServerImpl
//$ extends java.io.Closeable
//$ implements javax.management.remote.rmi.RMIServer

#include <java/io/Closeable.h>
#include <javax/management/remote/rmi/RMIServer.h>

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					class NotificationBuffer;
				}
			}
		}
	}
}
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
	namespace lang {
		class ClassLoader;
	}
}
namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace util {
		class List;
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
			namespace rmi {
				class RMIConnection;
				class RMIConnectorServer;
			}
		}
	}
}
namespace javax {
	namespace security {
		namespace auth {
			class Subject;
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class $import RMIServerImpl : public ::java::io::Closeable, public ::javax::management::remote::rmi::RMIServer {
	$class(RMIServerImpl, 0, ::java::io::Closeable, ::javax::management::remote::rmi::RMIServer)
public:
	RMIServerImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::util::Map* env);
	virtual void clientClosed(::javax::management::remote::rmi::RMIConnection* client);
	virtual void close() override;
	virtual void closeClient(::javax::management::remote::rmi::RMIConnection* client) {}
	virtual void closeServer() {}
	virtual ::javax::management::remote::rmi::RMIConnection* doNewClient(Object$* credentials);
	void dropDeadReferences();
	virtual void export$() {}
	virtual ::java::lang::ClassLoader* getDefaultClassLoader();
	virtual ::javax::management::MBeanServer* getMBeanServer();
	virtual ::com::sun::jmx::remote::internal::NotificationBuffer* getNotifBuffer();
	virtual $String* getProtocol() {return nullptr;}
	virtual $String* getVersion() override;
	virtual ::javax::management::remote::rmi::RMIConnection* makeClient($String* connectionId, ::javax::security::auth::Subject* subject) {return nullptr;}
	static $String* makeConnectionId($String* protocol, ::javax::security::auth::Subject* subject);
	virtual ::javax::management::remote::rmi::RMIConnection* newClient(Object$* credentials) override;
	virtual void setDefaultClassLoader(::java::lang::ClassLoader* cl);
	virtual void setMBeanServer(::javax::management::MBeanServer* mbs);
	virtual void setRMIConnectorServer(::javax::management::remote::rmi::RMIConnectorServer* connServer);
	virtual $String* toString() override;
	virtual ::java::rmi::Remote* toStub() {return nullptr;}
	static ::com::sun::jmx::remote::util::ClassLogger* logger;
	::java::util::List* clientList = nullptr;
	::java::lang::ClassLoader* cl = nullptr;
	::javax::management::MBeanServer* mbeanServer = nullptr;
	::java::util::Map* env = nullptr;
	::javax::management::remote::rmi::RMIConnectorServer* connServer = nullptr;
	static int32_t connectionIdNumber;
	::com::sun::jmx::remote::internal::NotificationBuffer* notifBuffer = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIServerImpl_h_