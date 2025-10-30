#include <javax/management/remote/rmi/RMIConnection.h>

#include <java/io/Closeable.h>
#include <java/rmi/MarshalledObject.h>
#include <java/util/Set.h>
#include <javax/management/AttributeList.h>
#include <javax/management/MBeanInfo.h>
#include <javax/management/ObjectInstance.h>
#include <javax/management/ObjectName.h>
#include <javax/management/remote/NotificationResult.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

using $IntegerArray = $Array<::java::lang::Integer>;
using $MarshalledObjectArray = $Array<::java::rmi::MarshalledObject>;
using $ObjectNameArray = $Array<::javax::management::ObjectName>;
using $SubjectArray = $Array<::javax::security::auth::Subject>;
using $Closeable = ::java::io::Closeable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $Remote = ::java::rmi::Remote;
using $Set = ::java::util::Set;
using $AttributeList = ::javax::management::AttributeList;
using $MBeanInfo = ::javax::management::MBeanInfo;
using $ObjectInstance = ::javax::management::ObjectInstance;
using $ObjectName = ::javax::management::ObjectName;
using $NotificationResult = ::javax::management::remote::NotificationResult;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$MethodInfo _RMIConnection_MethodInfo_[] = {
	{"addNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"addNotificationListeners", "([Ljavax/management/ObjectName;[Ljava/rmi/MarshalledObject;[Ljavax/security/auth/Subject;)[Ljava/lang/Integer;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"close", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,javax.management.InstanceNotFoundException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,javax.management.InstanceNotFoundException,java.io.IOException"},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"fetchNotifications", "(JIJ)Ljavax/management/remote/NotificationResult;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"getAttribute", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.MBeanException,javax.management.AttributeNotFoundException,javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"getAttributes", "(Ljavax/management/ObjectName;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/AttributeList;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"getConnectionId", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getDefaultDomain", "(Ljavax/security/auth/Subject;)Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getDomains", "(Ljavax/security/auth/Subject;)[Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getMBeanCount", "(Ljavax/security/auth/Subject;)Ljava/lang/Integer;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getMBeanInfo", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/MBeanInfo;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.IntrospectionException,javax.management.ReflectionException,java.io.IOException"},
	{"getObjectInstance", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"invoke", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.ReflectionException,java.io.IOException"},
	{"isInstanceOf", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljavax/security/auth/Subject;)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"isRegistered", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"queryMBeans", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set;", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set<Ljavax/management/ObjectInstance;>;", $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"queryNames", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set;", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set<Ljavax/management/ObjectName;>;", $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListeners", "(Ljavax/management/ObjectName;[Ljava/lang/Integer;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"setAttribute", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.AttributeNotFoundException,javax.management.InvalidAttributeValueException,javax.management.MBeanException,javax.management.ReflectionException,java.io.IOException"},
	{"setAttributes", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljavax/management/AttributeList;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unregisterMBean", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "javax.management.InstanceNotFoundException,javax.management.MBeanRegistrationException,java.io.IOException"},
	{}
};

$ClassInfo _RMIConnection_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.management.remote.rmi.RMIConnection",
	nullptr,
	"java.io.Closeable,java.rmi.Remote",
	nullptr,
	_RMIConnection_MethodInfo_
};

$Object* allocate$RMIConnection($Class* clazz) {
	return $of($alloc(RMIConnection));
}

int32_t RMIConnection::hashCode() {
	 return this->$Closeable::hashCode();
}

bool RMIConnection::equals(Object$* arg0) {
	 return this->$Closeable::equals(arg0);
}

$Object* RMIConnection::clone() {
	 return this->$Closeable::clone();
}

$String* RMIConnection::toString() {
	 return this->$Closeable::toString();
}

void RMIConnection::finalize() {
	this->$Closeable::finalize();
}

$Class* RMIConnection::load$($String* name, bool initialize) {
	$loadClass(RMIConnection, name, initialize, &_RMIConnection_ClassInfo_, allocate$RMIConnection);
	return class$;
}

$Class* RMIConnection::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax