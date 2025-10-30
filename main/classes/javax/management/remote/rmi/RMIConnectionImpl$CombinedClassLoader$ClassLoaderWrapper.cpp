#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper.h>

#include <java/lang/ClassLoader.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RMIConnectionImpl$CombinedClassLoader = ::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$MethodInfo _RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;)V", nullptr, 0, $method(static_cast<void(RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::*)($ClassLoader*)>(&RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::init$))},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, nullptr, "java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader", "javax.management.remote.rmi.RMIConnectionImpl", "CombinedClassLoader", $PRIVATE | $STATIC | $FINAL},
	{"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper", "javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader", "ClassLoaderWrapper", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper",
	"java.lang.ClassLoader",
	nullptr,
	nullptr,
	_RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper));
}

void RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::init$($ClassLoader* cl) {
	$ClassLoader::init$(cl);
}

$Class* RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::loadClass($String* name, bool resolve) {
	return $ClassLoader::loadClass(name, resolve);
}

RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper() {
}

$Class* RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper, name, initialize, &_RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_ClassInfo_, allocate$RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper);
	return class$;
}

$Class* RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax