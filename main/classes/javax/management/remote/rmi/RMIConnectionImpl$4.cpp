#include <javax/management/remote/rmi/RMIConnectionImpl$4.h>

#include <com/sun/jmx/remote/internal/ServerNotifForwarder.h>
#include <javax/management/remote/NotificationResult.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ServerNotifForwarder = ::com::sun::jmx::remote::internal::ServerNotifForwarder;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $NotificationResult = ::javax::management::remote::NotificationResult;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$4_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$4, this$0)},
	{"val$mn", "I", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$4, val$mn)},
	{"val$t", "J", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$4, val$t)},
	{"val$csn", "J", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$4, val$csn)},
	{}
};

$MethodInfo _RMIConnectionImpl$4_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;JJI)V", "()V", 0, $method(static_cast<void(RMIConnectionImpl$4::*)($RMIConnectionImpl*,int64_t,int64_t,int32_t)>(&RMIConnectionImpl$4::init$))},
	{"run", "()Ljavax/management/remote/NotificationResult;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$4_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"fetchNotifications",
	"(JIJ)Ljavax/management/remote/NotificationResult;"
};

$InnerClassInfo _RMIConnectionImpl$4_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$4", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$4_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$4",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RMIConnectionImpl$4_FieldInfo_,
	_RMIConnectionImpl$4_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljavax/management/remote/NotificationResult;>;",
	&_RMIConnectionImpl$4_EnclosingMethodInfo_,
	_RMIConnectionImpl$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$4($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$4));
}

void RMIConnectionImpl$4::init$($RMIConnectionImpl* this$0, int64_t val$csn, int64_t val$t, int32_t val$mn) {
	$set(this, this$0, this$0);
	this->val$csn = val$csn;
	this->val$t = val$t;
	this->val$mn = val$mn;
}

$Object* RMIConnectionImpl$4::run() {
	return $of($nc($(this->this$0->getServerNotifFwd()))->fetchNotifs(this->val$csn, this->val$t, this->val$mn));
}

RMIConnectionImpl$4::RMIConnectionImpl$4() {
}

$Class* RMIConnectionImpl$4::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$4, name, initialize, &_RMIConnectionImpl$4_ClassInfo_, allocate$RMIConnectionImpl$4);
	return class$;
}

$Class* RMIConnectionImpl$4::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax