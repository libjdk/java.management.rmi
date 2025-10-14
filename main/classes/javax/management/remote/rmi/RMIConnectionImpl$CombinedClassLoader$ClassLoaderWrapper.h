#ifndef _javax_management_remote_rmi_RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper
//$ extends java.lang.ClassLoader

#include <java/lang/ClassLoader.h>

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper : public ::java::lang::ClassLoader {
	$class(RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper, $NO_CLASS_INIT, ::java::lang::ClassLoader)
public:
	RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper();
	void init$(::java::lang::ClassLoader* cl);
	using ::java::lang::ClassLoader::loadClass;
	virtual $Class* loadClass($String* name, bool resolve) override;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$CombinedClassLoader$ClassLoaderWrapper_h_