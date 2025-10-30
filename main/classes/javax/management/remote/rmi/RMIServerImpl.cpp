#include <javax/management/remote/rmi/RMIServerImpl.h>

#include <com/sun/jmx/remote/internal/ArrayNotificationBuffer.h>
#include <com/sun/jmx/remote/internal/NotificationBuffer.h>
#include <com/sun/jmx/remote/security/JMXPluggableAuthenticator.h>
#include <com/sun/jmx/remote/util/ClassLogger.h>
#include <java/io/Closeable.h>
#include <java/io/IOException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/ref/WeakReference.h>
#include <java/rmi/server/RemoteServer.h>
#include <java/rmi/server/ServerNotActiveException.h>
#include <java/security/Principal.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/management/MBeanServer.h>
#include <javax/management/remote/JMXAuthenticator.h>
#include <javax/management/remote/JMXConnectorServer.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnectorServer.h>
#include <javax/security/auth/Subject.h>
#include <jcpp.h>

#undef AUTHENTICATOR

using $ArrayNotificationBuffer = ::com::sun::jmx::remote::internal::ArrayNotificationBuffer;
using $NotificationBuffer = ::com::sun::jmx::remote::internal::NotificationBuffer;
using $JMXPluggableAuthenticator = ::com::sun::jmx::remote::security::JMXPluggableAuthenticator;
using $ClassLogger = ::com::sun::jmx::remote::util::ClassLogger;
using $Closeable = ::java::io::Closeable;
using $IOException = ::java::io::IOException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $Reference = ::java::lang::ref::Reference;
using $WeakReference = ::java::lang::ref::WeakReference;
using $Remote = ::java::rmi::Remote;
using $RemoteServer = ::java::rmi::server::RemoteServer;
using $ServerNotActiveException = ::java::rmi::server::ServerNotActiveException;
using $Principal = ::java::security::Principal;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $MBeanServer = ::javax::management::MBeanServer;
using $JMXAuthenticator = ::javax::management::remote::JMXAuthenticator;
using $JMXConnectorServer = ::javax::management::remote::JMXConnectorServer;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIConnectorServer = ::javax::management::remote::rmi::RMIConnectorServer;
using $RMIServer = ::javax::management::remote::rmi::RMIServer;
using $Subject = ::javax::security::auth::Subject;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIServerImpl_FieldInfo_[] = {
	{"logger", "Lcom/sun/jmx/remote/util/ClassLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIServerImpl, logger)},
	{"clientList", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/ref/WeakReference<Ljavax/management/remote/rmi/RMIConnection;>;>;", $PRIVATE | $FINAL, $field(RMIServerImpl, clientList)},
	{"cl", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(RMIServerImpl, cl)},
	{"mbeanServer", "Ljavax/management/MBeanServer;", nullptr, $PRIVATE, $field(RMIServerImpl, mbeanServer)},
	{"env", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;*>;", $PRIVATE | $FINAL, $field(RMIServerImpl, env)},
	{"connServer", "Ljavax/management/remote/rmi/RMIConnectorServer;", nullptr, $PRIVATE, $field(RMIServerImpl, connServer)},
	{"connectionIdNumber", "I", nullptr, $PRIVATE | $STATIC, $staticField(RMIServerImpl, connectionIdNumber)},
	{"notifBuffer", "Lcom/sun/jmx/remote/internal/NotificationBuffer;", nullptr, $PRIVATE, $field(RMIServerImpl, notifBuffer)},
	{}
};

$MethodInfo _RMIServerImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(RMIServerImpl::*)($Map*)>(&RMIServerImpl::init$))},
	{"clientClosed", "(Ljavax/management/remote/rmi/RMIConnection;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"closeClient", "(Ljavax/management/remote/rmi/RMIConnection;)V", nullptr, $PROTECTED | $ABSTRACT, nullptr, "java.io.IOException"},
	{"closeServer", "()V", nullptr, $PROTECTED | $ABSTRACT, nullptr, "java.io.IOException"},
	{"doNewClient", "(Ljava/lang/Object;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, 0, nullptr, "java.io.IOException"},
	{"dropDeadReferences", "()V", nullptr, $PRIVATE, $method(static_cast<void(RMIServerImpl::*)()>(&RMIServerImpl::dropDeadReferences))},
	{"export", "()V", nullptr, $PROTECTED | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getDefaultClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"getMBeanServer", "()Ljavax/management/MBeanServer;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"getNotifBuffer", "()Lcom/sun/jmx/remote/internal/NotificationBuffer;", nullptr, $SYNCHRONIZED},
	{"getProtocol", "()Ljava/lang/String;", nullptr, $PROTECTED | $ABSTRACT},
	{"getVersion", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"makeClient", "(Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, $PROTECTED | $ABSTRACT, nullptr, "java.io.IOException"},
	{"makeConnectionId", "(Ljava/lang/String;Ljavax/security/auth/Subject;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<$String*(*)($String*,$Subject*)>(&RMIServerImpl::makeConnectionId))},
	{"newClient", "(Ljava/lang/Object;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"setDefaultClassLoader", "(Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setMBeanServer", "(Ljavax/management/MBeanServer;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setRMIConnectorServer", "(Ljavax/management/remote/rmi/RMIConnectorServer;)V", nullptr, 0, nullptr, "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toStub", "()Ljava/rmi/Remote;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _RMIServerImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"javax.management.remote.rmi.RMIServerImpl",
	"java.lang.Object",
	"java.io.Closeable,javax.management.remote.rmi.RMIServer",
	_RMIServerImpl_FieldInfo_,
	_RMIServerImpl_MethodInfo_
};

$Object* allocate$RMIServerImpl($Class* clazz) {
	return $of($alloc(RMIServerImpl));
}

int32_t RMIServerImpl::hashCode() {
	 return this->$Closeable::hashCode();
}

bool RMIServerImpl::equals(Object$* arg0) {
	 return this->$Closeable::equals(arg0);
}

$Object* RMIServerImpl::clone() {
	 return this->$Closeable::clone();
}

$String* RMIServerImpl::toString() {
	 return this->$Closeable::toString();
}

void RMIServerImpl::finalize() {
	this->$Closeable::finalize();
}

$ClassLogger* RMIServerImpl::logger = nullptr;
int32_t RMIServerImpl::connectionIdNumber = 0;

void RMIServerImpl::init$($Map* env) {
	$set(this, clientList, $new($ArrayList));
	$set(this, env, (env == nullptr) ? $Collections::emptyMap() : env);
}

void RMIServerImpl::setRMIConnectorServer($RMIConnectorServer* connServer) {
	$set(this, connServer, connServer);
}

void RMIServerImpl::setDefaultClassLoader($ClassLoader* cl) {
	$synchronized(this) {
		$set(this, cl, cl);
	}
}

$ClassLoader* RMIServerImpl::getDefaultClassLoader() {
	$synchronized(this) {
		return this->cl;
	}
}

void RMIServerImpl::setMBeanServer($MBeanServer* mbs) {
	$synchronized(this) {
		$set(this, mbeanServer, mbs);
	}
}

$MBeanServer* RMIServerImpl::getMBeanServer() {
	$synchronized(this) {
		return this->mbeanServer;
	}
}

$String* RMIServerImpl::getVersion() {
	try {
		return $str({"1.0 java_runtime_"_s, $($System::getProperty("java.runtime.version"_s))});
	} catch ($SecurityException& e) {
		return "1.0 "_s;
	}
	$shouldNotReachHere();
}

$RMIConnection* RMIServerImpl::newClient(Object$* credentials) {
	return doNewClient(credentials);
}

$RMIConnection* RMIServerImpl::doNewClient(Object$* credentials) {
	$useLocalCurrentObjectStackCache();
	bool tracing = $nc(RMIServerImpl::logger)->traceOn();
	if (tracing) {
		$nc(RMIServerImpl::logger)->trace("newClient"_s, "making new client"_s);
	}
	if (getMBeanServer() == nullptr) {
		$throwNew($IllegalStateException, "Not attached to an MBean server"_s);
	}
	$var($Subject, subject, nullptr);
	$init($JMXConnectorServer);
	$var($JMXAuthenticator, authenticator, $cast($JMXAuthenticator, $nc(this->env)->get($JMXConnectorServer::AUTHENTICATOR)));
	if (authenticator == nullptr) {
		bool var$0 = $nc(this->env)->get("jmx.remote.x.password.file"_s) != nullptr;
		if (var$0 || $nc(this->env)->get("jmx.remote.x.login.config"_s) != nullptr) {
			$assign(authenticator, $new($JMXPluggableAuthenticator, this->env));
		}
	}
	if (authenticator != nullptr) {
		if (tracing) {
			$nc(RMIServerImpl::logger)->trace("newClient"_s, $$str({"got authenticator: "_s, $($of(authenticator)->getClass()->getName())}));
		}
		try {
			$assign(subject, authenticator->authenticate(credentials));
		} catch ($SecurityException& e) {
			$nc(RMIServerImpl::logger)->trace("newClient"_s, $$str({"Authentication failed: "_s, e}));
			$throw(e);
		}
	}
	if (tracing) {
		if (subject != nullptr) {
			$nc(RMIServerImpl::logger)->trace("newClient"_s, "subject is not null"_s);
		} else {
			$nc(RMIServerImpl::logger)->trace("newClient"_s, "no subject"_s);
		}
	}
	$var($String, connectionId, makeConnectionId($(getProtocol()), subject));
	if (tracing) {
		$nc(RMIServerImpl::logger)->trace("newClient"_s, $$str({"making new connection: "_s, connectionId}));
	}
	$var($RMIConnection, client, makeClient(connectionId, subject));
	dropDeadReferences();
	$var($WeakReference, wr, $new($WeakReference, client));
	$synchronized(this->clientList) {
		$nc(this->clientList)->add(wr);
	}
	$nc(this->connServer)->connectionOpened(connectionId, "Connection opened"_s, nullptr);
	$synchronized(this->clientList) {
		if (!$nc(this->clientList)->contains(wr)) {
			$throwNew($IOException, "The connection is refused."_s);
		}
	}
	if (tracing) {
		$nc(RMIServerImpl::logger)->trace("newClient"_s, $$str({"new connection done: "_s, connectionId}));
	}
	return client;
}

void RMIServerImpl::clientClosed($RMIConnection* client) {
	$useLocalCurrentObjectStackCache();
	bool debug = $nc(RMIServerImpl::logger)->debugOn();
	if (debug) {
		$nc(RMIServerImpl::logger)->trace("clientClosed"_s, $$str({"client="_s, client}));
	}
	if (client == nullptr) {
		$throwNew($NullPointerException, "Null client"_s);
	}
	$synchronized(this->clientList) {
		dropDeadReferences();
		{
			$var($Iterator, it, $nc(this->clientList)->iterator());
			for (; $nc(it)->hasNext();) {
				$var($WeakReference, wr, $cast($WeakReference, it->next()));
				if ($equals($nc(wr)->get(), client)) {
					it->remove();
					break;
				}
			}
		}
	}
	if (debug) {
		$nc(RMIServerImpl::logger)->trace("clientClosed"_s, "closing client."_s);
	}
	closeClient(client);
	if (debug) {
		$nc(RMIServerImpl::logger)->trace("clientClosed"_s, "sending notif"_s);
	}
	$nc(this->connServer)->connectionClosed($($nc(client)->getConnectionId()), "Client connection closed"_s, nullptr);
	if (debug) {
		$nc(RMIServerImpl::logger)->trace("clientClosed"_s, "done"_s);
	}
}

void RMIServerImpl::close() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		bool tracing = $nc(RMIServerImpl::logger)->traceOn();
		bool debug = $nc(RMIServerImpl::logger)->debugOn();
		if (tracing) {
			$nc(RMIServerImpl::logger)->trace("close"_s, "closing"_s);
		}
		$var($IOException, ioException, nullptr);
		try {
			if (debug) {
				$nc(RMIServerImpl::logger)->debug("close"_s, "closing Server"_s);
			}
			closeServer();
		} catch ($IOException& e) {
			if (tracing) {
				$nc(RMIServerImpl::logger)->trace("close"_s, $$str({"Failed to close server: "_s, e}));
			}
			if (debug) {
				$nc(RMIServerImpl::logger)->debug("close"_s, static_cast<$Throwable*>(e));
			}
			$assign(ioException, e);
		}
		if (debug) {
			$nc(RMIServerImpl::logger)->debug("close"_s, "closing Clients"_s);
		}
		while (true) {
			$synchronized(this->clientList) {
				if (debug) {
					$nc(RMIServerImpl::logger)->debug("close"_s, "droping dead references"_s);
				}
				dropDeadReferences();
				if (debug) {
					$nc(RMIServerImpl::logger)->debug("close"_s, $$str({"client count: "_s, $$str($nc(this->clientList)->size())}));
				}
				if ($nc(this->clientList)->size() == 0) {
					break;
				}
				{
					$var($Iterator, it, $nc(this->clientList)->iterator());
					for (; $nc(it)->hasNext();) {
						$var($WeakReference, wr, $cast($WeakReference, it->next()));
						$var($RMIConnection, client, $cast($RMIConnection, $nc(wr)->get()));
						it->remove();
						if (client != nullptr) {
							try {
								client->close();
							} catch ($IOException& e) {
								if (tracing) {
									$nc(RMIServerImpl::logger)->trace("close"_s, $$str({"Failed to close client: "_s, e}));
								}
								if (debug) {
									$nc(RMIServerImpl::logger)->debug("close"_s, static_cast<$Throwable*>(e));
								}
								if (ioException == nullptr) {
									$assign(ioException, e);
								}
							}
							break;
						}
					}
				}
			}
		}
		if (this->notifBuffer != nullptr) {
			$nc(this->notifBuffer)->dispose();
		}
		if (ioException != nullptr) {
			if (tracing) {
				$nc(RMIServerImpl::logger)->trace("close"_s, "close failed."_s);
			}
			$throw(ioException);
		}
		if (tracing) {
			$nc(RMIServerImpl::logger)->trace("close"_s, "closed."_s);
		}
	}
}

$String* RMIServerImpl::makeConnectionId($String* protocol, $Subject* subject) {
	$load(RMIServerImpl);
	$synchronized(class$) {
		$init(RMIServerImpl);
		$useLocalCurrentObjectStackCache();
		++RMIServerImpl::connectionIdNumber;
		$var($String, clientHost, ""_s);
		try {
			$assign(clientHost, $RemoteServer::getClientHost());
			if ($nc(clientHost)->contains(":"_s)) {
				$assign(clientHost, $str({"["_s, clientHost, "]"_s}));
			}
		} catch ($ServerNotActiveException& e) {
			$nc(RMIServerImpl::logger)->trace("makeConnectionId"_s, "getClientHost"_s, e);
		}
		$var($StringBuilder, buf, $new($StringBuilder));
		buf->append(protocol)->append(":"_s);
		if (clientHost->length() > 0) {
			buf->append("//"_s)->append(clientHost);
		}
		buf->append(" "_s);
		if (subject != nullptr) {
			$var($Set, principals, subject->getPrincipals());
			$var($String, sep, ""_s);
			{
				$var($Iterator, it, $nc(principals)->iterator());
				for (; $nc(it)->hasNext();) {
					$var($Principal, p, $cast($Principal, it->next()));
					$var($String, name, $($nc($($nc(p)->getName()))->replace(u' ', u'_'))->replace(u';', u':'));
					buf->append(sep)->append(name);
					$assign(sep, ";"_s);
				}
			}
		}
		buf->append(" "_s)->append(RMIServerImpl::connectionIdNumber);
		if ($nc(RMIServerImpl::logger)->traceOn()) {
			$nc(RMIServerImpl::logger)->trace("newConnectionId"_s, $$str({"connectionId="_s, buf}));
		}
		return buf->toString();
	}
}

void RMIServerImpl::dropDeadReferences() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->clientList) {
		{
			$var($Iterator, it, $nc(this->clientList)->iterator());
			for (; $nc(it)->hasNext();) {
				$var($WeakReference, wr, $cast($WeakReference, it->next()));
				if ($nc(wr)->get() == nullptr) {
					it->remove();
				}
			}
		}
	}
}

$NotificationBuffer* RMIServerImpl::getNotifBuffer() {
	$synchronized(this) {
		if (this->notifBuffer == nullptr) {
			$set(this, notifBuffer, $ArrayNotificationBuffer::getNotificationBuffer(this->mbeanServer, this->env));
		}
		return this->notifBuffer;
	}
}

void clinit$RMIServerImpl($Class* class$) {
	$assignStatic(RMIServerImpl::logger, $new($ClassLogger, "javax.management.remote.rmi"_s, "RMIServerImpl"_s));
}

RMIServerImpl::RMIServerImpl() {
}

$Class* RMIServerImpl::load$($String* name, bool initialize) {
	$loadClass(RMIServerImpl, name, initialize, &_RMIServerImpl_ClassInfo_, clinit$RMIServerImpl, allocate$RMIServerImpl);
	return class$;
}

$Class* RMIServerImpl::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax