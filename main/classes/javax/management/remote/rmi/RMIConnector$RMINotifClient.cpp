#include <javax/management/remote/rmi/RMIConnector$RMINotifClient.h>

#include <com/sun/jmx/remote/internal/ClientCommunicatorAdmin.h>
#include <com/sun/jmx/remote/internal/ClientNotifForwarder.h>
#include <java/io/IOException.h>
#include <java/io/NotSerializableException.h>
#include <java/lang/ClassLoader.h>
#include <java/rmi/MarshalledObject.h>
#include <java/rmi/UnmarshalException.h>
#include <java/util/Map.h>
#include <javax/management/MBeanServerDelegate.h>
#include <javax/management/MBeanServerNotification.h>
#include <javax/management/Notification.h>
#include <javax/management/NotificationFilterSupport.h>
#include <javax/management/ObjectName.h>
#include <javax/management/remote/JMXConnectionNotification.h>
#include <javax/management/remote/NotificationResult.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnector$Util.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

#undef DELEGATE_NAME
#undef FAILED
#undef NOTIFS_LOST
#undef UNREGISTRATION_NOTIFICATION

using $IntegerArray = $Array<::java::lang::Integer>;
using $MarshalledObjectArray = $Array<::java::rmi::MarshalledObject>;
using $ObjectNameArray = $Array<::javax::management::ObjectName>;
using $SubjectArray = $Array<::javax::security::auth::Subject>;
using $ClientCommunicatorAdmin = ::com::sun::jmx::remote::internal::ClientCommunicatorAdmin;
using $ClientNotifForwarder = ::com::sun::jmx::remote::internal::ClientNotifForwarder;
using $IOException = ::java::io::IOException;
using $NotSerializableException = ::java::io::NotSerializableException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $Map = ::java::util::Map;
using $MBeanServerDelegate = ::javax::management::MBeanServerDelegate;
using $MBeanServerNotification = ::javax::management::MBeanServerNotification;
using $Notification = ::javax::management::Notification;
using $NotificationFilterSupport = ::javax::management::NotificationFilterSupport;
using $ObjectName = ::javax::management::ObjectName;
using $JMXConnectionNotification = ::javax::management::remote::JMXConnectionNotification;
using $NotificationResult = ::javax::management::remote::NotificationResult;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;
using $RMIConnector$Util = ::javax::management::remote::rmi::RMIConnector$Util;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnector$RMINotifClient_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnector;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$RMINotifClient, this$0)},
	{}
};

$MethodInfo _RMIConnector$RMINotifClient_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnector;Ljava/lang/ClassLoader;Ljava/util/Map;)V", "(Ljava/lang/ClassLoader;Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(RMIConnector$RMINotifClient::*)($RMIConnector*,$ClassLoader*,$Map*)>(&RMIConnector$RMINotifClient::init$))},
	{"addListenerForMBeanRemovedNotif", "()Ljava/lang/Integer;", nullptr, $PROTECTED, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException"},
	{"fetchNotifs", "(JIJ)Ljavax/management/remote/NotificationResult;", nullptr, $PROTECTED, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"lostNotifs", "(Ljava/lang/String;J)V", nullptr, $PROTECTED},
	{"removeListenerForMBeanRemovedNotif", "(Ljava/lang/Integer;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException,javax.management.InstanceNotFoundException,javax.management.ListenerNotFoundException"},
	{"rethrowDeserializationException", "(Ljava/io/IOException;)V", nullptr, $PRIVATE, $method(static_cast<void(RMIConnector$RMINotifClient::*)($IOException*)>(&RMIConnector$RMINotifClient::rethrowDeserializationException)), "java.lang.ClassNotFoundException,java.io.IOException"},
	{}
};

$InnerClassInfo _RMIConnector$RMINotifClient_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$RMINotifClient", "javax.management.remote.rmi.RMIConnector", "RMINotifClient", $PRIVATE},
	{}
};

$ClassInfo _RMIConnector$RMINotifClient_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$RMINotifClient",
	"com.sun.jmx.remote.internal.ClientNotifForwarder",
	nullptr,
	_RMIConnector$RMINotifClient_FieldInfo_,
	_RMIConnector$RMINotifClient_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnector$RMINotifClient_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$RMINotifClient($Class* clazz) {
	return $of($alloc(RMIConnector$RMINotifClient));
}

void RMIConnector$RMINotifClient::init$($RMIConnector* this$0, $ClassLoader* cl, $Map* env) {
	$set(this, this$0, this$0);
	$ClientNotifForwarder::init$(cl, env);
}

$NotificationResult* RMIConnector$RMINotifClient::fetchNotifs(int64_t clientSequenceNumber, int32_t maxNotifications, int64_t timeout) {
	$useLocalCurrentObjectStackCache();
	bool retried = false;
	while (true) {
		try {
			return $nc(this->this$0->connection)->fetchNotifications(clientSequenceNumber, maxNotifications, timeout);
		} catch ($IOException& ioe) {
			rethrowDeserializationException(ioe);
			try {
				$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
			} catch ($IOException& ee) {
				bool toClose = false;
				$synchronized(this) {
					if (this->this$0->terminated) {
						$throw(ioe);
					} else if (retried) {
						toClose = true;
					}
				}
				if (toClose) {
					$init($JMXConnectionNotification);
					$var($String, var$0, $JMXConnectionNotification::FAILED);
					$var($String, var$1, this->this$0->connectionId);
					$var($Notification, failedNotif, $new($JMXConnectionNotification, var$0, this, var$1, this->this$0->clientNotifSeqNo++, $$str({"Failed to communicate with the server: "_s, $(ioe->toString())}), ioe));
					this->this$0->sendNotification(failedNotif);
					try {
						this->this$0->close(true);
					} catch ($Exception& e) {
					}
					$throw(ioe);
				} else {
					retried = true;
				}
			}
		}
	}
	$shouldNotReachHere();
}

void RMIConnector$RMINotifClient::rethrowDeserializationException($IOException* ioe) {
	if ($instanceOf($UnmarshalException, ioe)) {
		$var($NotSerializableException, nse, $new($NotSerializableException));
		nse->initCause(ioe);
		$throw(nse);
	}
}

$Integer* RMIConnector$RMINotifClient::addListenerForMBeanRemovedNotif() {
	$useLocalCurrentObjectStackCache();
	$var($NotificationFilterSupport, clientFilter, $new($NotificationFilterSupport));
	$init($MBeanServerNotification);
	clientFilter->enableType($MBeanServerNotification::UNREGISTRATION_NOTIFICATION);
	$var($MarshalledObject, sFilter, $new($MarshalledObject, clientFilter));
	$var($IntegerArray, listenerIDs, nullptr);
	$init($MBeanServerDelegate);
	$var($ObjectNameArray, names, $new($ObjectNameArray, {$MBeanServerDelegate::DELEGATE_NAME}));
	$var($MarshalledObjectArray, filters, $cast($MarshalledObjectArray, $RMIConnector$Util::cast($$new($MarshalledObjectArray, {sFilter}))));
	$var($SubjectArray, subjects, $new($SubjectArray, {($Subject*)nullptr}));
	try {
		$assign(listenerIDs, $nc(this->this$0->connection)->addNotificationListeners(names, filters, subjects));
	} catch ($IOException& ioe) {
		$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
		$assign(listenerIDs, $nc(this->this$0->connection)->addNotificationListeners(names, filters, subjects));
	}
	return $nc(listenerIDs)->get(0);
}

void RMIConnector$RMINotifClient::removeListenerForMBeanRemovedNotif($Integer* id) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($MBeanServerDelegate);
		$nc(this->this$0->connection)->removeNotificationListeners($MBeanServerDelegate::DELEGATE_NAME, $$new($IntegerArray, {id}), nullptr);
	} catch ($IOException& ioe) {
		$nc(this->this$0->communicatorAdmin)->gotIOException(ioe);
		$init($MBeanServerDelegate);
		$nc(this->this$0->connection)->removeNotificationListeners($MBeanServerDelegate::DELEGATE_NAME, $$new($IntegerArray, {id}), nullptr);
	}
}

void RMIConnector$RMINotifClient::lostNotifs($String* message, int64_t number) {
	$useLocalCurrentObjectStackCache();
	$init($JMXConnectionNotification);
	$var($String, notifType, $JMXConnectionNotification::NOTIFS_LOST);
	$var($String, var$0, notifType);
	$var($Object, var$1, $of(this->this$0));
	$var($String, var$2, this->this$0->connectionId);
	$var($JMXConnectionNotification, n, $new($JMXConnectionNotification, var$0, var$1, var$2, this->this$0->clientNotifCounter++, message, $($Long::valueOf(number))));
	this->this$0->sendNotification(n);
}

RMIConnector$RMINotifClient::RMIConnector$RMINotifClient() {
}

$Class* RMIConnector$RMINotifClient::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$RMINotifClient, name, initialize, &_RMIConnector$RMINotifClient_ClassInfo_, allocate$RMIConnector$RMINotifClient);
	return class$;
}

$Class* RMIConnector$RMINotifClient::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax