#ifndef _javax_management_remote_rmi_RMIConnectionImpl$CombinedClassLoader_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$CombinedClassLoader_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader
//$ extends java.lang.ClassLoader

#include <java/lang/ClassLoader.h>

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$CombinedClassLoader : public ::java::lang::ClassLoader {
	$class(RMIConnectionImpl$CombinedClassLoader, $NO_CLASS_INIT, ::java::lang::ClassLoader)
public:
	RMIConnectionImpl$CombinedClassLoader();
	void init$(::java::lang::ClassLoader* parent, ::java::lang::ClassLoader* defaultCL);
	using ::java::lang::ClassLoader::loadClass;
	virtual $Class* loadClass($String* name, bool resolve) override;
	::javax::management::remote::rmi::RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper* defaultCL = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$CombinedClassLoader_h_