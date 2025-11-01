#ifndef _javax_management_remote_rmi_RMIConnector_h_
#define _javax_management_remote_rmi_RMIConnector_h_
//$ class javax.management.remote.rmi.RMIConnector
//$ extends javax.management.remote.JMXConnector
//$ implements java.io.Serializable,javax.management.remote.JMXAddressable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <javax/management/remote/JMXAddressable.h>
#include <javax/management/remote/JMXConnector.h>

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					class ClientCommunicatorAdmin;
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
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace lang {
		class ClassLoader;
		class Exception;
		class Integer;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class WeakReference;
		}
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class Constructor;
		}
	}
}
namespace java {
	namespace rmi {
		class MarshalledObject;
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteObject;
		}
	}
}
namespace java {
	namespace util {
		class Map;
		class WeakHashMap;
	}
}
namespace javax {
	namespace management {
		class AttributeList;
		class MBeanServerConnection;
		class Notification;
		class NotificationBroadcasterSupport;
		class NotificationFilter;
		class NotificationListener;
		class ObjectName;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			class JMXServiceURL;
		}
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnection;
				class RMIConnector$RMINotifClient;
				class RMIServer;
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

class $export RMIConnector : public ::javax::management::remote::JMXConnector, public ::java::io::Serializable, public ::javax::management::remote::JMXAddressable {
	$class(RMIConnector, 0, ::javax::management::remote::JMXConnector, ::java::io::Serializable, ::javax::management::remote::JMXAddressable)
public:
	RMIConnector();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::javax::management::remote::rmi::RMIServer* rmiServer, ::javax::management::remote::JMXServiceURL* address, ::java::util::Map* environment);
	void init$(::javax::management::remote::JMXServiceURL* url, ::java::util::Map* environment);
	void init$(::javax::management::remote::rmi::RMIServer* rmiServer, ::java::util::Map* environment);
	virtual void addConnectionNotificationListener(::javax::management::NotificationListener* listener, ::javax::management::NotificationFilter* filter, Object$* handback) override;
	::java::lang::Integer* addListenerWithSubject(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* filter, ::javax::security::auth::Subject* delegationSubject, bool reconnect);
	$Array<::java::lang::Integer>* addListenersWithSubjects($Array<::javax::management::ObjectName>* names, $Array<::java::rmi::MarshalledObject>* filters, $Array<::javax::security::auth::Subject>* delegationSubjects, bool reconnect);
	static $bytes* base64ToByteArray($String* s);
	static int32_t base64toInt(char16_t c);
	static void checkStub(::java::rmi::Remote* stub, $Class* stubClass);
	virtual void close() override;
	void close(bool intern);
	virtual void connect() override;
	virtual void connect(::java::util::Map* environment) override;
	::javax::management::remote::rmi::RMIServer* findRMIServer(::javax::management::remote::JMXServiceURL* directoryURL, ::java::util::Map* environment);
	::javax::management::remote::rmi::RMIServer* findRMIServerJNDI($String* jndiURL, ::java::util::Map* env);
	::javax::management::remote::rmi::RMIServer* findRMIServerJRMP($String* base64, ::java::util::Map* env);
	virtual ::javax::management::remote::JMXServiceURL* getAddress() override;
	static $String* getAttributesNames(::javax::management::AttributeList* attributes);
	static ::javax::management::remote::rmi::RMIConnection* getConnection(::javax::management::remote::rmi::RMIServer* server, Object$* credentials, bool checkStub);
	virtual $String* getConnectionId() override;
	::javax::management::MBeanServerConnection* getConnectionWithSubject(::javax::security::auth::Subject* delegationSubject);
	virtual ::javax::management::MBeanServerConnection* getMBeanServerConnection() override;
	virtual ::javax::management::MBeanServerConnection* getMBeanServerConnection(::javax::security::auth::Subject* delegationSubject) override;
	void initTransients();
	static ::javax::management::remote::rmi::RMIServer* narrowJRMPServer(Object$* objref);
	static $String* objects($ObjectArray* objs);
	static $String* packageOf($String* cn);
	void popDefaultClassLoader(::java::lang::ClassLoader* old);
	::java::lang::ClassLoader* pushDefaultClassLoader();
	void readObject(::java::io::ObjectInputStream* s);
	virtual void removeConnectionNotificationListener(::javax::management::NotificationListener* listener) override;
	virtual void removeConnectionNotificationListener(::javax::management::NotificationListener* listener, ::javax::management::NotificationFilter* filter, Object$* handback) override;
	void sendNotification(::javax::management::Notification* n);
	static ::javax::management::remote::rmi::RMIConnection* shadowJrmpStub(::java::rmi::server::RemoteObject* stub);
	static $String* strings($StringArray* strs);
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* s);
	static ::com::sun::jmx::remote::util::ClassLogger* logger;
	static const int64_t serialVersionUID = (int64_t)0x0B57B6F88224E2E9;
	static $String* rmiServerImplStubClassName;
	static $Class* rmiServerImplStubClass;
	static $String* rmiConnectionImplStubClassName;
	static $Class* rmiConnectionImplStubClass;
	static $String* pRefClassName;
	static ::java::lang::reflect::Constructor* proxyRefConstructor;
	static $bytes* base64ToInt;
	::javax::management::remote::rmi::RMIServer* rmiServer = nullptr;
	::javax::management::remote::JMXServiceURL* jmxServiceURL = nullptr;
	::java::util::Map* env = nullptr;
	::java::lang::ClassLoader* defaultClassLoader = nullptr;
	::javax::management::remote::rmi::RMIConnection* connection = nullptr;
	$String* connectionId = nullptr;
	int64_t clientNotifSeqNo = 0;
	::java::util::WeakHashMap* rmbscMap = nullptr;
	::java::lang::ref::WeakReference* nullSubjectConnRef = nullptr;
	::javax::management::remote::rmi::RMIConnector$RMINotifClient* rmiNotifClient = nullptr;
	int64_t clientNotifCounter = 0;
	bool connected = false;
	bool terminated = false;
	::java::lang::Exception* closeException = nullptr;
	::javax::management::NotificationBroadcasterSupport* connectionBroadcaster = nullptr;
	::com::sun::jmx::remote::internal::ClientCommunicatorAdmin* communicatorAdmin = nullptr;
	static $volatile(::java::lang::ref::WeakReference*) orb;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector_h_