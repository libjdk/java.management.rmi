#include <javax/management/remote/rmi/RMIConnectionImpl$2.h>

#include <com/sun/jmx/remote/util/ClassLoaderWithRepository.h>
#include <java/lang/ClassLoader.h>
#include <javax/management/loading/ClassLoaderRepository.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <jcpp.h>

using $ClassLoaderWithRepository = ::com::sun::jmx::remote::util::ClassLoaderWithRepository;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ClassLoaderRepository = ::javax::management::loading::ClassLoaderRepository;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$2_FieldInfo_[] = {
	{"this$0", "Ljavax/management/remote/rmi/RMIConnectionImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$2, this$0)},
	{"val$dcl", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$2, val$dcl)},
	{"val$repository", "Ljavax/management/loading/ClassLoaderRepository;", nullptr, $FINAL | $SYNTHETIC, $field(RMIConnectionImpl$2, val$repository)},
	{}
};

$MethodInfo _RMIConnectionImpl$2_MethodInfo_[] = {
	{"<init>", "(Ljavax/management/remote/rmi/RMIConnectionImpl;Ljavax/management/loading/ClassLoaderRepository;Ljava/lang/ClassLoader;)V", "()V", 0, $method(static_cast<void(RMIConnectionImpl$2::*)($RMIConnectionImpl*,$ClassLoaderRepository*,$ClassLoader*)>(&RMIConnectionImpl$2::init$))},
	{"run", "()Lcom/sun/jmx/remote/util/ClassLoaderWithRepository;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIConnectionImpl$2_EnclosingMethodInfo_ = {
	"javax.management.remote.rmi.RMIConnectionImpl",
	"<init>",
	"(Ljavax/management/remote/rmi/RMIServerImpl;Ljava/lang/String;Ljava/lang/ClassLoader;Ljavax/security/auth/Subject;Ljava/util/Map;)V"
};

$InnerClassInfo _RMIConnectionImpl$2_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIConnectionImpl$2_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RMIConnectionImpl$2_FieldInfo_,
	_RMIConnectionImpl$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Lcom/sun/jmx/remote/util/ClassLoaderWithRepository;>;",
	&_RMIConnectionImpl$2_EnclosingMethodInfo_,
	_RMIConnectionImpl$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$2($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$2));
}

void RMIConnectionImpl$2::init$($RMIConnectionImpl* this$0, $ClassLoaderRepository* val$repository, $ClassLoader* val$dcl) {
	$set(this, this$0, this$0);
	$set(this, val$repository, val$repository);
	$set(this, val$dcl, val$dcl);
}

$Object* RMIConnectionImpl$2::run() {
	return $of($new($ClassLoaderWithRepository, this->val$repository, this->val$dcl));
}

RMIConnectionImpl$2::RMIConnectionImpl$2() {
}

$Class* RMIConnectionImpl$2::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$2, name, initialize, &_RMIConnectionImpl$2_ClassInfo_, allocate$RMIConnectionImpl$2);
	return class$;
}

$Class* RMIConnectionImpl$2::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax