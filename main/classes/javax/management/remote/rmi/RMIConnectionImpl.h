#ifndef _javax_management_remote_rmi_RMIConnectionImpl_h_
#define _javax_management_remote_rmi_RMIConnectionImpl_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl
//$ extends javax.management.remote.rmi.RMIConnection
//$ implements java.rmi.server.Unreferenced

#include <java/lang/Array.h>
#include <java/rmi/server/Unreferenced.h>
#include <javax/management/remote/rmi/RMIConnection.h>

#pragma push_macro("ADD_NOTIFICATION_LISTENERS")
#undef ADD_NOTIFICATION_LISTENERS
#pragma push_macro("ADD_NOTIFICATION_LISTENER_OBJECTNAME")
#undef ADD_NOTIFICATION_LISTENER_OBJECTNAME
#pragma push_macro("CREATE_MBEAN")
#undef CREATE_MBEAN
#pragma push_macro("CREATE_MBEAN_LOADER")
#undef CREATE_MBEAN_LOADER
#pragma push_macro("CREATE_MBEAN_LOADER_PARAMS")
#undef CREATE_MBEAN_LOADER_PARAMS
#pragma push_macro("CREATE_MBEAN_PARAMS")
#undef CREATE_MBEAN_PARAMS
#pragma push_macro("GET_ATTRIBUTE")
#undef GET_ATTRIBUTE
#pragma push_macro("GET_ATTRIBUTES")
#undef GET_ATTRIBUTES
#pragma push_macro("GET_DEFAULT_DOMAIN")
#undef GET_DEFAULT_DOMAIN
#pragma push_macro("GET_DOMAINS")
#undef GET_DOMAINS
#pragma push_macro("GET_MBEAN_COUNT")
#undef GET_MBEAN_COUNT
#pragma push_macro("GET_MBEAN_INFO")
#undef GET_MBEAN_INFO
#pragma push_macro("GET_OBJECT_INSTANCE")
#undef GET_OBJECT_INSTANCE
#pragma push_macro("INVOKE")
#undef INVOKE
#pragma push_macro("IS_INSTANCE_OF")
#undef IS_INSTANCE_OF
#pragma push_macro("IS_REGISTERED")
#undef IS_REGISTERED
#pragma push_macro("NO_OBJECTS")
#undef NO_OBJECTS
#pragma push_macro("NO_STRINGS")
#undef NO_STRINGS
#pragma push_macro("QUERY_MBEANS")
#undef QUERY_MBEANS
#pragma push_macro("QUERY_NAMES")
#undef QUERY_NAMES
#pragma push_macro("REMOVE_NOTIFICATION_LISTENER")
#undef REMOVE_NOTIFICATION_LISTENER
#pragma push_macro("REMOVE_NOTIFICATION_LISTENER_OBJECTNAME")
#undef REMOVE_NOTIFICATION_LISTENER_OBJECTNAME
#pragma push_macro("REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK")
#undef REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK
#pragma push_macro("SET_ATTRIBUTE")
#undef SET_ATTRIBUTE
#pragma push_macro("SET_ATTRIBUTES")
#undef SET_ATTRIBUTES
#pragma push_macro("UNREGISTER_MBEAN")
#undef UNREGISTER_MBEAN

namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace internal {
					class ServerCommunicatorAdmin;
					class ServerNotifForwarder;
				}
			}
		}
	}
}
namespace com {
	namespace sun {
		namespace jmx {
			namespace remote {
				namespace security {
					class SubjectDelegator;
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
					class ClassLoaderWithRepository;
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
		class Exception;
		class Integer;
		class Throwable;
	}
}
namespace java {
	namespace rmi {
		class MarshalledObject;
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
		class Permission;
	}
}
namespace java {
	namespace util {
		class Map;
		class Set;
	}
}
namespace javax {
	namespace management {
		class AttributeList;
		class MBeanInfo;
		class MBeanServer;
		class ObjectInstance;
		class ObjectName;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			class NotificationResult;
		}
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIServerImpl;
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

class $export RMIConnectionImpl : public ::javax::management::remote::rmi::RMIConnection, public ::java::rmi::server::Unreferenced {
	$class(RMIConnectionImpl, 0, ::javax::management::remote::rmi::RMIConnection, ::java::rmi::server::Unreferenced)
public:
	RMIConnectionImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::javax::management::remote::rmi::RMIServerImpl* rmiServer, $String* connectionId, ::java::lang::ClassLoader* defaultClassLoader, ::javax::security::auth::Subject* subject, ::java::util::Map* env);
	virtual void addNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::java::rmi::MarshalledObject* filter, ::java::rmi::MarshalledObject* handback, ::javax::security::auth::Subject* delegationSubject) override;
	virtual $Array<::java::lang::Integer>* addNotificationListeners($Array<::javax::management::ObjectName>* names, $Array<::java::rmi::MarshalledObject>* filters, $Array<::javax::security::auth::Subject>* delegationSubjects) override;
	static void checkNonNull($String* what, Object$* x);
	virtual void close() override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::management::ObjectName* loaderName, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* params, $StringArray* signature, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::management::ObjectName* loaderName, ::java::rmi::MarshalledObject* params, $StringArray* signature, ::javax::security::auth::Subject* delegationSubject) override;
	$Object* doOperation(int32_t operation, $ObjectArray* params);
	$Object* doPrivilegedOperation(int32_t operation, $ObjectArray* params, ::javax::security::auth::Subject* delegationSubject);
	static ::java::lang::Exception* extractException(::java::lang::Exception* e);
	virtual ::javax::management::remote::NotificationResult* fetchNotifications(int64_t clientSequenceNumber, int32_t maxNotifications, int64_t timeout) override;
	virtual $Object* getAttribute(::javax::management::ObjectName* name, $String* attribute, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::AttributeList* getAttributes(::javax::management::ObjectName* name, $StringArray* attributes, ::javax::security::auth::Subject* delegationSubject) override;
	::java::lang::ClassLoader* getClassLoader(::javax::management::ObjectName* name);
	::java::lang::ClassLoader* getClassLoaderFor(::javax::management::ObjectName* name);
	virtual $String* getConnectionId() override;
	virtual $String* getDefaultDomain(::javax::security::auth::Subject* delegationSubject) override;
	virtual $StringArray* getDomains(::javax::security::auth::Subject* delegationSubject) override;
	virtual ::java::lang::Integer* getMBeanCount(::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::MBeanInfo* getMBeanInfo(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::ObjectInstance* getObjectInstance(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) override;
	::com::sun::jmx::remote::internal::ServerNotifForwarder* getServerNotifFwd();
	virtual $Object* invoke(::javax::management::ObjectName* name, $String* operationName, ::java::rmi::MarshalledObject* params, $StringArray* signature, ::javax::security::auth::Subject* delegationSubject) override;
	virtual bool isInstanceOf(::javax::management::ObjectName* name, $String* className, ::javax::security::auth::Subject* delegationSubject) override;
	virtual bool isRegistered(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) override;
	static $Object* lambda$unwrap$0($Class* wrappedClass, ::java::rmi::MarshalledObject* mo);
	static ::java::io::IOException* newIOException($String* message, $Throwable* cause);
	static $ObjectArray* nullIsEmpty($ObjectArray* array);
	static $StringArray* nullIsEmpty($StringArray* array);
	static $String* objects($ObjectArray* objs);
	virtual ::java::util::Set* queryMBeans(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* query, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::java::util::Set* queryNames(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* query, ::javax::security::auth::Subject* delegationSubject) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::javax::security::auth::Subject* delegationSubject) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::java::rmi::MarshalledObject* filter, ::java::rmi::MarshalledObject* handback, ::javax::security::auth::Subject* delegationSubject) override;
	virtual void removeNotificationListeners(::javax::management::ObjectName* name, $Array<::java::lang::Integer>* listenerIDs, ::javax::security::auth::Subject* delegationSubject) override;
	virtual void setAttribute(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* attribute, ::javax::security::auth::Subject* delegationSubject) override;
	virtual ::javax::management::AttributeList* setAttributes(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* attributes, ::javax::security::auth::Subject* delegationSubject) override;
	static $String* strings($StringArray* strs);
	virtual $String* toString() override;
	virtual void unreferenced() override;
	virtual void unregisterMBean(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) override;
	$Object* unwrap(::java::rmi::MarshalledObject* mo, ::java::lang::ClassLoader* cl, $Class* wrappedClass, ::javax::security::auth::Subject* delegationSubject);
	$Object* unwrap(::java::rmi::MarshalledObject* mo, ::java::lang::ClassLoader* cl1, ::java::lang::ClassLoader* cl2, $Class* wrappedClass, ::javax::security::auth::Subject* delegationSubject);
	static ::java::security::AccessControlContext* withPermissions($Array<::java::security::Permission>* perms);
	static $ObjectArray* NO_OBJECTS;
	static $StringArray* NO_STRINGS;
	::javax::security::auth::Subject* subject = nullptr;
	::com::sun::jmx::remote::security::SubjectDelegator* subjectDelegator = nullptr;
	bool removeCallerContext = false;
	::java::security::AccessControlContext* acc = nullptr;
	::javax::management::remote::rmi::RMIServerImpl* rmiServer = nullptr;
	::javax::management::MBeanServer* mbeanServer = nullptr;
	::java::lang::ClassLoader* defaultClassLoader = nullptr;
	::java::lang::ClassLoader* defaultContextClassLoader = nullptr;
	::com::sun::jmx::remote::util::ClassLoaderWithRepository* classLoaderWithRepository = nullptr;
	bool terminated = false;
	$String* connectionId = nullptr;
	::com::sun::jmx::remote::internal::ServerCommunicatorAdmin* serverCommunicatorAdmin = nullptr;
	static const int32_t ADD_NOTIFICATION_LISTENERS = 1;
	static const int32_t ADD_NOTIFICATION_LISTENER_OBJECTNAME = 2;
	static const int32_t CREATE_MBEAN = 3;
	static const int32_t CREATE_MBEAN_PARAMS = 4;
	static const int32_t CREATE_MBEAN_LOADER = 5;
	static const int32_t CREATE_MBEAN_LOADER_PARAMS = 6;
	static const int32_t GET_ATTRIBUTE = 7;
	static const int32_t GET_ATTRIBUTES = 8;
	static const int32_t GET_DEFAULT_DOMAIN = 9;
	static const int32_t GET_DOMAINS = 10;
	static const int32_t GET_MBEAN_COUNT = 11;
	static const int32_t GET_MBEAN_INFO = 12;
	static const int32_t GET_OBJECT_INSTANCE = 13;
	static const int32_t INVOKE = 14;
	static const int32_t IS_INSTANCE_OF = 15;
	static const int32_t IS_REGISTERED = 16;
	static const int32_t QUERY_MBEANS = 17;
	static const int32_t QUERY_NAMES = 18;
	static const int32_t REMOVE_NOTIFICATION_LISTENER = 19;
	static const int32_t REMOVE_NOTIFICATION_LISTENER_OBJECTNAME = 20;
	static const int32_t REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK = 21;
	static const int32_t SET_ATTRIBUTE = 22;
	static const int32_t SET_ATTRIBUTES = 23;
	static const int32_t UNREGISTER_MBEAN = 24;
	::com::sun::jmx::remote::internal::ServerNotifForwarder* serverNotifForwarder = nullptr;
	::java::util::Map* env = nullptr;
	static ::com::sun::jmx::remote::util::ClassLogger* logger;
};

			} // rmi
		} // remote
	} // management
} // javax

#pragma pop_macro("ADD_NOTIFICATION_LISTENERS")
#pragma pop_macro("ADD_NOTIFICATION_LISTENER_OBJECTNAME")
#pragma pop_macro("CREATE_MBEAN")
#pragma pop_macro("CREATE_MBEAN_LOADER")
#pragma pop_macro("CREATE_MBEAN_LOADER_PARAMS")
#pragma pop_macro("CREATE_MBEAN_PARAMS")
#pragma pop_macro("GET_ATTRIBUTE")
#pragma pop_macro("GET_ATTRIBUTES")
#pragma pop_macro("GET_DEFAULT_DOMAIN")
#pragma pop_macro("GET_DOMAINS")
#pragma pop_macro("GET_MBEAN_COUNT")
#pragma pop_macro("GET_MBEAN_INFO")
#pragma pop_macro("GET_OBJECT_INSTANCE")
#pragma pop_macro("INVOKE")
#pragma pop_macro("IS_INSTANCE_OF")
#pragma pop_macro("IS_REGISTERED")
#pragma pop_macro("NO_OBJECTS")
#pragma pop_macro("NO_STRINGS")
#pragma pop_macro("QUERY_MBEANS")
#pragma pop_macro("QUERY_NAMES")
#pragma pop_macro("REMOVE_NOTIFICATION_LISTENER")
#pragma pop_macro("REMOVE_NOTIFICATION_LISTENER_OBJECTNAME")
#pragma pop_macro("REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK")
#pragma pop_macro("SET_ATTRIBUTE")
#pragma pop_macro("SET_ATTRIBUTES")
#pragma pop_macro("UNREGISTER_MBEAN")

#endif // _javax_management_remote_rmi_RMIConnectionImpl_h_