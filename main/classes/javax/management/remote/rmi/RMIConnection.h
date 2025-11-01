#ifndef _javax_management_remote_rmi_RMIConnection_h_
#define _javax_management_remote_rmi_RMIConnection_h_
//$ interface javax.management.remote.rmi.RMIConnection
//$ extends java.io.Closeable,java.rmi.Remote

#include <java/io/Closeable.h>
#include <java/lang/Array.h>
#include <java/rmi/Remote.h>

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace java {
	namespace rmi {
		class MarshalledObject;
	}
}
namespace java {
	namespace util {
		class Set;
	}
}
namespace javax {
	namespace management {
		class AttributeList;
		class MBeanInfo;
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

class $export RMIConnection : public ::java::io::Closeable, public ::java::rmi::Remote {
	$interface(RMIConnection, $NO_CLASS_INIT, ::java::io::Closeable, ::java::rmi::Remote)
public:
	virtual void addNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::java::rmi::MarshalledObject* filter, ::java::rmi::MarshalledObject* handback, ::javax::security::auth::Subject* delegationSubject) {}
	virtual $Array<::java::lang::Integer>* addNotificationListeners($Array<::javax::management::ObjectName>* names, $Array<::java::rmi::MarshalledObject>* filters, $Array<::javax::security::auth::Subject>* delegationSubjects) {return nullptr;}
	virtual $Object* clone() override;
	virtual void close() override {}
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::management::ObjectName* loaderName, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* params, $StringArray* signature, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::management::ObjectName* loaderName, ::java::rmi::MarshalledObject* params, $StringArray* signature, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual bool equals(Object$* arg0) override;
	virtual ::javax::management::remote::NotificationResult* fetchNotifications(int64_t clientSequenceNumber, int32_t maxNotifications, int64_t timeout) {return nullptr;}
	virtual void finalize() override;
	virtual $Object* getAttribute(::javax::management::ObjectName* name, $String* attribute, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::javax::management::AttributeList* getAttributes(::javax::management::ObjectName* name, $StringArray* attributes, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual $String* getConnectionId() {return nullptr;}
	virtual $String* getDefaultDomain(::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual $StringArray* getDomains(::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::java::lang::Integer* getMBeanCount(::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::javax::management::MBeanInfo* getMBeanInfo(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::javax::management::ObjectInstance* getObjectInstance(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual int32_t hashCode() override;
	virtual $Object* invoke(::javax::management::ObjectName* name, $String* operationName, ::java::rmi::MarshalledObject* params, $StringArray* signature, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual bool isInstanceOf(::javax::management::ObjectName* name, $String* className, ::javax::security::auth::Subject* delegationSubject) {return false;}
	virtual bool isRegistered(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) {return false;}
	virtual ::java::util::Set* queryMBeans(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* query, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual ::java::util::Set* queryNames(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* query, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::javax::security::auth::Subject* delegationSubject) {}
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::java::rmi::MarshalledObject* filter, ::java::rmi::MarshalledObject* handback, ::javax::security::auth::Subject* delegationSubject) {}
	virtual void removeNotificationListeners(::javax::management::ObjectName* name, $Array<::java::lang::Integer>* listenerIDs, ::javax::security::auth::Subject* delegationSubject) {}
	virtual void setAttribute(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* attribute, ::javax::security::auth::Subject* delegationSubject) {}
	virtual ::javax::management::AttributeList* setAttributes(::javax::management::ObjectName* name, ::java::rmi::MarshalledObject* attributes, ::javax::security::auth::Subject* delegationSubject) {return nullptr;}
	virtual $String* toString() override;
	virtual void unregisterMBean(::javax::management::ObjectName* name, ::javax::security::auth::Subject* delegationSubject) {}
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnection_h_