#ifndef _javax_management_remote_rmi_RMIConnectionImpl_Stub_h_
#define _javax_management_remote_rmi_RMIConnectionImpl_Stub_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl_Stub
//$ extends java.rmi.server.RemoteStub
//$ implements javax.management.remote.rmi.RMIConnection

#include <java/lang/Array.h>
#include <java/rmi/server/RemoteStub.h>
#include <javax/management/remote/rmi/RMIConnection.h>

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
	}
}
namespace java {
	namespace rmi {
		class MarshalledObject;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteRef;
		}
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

class $import RMIConnectionImpl_Stub : public ::java::rmi::server::RemoteStub, public ::javax::management::remote::rmi::RMIConnection {
	$class(RMIConnectionImpl_Stub, 0, ::java::rmi::server::RemoteStub, ::javax::management::remote::rmi::RMIConnection)
public:
	RMIConnectionImpl_Stub();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::rmi::server::RemoteRef* ref);
	virtual void addNotificationListener(::javax::management::ObjectName* $param_ObjectName_1, ::javax::management::ObjectName* $param_ObjectName_2, ::java::rmi::MarshalledObject* $param_MarshalledObject_3, ::java::rmi::MarshalledObject* $param_MarshalledObject_4, ::javax::security::auth::Subject* $param_Subject_5) override;
	virtual $Array<::java::lang::Integer>* addNotificationListeners($Array<::javax::management::ObjectName>* $param_arrayOf_ObjectName_1, $Array<::java::rmi::MarshalledObject>* $param_arrayOf_MarshalledObject_2, $Array<::javax::security::auth::Subject>* $param_arrayOf_Subject_3) override;
	virtual void close() override;
	virtual ::javax::management::ObjectInstance* createMBean($String* $param_String_1, ::javax::management::ObjectName* $param_ObjectName_2, ::java::rmi::MarshalledObject* $param_MarshalledObject_3, $StringArray* $param_arrayOf_String_4, ::javax::security::auth::Subject* $param_Subject_5) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* $param_String_1, ::javax::management::ObjectName* $param_ObjectName_2, ::javax::management::ObjectName* $param_ObjectName_3, ::java::rmi::MarshalledObject* $param_MarshalledObject_4, $StringArray* $param_arrayOf_String_5, ::javax::security::auth::Subject* $param_Subject_6) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* $param_String_1, ::javax::management::ObjectName* $param_ObjectName_2, ::javax::management::ObjectName* $param_ObjectName_3, ::javax::security::auth::Subject* $param_Subject_4) override;
	virtual ::javax::management::ObjectInstance* createMBean($String* $param_String_1, ::javax::management::ObjectName* $param_ObjectName_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual ::javax::management::remote::NotificationResult* fetchNotifications(int64_t $param_long_1, int32_t $param_int_2, int64_t $param_long_3) override;
	virtual $Object* getAttribute(::javax::management::ObjectName* $param_ObjectName_1, $String* $param_String_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual ::javax::management::AttributeList* getAttributes(::javax::management::ObjectName* $param_ObjectName_1, $StringArray* $param_arrayOf_String_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual $String* getConnectionId() override;
	virtual $String* getDefaultDomain(::javax::security::auth::Subject* $param_Subject_1) override;
	virtual $StringArray* getDomains(::javax::security::auth::Subject* $param_Subject_1) override;
	virtual ::java::lang::Integer* getMBeanCount(::javax::security::auth::Subject* $param_Subject_1) override;
	virtual ::javax::management::MBeanInfo* getMBeanInfo(::javax::management::ObjectName* $param_ObjectName_1, ::javax::security::auth::Subject* $param_Subject_2) override;
	virtual ::javax::management::ObjectInstance* getObjectInstance(::javax::management::ObjectName* $param_ObjectName_1, ::javax::security::auth::Subject* $param_Subject_2) override;
	virtual $Object* invoke(::javax::management::ObjectName* $param_ObjectName_1, $String* $param_String_2, ::java::rmi::MarshalledObject* $param_MarshalledObject_3, $StringArray* $param_arrayOf_String_4, ::javax::security::auth::Subject* $param_Subject_5) override;
	virtual bool isInstanceOf(::javax::management::ObjectName* $param_ObjectName_1, $String* $param_String_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual bool isRegistered(::javax::management::ObjectName* $param_ObjectName_1, ::javax::security::auth::Subject* $param_Subject_2) override;
	virtual ::java::util::Set* queryMBeans(::javax::management::ObjectName* $param_ObjectName_1, ::java::rmi::MarshalledObject* $param_MarshalledObject_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual ::java::util::Set* queryNames(::javax::management::ObjectName* $param_ObjectName_1, ::java::rmi::MarshalledObject* $param_MarshalledObject_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* $param_ObjectName_1, ::javax::management::ObjectName* $param_ObjectName_2, ::java::rmi::MarshalledObject* $param_MarshalledObject_3, ::java::rmi::MarshalledObject* $param_MarshalledObject_4, ::javax::security::auth::Subject* $param_Subject_5) override;
	virtual void removeNotificationListener(::javax::management::ObjectName* $param_ObjectName_1, ::javax::management::ObjectName* $param_ObjectName_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual void removeNotificationListeners(::javax::management::ObjectName* $param_ObjectName_1, $Array<::java::lang::Integer>* $param_arrayOf_Integer_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual void setAttribute(::javax::management::ObjectName* $param_ObjectName_1, ::java::rmi::MarshalledObject* $param_MarshalledObject_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual ::javax::management::AttributeList* setAttributes(::javax::management::ObjectName* $param_ObjectName_1, ::java::rmi::MarshalledObject* $param_MarshalledObject_2, ::javax::security::auth::Subject* $param_Subject_3) override;
	virtual $String* toString() override;
	virtual void unregisterMBean(::javax::management::ObjectName* $param_ObjectName_1, ::javax::security::auth::Subject* $param_Subject_2) override;
	static const int64_t serialVersionUID = 2;
	static ::java::lang::reflect::Method* $method_addNotificationListener_0;
	static ::java::lang::reflect::Method* $method_addNotificationListeners_1;
	static ::java::lang::reflect::Method* $method_close_2;
	static ::java::lang::reflect::Method* $method_createMBean_3;
	static ::java::lang::reflect::Method* $method_createMBean_4;
	static ::java::lang::reflect::Method* $method_createMBean_5;
	static ::java::lang::reflect::Method* $method_createMBean_6;
	static ::java::lang::reflect::Method* $method_fetchNotifications_7;
	static ::java::lang::reflect::Method* $method_getAttribute_8;
	static ::java::lang::reflect::Method* $method_getAttributes_9;
	static ::java::lang::reflect::Method* $method_getConnectionId_10;
	static ::java::lang::reflect::Method* $method_getDefaultDomain_11;
	static ::java::lang::reflect::Method* $method_getDomains_12;
	static ::java::lang::reflect::Method* $method_getMBeanCount_13;
	static ::java::lang::reflect::Method* $method_getMBeanInfo_14;
	static ::java::lang::reflect::Method* $method_getObjectInstance_15;
	static ::java::lang::reflect::Method* $method_invoke_16;
	static ::java::lang::reflect::Method* $method_isInstanceOf_17;
	static ::java::lang::reflect::Method* $method_isRegistered_18;
	static ::java::lang::reflect::Method* $method_queryMBeans_19;
	static ::java::lang::reflect::Method* $method_queryNames_20;
	static ::java::lang::reflect::Method* $method_removeNotificationListener_21;
	static ::java::lang::reflect::Method* $method_removeNotificationListener_22;
	static ::java::lang::reflect::Method* $method_removeNotificationListeners_23;
	static ::java::lang::reflect::Method* $method_setAttribute_24;
	static ::java::lang::reflect::Method* $method_setAttributes_25;
	static ::java::lang::reflect::Method* $method_unregisterMBean_26;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl_Stub_h_