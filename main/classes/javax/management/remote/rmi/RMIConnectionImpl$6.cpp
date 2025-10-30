#include <javax/management/remote/rmi/RMIConnectionImpl$6.h>

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

$FieldInfo _RMIConnectionImpl$6_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$6, this$0)},
	{"val$name", "Ljavax/management/ObjectName;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$6, val$name)},
	{}
};

$MethodInfo _RMIConnectionImpl$6_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;Ljavax/management/ObjectName;)V", "()V", 0, $method(static_cast<void(RMIConnectionImpl$6::*)($RMIConnectionImpl*,$ObjectName*)>(&RMIConnectionImpl$6::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.management.InstanceNotFoundException"},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$6_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"getClassLoaderFor",
	"(Ljavax/management/ObjectName;)Ljava/lang/ClassLoader;"
};

$InnerClassInfo _RMIConnectionImpl$6_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$6", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$6_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$6",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RMIConnectionImpl$6_FieldInfo_,
	_RMIConnectionImpl$6_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Object;>;",
	&_RMIConnectionImpl$6_EnclosingMethodInfo_,
	_RMIConnectionImpl$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$6($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$6));
}

void RMIConnectionImpl$6::init$($RMIConnectionImpl* this$0, $ObjectName* val$name) {
	$set(this, this$0, this$0);
	$set(this, val$name, val$name);
}

$Object* RMIConnectionImpl$6::run() {
	return $of($nc(this->this$0->mbeanServer)->getClassLoaderFor(this->val$name));
}

RMIConnectionImpl$6::RMIConnectionImpl$6() {
}

$Class* RMIConnectionImpl$6::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$6, name, initialize, &_RMIConnectionImpl$6_ClassInfo_, allocate$RMIConnectionImpl$6);
	return class$;
}

$Class* RMIConnectionImpl$6::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax