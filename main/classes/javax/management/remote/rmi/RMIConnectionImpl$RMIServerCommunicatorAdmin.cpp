#include <javax/management/remote/rmi/RMIConnectionImpl$RMIServerCommunicatorAdmin.h>

#include <com/sun/jmx/remote/internal/ServerCommunicatorAdmin.h>
#include <com/sun/jmx/remote/util/ClassLogger.h>
#include <java/io/IOException.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ServerCommunicatorAdmin = ::com::sun::jmx::remote::internal::ServerCommunicatorAdmin;
using $ClassLogger = ::com::sun::jmx::remote::util::ClassLogger;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$RMIServerCommunicatorAdmin_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$RMIServerCommunicatorAdmin, this$0)},
	{}
};

$MethodInfo _RMIConnectionImpl$RMIServerCommunicatorAdmin_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;J)V", nullptr, $PUBLIC, $method(static_cast<void(RMIConnectionImpl$RMIServerCommunicatorAdmin::*)($RMIConnectionImpl*,int64_t)>(&RMIConnectionImpl$RMIServerCommunicatorAdmin::init$))},
	{"doStop", "()V", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _RMIConnectionImpl$RMIServerCommunicatorAdmin_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$RMIServerCommunicatorAdmin", "javax.management.remote.rmi.RMIConnectionImpl", "RMIServerCommunicatorAdmin", $PRIVATE},
	{}
};

$ClassInfo _RMIConnectionImpl$RMIServerCommunicatorAdmin_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$RMIServerCommunicatorAdmin",
	"com.sun.jmx.remote.internal.ServerCommunicatorAdmin",
	nullptr,
	_RMIConnectionImpl$RMIServerCommunicatorAdmin_FieldInfo_,
	_RMIConnectionImpl$RMIServerCommunicatorAdmin_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnectionImpl$RMIServerCommunicatorAdmin_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$RMIServerCommunicatorAdmin($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$RMIServerCommunicatorAdmin));
}

void RMIConnectionImpl$RMIServerCommunicatorAdmin::init$($RMIConnectionImpl* this$0, int64_t timeout) {
	$set(this, this$0, this$0);
	$ServerCommunicatorAdmin::init$(timeout);
}

void RMIConnectionImpl$RMIServerCommunicatorAdmin::doStop() {
	try {
		this->this$0->close();
	} catch ($IOException& ie) {
		$init($RMIConnectionImpl);
		$nc($RMIConnectionImpl::logger)->warning("RMIServerCommunicatorAdmin-doStop"_s, $$str({"Failed to close: "_s, ie}));
		$nc($RMIConnectionImpl::logger)->debug("RMIServerCommunicatorAdmin-doStop"_s, static_cast<$Throwable*>(ie));
	}
}

RMIConnectionImpl$RMIServerCommunicatorAdmin::RMIConnectionImpl$RMIServerCommunicatorAdmin() {
}

$Class* RMIConnectionImpl$RMIServerCommunicatorAdmin::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$RMIServerCommunicatorAdmin, name, initialize, &_RMIConnectionImpl$RMIServerCommunicatorAdmin_ClassInfo_, allocate$RMIConnectionImpl$RMIServerCommunicatorAdmin);
	return class$;
}

$Class* RMIConnectionImpl$RMIServerCommunicatorAdmin::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax