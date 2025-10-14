#ifndef _javax_management_remote_rmi_RMIConnector$ObjectInputStreamWithLoader_h_
#define _javax_management_remote_rmi_RMIConnector$ObjectInputStreamWithLoader_h_
//$ class javax.management.remote.rmi.RMIConnector$ObjectInputStreamWithLoader
//$ extends java.io.ObjectInputStream

#include <java/io/ObjectInputStream.h>

namespace java {
	namespace io {
		class InputStream;
		class ObjectStreamClass;
	}
}
namespace java {
	namespace lang {
		class ClassLoader;
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnector$ObjectInputStreamWithLoader : public ::java::io::ObjectInputStream {
	$class(RMIConnector$ObjectInputStreamWithLoader, $NO_CLASS_INIT, ::java::io::ObjectInputStream)
public:
	RMIConnector$ObjectInputStreamWithLoader();
	void init$(::java::io::InputStream* in, ::java::lang::ClassLoader* cl);
	using ::java::io::ObjectInputStream::read;
	virtual $Class* resolveClass(::java::io::ObjectStreamClass* classDesc) override;
	::java::lang::ClassLoader* loader = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$ObjectInputStreamWithLoader_h_