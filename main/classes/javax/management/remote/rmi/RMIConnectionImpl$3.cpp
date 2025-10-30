#include <javax/management/remote/rmi/RMIConnectionImpl$3.h>

#include <java/lang/ClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;
using $RMIConnectionImpl$CombinedClassLoader = ::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$3_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$3, this$0)},
	{"val$dcl", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$3, val$dcl)},
	{}
};

$MethodInfo _RMIConnectionImpl$3_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;Ljava/lang/ClassLoader;)V", "()V", 0, $method(static_cast<void(RMIConnectionImpl$3::*)($RMIConnectionImpl*,$ClassLoader*)>(&RMIConnectionImpl$3::init$))},
	{"run", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$3_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"<init>",
	"(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/lang/String;Ljava/lang/ClassLoader;Ljavax/security/auth/Subject;Ljava/util/Map;)V"
};

$InnerClassInfo _RMIConnectionImpl$3_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$3_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RMIConnectionImpl$3_FieldInfo_,
	_RMIConnectionImpl$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/ClassLoader;>;",
	&_RMIConnectionImpl$3_EnclosingMethodInfo_,
	_RMIConnectionImpl$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$3($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$3));
}

void RMIConnectionImpl$3::init$($RMIConnectionImpl* this$0, $ClassLoader* val$dcl) {
	$set(this, this$0, this$0);
	$set(this, val$dcl, val$dcl);
}

$Object* RMIConnectionImpl$3::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $of($new($RMIConnectionImpl$CombinedClassLoader, $($($Thread::currentThread())->getContextClassLoader()), this->val$dcl));
}

RMIConnectionImpl$3::RMIConnectionImpl$3() {
}

$Class* RMIConnectionImpl$3::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$3, name, initialize, &_RMIConnectionImpl$3_ClassInfo_, allocate$RMIConnectionImpl$3);
	return class$;
}

$Class* RMIConnectionImpl$3::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax