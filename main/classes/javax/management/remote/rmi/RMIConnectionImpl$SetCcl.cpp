#include <javax/management/remote/rmi/RMIConnectionImpl$SetCcl.h>

#include <java/lang/ClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$SetCcl_FieldInfo_[] = {
	{"classLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(RMIConnectionImpl$SetCcl, classLoader)},
	{}
};

$MethodInfo _RMIConnectionImpl$SetCcl_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, 0, $method(static_cast<void(RMIConnectionImpl$SetCcl::*)($ClassLoader*)>(&RMIConnectionImpl$SetCcl::init$))},
	{"run", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _RMIConnectionImpl$SetCcl_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$SetCcl", "javax.management.remote.rmi.RMIConnectionImpl", "SetCcl", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _RMIConnectionImpl$SetCcl_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$SetCcl",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RMIConnectionImpl$SetCcl_FieldInfo_,
	_RMIConnectionImpl$SetCcl_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/ClassLoader;>;",
	nullptr,
	_RMIConnectionImpl$SetCcl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$SetCcl($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$SetCcl));
}

void RMIConnectionImpl$SetCcl::init$($ClassLoader* classLoader) {
	$set(this, classLoader, classLoader);
}

$Object* RMIConnectionImpl$SetCcl::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Thread, currentThread, $Thread::currentThread());
	$var($ClassLoader, old, currentThread->getContextClassLoader());
	currentThread->setContextClassLoader(this->classLoader);
	return $of(old);
}

RMIConnectionImpl$SetCcl::RMIConnectionImpl$SetCcl() {
}

$Class* RMIConnectionImpl$SetCcl::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$SetCcl, name, initialize, &_RMIConnectionImpl$SetCcl_ClassInfo_, allocate$RMIConnectionImpl$SetCcl);
	return class$;
}

$Class* RMIConnectionImpl$SetCcl::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax