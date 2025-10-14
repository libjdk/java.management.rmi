#ifndef _javax_management_remote_rmi_NoCallStackClassLoader_h_
#define _javax_management_remote_rmi_NoCallStackClassLoader_h_
//$ class javax.management.remote.rmi.NoCallStackClassLoader
//$ extends java.lang.ClassLoader

#include <java/lang/Array.h>
#include <java/lang/ClassLoader.h>

namespace java {
	namespace security {
		class ProtectionDomain;
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class NoCallStackClassLoader : public ::java::lang::ClassLoader {
	$class(NoCallStackClassLoader, $NO_CLASS_INIT, ::java::lang::ClassLoader)
public:
	NoCallStackClassLoader();
	using ::java::lang::ClassLoader::findClass;
	void init$($String* className, $bytes* byteCode, $StringArray* referencedClassNames, ::java::lang::ClassLoader* referencedClassLoader, ::java::security::ProtectionDomain* protectionDomain);
	void init$($StringArray* classNames, $Array<int8_t, 2>* byteCodes, $StringArray* referencedClassNames, ::java::lang::ClassLoader* referencedClassLoader, ::java::security::ProtectionDomain* protectionDomain);
	virtual $Class* findClass($String* name) override;
	static $bytes* stringToBytes($String* s);
	$StringArray* classNames = nullptr;
	$Array<int8_t, 2>* byteCodes = nullptr;
	$StringArray* referencedClassNames = nullptr;
	::java::lang::ClassLoader* referencedClassLoader = nullptr;
	::java::security::ProtectionDomain* protectionDomain = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_NoCallStackClassLoader_h_