#ifndef _javax_management_remote_rmi_RMIConnector$3_h_
#define _javax_management_remote_rmi_RMIConnector$3_h_
//$ class javax.management.remote.rmi.RMIConnector$3
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {
				class RMIConnector;
			}
		}
	}
}

namespace javax {
	namespace management {
		namespace remote {
			namespace rmi {

class RMIConnector$3 : public ::java::security::PrivilegedAction {
	$class(RMIConnector$3, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RMIConnector$3();
	void init$(::javax::management::remote::rmi::RMIConnector* this$0, ::java::lang::ClassLoader* val$old);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnector* this$0 = nullptr;
	::java::lang::ClassLoader* val$old = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnector$3_h_