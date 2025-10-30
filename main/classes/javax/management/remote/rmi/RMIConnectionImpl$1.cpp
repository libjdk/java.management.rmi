#include <javax/management/remote/rmi/RMIConnectionImpl$1.h>

#include <javax/management/MBeanServer.h>
#include <javax/management/loading/ClassLoaderRepository.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $MBeanServer = ::javax::management::MBeanServer;
using $ClassLoaderRepository = ::javax::management::loading::ClassLoaderRepository;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$1_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$1, this$0)},
	{}
};

$MethodInfo _RMIConnectionImpl$1_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;)V", nullptr, 0, $method(static_cast<void(RMIConnectionImpl$1::*)($RMIConnectionImpl*)>(&RMIConnectionImpl$1::init$))},
	{"run", "()Ljavax/management/loading/ClassLoaderRepository;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$1_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"<init>",
	"(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/lang/String;Ljava/lang/ClassLoader;Ljavax/security/auth/Subject;Ljava/util/Map;)V"
};

$InnerClassInfo _RMIConnectionImpl$1_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RMIConnectionImpl$1_FieldInfo_,
	_RMIConnectionImpl$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljavax/management/loading/ClassLoaderRepository;>;",
	&_RMIConnectionImpl$1_EnclosingMethodInfo_,
	_RMIConnectionImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$1($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$1));
}

void RMIConnectionImpl$1::init$($RMIConnectionImpl* this$0) {
	$set(this, this$0, this$0);
}

$Object* RMIConnectionImpl$1::run() {
	return $of($nc(this->this$0->mbeanServer)->getClassLoaderRepository());
}

RMIConnectionImpl$1::RMIConnectionImpl$1() {
}

$Class* RMIConnectionImpl$1::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$1, name, initialize, &_RMIConnectionImpl$1_ClassInfo_, allocate$RMIConnectionImpl$1);
	return class$;
}

$Class* RMIConnectionImpl$1::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax