#include <javax/management/remote/rmi/RMIConnector$Util.h>

#include <javax/management/remote/rmi/RMIConnector.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RMIConnector = ::javax::management::remote::rmi::RMIConnector;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$MethodInfo _RMIConnector$Util_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(RMIConnector$Util::*)()>(&RMIConnector$Util::init$))},
	{"cast", "(Ljava/lang/Object;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Object;)TT;", $PUBLIC | $STATIC, $method(static_cast<$Object*(*)(Object$*)>(&RMIConnector$Util::cast))},
	{}
};

$InnerClassInfo _RMIConnector$Util_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnector$Util", "javax.management.remote.rmi.RMIConnector", "Util", $STATIC | $FINAL},
	{}
};

$ClassInfo _RMIConnector$Util_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"javax.management.remote.rmi.RMIConnector$Util",
	"java.lang.Object",
	nullptr,
	nullptr,
	_RMIConnector$Util_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnector$Util_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnector"
};

$Object* allocate$RMIConnector$Util($Class* clazz) {
	return $of($alloc(RMIConnector$Util));
}

void RMIConnector$Util::init$() {
}

$Object* RMIConnector$Util::cast(Object$* x) {
	return $of(x);
}

RMIConnector$Util::RMIConnector$Util() {
}

$Class* RMIConnector$Util::load$($String* name, bool initialize) {
	$loadClass(RMIConnector$Util, name, initialize, &_RMIConnector$Util_ClassInfo_, allocate$RMIConnector$Util);
	return class$;
}

$Class* RMIConnector$Util::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax