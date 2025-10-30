#include <javax/management/remote/rmi/RMIConnector$RMIClientCommunicatorAdmin.h>

#include <com/sun/jmx/remote/internal/ClientCommunicatorAdmin.h>
#include <com/sun/jmx/remote/internal/ClientListenerInfo.h>
#include <com/sun/jmx/remote/internal/ClientNotifForwarder.h>
#include <com/sun/jmx/remote/util/ClassLogger.h>
#include <java/io/IOException.h>
#include <java/rmi/MarshalledObject.h>
#include <java/rmi/NoSuchObjectException.h>
#include <java/rmi/ServerException.h>
#include <java/util/Map.h>
#include <javax/management/InstanceNotFoundException.h>
#include <javax/management/Notification.h>
#include <javax/management/NotificationFilter.h>
#include <javax/management/NotificationListener.h>
#include <javax/management/ObjectName.h>
#include <javax/management/remote/JMXConnectionNotification.h>
#include <javax/management/remote/JMXServiceURL.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnector$RMINotifClient.h>
#include <javax/management/remote/rmi/RMIConnector$Util.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <javax/management/remote/rmi/RMIServer.h>
#include <javax/naming/NamingException.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

#undef FAILED
#undef OPENED

using $ClientListenerInfoArray = $Array<::com::sun::jmx::remote::internal::ClientListenerInfo>;
using $IntegerArray = $Array<::java::lang::Integer>;
using $MarshalledObjectArray = $Array<::java::rmi::MarshalledObject>;
using $NotificationFilterArray = $Array<::javax::management::NotificationFilter>;
using $NotificationListenerArray = $Array<::javax::management::NotificationListener>;
using $ObjectNameArray = $Array<::javax::management::ObjectName>;
using $SubjectArray = $Array<::javax::security::auth::Subject>;
using $ClientCommunicatorAdmin = ::com::sun::jmx::remote::internal::ClientCommunicatorAdmin;
using $ClientListenerInfo = ::com::sun::jmx::remote::internal::ClientListenerInfo;
using $ClientNotifForwarder = ::com::sun::jmx::remote::internal::ClientNotifForwarder;
using $ClassLogger = ::com::sun::jmx::remote::util::ClassLogger;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $NoSuchObjectException = ::java::rmi::NoSuchObjectException;
using $RemoteException = ::java::rmi::RemoteException;
using $ServerException = ::java::rmi::ServerException;
using $Map = ::java::util::Map;
using $InstanceNotFoundException = ::javax::management::InstanceNotFoundException;
using $Notification = ::javax::management::Notification;
using $NotificationFilter = ::javax::management::NotificationFilter;
using $NotificationListener = ::javax::management::NotificationListener;
using $ObjectName = ::javax::management::ObjectName;
using $JMXConnectionNotification = ::javax::management::remote::JMXConnectionNotification;
using $JMXServiceURL = ::javax::management::remote::JMXServiceURL;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;
using $RMIConnector$RMINotifClient = ::javax::management::remote::rmi::RMIConnector$RMINotifClient;
using $RMIConnector$Util = ::javax::management::remote::rmi::RMIConnector$Util;
using $RMIServer = ::javax::management::remote::rmi::RMIServer;
using $NamingException = ::javax::naming::NamingException;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnector$RMIClientCommunicatorAdmin_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnector;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$RMIClientCommunicatorAdmin, this$0)},
	{}
};

$MethodInfo _RMIConnector$RMIClientCommunicatorAdmin_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnector;J)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnector$RMIClientCommunicatorAdmin::*)($RMIConnector*,int64_t)>(&RMIConnector$RMIClientCommunicatorAdmin::init$))},
	{"checkConnection", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"doStart", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"doStop", "()V", nullptr, $PROTECTED},
	{"gotIOException", "(Ljava/io/IOException;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"reconnectNotificationListeners", "([Lcom/sun/jmx/remote/internal/ClientListenerInfo;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _RMIConnector$RMIClientCommunicatorAdmin_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$RMIClientCommunicatorAdmin", "javax.management.remote.rmi.RMIConnector", "RMIClientCommunicatorAdmin", $PRIVATE},
	{}
};

$ClassInfo _RMIConnector$RMIClientCommunicatorAdmin_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$RMIClientCommunicatorAdmin",
	"com.sun.jmx.remote.internal.ClientCommunicatorAdmin",
	nullptr,
	_RMIConnector$RMIClientCommunicatorAdmin_FieldInfo_,
	_RMIConnector$RMIClientCommunicatorAdmin_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnector$RMIClientCommunicatorAdmin_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$RMIClientCommunicatorAdmin($Class* clazz) {
	return $of($alloc(RMIConnector$RMIClientCommunicatorAdmin));
}

void RMIConnector$RMIClientCommunicatorAdmin::init$($RMIConnector* this$0, int64_t period) {
	$set(this, this$0, this$0);
	$ClientCommunicatorAdmin::init$(period);
}

void RMIConnector$RMIClientCommunicatorAdmin::gotIOException($IOException* ioe) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($NoSuchObjectException, ioe)) {
		$ClientCommunicatorAdmin::gotIOException(ioe);
		return;
	}
	try {
		$nc(this->this$0->connection)->getDefaultDomain(nullptr);
	} catch ($IOException& ioexc) {
		bool toClose = false;
		$synchronized(this) {
			if (!this->this$0->terminated) {
				this->this$0->terminated = true;
				toClose = true;
			}
		}
		if (toClose) {
			$init($JMXConnectionNotification);
			$var($String, var$0, $JMXConnectionNotification::FAILED);
			$var($String, var$1, this->this$0->connectionId);
			$var($Notification, failedNotif, $new($JMXConnectionNotification, var$0, this, var$1, this->this$0->clientNotifSeqNo++, $$str({"Failed to communicate with the server: "_s, $($nc(ioe)->toString())}), ioe));
			this->this$0->sendNotification(failedNotif);
			try {
				this->this$0->close(true);
			} catch ($Exception& e) {
			}
		}
	}
	if ($instanceOf($ServerException, ioe)) {
		$var($Throwable, tt, $nc(($cast($ServerException, ioe)))->detail);
		if ($instanceOf($IOException, tt)) {
			$throw($cast($IOException, tt));
		} else if ($instanceOf($RuntimeException, tt)) {
			$throw($cast($RuntimeException, tt));
		}
	}
	$throw(ioe);
}

void RMIConnector$RMIClientCommunicatorAdmin::reconnectNotificationListeners($ClientListenerInfoArray* old) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(old)->length;
	int32_t i = 0;
	$var($ClientListenerInfoArray, clis, $new($ClientListenerInfoArray, len));
	$var($SubjectArray, subjects, $new($SubjectArray, len));
	$var($ObjectNameArray, names, $new($ObjectNameArray, len));
	$var($NotificationListenerArray, listeners, $new($NotificationListenerArray, len));
	$var($NotificationFilterArray, filters, $new($NotificationFilterArray, len));
	$var($MarshalledObjectArray, mFilters, $cast($MarshalledObjectArray, $RMIConnector$Util::cast($$new($MarshalledObjectArray, len))));
	$var($ObjectArray, handbacks, $new($ObjectArray, len));
	for (i = 0; i < len; ++i) {
		subjects->set(i, $($nc(old->get(i))->getDelegationSubject()));
		names->set(i, $($nc(old->get(i))->getObjectName()));
		listeners->set(i, $($nc(old->get(i))->getListener()));
		filters->set(i, $($nc(old->get(i))->getNotificationFilter()));
		$nc(mFilters)->set(i, $$new($MarshalledObject, filters->get(i)));
		handbacks->set(i, $($nc(old->get(i))->getHandback()));
	}
	try {
		$var($IntegerArray, ids, this->this$0->addListenersWithSubjects(names, mFilters, subjects, false));
		for (i = 0; i < len; ++i) {
			clis->set(i, $$new($ClientListenerInfo, $nc(ids)->get(i), names->get(i), listeners->get(i), filters->get(i), handbacks->get(i), subjects->get(i)));
		}
		$nc(this->this$0->rmiNotifClient)->postReconnection(clis);
		return;
	} catch ($InstanceNotFoundException& infe) {
	}
	int32_t j = 0;
	for (i = 0; i < len; ++i) {
		try {
			$var($Integer, id, this->this$0->addListenerWithSubject(names->get(i), $$new($MarshalledObject, filters->get(i)), subjects->get(i), false));
			clis->set(j++, $$new($ClientListenerInfo, id, names->get(i), listeners->get(i), filters->get(i), handbacks->get(i), subjects->get(i)));
		} catch ($InstanceNotFoundException& infe) {
			$init($RMIConnector);
			$nc($RMIConnector::logger)->warning("reconnectNotificationListeners"_s, $$str({"Can\'t reconnect listener for "_s, names->get(i)}));
		}
	}
	if (j != len) {
		$var($ClientListenerInfoArray, tmp, clis);
		$assign(clis, $new($ClientListenerInfoArray, j));
		$System::arraycopy(tmp, 0, clis, 0, j);
	}
	$nc(this->this$0->rmiNotifClient)->postReconnection(clis);
}

void RMIConnector$RMIClientCommunicatorAdmin::checkConnection() {
	$init($RMIConnector);
	if ($nc($RMIConnector::logger)->debugOn()) {
		$nc($RMIConnector::logger)->debug("RMIClientCommunicatorAdmin-checkConnection"_s, "Calling the method getDefaultDomain."_s);
	}
	$nc(this->this$0->connection)->getDefaultDomain(nullptr);
}

void RMIConnector$RMIClientCommunicatorAdmin::doStart() {
	$useLocalCurrentObjectStackCache();
	$var($RMIServer, stub, nullptr);
	try {
		$assign(stub, (this->this$0->rmiServer != nullptr) ? this->this$0->rmiServer : this->this$0->findRMIServer(this->this$0->jmxServiceURL, this->this$0->env));
	} catch ($NamingException& ne) {
		$throwNew($IOException, $$str({"Failed to get a RMI stub: "_s, ne}));
	}
	$var($Object, credentials, $nc(this->this$0->env)->get("jmx.remote.credentials"_s));
	$set(this->this$0, connection, $nc(stub)->newClient(credentials));
	$var($ClientListenerInfoArray, old, $nc(this->this$0->rmiNotifClient)->preReconnection());
	reconnectNotificationListeners(old);
	$set(this->this$0, connectionId, this->this$0->getConnectionId());
	$init($JMXConnectionNotification);
	$var($String, var$0, $JMXConnectionNotification::OPENED);
	$var($String, var$1, this->this$0->connectionId);
	$var($Notification, reconnectedNotif, $new($JMXConnectionNotification, var$0, this, var$1, this->this$0->clientNotifSeqNo++, "Reconnected to server"_s, nullptr));
	this->this$0->sendNotification(reconnectedNotif);
}

void RMIConnector$RMIClientCommunicatorAdmin::doStop() {
	try {
		this->this$0->close();
	} catch ($IOException& ioe) {
		$init($RMIConnector);
		$nc($RMIConnector::logger)->warning("RMIClientCommunicatorAdmin-doStop"_s, $$str({"Failed to call the method close():"_s, ioe}));
		$nc($RMIConnector::logger)->debug("RMIClientCommunicatorAdmin-doStop"_s, static_cast<$Throwable*>(ioe));
	}
}

RMIConnector$RMIClientCommunicatorAdmin::RMIConnector$RMIClientCommunicatorAdmin() {
}

$Class* RMIConnector$RMIClientCommunicatorAdmin::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$RMIClientCommunicatorAdmin, name, initialize, &_RMIConnector$RMIClientCommunicatorAdmin_ClassInfo_, allocate$RMIConnector$RMIClientCommunicatorAdmin);
	return class$;
}

$Class* RMIConnector$RMIClientCommunicatorAdmin::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax