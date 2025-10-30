#include <javax/management/remote/rmi/RMIConnector$RemoteMBeanServerConnection.h>

#include <com/sun/jmx/remote/internal/ClientCommunicatorAdmin.h>
#include <com/sun/jmx/remote/internal/ClientNotifForwarder.h>
#include <com/sun/jmx/remote/util/ClassLogger.h>
#include <java/io/IOException.h>
#include <java/lang/ClassLoader.h>
#include <java/rmi/MarshalledObject.h>
#include <java/util/Set.h>
#include <javax/management/Attribute.h>
#include <javax/management/AttributeList.h>
#include <javax/management/MBeanInfo.h>
#include <javax/management/NotificationFilter.h>
#include <javax/management/NotificationListener.h>
#include <javax/management/ObjectInstance.h>
#include <javax/management/ObjectName.h>
#include <javax/management/QueryExp.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnector$RMINotifClient.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

using $IntegerArray = $Array<::java::lang::Integer>;
using $ClientCommunicatorAdmin = ::com::sun::jmx::remote::internal::ClientCommunicatorAdmin;
using $ClientNotifForwarder = ::com::sun::jmx::remote::internal::ClientNotifForwarder;
using $ClassLogger = ::com::sun::jmx::remote::util::ClassLogger;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $Set = ::java::util::Set;
using $Attribute = ::javax::management::Attribute;
using $AttributeList = ::javax::management::AttributeList;
using $MBeanInfo = ::javax::management::MBeanInfo;
using $MBeanServerConnection = ::javax::management::MBeanServerConnection;
using $NotificationFilter = ::javax::management::NotificationFilter;
using $NotificationListener = ::javax::management::NotificationListener;
using $ObjectInstance = ::javax::management::ObjectInstance;
using $ObjectName = ::javax::management::ObjectName;
using $QueryExp = ::javax::management::QueryExp;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;
using $RMIConnector$RMINotifClient = ::javax::management::remote::rmi::RMIConnector$RMINotifClient;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnector$RemoteMBeanServerConnection_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnector;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$RemoteMBeanServerConnection, this$0)},
	{"delegationSubject", "Ljavax/security/auth/Subject;", nullptr, $PRIVATE, $field(RMIConnector$RemoteMBeanServerConnection, delegationSubject)},
	{}
};

$MethodInfo _RMIConnector$RemoteMBeanServerConnection_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnector;)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnector$RemoteMBeanServerConnection::*)($RMIConnector*)>(&RMIConnector$RemoteMBeanServerConnection::init$))},
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnector;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnector$RemoteMBeanServerConnection::*)($RMIConnector*,$Subject*)>(&RMIConnector$RemoteMBeanServerConnection::init$))},
	{"addNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/management/NotificationFilter;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"addNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/NotificationListener;Ljavax/management/NotificationFilter;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,javax.management.InstanceNotFoundException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;[Ljava/lang/Object;[Ljava/lang/String;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;[Ljava/lang/Object;[Ljava/lang/String;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,javax.management.InstanceNotFoundException,java.io.IOException"},
	{"getAttribute", "(Ljavax/management/ObjectName;Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.management.MBeanException,javax.management.AttributeNotFoundException,javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"getAttributes", "(Ljavax/management/ObjectName;[Ljava/lang/String;)Ljavax/management/AttributeList;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"getDefaultDomain", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getDomains", "()[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getMBeanCount", "()Ljava/lang/Integer;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getMBeanInfo", "(Ljavax/management/ObjectName;)Ljavax/management/MBeanInfo;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.IntrospectionException,javax.management.ReflectionException,java.io.IOException"},
	{"getObjectInstance", "(Ljavax/management/ObjectName;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"invoke", "(Ljavax/management/ObjectName;Ljava/lang/String;[Ljava/lang/Object;[Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.ReflectionException,java.io.IOException"},
	{"isInstanceOf", "(Ljavax/management/ObjectName;Ljava/lang/String;)Z", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"isRegistered", "(Ljavax/management/ObjectName;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"queryMBeans", "(Ljavax/management/ObjectName;Ljavax/management/QueryExp;)Ljava/util/Set;", "(Ljavax/management/ObjectName;Ljavax/management/QueryExp;)Ljava/util/Set<Ljavax/management/ObjectInstance;>;", $PUBLIC, nullptr, "java.io.IOException"},
	{"queryNames", "(Ljavax/management/ObjectName;Ljavax/management/QueryExp;)Ljava/util/Set;", "(Ljavax/management/ObjectName;Ljavax/management/QueryExp;)Ljava/util/Set<Ljavax/management/ObjectName;>;", $PUBLIC, nullptr, "java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/management/NotificationFilter;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/NotificationListener;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/NotificationListener;Ljavax/management/NotificationFilter;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"setAttribute", "(Ljavax/management/ObjectName;Ljavax/management/Attribute;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.AttributeNotFoundException,javax.management.InvalidAttributeValueException,javax.management.MBeanException,javax.management.ReflectionException,java.io.IOException"},
	{"setAttributes", "(Ljavax/management/ObjectName;Ljavax/management/AttributeList;)Ljavax/management/AttributeList;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"unregisterMBean", "(Ljavax/management/ObjectName;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.MBeanRegistrationException,java.io.IOException"},
	{}
};

$InnerClassInfo _RMIConnector$RemoteMBeanServerConnection_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$RemoteMBeanServerConnection", "javax.management.remote.rmi.RMIConnector", "RemoteMBeanServerConnection", $PRIVATE},
	{}
};

$ClassInfo _RMIConnector$RemoteMBeanServerConnection_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$RemoteMBeanServerConnection",
	"java.lang.Object",
	"javax.management.MBeanServerConnection",
	_RMIConnector$RemoteMBeanServerConnection_FieldInfo_,
	_RMIConnector$RemoteMBeanServerConnection_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnector$RemoteMBeanServerConnection_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$RemoteMBeanServerConnection($Class* clazz) {
	return $of($alloc(RMIConnector$RemoteMBeanServerConnection));
}

void RMIConnector$RemoteMBeanServerConnection::init$($RMIConnector* this$0) {
	RMIConnector$RemoteMBeanServerConnection::init$(this$0, nullptr);
}

void RMIConnector$RemoteMBeanServerConnection::init$($RMIConnector* this$0, $Subject* delegationSubject) {
	$set(this, this$0, this$0);
	$set(this, delegationSubject, delegationSubject);
}

$ObjectInstance* RMIConnector$RemoteMBeanServerConnection::createMBean($String* className, $ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("createMBean(String,ObjectName)"_s, $$str({"className="_s, className, ", name="_s, name}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($ObjectInstance, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->createMBean(className, name, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->createMBean(className, name, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnector$RemoteMBeanServerConnection::createMBean($String* className, $ObjectName* name, $ObjectName* loaderName) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("createMBean(String,ObjectName,ObjectName)"_s, $$str({"className="_s, className, ", name="_s, name, ", loaderName="_s, loaderName, ")"_s}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($ObjectInstance, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->createMBean(className, name, loaderName, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->createMBean(className, name, loaderName, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnector$RemoteMBeanServerConnection::createMBean($String* className, $ObjectName* name, $ObjectArray* params, $StringArray* signature) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$var($String, var$0, $$str({"className="_s, className, ", name="_s, name, ", signature="_s}));
		$nc($RMIConnector::logger)->debug("createMBean(String,ObjectName,Object[],String[])"_s, $$concat(var$0, $($RMIConnector::strings(signature))));
	}
	$var($MarshalledObject, sParams, $new($MarshalledObject, params));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$1, nullptr);
		$var($ObjectInstance, var$3, nullptr);
		bool return$2 = false;
		try {
			try {
				$assign(var$3, $nc(this->this$0->connection)->createMBean(className, name, sParams, signature, this->delegationSubject));
				return$2 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$3, $nc(this->this$0->connection)->createMBean(className, name, sParams, signature, this->delegationSubject));
				return$2 = true;
				goto $finally;
			}
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return var$3;
		}
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnector$RemoteMBeanServerConnection::createMBean($String* className, $ObjectName* name, $ObjectName* loaderName, $ObjectArray* params, $StringArray* signature) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$var($String, var$0, $$str({"className="_s, className, ", name="_s, name, ", loaderName="_s, loaderName, ", signature="_s}));
		$nc($RMIConnector::logger)->debug("createMBean(String,ObjectName,ObjectName,Object[],String[])"_s, $$concat(var$0, $($RMIConnector::strings(signature))));
	}
	$var($MarshalledObject, sParams, $new($MarshalledObject, params));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$1, nullptr);
		$var($ObjectInstance, var$3, nullptr);
		bool return$2 = false;
		try {
			try {
				$assign(var$3, $nc(this->this$0->connection)->createMBean(className, name, loaderName, sParams, signature, this->delegationSubject));
				return$2 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$3, $nc(this->this$0->connection)->createMBean(className, name, loaderName, sParams, signature, this->delegationSubject));
				return$2 = true;
				goto $finally;
			}
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return var$3;
		}
	}
	$shouldNotReachHere();
}

void RMIConnector$RemoteMBeanServerConnection::unregisterMBean($ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("unregisterMBean"_s, $$str({"name="_s, name}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->unregisterMBean(name, this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->unregisterMBean(name, this->delegationSubject);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$ObjectInstance* RMIConnector$RemoteMBeanServerConnection::getObjectInstance($ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("getObjectInstance"_s, $$str({"name="_s, name}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($ObjectInstance, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->getObjectInstance(name, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->getObjectInstance(name, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Set* RMIConnector$RemoteMBeanServerConnection::queryMBeans($ObjectName* name, $QueryExp* query) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("queryMBeans"_s, $$str({"name="_s, name, ", query="_s, query}));
	}
	$var($MarshalledObject, sQuery, $new($MarshalledObject, query));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($Set, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->queryMBeans(name, sQuery, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->queryMBeans(name, sQuery, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Set* RMIConnector$RemoteMBeanServerConnection::queryNames($ObjectName* name, $QueryExp* query) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("queryNames"_s, $$str({"name="_s, name, ", query="_s, query}));
	}
	$var($MarshalledObject, sQuery, $new($MarshalledObject, query));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($Set, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->queryNames(name, sQuery, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->queryNames(name, sQuery, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool RMIConnector$RemoteMBeanServerConnection::isRegistered($ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("isRegistered"_s, $$str({"name="_s, name}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			try {
				var$2 = $nc(this->this$0->connection)->isRegistered(name, this->delegationSubject);
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				var$2 = $nc(this->this$0->connection)->isRegistered(name, this->delegationSubject);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Integer* RMIConnector$RemoteMBeanServerConnection::getMBeanCount() {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("getMBeanCount"_s, ""_s);
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($Integer, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->getMBeanCount(this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->getMBeanCount(this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* RMIConnector$RemoteMBeanServerConnection::getAttribute($ObjectName* name, $String* attribute) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("getAttribute"_s, $$str({"name="_s, name, ", attribute="_s, attribute}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->getAttribute(name, attribute, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->getAttribute(name, attribute, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$AttributeList* RMIConnector$RemoteMBeanServerConnection::getAttributes($ObjectName* name, $StringArray* attributes) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$var($String, var$0, $$str({"name="_s, name, ", attributes="_s}));
		$nc($RMIConnector::logger)->debug("getAttributes"_s, $$concat(var$0, $($RMIConnector::strings(attributes))));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$1, nullptr);
		$var($AttributeList, var$3, nullptr);
		bool return$2 = false;
		try {
			try {
				$assign(var$3, $nc(this->this$0->connection)->getAttributes(name, attributes, this->delegationSubject));
				return$2 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$3, $nc(this->this$0->connection)->getAttributes(name, attributes, this->delegationSubject));
				return$2 = true;
				goto $finally;
			}
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return var$3;
		}
	}
	$shouldNotReachHere();
}

void RMIConnector$RemoteMBeanServerConnection::setAttribute($ObjectName* name, $Attribute* attribute) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$var($String, var$0, $$str({"name="_s, name, ", attribute name="_s}));
		$nc($RMIConnector::logger)->debug("setAttribute"_s, $$concat(var$0, $($nc(attribute)->getName())));
	}
	$var($MarshalledObject, sAttribute, $new($MarshalledObject, attribute));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$1, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->setAttribute(name, sAttribute, this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->setAttribute(name, sAttribute, this->delegationSubject);
			}
		} catch ($Throwable& var$2) {
			$assign(var$1, var$2);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
}

$AttributeList* RMIConnector$RemoteMBeanServerConnection::setAttributes($ObjectName* name, $AttributeList* attributes) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$var($String, var$0, $$str({"name="_s, name, ", attribute names="_s}));
		$nc($RMIConnector::logger)->debug("setAttributes"_s, $$concat(var$0, $($RMIConnector::getAttributesNames(attributes))));
	}
	$var($MarshalledObject, sAttributes, $new($MarshalledObject, attributes));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$1, nullptr);
		$var($AttributeList, var$3, nullptr);
		bool return$2 = false;
		try {
			try {
				$assign(var$3, $nc(this->this$0->connection)->setAttributes(name, sAttributes, this->delegationSubject));
				return$2 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$3, $nc(this->this$0->connection)->setAttributes(name, sAttributes, this->delegationSubject));
				return$2 = true;
				goto $finally;
			}
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return var$3;
		}
	}
	$shouldNotReachHere();
}

$Object* RMIConnector$RemoteMBeanServerConnection::invoke($ObjectName* name, $String* operationName, $ObjectArray* params, $StringArray* signature) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$var($String, var$0, $$str({"name="_s, name, ", operationName="_s, operationName, ", signature="_s}));
		$nc($RMIConnector::logger)->debug("invoke"_s, $$concat(var$0, $($RMIConnector::strings(signature))));
	}
	$var($MarshalledObject, sParams, $new($MarshalledObject, params));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$1, nullptr);
		$var($Object, var$3, nullptr);
		bool return$2 = false;
		try {
			try {
				$assign(var$3, $nc(this->this$0->connection)->invoke(name, operationName, sParams, signature, this->delegationSubject));
				return$2 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$3, $nc(this->this$0->connection)->invoke(name, operationName, sParams, signature, this->delegationSubject));
				return$2 = true;
				goto $finally;
			}
		} catch ($Throwable& var$4) {
			$assign(var$1, var$4);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
		if (return$2) {
			return var$3;
		}
	}
	$shouldNotReachHere();
}

$String* RMIConnector$RemoteMBeanServerConnection::getDefaultDomain() {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("getDefaultDomain"_s, ""_s);
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($String, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->getDefaultDomain(this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->getDefaultDomain(this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$StringArray* RMIConnector$RemoteMBeanServerConnection::getDomains() {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("getDomains"_s, ""_s);
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($StringArray, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->getDomains(this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->getDomains(this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$MBeanInfo* RMIConnector$RemoteMBeanServerConnection::getMBeanInfo($ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("getMBeanInfo"_s, $$str({"name="_s, name}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		$var($MBeanInfo, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(var$2, $nc(this->this$0->connection)->getMBeanInfo(name, this->delegationSubject));
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$assign(var$2, $nc(this->this$0->connection)->getMBeanInfo(name, this->delegationSubject));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool RMIConnector$RemoteMBeanServerConnection::isInstanceOf($ObjectName* name, $String* className) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("isInstanceOf"_s, $$str({"name="_s, name, ", className="_s, className}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			try {
				var$2 = $nc(this->this$0->connection)->isInstanceOf(name, className, this->delegationSubject);
				return$1 = true;
				goto $finally;
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				var$2 = $nc(this->this$0->connection)->isInstanceOf(name, className, this->delegationSubject);
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void RMIConnector$RemoteMBeanServerConnection::addNotificationListener($ObjectName* name, $ObjectName* listener, $NotificationFilter* filter, Object$* handback) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("addNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"name="_s, name, ", listener="_s, listener, ", filter="_s, filter, ", handback="_s, handback}));
	}
	$var($MarshalledObject, sFilter, $new($MarshalledObject, filter));
	$var($MarshalledObject, sHandback, $new($MarshalledObject, handback));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->addNotificationListener(name, listener, sFilter, sHandback, this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->addNotificationListener(name, listener, sFilter, sHandback, this->delegationSubject);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void RMIConnector$RemoteMBeanServerConnection::removeNotificationListener($ObjectName* name, $ObjectName* listener) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("removeNotificationListener(ObjectName,ObjectName)"_s, $$str({"name="_s, name, ", listener="_s, listener}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->removeNotificationListener(name, listener, this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->removeNotificationListener(name, listener, this->delegationSubject);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void RMIConnector$RemoteMBeanServerConnection::removeNotificationListener($ObjectName* name, $ObjectName* listener, $NotificationFilter* filter, Object$* handback) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("removeNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"name="_s, name, ", listener="_s, listener, ", filter="_s, filter, ", handback="_s, handback}));
	}
	$var($MarshalledObject, sFilter, $new($MarshalledObject, filter));
	$var($MarshalledObject, sHandback, $new($MarshalledObject, handback));
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->removeNotificationListener(name, listener, sFilter, sHandback, this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->removeNotificationListener(name, listener, sFilter, sHandback, this->delegationSubject);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void RMIConnector$RemoteMBeanServerConnection::addNotificationListener($ObjectName* name, $NotificationListener* listener, $NotificationFilter* filter, Object$* handback) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	bool debug = $nc($RMIConnector::logger)->debugOn();
	if (debug) {
		$nc($RMIConnector::logger)->debug("addNotificationListener(ObjectName,NotificationListener,NotificationFilter,Object)"_s, $$str({"name="_s, name, ", listener="_s, listener, ", filter="_s, filter, ", handback="_s, handback}));
	}
	$var($Integer, listenerID, this->this$0->addListenerWithSubject(name, $$new($MarshalledObject, filter), this->delegationSubject, true));
	$nc(this->this$0->rmiNotifClient)->addNotificationListener(listenerID, name, listener, filter, handback, this->delegationSubject);
}

void RMIConnector$RemoteMBeanServerConnection::removeNotificationListener($ObjectName* name, $NotificationListener* listener) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	bool debug = $nc($RMIConnector::logger)->debugOn();
	if (debug) {
		$nc($RMIConnector::logger)->debug("removeNotificationListener(ObjectName,NotificationListener)"_s, $$str({"name="_s, name, ", listener="_s, listener}));
	}
	$var($IntegerArray, ret, $nc(this->this$0->rmiNotifClient)->getListenerIds(name, listener));
	if (debug) {
		$nc($RMIConnector::logger)->debug("removeNotificationListener"_s, $$str({"listenerIDs="_s, $($RMIConnector::objects(ret))}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->removeNotificationListeners(name, ret, this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->removeNotificationListeners(name, ret, this->delegationSubject);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$nc(this->this$0->rmiNotifClient)->removeNotificationListener(name, listener);
}

void RMIConnector$RemoteMBeanServerConnection::removeNotificationListener($ObjectName* name, $NotificationListener* listener, $NotificationFilter* filter, Object$* handback) {
	$useLocalCurrentObjectStackCache();
	$init($RMIConnector);
	bool debug = $nc($RMIConnector::logger)->debugOn();
	if (debug) {
		$nc($RMIConnector::logger)->debug("removeNotificationListener(ObjectName,NotificationListener,NotificationFilter,Object)"_s, $$str({"name="_s, name, ", listener="_s, listener, ", filter="_s, filter, ", handback="_s, handback}));
	}
	$var($Integer, ret, $nc(this->this$0->rmiNotifClient)->getListenerId(name, listener, filter, handback));
	if (debug) {
		$nc($RMIConnector::logger)->debug("removeNotificationListener"_s, $$str({"listenerID="_s, ret}));
	}
	$var($ClassLoader, old, this->this$0->pushDefaultClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$nc(this->this$0->connection)->removeNotificationListeners(name, $$new($IntegerArray, {ret}), this->delegationSubject);
			} catch ($IOException& ioe) {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
				$nc(this->this$0->connection)->removeNotificationListeners(name, $$new($IntegerArray, {ret}), this->delegationSubject);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			this->this$0->popDefaultClassLoader(old);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$nc(this->this$0->rmiNotifClient)->removeNotificationListener(name, listener, filter, handback);
}

RMIConnector$RemoteMBeanServerConnection::RMIConnector$RemoteMBeanServerConnection() {
}

$Class* RMIConnector$RemoteMBeanServerConnection::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$RemoteMBeanServerConnection, name, initialize, &_RMIConnector$RemoteMBeanServerConnection_ClassInfo_, allocate$RMIConnector$RemoteMBeanServerConnection);
	return class$;
}

$Class* RMIConnector$RemoteMBeanServerConnection::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax