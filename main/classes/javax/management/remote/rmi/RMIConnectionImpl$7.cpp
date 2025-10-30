#include <javax/management/remote/rmi/RMIConnectionImpl$7.h>

#include <com/sun/jmx/remote/util/OrderClassLoaders.h>
#include <java/lang/ClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $OrderClassLoaders = ::com::sun::jmx::remote::util::OrderClassLoaders;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;
using $RMIConnectionImpl$CombinedClassLoader = ::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$7_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$7, this$0)},
	{"val$cl2", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$7, val$cl2)},
	{"val$cl1", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$7, val$cl1)},
	{}
};

$MethodInfo _RMIConnectionImpl$7_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)V", "()V", 0, $method(static_cast<void(RMIConnectionImpl$7::*)($RMIConnectionImpl*,$ClassLoader*,$ClassLoader*)>(&RMIConnectionImpl$7::init$))},
	{"run", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$7_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"unwrap",
	"(Ljava/rmi/MarshalledObject;Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;Ljava/lang/Class;Ljavax/security/auth/Subject;)Ljava/lang/Object;"
};

$InnerClassInfo _RMIConnectionImpl$7_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$7", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$7_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$7",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RMIConnectionImpl$7_FieldInfo_,
	_RMIConnectionImpl$7_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/ClassLoader;>;",
	&_RMIConnectionImpl$7_EnclosingMethodInfo_,
	_RMIConnectionImpl$7_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$7($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$7));
}

void RMIConnectionImpl$7::init$($RMIConnectionImpl* this$0, $ClassLoader* val$cl1, $ClassLoader* val$cl2) {
	$set(this, this$0, this$0);
	$set(this, val$cl1, val$cl1);
	$set(this, val$cl2, val$cl2);
}

$Object* RMIConnectionImpl$7::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, var$0, $($Thread::currentThread())->getContextClassLoader());
	return $of($new($RMIConnectionImpl$CombinedClassLoader, var$0, $$new($OrderClassLoaders, this->val$cl1, this->val$cl2)));
}

RMIConnectionImpl$7::RMIConnectionImpl$7() {
}

$Class* RMIConnectionImpl$7::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$7, name, initialize, &_RMIConnectionImpl$7_ClassInfo_, allocate$RMIConnectionImpl$7);
	return class$;
}

$Class* RMIConnectionImpl$7::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax