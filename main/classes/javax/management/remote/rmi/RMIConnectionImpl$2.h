#ifndef _javax_management_remote_rmi_RMIConnectionImpl$2_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$2_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace javax {
	namespace management {
		namespace loading {
			class ClassLoaderRepository;
		}
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnectionImpl;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnectionImpl$2 : public ::java::security::PrivilegedAction {
	$class(RMIConnectionImpl$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RMIConnectionImpl$2();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0, ::javax::management::loading::ClassLoaderRepository* val$repository, ::java::lang::ClassLoader* val$dcl);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
	::java::lang::ClassLoader* val$dcl = nullptr;
	::javax::management::loading::ClassLoaderRepository* val$repository = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$2_h_