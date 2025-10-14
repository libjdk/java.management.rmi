#ifndef _javax_management_remote_rmi_RMIConnector$RemoteMBeanServerConnection_h_
#define _javax_management_remote_rmi_RMIConnector$RemoteMBeanServerConnection_h_
//$ class javax.management.remote.rmi.RMIConnector$RemoteMBeanServerConnection
//$ extends javax.management.MBeanServerConnection

#include <java/lang/Array.h>
#include <javax/management/MBeanServerConnection.h>

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace java {
	namespace util {
		class Set;
	}
}
namespace javax {
	namespace management {
		class Attribute;
		class AttributeList;
		class MBeanInfo;
		class NotificationFilter;
		class NotificationListener;
		class ObjectInstance;
		class ObjectName;
		class QueryExp;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnector;
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

class RMIConnector$RemoteMBeanServerConnection : public ::javax::management::MBeanServerConnection {
	$class(RMIConnector$RemoteMBeanServerConnection, $NO_CLASS_INIT, ::javax::management::MBeanServerConnection)
public:
	RMIConnector$RemoteMBeanServerConnection();
	void init$(::javax::management::remote::rmi::RMIConnector* this$0);
	void init$(::javax::management::remote::rmi::RMIConnector* this$0, ::javax::security::auth::Subject* delegationSubject);
	virtual void addNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::javax::management::NotificationFilter* filter, Object$* handback) override;
	virtual void addNotificationListener(::javax::management::ObjectName* name, ::javax::management::NotificationListener* listener, ::javax::management::NotificationFilter* filter, Object$* handback) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::management::ObjectName* loaderName) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, $ObjectArray* params, $StringArray* signature) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* className, ::javax::management::ObjectName* name, ::javax::management::ObjectName* loaderName, $ObjectArray* params, $StringArray* signature) override;
	virtual $Object* getAttribute(::javax::management::ObjectName* name, $String* attribute) override;
	virtual ::javax::management::AttributeList* getAttributes(::javax::management::ObjectName* name, $StringArray* attributes) override;
	virtual $String* getDefaultDomain() override;
	virtual $StringArray* getDomains() override;
	virtual ::java::lang::Integer* getMBeanCount() override;
	virtual ::javax::management::MBeanInfo* getMBeanInfo(::javax::management::ObjectName* name) override;
	virtual ::javax::management::ObjectInstance* getObjectInstance(::javax::management::ObjectName* name) override;
	virtual $Object* invoke(::javax::management::ObjectName* name, $String* operationName, $ObjectArray* params, $StringArray* signature) override;
	virtual bool isInstanceOf(::javax::management::ObjectName* name, $String* className) override;
	virtual bool isRegistered(::javax::management::ObjectName* name) override;
	virtual ::java::util::Set* queryMBeans(::javax::management::ObjectName* name, ::javax::management::QueryExp* query) override;
	virtual ::java::util::Set* queryNames(::javax::management::ObjectName* name, ::javax::management::QueryExp* query) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::ObjectName* listener, ::javax::management::NotificationFilter* filter, Object$* handback) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::NotificationListener* listener) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* name, ::javax::management::NotificationListener* listener, ::javax::management::NotificationFilter* filter, Object$* handback) override;
	virtual void setAttribute(::javax::management::ObjectName* name, ::javax::management::Attribute* attribute) override;
	virtual ::javax::management::AttributeList* setAttributes(::javax::management::ObjectName* name, ::javax::management::AttributeList* attributes) override;
	virtual void unregisterMBean(::javax::management::ObjectName* name) override;
	::javax::management::remote::rmi::RMIConnector* this$0 = nullptr;
	::javax::security::auth::Subject* delegationSubject = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$RemoteMBeanServerConnection_h_