#include <javax/management/remote/rmi/RMIConnectionImpl_Stub.h>

#include <java/io/IOException.h>
#include <java/lang/AutoCloseable.h>
#include <java/lang/NoSuchMethodError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/MarshalledObject.h>
#include <java/rmi/Remote.h>
#include <java/rmi/UnexpectedException.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/util/Set.h>
#include <javax/management/AttributeList.h>
#include <javax/management/AttributeNotFoundException.h>
#include <javax/management/InstanceAlreadyExistsException.h>
#include <javax/management/InstanceNotFoundException.h>
#include <javax/management/IntrospectionException.h>
#include <javax/management/InvalidAttributeValueException.h>
#include <javax/management/ListenerNotFoundException.h>
#include <javax/management/MBeanException.h>
#include <javax/management/MBeanInfo.h>
#include <javax/management/MBeanRegistrationException.h>
#include <javax/management/NotCompliantMBeanException.h>
#include <javax/management/ObjectInstance.h>
#include <javax/management/ObjectName.h>
#include <javax/management/ReflectionException.h>
#include <javax/management/remote/NotificationResult.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

#undef TYPE

using $IntegerArray = $Array<::java::lang::Integer>;
using $MarshalledObjectArray = $Array<::java::rmi::MarshalledObject>;
using $ObjectNameArray = $Array<::javax::management::ObjectName>;
using $SubjectArray = $Array<::javax::security::auth::Subject>;
using $IOException = ::java::io::IOException;
using $AutoCloseable = ::java::lang::AutoCloseable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodError = ::java::lang::NoSuchMethodError;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Method = ::java::lang::reflect::Method;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $Remote = ::java::rmi::Remote;
using $UnexpectedException = ::java::rmi::UnexpectedException;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $Set = ::java::util::Set;
using $AttributeList = ::javax::management::AttributeList;
using $AttributeNotFoundException = ::javax::management::AttributeNotFoundException;
using $InstanceAlreadyExistsException = ::javax::management::InstanceAlreadyExistsException;
using $InstanceNotFoundException = ::javax::management::InstanceNotFoundException;
using $IntrospectionException = ::javax::management::IntrospectionException;
using $InvalidAttributeValueException = ::javax::management::InvalidAttributeValueException;
using $ListenerNotFoundException = ::javax::management::ListenerNotFoundException;
using $MBeanException = ::javax::management::MBeanException;
using $MBeanInfo = ::javax::management::MBeanInfo;
using $MBeanRegistrationException = ::javax::management::MBeanRegistrationException;
using $NotCompliantMBeanException = ::javax::management::NotCompliantMBeanException;
using $ObjectInstance = ::javax::management::ObjectInstance;
using $ObjectName = ::javax::management::ObjectName;
using $ReflectionException = ::javax::management::ReflectionException;
using $NotificationResult = ::javax::management::remote::NotificationResult;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl_Stub_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl_Stub, serialVersionUID)},
	{"$method_addNotificationListener_0", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_addNotificationListener_0)},
	{"$method_addNotificationListeners_1", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_addNotificationListeners_1)},
	{"$method_close_2", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_close_2)},
	{"$method_createMBean_3", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_createMBean_3)},
	{"$method_createMBean_4", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_createMBean_4)},
	{"$method_createMBean_5", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_createMBean_5)},
	{"$method_createMBean_6", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_createMBean_6)},
	{"$method_fetchNotifications_7", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_fetchNotifications_7)},
	{"$method_getAttribute_8", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getAttribute_8)},
	{"$method_getAttributes_9", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getAttributes_9)},
	{"$method_getConnectionId_10", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getConnectionId_10)},
	{"$method_getDefaultDomain_11", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getDefaultDomain_11)},
	{"$method_getDomains_12", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getDomains_12)},
	{"$method_getMBeanCount_13", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getMBeanCount_13)},
	{"$method_getMBeanInfo_14", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getMBeanInfo_14)},
	{"$method_getObjectInstance_15", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_getObjectInstance_15)},
	{"$method_invoke_16", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_invoke_16)},
	{"$method_isInstanceOf_17", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_isInstanceOf_17)},
	{"$method_isRegistered_18", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_isRegistered_18)},
	{"$method_queryMBeans_19", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_queryMBeans_19)},
	{"$method_queryNames_20", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_queryNames_20)},
	{"$method_removeNotificationListener_21", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_removeNotificationListener_21)},
	{"$method_removeNotificationListener_22", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_removeNotificationListener_22)},
	{"$method_removeNotificationListeners_23", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_removeNotificationListeners_23)},
	{"$method_setAttribute_24", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_setAttribute_24)},
	{"$method_setAttributes_25", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_setAttributes_25)},
	{"$method_unregisterMBean_26", "Ljava/lang/reflect/Method;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectionImpl_Stub, $method_unregisterMBean_26)},
	{}
};

$MethodInfo _RMIConnectionImpl_Stub_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnectionImpl_Stub::*)($RemoteRef*)>(&RMIConnectionImpl_Stub::init$))},
	{"addNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException"},
	{"addNotificationListeners", "([Ljavax/management/ObjectName;[Ljava/rmi/MarshalledObject;[Ljavax/security/auth/Subject;)[Ljava/lang/Integer;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanException,javax.management.MBeanRegistrationException,javax.management.NotCompliantMBeanException,javax.management.ReflectionException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceAlreadyExistsException,javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.MBeanRegistrationException,javax.management.NotCompliantMBeanException,javax.management.ReflectionException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceAlreadyExistsException,javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.MBeanRegistrationException,javax.management.NotCompliantMBeanException,javax.management.ReflectionException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanException,javax.management.MBeanRegistrationException,javax.management.NotCompliantMBeanException,javax.management.ReflectionException"},
	{"fetchNotifications", "(JIJ)Ljavax/management/remote/NotificationResult;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getAttribute", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.AttributeNotFoundException,javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.ReflectionException"},
	{"getAttributes", "(Ljavax/management/ObjectName;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/AttributeList;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.ReflectionException"},
	{"getConnectionId", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getDefaultDomain", "(Ljavax/security/auth/Subject;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getDomains", "(Ljavax/security/auth/Subject;)[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getMBeanCount", "(Ljavax/security/auth/Subject;)Ljava/lang/Integer;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getMBeanInfo", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/MBeanInfo;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.IntrospectionException,javax.management.ReflectionException"},
	{"getObjectInstance", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException"},
	{"invoke", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.ReflectionException"},
	{"isInstanceOf", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljavax/security/auth/Subject;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException"},
	{"isRegistered", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"queryMBeans", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"queryNames", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException"},
	{"removeNotificationListeners", "(Ljavax/management/ObjectName;[Ljava/lang/Integer;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException"},
	{"setAttribute", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.AttributeNotFoundException,javax.management.InstanceNotFoundException,javax.management.InvalidAttributeValueException,javax.management.MBeanException,javax.management.ReflectionException"},
	{"setAttributes", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljavax/management/AttributeList;", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.ReflectionException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unregisterMBean", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.MBeanRegistrationException"},
	{}
};

$ClassInfo _RMIConnectionImpl_Stub_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl_Stub",
	"java.rmi.server.RemoteStub",
	"javax.management.remote.rmi.RMIConnection",
	_RMIConnectionImpl_Stub_FieldInfo_,
	_RMIConnectionImpl_Stub_MethodInfo_
};

$Object* allocate$RMIConnectionImpl_Stub($Class* clazz) {
	return $of($alloc(RMIConnectionImpl_Stub));
}

int32_t RMIConnectionImpl_Stub::hashCode() {
	 return this->$RemoteStub::hashCode();
}

bool RMIConnectionImpl_Stub::equals(Object$* arg0) {
	 return this->$RemoteStub::equals(arg0);
}

$String* RMIConnectionImpl_Stub::toString() {
	 return this->$RemoteStub::toString();
}

$Object* RMIConnectionImpl_Stub::clone() {
	 return this->$RemoteStub::clone();
}

void RMIConnectionImpl_Stub::finalize() {
	this->$RemoteStub::finalize();
}

$Method* RMIConnectionImpl_Stub::$method_addNotificationListener_0 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_addNotificationListeners_1 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_close_2 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_createMBean_3 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_createMBean_4 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_createMBean_5 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_createMBean_6 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_fetchNotifications_7 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getAttribute_8 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getAttributes_9 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getConnectionId_10 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getDefaultDomain_11 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getDomains_12 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getMBeanCount_13 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getMBeanInfo_14 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_getObjectInstance_15 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_invoke_16 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_isInstanceOf_17 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_isRegistered_18 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_queryMBeans_19 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_queryNames_20 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_removeNotificationListener_21 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_removeNotificationListener_22 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_removeNotificationListeners_23 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_setAttribute_24 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_setAttributes_25 = nullptr;
$Method* RMIConnectionImpl_Stub::$method_unregisterMBean_26 = nullptr;

void RMIConnectionImpl_Stub::init$($RemoteRef* ref) {
	$RemoteStub::init$(ref);
}

void RMIConnectionImpl_Stub::addNotificationListener($ObjectName* $param_ObjectName_1, $ObjectName* $param_ObjectName_2, $MarshalledObject* $param_MarshalledObject_3, $MarshalledObject* $param_MarshalledObject_4, $Subject* $param_Subject_5) {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_addNotificationListener_0, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_ObjectName_2),
			$of($param_MarshalledObject_3),
			$of($param_MarshalledObject_4),
			$of($param_Subject_5)
		}), 0x88F3B1814F68CCEB);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

$IntegerArray* RMIConnectionImpl_Stub::addNotificationListeners($ObjectNameArray* $param_arrayOf_ObjectName_1, $MarshalledObjectArray* $param_arrayOf_MarshalledObject_2, $SubjectArray* $param_arrayOf_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_addNotificationListeners_1, $$new($ObjectArray, {
			$of($param_arrayOf_ObjectName_1),
			$of($param_arrayOf_MarshalledObject_2),
			$of($param_arrayOf_Subject_3)
		}), 0xB6258D6E656D6EEF));
		return ($cast($IntegerArray, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

void RMIConnectionImpl_Stub::close() {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_close_2, nullptr, 0xBE2E5BC7809D0DCC);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

$ObjectInstance* RMIConnectionImpl_Stub::createMBean($String* $param_String_1, $ObjectName* $param_ObjectName_2, $MarshalledObject* $param_MarshalledObject_3, $StringArray* $param_arrayOf_String_4, $Subject* $param_Subject_5) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_createMBean_3, $$new($ObjectArray, {
			$of($param_String_1),
			$of($param_ObjectName_2),
			$of($param_MarshalledObject_3),
			$of($param_arrayOf_String_4),
			$of($param_Subject_5)
		}), 0x438DFA6CEA1191A2));
		return ($cast($ObjectInstance, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceAlreadyExistsException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($NotCompliantMBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl_Stub::createMBean($String* $param_String_1, $ObjectName* $param_ObjectName_2, $ObjectName* $param_ObjectName_3, $MarshalledObject* $param_MarshalledObject_4, $StringArray* $param_arrayOf_String_5, $Subject* $param_Subject_6) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_createMBean_4, $$new($ObjectArray, {
			$of($param_String_1),
			$of($param_ObjectName_2),
			$of($param_ObjectName_3),
			$of($param_MarshalledObject_4),
			$of($param_arrayOf_String_5),
			$of($param_Subject_6)
		}), 0xA4567C41A6370B8F));
		return ($cast($ObjectInstance, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceAlreadyExistsException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($NotCompliantMBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl_Stub::createMBean($String* $param_String_1, $ObjectName* $param_ObjectName_2, $ObjectName* $param_ObjectName_3, $Subject* $param_Subject_4) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_createMBean_5, $$new($ObjectArray, {
			$of($param_String_1),
			$of($param_ObjectName_2),
			$of($param_ObjectName_3),
			$of($param_Subject_4)
		}), 0x878C5407AEFC625C));
		return ($cast($ObjectInstance, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceAlreadyExistsException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($NotCompliantMBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl_Stub::createMBean($String* $param_String_1, $ObjectName* $param_ObjectName_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_createMBean_6, $$new($ObjectArray, {
			$of($param_String_1),
			$of($param_ObjectName_2),
			$of($param_Subject_3)
		}), 0x22D7FD4A906AC8E6));
		return ($cast($ObjectInstance, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceAlreadyExistsException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($NotCompliantMBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$NotificationResult* RMIConnectionImpl_Stub::fetchNotifications(int64_t $param_long_1, int32_t $param_int_2, int64_t $param_long_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_fetchNotifications_7, $$new($ObjectArray, {
			$($of($Long::valueOf($param_long_1))),
			$($of($Integer::valueOf($param_int_2))),
			$($of($Long::valueOf($param_long_3)))
		}), 0xBA171F3DC87C75E2));
		return ($cast($NotificationResult, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$Object* RMIConnectionImpl_Stub::getAttribute($ObjectName* $param_ObjectName_1, $String* $param_String_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getAttribute_8, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_String_2),
			$of($param_Subject_3)
		}), 0xF0E0500A394D7215));
		return $of($result);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($AttributeNotFoundException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$AttributeList* RMIConnectionImpl_Stub::getAttributes($ObjectName* $param_ObjectName_1, $StringArray* $param_arrayOf_String_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getAttributes_9, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_arrayOf_String_2),
			$of($param_Subject_3)
		}), 0x5739D96A8B235C47));
		return ($cast($AttributeList, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$String* RMIConnectionImpl_Stub::getConnectionId() {
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getConnectionId_10, nullptr, 0xFF0EBEC77DC65363));
		return ($cast($String, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$String* RMIConnectionImpl_Stub::getDefaultDomain($Subject* $param_Subject_1) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getDefaultDomain_11, $$new($ObjectArray, {$of($param_Subject_1)}), 0x53EDA2D82E1BDFA8));
		return ($cast($String, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$StringArray* RMIConnectionImpl_Stub::getDomains($Subject* $param_Subject_1) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getDomains_12, $$new($ObjectArray, {$of($param_Subject_1)}), 0xA38AB48D41D0F631));
		return ($cast($StringArray, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$Integer* RMIConnectionImpl_Stub::getMBeanCount($Subject* $param_Subject_1) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getMBeanCount_13, $$new($ObjectArray, {$of($param_Subject_1)}), 0xE3A812879DC32EA5));
		return ($cast($Integer, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$MBeanInfo* RMIConnectionImpl_Stub::getMBeanInfo($ObjectName* $param_ObjectName_1, $Subject* $param_Subject_2) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getMBeanInfo_14, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_Subject_2)
		}), 0x993CD0F9B9817AF6));
		return ($cast($MBeanInfo, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($IntrospectionException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl_Stub::getObjectInstance($ObjectName* $param_ObjectName_1, $Subject* $param_Subject_2) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_getObjectInstance_15, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_Subject_2)
		}), 0x6073B3361F37BDC2));
		return ($cast($ObjectInstance, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$Object* RMIConnectionImpl_Stub::invoke($ObjectName* $param_ObjectName_1, $String* $param_String_2, $MarshalledObject* $param_MarshalledObject_3, $StringArray* $param_arrayOf_String_4, $Subject* $param_Subject_5) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_invoke_16, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_String_2),
			$of($param_MarshalledObject_3),
			$of($param_arrayOf_String_4),
			$of($param_Subject_5)
		}), 0x13E7D69417E5DA20));
		return $of($result);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

bool RMIConnectionImpl_Stub::isInstanceOf($ObjectName* $param_ObjectName_1, $String* $param_String_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_isInstanceOf_17, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_String_2),
			$of($param_Subject_3)
		}), 0xE2327CC9422DBCF2));
		return $nc(($cast($Boolean, $result)))->booleanValue();
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

bool RMIConnectionImpl_Stub::isRegistered($ObjectName* $param_ObjectName_1, $Subject* $param_Subject_2) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_isRegistered_18, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_Subject_2)
		}), 0x738AC4E1CCABA014));
		return $nc(($cast($Boolean, $result)))->booleanValue();
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$Set* RMIConnectionImpl_Stub::queryMBeans($ObjectName* $param_ObjectName_1, $MarshalledObject* $param_MarshalledObject_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_queryMBeans_19, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_MarshalledObject_2),
			$of($param_Subject_3)
		}), 0x28774A543CA14DD8));
		return ($cast($Set, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$Set* RMIConnectionImpl_Stub::queryNames($ObjectName* $param_ObjectName_1, $MarshalledObject* $param_MarshalledObject_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_queryNames_20, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_MarshalledObject_2),
			$of($param_Subject_3)
		}), 0x7F0473ACB73677DA));
		return ($cast($Set, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

void RMIConnectionImpl_Stub::removeNotificationListener($ObjectName* $param_ObjectName_1, $ObjectName* $param_ObjectName_2, $MarshalledObject* $param_MarshalledObject_3, $MarshalledObject* $param_MarshalledObject_4, $Subject* $param_Subject_5) {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_removeNotificationListener_21, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_ObjectName_2),
			$of($param_MarshalledObject_3),
			$of($param_MarshalledObject_4),
			$of($param_Subject_5)
		}), 0x23C70088FDB91189);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($ListenerNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

void RMIConnectionImpl_Stub::removeNotificationListener($ObjectName* $param_ObjectName_1, $ObjectName* $param_ObjectName_2, $Subject* $param_Subject_3) {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_removeNotificationListener_22, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_ObjectName_2),
			$of($param_Subject_3)
		}), 0x5BA8AEE8FA8E0529);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($ListenerNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

void RMIConnectionImpl_Stub::removeNotificationListeners($ObjectName* $param_ObjectName_1, $IntegerArray* $param_arrayOf_Integer_2, $Subject* $param_Subject_3) {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_removeNotificationListeners_23, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_arrayOf_Integer_2),
			$of($param_Subject_3)
		}), 0x23604B280B8BBE96);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($ListenerNotFoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

void RMIConnectionImpl_Stub::setAttribute($ObjectName* $param_ObjectName_1, $MarshalledObject* $param_MarshalledObject_2, $Subject* $param_Subject_3) {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_setAttribute_24, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_MarshalledObject_2),
			$of($param_Subject_3)
		}), 0x5D845744730AFE0C);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($AttributeNotFoundException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($InvalidAttributeValueException& e) {
		$throw(e);
	} catch ($MBeanException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

$AttributeList* RMIConnectionImpl_Stub::setAttributes($ObjectName* $param_ObjectName_1, $MarshalledObject* $param_MarshalledObject_2, $Subject* $param_Subject_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Object, $result, $nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_setAttributes_25, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_MarshalledObject_2),
			$of($param_Subject_3)
		}), 0xFCCD348C60EF0EE4));
		return ($cast($AttributeList, $result));
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($ReflectionException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

void RMIConnectionImpl_Stub::unregisterMBean($ObjectName* $param_ObjectName_1, $Subject* $param_Subject_2) {
	try {
		$nc(this->ref)->invoke(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteStub*>(this))), RMIConnectionImpl_Stub::$method_unregisterMBean_26, $$new($ObjectArray, {
			$of($param_ObjectName_1),
			$of($param_Subject_2)
		}), 0xFDC958E2C12414D4);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($IOException& e) {
		$throw(e);
	} catch ($InstanceNotFoundException& e) {
		$throw(e);
	} catch ($MBeanRegistrationException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

void clinit$RMIConnectionImpl_Stub($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		try {
			$load($RMIConnection);
			$load($ObjectName);
			$load($MarshalledObject);
			$load($Subject);
			$assignStatic(RMIConnectionImpl_Stub::$method_addNotificationListener_0, $RMIConnection::class$->getMethod("addNotificationListener"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$ObjectName::class$,
				$MarshalledObject::class$,
				$MarshalledObject::class$,
				$Subject::class$
			})));
			$load($ObjectNameArray);
			$load($MarshalledObjectArray);
			$load($SubjectArray);
			$assignStatic(RMIConnectionImpl_Stub::$method_addNotificationListeners_1, $RMIConnection::class$->getMethod("addNotificationListeners"_s, $$new($ClassArray, {
				$getClass($ObjectNameArray),
				$getClass($MarshalledObjectArray),
				$getClass($SubjectArray)
			})));
			$load($AutoCloseable);
			$assignStatic(RMIConnectionImpl_Stub::$method_close_2, $AutoCloseable::class$->getMethod("close"_s, $$new($ClassArray, 0)));
			$load($StringArray);
			$assignStatic(RMIConnectionImpl_Stub::$method_createMBean_3, $RMIConnection::class$->getMethod("createMBean"_s, $$new($ClassArray, {
				$String::class$,
				$ObjectName::class$,
				$MarshalledObject::class$,
				$getClass($StringArray),
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_createMBean_4, $RMIConnection::class$->getMethod("createMBean"_s, $$new($ClassArray, {
				$String::class$,
				$ObjectName::class$,
				$ObjectName::class$,
				$MarshalledObject::class$,
				$getClass($StringArray),
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_createMBean_5, $RMIConnection::class$->getMethod("createMBean"_s, $$new($ClassArray, {
				$String::class$,
				$ObjectName::class$,
				$ObjectName::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_createMBean_6, $RMIConnection::class$->getMethod("createMBean"_s, $$new($ClassArray, {
				$String::class$,
				$ObjectName::class$,
				$Subject::class$
			})));
			$init($Long);
			$init($Integer);
			$assignStatic(RMIConnectionImpl_Stub::$method_fetchNotifications_7, $RMIConnection::class$->getMethod("fetchNotifications"_s, $$new($ClassArray, {
				$Long::TYPE,
				$Integer::TYPE,
				$Long::TYPE
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getAttribute_8, $RMIConnection::class$->getMethod("getAttribute"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$String::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getAttributes_9, $RMIConnection::class$->getMethod("getAttributes"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$getClass($StringArray),
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getConnectionId_10, $RMIConnection::class$->getMethod("getConnectionId"_s, $$new($ClassArray, 0)));
			$assignStatic(RMIConnectionImpl_Stub::$method_getDefaultDomain_11, $RMIConnection::class$->getMethod("getDefaultDomain"_s, $$new($ClassArray, {$Subject::class$})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getDomains_12, $RMIConnection::class$->getMethod("getDomains"_s, $$new($ClassArray, {$Subject::class$})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getMBeanCount_13, $RMIConnection::class$->getMethod("getMBeanCount"_s, $$new($ClassArray, {$Subject::class$})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getMBeanInfo_14, $RMIConnection::class$->getMethod("getMBeanInfo"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_getObjectInstance_15, $RMIConnection::class$->getMethod("getObjectInstance"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_invoke_16, $RMIConnection::class$->getMethod("invoke"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$String::class$,
				$MarshalledObject::class$,
				$getClass($StringArray),
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_isInstanceOf_17, $RMIConnection::class$->getMethod("isInstanceOf"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$String::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_isRegistered_18, $RMIConnection::class$->getMethod("isRegistered"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_queryMBeans_19, $RMIConnection::class$->getMethod("queryMBeans"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$MarshalledObject::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_queryNames_20, $RMIConnection::class$->getMethod("queryNames"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$MarshalledObject::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_removeNotificationListener_21, $RMIConnection::class$->getMethod("removeNotificationListener"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$ObjectName::class$,
				$MarshalledObject::class$,
				$MarshalledObject::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_removeNotificationListener_22, $RMIConnection::class$->getMethod("removeNotificationListener"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$ObjectName::class$,
				$Subject::class$
			})));
			$load($IntegerArray);
			$assignStatic(RMIConnectionImpl_Stub::$method_removeNotificationListeners_23, $RMIConnection::class$->getMethod("removeNotificationListeners"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$getClass($IntegerArray),
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_setAttribute_24, $RMIConnection::class$->getMethod("setAttribute"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$MarshalledObject::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_setAttributes_25, $RMIConnection::class$->getMethod("setAttributes"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$MarshalledObject::class$,
				$Subject::class$
			})));
			$assignStatic(RMIConnectionImpl_Stub::$method_unregisterMBean_26, $RMIConnection::class$->getMethod("unregisterMBean"_s, $$new($ClassArray, {
				$ObjectName::class$,
				$Subject::class$
			})));
		} catch ($NoSuchMethodException& e) {
			$throwNew($NoSuchMethodError, "stub class initialization failed"_s);
		}
	}
}

RMIConnectionImpl_Stub::RMIConnectionImpl_Stub() {
}

$Class* RMIConnectionImpl_Stub::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl_Stub, name, initialize, &_RMIConnectionImpl_Stub_ClassInfo_, clinit$RMIConnectionImpl_Stub, allocate$RMIConnectionImpl_Stub);
	return class$;
}

$Class* RMIConnectionImpl_Stub::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax