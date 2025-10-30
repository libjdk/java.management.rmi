#include <javax/management/remote/rmi/NoCallStackClassLoader.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/security/ProtectionDomain.h>
#include <jcpp.h>

using $byteArray2 = $Array<int8_t, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ProtectionDomain = ::java::security::ProtectionDomain;

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

$FieldInfo _NoCallStackClassLoader_FieldInfo_[] = {
	{"classNames", "[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(NoCallStackClassLoader, classNames)},
	{"byteCodes", "[[B", nullptr, $PRIVATE | $FINAL, $field(NoCallStackClassLoader, byteCodes)},
	{"referencedClassNames", "[Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(NoCallStackClassLoader, referencedClassNames)},
	{"referencedClassLoader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(NoCallStackClassLoader, referencedClassLoader)},
	{"protectionDomain", "Ljava/security/ProtectionDomain;", nullptr, $PRIVATE | $FINAL, $field(NoCallStackClassLoader, protectionDomain)},
	{}
};

$MethodInfo _NoCallStackClassLoader_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;[B[Ljava/lang/String;Ljava/lang/ClassLoader;Ljava/security/ProtectionDomain;)V", nullptr, $PUBLIC, $method(static_cast<void(NoCallStackClassLoader::*)($String*,$bytes*,$StringArray*,$ClassLoader*,$ProtectionDomain*)>(&NoCallStackClassLoader::init$))},
	{"<init>", "([Ljava/lang/String;[[B[Ljava/lang/String;Ljava/lang/ClassLoader;Ljava/security/ProtectionDomain;)V", nullptr, $PUBLIC, $method(static_cast<void(NoCallStackClassLoader::*)($StringArray*,$byteArray2*,$StringArray*,$ClassLoader*,$ProtectionDomain*)>(&NoCallStackClassLoader::init$))},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, nullptr, "java.lang.ClassNotFoundException"},
	{"stringToBytes", "(Ljava/lang/String;)[B", nullptr, $PUBLIC | $STATIC, $method(static_cast<$bytes*(*)($String*)>(&NoCallStackClassLoader::stringToBytes))},
	{}
};

$ClassInfo _NoCallStackClassLoader_ClassInfo_ = {
	$ACC_SUPER,
	"javax.management.remote.rmi.NoCallStackClassLoader",
	"java.lang.ClassLoader",
	nullptr,
	_NoCallStackClassLoader_FieldInfo_,
	_NoCallStackClassLoader_MethodInfo_
};

$Object* allocate$NoCallStackClassLoader($Class* clazz) {
	return $of($alloc(NoCallStackClassLoader));
}

void NoCallStackClassLoader::init$($String* className, $bytes* byteCode, $StringArray* referencedClassNames, $ClassLoader* referencedClassLoader, $ProtectionDomain* protectionDomain) {
	$useLocalCurrentObjectStackCache();
	NoCallStackClassLoader::init$($$new($StringArray, {className}), $$new($byteArray2, {byteCode}), referencedClassNames, referencedClassLoader, protectionDomain);
}

void NoCallStackClassLoader::init$($StringArray* classNames, $byteArray2* byteCodes, $StringArray* referencedClassNames, $ClassLoader* referencedClassLoader, $ProtectionDomain* protectionDomain) {
	$ClassLoader::init$(nullptr);
	if (classNames == nullptr || $nc(classNames)->length == 0 || byteCodes == nullptr || $nc(classNames)->length != $nc(byteCodes)->length || referencedClassNames == nullptr || protectionDomain == nullptr) {
		$throwNew($IllegalArgumentException);
	}
	for (int32_t i = 0; i < $nc(classNames)->length; ++i) {
		if (classNames->get(i) == nullptr || $nc(byteCodes)->get(i) == nullptr) {
			$throwNew($IllegalArgumentException);
		}
	}
	for (int32_t i = 0; i < $nc(referencedClassNames)->length; ++i) {
		if (referencedClassNames->get(i) == nullptr) {
			$throwNew($IllegalArgumentException);
		}
	}
	$set(this, classNames, classNames);
	$set(this, byteCodes, byteCodes);
	$set(this, referencedClassNames, referencedClassNames);
	$set(this, referencedClassLoader, referencedClassLoader);
	$set(this, protectionDomain, protectionDomain);
}

$Class* NoCallStackClassLoader::findClass($String* name) {
	for (int32_t i = 0; i < $nc(this->classNames)->length; ++i) {
		if ($nc(name)->equals($nc(this->classNames)->get(i))) {
			return defineClass($nc(this->classNames)->get(i), $nc(this->byteCodes)->get(i), 0, $nc($nc(this->byteCodes)->get(i))->length, this->protectionDomain);
		}
	}
	if (this->referencedClassLoader != nullptr) {
		for (int32_t i = 0; i < $nc(this->referencedClassNames)->length; ++i) {
			if ($nc(name)->equals($nc(this->referencedClassNames)->get(i))) {
				return $nc(this->referencedClassLoader)->loadClass(name);
			}
		}
	}
	$throwNew($ClassNotFoundException, name);
}

$bytes* NoCallStackClassLoader::stringToBytes($String* s) {
	$init(NoCallStackClassLoader);
	int32_t slen = $nc(s)->length();
	$var($bytes, bytes, $new($bytes, slen));
	for (int32_t i = 0; i < slen; ++i) {
		bytes->set(i, (int8_t)s->charAt(i));
	}
	return bytes;
}

NoCallStackClassLoader::NoCallStackClassLoader() {
}

$Class* NoCallStackClassLoader::load$($String* name, bool initialize) {
	$loadClass(NoCallStackClassLoader, name, initialize, &_NoCallStackClassLoader_ClassInfo_, allocate$NoCallStackClassLoader);
	return class$;
}

$Class* NoCallStackClassLoader::class$ = nullptr;

			} // rmi
		} // remote
	} // management
} // javax