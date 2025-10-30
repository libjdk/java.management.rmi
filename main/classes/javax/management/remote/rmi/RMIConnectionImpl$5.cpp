#include <javax/management/remote/rmi/RMIConnectionImpl$5.h>

#include <java/lang/ClassLoader.h>
#include <javax/management/MBeanServer.h>
#include <javax/management/ObjectName.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $MBeanServer = ::javax::management::MBeanServer;
using $ObjectName = ::javax::management::ObjectName;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$5_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$5, this$0)},
	{"val$name", "Ljavax/management/ObjectName;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$5, val$name)},
	{}
};

$MethodInfo _RMIConnectionImpl$5_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;Ljavax/management/ObjectName;)V", "()V", 0, $method(static_cast<void(RMIConnectionImpl$5::*)($RMIConnectionImpl*,$ObjectName*)>(&RMIConnectionImpl$5::init$))},
	{"run", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException"},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$5_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"getClassLoader",
	"(Ljavax/management/ObjectName;)Ljava/lang/ClassLoader;"
};

$InnerClassInfo _RMIConnectionImpl$5_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$5", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$5_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$5",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RMIConnectionImpl$5_FieldInfo_,
	_RMIConnectionImpl$5_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/ClassLoader;>;",
	&_RMIConnectionImpl$5_EnclosingMethodInfo_,
	_RMIConnectionImpl$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$5($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$5));
}

void RMIConnectionImpl$5::init$($RMIConnectionImpl* this$0, $ObjectName* val$name) {
	$set(this, this$0, this$0);
	$set(this, val$name, val$name);
}

$Object* RMIConnectionImpl$5::run() {
	return $of($nc(this->this$0->mbeanServer)->getClassLoader(this->val$name));
}

RMIConnectionImpl$5::RMIConnectionImpl$5() {
}

$Class* RMIConnectionImpl$5::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$5, name, initialize, &_RMIConnectionImpl$5_ClassInfo_, allocate$RMIConnectionImpl$5);
	return class$;
}

$Class* RMIConnectionImpl$5::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax