#include <javax/management/remote/rmi/RMIConnector$2.h>

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

$FieldInfo _RMIConnector$2_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnector;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$2, this$0)},
	{"val$t", "Ljava/lang/Thread;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnector$2, val$t)},
	{}
};

$MethodInfo _RMIConnector$2_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnector;Ljava/lang/Thread;)V", "()V", 0, $method(static_cast<void(RMIConnector$2::*)($RMIConnector*,$Thread*)>(&RMIConnector$2::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIConnector$2_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnector",
	"pushDefaultClassLoader",
	"()Ljava/lang/ClassLoader;"
};

$InnerClassInfo _RMIConnector$2_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnector$2_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RMIConnector$2_FieldInfo_,
	_RMIConnector$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_RMIConnector$2_EnclosingMethodInfo_,
	_RMIConnector$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$2($Class* clazz) {
	return $of($alloc(RMIConnector$2));
}

void RMIConnector$2::init$($RMIConnector* this$0, $Thread* val$t) {
	$set(this, this$0, this$0);
	$set(this, val$t, val$t);
}

$Object* RMIConnector$2::run() {
	$nc(this->val$t)->setContextClassLoader(this->this$0->defaultClassLoader);
	return $of(nullptr);
}

RMIConnector$2::RMIConnector$2() {
}

$Class* RMIConnector$2::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$2, name, initialize, &_RMIConnector$2_ClassInfo_, allocate$RMIConnector$2);
	return class$;
}

$Class* RMIConnector$2::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax