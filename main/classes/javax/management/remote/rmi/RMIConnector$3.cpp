#include <javax/management/remote/rmi/RMIConnector$3.h>

#include <java/lang/ClassLoader.h>
#include <javax/management/remote/rmi/RMIConnector.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnector$3_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnector;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$3, this$0)},
	{"val$old", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$3, val$old)},
	{}
};

$MethodInfo _RMIConnector$3_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnector;Ljava/lang/ClassLoader;)V", "()V", 0, $method(static_cast<void(RMIConnector$3::*)($RMIConnector*,$ClassLoader*)>(&RMIConnector$3::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIConnector$3_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnector",
	"popDefaultClassLoader",
	"(Ljava/lang/ClassLoader;)V"
};

$InnerClassInfo _RMIConnector$3_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnector$3_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RMIConnector$3_FieldInfo_,
	_RMIConnector$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_RMIConnector$3_EnclosingMethodInfo_,
	_RMIConnector$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$3($Class* clazz) {
	return $of($alloc(RMIConnector$3));
}

void RMIConnector$3::init$($RMIConnector* this$0, $ClassLoader* val$old) {
	$set(this, this$0, this$0);
	$set(this, val$old, val$old);
}

$Object* RMIConnector$3::run() {
	$($Thread::currentThread())->setContextClassLoader(this->val$old);
	return $of(nullptr);
}

RMIConnector$3::RMIConnector$3() {
}

$Class* RMIConnector$3::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$3, name, initialize, &_RMIConnector$3_ClassInfo_, allocate$RMIConnector$3);
	return class$;
}

$Class* RMIConnector$3::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax