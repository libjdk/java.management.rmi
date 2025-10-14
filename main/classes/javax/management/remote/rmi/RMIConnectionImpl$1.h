#ifndef _javax_management_remote_rmi_RMIConnectionImpl$1_h_
#define _javax_management_remote_rmi_RMIConnectionImpl$1_h_
//$ class javax.management.remote.rmi.RMIConnectionImpl$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

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

class RMIConnectionImpl$1 : public ::java::security::PrivilegedAction {
	$class(RMIConnectionImpl$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RMIConnectionImpl$1();
	void init$(::javax::management::remote::rmi::RMIConnectionImpl* this$0);
	virtual $Object* run() override;
	::javax::management::remote::rmi::RMIConnectionImpl* this$0 = nullptr;
};

			} // rmi
		} // remote
	} // management
} // javax

#endif // _javax_management_remote_rmi_RMIConnectionImpl$1_h_