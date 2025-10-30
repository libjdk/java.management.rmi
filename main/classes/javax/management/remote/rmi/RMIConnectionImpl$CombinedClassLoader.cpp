#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/SecurityException.h>
#include <javax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper.h>
#include <javax/management/remote/rmi/RMIConnectionImpl.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $RMIConnectionImpl = ::javax::management::remote::rmi::RMIConnectionImpl;
using $RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper = ::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _RMIConnectionImpl$CombinedClassLoader_FieldInfo_[] = {
	{"defaultCL", "Ljavax/management/remote/rmi/RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper;", nullptr, $FINAL, $field(RMIConnectionImpl$CombinedClassLoader, defaultCL)},
	{}
};

$MethodInfo _RMIConnectionImpl$CombinedClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)V", nullptr, $PRIVATE, $method(static_cast<void(RMIConnectionImpl$CombinedClassLoader::*)($ClassLoader*,$ClassLoader*)>(&RMIConnectionImpl$CombinedClassLoader::init$))},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, nullptr, "java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _RMIConnectionImpl$CombinedClassLoader_InnerClassesInfo_[] = {
	{"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader", "javax.management.remote.rmi.RMIConnectionImpl", "CombinedClassLoader", $PRIVATE | $STATIC | $FINAL},
	{"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper", "javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader", "ClassLoaderWrapper", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _RMIConnectionImpl$CombinedClassLoader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader",
	"java.lang.ClassLoader",
	nullptr,
	_RMIConnectionImpl$CombinedClassLoader_FieldInfo_,
	_RMIConnectionImpl$CombinedClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_RMIConnectionImpl$CombinedClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.management.remote.rmi.RMIConnectionImpl"
};

$Object* allocate$RMIConnectionImpl$CombinedClassLoader($Class* clazz) {
	return $of($alloc(RMIConnectionImpl$CombinedClassLoader));
}

void RMIConnectionImpl$CombinedClassLoader::init$($ClassLoader* parent, $ClassLoader* defaultCL) {
	$ClassLoader::init$(parent);
	$set(this, defaultCL, $new($RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper, defaultCL));
}

$Class* RMIConnectionImpl$CombinedClassLoader::loadClass($String* name, bool resolve) {
	$useLocalCurrentObjectStackCache();
	$ReflectUtil::checkPackageAccess(name);
	try {
		$ClassLoader::loadClass(name, resolve);
	} catch ($Exception& e) {
		{
			$var($Throwable, t, e);
			for (; t != nullptr; $assign(t, t->getCause())) {
				if ($instanceOf($SecurityException, t)) {
					$throw($equals(t, e) ? $cast($SecurityException, t) : $$new($SecurityException, $($nc(t)->getMessage()), e));
				}
			}
		}
	}
	$Class* cl = $nc(this->defaultCL)->loadClass(name, resolve);
	return cl;
}

RMIConnectionImpl$CombinedClassLoader::RMIConnectionImpl$CombinedClassLoader() {
}

$Class* RMIConnectionImpl$CombinedClassLoader::load$($String* name, bool initialize) {
	$loadClass(RMIConnectionImpl$CombinedClassLoader, name, initialize, &_RMIConnectionImpl$CombinedClassLoader_ClassInfo_, allocate$RMIConnectionImpl$CombinedClassLoader);
	return class$;
}

$Class* RMIConnectionImpl$CombinedClassLoader::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax