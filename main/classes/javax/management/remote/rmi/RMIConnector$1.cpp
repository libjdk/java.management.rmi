#include <javax/management/remote/rmi/RMIConnector$1.h>

#include <com/sun/jmx/remote/internal/rmi/ProxyRef.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Module.h>
#include <java/lang/module/ModuleDescriptor$Builder.h>
#include <java/lang/module/ModuleDescriptor$Modifier.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/reflect/Constructor.h>
#include <java/net/URI.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/Set.h>
#include <javax/management/remote/rmi/NoCallStackClassLoader.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <jdk/internal/module/Modules.h>
#include <jcpp.h>

#undef SYNTHETIC

using $ProxyRef = ::com::sun::jmx::remote::internal::rmi::ProxyRef;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Builder = ::java::lang::module::ModuleDescriptor$Builder;
using $ModuleDescriptor$Modifier = ::java::lang::module::ModuleDescriptor$Modifier;
using $Constructor = ::java::lang::reflect::Constructor;
using $URI = ::java::net::URI;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $Set = ::java::util::Set;
using $NoCallStackClassLoader = ::javax::management::remote::rmi::NoCallStackClassLoader;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;
using $Modules = ::jdk::internal::module::Modules;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnector$1_FieldInfo_[] = {
	{"val$pRefByteCode", "[B", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$1, val$pRefByteCode)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(RMIConnector$1, $assertionsDisabled)},
	{}
};

$MethodInfo _RMIConnector$1_MethodInfo_[] = {
	{"<init>", "([B)V", "()V", 0, $method(static_cast<void(RMIConnector$1::*)($bytes*)>(&RMIConnector$1::init$))},
	{"run", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<*>;", $PUBLIC, nullptr, "java.lang.Exception"},
	{}
};

$EnclosingMethodInfo _RMIConnector$1_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnector",
	nullptr,
	nullptr
};

$InnerClassInfo _RMIConnector$1_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnector$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RMIConnector$1_FieldInfo_,
	_RMIConnector$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/reflect/Constructor<*>;>;",
	&_RMIConnector$1_EnclosingMethodInfo_,
	_RMIConnector$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$1($Class* clazz) {
	return $of($alloc(RMIConnector$1));
}

bool RMIConnector$1::$assertionsDisabled = false;

void RMIConnector$1::init$($bytes* val$pRefByteCode) {
	$set(this, val$pRefByteCode, val$pRefByteCode);
}

$Object* RMIConnector$1::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$load($RMIConnector);
	$Class* thisClass = $RMIConnector::class$;
	$var($ClassLoader, thisLoader, $nc(thisClass)->getClassLoader());
	$var($ProtectionDomain, thisProtectionDomain, thisClass->getProtectionDomain());
	$load($ProxyRef);
	$var($String, proxyRefCName, $ProxyRef::class$->getName());
	$var($ClassLoader, cl, $new($NoCallStackClassLoader, "jdk.jmx.remote.internal.rmi.PRef"_s, this->val$pRefByteCode, $$new($StringArray, {proxyRefCName}), thisLoader, thisProtectionDomain));
	$var($Module, jmxModule, $ProxyRef::class$->getModule());
	$load($RemoteRef);
	$var($Module, rmiModule, $RemoteRef::class$->getModule());
	$var($String, pkg, $RMIConnector::packageOf("jdk.jmx.remote.internal.rmi.PRef"_s));
	bool var$0 = !RMIConnector$1::$assertionsDisabled;
	if (var$0) {
		bool var$1 = pkg != nullptr && pkg->length() > 0;
		var$0 = !(var$1 && !pkg->equals($($RMIConnector::packageOf(proxyRefCName))));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$init($ModuleDescriptor$Modifier);
	$var($ModuleDescriptor, descriptor, $nc($($nc($($ModuleDescriptor::newModule("jdk.remoteref"_s, $($Set::of($of($ModuleDescriptor$Modifier::SYNTHETIC))))))->packages($($Set::of($of(pkg))))))->build());
	$var($Module, m, $Modules::defineModule(cl, descriptor, nullptr));
	$Modules::addReads(m, $($Object::class$->getModule()));
	$Modules::addReads(m, jmxModule);
	$Modules::addReads(m, rmiModule);
	$Modules::addExports(jmxModule, $($RMIConnector::packageOf(proxyRefCName)), m);
	$Modules::addReads(jmxModule, m);
	$Modules::addExports(m, pkg, jmxModule);
	$Class* c = cl->loadClass("jdk.jmx.remote.internal.rmi.PRef"_s);
	return $of($nc(c)->getConstructor($$new($ClassArray, {$RemoteRef::class$})));
}

void clinit$RMIConnector$1($Class* class$) {
	$load($RMIConnector);
	RMIConnector$1::$assertionsDisabled = !$RMIConnector::class$->desiredAssertionStatus();
}

RMIConnector$1::RMIConnector$1() {
}

$Class* RMIConnector$1::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$1, name, initialize, &_RMIConnector$1_ClassInfo_, clinit$RMIConnector$1, allocate$RMIConnector$1);
	return class$;
}

$Class* RMIConnector$1::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax