#include <javax/management/remote/rmi/RMIConnectionImpl$PrivilegedOperation.h>

#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$PrivilegedOperation_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$PrivilegedOperation, this$0)},
	{"operation", "I", nullptr, $PRIVATE, $field(RMIConnectionImpl$PrivilegedOperation, operation)},
	{"params", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(RMIConnectionImpl$PrivilegedOperation, params)},
	{}
};

$MethodInfo _RMIConnectionImpl$PrivilegedOperation_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnectionImpl$PrivilegedOperation::*)($RMIConnectionImpl*,int32_t,$ObjectArray*)>(&RMIConnectionImpl$PrivilegedOperation::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{}
};

$InnerClassInfo _RMIConnectionImpl$PrivilegedOperation_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$PrivilegedOperation", "javax.management.remote.rmi.RMIConnectionImpl", "PrivilegedOperation", $PRIVATE},
	{}
};

$ClassInfo _RMIConnectionImpl$PrivilegedOperation_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$PrivilegedOperation",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RMIConnectionImpl$PrivilegedOperation_FieldInfo_,
	_RMIConnectionImpl$PrivilegedOperation_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Object;>;",
	nullptr,
	_RMIConnectionImpl$PrivilegedOperation_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$PrivilegedOperation($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$PrivilegedOperation));
}

void RMIConnectionImpl$PrivilegedOperation::init$($RMIConnectionImpl* this$0, int32_t operation, $ObjectArray* params) {
	$set(this, this$0, this$0);
	this->operation = operation;
	$set(this, params, params);
}

$Object* RMIConnectionImpl$PrivilegedOperation::run() {
	return $of(this->this$0->doOperation(this->operation, this->params));
}

RMIConnectionImpl$PrivilegedOperation::RMIConnectionImpl$PrivilegedOperation() {
}

$Class* RMIConnectionImpl$PrivilegedOperation::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$PrivilegedOperation, name, initialize, &_RMIConnectionImpl$PrivilegedOperation_ClassInfo_, allocate$RMIConnectionImpl$PrivilegedOperation);
	return class$;
}

$Class* RMIConnectionImpl$PrivilegedOperation::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax