#include <javax/management/remote/rmi/RMIJRMPServerImpl.h>

#include <com/sun/jmx/remote/internal/rmi/RMIExporter.h>
#include <com/sun/jmx/remote/util/EnvHelp.h>
#include <java/io/ObjectInputFilter$Config.h>
#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/UnicastRemoteObject.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Predicate.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <javax/management/remote/rmi/RMIConnection.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <javax/management/remote/rmi/RMIConnectorServer.h>
#include <javax/management/remote/rmi/RMIServer.h>
#include <javax/management/remote/rmi/RMIServerImpl.h>
#include <javax/security/auth/Subject.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/UnicastServerRef2.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

#undef ALLOWED
#undef CREDENTIALS_FILTER_PATTERN
#undef EXPORTER_ATTRIBUTE
#undef JMX_SERVER_DAEMON
#undef REJECTED
#undef SERIAL_FILTER_PATTERN
#undef UNDECIDED

using $RMIExporter = ::com::sun::jmx::remote::internal::rmi::RMIExporter;
using $EnvHelp = ::com::sun::jmx::remote::util::EnvHelp;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$Config = ::java::io::ObjectInputFilter$Config;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Remote = ::java::rmi::Remote;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $UnicastRemoteObject = ::java::rmi::server::UnicastRemoteObject;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Predicate = ::java::util::function::Predicate;
using $Collector = ::java::util::stream::Collector;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $RMIConnection = ::javax::management::remote::rmi::RMIConnection;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;
using $RMIConnectorServer = ::javax::management::remote::rmi::RMIConnectorServer;
using $RMIServer = ::javax::management::remote::rmi::RMIServer;
using $RMIServerImpl = ::javax::management::remote::rmi::RMIServerImpl;
using $Subject = ::javax::security::auth::Subject;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $UnicastServerRef2 = ::sun::rmi::server::UnicastServerRef2;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIJRMPServerImpl$$Lambda$lambda$new$0 : public $Predicate {
	$class(RMIJRMPServerImpl$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* s) override {
		 return RMIJRMPServerImpl::lambda$new$0($cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RMIJRMPServerImpl$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RMIJRMPServerImpl$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RMIJRMPServerImpl$$Lambda$lambda$new$0::*)()>(&RMIJRMPServerImpl$$Lambda$lambda$new$0::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo RMIJRMPServerImpl$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"javax.management.remote.rmi.RMIJRMPServerImpl$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* RMIJRMPServerImpl$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(RMIJRMPServerImpl$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RMIJRMPServerImpl$$Lambda$lambda$new$0::class$ = nullptr;

class RMIJRMPServerImpl$$Lambda$checkPackageAccess$1 : public $Consumer {
	$class(RMIJRMPServerImpl$$Lambda$checkPackageAccess$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* arg0) override {
		$ReflectUtil::checkPackageAccess($cast($String, arg0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RMIJRMPServerImpl$$Lambda$checkPackageAccess$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::*)()>(&RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"javax.management.remote.rmi.RMIJRMPServerImpl$$Lambda$checkPackageAccess$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::load$($String* name, bool initialize) {
	$loadClass(RMIJRMPServerImpl$$Lambda$checkPackageAccess$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::class$ = nullptr;

class RMIJRMPServerImpl$$Lambda$newClientCheckInput$2 : public $ObjectInputFilter {
	$class(RMIJRMPServerImpl$$Lambda$newClientCheckInput$2, $NO_CLASS_INIT, $ObjectInputFilter)
public:
	void init$(RMIJRMPServerImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $ObjectInputFilter$Status* checkInput($ObjectInputFilter$FilterInfo* filterInfo) override {
		 return $nc(inst$)->newClientCheckInput(filterInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RMIJRMPServerImpl$$Lambda$newClientCheckInput$2>());
	}
	RMIJRMPServerImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(RMIJRMPServerImpl$$Lambda$newClientCheckInput$2, inst$)},
	{}
};
$MethodInfo RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::methodInfos[3] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIJRMPServerImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::*)(RMIJRMPServerImpl*)>(&RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::init$))},
	{"checkInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"javax.management.remote.rmi.RMIJRMPServerImpl$$Lambda$newClientCheckInput$2",
	"java.lang.Object",
	"java.io.ObjectInputFilter",
	fieldInfos,
	methodInfos
};
$Class* RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::load$($String* name, bool initialize) {
	$loadClass(RMIJRMPServerImpl$$Lambda$newClientCheckInput$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::class$ = nullptr;

$FieldInfo _RMIJRMPServerImpl_FieldInfo_[] = {
	{"port", "I", nullptr, $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, port)},
	{"csf", "Ljava/rmi/server/RMIClientSocketFactory;", nullptr, $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, csf)},
	{"ssf", "Ljava/rmi/server/RMIServerSocketFactory;", nullptr, $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, ssf)},
	{"env", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;*>;", $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, env)},
	{"allowedTypes", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, allowedTypes)},
	{"jmxRmiFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, jmxRmiFilter)},
	{"cFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $FINAL, $field(RMIJRMPServerImpl, cFilter)},
	{}
};

$MethodInfo _RMIJRMPServerImpl_MethodInfo_[] = {
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/util/Map;)V", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(RMIJRMPServerImpl::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*,$Map*)>(&RMIJRMPServerImpl::init$)), "java.io.IOException"},
	{"closeClient", "(Ljavax/management/remote/rmi/RMIConnection;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"closeServer", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"export", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"export", "(Ljava/rmi/Remote;Ljava/io/ObjectInputFilter;)V", nullptr, $PRIVATE, $method(static_cast<void(RMIJRMPServerImpl::*)($Remote*,$ObjectInputFilter*)>(&RMIJRMPServerImpl::export$)), "java.rmi.RemoteException"},
	{"getProtocol", "()Ljava/lang/String;", nullptr, $PROTECTED},
	{"lambda$new$0", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*)>(&RMIJRMPServerImpl::lambda$new$0))},
	{"makeClient", "(Ljava/lang/String;Ljavax/security/auth/Subject;)Ljavax/management/remote/rmi/RMIConnection;", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"newClientCheckInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, 0},
	{"toStub", "()Ljava/rmi/Remote;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"unexport", "(Ljava/rmi/Remote;Z)V", nullptr, $PRIVATE, $method(static_cast<void(RMIJRMPServerImpl::*)($Remote*,bool)>(&RMIJRMPServerImpl::unexport)), "java.rmi.NoSuchObjectException"},
	{}
};

$ClassInfo _RMIJRMPServerImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.management.remote.rmi.RMIJRMPServerImpl",
	"javax.management.remote.rmi.RMIServerImpl",
	nullptr,
	_RMIJRMPServerImpl_FieldInfo_,
	_RMIJRMPServerImpl_MethodInfo_
};

$Object* allocate$RMIJRMPServerImpl($Class* clazz) {
	return $of($alloc(RMIJRMPServerImpl));
}

void RMIJRMPServerImpl::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf, $Map* env) {
	$useLocalCurrentObjectStackCache();
	$RMIServerImpl::init$(env);
	if (port < 0) {
		$throwNew($IllegalArgumentException, $$str({"Negative port: "_s, $$str(port)}));
	}
	this->port = port;
	$set(this, csf, csf);
	$set(this, ssf, ssf);
	$set(this, env, (env == nullptr) ? $Collections::emptyMap() : env);
	$var($StringArray, credentialsTypes, $cast($StringArray, $nc(this->env)->get("jmx.remote.rmi.server.credential.types"_s)));
	$init($RMIConnectorServer);
	$var($String, credentialsFilter, $cast($String, $nc(this->env)->get($RMIConnectorServer::CREDENTIALS_FILTER_PATTERN)));
	if (credentialsTypes != nullptr && credentialsFilter != nullptr) {
		$throwNew($IllegalArgumentException, $$str({"Cannot specify both \"jmx.remote.rmi.server.credential.types\" and \""_s, $RMIConnectorServer::CREDENTIALS_FILTER_PATTERN, "\""_s}));
	} else if (credentialsFilter != nullptr) {
		$set(this, cFilter, $ObjectInputFilter$Config::createFilter(credentialsFilter));
		$set(this, allowedTypes, nullptr);
	} else if (credentialsTypes != nullptr) {
		$set(this, allowedTypes, $cast($Set, $nc($($nc($($Arrays::stream(credentialsTypes)))->filter(static_cast<$Predicate*>($$new(RMIJRMPServerImpl$$Lambda$lambda$new$0)))))->collect($($Collectors::toSet()))));
		$nc($($nc(this->allowedTypes)->stream()))->forEach(static_cast<$Consumer*>($$new(RMIJRMPServerImpl$$Lambda$checkPackageAccess$1)));
		$set(this, cFilter, static_cast<$ObjectInputFilter*>($new(RMIJRMPServerImpl$$Lambda$newClientCheckInput$2, this)));
	} else {
		$set(this, allowedTypes, nullptr);
		$set(this, cFilter, nullptr);
	}
	$var($String, userJmxFilter, $cast($String, $nc(this->env)->get($RMIConnectorServer::SERIAL_FILTER_PATTERN)));
	if (userJmxFilter != nullptr && !userJmxFilter->isEmpty()) {
		$set(this, jmxRmiFilter, $ObjectInputFilter$Config::createFilter(userJmxFilter));
	} else {
		$set(this, jmxRmiFilter, nullptr);
	}
}

void RMIJRMPServerImpl::export$() {
	export$(this, this->cFilter);
}

void RMIJRMPServerImpl::export$($Remote* obj, $ObjectInputFilter* typeFilter) {
	$useLocalCurrentObjectStackCache();
	$init($RMIExporter);
	$var($RMIExporter, exporter, $cast($RMIExporter, $nc(this->env)->get($RMIExporter::EXPORTER_ATTRIBUTE)));
	bool daemon = $EnvHelp::isServerDaemon(this->env);
	if (daemon && exporter != nullptr) {
		$throwNew($IllegalArgumentException, $$str({"If "_s, $EnvHelp::JMX_SERVER_DAEMON, " is specified as true, "_s, $RMIExporter::EXPORTER_ATTRIBUTE, " cannot be used to specify an exporter!"_s}));
	}
	if (exporter != nullptr) {
		exporter->exportObject(obj, this->port, this->csf, this->ssf, typeFilter);
	} else if (this->csf == nullptr && this->ssf == nullptr) {
		$$new($UnicastServerRef, $$new($LiveRef, this->port), typeFilter)->exportObject(obj, nullptr, daemon);
	} else {
		$$new($UnicastServerRef2, this->port, this->csf, this->ssf, typeFilter)->exportObject(obj, nullptr, daemon);
	}
}

void RMIJRMPServerImpl::unexport($Remote* obj, bool force) {
	$init($RMIExporter);
	$var($RMIExporter, exporter, $cast($RMIExporter, $nc(this->env)->get($RMIExporter::EXPORTER_ATTRIBUTE)));
	if (exporter == nullptr) {
		$UnicastRemoteObject::unexportObject(obj, force);
	} else {
		$nc(exporter)->unexportObject(obj, force);
	}
}

$String* RMIJRMPServerImpl::getProtocol() {
	return "rmi"_s;
}

$Remote* RMIJRMPServerImpl::toStub() {
	return $RemoteObject::toStub(this);
}

$RMIConnection* RMIJRMPServerImpl::makeClient($String* connectionId, $Subject* subject) {
	$useLocalCurrentObjectStackCache();
	if (connectionId == nullptr) {
		$throwNew($NullPointerException, "Null connectionId"_s);
	}
	$var($RMIConnection, client, $new($RMIConnectionImpl, this, connectionId, $(getDefaultClassLoader()), subject, this->env));
	export$(client, this->jmxRmiFilter);
	return client;
}

void RMIJRMPServerImpl::closeClient($RMIConnection* client) {
	unexport(client, true);
}

void RMIJRMPServerImpl::closeServer() {
	unexport(this, true);
}

$ObjectInputFilter$Status* RMIJRMPServerImpl::newClientCheckInput($ObjectInputFilter$FilterInfo* filterInfo) {
	$init($ObjectInputFilter$Status);
	$ObjectInputFilter$Status* status = $ObjectInputFilter$Status::UNDECIDED;
	if (this->allowedTypes != nullptr && $nc(filterInfo)->serialClass() != nullptr) {
		$var($String, type, $nc(filterInfo->serialClass())->getName());
		if ($nc(this->allowedTypes)->contains(type)) {
			status = $ObjectInputFilter$Status::ALLOWED;
		} else {
			status = $ObjectInputFilter$Status::REJECTED;
		}
	}
	return status;
}

bool RMIJRMPServerImpl::lambda$new$0($String* s) {
	$init(RMIJRMPServerImpl);
	return s != nullptr;
}

RMIJRMPServerImpl::RMIJRMPServerImpl() {
}

$Class* RMIJRMPServerImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RMIJRMPServerImpl$$Lambda$lambda$new$0::classInfo$.name)) {
			return RMIJRMPServerImpl$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::classInfo$.name)) {
			return RMIJRMPServerImpl$$Lambda$checkPackageAccess$1::load$(name, initialize);
		}
		if (name->equals(RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::classInfo$.name)) {
			return RMIJRMPServerImpl$$Lambda$newClientCheckInput$2::load$(name, initialize);
		}
	}
	$loadClass(RMIJRMPServerImpl, name, initialize, &_RMIJRMPServerImpl_ClassInfo_, allocate$RMIJRMPServerImpl);
	return class$;
}

$Class* RMIJRMPServerImpl::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax