#include <javax/management/remote/rmi/RMIConnectorServer.h>

#include <com/sun/jmx/remote/security/MBeanServerAccessController.h>
#include <com/sun/jmx/remote/security/MBeanServerFileAccessController.h>
#include <com/sun/jmx/remote/util/ClassLogger.h>
#include <com/sun/jmx/remote/util/EnvHelp.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalStateException.h>
#include <java/net/MalformedURLException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Hashtable.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/management/InstanceNotFoundException.h>
#include <javax/management/JMException.h>
#include <javax/management/MBeanServer.h>
#include <javax/management/OperationsException.h>
#include <javax/management/remote/JMXConnector.h>
#include <javax/management/remote/JMXConnectorServer.h>
#include <javax/management/remote/JMXServiceURL.h>
#include <javax/management/remote/MBeanServerForwarder.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <javax/management/remote/rmi/RMIJRMPServerImpl.h>
#include <javax/management/remote/rmi/RMIServer.h>
#include <javax/management/remote/rmi/RMIServerImpl.h>
#include <javax/naming/InitialContext.h>
#include <javax/naming/NamingException.h>
#include <jcpp.h>

#undef CREATED
#undef CREDENTIALS_FILTER_PATTERN
#undef JNDI_REBIND_ATTRIBUTE
#undef RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE
#undef RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE
#undef SERIAL_FILTER_PATTERN
#undef STARTED
#undef STOPPED

using $MBeanServerAccessController = ::com::sun::jmx::remote::security::MBeanServerAccessController;
using $MBeanServerFileAccessController = ::com::sun::jmx::remote::security::MBeanServerFileAccessController;
using $ClassLogger = ::com::sun::jmx::remote::util::ClassLogger;
using $EnvHelp = ::com::sun::jmx::remote::util::EnvHelp;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $Remote = ::java::rmi::Remote;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSet = ::java::util::AbstractSet;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Hashtable = ::java::util::Hashtable;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $InstanceNotFoundException = ::javax::management::InstanceNotFoundException;
using $JMException = ::javax::management::JMException;
using $MBeanServer = ::javax::management::MBeanServer;
using $OperationsException = ::javax::management::OperationsException;
using $JMXConnector = ::javax::management::remote::JMXConnector;
using $JMXConnectorServer = ::javax::management::remote::JMXConnectorServer;
using $JMXServiceURL = ::javax::management::remote::JMXServiceURL;
using $MBeanServerForwarder = ::javax::management::remote::MBeanServerForwarder;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;
using $RMIJRMPServerImpl = ::javax::management::remote::rmi::RMIJRMPServerImpl;
using $RMIServer = ::javax::management::remote::rmi::RMIServer;
using $RMIServerImpl = ::javax::management::remote::rmi::RMIServerImpl;
using $InitialContext = ::javax::naming::InitialContext;
using $NamingException = ::javax::naming::NamingException;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectorServer_FieldInfo_[] = {
	{"JNDI_REBIND_ATTRIBUTE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RMIConnectorServer, JNDI_REBIND_ATTRIBUTE)},
	{"RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RMIConnectorServer, RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE)},
	{"RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RMIConnectorServer, RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE)},
	{"CREDENTIALS_FILTER_PATTERN", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RMIConnectorServer, CREDENTIALS_FILTER_PATTERN)},
	{"SERIAL_FILTER_PATTERN", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RMIConnectorServer, SERIAL_FILTER_PATTERN)},
	{"intToAlpha", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIConnectorServer, intToAlpha)},
	{"logger", "Lcom/sun/jmx/remote/util/ClassLogger;", nullptr, $PRIVATE | $STATIC, $staticField(RMIConnectorServer, logger)},
	{"address", "Ljavax/management/remote/JMXServiceURL;", nullptr, $PRIVATE, $field(RMIConnectorServer, address)},
	{"rmiServerImpl", "Ljavax/management/remote/rmi/RMIServerImpl;", nullptr, $PRIVATE, $field(RMIConnectorServer, rmiServerImpl)},
	{"attributes", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;*>;", $PRIVATE | $FINAL, $field(RMIConnectorServer, attributes)},
	{"defaultClassLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(RMIConnectorServer, defaultClassLoader)},
	{"boundJndiUrl", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RMIConnectorServer, boundJndiUrl)},
	{"CREATED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectorServer, CREATED)},
	{"STARTED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectorServer, STARTED)},
	{"STOPPED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMIConnectorServer, STOPPED)},
	{"state", "I", nullptr, $PRIVATE, $field(RMIConnectorServer, state)},
	{"openedServers", "Ljava/util/Set;", "Ljava/util/Set<Ljavax/management/remote/rmi/RMIConnectorServer;>;", $PRIVATE | $STATIC | $FINAL, $staticField(RMIConnectorServer, openedServers)},
	{}
};

$MethodInfo _RMIConnectorServer_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map;)V", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(RMIConnectorServer::*)($JMXServiceURL*,$Map*)>(&RMIConnectorServer::init$)), "java.io.IOException"},
	{"<init>", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map;Ljavax/management/MBeanServer;)V", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map<Ljava/lang/String;*>;Ljavax/management/MBeanServer;)V", $PUBLIC, $method(static_cast<void(RMIConnectorServer::*)($JMXServiceURL*,$Map*,$MBeanServer*)>(&RMIConnectorServer::init$)), "java.io.IOException"},
	{"<init>", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map;Ljavax/management/remote/rmi/RMIServerImpl;Ljavax/management/MBeanServer;)V", "(Ljavax/management/remote/JMXServiceURL;Ljava/util/Map<Ljava/lang/String;*>;Ljavax/management/remote/rmi/RMIServerImpl;Ljavax/management/MBeanServer;)V", $PUBLIC, $method(static_cast<void(RMIConnectorServer::*)($JMXServiceURL*,$Map*,$RMIServerImpl*,$MBeanServer*)>(&RMIConnectorServer::init$)), "java.io.IOException"},
	{"bind", "(Ljava/lang/String;Ljava/util/Hashtable;Ljavax/management/remote/rmi/RMIServer;Z)V", "(Ljava/lang/String;Ljava/util/Hashtable<**>;Ljavax/management/remote/rmi/RMIServer;Z)V", 0, nullptr, "javax.naming.NamingException,java.net.MalformedURLException"},
	{"byteArrayToBase64", "([B)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($bytes*)>(&RMIConnectorServer::byteArrayToBase64))},
	{"connectionClosed", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED},
	{"connectionFailed", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED},
	{"connectionOpened", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PROTECTED},
	{"encodeJRMPStub", "(Ljavax/management/remote/rmi/RMIServer;Ljava/util/Map;)Ljava/lang/String;", "(Ljavax/management/remote/rmi/RMIServer;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/lang/String;", $STATIC, $method(static_cast<$String*(*)($RMIServer*,$Map*)>(&RMIConnectorServer::encodeJRMPStub)), "java.io.IOException"},
	{"encodeStub", "(Ljavax/management/remote/rmi/RMIServer;Ljava/util/Map;)Ljava/lang/String;", "(Ljavax/management/remote/rmi/RMIServer;Ljava/util/Map<Ljava/lang/String;*>;)Ljava/lang/String;", $STATIC, $method(static_cast<$String*(*)($RMIServer*,$Map*)>(&RMIConnectorServer::encodeStub)), "java.io.IOException"},
	{"encodeStubInAddress", "(Ljavax/management/remote/rmi/RMIServer;Ljava/util/Map;)V", "(Ljavax/management/remote/rmi/RMIServer;Ljava/util/Map<Ljava/lang/String;*>;)V", $PRIVATE, $method(static_cast<void(RMIConnectorServer::*)($RMIServer*,$Map*)>(&RMIConnectorServer::encodeStubInAddress)), "java.io.IOException"},
	{"getAddress", "()Ljavax/management/remote/JMXServiceURL;", nullptr, $PUBLIC},
	{"getAttributes", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;*>;", $PUBLIC},
	{"isActive", "()Z", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"newIOException", "(Ljava/lang/String;Ljava/lang/Throwable;)Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$IOException*(*)($String*,$Throwable*)>(&RMIConnectorServer::newIOException))},
	{"newJRMPServer", "(Ljava/util/Map;I)Ljavax/management/remote/rmi/RMIServerImpl;", "(Ljava/util/Map<Ljava/lang/String;*>;I)Ljavax/management/remote/rmi/RMIServerImpl;", $PRIVATE | $STATIC, $method(static_cast<$RMIServerImpl*(*)($Map*,int32_t)>(&RMIConnectorServer::newJRMPServer)), "java.io.IOException"},
	{"newServer", "()Ljavax/management/remote/rmi/RMIServerImpl;", nullptr, 0, nullptr, "java.io.IOException"},
	{"objectToBind", "(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/util/Map;)Ljavax/management/remote/rmi/RMIServer;", "(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/util/Map<Ljava/lang/String;*>;)Ljavax/management/remote/rmi/RMIServer;", $PRIVATE | $STATIC, $method(static_cast<$RMIServer*(*)($RMIServerImpl*,$Map*)>(&RMIConnectorServer::objectToBind)), "java.io.IOException"},
	{"setMBeanServerForwarder", "(Ljavax/management/remote/MBeanServerForwarder;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"start", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"stop", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"toJMXConnector", "(Ljava/util/Map;)Ljavax/management/remote/JMXConnector;", "(Ljava/util/Map<Ljava/lang/String;*>;)Ljavax/management/remote/JMXConnector;", $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _RMIConnectorServer_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectorServer",
	"javax.management.remote.JMXConnectorServer",
	nullptr,
	_RMIConnectorServer_FieldInfo_,
	_RMIConnectorServer_MethodInfo_
};

$Object* allocate$RMIConnectorServer($Class* clazz) {
	return $of($alloc(RMIConnectorServer));
}

$String* RMIConnectorServer::JNDI_REBIND_ATTRIBUTE = nullptr;
$String* RMIConnectorServer::RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE = nullptr;
$String* RMIConnectorServer::RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE = nullptr;
$String* RMIConnectorServer::CREDENTIALS_FILTER_PATTERN = nullptr;
$String* RMIConnectorServer::SERIAL_FILTER_PATTERN = nullptr;
$chars* RMIConnectorServer::intToAlpha = nullptr;
$ClassLogger* RMIConnectorServer::logger = nullptr;
$Set* RMIConnectorServer::openedServers = nullptr;

void RMIConnectorServer::init$($JMXServiceURL* url, $Map* environment) {
	RMIConnectorServer::init$(url, environment, ($MBeanServer*)nullptr);
}

void RMIConnectorServer::init$($JMXServiceURL* url, $Map* environment, $MBeanServer* mbeanServer) {
	RMIConnectorServer::init$(url, environment, ($RMIServerImpl*)nullptr, mbeanServer);
}

void RMIConnectorServer::init$($JMXServiceURL* url, $Map* environment, $RMIServerImpl* rmiServerImpl, $MBeanServer* mbeanServer) {
	$useLocalCurrentObjectStackCache();
	$JMXConnectorServer::init$(mbeanServer);
	$set(this, defaultClassLoader, nullptr);
	this->state = RMIConnectorServer::CREATED;
	if (url == nullptr) {
		$throwNew($IllegalArgumentException, "Null JMXServiceURL"_s);
	}
	if (rmiServerImpl == nullptr) {
		$var($String, prt, $nc(url)->getProtocol());
		if (prt == nullptr || !($nc(prt)->equals("rmi"_s))) {
			$var($String, msg, $str({"Invalid protocol type: "_s, prt}));
			$throwNew($MalformedURLException, msg);
		}
		$var($String, urlPath, url->getURLPath());
		bool var$1 = !$nc(urlPath)->isEmpty();
		bool var$0 = var$1 && !urlPath->equals("/"_s);
		if (var$0 && !urlPath->startsWith("/jndi/"_s)) {
			$var($String, msg, "URL path must be empty or start with /jndi/"_s);
			$throwNew($MalformedURLException, msg);
		}
	}
	if (environment == nullptr) {
		$set(this, attributes, $Collections::emptyMap());
	} else {
		$EnvHelp::checkAttributes(environment);
		$set(this, attributes, $Collections::unmodifiableMap(environment));
	}
	$set(this, address, url);
	$set(this, rmiServerImpl, rmiServerImpl);
}

$JMXConnector* RMIConnectorServer::toJMXConnector($Map* env) {
	$useLocalCurrentObjectStackCache();
	if (!isActive()) {
		$throwNew($IllegalStateException, "Connector is not active"_s);
	}
	$var($Map, usemap, $new($HashMap, (this->attributes == nullptr) ? $($Collections::emptyMap()) : this->attributes));
	if (env != nullptr) {
		$EnvHelp::checkAttributes(env);
		usemap->putAll(env);
	}
	$assign(usemap, $EnvHelp::filterAttributes(usemap));
	$var($RMIServer, stub, $cast($RMIServer, $nc(this->rmiServerImpl)->toStub()));
	return $new($RMIConnector, stub, usemap);
}

void RMIConnectorServer::start() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		bool tracing = $nc(RMIConnectorServer::logger)->traceOn();
		if (this->state == RMIConnectorServer::STARTED) {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("start"_s, "already started"_s);
			}
			return;
		} else if (this->state == RMIConnectorServer::STOPPED) {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("start"_s, "already stopped"_s);
			}
			$throwNew($IOException, "The server has been stopped."_s);
		}
		if (getMBeanServer() == nullptr) {
			$throwNew($IllegalStateException, "This connector server is not attached to an MBean server"_s);
		}
		if (this->attributes != nullptr) {
			$var($String, accessFile, $cast($String, $nc(this->attributes)->get("jmx.remote.x.access.file"_s)));
			if (accessFile != nullptr) {
				$var($MBeanServerForwarder, mbsf, nullptr);
				try {
					$assign(mbsf, $new($MBeanServerFileAccessController, accessFile));
				} catch ($IOException& e) {
					$throw($cast($IllegalArgumentException, $($EnvHelp::initCause($$new($IllegalArgumentException, $(e->getMessage())), e))));
				}
				setMBeanServerForwarder(mbsf);
			}
		}
		try {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("start"_s, "setting default class loader"_s);
			}
			$set(this, defaultClassLoader, $EnvHelp::resolveServerClassLoader(this->attributes, $(getMBeanServer())));
		} catch ($InstanceNotFoundException& infc) {
			$var($IllegalArgumentException, x, $new($IllegalArgumentException, $$str({"ClassLoader not found: "_s, infc})));
			$throw($cast($IllegalArgumentException, $($EnvHelp::initCause(x, infc))));
		}
		if (tracing) {
			$nc(RMIConnectorServer::logger)->trace("start"_s, "setting RMIServer object"_s);
		}
		$var($RMIServerImpl, rmiServer, nullptr);
		if (this->rmiServerImpl != nullptr) {
			$assign(rmiServer, this->rmiServerImpl);
		} else {
			$assign(rmiServer, newServer());
		}
		$nc(rmiServer)->setMBeanServer($(getMBeanServer()));
		rmiServer->setDefaultClassLoader(this->defaultClassLoader);
		rmiServer->setRMIConnectorServer(this);
		rmiServer->export$();
		try {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("start"_s, "getting RMIServer object to export"_s);
			}
			$var($RMIServer, objref, objectToBind(rmiServer, this->attributes));
			if (this->address != nullptr && $nc($($nc(this->address)->getURLPath()))->startsWith("/jndi/"_s)) {
				$var($String, jndiUrl, $nc($($nc(this->address)->getURLPath()))->substring(6));
				if (tracing) {
					$nc(RMIConnectorServer::logger)->trace("start"_s, $$str({"Using external directory: "_s, jndiUrl}));
				}
				$var($String, stringBoolean, $cast($String, $nc(this->attributes)->get(RMIConnectorServer::JNDI_REBIND_ATTRIBUTE)));
				bool rebind = $EnvHelp::computeBooleanFromString(stringBoolean);
				if (tracing) {
					$nc(RMIConnectorServer::logger)->trace("start"_s, $$str({RMIConnectorServer::JNDI_REBIND_ATTRIBUTE, "="_s, $$str(rebind)}));
				}
				try {
					if (tracing) {
						$nc(RMIConnectorServer::logger)->trace("start"_s, $$str({"binding to "_s, jndiUrl}));
					}
					$var($Hashtable, usemap, $EnvHelp::mapToHashtable(this->attributes));
					bind(jndiUrl, usemap, objref, rebind);
					$set(this, boundJndiUrl, jndiUrl);
				} catch ($NamingException& e) {
					$throw($(newIOException($$str({"Cannot bind to URL ["_s, jndiUrl, "]: "_s, e}), e)));
				}
			} else {
				if (tracing) {
					$nc(RMIConnectorServer::logger)->trace("start"_s, "Encoding URL"_s);
				}
				encodeStubInAddress(objref, this->attributes);
				if (tracing) {
					$nc(RMIConnectorServer::logger)->trace("start"_s, $$str({"Encoded URL: "_s, this->address}));
				}
			}
		} catch ($Exception& e) {
			try {
				rmiServer->close();
			} catch ($Exception& x) {
			}
			if ($instanceOf($RuntimeException, e)) {
				$throw($cast($RuntimeException, e));
			} else if ($instanceOf($IOException, e)) {
				$throw($cast($IOException, e));
			} else {
				$throw($(newIOException($$str({"Got unexpected exception while starting the connector server: "_s, e}), e)));
			}
		}
		$set(this, rmiServerImpl, rmiServer);
		$synchronized(RMIConnectorServer::openedServers) {
			$nc(RMIConnectorServer::openedServers)->add(this);
		}
		this->state = RMIConnectorServer::STARTED;
		if (tracing) {
			$nc(RMIConnectorServer::logger)->trace("start"_s, $$str({"Connector Server Address = "_s, this->address}));
			$nc(RMIConnectorServer::logger)->trace("start"_s, "started."_s);
		}
	}
}

void RMIConnectorServer::stop() {
	$useLocalCurrentObjectStackCache();
	bool tracing = $nc(RMIConnectorServer::logger)->traceOn();
	$synchronized(this) {
		if (this->state == RMIConnectorServer::STOPPED) {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("stop"_s, "already stopped."_s);
			}
			return;
		} else if (this->state == RMIConnectorServer::CREATED) {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("stop"_s, "not started yet."_s);
			}
		}
		if (tracing) {
			$nc(RMIConnectorServer::logger)->trace("stop"_s, "stopping."_s);
		}
		this->state = RMIConnectorServer::STOPPED;
	}
	$synchronized(RMIConnectorServer::openedServers) {
		$nc(RMIConnectorServer::openedServers)->remove(this);
	}
	$var($IOException, exception, nullptr);
	if (this->rmiServerImpl != nullptr) {
		try {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("stop"_s, "closing RMI server."_s);
			}
			$nc(this->rmiServerImpl)->close();
		} catch ($IOException& e) {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("stop"_s, $$str({"failed to close RMI server: "_s, e}));
			}
			if ($nc(RMIConnectorServer::logger)->debugOn()) {
				$nc(RMIConnectorServer::logger)->debug("stop"_s, static_cast<$Throwable*>(e));
			}
			$assign(exception, e);
		}
	}
	if (this->boundJndiUrl != nullptr) {
		try {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("stop"_s, $$str({"unbind from external directory: "_s, this->boundJndiUrl}));
			}
			$var($Hashtable, usemap, $EnvHelp::mapToHashtable(this->attributes));
			$var($InitialContext, ctx, $new($InitialContext, usemap));
			ctx->unbind(this->boundJndiUrl);
			ctx->close();
		} catch ($NamingException& e) {
			if (tracing) {
				$nc(RMIConnectorServer::logger)->trace("stop"_s, $$str({"failed to unbind RMI server: "_s, e}));
			}
			if ($nc(RMIConnectorServer::logger)->debugOn()) {
				$nc(RMIConnectorServer::logger)->debug("stop"_s, static_cast<$Throwable*>(e));
			}
			if (exception == nullptr) {
				$assign(exception, newIOException($$str({"Cannot bind to URL: "_s, e}), e));
			}
		}
	}
	if (exception != nullptr) {
		$throw(exception);
	}
	if (tracing) {
		$nc(RMIConnectorServer::logger)->trace("stop"_s, "stopped"_s);
	}
}

bool RMIConnectorServer::isActive() {
	$synchronized(this) {
		return (this->state == RMIConnectorServer::STARTED);
	}
}

$JMXServiceURL* RMIConnectorServer::getAddress() {
	if (!isActive()) {
		return nullptr;
	}
	return this->address;
}

$Map* RMIConnectorServer::getAttributes() {
	$var($Map, map, $EnvHelp::filterAttributes(this->attributes));
	return $Collections::unmodifiableMap(map);
}

void RMIConnectorServer::setMBeanServerForwarder($MBeanServerForwarder* mbsf) {
	$synchronized(this) {
		$JMXConnectorServer::setMBeanServerForwarder(mbsf);
		if (this->rmiServerImpl != nullptr) {
			$nc(this->rmiServerImpl)->setMBeanServer($(getMBeanServer()));
		}
	}
}

void RMIConnectorServer::connectionOpened($String* connectionId, $String* message, Object$* userData) {
	$JMXConnectorServer::connectionOpened(connectionId, message, userData);
}

void RMIConnectorServer::connectionClosed($String* connectionId, $String* message, Object$* userData) {
	$JMXConnectorServer::connectionClosed(connectionId, message, userData);
}

void RMIConnectorServer::connectionFailed($String* connectionId, $String* message, Object$* userData) {
	$JMXConnectorServer::connectionFailed(connectionId, message, userData);
}

void RMIConnectorServer::bind($String* jndiUrl, $Hashtable* attributes, $RMIServer* rmiServer, bool rebind) {
	$var($InitialContext, ctx, $new($InitialContext, attributes));
	if (rebind) {
		ctx->rebind(jndiUrl, $of(rmiServer));
	} else {
		ctx->bind(jndiUrl, $of(rmiServer));
	}
	ctx->close();
}

$RMIServerImpl* RMIConnectorServer::newServer() {
	int32_t port = 0;
	if (this->address == nullptr) {
		port = 0;
	} else {
		port = $nc(this->address)->getPort();
	}
	return newJRMPServer(this->attributes, port);
}

void RMIConnectorServer::encodeStubInAddress($RMIServer* rmiServer, $Map* attributes) {
	$useLocalCurrentObjectStackCache();
	$var($String, protocol, nullptr);
	$var($String, host, nullptr);
	int32_t port = 0;
	if (this->address == nullptr) {
		$assign(protocol, "rmi"_s);
		$assign(host, nullptr);
		port = 0;
	} else {
		$assign(protocol, $nc(this->address)->getProtocol());
		$assign(host, ($nc($($nc(this->address)->getHost()))->isEmpty()) ? ($String*)nullptr : $nc(this->address)->getHost());
		port = $nc(this->address)->getPort();
	}
	$var($String, urlPath, encodeStub(rmiServer, attributes));
	$set(this, address, $new($JMXServiceURL, protocol, host, port, urlPath));
}

$String* RMIConnectorServer::encodeStub($RMIServer* rmiServer, $Map* env) {
	$init(RMIConnectorServer);
	return $str({"/stub/"_s, $(encodeJRMPStub(rmiServer, env))});
}

$String* RMIConnectorServer::encodeJRMPStub($RMIServer* rmiServer, $Map* env) {
	$init(RMIConnectorServer);
	$useLocalCurrentObjectStackCache();
	$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream));
	$var($ObjectOutputStream, oout, $new($ObjectOutputStream, bout));
	oout->writeObject(rmiServer);
	oout->close();
	$var($bytes, bytes, bout->toByteArray());
	return byteArrayToBase64(bytes);
}

$RMIServer* RMIConnectorServer::objectToBind($RMIServerImpl* rmiServer, $Map* env) {
	$init(RMIConnectorServer);
	return $cast($RMIServer, $nc(rmiServer)->toStub());
}

$RMIServerImpl* RMIConnectorServer::newJRMPServer($Map* env, int32_t port) {
	$init(RMIConnectorServer);
	$useLocalCurrentObjectStackCache();
	$var($RMIClientSocketFactory, csf, $cast($RMIClientSocketFactory, $nc(env)->get(RMIConnectorServer::RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE)));
	$var($RMIServerSocketFactory, ssf, $cast($RMIServerSocketFactory, env->get(RMIConnectorServer::RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE)));
	return $new($RMIJRMPServerImpl, port, csf, ssf, env);
}

$String* RMIConnectorServer::byteArrayToBase64($bytes* a) {
	$init(RMIConnectorServer);
	int32_t aLen = $nc(a)->length;
	int32_t numFullGroups = aLen / 3;
	int32_t numBytesInPartialGroup = aLen - 3 * numFullGroups;
	int32_t resultLen = 4 * ((aLen + 2) / 3);
	$var($StringBuilder, result, $new($StringBuilder, resultLen));
	int32_t inCursor = 0;
	for (int32_t i = 0; i < numFullGroups; ++i) {
		int32_t byte0 = (int32_t)(a->get(inCursor++) & (uint32_t)255);
		int32_t byte1 = (int32_t)(a->get(inCursor++) & (uint32_t)255);
		int32_t byte2 = (int32_t)(a->get(inCursor++) & (uint32_t)255);
		result->append($nc(RMIConnectorServer::intToAlpha)->get(byte0 >> 2));
		result->append($nc(RMIConnectorServer::intToAlpha)->get(((int32_t)((byte0 << 4) & (uint32_t)63)) | (byte1 >> 4)));
		result->append($nc(RMIConnectorServer::intToAlpha)->get(((int32_t)((byte1 << 2) & (uint32_t)63)) | (byte2 >> 6)));
		result->append($nc(RMIConnectorServer::intToAlpha)->get((int32_t)(byte2 & (uint32_t)63)));
	}
	if (numBytesInPartialGroup != 0) {
		int32_t byte0 = (int32_t)(a->get(inCursor++) & (uint32_t)255);
		result->append($nc(RMIConnectorServer::intToAlpha)->get(byte0 >> 2));
		if (numBytesInPartialGroup == 1) {
			result->append($nc(RMIConnectorServer::intToAlpha)->get((int32_t)((byte0 << 4) & (uint32_t)63)));
			result->append("=="_s);
		} else {
			int32_t byte1 = (int32_t)(a->get(inCursor++) & (uint32_t)255);
			result->append($nc(RMIConnectorServer::intToAlpha)->get(((int32_t)((byte0 << 4) & (uint32_t)63)) | (byte1 >> 4)));
			result->append($nc(RMIConnectorServer::intToAlpha)->get((int32_t)((byte1 << 2) & (uint32_t)63)));
			result->append(u'=');
		}
	}
	return result->toString();
}

$IOException* RMIConnectorServer::newIOException($String* message, $Throwable* cause) {
	$init(RMIConnectorServer);
	$var($IOException, x, $new($IOException, message));
	return $cast($IOException, $EnvHelp::initCause(x, cause));
}

void clinit$RMIConnectorServer($Class* class$) {
	$assignStatic(RMIConnectorServer::JNDI_REBIND_ATTRIBUTE, "jmx.remote.jndi.rebind"_s);
	$assignStatic(RMIConnectorServer::RMI_CLIENT_SOCKET_FACTORY_ATTRIBUTE, "jmx.remote.rmi.client.socket.factory"_s);
	$assignStatic(RMIConnectorServer::RMI_SERVER_SOCKET_FACTORY_ATTRIBUTE, "jmx.remote.rmi.server.socket.factory"_s);
	$assignStatic(RMIConnectorServer::CREDENTIALS_FILTER_PATTERN, "jmx.remote.rmi.server.credentials.filter.pattern"_s);
	$assignStatic(RMIConnectorServer::SERIAL_FILTER_PATTERN, "jmx.remote.rmi.server.serial.filter.pattern"_s);
	$assignStatic(RMIConnectorServer::intToAlpha, $new($chars, {
		u'A',
		u'B',
		u'C',
		u'D',
		u'E',
		u'F',
		u'G',
		u'H',
		u'I',
		u'J',
		u'K',
		u'L',
		u'M',
		u'N',
		u'O',
		u'P',
		u'Q',
		u'R',
		u'S',
		u'T',
		u'U',
		u'V',
		u'W',
		u'X',
		u'Y',
		u'Z',
		u'a',
		u'b',
		u'c',
		u'd',
		u'e',
		u'f',
		u'g',
		u'h',
		u'i',
		u'j',
		u'k',
		u'l',
		u'm',
		u'n',
		u'o',
		u'p',
		u'q',
		u'r',
		u's',
		u't',
		u'u',
		u'v',
		u'w',
		u'x',
		u'y',
		u'z',
		u'0',
		u'1',
		u'2',
		u'3',
		u'4',
		u'5',
		u'6',
		u'7',
		u'8',
		u'9',
		u'+',
		u'/'
	}));
	$assignStatic(RMIConnectorServer::logger, $new($ClassLogger, "javax.management.remote.rmi"_s, "RMIConnectorServer"_s));
	$assignStatic(RMIConnectorServer::openedServers, $new($HashSet));
}

RMIConnectorServer::RMIConnectorServer() {
}

$Class* RMIConnectorServer::load$($String* name, bool initialize) {
	$loadClass(RMIConnectorServer, name, initialize, &_RMIConnectorServer_ClassInfo_, clinit$RMIConnectorServer, allocate$RMIConnectorServer);
	return class$;
}

$Class* RMIConnectorServer::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax