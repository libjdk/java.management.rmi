#include <javax/management/remote/rmi/RMIConnectionImpl.h>

#include <com/sun/jmx/remote/internal/NotificationBuffer.h>
#include <com/sun/jmx/remote/internal/ServerCommunicatorAdmin.h>
#include <com/sun/jmx/remote/internal/ServerNotifForwarder.h>
#include <com/sun/jmx/remote/security/JMXSubjectDomainCombiner.h>
#include <com/sun/jmx/remote/security/SubjectDelegator.h>
#include <com/sun/jmx/remote/util/ClassLoaderWithRepository.h>
#include <com/sun/jmx/remote/util/ClassLogger.h>
#include <com/sun/jmx/remote/util/EnvHelp.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/MarshalledObject.h>
#include <java/rmi/UnmarshalException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/management/Attribute.h>
#include <javax/management/AttributeList.h>
#include <javax/management/AttributeNotFoundException.h>
#include <javax/management/InstanceAlreadyExistsException.h>
#include <javax/management/InstanceNotFoundException.h>
#include <javax/management/IntrospectionException.h>
#include <javax/management/InvalidAttributeValueException.h>
#include <javax/management/ListenerNotFoundException.h>
#include <javax/management/MBeanException.h>
#include <javax/management/MBeanInfo.h>
#include <javax/management/MBeanPermission.h>
#include <javax/management/MBeanRegistrationException.h>
#include <javax/management/MBeanServer.h>
#include <javax/management/NotCompliantMBeanException.h>
#include <javax/management/NotificationFilter.h>
#include <javax/management/ObjectInstance.h>
#include <javax/management/ObjectName.h>
#include <javax/management/QueryExp.h>
#include <javax/management/ReflectionException.h>
#include <javax/management/RuntimeOperationsException.h>
#include <javax/management/loading/ClassLoaderRepository.h>
#include <javax/management/remote/JMXServerErrorException.h>
#include <javax/management/remote/NotificationResult.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$1.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$2.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$3.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$4.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$5.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$6.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$7.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$PrivilegedOperation.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$RMIServerCommunicatorAdmin.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$SetCcl.h>
#include <javax/management/remote/rmi/RMIConnector$Util.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <javax/management/remote/rmi/RMIServerImpl.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

#undef ADD_NOTIFICATION_LISTENERS
#undef ADD_NOTIFICATION_LISTENER_OBJECTNAME
#undef CREATE_MBEAN
#undef CREATE_MBEAN_LOADER
#undef CREATE_MBEAN_LOADER_PARAMS
#undef CREATE_MBEAN_PARAMS
#undef FALSE
#undef GET_ATTRIBUTE
#undef GET_ATTRIBUTES
#undef GET_DEFAULT_DOMAIN
#undef GET_DOMAINS
#undef GET_MBEAN_COUNT
#undef GET_MBEAN_INFO
#undef GET_OBJECT_INSTANCE
#undef INVOKE
#undef IS_INSTANCE_OF
#undef IS_REGISTERED
#undef NO_OBJECTS
#undef NO_STRINGS
#undef QUERY_MBEANS
#undef QUERY_NAMES
#undef REMOVE_NOTIFICATION_LISTENER
#undef REMOVE_NOTIFICATION_LISTENER_OBJECTNAME
#undef REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK
#undef SET_ATTRIBUTE
#undef SET_ATTRIBUTES
#undef TRUE
#undef UNREGISTER_MBEAN

using $IntegerArray = $Array<::java::lang::Integer>;
using $MarshalledObjectArray = $Array<::java::rmi::MarshalledObject>;
using $PermissionArray = $Array<::java::security::Permission>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $NotificationFilterArray = $Array<::javax::management::NotificationFilter>;
using $ObjectNameArray = $Array<::javax::management::ObjectName>;
using $SubjectArray = $Array<::javax::security::auth::Subject>;
using $NotificationBuffer = ::com::sun::jmx::remote::internal::NotificationBuffer;
using $ServerCommunicatorAdmin = ::com::sun::jmx::remote::internal::ServerCommunicatorAdmin;
using $ServerNotifForwarder = ::com::sun::jmx::remote::internal::ServerNotifForwarder;
using $JMXSubjectDomainCombiner = ::com::sun::jmx::remote::security::JMXSubjectDomainCombiner;
using $SubjectDelegator = ::com::sun::jmx::remote::security::SubjectDelegator;
using $ClassLoaderWithRepository = ::com::sun::jmx::remote::util::ClassLoaderWithRepository;
using $ClassLogger = ::com::sun::jmx::remote::util::ClassLogger;
using $EnvHelp = ::com::sun::jmx::remote::util::EnvHelp;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $Unreferenced = ::java::rmi::server::Unreferenced;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Attribute = ::javax::management::Attribute;
using $AttributeList = ::javax::management::AttributeList;
using $AttributeNotFoundException = ::javax::management::AttributeNotFoundException;
using $InstanceAlreadyExistsException = ::javax::management::InstanceAlreadyExistsException;
using $InstanceNotFoundException = ::javax::management::InstanceNotFoundException;
using $IntrospectionException = ::javax::management::IntrospectionException;
using $InvalidAttributeValueException = ::javax::management::InvalidAttributeValueException;
using $ListenerNotFoundException = ::javax::management::ListenerNotFoundException;
using $MBeanException = ::javax::management::MBeanException;
using $MBeanInfo = ::javax::management::MBeanInfo;
using $MBeanPermission = ::javax::management::MBeanPermission;
using $MBeanRegistrationException = ::javax::management::MBeanRegistrationException;
using $MBeanServer = ::javax::management::MBeanServer;
using $NotCompliantMBeanException = ::javax::management::NotCompliantMBeanException;
using $NotificationFilter = ::javax::management::NotificationFilter;
using $ObjectInstance = ::javax::management::ObjectInstance;
using $ObjectName = ::javax::management::ObjectName;
using $QueryExp = ::javax::management::QueryExp;
using $ReflectionException = ::javax::management::ReflectionException;
using $RuntimeOperationsException = ::javax::management::RuntimeOperationsException;
using $ClassLoaderRepository = ::javax::management::loading::ClassLoaderRepository;
using $JMXServerErrorException = ::javax::management::remote::JMXServerErrorException;
using $NotificationResult = ::javax::management::remote::NotificationResult;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIConnectionImpl$1 = ::javax::management::remote::rmi::RMIConnectionImpl$1;
using $RMIConnectionImpl$2 = ::javax::management::remote::rmi::RMIConnectionImpl$2;
using $RMIConnectionImpl$3 = ::javax::management::remote::rmi::RMIConnectionImpl$3;
using $RMIConnectionImpl$4 = ::javax::management::remote::rmi::RMIConnectionImpl$4;
using $RMIConnectionImpl$5 = ::javax::management::remote::rmi::RMIConnectionImpl$5;
using $RMIConnectionImpl$6 = ::javax::management::remote::rmi::RMIConnectionImpl$6;
using $RMIConnectionImpl$7 = ::javax::management::remote::rmi::RMIConnectionImpl$7;
using $RMIConnectionImpl$PrivilegedOperation = ::javax::management::remote::rmi::RMIConnectionImpl$PrivilegedOperation;
using $RMIConnectionImpl$RMIServerCommunicatorAdmin = ::javax::management::remote::rmi::RMIConnectionImpl$RMIServerCommunicatorAdmin;
using $RMIConnectionImpl$SetCcl = ::javax::management::remote::rmi::RMIConnectionImpl$SetCcl;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;
using $RMIConnector$Util = ::javax::management::remote::rmi::RMIConnector$Util;
using $RMIServerImpl = ::javax::management::remote::rmi::RMIServerImpl;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$$Lambda$lambda$unwrap$0 : public $PrivilegedExceptionAction {
	$class(RMIConnectionImpl$$Lambda$lambda$unwrap$0, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$($Class* wrappedClass, $MarshalledObject* mo) {
		this->wrappedClass = wrappedClass;
		$set(this, mo, mo);
	}
	virtual $Object* run() override {
		 return RMIConnectionImpl::lambda$unwrap$0(wrappedClass, mo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RMIConnectionImpl$$Lambda$lambda$unwrap$0>());
	}
	$Class* wrappedClass = nullptr;
	$MarshalledObject* mo = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RMIConnectionImpl$$Lambda$lambda$unwrap$0::fieldInfos[3] = {
	{"wrappedClass", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(RMIConnectionImpl$$Lambda$lambda$unwrap$0, wrappedClass)},
	{"mo", "Ljava/rmi/MarshalledObject;", nullptr, $PUBLIC, $field(RMIConnectionImpl$$Lambda$lambda$unwrap$0, mo)},
	{}
};
$MethodInfo RMIConnectionImpl$$Lambda$lambda$unwrap$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Class;Ljava/rmi/MarshalledObject;)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnectionImpl$$Lambda$lambda$unwrap$0::*)($Class*,$MarshalledObject*)>(&RMIConnectionImpl$$Lambda$lambda$unwrap$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RMIConnectionImpl$$Lambda$lambda$unwrap$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"javax.management.remote.rmi.RMIConnectionImpl$$Lambda$lambda$unwrap$0",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* RMIConnectionImpl$$Lambda$lambda$unwrap$0::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$$Lambda$lambda$unwrap$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RMIConnectionImpl$$Lambda$lambda$unwrap$0::class$ = nullptr;

$FieldInfo _RMIConnectionImpl_FieldInfo_[] = {
	{"NO_OBJECTS", "[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIConnectionImpl, NO_OBJECTS)},
	{"NO_STRINGS", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIConnectionImpl, NO_STRINGS)},
	{"subject", "Ljavax/security/auth/Subject;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, subject)},
	{"subjectDelegator", "Lcom/sun/jmx/remote/security/SubjectDelegator;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, subjectDelegator)},
	{"removeCallerContext", "Z", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, removeCallerContext)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, acc)},
	{"rmiServer", "Ljavax/management/remote/rmi/RMIServerImpl;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, rmiServer)},
	{"mbeanServer", "Ljavax/management/MBeanServer;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, mbeanServer)},
	{"defaultClassLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, defaultClassLoader)},
	{"defaultContextClassLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, defaultContextClassLoader)},
	{"classLoaderWithRepository", "Lcom/sun/jmx/remote/util/ClassLoaderWithRepository;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, classLoaderWithRepository)},
	{"terminated", "Z", nullptr, $PRIVATE, $field(RMIConnectionImpl, terminated)},
	{"connectionId", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, connectionId)},
	{"serverCommunicatorAdmin", "Lcom/sun/jmx/remote/internal/ServerCommunicatorAdmin;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl, serverCommunicatorAdmin)},
	{"ADD_NOTIFICATION_LISTENERS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, ADD_NOTIFICATION_LISTENERS)},
	{"ADD_NOTIFICATION_LISTENER_OBJECTNAME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, ADD_NOTIFICATION_LISTENER_OBJECTNAME)},
	{"CREATE_MBEAN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, CREATE_MBEAN)},
	{"CREATE_MBEAN_PARAMS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, CREATE_MBEAN_PARAMS)},
	{"CREATE_MBEAN_LOADER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, CREATE_MBEAN_LOADER)},
	{"CREATE_MBEAN_LOADER_PARAMS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, CREATE_MBEAN_LOADER_PARAMS)},
	{"GET_ATTRIBUTE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_ATTRIBUTE)},
	{"GET_ATTRIBUTES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_ATTRIBUTES)},
	{"GET_DEFAULT_DOMAIN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_DEFAULT_DOMAIN)},
	{"GET_DOMAINS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_DOMAINS)},
	{"GET_MBEAN_COUNT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_MBEAN_COUNT)},
	{"GET_MBEAN_INFO", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_MBEAN_INFO)},
	{"GET_OBJECT_INSTANCE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, GET_OBJECT_INSTANCE)},
	{"INVOKE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, INVOKE)},
	{"IS_INSTANCE_OF", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, IS_INSTANCE_OF)},
	{"IS_REGISTERED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, IS_REGISTERED)},
	{"QUERY_MBEANS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, QUERY_MBEANS)},
	{"QUERY_NAMES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, QUERY_NAMES)},
	{"REMOVE_NOTIFICATION_LISTENER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, REMOVE_NOTIFICATION_LISTENER)},
	{"REMOVE_NOTIFICATION_LISTENER_OBJECTNAME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, REMOVE_NOTIFICATION_LISTENER_OBJECTNAME)},
	{"REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK)},
	{"SET_ATTRIBUTE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, SET_ATTRIBUTE)},
	{"SET_ATTRIBUTES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, SET_ATTRIBUTES)},
	{"UNREGISTER_MBEAN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectionImpl, UNREGISTER_MBEAN)},
	{"serverNotifForwarder", "Lcom/sun/jmx/remote/internal/ServerNotifForwarder;", nullptr, $PRIVATE, $field(RMIConnectionImpl, serverNotifForwarder)},
	{"env", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;*>;", $PRIVATE, $field(RMIConnectionImpl, env)},
	{"logger", "Lcom/sun/jmx/remote/util/ClassLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIConnectionImpl, logger)},
	{}
};

$MethodInfo _RMIConnectionImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/lang/String;Ljava/lang/ClassLoader;Ljavax/security/auth/Subject;Ljava/util/Map;)V", "(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/lang/String;Ljava/lang/ClassLoader;Ljavax/security/auth/Subject;Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(RMIConnectionImpl::*)($RMIServerImpl*,$String*,$ClassLoader*,$Subject*,$Map*)>(&RMIConnectionImpl::init$))},
	{"addNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"addNotificationListeners", "([Ljavax/management/ObjectName;[Ljava/rmi/MarshalledObject;[Ljavax/security/auth/Subject;)[Ljava/lang/Integer;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"checkNonNull", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($String*,Object$*)>(&RMIConnectionImpl::checkNonNull))},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,javax.management.InstanceNotFoundException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,java.io.IOException"},
	{"createMBean", "(Ljava/lang/String;Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.ReflectionException,javax.management.InstanceAlreadyExistsException,javax.management.MBeanRegistrationException,javax.management.MBeanException,javax.management.NotCompliantMBeanException,javax.management.InstanceNotFoundException,java.io.IOException"},
	{"doOperation", "(I[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(RMIConnectionImpl::*)(int32_t,$ObjectArray*)>(&RMIConnectionImpl::doOperation)), "java.lang.Exception"},
	{"doPrivilegedOperation", "(I[Ljava/lang/Object;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(RMIConnectionImpl::*)(int32_t,$ObjectArray*,$Subject*)>(&RMIConnectionImpl::doPrivilegedOperation)), "java.security.PrivilegedActionException,java.io.IOException"},
	{"extractException", "(Ljava/lang/Exception;)Ljava/lang/Exception;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Exception*(*)($Exception*)>(&RMIConnectionImpl::extractException))},
	{"fetchNotifications", "(JIJ)Ljavax/management/remote/NotificationResult;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getAttribute", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.management.MBeanException,javax.management.AttributeNotFoundException,javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"getAttributes", "(Ljavax/management/ObjectName;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/AttributeList;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"getClassLoader", "(Ljavax/management/ObjectName;)Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $method(static_cast<$ClassLoader*(RMIConnectionImpl::*)($ObjectName*)>(&RMIConnectionImpl::getClassLoader)), "javax.management.InstanceNotFoundException"},
	{"getClassLoaderFor", "(Ljavax/management/ObjectName;)Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $method(static_cast<$ClassLoader*(RMIConnectionImpl::*)($ObjectName*)>(&RMIConnectionImpl::getClassLoaderFor)), "javax.management.InstanceNotFoundException"},
	{"getConnectionId", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getDefaultDomain", "(Ljavax/security/auth/Subject;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getDomains", "(Ljavax/security/auth/Subject;)[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getMBeanCount", "(Ljavax/security/auth/Subject;)Ljava/lang/Integer;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getMBeanInfo", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/MBeanInfo;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.IntrospectionException,javax.management.ReflectionException,java.io.IOException"},
	{"getObjectInstance", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Ljavax/management/ObjectInstance;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"getServerNotifFwd", "()Lcom/sun/jmx/remote/internal/ServerNotifForwarder;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<$ServerNotifForwarder*(RMIConnectionImpl::*)()>(&RMIConnectionImpl::getServerNotifFwd))},
	{"invoke", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljava/rmi/MarshalledObject;[Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.MBeanException,javax.management.ReflectionException,java.io.IOException"},
	{"isInstanceOf", "(Ljavax/management/ObjectName;Ljava/lang/String;Ljavax/security/auth/Subject;)Z", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,java.io.IOException"},
	{"isRegistered", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"lambda$unwrap$0", "(Ljava/lang/Class;Ljava/rmi/MarshalledObject;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Object*(*)($Class*,$MarshalledObject*)>(&RMIConnectionImpl::lambda$unwrap$0)), "java.lang.Exception"},
	{"newIOException", "(Ljava/lang/String;Ljava/lang/Throwable;)Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$IOException*(*)($String*,$Throwable*)>(&RMIConnectionImpl::newIOException))},
	{"nullIsEmpty", "([Ljava/lang/Object;)[Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ObjectArray*(*)($ObjectArray*)>(&RMIConnectionImpl::nullIsEmpty))},
	{"nullIsEmpty", "([Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)($StringArray*)>(&RMIConnectionImpl::nullIsEmpty))},
	{"objects", "([Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($ObjectArray*)>(&RMIConnectionImpl::objects))},
	{"queryMBeans", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set;", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set<Ljavax/management/ObjectInstance;>;", $PUBLIC, nullptr, "java.io.IOException"},
	{"queryNames", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set;", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljava/util/Set<Ljavax/management/ObjectName;>;", $PUBLIC, nullptr, "java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListener", "(Ljavax/management/ObjectName;Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"removeNotificationListeners", "(Ljavax/management/ObjectName;[Ljava/lang/Integer;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException,java.io.IOException"},
	{"setAttribute", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.AttributeNotFoundException,javax.management.InvalidAttributeValueException,javax.management.MBeanException,javax.management.ReflectionException,java.io.IOException"},
	{"setAttributes", "(Ljavax/management/ObjectName;Ljava/rmi/MarshalledObject;Ljavax/security/auth/Subject;)Ljavax/management/AttributeList;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.ReflectionException,java.io.IOException"},
	{"strings", "([Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($StringArray*)>(&RMIConnectionImpl::strings))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unreferenced", "()V", nullptr, $PUBLIC},
	{"unregisterMBean", "(Ljavax/management/ObjectName;Ljavax/security/auth/Subject;)V", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException,javax.management.MBeanRegistrationException,java.io.IOException"},
	{"unwrap", "(Ljava/rmi/MarshalledObject;Ljava/lang/ClassLoader;Ljava/lang/Class;Ljavax/security/auth/Subject;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/rmi/MarshalledObject<*>;Ljava/lang/ClassLoader;Ljava/lang/Class<TT;>;Ljavax/security/auth/Subject;)TT;", $PRIVATE, $method(static_cast<$Object*(RMIConnectionImpl::*)($MarshalledObject*,$ClassLoader*,$Class*,$Subject*)>(&RMIConnectionImpl::unwrap)), "java.io.IOException"},
	{"unwrap", "(Ljava/rmi/MarshalledObject;Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;Ljava/lang/Class;Ljavax/security/auth/Subject;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/rmi/MarshalledObject<*>;Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;Ljava/lang/Class<TT;>;Ljavax/security/auth/Subject;)TT;", $PRIVATE, $method(static_cast<$Object*(RMIConnectionImpl::*)($MarshalledObject*,$ClassLoader*,$ClassLoader*,$Class*,$Subject*)>(&RMIConnectionImpl::unwrap)), "java.io.IOException"},
	{"withPermissions", "([Ljava/security/Permission;)Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $method(static_cast<$AccessControlContext*(*)($PermissionArray*)>(&RMIConnectionImpl::withPermissions))},
	{}
};

$InnerClassInfo _RMIConnectionImpl_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader", "javax.management.remote.rmi.RMIConnectionImpl", "CombinedClassLoader", $PRIVATE | $STATIC | $FINAL},
	{"javax.management.remote.rmi.RMIConnectionImpl$SetCcl", "javax.management.remote.rmi.RMIConnectionImpl", "SetCcl", $PRIVATE | $STATIC},
	{"javax.management.remote.rmi.RMIConnectionImpl$RMIServerCommunicatorAdmin", "javax.management.remote.rmi.RMIConnectionImpl", "RMIServerCommunicatorAdmin", $PRIVATE},
	{"javax.management.remote.rmi.RMIConnectionImpl$PrivilegedOperation", "javax.management.remote.rmi.RMIConnectionImpl", "PrivilegedOperation", $PRIVATE},
	{"javax.management.remote.rmi.RMIConnectionImpl$7", nullptr, nullptr, 0},
	{"javax.management.remote.rmi.RMIConnectionImpl$6", nullptr, nullptr, 0},
	{"javax.management.remote.rmi.RMIConnectionImpl$5", nullptr, nullptr, 0},
	{"javax.management.remote.rmi.RMIConnectionImpl$4", nullptr, nullptr, 0},
	{"javax.management.remote.rmi.RMIConnectionImpl$3", nullptr, nullptr, 0},
	{"javax.management.remote.rmi.RMIConnectionImpl$2", nullptr, nullptr, 0},
	{"javax.management.remote.rmi.RMIConnectionImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl",
	"java.lang.Object",
	"javax.management.remote.rmi.RMIConnection,java.rmi.server.Unreferenced",
	_RMIConnectionImpl_FieldInfo_,
	_RMIConnectionImpl_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnectionImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader,javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper,javax.management.remote.rmi.RMIConnectionImpl$SetCcl,javax.management.remote.rmi.RMIConnectionImpl$RMIServerCommunicatorAdmin,javax.management.remote.rmi.RMIConnectionImpl$PrivilegedOperation,javax.management.remote.rmi.RMIConnectionImpl$7,javax.management.remote.rmi.RMIConnectionImpl$6,javax.management.remote.rmi.RMIConnectionImpl$5,javax.management.remote.rmi.RMIConnectionImpl$4,javax.management.remote.rmi.RMIConnectionImpl$3,javax.management.remote.rmi.RMIConnectionImpl$2,javax.management.remote.rmi.RMIConnectionImpl$1"
};

$Object* allocate$RMIConnectionImpl($Class* clazz) {
	return $of($alloc(RMIConnectionImpl));
}

int32_t RMIConnectionImpl::hashCode() {
	 return this->$RMIConnection::hashCode();
}

bool RMIConnectionImpl::equals(Object$* arg0) {
	 return this->$RMIConnection::equals(arg0);
}

$Object* RMIConnectionImpl::clone() {
	 return this->$RMIConnection::clone();
}

void RMIConnectionImpl::finalize() {
	this->$RMIConnection::finalize();
}

$ObjectArray* RMIConnectionImpl::NO_OBJECTS = nullptr;
$StringArray* RMIConnectionImpl::NO_STRINGS = nullptr;
$ClassLogger* RMIConnectionImpl::logger = nullptr;

void RMIConnectionImpl::init$($RMIServerImpl* rmiServer, $String* connectionId, $ClassLoader* defaultClassLoader, $Subject* subject, $Map* env$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Map, env, env$renamed);
	$beforeCallerSensitive();
	this->terminated = false;
	if (rmiServer == nullptr || connectionId == nullptr) {
		$throwNew($NullPointerException, "Illegal null argument"_s);
	}
	if (env == nullptr) {
		$assign(env, $Collections::emptyMap());
	}
	$set(this, rmiServer, rmiServer);
	$set(this, connectionId, connectionId);
	$set(this, defaultClassLoader, defaultClassLoader);
	$set(this, subjectDelegator, $new($SubjectDelegator));
	$set(this, subject, subject);
	if (subject == nullptr) {
		$set(this, acc, nullptr);
		this->removeCallerContext = false;
	} else {
		this->removeCallerContext = $SubjectDelegator::checkRemoveCallerContext(subject);
		if (this->removeCallerContext) {
			$set(this, acc, $JMXSubjectDomainCombiner::getDomainCombinerContext(subject));
		} else {
			$set(this, acc, $JMXSubjectDomainCombiner::getContext(subject));
		}
	}
	$set(this, mbeanServer, $nc(rmiServer)->getMBeanServer());
	$var($ClassLoader, dcl, defaultClassLoader);
	$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new($RMIConnectionImpl$1, this)));
	$var($ClassLoaderRepository, repository, $cast($ClassLoaderRepository, $AccessController::doPrivileged(var$0, $(withPermissions($$new($PermissionArray, {static_cast<$Permission*>($$new($MBeanPermission, "*"_s, "getClassLoaderRepository"_s))}))))));
	$var($PrivilegedAction, var$1, static_cast<$PrivilegedAction*>($new($RMIConnectionImpl$2, this, repository, dcl)));
	$set(this, classLoaderWithRepository, $cast($ClassLoaderWithRepository, $AccessController::doPrivileged(var$1, $(withPermissions($$new($PermissionArray, {static_cast<$Permission*>($$new($RuntimePermission, "createClassLoader"_s))}))))));
	$set(this, defaultContextClassLoader, $cast($ClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RMIConnectionImpl$3, this, dcl)))));
	$set(this, serverCommunicatorAdmin, $new($RMIConnectionImpl$RMIServerCommunicatorAdmin, this, $EnvHelp::getServerConnectionTimeout(env)));
	$set(this, env, env);
}

$AccessControlContext* RMIConnectionImpl::withPermissions($PermissionArray* perms) {
	$init(RMIConnectionImpl);
	$useLocalCurrentObjectStackCache();
	$var($Permissions, col, $new($Permissions));
	{
		$var($PermissionArray, arr$, perms);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Permission, thePerm, arr$->get(i$));
			{
				col->add(thePerm);
			}
		}
	}
	$var($ProtectionDomain, pd, $new($ProtectionDomain, nullptr, col));
	return $new($AccessControlContext, $$new($ProtectionDomainArray, {pd}));
}

$ServerNotifForwarder* RMIConnectionImpl::getServerNotifFwd() {
	$synchronized(this) {
		if (this->serverNotifForwarder == nullptr) {
			$set(this, serverNotifForwarder, $new($ServerNotifForwarder, this->mbeanServer, this->env, $($nc(this->rmiServer)->getNotifBuffer()), this->connectionId));
		}
		return this->serverNotifForwarder;
	}
}

$String* RMIConnectionImpl::getConnectionId() {
	return this->connectionId;
}

void RMIConnectionImpl::close() {
	$useLocalCurrentObjectStackCache();
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	$var($String, idstr, debug ? $str({"["_s, $(this->toString()), "]"_s}) : ($String*)nullptr);
	$synchronized(this) {
		if (this->terminated) {
			if (debug) {
				$nc(RMIConnectionImpl::logger)->debug("close"_s, $$str({idstr, " already terminated."_s}));
			}
			return;
		}
		if (debug) {
			$nc(RMIConnectionImpl::logger)->debug("close"_s, $$str({idstr, " closing."_s}));
		}
		this->terminated = true;
		if (this->serverCommunicatorAdmin != nullptr) {
			$nc(this->serverCommunicatorAdmin)->terminate();
		}
		if (this->serverNotifForwarder != nullptr) {
			$nc(this->serverNotifForwarder)->terminate();
		}
	}
	$nc(this->rmiServer)->clientClosed(this);
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("close"_s, $$str({idstr, " closed."_s}));
	}
}

void RMIConnectionImpl::unreferenced() {
	$nc(RMIConnectionImpl::logger)->debug("unreferenced"_s, "called"_s);
	try {
		close();
		$nc(RMIConnectionImpl::logger)->debug("unreferenced"_s, "done"_s);
	} catch ($IOException& e) {
		$nc(RMIConnectionImpl::logger)->fine("unreferenced"_s, static_cast<$Throwable*>(e));
	}
}

$ObjectInstance* RMIConnectionImpl::createMBean($String* className, $ObjectName* name, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(className),
			$of(name)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("createMBean(String,ObjectName)"_s, $$str({"connectionId="_s, this->connectionId, ", className="_s, className, ", name="_s, name}));
		}
		return $cast($ObjectInstance, doPrivilegedOperation(RMIConnectionImpl::CREATE_MBEAN, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($InstanceAlreadyExistsException, e)) {
			$throw($cast($InstanceAlreadyExistsException, e));
		}
		if ($instanceOf($MBeanRegistrationException, e)) {
			$throw($cast($MBeanRegistrationException, e));
		}
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($NotCompliantMBeanException, e)) {
			$throw($cast($NotCompliantMBeanException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl::createMBean($String* className, $ObjectName* name, $ObjectName* loaderName, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(className),
			$of(name),
			$of(loaderName)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("createMBean(String,ObjectName,ObjectName)"_s, $$str({"connectionId="_s, this->connectionId, ", className="_s, className, ", name="_s, name, ", loaderName="_s, loaderName}));
		}
		return $cast($ObjectInstance, doPrivilegedOperation(RMIConnectionImpl::CREATE_MBEAN_LOADER, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($InstanceAlreadyExistsException, e)) {
			$throw($cast($InstanceAlreadyExistsException, e));
		}
		if ($instanceOf($MBeanRegistrationException, e)) {
			$throw($cast($MBeanRegistrationException, e));
		}
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($NotCompliantMBeanException, e)) {
			$throw($cast($NotCompliantMBeanException, e));
		}
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl::createMBean($String* className, $ObjectName* name, $MarshalledObject* params, $StringArray* signature, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, values, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("createMBean(String,ObjectName,Object[],String[])"_s, $$str({"connectionId="_s, this->connectionId, ", unwrapping parameters using classLoaderWithRepository."_s}));
	}
	$load($ObjectArray);
	$assign(values, nullIsEmpty($cast($ObjectArray, $(unwrap(params, this->classLoaderWithRepository, $getClass($ObjectArray), delegationSubject)))));
	try {
		$var($ObjectArray, params2, $new($ObjectArray, {
			$of(className),
			$of(name),
			$of(values),
			$($of(nullIsEmpty(signature)))
		}));
		if (debug) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", className="_s, className, ", name="_s, name, ", signature="_s}));
			$nc(RMIConnectionImpl::logger)->debug("createMBean(String,ObjectName,Object[],String[])"_s, $$concat(var$0, $(strings(signature))));
		}
		return $cast($ObjectInstance, doPrivilegedOperation(RMIConnectionImpl::CREATE_MBEAN_PARAMS, params2, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($InstanceAlreadyExistsException, e)) {
			$throw($cast($InstanceAlreadyExistsException, e));
		}
		if ($instanceOf($MBeanRegistrationException, e)) {
			$throw($cast($MBeanRegistrationException, e));
		}
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($NotCompliantMBeanException, e)) {
			$throw($cast($NotCompliantMBeanException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$ObjectInstance* RMIConnectionImpl::createMBean($String* className, $ObjectName* name, $ObjectName* loaderName, $MarshalledObject* params, $StringArray* signature, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, values, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("createMBean(String,ObjectName,ObjectName,Object[],String[])"_s, $$str({"connectionId="_s, this->connectionId, ", unwrapping params with MBean extended ClassLoader."_s}));
	}
	$load($ObjectArray);
	$assign(values, nullIsEmpty($cast($ObjectArray, $(unwrap(params, $(getClassLoader(loaderName)), this->defaultClassLoader, $getClass($ObjectArray), delegationSubject)))));
	try {
		$var($ObjectArray, params2, $new($ObjectArray, {
			$of(className),
			$of(name),
			$of(loaderName),
			$of(values),
			$($of(nullIsEmpty(signature)))
		}));
		if (debug) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", className="_s, className, ", name="_s, name, ", loaderName="_s, loaderName, ", signature="_s}));
			$nc(RMIConnectionImpl::logger)->debug("createMBean(String,ObjectName,ObjectName,Object[],String[])"_s, $$concat(var$0, $(strings(signature))));
		}
		return $cast($ObjectInstance, doPrivilegedOperation(RMIConnectionImpl::CREATE_MBEAN_LOADER_PARAMS, params2, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($InstanceAlreadyExistsException, e)) {
			$throw($cast($InstanceAlreadyExistsException, e));
		}
		if ($instanceOf($MBeanRegistrationException, e)) {
			$throw($cast($MBeanRegistrationException, e));
		}
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($NotCompliantMBeanException, e)) {
			$throw($cast($NotCompliantMBeanException, e));
		}
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

void RMIConnectionImpl::unregisterMBean($ObjectName* name, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, {$of(name)}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("unregisterMBean"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name}));
		}
		doPrivilegedOperation(RMIConnectionImpl::UNREGISTER_MBEAN, params, delegationSubject);
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($MBeanRegistrationException, e)) {
			$throw($cast($MBeanRegistrationException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
}

$ObjectInstance* RMIConnectionImpl::getObjectInstance($ObjectName* name, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("ObjectName"_s, name);
	try {
		$var($ObjectArray, params, $new($ObjectArray, {$of(name)}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("getObjectInstance"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name}));
		}
		return $cast($ObjectInstance, doPrivilegedOperation(RMIConnectionImpl::GET_OBJECT_INSTANCE, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$Set* RMIConnectionImpl::queryMBeans($ObjectName* name, $MarshalledObject* query, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$var($QueryExp, queryValue, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("queryMBeans"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping query with defaultClassLoader."_s}));
	}
	$load($QueryExp);
	$assign(queryValue, $cast($QueryExp, unwrap(query, this->defaultContextClassLoader, $QueryExp::class$, delegationSubject)));
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(queryValue)
		}));
		if (debug) {
			$nc(RMIConnectionImpl::logger)->debug("queryMBeans"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", query="_s, query}));
		}
		return $cast($Set, $RMIConnector$Util::cast($(doPrivilegedOperation(RMIConnectionImpl::QUERY_MBEANS, params, delegationSubject))));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$Set* RMIConnectionImpl::queryNames($ObjectName* name, $MarshalledObject* query, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$var($QueryExp, queryValue, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("queryNames"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping query with defaultClassLoader."_s}));
	}
	$load($QueryExp);
	$assign(queryValue, $cast($QueryExp, unwrap(query, this->defaultContextClassLoader, $QueryExp::class$, delegationSubject)));
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(queryValue)
		}));
		if (debug) {
			$nc(RMIConnectionImpl::logger)->debug("queryNames"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", query="_s, query}));
		}
		return $cast($Set, $RMIConnector$Util::cast($(doPrivilegedOperation(RMIConnectionImpl::QUERY_NAMES, params, delegationSubject))));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

bool RMIConnectionImpl::isRegistered($ObjectName* name, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, {$of(name)}));
		return $nc(($cast($Boolean, $(doPrivilegedOperation(RMIConnectionImpl::IS_REGISTERED, params, delegationSubject)))))->booleanValue();
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$Integer* RMIConnectionImpl::getMBeanCount($Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, 0));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("getMBeanCount"_s, $$str({"connectionId="_s, this->connectionId}));
		}
		return $cast($Integer, doPrivilegedOperation(RMIConnectionImpl::GET_MBEAN_COUNT, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$Object* RMIConnectionImpl::getAttribute($ObjectName* name, $String* attribute, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(attribute)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("getAttribute"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", attribute="_s, attribute}));
		}
		return $of(doPrivilegedOperation(RMIConnectionImpl::GET_ATTRIBUTE, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($AttributeNotFoundException, e)) {
			$throw($cast($AttributeNotFoundException, e));
		}
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$AttributeList* RMIConnectionImpl::getAttributes($ObjectName* name, $StringArray* attributes, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(attributes)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", attributes="_s}));
			$nc(RMIConnectionImpl::logger)->debug("getAttributes"_s, $$concat(var$0, $(strings(attributes))));
		}
		return $cast($AttributeList, doPrivilegedOperation(RMIConnectionImpl::GET_ATTRIBUTES, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

void RMIConnectionImpl::setAttribute($ObjectName* name, $MarshalledObject* attribute, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$var($Attribute, attr, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("setAttribute"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping attribute with MBean extended ClassLoader."_s}));
	}
	$load($Attribute);
	$assign(attr, $cast($Attribute, unwrap(attribute, $(getClassLoaderFor(name)), this->defaultClassLoader, $Attribute::class$, delegationSubject)));
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(attr)
		}));
		if (debug) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", attribute name="_s}));
			$nc(RMIConnectionImpl::logger)->debug("setAttribute"_s, $$concat(var$0, $($nc(attr)->getName())));
		}
		doPrivilegedOperation(RMIConnectionImpl::SET_ATTRIBUTE, params, delegationSubject);
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($AttributeNotFoundException, e)) {
			$throw($cast($AttributeNotFoundException, e));
		}
		if ($instanceOf($InvalidAttributeValueException, e)) {
			$throw($cast($InvalidAttributeValueException, e));
		}
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
}

$AttributeList* RMIConnectionImpl::setAttributes($ObjectName* name, $MarshalledObject* attributes, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$var($AttributeList, attrlist, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("setAttributes"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping attributes with MBean extended ClassLoader."_s}));
	}
	$load($AttributeList);
	$assign(attrlist, $cast($AttributeList, unwrap(attributes, $(getClassLoaderFor(name)), this->defaultClassLoader, $AttributeList::class$, delegationSubject)));
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(attrlist)
		}));
		if (debug) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", attribute names="_s}));
			$nc(RMIConnectionImpl::logger)->debug("setAttributes"_s, $$concat(var$0, $($RMIConnector::getAttributesNames(attrlist))));
		}
		return $cast($AttributeList, doPrivilegedOperation(RMIConnectionImpl::SET_ATTRIBUTES, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$Object* RMIConnectionImpl::invoke($ObjectName* name, $String* operationName, $MarshalledObject* params, $StringArray* signature, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("ObjectName"_s, name);
	checkNonNull("Operation name"_s, operationName);
	$var($ObjectArray, values, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("invoke"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping params with MBean extended ClassLoader."_s}));
	}
	$load($ObjectArray);
	$assign(values, nullIsEmpty($cast($ObjectArray, $(unwrap(params, $(getClassLoaderFor(name)), this->defaultClassLoader, $getClass($ObjectArray), delegationSubject)))));
	try {
		$var($ObjectArray, params2, $new($ObjectArray, {
			$of(name),
			$of(operationName),
			$of(values),
			$($of(nullIsEmpty(signature)))
		}));
		if (debug) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", operationName="_s, operationName, ", signature="_s}));
			$nc(RMIConnectionImpl::logger)->debug("invoke"_s, $$concat(var$0, $(strings(signature))));
		}
		return $of(doPrivilegedOperation(RMIConnectionImpl::INVOKE, params2, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($MBeanException, e)) {
			$throw($cast($MBeanException, e));
		}
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$String* RMIConnectionImpl::getDefaultDomain($Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, 0));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("getDefaultDomain"_s, $$str({"connectionId="_s, this->connectionId}));
		}
		return $cast($String, doPrivilegedOperation(RMIConnectionImpl::GET_DEFAULT_DOMAIN, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$StringArray* RMIConnectionImpl::getDomains($Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ObjectArray, params, $new($ObjectArray, 0));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("getDomains"_s, $$str({"connectionId="_s, this->connectionId}));
		}
		return $cast($StringArray, doPrivilegedOperation(RMIConnectionImpl::GET_DOMAINS, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$MBeanInfo* RMIConnectionImpl::getMBeanInfo($ObjectName* name, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("ObjectName"_s, name);
	try {
		$var($ObjectArray, params, $new($ObjectArray, {$of(name)}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("getMBeanInfo"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name}));
		}
		return $cast($MBeanInfo, doPrivilegedOperation(RMIConnectionImpl::GET_MBEAN_INFO, params, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($IntrospectionException, e)) {
			$throw($cast($IntrospectionException, e));
		}
		if ($instanceOf($ReflectionException, e)) {
			$throw($cast($ReflectionException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

bool RMIConnectionImpl::isInstanceOf($ObjectName* name, $String* className, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("ObjectName"_s, name);
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(className)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("isInstanceOf"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", className="_s, className}));
		}
		return $nc(($cast($Boolean, $(doPrivilegedOperation(RMIConnectionImpl::IS_INSTANCE_OF, params, delegationSubject)))))->booleanValue();
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
	$shouldNotReachHere();
}

$IntegerArray* RMIConnectionImpl::addNotificationListeners($ObjectNameArray* names, $MarshalledObjectArray* filters, $SubjectArray* delegationSubjects) {
	$useLocalCurrentObjectStackCache();
	if (names == nullptr || filters == nullptr) {
		$throwNew($IllegalArgumentException, "Got null arguments."_s);
	}
	$var($SubjectArray, sbjs, (delegationSubjects != nullptr) ? delegationSubjects : $new($SubjectArray, $nc(names)->length));
	if (names->length != $nc(filters)->length || $nc(filters)->length != $nc(sbjs)->length) {
		$var($String, msg, "The value lengths of 3 parameters are not same."_s);
		$throwNew($IllegalArgumentException, msg);
	}
	for (int32_t i = 0; i < names->length; ++i) {
		if (names->get(i) == nullptr) {
			$throwNew($IllegalArgumentException, "Null Object name."_s);
		}
	}
	int32_t i = 0;
	$var($ClassLoader, targetCl, nullptr);
	$var($NotificationFilterArray, filterValues, $new($NotificationFilterArray, names->length));
	$var($IntegerArray, ids, $new($IntegerArray, names->length));
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	try {
		for (; i < names->length; ++i) {
			$assign(targetCl, getClassLoaderFor(names->get(i)));
			if (debug) {
				$nc(RMIConnectionImpl::logger)->debug("addNotificationListener(ObjectName,NotificationFilter)"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping filter with target extended ClassLoader."_s}));
			}
			$load($NotificationFilter);
			filterValues->set(i, $cast($NotificationFilter, $(unwrap($nc(filters)->get(i), targetCl, this->defaultClassLoader, $NotificationFilter::class$, $nc(sbjs)->get(i)))));
			if (debug) {
				$nc(RMIConnectionImpl::logger)->debug("addNotificationListener(ObjectName,NotificationFilter)"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, names->get(i), ", filter="_s, filterValues->get(i)}));
			}
			ids->set(i, $cast($Integer, $(doPrivilegedOperation(RMIConnectionImpl::ADD_NOTIFICATION_LISTENERS, $$new($ObjectArray, {
				$of(names->get(i)),
				$of(filterValues->get(i))
			}), $nc(sbjs)->get(i)))));
		}
		return ids;
	} catch ($Exception& e) {
		for (int32_t j = 0; j < i; ++j) {
			try {
				$nc($(getServerNotifFwd()))->removeNotificationListener(names->get(j), ids->get(j));
			} catch ($Exception& eee) {
			}
		}
		if ($instanceOf($PrivilegedActionException, e)) {
			$assign(e, extractException(e));
		}
		if ($instanceOf($ClassCastException, e)) {
			$throw($cast($ClassCastException, e));
		} else if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		} else if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		} else if ($instanceOf($RuntimeException, e)) {
			$throw($cast($RuntimeException, e));
		} else {
			$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
		}
	}
	$shouldNotReachHere();
}

void RMIConnectionImpl::addNotificationListener($ObjectName* name, $ObjectName* listener, $MarshalledObject* filter, $MarshalledObject* handback, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("Target MBean name"_s, name);
	checkNonNull("Listener MBean name"_s, listener);
	$var($NotificationFilter, filterValue, nullptr);
	$var($Object, handbackValue, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	$var($ClassLoader, targetCl, getClassLoaderFor(name));
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("addNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping filter with target extended ClassLoader."_s}));
	}
	$load($NotificationFilter);
	$assign(filterValue, $cast($NotificationFilter, unwrap(filter, targetCl, this->defaultClassLoader, $NotificationFilter::class$, delegationSubject)));
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("addNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping handback with target extended ClassLoader."_s}));
	}
	$assign(handbackValue, unwrap(handback, targetCl, this->defaultClassLoader, $Object::class$, delegationSubject));
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(listener),
			$of(filterValue),
			handbackValue
		}));
		if (debug) {
			$nc(RMIConnectionImpl::logger)->debug("addNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", listenerName="_s, listener, ", filter="_s, filterValue, ", handback="_s, handbackValue}));
		}
		doPrivilegedOperation(RMIConnectionImpl::ADD_NOTIFICATION_LISTENER_OBJECTNAME, params, delegationSubject);
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
}

void RMIConnectionImpl::removeNotificationListeners($ObjectName* name, $IntegerArray* listenerIDs, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	if (name == nullptr || listenerIDs == nullptr) {
		$throwNew($IllegalArgumentException, "Illegal null parameter"_s);
	}
	for (int32_t i = 0; i < $nc(listenerIDs)->length; ++i) {
		if (listenerIDs->get(i) == nullptr) {
			$throwNew($IllegalArgumentException, "Null listener ID"_s);
		}
	}
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(listenerIDs)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$var($String, var$0, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", listenerIDs="_s}));
			$nc(RMIConnectionImpl::logger)->debug("removeNotificationListener(ObjectName,Integer[])"_s, $$concat(var$0, $(objects(listenerIDs))));
		}
		doPrivilegedOperation(RMIConnectionImpl::REMOVE_NOTIFICATION_LISTENER, params, delegationSubject);
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($ListenerNotFoundException, e)) {
			$throw($cast($ListenerNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
}

void RMIConnectionImpl::removeNotificationListener($ObjectName* name, $ObjectName* listener, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("Target MBean name"_s, name);
	checkNonNull("Listener MBean name"_s, listener);
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(listener)
		}));
		if ($nc(RMIConnectionImpl::logger)->debugOn()) {
			$nc(RMIConnectionImpl::logger)->debug("removeNotificationListener(ObjectName,ObjectName)"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", listenerName="_s, listener}));
		}
		doPrivilegedOperation(RMIConnectionImpl::REMOVE_NOTIFICATION_LISTENER_OBJECTNAME, params, delegationSubject);
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($ListenerNotFoundException, e)) {
			$throw($cast($ListenerNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
}

void RMIConnectionImpl::removeNotificationListener($ObjectName* name, $ObjectName* listener, $MarshalledObject* filter, $MarshalledObject* handback, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	checkNonNull("Target MBean name"_s, name);
	checkNonNull("Listener MBean name"_s, listener);
	$var($NotificationFilter, filterValue, nullptr);
	$var($Object, handbackValue, nullptr);
	bool debug = $nc(RMIConnectionImpl::logger)->debugOn();
	$var($ClassLoader, targetCl, getClassLoaderFor(name));
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("removeNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping filter with target extended ClassLoader."_s}));
	}
	$load($NotificationFilter);
	$assign(filterValue, $cast($NotificationFilter, unwrap(filter, targetCl, this->defaultClassLoader, $NotificationFilter::class$, delegationSubject)));
	if (debug) {
		$nc(RMIConnectionImpl::logger)->debug("removeNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"connectionId="_s, this->connectionId, " unwrapping handback with target extended ClassLoader."_s}));
	}
	$assign(handbackValue, unwrap(handback, targetCl, this->defaultClassLoader, $Object::class$, delegationSubject));
	try {
		$var($ObjectArray, params, $new($ObjectArray, {
			$of(name),
			$of(listener),
			$of(filterValue),
			handbackValue
		}));
		if (debug) {
			$nc(RMIConnectionImpl::logger)->debug("removeNotificationListener(ObjectName,ObjectName,NotificationFilter,Object)"_s, $$str({"connectionId="_s, this->connectionId, ", name="_s, name, ", listenerName="_s, listener, ", filter="_s, filterValue, ", handback="_s, handbackValue}));
		}
		doPrivilegedOperation(RMIConnectionImpl::REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK, params, delegationSubject);
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($InstanceNotFoundException, e)) {
			$throw($cast($InstanceNotFoundException, e));
		}
		if ($instanceOf($ListenerNotFoundException, e)) {
			$throw($cast($ListenerNotFoundException, e));
		}
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		$throw($(newIOException($$str({"Got unexpected server exception: "_s, e}), e)));
	}
}

$NotificationResult* RMIConnectionImpl::fetchNotifications(int64_t clientSequenceNumber, int32_t maxNotifications, int64_t timeout) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(RMIConnectionImpl::logger)->debugOn()) {
		$nc(RMIConnectionImpl::logger)->debug("fetchNotifications"_s, $$str({"connectionId="_s, this->connectionId, ", timeout="_s, $$str(timeout)}));
	}
	if (maxNotifications < 0 || timeout < 0) {
		$throwNew($IllegalArgumentException, "Illegal negative argument"_s);
	}
	bool serverTerminated = $nc(this->serverCommunicatorAdmin)->reqIncoming();
	{
		$var($Throwable, var$0, nullptr);
		$var($NotificationResult, var$2, nullptr);
		bool return$1 = false;
		try {
			if (serverTerminated) {
				if ($nc(RMIConnectionImpl::logger)->debugOn()) {
					$nc(RMIConnectionImpl::logger)->debug("fetchNotifications"_s, "The notification server has been closed, returns null to force the client to stop fetching"_s);
				}
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			int64_t csn = clientSequenceNumber;
			int32_t mn = maxNotifications;
			int64_t t = timeout;
			$var($PrivilegedAction, action, $new($RMIConnectionImpl$4, this, csn, t, mn));
			if (this->acc == nullptr) {
				$assign(var$2, $cast($NotificationResult, action->run()));
				return$1 = true;
				goto $finally;
			} else {
				$assign(var$2, $cast($NotificationResult, $AccessController::doPrivileged(action, this->acc)));
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->serverCommunicatorAdmin)->rspOutgoing();
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

$String* RMIConnectionImpl::toString() {
	return $str({$($RMIConnection::toString()), ": connectionId="_s, this->connectionId});
}

$ClassLoader* RMIConnectionImpl::getClassLoader($ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($RMIConnectionImpl$5, this, name)));
		return $cast($ClassLoader, $AccessController::doPrivileged(var$0, $(withPermissions($$new($PermissionArray, {static_cast<$Permission*>($$new($MBeanPermission, "*"_s, "getClassLoader"_s))})))));
	} catch ($PrivilegedActionException& pe) {
		$throw($cast($InstanceNotFoundException, $(extractException(pe))));
	}
	$shouldNotReachHere();
}

$ClassLoader* RMIConnectionImpl::getClassLoaderFor($ObjectName* name) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($RMIConnectionImpl$6, this, name)));
		return $cast($ClassLoader, $AccessController::doPrivileged(var$0, $(withPermissions($$new($PermissionArray, {static_cast<$Permission*>($$new($MBeanPermission, "*"_s, "getClassLoaderFor"_s))})))));
	} catch ($PrivilegedActionException& pe) {
		$throw($cast($InstanceNotFoundException, $(extractException(pe))));
	}
	$shouldNotReachHere();
}

$Object* RMIConnectionImpl::doPrivilegedOperation(int32_t operation, $ObjectArray* params, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc(this->serverCommunicatorAdmin)->reqIncoming();
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($AccessControlContext, reqACC, nullptr);
				if (delegationSubject == nullptr) {
					$assign(reqACC, this->acc);
				} else {
					if (this->subject == nullptr) {
						$var($String, msg, "Subject delegation cannot be enabled unless an authenticated subject is put in place"_s);
						$throwNew($SecurityException, msg);
					}
					$assign(reqACC, $nc(this->subjectDelegator)->delegatedContext(this->acc, delegationSubject, this->removeCallerContext));
				}
				$var($RMIConnectionImpl$PrivilegedOperation, op, $new($RMIConnectionImpl$PrivilegedOperation, this, operation, params));
				if (reqACC == nullptr) {
					try {
						return $of(op->run());
					} catch ($Exception& e) {
						if ($instanceOf($RuntimeException, e)) {
							$throw($cast($RuntimeException, e));
						}
						$throwNew($PrivilegedActionException, e);
					}
				} else {
					$assign(var$2, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>(op), reqACC));
					return$1 = true;
					goto $finally;
				}
			} catch ($Error& e) {
				$throwNew($JMXServerErrorException, $(e->toString()), e);
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->serverCommunicatorAdmin)->rspOutgoing();
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

$Object* RMIConnectionImpl::doOperation(int32_t operation, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	switch (operation) {
	case RMIConnectionImpl::CREATE_MBEAN:
		{
			return $of($nc(this->mbeanServer)->createMBean($cast($String, $nc(params)->get(0)), $cast($ObjectName, params->get(1))));
		}
	case RMIConnectionImpl::CREATE_MBEAN_LOADER:
		{
			return $of($nc(this->mbeanServer)->createMBean($cast($String, $nc(params)->get(0)), $cast($ObjectName, params->get(1)), $cast($ObjectName, params->get(2))));
		}
	case RMIConnectionImpl::CREATE_MBEAN_PARAMS:
		{
			return $of($nc(this->mbeanServer)->createMBean($cast($String, $nc(params)->get(0)), $cast($ObjectName, params->get(1)), $cast($ObjectArray, params->get(2)), $cast($StringArray, params->get(3))));
		}
	case RMIConnectionImpl::CREATE_MBEAN_LOADER_PARAMS:
		{
			return $of($nc(this->mbeanServer)->createMBean($cast($String, $nc(params)->get(0)), $cast($ObjectName, params->get(1)), $cast($ObjectName, params->get(2)), $cast($ObjectArray, params->get(3)), $cast($StringArray, params->get(4))));
		}
	case RMIConnectionImpl::GET_ATTRIBUTE:
		{
			return $of($nc(this->mbeanServer)->getAttribute($cast($ObjectName, $nc(params)->get(0)), $cast($String, params->get(1))));
		}
	case RMIConnectionImpl::GET_ATTRIBUTES:
		{
			return $of($nc(this->mbeanServer)->getAttributes($cast($ObjectName, $nc(params)->get(0)), $cast($StringArray, params->get(1))));
		}
	case RMIConnectionImpl::GET_DEFAULT_DOMAIN:
		{
			return $of($nc(this->mbeanServer)->getDefaultDomain());
		}
	case RMIConnectionImpl::GET_DOMAINS:
		{
			return $of($nc(this->mbeanServer)->getDomains());
		}
	case RMIConnectionImpl::GET_MBEAN_COUNT:
		{
			return $of($nc(this->mbeanServer)->getMBeanCount());
		}
	case RMIConnectionImpl::GET_MBEAN_INFO:
		{
			return $of($nc(this->mbeanServer)->getMBeanInfo($cast($ObjectName, $nc(params)->get(0))));
		}
	case RMIConnectionImpl::GET_OBJECT_INSTANCE:
		{
			return $of($nc(this->mbeanServer)->getObjectInstance($cast($ObjectName, $nc(params)->get(0))));
		}
	case RMIConnectionImpl::INVOKE:
		{
			return $of($nc(this->mbeanServer)->invoke($cast($ObjectName, $nc(params)->get(0)), $cast($String, params->get(1)), $cast($ObjectArray, params->get(2)), $cast($StringArray, params->get(3))));
		}
	case RMIConnectionImpl::IS_INSTANCE_OF:
		{
			$init($Boolean);
			return $of($nc(this->mbeanServer)->isInstanceOf($cast($ObjectName, $nc(params)->get(0)), $cast($String, params->get(1))) ? $Boolean::TRUE : $Boolean::FALSE);
		}
	case RMIConnectionImpl::IS_REGISTERED:
		{
			$init($Boolean);
			return $of($nc(this->mbeanServer)->isRegistered($cast($ObjectName, $nc(params)->get(0))) ? $Boolean::TRUE : $Boolean::FALSE);
		}
	case RMIConnectionImpl::QUERY_MBEANS:
		{
			return $of($nc(this->mbeanServer)->queryMBeans($cast($ObjectName, $nc(params)->get(0)), $cast($QueryExp, params->get(1))));
		}
	case RMIConnectionImpl::QUERY_NAMES:
		{
			return $of($nc(this->mbeanServer)->queryNames($cast($ObjectName, $nc(params)->get(0)), $cast($QueryExp, params->get(1))));
		}
	case RMIConnectionImpl::SET_ATTRIBUTE:
		{
			$nc(this->mbeanServer)->setAttribute($cast($ObjectName, $nc(params)->get(0)), $cast($Attribute, params->get(1)));
			return $of(nullptr);
		}
	case RMIConnectionImpl::SET_ATTRIBUTES:
		{
			return $of($nc(this->mbeanServer)->setAttributes($cast($ObjectName, $nc(params)->get(0)), $cast($AttributeList, params->get(1))));
		}
	case RMIConnectionImpl::UNREGISTER_MBEAN:
		{
			$nc(this->mbeanServer)->unregisterMBean($cast($ObjectName, $nc(params)->get(0)));
			return $of(nullptr);
		}
	case RMIConnectionImpl::ADD_NOTIFICATION_LISTENERS:
		{
			return $of($nc($(getServerNotifFwd()))->addNotificationListener($cast($ObjectName, $nc(params)->get(0)), $cast($NotificationFilter, params->get(1))));
		}
	case RMIConnectionImpl::ADD_NOTIFICATION_LISTENER_OBJECTNAME:
		{
			$nc(this->mbeanServer)->addNotificationListener($cast($ObjectName, $nc(params)->get(0)), $cast($ObjectName, params->get(1)), $cast($NotificationFilter, params->get(2)), params->get(3));
			return $of(nullptr);
		}
	case RMIConnectionImpl::REMOVE_NOTIFICATION_LISTENER:
		{
			$nc($(getServerNotifFwd()))->removeNotificationListener($cast($ObjectName, $nc(params)->get(0)), $cast($IntegerArray, params->get(1)));
			return $of(nullptr);
		}
	case RMIConnectionImpl::REMOVE_NOTIFICATION_LISTENER_OBJECTNAME:
		{
			$nc(this->mbeanServer)->removeNotificationListener($cast($ObjectName, $nc(params)->get(0)), $cast($ObjectName, params->get(1)));
			return $of(nullptr);
		}
	case RMIConnectionImpl::REMOVE_NOTIFICATION_LISTENER_OBJECTNAME_FILTER_HANDBACK:
		{
			$nc(this->mbeanServer)->removeNotificationListener($cast($ObjectName, $nc(params)->get(0)), $cast($ObjectName, params->get(1)), $cast($NotificationFilter, params->get(2)), params->get(3));
			return $of(nullptr);
		}
	default:
		{
			$throwNew($IllegalArgumentException, "Invalid operation"_s);
		}
	}
}

$Object* RMIConnectionImpl::unwrap($MarshalledObject* mo, $ClassLoader* cl, $Class* wrappedClass, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (mo == nullptr) {
		return $of(nullptr);
	}
	try {
		$var($ClassLoader, old, $cast($ClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($RMIConnectionImpl$SetCcl, cl)))));
		{
			$var($Throwable, var$0, nullptr);
			$var($Object, var$2, nullptr);
			bool return$1 = false;
			try {
				$var($AccessControlContext, reqACC, nullptr);
				if (delegationSubject == nullptr) {
					$assign(reqACC, this->acc);
				} else {
					if (this->subject == nullptr) {
						$var($String, msg, "Subject delegation cannot be enabled unless an authenticated subject is put in place"_s);
						$throwNew($SecurityException, msg);
					}
					$assign(reqACC, $nc(this->subjectDelegator)->delegatedContext(this->acc, delegationSubject, this->removeCallerContext));
				}
				if (reqACC != nullptr) {
					$assign(var$2, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new(RMIConnectionImpl$$Lambda$lambda$unwrap$0, wrappedClass, mo)), reqACC));
					return$1 = true;
					goto $finally;
				} else {
					$assign(var$2, $nc(wrappedClass)->cast($($nc(mo)->get())));
					return$1 = true;
					goto $finally;
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($RMIConnectionImpl$SetCcl, old)));
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		if ($instanceOf($ClassNotFoundException, e)) {
			$throwNew($UnmarshalException, $($nc(e)->toString()), e);
		}
		$nc(RMIConnectionImpl::logger)->warning("unwrap"_s, $$str({"Failed to unmarshall object: "_s, e}));
		$nc(RMIConnectionImpl::logger)->debug("unwrap"_s, static_cast<$Throwable*>(e));
	} catch ($ClassNotFoundException& ex) {
		$nc(RMIConnectionImpl::logger)->warning("unwrap"_s, $$str({"Failed to unmarshall object: "_s, ex}));
		$nc(RMIConnectionImpl::logger)->debug("unwrap"_s, static_cast<$Throwable*>(ex));
		$throwNew($UnmarshalException, $(ex->toString()), ex);
	}
	return $of(nullptr);
}

$Object* RMIConnectionImpl::unwrap($MarshalledObject* mo, $ClassLoader* cl1, $ClassLoader* cl2, $Class* wrappedClass, $Subject* delegationSubject) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (mo == nullptr) {
		return $of(nullptr);
	}
	try {
		$var($ClassLoader, orderCL, $cast($ClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($RMIConnectionImpl$7, this, cl1, cl2)))));
		return $of(unwrap(mo, orderCL, wrappedClass, delegationSubject));
	} catch ($PrivilegedActionException& pe) {
		$var($Exception, e, extractException(pe));
		if ($instanceOf($IOException, e)) {
			$throw($cast($IOException, e));
		}
		if ($instanceOf($ClassNotFoundException, e)) {
			$throwNew($UnmarshalException, $($nc(e)->toString()), e);
		}
		$nc(RMIConnectionImpl::logger)->warning("unwrap"_s, $$str({"Failed to unmarshall object: "_s, e}));
		$nc(RMIConnectionImpl::logger)->debug("unwrap"_s, static_cast<$Throwable*>(e));
	}
	return $of(nullptr);
}

$IOException* RMIConnectionImpl::newIOException($String* message, $Throwable* cause) {
	$init(RMIConnectionImpl);
	$var($IOException, x, $new($IOException, message));
	return $cast($IOException, $EnvHelp::initCause(x, cause));
}

$Exception* RMIConnectionImpl::extractException($Exception* e$renamed) {
	$init(RMIConnectionImpl);
	$var($Exception, e, e$renamed);
	while ($instanceOf($PrivilegedActionException, e)) {
		$assign(e, $nc(($cast($PrivilegedActionException, e)))->getException());
	}
	return e;
}

$ObjectArray* RMIConnectionImpl::nullIsEmpty($ObjectArray* array) {
	$init(RMIConnectionImpl);
	return (array == nullptr) ? RMIConnectionImpl::NO_OBJECTS : array;
}

$StringArray* RMIConnectionImpl::nullIsEmpty($StringArray* array) {
	$init(RMIConnectionImpl);
	return (array == nullptr) ? RMIConnectionImpl::NO_STRINGS : array;
}

void RMIConnectionImpl::checkNonNull($String* what, Object$* x) {
	$init(RMIConnectionImpl);
	$useLocalCurrentObjectStackCache();
	if (x == nullptr) {
		$var($RuntimeException, wrapped, $new($IllegalArgumentException, $$str({what, " must not be null"_s})));
		$throwNew($RuntimeOperationsException, wrapped);
	}
}

$String* RMIConnectionImpl::objects($ObjectArray* objs) {
	$init(RMIConnectionImpl);
	if (objs == nullptr) {
		return "null"_s;
	} else {
		return $nc($of($($Arrays::asList(objs))))->toString();
	}
}

$String* RMIConnectionImpl::strings($StringArray* strs) {
	$init(RMIConnectionImpl);
	return objects(strs);
}

$Object* RMIConnectionImpl::lambda$unwrap$0($Class* wrappedClass, $MarshalledObject* mo) {
	$init(RMIConnectionImpl);
	return $of($nc(wrappedClass)->cast($($nc(mo)->get())));
}

void clinit$RMIConnectionImpl($Class* class$) {
	$assignStatic(RMIConnectionImpl::NO_OBJECTS, $new($ObjectArray, 0));
	$assignStatic(RMIConnectionImpl::NO_STRINGS, $new($StringArray, 0));
	$assignStatic(RMIConnectionImpl::logger, $new($ClassLogger, "javax.management.remote.rmi"_s, "RMIConnectionImpl"_s));
}

RMIConnectionImpl::RMIConnectionImpl() {
}

$Class* RMIConnectionImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RMIConnectionImpl$$Lambda$lambda$unwrap$0::classInfo$.name)) {
			return RMIConnectionImpl$$Lambda$lambda$unwrap$0::load$(name, initialize);
		}
	}
	$loadClass(RMIConnectionImpl, name, initialize, &_RMIConnectionImpl_ClassInfo_, clinit$RMIConnectionImpl, allocate$RMIConnectionImpl);
	return class$;
}

$Class* RMIConnectionImpl::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax